%{
/* Declarations section */
	#include "tokens.hpp"
%}

%option noyywrap
%option yylineno
digit ([0-9])
nonzero ([1-9])
letter ([a-zA-Z]) 
whitespace ([\r\t\n ])
anything([!-~^"])
digitorletter ([a-zA-z0-9 \r\t])
%%

whitespace ;
void	return VOID;
int		return INT;
byte	return BYTE;
b		return B;
bool	return BOOL;
and		return AND;
or		return OR;
not		return NOT;
true	return TRUE;
false	return FALSE;
return	return RETURN;
if		return IF;
else	return ELSE;
while	return WHILE;
break	return BREAK;
continue	return CONTINUE;
default	return DEFAULT;
:		return COLON;
;		return SC;
,		return COMMA;
\(		return LPAREN;
\)		return RPAREN;
{		return LBRACE;
}		return RBRACE;
=		return ASSIGN;
"=="|"!="|"<"|">"|"<="|"=>"		return RELOP;
"+"|"-"|"*"|"/"			return BINOP;
"//"([^[\n\r]])*		return COMMENT; 
(letter)(digitorletter)*		return ID;
[1-9]([0-9])*			return NUM;
\"(anything)*(\n)		return -2;
\"(anything)*\"		return STRING;
.		return -1;


%%

