%{
        #include <stdio.h>
        #include <string.h>
        #include "listaSimbolos.h"
        Lista tabSimb;
        Tipo tipo;
        void yyerror(const char * s);
        int contadorEtiquetas = 1;
        int contadorCadenas = 1;
        int numErroresSintacticos = 0;
        int numErroresSemanticos = 0;
        int numErroresLexicos = 0;
        extern int yylex();
%}

%code requires {
    #include "listaCodigo.h"
}

%union {
    char *lexema; /* solo string */
    ListaC codigo;
}

%token LPAREN DPAREN LEFTKEY RIGHTKEY VAR CONST COMMA ASSIGNOP SEMICOLON WHILE PRINT READ MINUS MINUSOP MULTIPLICATION DIVISION PLUSOP IF ELSE 
%token <lexema> INTLITERAL STRING ID

%type <codigo> expression statement print_item print_list read_list declarations identifier_list identifier statement_list

    /* prioridad */
%left PLUSOP MINUSOP
%left MULTIPLICATION DIVISION
%left MINUS

%define parse.error verbose

/* Aceptar conflictos if - else *
%expect 1

%%

program : { tabSimb = creaLS();} ID LPAREN DPAREN LEFTKEY declarations statement_list RIGHTKEY {   concatenaLC($6, $7) if ((numErroresLexicos == 0 && numErroresSemanticos == 0 && numErroresSintacticos == 0)) {
                                                                                                                            imprimirTabSimb(tabSimb);
                                                                                                                            imprimirCodigo($6);
                                                                                                                        } 
                                                                                                                        liberaLC($6); liberaLC($7); liberaLS(tabSimb); }
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

identifier_list : identifier { $$ = $1; } // necesario?
                | identifier_list COMMA identifier {
                                                        $$ = $1;
                                                        concatenaLC($$, $3);
                                                        liberaLC($3);   
                                                    }
                | // lambda??
                ;

identifier : ID             /* comprobar que no se redeclaren */ 
                        { 
                        if(!perteneceTabSimb(tabSimb,$1)) {
                            insertarTS($1,tipo);
                        }
                        else {
                            printf("ERROR en la linea %d: variable %s ya declarada anteriormente.\n", yylineno,$1);
                            numErroresSemanticos++;
                        }
                            // algo mas?
                        $$ = creaLS();
                     }
           | ID ASSIGNOP expression { /* comprobar que no se redeclaren */ 
                                        if(!perteneceTabSimb(tabSimb, $1)) {
                                            insertarTS($1,tipo);
                                        }
                                        else {
                                            printf("ERROR en la linea %d: variable %s ya declarada anteriormente.\n", yylineno,$1);
                                            numErroresSemanticos++;
                                        }
                                
                                        //$3 recibe lista de codigo
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
				                             concatenaLC($$, $2);}
               | { $$ = creaLC(); } // concatenar con lo otro // crear lista vacia en lambda 
               ; 
 
statement : ID ASSIGNOP expression SEMICOLON     { 
                                                    // ver si ID previamente declarado
                                                    if(!perteneceTabSimb(tabSimb,$1)) {
                                                        printf("ERROR en la linea %d: variable %s no declarada.\n",yylineno,$1); ;     
                                                        numErroresSemanticos++;
                                                    }
                                                    else if (esConstante($1)) {
                                                        printf("ERROR en la linea %d: asignación a constante %s\n", yylineno, $1);
                                                        numErroresSemanticos++;
                                                    }

                                                    $$ = $3;
                                                    
                                                    Operacion oper;
                                                    oper.op = "sw";
                                                    oper.res = recuperaResLC($3);
                                                    oper.arg1 = concatenaCads("_",$1);
                                                    oper.arg2 = NULL;  

                                                    /*
                                                    printf("Expr contiene %d operaciones\n",longitudLC($3));
                                                    PosicionListaC p = inicioLC($3);
                                                    
                                                    while (p != finalLC($3)) {
                                                        oper = recuperaLC($3,p);
                                                        printf("%s",oper.op);
                                                        if (oper.res) printf(" %s",oper.res);
                                                        if (oper.arg1) printf(",%s",oper.arg1);
                                                        if (oper.arg2) printf(",%s",oper.arg2);
                                                        printf("\n");
                                                        p = siguienteLC($3,p);
                                                    } */
                                                    
                                                    insertaLC($$, finalLC($$), oper);

                                                    //imprimirListaC($$);
                                        
                                                    liberarReg(oper.res);

                                               }
          | LEFTKEY statement_list RIGHTKEY
          | IF LPAREN expression DPAREN statement ELSE statement {




                                                                }
          | IF LPAREN expression DPAREN statement    {




                                                     }
          | WHILE LPAREN expression DPAREN statement {








                                                      }
          | PRINT LPAREN print_list DPAREN SEMICOLON { $$=$3;}
          | READ LPAREN read_list DPAREN SEMICOLON { $$=$3;} 
          ;

print_list : print_item // poner algo?
           | print_list COMMA print_item // poner algo?
           ;


print_item : expression {

                        $$ = $1;

                        Operacion oper1;
                        Operacion oper2;
                        Operacion oper3;
                        
                        //move o lw/la??
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
                        insertaLC($$, finalLC($$), oper2);
                        liberarReg(recuperaResLC($1));

                    }
           | STRING {/* solo almacenar para luego imprimir str1... */
                        insertarTS($1,CADENA); 
                        //contadorEtiquetas++;
                        contadorCadenas++;
                        //char* etiqueta = obtenerEtiqueta();
                        //char * aux = malloc(32);
                        //sprintf(aux, "$str%d", contadorCadenas++);

                        $$ = creaLS();

                        Operacion oper1;
                        Operacion oper2;
                        Operacion oper3;
                        
                        oper1.op = "la";
                        oper1.res = "$a0";
                        oper1.arg1 = concatenaCadNUm("$str", contadorCadenas);
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

read_list : ID                  { /* comprobar si declarado o no. Si es constante -> error */
                                                if(!perteneceTabSimb(tabSimb,$1)) {
                                                    printf("ERROR en la linea %d: variable %s no declarada.\n",yylineno,$1);
                                                    numErroresSemanticos++;
                                                }
                                                else if (esConstante($1)) {
                                                    printf("ERROR en la linea %d: asignación a constante %s\n", yylineno, $1);
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
                                                oper3.arg1 = concatenaCads("_",$3);
                                                oper3.arg2 = NULL;
                                                insertaLC($$, finalLC($$), oper3);
                                }
          | read_list COMMA ID  { /* comprobar si declarado o no. Si es constante -> error */
                                                if (!perteneceTabSimb(tabSimb,$3)) {
                                                    printf("ERROR, %s ya declarado anteriormente", $3);     
                                                    numErroresSemanticos++;
                                                }
                                                else if (esConstante($3)) {
                                                    printf("ERROR en la linea %d: asignación a constante %s\n", yylineno, $1);
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
                                                            $$ = $1; // pasar al padre el resultado
                                                            concatenaLC($$, $3);
                                                            Operacion oper;
                                                            oper.op = "addi";
                                                            oper.res = asignarRegistroTemporal(); // (TO-DO) buscar primer registro temporal libre
                                                            oper.arg1 = recuperaResLC($1);    // (TO-DO) coger el campo res de $1 (recuperar res)
                                                            oper.arg2 = recuperaResLC($3);    // (TO-DO)
                                                            insertaLC($$, finalLC($$), oper);
                                                            liberarReg(oper.arg2);
                                                            liberaLC($3); 
                                                        }
           | expression MINUSOP expression              {   
                                                            $$ = $1; // pasar al padre el resultado
                                                            concatenaLC($$, $3);
                                                            Operacion oper;
                                                            oper.op = "sub";
                                                            oper.res = asignarRegistroTemporal(); // (TO-DO) buscar primer registro temporal libre
                                                            oper.arg1 = recuperaResLC($1);    // (TO-DO) coger el campo res de $1 (recuperar res)
                                                            oper.arg2 = recuperaResLC($3);   // (TO-DO)
                                                            insertaLC($$, finalLC($$), oper);
                                                            liberarReg(oper.arg2);
                                                            liberaLC($3);                            

                                                        }  
             | expression MULTIPLICATION expression      {
                                                            $$ = $1; // pasar al padre el resultado
                                                            concatenaLC($$, $3);    
                                                            Operacion oper;
                                                            oper.op = "mul";
                                                            oper.res = asignarRegistroTemporal(); // (TO-DO) buscar primer registro temporal libre
                                                            oper.arg1 = recuperaResLC($1);    // (TO-DO) coger el campo res de $1 (recuperar res)
                                                            oper.arg2 = recuperaResLC($3);   // (TO-DO)
                                                            insertaLC($$, finalLC($$), oper);
                                                            // liberar las 2 kistas
                                                            liberarReg(oper.arg2);
                                                            liberaLC($3);              

                                                        }
           | expression DIVISION expression             {
                                                            $$ = $1; // pasar al padre el resultado
                                                            char *arg1 = recuperaResLC($1); // izq
                                                            char *arg2 = recuperaResLC($3); // der

                                                            concatenaLC($$, $3);
                                                            liberaLC($3);
                                                            Operacion oper;
                                                            oper.op = "div";
                                                            oper.res = asignarRegistroTemporal(); // (TO-DO) buscar primer registro temporal libre
                                                            oper.arg1 = arg1;    // (TO-DO) coger el campo res de $1 (recuperar res)
                                                            oper.arg2 = arg2;    // (TO-DO)
                                                            insertaLC($$, finalLC($$), oper);
                                                            liberarReg(oper.arg2);
                                                            
                                                        }
           | MINUSOP expression %prec MINUS             {  
                                                            $$ = $2; 
                                                            Operacion oper;
                                                            oper.op = "neg";
                                                            oper.res = asignarRegistroTemporal(); // (TO-DO) buscar primer registro temporal libre
                                                            oper.arg1 = recuperaResLC($2);    // (TO-DO) coger el campo res de $2 (recuperar res)
                                                            oper.arg2 = NULL;
                                                            insertaLC($$, finalLC($$), oper);
                                                            guardaResLC($$, oper.res);
                                                            liberarReg(oper.arg1);
                                                            
                                                        }
           | LPAREN expression DPAREN                   {   $$=$2; }
           | ID                                         {
                                                        
                                                        /* no se va a guardar/asignar nada. Solo ver si id está en la tabla para imprimir o sumar*/
                                                            if (!perteneceTabSimb(tabSimb,$1)) {
                                                                printf("ERROR en la linea %d: variable %s no declarada.\n", yylineno,$1); 
                                                                numErroresSemanticos++; 
                                                            }
                                                            $$ = creaLS();
                                                            Operacion oper;
                                                            oper.op = "lw";
                                                            oper.res = asignarRegistroTemporal();
                                                            oper.arg1 = concatenaCads("_", $1);
                                                            oper.arg2 = NULL;
                                                            insertaLC($$, finalLC($$), oper);
                                                            guardaResLC($$, oper.res);
                                                        }
           | INTLITERAL                                 {
                                                            $$ = creaLS();
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

// comentarios -> trabajar con la PosicionListatabla de símbolos 

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

char *concatenaCadNUm(char *cad, int num) {
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
		else if (oper.op == "li" || oper.op == "la" || oper.op == "lw" || oper.op == "sw" || oper.op == "neg" || oper.op == "move" || oper.op == "beqz"){
			printf("   %s ", oper.op);
			if(oper.res) printf ("%s, ", oper.res);
			if(oper.arg1) printf ("%s", oper.arg1);
			if(oper.arg2) printf ("%s", oper.arg2);
			printf("\n");
	
			}
		else if (oper.op == "add" || oper.op == "sub" || oper.op == "div" || oper.op == "mul"  || oper.op == "bgt" || oper.op == "addi" ){
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
	printf("   jr $ra\n");

}

void yyerror(const char * s) {
    printf("Se ha producido un error en esta expresión %s\n",s);
}


