%{
#include "lexico1.h"
#define     MAX_INT     2147483648 
void error_lexico();
int comprobarNumero(char * d);
int comprobarLongitud(int longitud);
%}

digito              [0-9]
letra               [a-zA-Z]
entero              {digito}+

%x COMENT
%option yylineno

%%

[ \r\n\t]+                          ;
"//"(.*)[\n]                        ;

  /* Comentarios multilinea */
"/*"  	                                          { BEGIN(COMENT); }
<COMENT>([^*]|[*]+[^*/])*                         ;
<COMENT>[*]+"/"                                   { BEGIN(0); }
<COMENT><<EOF>>                                   { 
                                                    fprintf(stderr, "Error léxico: comentario sin cerrar\n");
                                                    return 0; 
                                                  }


var                                 return VAR;
const                               return CONST;
if                                  return IF;
else                                return ELSE;
while                               return WHILE;
print                               return PRINT;
read                                return READ;

  /* Cadenas */
\"([^"]|\\\\|\\\")*\"               { printf("Cadena: --%s--\n",yytext); }


({letra}|_)({letra}|{digito}|_)*    {
                                        if(comprobarLongitud(yyleng)) {
                                          return ID;
                                        } else {
                                          fprintf(stderr, "Error léxico: en la línea %d, cadena demasiado larga \"%s\"\n", yylineno, yytext);
                                          return ID;
                                        }
                                    }
{entero}                            {

                                        if(comprobarNumero(yytext)) {
                                          return INTLITERAL;
                                        } else {
                                          fprintf(stderr, "Error léxico: en la línea %d, entero demasiado grande \"%s\"\n",yylineno, yytext);
                                          return INTLITERAL;
                                        }
                                    }
"("                                 return LPAREN;		
")"                                 return RPAREN;
";"                                 return SEMICOLON;
","                                 return COMMA;
"="                                 return ASSIGNOP;
"+"                                 return PLUSOP;
"-"                                 return MINUSOP;
"*"                                 return MULTIPLICATION;
"/"                                 return DIVISION;
"{"                                 return LEFTKEY;
"}"                                 return RIGHTKEY;
{entero}[.]{entero}                 error_lexico();
[^ \r\n\t/a-zA-Z_0-9(){};,*=+\-]+   error_lexico();
%%

void error_lexico()
{
  printf("\nERROR, símbolo no reconocido %s\n",yytext);
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

void main() {
    int i;
    while (i=yylex())
        printf("%d %s\n",i,yytext);
    printf("FIN DE ANALISIS LEXICO\n");
}

