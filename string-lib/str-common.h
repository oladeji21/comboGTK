#ifndef STR_COMMON 
#define STR_COMMON

struct long_string{
    int length;
    char* String;
};
typedef struct long_string longstring;

int         indexOf_shift (char* base, char* str, int startIndex);
longstring  getLongString (FILE* fp); 
#endif