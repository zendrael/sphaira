/*
#define _UNDER_TEST_
*/
#include <stdio.h>
#include <string.h>
#include "inifiles.h"
/*
#ifdef _UNDER_TEST_
int main(int argv, char *argc[]);


int main(int argv, char *argc[])
{
    INI_section my_list;
    int xx;
    INI_inifile my_file;

    printf("VVV=== ini_get_inifile(\"%s\") =====VVV\n", argc[1]);
    my_file = ini_get_section(argc[1]);
    for (xx = 0; xx < my_file.len; xx++) {
	printf("[%s] ", my_file.section[xx]);
    }
    printf("\n^^^==================================^^^\n");


    printf("ini_get_int( \"%s\", \"%s\", \"%s\", %d ) => [%d] \n",
	   argc[1],
	   argc[2],
	   argc[3],
	   atoi(argc[4]), ini_get_int(argc[1], argc[2], argc[3],
				      atoi(argc[4]))
	);

    printf("ini_get_str( \"%s\", \"%s\", \"%s\", \"%s\" ) => [%s] \n",
	   argc[1],
	   argc[2],
	   argc[3],
	   argc[4], ini_get_str(argc[1], argc[2], argc[3], argc[4])
	);


    printf("VVV=== ini_get_vars( \"%s\",\"%s\") ====VVV\n", argc[1],
	   argc[2]);
    my_list = ini_get_vars(argc[1], argc[2]);
    printf("section:[%s]\n", my_list.namesection);

    for (xx = 0; xx < my_list.len; xx++)
	printf("%s = %s\n",
	       my_list.reg[xx].variable, my_list.reg[xx].value);
    printf("^^^======================================^^^\n");
}
#endif
*/


char *ini_get_str(char *sname_file, char *section, char *svalue, char *sdefault)
{
    FILE *inifile;
    char sread[255], ch;
    char term1[255], term2[255], term3[255];
    char t_section[255];
    size_t l_section, i, xx;


    l_section = strlen(section) + 2;

    sprintf(t_section, "[%s]", section);

    memset(sread, '\0', 255);

    if ((inifile = fopen(sname_file, "r")) == NULL) {
	printf("IO Error.\n");
	exit(1);
    }

    if (strlen(section)) {
	while (!feof(inifile))	// INI search section
	{
	    for (i = 0; i < l_section - 1; i++)
		sread[i] = sread[i + 1];

	    ch = getc(inifile);
	    sread[l_section - 1] = ch;
	    if (!strcmp(sread, t_section)) {
		ch = getc(inifile);	// Jump the ']' 
		break;
	    }
	}
    } else {
	ch = getc(inifile);
    }

    if (!feof(inifile)) {
	while (!feof(inifile) && ch != '[')	// loop while not end of section 
	{

	    //skip remarks in the .ini file ....
	    if (ch == '#')
		while (!feof(inifile) && (ch = getc(inifile) != 10));;

	    // read lines of section
	    if (isprint(ch) && !isspace(ch)) {

		xx = 0;
		memset(term1, '\0', 255);
//              while (!feof(inifile) && ('=' != ch) && (isprint(ch))) {
//                  if (isalnum(ch) || ch == '_' || ch == 32)
//                      term1[xx++] = ch;
//                  ch = getc(inifile);
//              }

		while (!feof(inifile) && ('=' != ch) && (isprint(ch))) {

		    if (isalnum(ch) || ch == '_')
			term1[xx++] = ch;

		    if (ch == 32) {
			while (!feof(inifile) && ch == 32)
			    ch = getc(inifile);

			if (ch != '=') {
			    term1[xx++] = 32;
			    term1[xx++] = ch;
			}

		    } else {
			ch = getc(inifile);
		    }
		}

		memset(term2, '\0', 255);
		if (ch == '=')
		    term2[0] = ch;

		ch = getc(inifile);
		xx = 0;
		memset(term3, '\0', 255);

		// skip the initial spaces 
		if (ch == ' ')
		    while (!feof(inifile) && isspace(ch = getc(inifile)));;

		while (!feof(inifile) && (isprint(ch))) {
		    term3[xx++] = ch;
		    ch = getc(inifile);
		}

		if ((strcmp(term2, "=")) ||
		    (strchr(term1, '#') != NULL) ||
		    (strchr(term3, '#') != NULL)) {
		    strcpy(sret, sdefault);

		} else {
		    if (!strcmp(term1, svalue)) {
			strcpy(sret, term3);
			return sret;

		    }

		}
	    }
	    ch = getc(inifile);
	}
    }

    fclose(inifile);
    strcpy(sret, sdefault);
    return sret;
}

/*********************************************/
int ini_get_int(char *sname_file, char *section, char *svalue,
		int idefault)
{
    char xdefault[255];

    sprintf(xdefault, "%d", idefault);
    return atoi(ini_get_str(sname_file, section, svalue, xdefault));
}

/*********************************************/
INI_section ini_get_vars(char *sname_file, char *section)
{
    FILE *inifile;
    char sread[255], ch;
    char term1[255], term2[255], term3[255];
    char t_section[255];
    size_t l_section, i, xx;
    INI_section pret;

    l_section = strlen(section) + 2;

    sprintf(t_section, "[%s]", section);

    memset(sread, '\0', 255);

    if ((inifile = fopen(sname_file, "r")) == NULL) {
	printf("IO Error.\n");
	exit(1);
    }

    if (strlen(section)) {
	while (!feof(inifile))	// INI search section
	{
	    for (i = 0; i < l_section - 1; i++)
		sread[i] = sread[i + 1];
	    ch = getc(inifile);
	    sread[l_section - 1] = ch;
	    if (!strcmp(sread, t_section)) {
		ch = getc(inifile);	// Jump the ']' 
		break;
	    }
	}
    } else {
	ch = getc(inifile);
    }

    if (!feof(inifile)) {
	i = 0;
	while (!feof(inifile) && ch != '[')	// loop while not end of section 
	{

	    //skip remarks in the .ini file ....
	    if (ch == '#')
		while (!feof(inifile) && ((ch = getc(inifile)) != 10));;

	    // read lines of section
	    if (isalnum(ch) && !isspace(ch)) {

		xx = 0;
		memset(term1, '\0', 255);
		while (!feof(inifile) && ('=' != ch) && (isprint(ch))) {

		    if (isalnum(ch) || ch == '_')
			term1[xx++] = ch;

		    if (ch == 32) {
			while (!feof(inifile) && ch == 32)
			    ch = getc(inifile);

			if (ch != '=') {
			    term1[xx++] = 32;
			    term1[xx++] = ch;
			    ch = getc(inifile);

			}

		    } else {
			ch = getc(inifile);
		    }
		}

		memset(term2, '\0', 255);
		if (ch == '=')
		    term2[0] = ch;

		ch = getc(inifile);
		xx = 0;
		memset(term3, '\0', 255);

		// skip the initial spaces 
		if (ch == ' ')
		    while (!feof(inifile) && isspace(ch = getc(inifile)));;

		while (!feof(inifile) && (isprint(ch))) {
		    term3[xx++] = ch;
		    ch = getc(inifile);
		}

		if ((!strcmp(term2, "=")) &&
		    (strchr(term1, '#') == NULL) &&
		    (strchr(term3, '#') == NULL)) {

		    sprintf(pret.reg[i].variable, "%s", term1);
		    sprintf(pret.reg[i++].value, "%s", term3);

		}
	    }
	    ch = getc(inifile);

	}
    }
    fclose(inifile);
    sprintf(pret.namesection, "%s", section);
    pret.len = i;
    return pret;
}

/*********************************************/

INI_inifile ini_get_section(char *sname_file)
{
    FILE *inifile;
    char ch;
    int i = 0, xx = 0;
    INI_inifile line;

    sprintf(line.namefile, "%s", sname_file);

    if ((inifile = fopen(sname_file, "r")) == NULL) {
	printf("IO Error.\n");
	exit(1);
    }

    while (!feof(inifile)) {
	ch = getc(inifile);
	if (ch == '[') {
	    ch = getc(inifile);
	    while ((!feof(inifile)) && (ch != 10) && ch != ']') {
		line.section[i][xx++] = ch;
		ch = getc(inifile);
	    }
	    xx = 0;
	    i++;
	}
    }
    line.len = i;
    fclose(inifile);
    return line;
}

/*********************************************/

// - EOF
