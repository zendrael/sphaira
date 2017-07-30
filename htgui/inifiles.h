#ifndef _INIFILES_H
#define _INIFILES_H

char sret[255 * 2];

typedef struct _L_SECTION {

    char variable[40];
    char value[255];

} _L_SECTION;

typedef struct _INI_section {

    char namesection[40];
    int len;
    _L_SECTION reg[500];

} INI_section;

typedef struct _INI_inifile {

    char namefile[40];
    int len;
    char section[40][500];

} INI_inifile;

/* Protos ......*/
char *ini_get_str(char *sname_file, char *section, char *svalue,
		  char *sdefault);

int ini_get_int(char *sname_file, char *section, char *svalue,
		int idefault);

INI_section ini_get_vars(char *sname_file, char *section);

INI_inifile ini_get_section(char *sname_file);

#endif

