/*
 * 
 * HTGUI main file
 *
 */

#include <gtk/gtk.h>
#include <libgtkhtml/gtkhtml.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "inifiles.c"


//objects
GtkWidget *window;
GtkWidget *html;
GtkWidget *scrolledwindow;
HtmlDocument *html_doc;

gchar *text = "<html><body bgcolor='#D2D2D2'>No input file specified.</body></html>";

//prototypes
void linkClick( GtkWidget *html, char *link);
void callInterpreter(char *filename);
void loadScreen(FILE *stream);
void loadConfig( char *arq );

//main program
int main (int argc, char *argv[]){
	//++argv; --argc;
	
	//getting params
    gtk_init( &argc, &argv );
	
	//creating widgets
	window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
	scrolledwindow = gtk_scrolled_window_new( NULL, NULL );
	html_doc = html_document_new();
	html = html_view_new();
	
	//setting properties
	gtk_window_set_title( GTK_WINDOW( window ), "Application" );
    gtk_window_set_default_size( GTK_WINDOW( window ), 300, 150 );
	
	gtk_scrolled_window_set_policy( GTK_SCROLLED_WINDOW( scrolledwindow ),
                    				GTK_POLICY_AUTOMATIC,
                    				GTK_POLICY_AUTOMATIC );
	
	html_document_clear( html_doc );
    html_document_open_stream( html_doc, "text/html" );
	//inserting html content
    html_document_write_stream( HTML_DOCUMENT( html_doc ), text, -1/*strlen (text)*/);
    html_document_close_stream( html_doc );
	
	html_view_set_document( HTML_VIEW( html ), html_doc );
	
	//packing
	gtk_container_add( GTK_CONTAINER( window ), scrolledwindow );
	gtk_container_add(GTK_CONTAINER( scrolledwindow ), html );

	//connceting signals
	g_signal_connect( (gpointer)window, "delete_event", G_CALLBACK( gtk_main_quit ), NULL);
	g_signal_connect( (gpointer)html_doc, "link_clicked", G_CALLBACK( linkClick ), NULL);
	
	if( argc > 1 ){
		//callInterpreter( argv[1] );
		loadConfig( argv[1] );
	}
	
	//showing all
    gtk_widget_show_all( window );

	//start main loop
    gtk_main();

    return 0;
}

void linkClick( GtkWidget *html, char *link){
	//call interpreter for the file
	callInterpreter( link );
}

void callInterpreter(char *filename){
	FILE *in;
  	extern FILE *popen();
	char *interp = "./stp "; //Sphaira Transformation Program

    char *res = (char*)malloc( strlen(interp) + strlen(filename) );

    sprintf(res, "");
    strcat(res, interp);
    strcat(res, filename);

	if( ! ( in = popen( res , "r" ) ) ){
    		exit(1);
  	}

  	loadScreen( in );
  
}

void loadScreen(FILE *stream){
	char buff[512];

	__fpurge(stdin);
	__fpurge(stdout);

	html_document_clear( html_doc );
    html_document_open_stream( html_doc, "text/html" );
	
	//load content
	while (fgets(buff, sizeof(buff), stream) != NULL ) {
		//inserting html content
    	html_document_write_stream( HTML_DOCUMENT( html_doc ), buff, -1);
	}

    html_document_close_stream( html_doc );	
    
    //close the pipe
  	pclose(stream);
	
}

void loadConfig( char *arq ){
	//load application apearance
	gtk_window_set_title( GTK_WINDOW( window ), ini_get_str(arq, "app", "title", "Application") );
	
	gtk_widget_set_size_request( window , ini_get_int(arq, "app", "width", 500), ini_get_int(arq, "app", "height", 400) );
	
	gtk_window_set_position(GTK_WINDOW( window ), GTK_WIN_POS_CENTER);
	
	//start file
	callInterpreter( ini_get_str(arq, "start", "main", "") );
}

