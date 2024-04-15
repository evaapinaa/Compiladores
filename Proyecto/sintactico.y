%{
        #include <stdio.h>
        #include <string.h>
        #include "listaSimbolos.h"
        Lista tabSimb;
        Tipo tipo;
        void yyerror(const char * s);
        int contCadenas = 1;
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

%type <codigo> expression

    /* prioridad */
%nonassoc NO_ELSE
%nonassoc ELSE
%left PLUSOP MINUSOP
%left MULTIPLICATION DIVISION
%left MINUS

%define parse.error verbose

%%

program : { tabSimb = creaLS(); /*ID PASA A SER $2*/ } ID LPAREN DPAREN LEFTKEY declarations statement_list RIGHTKEY { imprimirTabSimb(tabSimb); liberaLS(tabSimb); }
        ;

declarations : declarations VAR { tipo = VARIABLE; } identifier_list SEMICOLON
             | declarations CONST { tipo = CONSTANTE; } identifier_list SEMICOLON
             |
             ;

identifier_list : identifier
                | identifier_list COMMA identifier
                |
                ;

identifier : ID      { /* comprobar que no se redeclaren */ 
                            if(!perteneceTabSimb($1)) insertarTS($1,tipo);
                            else printf("ERROR, %s ya declarado anteriormente", $1);
                     }
           | ID ASSIGNOP expression { /* comprobar que no se redeclaren */ 
                                        if(!perteneceTabSimb($1)) insertarTS($1,tipo);
                                        else printf("ERROR, %s ya declarado anteriormente", $1);
                                    }
           ;

statement_list : statement_list statement
               |
               ; 

statement : ID ASSIGNOP expression SEMICOLON     { 
                                                    // ver si ID previamente declarado
                                                    if(!perteneceTabSimb($1)) printf("ERROR, %s ya declarado anteriormente", $1);     
                                                    else if (esConstante($1)) printf("ERROR");
                                                    else ;

                                                    //sw
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
                                                    }
                                                    $$ = $1;
                                               }
          | LEFTKEY statement_list RIGHTKEY
          | IF LPAREN expression DPAREN statement ELSE statement
          | IF LPAREN expression DPAREN statement %prec NO_ELSE
          | WHILE LPAREN expression DPAREN statement
          | PRINT LPAREN print_list DPAREN SEMICOLON
          | READ LPAREN read_list DPAREN SEMICOLON
          ;

print_list : print_item
           | print_list COMMA print_item
           ;


print_item : expression
           | STRING {/* solo almacenar para luego imprimir str1... */
                        insertarTS($1,CADENA); contCadenas++;
                    }        
           ;

read_list : ID                  { /* comprobar si declarado o no. Si es constante -> error */
                                                if(!perteneceTabSimb($1)) printf("ERROR, %s ya declarado anteriormente", $1);     
                                                else if (esConstante($1)) printf("ERROR");
                                                else ;
                                }
          | read_list COMMA ID  { /* comprobar si declarado o no. Si es constante -> error */
                                                if (!perteneceTabSimb($3)) printf("ERROR, %s ya declarado anteriormente", $3);     
                                                else if (esConstante($3)) printf("ERROR");
                                                else ;
                                }
          ;

expression : expression PLUSOP expression               {
                                                            concatenaLC($1, $3);
                                                            liberaLC($3);
                                                            Operacion oper;
                                                            oper.op = "addi";
                                                            oper.res = "$ty"; // (TO-DO) buscar primer registro temporal libre
                                                            oper.arg1 = "$tizq";    // (TO-DO) coger el campo res de $1 (recuperar res)
                                                            oper.arg2 = "$tder";    // (TO-DO)
                                                            insertaLC($1, finalLC($1), oper);
                                                            $$ = $1; // pasar al padre el resultado
                                                        }
           | expression MINUSOP expression              {
                                                            concatenaLC($1, $3);
                                                            liberaLC($3);
                                                            Operacion oper;
                                                            oper.op = "sub";
                                                            oper.res = "$ty"; // (TO-DO) buscar primer registro temporal libre
                                                            oper.arg1 = "$tizq";    // (TO-DO) coger el campo res de $1 (recuperar res)
                                                            oper.arg2 = "$tder";    // (TO-DO)
                                                            insertaLC($1, finalLC($1), oper);
                                                            $$ = $1; // pasar al padre el resultado
                                                        }
           | expression MULTIPLICATION expression       {
                                                            concatenaLC($1, $3);
                                                            liberaLC($3);
                                                            Operacion oper;
                                                            oper.op = "mul";
                                                            oper.res = "$ty"; // (TO-DO) buscar primer registro temporal libre
                                                            oper.arg1 = "$tizq";    // (TO-DO) coger el campo res de $1 (recuperar res)
                                                            oper.arg2 = "$tder";    // (TO-DO)
                                                            insertaLC($1, finalLC($1), oper);
                                                            $$ = $1; // pasar al padre el resultado

                                                        }
           | expression DIVISION expression             {
                                                            concatenaLC($1, $3);
                                                            liberaLC($3);
                                                            Operacion oper;
                                                            oper.op = "div";
                                                            oper.res = "$ty"; // (TO-DO) buscar primer registro temporal libre
                                                            oper.arg1 = "$tizq";    // (TO-DO) coger el campo res de $1 (recuperar res)
                                                            oper.arg2 = "$tder";    // (TO-DO)
                                                            insertaLC($1, finalLC($1), oper);
                                                            $$ = $1; // pasar al padre el resultado
                                                        }
           | MINUSOP expression %prec MINUS             {  
                                                            Operacion oper;
                                                            oper.op = "neg";
                                                            oper.res = "$tx"; // (TO-DO) buscar primer registro temporal libre
                                                            oper.arg1 = $1;
                                                            oper.arg2 = NULL;
                                                            //insertaLC($$, finalLC($$), oper);
                                                            $$ = $2; 
                                                        }
           | LPAREN expression DPAREN                   {   $$=$2; }
           | ID                                         {
                                                        
                                                        /* no se va a guardar/asignar nada. Solo ver si id está en la tabla para imprimir o sumar*/
                                                            if (!perteneceTabSimb($1)) printf("ERROR, %s ya declarado anteriormente", $1);  

                                                            //igual con lw
                                                            $$ = creaLS();
                                                            Operacion oper;
                                                            oper.op = "lw";
                                                            oper.res = "$tx"; // (TO-DO) buscar primer registro temporal libre
                                                            oper.arg1 = $1;
                                                            oper.arg2 = NULL;
                                                            insertaLC($$, finalLC($$), oper);
                                                            //guardar res
                                                        }
           | INTLITERAL                                 {
                                                            $$ = creaLS();
                                                            Operacion oper;
                                                            oper.op = "li";
                                                            oper.res = "$tx"; // (TO-DO) buscar primer registro temporal libre
                                                            oper.arg1 = $1;
                                                            oper.arg2 = NULL;
                                                            insertaLC($$, finalLC($$), oper);
                                                            //guardar res
                                                        }
           ;

%%

// comentarios -> trabajar con la PosicionListatabla de símbolos 

void yyerror(const char * s) {
    printf("Se ha producido un error en esta expresión %s\n",s);
}


