
%{
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "listaSimbolos.h"

Lista TabladeSimbolos;
Tipo tipo;

void yyerror();
extern int yylex();
extern int yylineno;
extern int errores_lexicos;
void yyerror();
extern char * yytext;
	
	int contadorCadenas=1;
	int contadorEtiquetas=1;
	int numErroresSintacticos = 0;
	int numErroresSemanticos = 0;
	char registros[10] = {0};
int ProgramaCorrecto();
char * enlazar_cadena();
char * enlazar_cadena_2();
char * obtenerRegistro();
void AnadirSimbolo();
void liberarReg();
int ContieneSimbolo();
int AnalizaConstantes();
void imprimirTabla();
void imprimirCod();
char *obtenerEtiqueta();
%}
%code requires{
	#include "listaCodigo.h"
	}
%union
{
    ListaC codigo;
    char *string;
}

%type <codigo> expression statement_list statement print_list print_item read_list declarations identifier_list asig

%token VOID VAR CONST IF ELSE WHILE PRINT READ PCOMMA COMMA PLUSOP MINUSOP ASTER BARRA ASSIG PARD PARI CORI CORD
%token <string> ID CADE ENT


/* Declaramos asociatividad y preferencia de los operadores */
%left PLUSOP MINUSOP
%left ASTER BARRA
%left NEG

/* Añadimos los flags de funciones de Bison */
%define parse.error verbose //para generar mensajes de error externos
%define parse.trace	//Para activar trazas con yydebug

/*Metodo para solucionar conflicto desplaza/reduce en if-else */
%expect 1

%%

//Generamos las reglas de produccion 
program : { TabladeSimbolos = creaLS(); }
	VOID ID PARI PARD CORI declarations statement_list CORD {
	if(ProgramaCorrecto()){ imprimirTabla();
				concatenaLC($7,$8);
				imprimirCod($7);} 
	else printf("errores lexicos: %d, errores sintanticos: %d, errores semánticos: %d\n", errores_lexicos, numErroresSintacticos, numErroresSemanticos);
	liberaLS(TabladeSimbolos);
	liberaLC($7);}
;

declarations :		declarations VAR
			{ tipo = VARIABLE;} 
			identifier_list PCOMMA
			{$$ = $1;
                        concatenaLC($$, $4);
                        liberaLC($4);}
                     	| declarations CONST
                     	{ tipo = CONSTANTE;}
                     	identifier_list PCOMMA
                     	{$$=$1;
			concatenaLC($$, $4);
			liberaLC($4);}   
			|	{$$ = creaLC();}            
;

identifier_list : 		asig
				{ $$ = $1; }
			|	identifier_list COMMA asig
				{ $$ = $1;
				concatenaLC($$, $3);
				liberaLC($3);}
;

asig : 			ID
				{ if (!ContieneSimbolo($1)){
					AnadirSimbolo($1, tipo);}
				else{numErroresSemanticos++;
				printf("Error semántico en la linea %d : \"%s\" ya esta declarada\n", yylineno, $1);}
				$$ = creaLC();}
				| ID ASSIG expression
				{if (!ContieneSimbolo($1)) AnadirSimbolo($1, tipo);
				else{
				numErroresSemanticos++;
				printf("Error semántico en la linea %d : \"%s\" ya esta declarada \n", yylineno, $1);}
				$$ = $3;
				Operacion opera;
				opera.op = "sw";
				opera.res = recuperaResLC($3);
				opera.arg1 = enlazar_cadena("_",$1);
				opera.arg2 = NULL;
				insertaLC($$,finalLC($$),opera);
				liberarReg(opera.res);}
;
	
statement_list :		statement_list statement
				{$$ = $1;
				concatenaLC($$, $2);}
			|	{ $$ = creaLC();}
;

statement : 			ID ASSIG expression PCOMMA
				{if (!ContieneSimbolo($1)){
					numErroresSemanticos++;
					printf("Error semántico en la linea %d: \"%s\" no está declarada\n", yylineno, $1);} else { 
					if (AnalizaConstantes($1)){
					numErroresSemanticos++;
					printf("Error semántico en la linea %d: \"%s\" es una constante\n", yylineno, $1);}}
				$$ = $3;
				Operacion opera;
				opera.op = "sw";
				opera.res = recuperaResLC($3);
				opera.arg1 = enlazar_cadena("_",$1);
				opera.arg2 = NULL;
				insertaLC($$, finalLC($$), opera);
				liberarReg(opera.res);	
				}
			|	 CORI statement_list CORD
				{ $$ = $2; }
			| 	IF PARI expression PARD statement ELSE statement
				{ $$ = $3;
				char *etiq = obtenerEtiqueta();
				char *etiq1 = obtenerEtiqueta();
				Operacion opera;
				opera.op = "beqz";
				opera.res = recuperaResLC($3);
				opera.arg1 = etiq;
				opera.arg2 = NULL;
				insertaLC($$,finalLC($$),opera);
				concatenaLC($$,$5);
				liberaLC($5);

				opera.op ="b";
				opera.res = etiq1;
				opera.arg1 = NULL;
				opera.arg2 = NULL;
				insertaLC($$,finalLC($$),opera);

				opera.op = "etiq";
				opera.res = etiq;
				opera.arg1 = NULL;
				opera.arg2 = NULL;
				insertaLC($$,finalLC($$),opera);
				concatenaLC($$,$7);
				liberaLC($7);

				opera.op = "etiq";
				opera.res = etiq1;
				opera.arg1 = NULL;
				opera.arg2 = NULL;
				insertaLC($$,finalLC($$),opera);
				liberarReg(recuperaResLC($3));}
			| IF PARI expression PARD statement
				{$$=$3;
				char *etiq = obtenerEtiqueta();
				Operacion opera;
				opera.op = "beqz";
				opera.res = recuperaResLC($3);
				opera.arg1 = etiq;
				opera.arg2 = NULL;
				insertaLC($$, finalLC($$), opera);
				concatenaLC($$, $5);
				liberaLC($5);
				
				opera.op = "etiq";
				opera.res = etiq;
				opera.arg1 = NULL;
				opera.arg2 = NULL;
				insertaLC($$,finalLC($$),opera);
				liberarReg(recuperaResLC($3));}
			| 	WHILE PARI expression PARD statement
				{ $$ = creaLC();
				char *etiq = obtenerEtiqueta();
				char *etiq1 = obtenerEtiqueta();
				Operacion opera;
				opera.op = "etiq";
				opera.res = etiq;
				opera.arg1 = NULL;
				opera.arg2 = NULL;
				insertaLC($$, finalLC($$),opera);
				concatenaLC($$,$3); 
				
				opera.op = "beqz";
				opera.res = recuperaResLC($3);
				opera.arg1 = etiq1;
				opera.arg2 = NULL;
				insertaLC($$,finalLC($$),opera);
				concatenaLC($$, $5);
				
				opera.op = "b";
				opera.res = etiq;
				opera.arg1 = NULL;
				opera.arg2 = NULL;
				insertaLC($$,finalLC($$),opera);
				
				opera.op = "etiq";
				opera.res = etiq1;
				opera.arg1 = NULL;
				opera.arg2 = NULL;
				insertaLC($$,finalLC($$),opera);
				liberarReg(recuperaResLC($3));}				
| PRINT print_list PCOMMA	{$$=$2;}
| READ read_list PCOMMA	{$$=$2;}
;

print_list : print_item
| print_list COMMA print_item 
;

print_item : expression
				{$$=$1;
				Operacion opera;
				opera.op = "move";
				opera.res = "$a0";
				opera.arg1 = recuperaResLC($1);
				opera.arg2 = NULL;
				
				insertaLC($$, finalLC($$), opera);
				opera.op = "li";
				opera.res = "$v0";
				opera.arg1 = "1";
				opera.arg2 = NULL;
				
				insertaLC($$,finalLC($$),opera);
				opera.op = "syscall";
				opera.res = NULL;
				opera.arg1 = NULL;
				opera.arg2 = NULL;
				
				insertaLC($$,finalLC($$),opera);
				liberarReg(recuperaResLC($1));}
| CADE
				{AnadirSimbolo($1, CADENA);
				$$ = creaLC();
				
				Operacion opera;
				opera.op = "la";
				opera.res="$a0";
				opera.arg1 = enlazar_cadena_2("$str", contadorCadenas-1);
				opera.arg2 = NULL;
				insertaLC($$,finalLC($$),opera);
				
				opera.op = "syscall";
				opera.res = NULL;
				opera.arg1 = NULL;
				opera.arg2 = NULL;
				insertaLC($$,finalLC($$),opera);}
;

read_list : ID
				{if (!ContieneSimbolo($1)){printf("La variable %s en la linea %d no esta declarada \n",$1,yylineno); numErroresSemanticos++;}
				else if(AnalizaConstantes($1)){printf("La variable %s de la linea %d es una constante (Asignacion a constante) \n", $1, yylineno); numErroresSemanticos++;}
				$$=creaLC();
				Operacion opera;
				opera.op = "li";
				opera.res = "$v0";
				opera.arg1 = "5";
				opera.arg2 = NULL;
				insertaLC($$,finalLC($$),opera);
				
				opera.op = "syscall";
				opera.res = NULL;
				opera.arg1 = NULL;
				opera.arg2 = NULL;
				insertaLC($$,finalLC($$),opera);
				
				opera.op = "sw";
				opera.res = "$v0";
				opera.arg1 = enlazar_cadena("_",$1);
				opera.arg2 = NULL;
				insertaLC($$,finalLC($$),opera);}
| read_list COMMA ID 
				{if(!ContieneSimbolo($3)){printf("La variable %s en la linea %d no esta declarada \n",$3,yylineno); numErroresSemanticos++;}
				else if(AnalizaConstantes($3)){printf("La variable %s de la linea %d es una constante (Asignacion a constante) \n", $3, yylineno); numErroresSemanticos++;}
				$$=$1;
				Operacion opera;
				opera.op = "li";
				opera.res = "$v0";
				opera.arg1 = "5";
				opera.arg2 = NULL;
				insertaLC($$,finalLC($$),opera);
				
				opera.op = "syscall";
				opera.res = NULL;
				opera.arg1 = NULL;
				opera.arg2 =NULL;
				insertaLC($$,finalLC($$),opera);
				
				opera.op = "sw";
				opera.res = "$v0";
				opera.arg1 = enlazar_cadena("_",$3);
				opera.arg2 = NULL;
				insertaLC($$,finalLC($$),opera);}
;

expression : expression PLUSOP expression {	$$ = $1;
						concatenaLC($$,$3);
						Operacion opera;
						opera.op = "add";
						opera.res = obtenerRegistro();
						opera.arg1 = recuperaResLC($1);
						opera.arg2 = recuperaResLC($3);
						insertaLC($$,finalLC($$),opera);
						liberaLC($3);
						guardaResLC($$,opera.res);
						liberarReg(opera.arg1);
						liberarReg(opera.arg2);}
| expression MINUSOP expression {		$$ = $1;
						concatenaLC($$,$3);
						Operacion opera;
						opera.op = "sub";
						opera.res = obtenerRegistro();
						opera.arg1 = recuperaResLC($1);
						opera.arg2 = recuperaResLC($3);
						insertaLC($$,finalLC($$),opera);
						liberaLC($3);
						guardaResLC($$,opera.res);
						liberarReg(opera.arg1);
						liberarReg(opera.arg2);}
| expression ASTER expression {		$$ = $1;
						concatenaLC($$,$3);
						Operacion opera;
						opera.op = "mul";
						opera.res = obtenerRegistro();
						opera.arg1 = recuperaResLC($1);
						opera.arg2 = recuperaResLC($3);
						insertaLC($$,finalLC($$),opera);
						liberaLC($3);
						guardaResLC($$,opera.res);
						liberarReg(opera.arg1);
						liberarReg(opera.arg2);}
| expression BARRA expression {		$$ = $1;
						concatenaLC($$,$3);
						Operacion opera;
						opera.op = "div";
						opera.res = obtenerRegistro();
						opera.arg1 = recuperaResLC($1);
						opera.arg2 = recuperaResLC($3);
						insertaLC($$,finalLC($$),opera);
						liberaLC($3);
						guardaResLC($$,opera.res);
						liberarReg(opera.arg1);
						liberarReg(opera.arg2);}
| MINUSOP expression %prec NEG {		$$ = $2;
						Operacion opera;
						opera.op = "neg";
						opera.res = obtenerRegistro();
						opera.arg1 = recuperaResLC($2);
						opera.arg2 = NULL;
						insertaLC($$,finalLC($$),opera);
						guardaResLC($$,opera.res);
						liberarReg(opera.arg1);}
| PARI expression PARD {$$ = $2;}
| ID						{if (!ContieneSimbolo($1)){ printf("La variable %s en la linea %d no esta declarada \n", $1, yylineno); numErroresSemanticos++;}
						$$ = creaLC();
						Operacion opera;
						opera.op = "lw";
						opera.res = obtenerRegistro();
						opera.arg1 = enlazar_cadena("_", $1);
						opera.arg2 = NULL;
						insertaLC($$,finalLC($$),opera);
						guardaResLC($$,opera.res);}
| ENT						{$$ = creaLC();
						Operacion opera;
						opera.op = "li";
						opera.res = obtenerRegistro();
						opera.arg1 = $1;
						opera.arg2 = NULL;
						insertaLC($$,finalLC($$),opera);
						guardaResLC($$,opera.res);}
;

%%

void yyerror()
{
printf("Se ha producido un error sintactico en la linea %d\n", yylineno);
numErroresSintacticos++;
}

int ProgramaCorrecto(){
	return !(errores_lexicos + numErroresSintacticos + numErroresSemanticos);
}

char *enlazar_cadena(char *arg1, char *arg2) {
	char *aux = (char*)malloc(strlen(arg1)+strlen(arg2)+1);
	sprintf(aux,"%s%s",arg1,arg2);
	return aux;
}

char *enlazar_cadena_2(char *arg1, int i) {
	char *aux = (char*)malloc(strlen(arg1)+11);
	sprintf(aux,"%s%d",arg1,i);
	return aux;
}
char *obtenerEtiqueta(){
	char aux[32];
	sprintf(aux, "$l%d", contadorEtiquetas++);
	return strdup(aux);
}


char *obtenerRegistro() {
	for (int i = 0; i < 10; i++) {
		if (registros[i] == 0) {
			registros[i] = 1;
			char aux[16];
			sprintf(aux,"$t%d",i);
			return strdup(aux);
		}
	}
	printf("Error: registros agotados\n");
	exit(1);
}

void liberarReg(char *reg) {
	if (reg[0] =='$' && reg[1] =='t') {
		int aux = reg[2] - '0';
		assert(aux >= 0);
		assert(aux < 9);
		registros[aux] = 0;
	}
}

int ContieneSimbolo(char* c)
{
    if (buscaLS(TabladeSimbolos, c) != finalLS(TabladeSimbolos))
	    return 1;
    else
        return 0;
}

void AnadirSimbolo(char *c, Tipo t){
    Simbolo s;
    s.nombre = c;
    s.tipo = t;

    if(t == CADENA){
		s.valor = contadorCadenas;
		contadorCadenas++;
	}


    insertaLS(TabladeSimbolos, finalLS(TabladeSimbolos), s);}
    
int AnalizaConstantes(char* c){
    Simbolo s;
    s = recuperaLS(TabladeSimbolos, buscaLS(TabladeSimbolos, c));

    if (s.tipo == CONSTANTE)
	    return 1;
    else
        return 0;
}

void imprimirCod(ListaC codigo) {
  printf("###################\n");
	printf("# Seccion de codigo\n");
	printf("\t.text\n");
	printf("\t.globl main\n");
	printf("main:\n");
	PosicionListaC p = inicioLC(codigo);
	while (p != finalLC(codigo)) {
		Operacion opera;
		opera = recuperaLC(codigo,p);
		if (!strcmp(opera.op,"etiq")) printf("%s:\n",opera.res);
		else {  printf("\t%s",opera.op);
			if (opera.res) printf(" %s",opera.res);
			if (opera.arg1) printf(",%s",opera.arg1);
			if (opera.arg2) printf(",%s",opera.arg2);
			}
		printf("\n");
		p = siguienteLC(codigo,p);
	}
	printf("##################\n");
	printf("# Fin\n");
	printf("\tli $v0, 10\n");
	printf("\tsyscall\n");
}

void imprimirTabla(){
    PosicionLista aux = inicioLS(TabladeSimbolos);
    printf("############################\n # Seccion de datos\n .data\n\n");
    printf("# Cadenas ##################\n");
    while(aux != finalLS(TabladeSimbolos)){
        Simbolo s = recuperaLS(TabladeSimbolos, aux);
        if (s.tipo == CADENA)
            printf("$str%d:\t.asciiz %s \n", s.valor, s.nombre);
        aux = siguienteLS(TabladeSimbolos, aux);
    }
    
    aux =  inicioLS(TabladeSimbolos);
    printf("\n# Identificadores ##############\n");
    while(aux != finalLS(TabladeSimbolos)){
        Simbolo s = recuperaLS(TabladeSimbolos, aux);
        if (s.tipo == VARIABLE)
            printf("_%s:\t.word 0\n", s.nombre);
        if (s.tipo == CONSTANTE)
            printf("_%s:\t.word 0\n", s.nombre);
        aux = siguienteLS(TabladeSimbolos, aux);
    }

}
