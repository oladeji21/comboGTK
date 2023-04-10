#include <stdarg.h>
#ifndef STRINGMANIP
#define STRINGMANIP
	#include "str-common.h"

	struct str_array{
		char **List;
		int    size;
	};

	typedef struct str_array   StringArray;
	// New functions to manipulate strings

	//char      *strFromChar   (char a);
	short       endsWith (char * base, char* str) ; 
	short       startsWith  (char* base, char* str) ;
	int         indexOf (char* base, char* str); 
	int         lastIndexOf (char* base, char * str) ;
	int         countOccurrence(char* base, char* str);
	StringArray split( char * base, char * str);
	char       *substr (char * base, unsigned start, unsigned len);
	char        charAtIndex ( char * base, int index);
	char       *str_alloc (int size_t);

	//New macros to use in our code debug or no debug 

	#define _string   char *
	#define STR(str)  str
	#define STR2(str) str
	#define str_free  free

#endif