/**************************************
 *
 * globals.h
 *
 **************************************/
 
//vars for parsing
#define YYSTYPE char*
extern YYSTYPE yylval;
 
//vars for execution
#define RUNNING int = 0
 
int linenum, inblock;
int blockstack[50], bcount;

/*struct blockstack
{
   int block;
   struct blockstack *nxt;
} *btop, *baux;*/
