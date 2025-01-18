%{
#include "miniC.tab.h"
#define     MAX_INT     2147483648 
void error_lexico();
int comprobarNumero(char * d);
int comprobarLongitud(int longitud);
int numErroresLexicos = 0;
%}

digito              [0-9]
letra               [a-zA-Z]
entero              {digito}+

%x COMENT
%option yylineno

%%

[ \r\n\t]+                          ;
"//"(.*)[\n]                        ;


"/*"  	                                          { BEGIN(COMENT); }
<COMENT>([^*]|[*]+[^*/])*                         ;
<COMENT>[*]+"/"                                   { BEGIN(0);}
<COMENT><<EOF>>                                   { 
                                                    printf("\nERROR en la línea %d: comentario sin cerrar.\n", yylineno);
                                                    numErroresLexicos++;
                                                    return 0; 
                                                  }                                             

var                                 return VAR;
const                               return CONST;
if                                  return IF;
else                                return ELSE;
do                                  return DO;
while                               return WHILE;
print                               return PRINT;
read                                return READ;

\"([^"]|\\\\|\\\")*\"               { yylval.lexema = strdup(yytext); return STRING; }

({letra}|_)({letra}|{digito}|_)*    {
                                        if(comprobarLongitud(yyleng)) {
                                          yylval.lexema = strdup(yytext);
                                          return ID;
                                        } else {
                                          fprintf(stderr, "\nERROR en la línea %d: cadena demasiado larga \"%s\"", yylineno, yytext);
                                          numErroresLexicos++;
                                          yylval.lexema = strdup(yytext);
                                          return ID;
                                        }
                                    }
{entero}                            {

                                        if(comprobarNumero(yytext)) {
                                          yylval.lexema = strdup(yytext);
                                          return INTLITERAL;
                                        } else {
                                          fprintf(stderr, "\nERROR en la línea %d: entero demasiado grande \"%s\"",yylineno, yytext);
                                          numErroresLexicos++;
                                          yylval.lexema = strdup(yytext);
                                          return INTLITERAL;
                                        }
                                    }
"("                                 return LPAREN;		
")"                                 return DPAREN;
";"                                 return SEMICOLON;
","                                 return COMMA;
"="                                 return ASSIGNOP;
"+"                                 return PLUSOP;
"-"                                 return MINUSOP;
"*"                                 return MULTIPLICATION;
"/"                                 return DIVISION;
"{"                                 return LEFTKEY;
"}"                                 return RIGHTKEY;
{entero}[.,]{entero}                error_lexico(1); yylval.lexema = strdup(yytext); return INTLITERAL;
[^ \r\n\t/a-zA-Z_0-9(){};,*=+\-]+   error_lexico(2); yylval.lexema = strdup(yytext); return ID;
%%

void error_lexico(int n)
{ 
  numErroresLexicos++;
  switch(n) {
    case 1:
            printf("\nERROR en la línea %d: número no reconocido \"%s\"", yylineno, yytext);
            break;
    case 2:
            printf("\nERROR en la línea %d: símbolo no reconocido \"%s\"", yylineno, yytext);
            break;
  }
}

int comprobarNumero(char * n) {
  if(atoll(n) > MAX_INT) {
    return 0;
  }
  return 1;
}

int comprobarLongitud(int longitud) {
  if(longitud > 32) {
    return 0;
  }
  return 1;
}