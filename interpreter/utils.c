/**************************************
 *
 * utils.c
 *
 **************************************/
 
#include <stdlib.h>
#include <stdio.h>
#include "globals.h"

void startblockstack(){
	bcount = 0;
}

void insertblock( int b){
   /*baux = (struct blockstack *)malloc( sizeof( baux ) );
   baux->block = b;
   baux->nxt = btop;
   btop = baux;
   */
   blockstack[bcount] = b;
   bcount++;
   
}

void removeblock(void){
   /*if (vazio(topo))
   {*/
   /*baux = btop;
   btop = btop->nxt;
   free(baux);
	*/
	bcount--;
}

