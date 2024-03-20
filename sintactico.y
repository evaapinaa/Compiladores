%{
        #include <stdio.h>
        #include <string.h>
        #include "listaSimbolos.c"
        Lista tabSimb;
        Tipo tipo;
        void yyerror(const char * s);
        int contCadenas = 1;
        extern int yylex();
%}

%union {
    char * cadena; /* solo string */
}

%token LPAREN DPAREN LEFTKEY RIGHTKEY VAR CONST COMMA ASSIGNOP SEMICOLON WHILE PRINT READ MINUS MINUSOP MULTIPLICATION DIVISION PLUSOP IF ELSE 
%token <cadena> INTLITERAL STRING ID 


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

statement : ID ASSIGNOP expression SEMICOLON   { /* ver si ID previamente declarado */
                                                if(!perteneceTabSimb($1)) printf("ERROR, %s ya declarado anteriormente", $1);     
                                                else if (esConstante($1)) printf("ERROR");
                                                else ;
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

expression : expression PLUSOP expression          
           | expression MINUSOP expression          
           | expression MULTIPLICATION expression    
           | expression DIVISION expression        
           | LPAREN expression DPAREN              
           | MINUSOP expression %prec MINUS        
           | ID         {/* no se va a guardar/asignar nada. Solo ver si id está en la tabla para imprimir o sumar*/
                            if (!perteneceTabSimb($1)) printf("ERROR, %s ya declarado anteriormente", $1);  
                        }
           | INTLITERAL
           ;

%%

// comentarios -> trabajar con la PosicionListatabla de símbolos 

int perteneceTabSimb(char *nombre) {
    PosicionLista pos = buscaLS(tabSimb, nombre);
    if (pos != finalLS(tabSimb) && strcmp(recuperaLS(tabSimb, pos).nombre, nombre) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void imprimirTabSimb(Lista tabSimb) {
    PosicionLista p = inicioLS(tabSimb);
    while (p != finalLS(tabSimb)) {
        Simbolo s = recuperaLS(tabSimb, p);
        printf("Nombre: %s, Tipo: %d, Valor: %d\n", s.nombre, s.tipo, s.valor);
        p = siguienteLS(tabSimb, p);
    }
}

void insertarTS(char * nombre, Tipo tipo) {
    Simbolo nuevoSimbolo;
    nuevoSimbolo.nombre = nombre;
    nuevoSimbolo.tipo = tipo;
    nuevoSimbolo.valor = contCadenas;
    insertaLS(tabSimb, finalLS(tabSimb), nuevoSimbolo);
}

int esConstante(char* nombre) {
    PosicionLista pos = buscaLS(tabSimb, nombre);
    if (pos != finalLS(tabSimb) && strcmp(recuperaLS(tabSimb, pos).nombre, nombre) == 0) {
        Simbolo s = recuperaLS(tabSimb, pos);
        if (s.tipo == CONSTANTE) {
            return 1;
        }
    }
    return 0;
}

void yyerror(const char * s) {
    printf("Se ha producido un error en esta expresión %s\n",s);
}