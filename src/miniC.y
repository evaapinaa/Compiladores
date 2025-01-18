%{
        #include <stdio.h>
        #include <string.h>
        #include "listaSimbolos.h"
        Lista tabSimb;
        Tipo tipo;
        void yyerror(const char * s);
        char *obtenerEtiqueta();
        char *concatenaCads(char *cad1, char *cad2);
        char *concatenaCadNum(char *cad, int num);
        void imprimirCodigo();
        void insertarTS(char *nombre, Tipo tipo);
        int perteneceTabSimb(char *nombre);
        void imprimirTabSimb(Lista tabSimb);
        char *asignarRegistroTemporal();
        void liberarReg(char *registro);
        int esConstante(char* nombre);
        int contadorEtiquetas = 1;
        int contadorCadenas = 1;
        int numErroresSintacticos = 0;
        int numErroresSemanticos = 0;
        extern int numErroresLexicos;
        extern int yylex();
        extern int yylineno;
        int tablaRegistrosTemporales[10] = {0};
%}

%code requires {
    #include "listaCodigo.h"
}

%union {
    char *lexema;
    ListaC codigo;
}

%token DO VAR CONST LPAREN DPAREN LEFTKEY RIGHTKEY COMMA ASSIGNOP SEMICOLON WHILE PRINT READ MINUS MINUSOP MULTIPLICATION DIVISION PLUSOP IF ELSE 
%token <lexema> INTLITERAL STRING ID

%type <codigo> expression statement print_item print_list read_list declarations identifier_list identifier statement_list

%left PLUSOP MINUSOP
%left MULTIPLICATION DIVISION
%left MINUS

%define parse.error verbose
%define parse.trace	

%expect 1

%%

program : { tabSimb = creaLS();} ID LPAREN DPAREN LEFTKEY declarations statement_list RIGHTKEY {
                                                                                                    if(numErroresLexicos == 0 && numErroresSintacticos == 0 && numErroresSemanticos == 0) {
                                                                                                        imprimirTabSimb(tabSimb);
                                                                                                        concatenaLC($6, $7);
                                                                                                        imprimirCodigo($6);
                                                                                                    }
                                                                                                    
                                                                                                    liberaLC($6); 
                                                                                                    liberaLC($7); 
                                                                                                    liberaLS(tabSimb); 
                                                                                               }
        ;

declarations : declarations VAR { tipo = VARIABLE; } identifier_list SEMICOLON { 
                                                                                    $$ = $1;
                                                                                    concatenaLC($$, $4);
                                                                                    liberaLC($4);
                                                                                                                                                               
                                                                                }
             | declarations CONST { tipo = CONSTANTE; } identifier_list SEMICOLON {
                                                                                    $$ = $1;
                                                                                    concatenaLC($$, $4);
                                                                                    liberaLC($4);
                                                                                    }
             | {$$ = creaLC();}
             ; 

identifier_list : identifier { $$ = $1; } 
                | identifier_list COMMA identifier {
                                                        $$ = $1;
                                                        concatenaLC($$, $3);
                                                        liberaLC($3);   
                                                    }
                ;

identifier : ID           
                        { 
                            if(!perteneceTabSimb($1)) {
                                insertarTS($1,tipo);
                            }
                            else {
                                printf("\nERROR en la linea %d: variable %s ya declarada anteriormente.", yylineno,$1);
                                numErroresSemanticos++;
                            }
                            
                            $$ = creaLC();
                     }
           | ID ASSIGNOP expression { 
                                        if(!perteneceTabSimb($1)) {
                                            insertarTS($1,tipo);
                                        }
                                        else {
                                            printf("\nERROR en la linea %d: variable %s ya declarada anteriormente.", yylineno,$1);
                                            numErroresSemanticos++;
                                        }
                                
                                       
                                        $$ = $3;
                                        Operacion oper;
                                        oper.op = "sw";
                                        oper.res = recuperaResLC($3);
                                        oper.arg1 = concatenaCads("_",$1);
                                        oper.arg2 = NULL;
                                        insertaLC($$, finalLC($$), oper);
                                        liberarReg(oper.res);
                                    }
           ;

statement_list : statement_list statement {  $$ = $1;
				                             concatenaLC($$, $2);
                                             liberaLC($2);
                                             }
               | { $$ = creaLC(); } 
               ; 
 
statement : ID ASSIGNOP expression SEMICOLON     { 
                                                  
                                                    if(!perteneceTabSimb($1)) {
                                                        printf("\nERROR en la linea %d: variable %s no declarada.",yylineno,$1); ;     
                                                        numErroresSemanticos++;
                                                    }
                                                    else if (esConstante($1)) {
                                                        printf("\nERROR en la linea %d: asignación a la constante %s.", yylineno, $1);
                                                        numErroresSemanticos++;
                                                    }

                                                    $$ = $3;
                                                    
                                                    Operacion oper;
                                                    oper.op = "sw";
                                                    oper.res = recuperaResLC($3);
                                                    oper.arg1 = concatenaCads("_",$1);
                                                    oper.arg2 = NULL;                                 
                                                    insertaLC($$, finalLC($$), oper);             
                                                    liberarReg(oper.res);

                                               }
          | LEFTKEY statement_list RIGHTKEY { $$ = $2; }
          | IF LPAREN expression DPAREN statement ELSE statement {
                                                                    $$ = $3;
                                                                    Operacion oper1;
                                                                    Operacion oper2;
                                                                    Operacion oper3;
                                                                    Operacion oper4;
                                                            
                                                                    oper1.op = "beqz";
                                                                    oper1.res = recuperaResLC($3);
                                                                    oper1.arg1 = obtenerEtiqueta();
                                                                    oper1.arg2 = NULL;
                                                                    insertaLC($$, finalLC($$), oper1);
                                                                    concatenaLC($$, $5);
                                                                    liberaLC($5);

                                                                    oper2.op = "b";
                                                                    oper2.res = obtenerEtiqueta();
                                                                    oper2.arg1 = NULL;
                                                                    oper2.arg2 = NULL;
                                                                    insertaLC($$, finalLC($$), oper2);
                                                                    
                                                                    oper3.op = "etiq";
                                                                    oper3.res = oper1.arg1;
                                                                    oper3.arg1 = NULL;
                                                                    oper3.arg2 = NULL;
                                                                    insertaLC($$, finalLC($$), oper3);
                                                                    concatenaLC($$, $7);                                                                    
                                                                    liberaLC($7);

                                                                    oper4.op = "etiq";
                                                                    oper4.res = oper2.res;
                                                                    oper4.arg1 = NULL;
                                                                    oper4.arg2 = NULL;
                                                                    insertaLC($$, finalLC($$), oper4);
                                                                    liberarReg(recuperaResLC($3));
                                                                }
          | IF LPAREN expression DPAREN statement    {

                                                                    $$ = $3;
                                                                    Operacion oper1;
                                                                    Operacion oper2;
                                                            
                                                                    oper1.op = "beqz";
                                                                    oper1.res = recuperaResLC($3);
                                                                    oper1.arg1 = obtenerEtiqueta();
                                                                    oper1.arg2 = NULL;
                                                                    insertaLC($$, finalLC($$), oper1);
                                                                    concatenaLC($$, $5);
                                                                    liberaLC($5);
 
                                                                    oper2.op = "etiq";
                                                                    oper2.res = oper1.arg1;
                                                                    oper2.arg1 = NULL;
                                                                    oper2.arg2 = NULL;
                                                                    insertaLC($$, finalLC($$), oper2);
                                                                    liberarReg(recuperaResLC($$));

                                                     }
          | WHILE LPAREN expression DPAREN statement 			{ 
                                                                    $$ = $3;
                                                                    Operacion oper1;
                                                                    Operacion oper2;
                                                                    Operacion oper3;
                                                                    Operacion oper4;
                                                                    
                                                                    oper1.op = "etiq";
                                                                    oper1.res = obtenerEtiqueta();
                                                                    oper1.arg1 = NULL;
                                                                    oper1.arg2 = NULL;
                                                                    insertaLC($$, inicioLC($$), oper1); 

                                                                    oper2.op = "beqz";
                                                                    oper2.res = recuperaResLC($3);
                                                                    oper2.arg1 = obtenerEtiqueta();
                                                                    oper2.arg2 = NULL;
                                                                    insertaLC($$,finalLC($$), oper2);
                                                                    concatenaLC($$, $5);
                                                                    liberaLC($5);

                                                                    oper3.op = "b";
                                                                    oper3.res = oper1.res;
                                                                    oper3.arg1 = NULL;
                                                                    oper3.arg2 = NULL;
                                                                    insertaLC($$,finalLC($$), oper3);

                                                                    oper4.op = "etiq";
                                                                    oper4.res = oper2.arg1;
                                                                    oper4.arg1 = NULL;
                                                                    oper4.arg2 = NULL;
                                                                    insertaLC($$,finalLC($$), oper4);
                                                                    liberarReg(recuperaResLC($$));
                                                                    
                                                                }
        | DO statement WHILE LPAREN expression DPAREN SEMICOLON {

                                                                    $$ = creaLC();
                                                                    Operacion oper1;
                                                                    Operacion oper2;
                                                                    Operacion oper3;


                                                                    oper1.op = "etiq";
                                                                    oper1.res = obtenerEtiqueta();
                                                                    oper1.arg1 = NULL;
                                                                    oper1.arg2 = NULL;
                                                                    insertaLC($$, inicioLC($$), oper1); 
                                                                    concatenaLC($$, $2);
                                                                    concatenaLC($$, $5);
                                                                    oper2.op = "bnez";
                                                                    oper2.res = recuperaResLC($5);
                                                                    oper2.arg1 = oper1.res;
                                                                    oper2.arg2 = NULL;
                                                                    insertaLC($$,finalLC($$), oper2);
                                                                    liberaLC($5);
                                                                    liberaLC($2);

                                                                }				
          | PRINT LPAREN print_list DPAREN SEMICOLON { $$=$3;}
          | READ LPAREN read_list DPAREN SEMICOLON { $$=$3;} 
          ;

print_list : print_item { $$ = $1;}
           | print_list COMMA print_item { $$ = $1; concatenaLC($$, $3); }
           ;


print_item : expression {
                        $$ = $1;

                        Operacion oper1;
                        Operacion oper2;
                        Operacion oper3;

                        oper1.op = "move";
                        oper1.res = "$a0";
                        oper1.arg1 = recuperaResLC($1);
                        oper1.arg2 = NULL;
                        insertaLC($$, finalLC($$), oper1);

                        oper2.op = "li";
                        oper2.res = "$v0";
                        oper2.arg1 = "1";
                        oper2.arg2 = NULL;
                        insertaLC($$, finalLC($$), oper2);
                        
                        oper3.op = "syscall";
                        oper3.res = NULL;
                        oper3.arg1 = NULL;
                        oper3.arg2 = NULL;
                        insertaLC($$, finalLC($$), oper3);
                        liberarReg(recuperaResLC($1));

                    }
           | STRING {
                        insertarTS($1, CADENA); 
                        contadorCadenas++;
                        $$ = creaLC();

                        Operacion oper1;
                        Operacion oper2;
                        Operacion oper3;
                        
                        oper1.op = "la";
                        oper1.res = "$a0";
                        oper1.arg1 = concatenaCadNum("$str", contadorCadenas-1);
                        oper1.arg2 = NULL;
                        insertaLC($$, finalLC($$), oper1);

                        oper2.op = "li";
                        oper2.res = "$v0";
                        oper2.arg1 = "4";
                        oper2.arg2 = NULL;
                        insertaLC($$, finalLC($$), oper2);

                        oper3.op = "syscall";
                        oper3.res = NULL;
                        oper3.arg1 = NULL;
                        oper3.arg2 = NULL;
                        insertaLC($$, finalLC($$), oper3);

                    }        
           ;

read_list : ID                  { 
                                                if(!perteneceTabSimb($1)) {
                                                    printf("\nERROR en la linea %d: variable %s no declarada.",yylineno,$1);
                                                    numErroresSemanticos++;
                                                }
                                                else if (esConstante($1)) {
                                                    printf("\nERROR en la linea %d: asignación a la constante %s.", yylineno, $1);
                                                    numErroresSemanticos++;
                                                }
                                                
                                                $$ = creaLC();
                                                Operacion oper1;
                                                Operacion oper2;
                                                Operacion oper3;

                                                oper1.op = "li";
                                                oper1.res = "$v0";
                                                oper1.arg1 = "5";
                                                oper1.arg2 = NULL;
                                                insertaLC($$, finalLC($$), oper1);
            
                                                oper2.op = "syscall";
                                                oper2.res = NULL;
                                                oper2.arg1 = NULL;
                                                oper2.arg2 = NULL;
                                                insertaLC($$, finalLC($$), oper2);
                                                
                                                oper3.op = "sw";
                                                oper3.res = "$v0";
                                                oper3.arg1 = concatenaCads("_",$1);
                                                oper3.arg2 = NULL;
                                                insertaLC($$, finalLC($$), oper3);
                                }
          | read_list COMMA ID  { 
                                                if (!perteneceTabSimb($3)) {
                                                    printf("\nERROR, %s ya declarado anteriormente.", $3);     
                                                    numErroresSemanticos++;
                                                }
                                                else if (esConstante($3)) {
                                                    printf("\nERROR en la linea %d: asignación a la constante %s.", yylineno, $1);
                                                    numErroresSemanticos++;
                                                }

                                                $$ = $1;

                                                Operacion oper1;
                                                Operacion oper2;
                                                Operacion oper3;
                                                
                                                oper1.op = "li";
                                                oper1.res = "$v0";
                                                oper1.arg1 = "5";
                                                oper1.arg2 = NULL;
                                                insertaLC($$, finalLC($$), oper1);
                                                
                                                oper2.op = "syscall";
                                                oper2.res = NULL;
                                                oper2.arg1 = NULL;
                                                oper2.arg2 = NULL;
                                                insertaLC($$, finalLC($$), oper2);
                                                
                                                oper3.op = "sw";
                                                oper3.res = "$v0";
                                                oper3.arg1 = concatenaCads("_", $3);
                                                oper3.arg2 = NULL;
                                                insertaLC($$, finalLC($$), oper3);
                                }
          ;

expression : expression PLUSOP expression               {
                                                            $$ = $1;
                                                            concatenaLC($$, $3);
                                                            Operacion oper;
                                                            oper.op = "add";
                                                            oper.res = asignarRegistroTemporal(); 
                                                            oper.arg1 = recuperaResLC($1);    
                                                            oper.arg2 = recuperaResLC($3);    
                                                            insertaLC($$, finalLC($$), oper);
                                                            guardaResLC($$,oper.res);
                                                            liberarReg(oper.arg2);
                                                            liberaLC($3); 
                                                        }
           | expression MINUSOP expression              {   
                                                            $$ = $1;
                                                            concatenaLC($$, $3);
                                                            Operacion oper;
                                                            oper.op = "sub";
                                                            oper.res = asignarRegistroTemporal(); 
                                                            oper.arg1 = recuperaResLC($1);   
                                                            oper.arg2 = recuperaResLC($3);  
                                                            insertaLC($$, finalLC($$), oper);
                                                            guardaResLC($$,oper.res);
                                                            liberarReg(oper.arg2);
                                                            liberaLC($3);                            

                                                        }  
             | expression MULTIPLICATION expression      {
                                                            $$ = $1;
                                                            concatenaLC($$, $3);    
                                                            Operacion oper;
                                                            oper.op = "mul";
                                                            oper.res = asignarRegistroTemporal(); 
                                                            oper.arg1 = recuperaResLC($1);    
                                                            oper.arg2 = recuperaResLC($3);  
                                                            insertaLC($$, finalLC($$), oper);
                                                            guardaResLC($$,oper.res);
                                                            liberarReg(oper.arg2);
                                                            liberaLC($3);              

                                                        }
           | expression DIVISION expression             {
                                                            $$ = $1;
                                                            concatenaLC($$, $3);
                                                            Operacion oper;
                                                            oper.op = "div";
                                                            oper.res = asignarRegistroTemporal();
                                                            oper.arg1 = recuperaResLC($1);     
                                                            oper.arg2 = recuperaResLC($3);    
                                                            insertaLC($$, finalLC($$), oper);
                                                            guardaResLC($$,oper.res);
                                                            liberarReg(oper.arg2);
                                                            liberaLC($3);
                                                        }
           | MINUSOP expression %prec MINUS             {  
                                                            $$ = $2; 
                                                            Operacion oper;
                                                            oper.op = "neg";
                                                            oper.res = asignarRegistroTemporal();
                                                            oper.arg1 = recuperaResLC($2);    
                                                            oper.arg2 = NULL;
                                                            insertaLC($$, finalLC($$), oper);
                                                            guardaResLC($$, oper.res);
                                                            
                                                        }
           | LPAREN expression DPAREN                   {   $$=$2; }
           | ID                                         {
                                                        
                                                            if (!perteneceTabSimb($1)) {
                                                                printf("\nERROR en la linea %d: variable %s no declarada.", yylineno,$1); 
                                                                numErroresSemanticos++; 
                                                            }
                                                            $$ = creaLC();
                                                            Operacion oper;
                                                            oper.op = "lw";
                                                            oper.res = asignarRegistroTemporal();
                                                            oper.arg1 = concatenaCads("_", $1);
                                                            oper.arg2 = NULL;
                                                            insertaLC($$, finalLC($$), oper);
                                                            guardaResLC($$, oper.res);
                                                        }
           | INTLITERAL                                 {
                                                            $$ = creaLC();
                                                            Operacion oper;
                                                            oper.op = "li";
                                                            oper.res = asignarRegistroTemporal();
                                                            oper.arg1 = $1;
                                                            oper.arg2 = NULL;
                                                            insertaLC($$, finalLC($$), oper);    
                                                            guardaResLC($$, oper.res);
                                                        }
           ;

%%



void imprimirTabSimb(Lista tabSimb) {
	printf("#####################\n");
	printf("# Seccion de datos\n");
	printf("   .data\n");
	PosicionLista p= inicioLS(tabSimb);
	while (p != finalLS(tabSimb)) {
		Simbolo aux = recuperaLS(tabSimb,p);
		if (aux.tipo == VARIABLE || aux.tipo == CONSTANTE){
			printf("_%s:\n   .word 0\n", aux.nombre);
		}
		else if (aux.tipo == CADENA){
			printf("$str%d:\n   .asciiz %s\n",aux.valor, aux.nombre);
		}
		p = siguienteLS(tabSimb,p);
	}
	printf("\n");
}


void insertarTS(char *nombre, Tipo tipo) {
	if (tipo == CADENA){
		Simbolo aux;
		aux.nombre = nombre;
		aux.tipo = tipo;
		aux.valor = contadorCadenas;
		insertaLS(tabSimb,finalLS(tabSimb), aux);
	} else {
		Simbolo aux;
		aux.nombre = nombre;
		aux.tipo = tipo;
		insertaLS(tabSimb,finalLS(tabSimb), aux);
	}
}

int perteneceTabSimb(char *nombre) {
    if (buscaLS(tabSimb, nombre) != finalLS(tabSimb))
	    return 1;
    else
        return 0;
}
int esConstante(char* nombre) {
    PosicionLista p = buscaLS(tabSimb, nombre);
  	Simbolo aux = recuperaLS(tabSimb, p);
  	if (aux.tipo == CONSTANTE) return 1;
  	return 0;
}


char *obtenerEtiqueta() {
    char aux[32];
    sprintf(aux,"$l%d",contadorEtiquetas++);
    return strdup(aux);
}

char *concatenaCads(char *cad1, char *cad2) {
    char *aux = malloc(strlen(cad1) + strlen(cad2) + 1);
    strcpy(aux, cad1);
    strcat(aux, cad2);
    return aux;
}

char *concatenaCadNum(char *cad, int num) {
    char aux[32];
    sprintf(aux,"%s%d",cad,num);
    return strdup(aux);
}

void imprimirCodigo(ListaC codigo){
	printf("#####################\n");
	printf("# Seccion de codigo\n");
	printf("   .text\n");
	printf("   .globl main\n");
	printf("main:\n");
	PosicionListaC p = inicioLC(codigo);
	while (p != finalLC(codigo)){
		Operacion oper = recuperaLC(codigo, p);
		if (oper.op == "etiq"){
			printf("%s:\n", oper.res);
		}
		else if (oper.op == "li" || oper.op == "la" || oper.op == "lw" || oper.op == "sw" || oper.op == "neg" || oper.op == "move" || oper.op == "beqz" || oper.op == "bnez" || oper.op == "b"){
			printf("   %s ", oper.op);
			if(oper.res) printf ("%s, ", oper.res);
			if(oper.arg1) printf ("%s", oper.arg1);
			if(oper.arg2) printf ("%s", oper.arg2);
			printf("\n");
	
			}
		else if (oper.op == "add" || oper.op == "sub" || oper.op == "div" || oper.op == "mul"){
			printf("   %s ", oper.op);
			if(oper.res) printf ("%s, ", oper.res);
			if(oper.arg1) printf ("%s, ", oper.arg1);
			if(oper.arg2) printf ("%s", oper.arg2);
			printf("\n");
		}
		else {
			printf("   %s ", oper.op);
			if(oper.res) printf ("%s", oper.res);
			if(oper.arg1) printf ("%s", oper.arg1);
			if(oper.arg2) printf ("%s", oper.arg2);
			printf("\n");
		}
		p = siguienteLC(codigo, p);	
	}
	printf("\n");
	printf("#####################\n");
	printf("# Fin\n");
    printf("   li $v0, 10\n");
    printf("   syscall\n");
}

char * asignarRegistroTemporal() {
  char aux[32];
  for(int i = 0; i < 10; i++) {
    if(tablaRegistrosTemporales[i] == 0) {
        tablaRegistrosTemporales[i] = 1;
        sprintf(aux,"$t%d",i);
        return strdup(aux);
    }
  }
}

void liberarReg(char *registro) {
    int i = registro[2] - '0';
    tablaRegistrosTemporales[i] = 0;
}

void yyerror(const char * s) {
    printf("\nERROR en la línea %d: %s\n",yylineno,s);
    numErroresSintacticos++;
}


