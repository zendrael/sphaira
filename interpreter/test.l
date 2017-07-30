%{

#include <stdio.h>
#include <string.h>
#include "globals.h"
#include "test.tab.h"

%}


%%
start					return START;
print					return PRINT;
get						return GET;
link					return LINK;
table					return TABLE;
row						return ROW;
col						return COL;
"div"					return DIV;

button					return BUTTON;
edit					return EDIT;
text					return TEXT;

"("						return LPAREN;
")"						return RPAREN;
"["						return LBRAC;
"]"						return RBRAC;
\'						return QUOTE;
:						return DOTS;
,						return COLON;
;						return SEMICOLON;
\n						{ linenum++; }/* ignore end of line */
[ \t]+					/* ignore whitespace */
[0-9]+					return NUMBER;

\'[^\']*\'				yylval = (char*)strdup(yytext); return STRING;

"/*" | 
"//" { 	register int c;
				while ( (c = input() ) )
    			{
    				if (c == '\n'){
    					linenum++;
    					break;
    				}
    				else if (c == '*')
      				{
       					if ((c = input()) == '/')
        					break;
       					else
        					unput (c);
      				}
      				else if (c == '\n')
       					linenum++;
      				else if (c == 0)
       					commenteof();
     			}
	}
    		
%%

commenteof()
{
	fprintf (stderr, "unexpected EOF inside comment at line %d\n",linenum);
 	exit (1);
}
