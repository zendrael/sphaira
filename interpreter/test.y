%{
#include <stdio_ext.h>
#include <string.h>
#include "globals.h"

void do_link( char* location, char* label  ){
	printf("<a href=\"%s\">%s</a>\n", location, label);
}

void do_button( char* iname, char* lbl  ){
	printf("<input type=\"submit\" name=\"%s\" value=\"%s\">\n", iname, lbl);
}

void do_text( char* iname, char* rows, char* cols  ){
	printf("<textarea cols=\"%s\" rows=\"%s\" name=\"%s\" wrap=\"VIRTUAL\"></textarea>\n", cols, rows, iname);
}

void do_edit( char* iname, char* len  ){
	printf("<input type=\"text\" size=\"%s\" name=\"%s\">\n", len, iname);
}

void yyerror(const char *str){
	fprintf(stderr,"<h2>Error:</h2><br><hr><br> %s in line %d<br>\n", str, linenum);
	//printf("%s\n", str);
	//printf("error: %s in line %d\n", str, linenum);
	//exit(0);
	
}
 
int yywrap(){
	return 1;
} 
  
main(int argc, char *argv[]){
	extern FILE *yyin;
	
	++argv; --argc;
	
	yyin = fopen( argv[0], "r");
	
	linenum = 1;
	startblockstack();
	//yydebug = 1;
	//errors = 0;
	
	__fpurge(stdin);
	__fpurge(stdout);
	
	printf("<html>\n");
	
	yyparse();
	
	printf("</html>");
}

%}

%token START PRINT GET LINK TABLE ROW COL DIV

%token NUMBER STRING

%token BUTTON EDIT TEXT

%token LPAREN RPAREN LBRAC RBRAC QUOTE DOTS COLON SEMICOLON

%%

program : starter DOTS commands endstart
		;
		
starter : START
			{
				printf("<body>\n");
			}
		|
		START LBRAC strings RBRAC
			{
				printf("<body %s>\n", $3);
			}
		;
		
		
endstart : SEMICOLON
			{
				printf("</body>\n");
			}
		;
			
commands : /* */
		|
		commands command
		;
		
command : PRINT LPAREN strings RPAREN
			{
				printf("%s\n", $3 );
			}
		|
		LINK LPAREN strings COLON strings RPAREN
			{
				do_link($3, $5);
			}
		|
		BUTTON LPAREN strings COLON strings RPAREN
			{
				do_button($3, $5);
			}
		|
		EDIT LPAREN strings COLON NUMBER RPAREN
			{
				do_edit($3, $5);
			}
		|
		TEXT LPAREN strings COLON NUMBER COLON NUMBER RPAREN
			{
				do_text($3, $5, $7);
			}
		|
		beginblock commands endblock
		;
		
beginblock : TABLE DOTS
			{
				insertblock( 1 );
				printf("<table>\n");
			}
		|
		TABLE LBRAC strings RBRAC DOTS
			{
				insertblock( 1 );
				printf("<table %s>\n", $3);
			}
		|
		ROW DOTS
			{
				insertblock( 2 );
				printf("<tr>\n");
			}
		|
		ROW LBRAC strings RBRAC DOTS
			{
				insertblock( 2 );
				printf("<tr %s>\n", $3);
			}
		|
		COL DOTS
			{
				insertblock( 3 );
				printf("<td>\n");
			}
		|
		COL LBRAC strings RBRAC DOTS
			{
				insertblock( 3 );
				printf("<td %s>\n", $3);
			}
		|
		DIV DOTS
			{
				insertblock( 4 );
				printf("<div>\n");
			}
		|
		DIV LBRAC strings RBRAC DOTS
			{
				insertblock( 4 );
				printf("<div %s>\n", $3);
			}
		;

endblock : SEMICOLON
			{
				switch( blockstack[bcount-1] ){
					case 1:	printf("</table>\n");
						break;
					case 2:	printf("</tr>\n");
						break;
					case 3:	printf("</td>\n");
						break;
					case 4:	printf("</div>\n");
						break;
				}
				removeblock();
			}
		;


strings : STRING
			{
				char* newstring;
				char* str2 = (char*)malloc( strlen( $1 )-1 );
				
				strncpy( str2, $1+1, strlen( $1 )-2 );
				
				newstring = (char*)malloc( sizeof( $1 ) );
				
				sprintf( newstring, "" );
				sprintf( newstring, "%s", str2);
				
				//free(str2);
				
				$$= newstring;
			}
		;

%%



