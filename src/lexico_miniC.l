%{
#include "miniC.tab.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

int inicio_comentario = 0;
int errores_lexicos = 0;
%}
%x comentario
%option yylineno

digito              [0-9]
caracter            [a-zA-Z_]
entero              {digito}+
panico				[^a-zA-Z0-9/();,=+*\-{}"\n\t ]+
%%


[ \n\t]+                            	;
"//"(.*)[\n]                        	;
"/*"				            		{ yymore(); BEGIN(comentario); inicio_comentario = yylineno; }
<comentario>"*/"			    		{ BEGIN(INITIAL); }
<comentario>(.|\n)			   			{ yymore(); }
<comentario><<EOF>>			    		{ printf("Error: comentario no cerrado %d\n", inicio_comentario);
					      		errores_lexicos++;
				              			  return 0;}
void                               	return VOID;
var                                 	return VAR;
read                                	return READ;
print                               	return PRINT;
const					return CONST;
if					return IF;
else					return ELSE;
while					return WHILE;

({caracter})({caracter}|{digito})*		{if(yyleng>16){
						printf("\nERROR: identificador demasiado largo en linea %d: %s \n", yylineno, yytext);
						errores_lexicos++;}
						yylval.string = strdup(yytext);
						return ID;}

{entero}                            	{if(atoll(yytext)>pow(2, 31)){
						printf("\nERROR: entero demasiado grande en linea %d: %s \n", yylineno, yytext);
						errores_lexicos++;}
						yylval.string = strdup(yytext);
						return ENT;}

"("                                 	return PARI;
")"                                 	return PARD;
";"                                 	return PCOMMA;
","                                 	return COMMA;
"="                                	return ASSIG;
"+"                                 	return PLUSOP;
"-"                                 	return MINUSOP;
"*"					return ASTER;
"/"					return BARRA;
"{"					return CORI;
"}"					return CORD;
\"([^"\n]|\\.)*\"				{yylval.string = strdup(yytext);
						return CADE;}
\"([^"\n]|\\\")*			    	{printf("Error: cadena sin cerrar en linea %d\n", yylineno);
						errores_lexicos++;}
{panico}    					{printf("ERROR LEXICO: caracteres no validos en linea %d: %s \n", yylineno, yytext);
						errores_lexicos++;}
%%
