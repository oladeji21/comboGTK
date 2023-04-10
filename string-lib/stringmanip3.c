#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <assert.h>
#include "stringmanip3.h"

//find-function
//((static|const|virtual)\s+)?\w+[* ]+\w+\s*\(\s*(\w+[* ]+\w+\s*)?(\s*,\s*\w+[* ]+\w+)*\s*\)\s*\{

s_str   New_s_str   (int W){
	char* Id ="string";
	s_str retval;
	
	strcpy(retval.Id, Id);
	retval.Txt = (char*) malloc(W);
	
	if(retval.Txt==NULL){
		printf("Could not allocate string");
		exit(0);
	}

	retval.Txt[0] = '\0';
	retval.Size   = W;

	return retval;
}

s_str s_str_fromCharPtr(gchar* str){

	char*   Id     = "string";
	int     len    = strlen(str)+1;
	s_str   retval   ;

	retval.Txt = str;
	strcpy(retval.Id, Id);
	retval.Size = len;


	if(retval.Txt==NULL){
		printf("bad string");
		exit(0);
	}

	return retval;
}

char *  charPtr_from_s_str(s_str str){
	assert(isvalid_s_str(str));
	return str.Txt;
}

s_str  _g_strcpy(s_str str, const char *g){
	int Len;
	

	assert(isvalid_s_str(str));

	Len = strlen(g);
	assert(str.Size > Len);

	strcpy(str.Txt,g);
	
	return str;
}

s_str _g_strncpy(s_str str, const char *g,int len){
		
	assert(isvalid_s_str(str));

	assert(str.Size > len);
    strncpy (str.Txt, g, len);
	
	
	return str;
}

short   isvalid_s_str(s_str str1){
	return (strcmp(str1.Id ,"string")==0);
}

s_str   copy_s_str     (s_str dst, s_str x){
	int   len ;
	s_str retval;

	assert(isvalid_s_str(dst));
	assert(isvalid_s_str(x));
	
	len = strlen(x.Txt);
	assert(dst.Size >= len);



	strcpy(dst.Txt, x.Txt);


	return dst;
}

StringArray _split( s_str base, s_str str) {
	
	int     index1 = 0;
	int     index2 = 0, count = 0;
	s_str* string_array;
	
	assert(isvalid_s_str(base));
	assert(isvalid_s_str(str));
	
	count = count_Occurrence(base, str) +1 ;
	string_array = (s_str*) malloc(count*sizeof(s_str));
	
	StringArray ret;
	ret.size = count;

	index1=0; index2=0; count = 0;

	while(  (index2 = indexOf_shift(base.Txt,str.Txt,index1)) != -1  ) {
		string_array[count] = s_str_substring(base,index1,index2-index1);
		index1 = index2+ length(str);
		count++;
	}
	
	index2 = length(base);
	string_array[count] = s_str_substring(base,index1,index2-index1);

	ret.List = string_array;
	return ret;
}

int count_Occurrence(s_str base, s_str str){
	int index1=0, index2, count=0;
	
	assert(isvalid_s_str(base));
	assert(isvalid_s_str(str));
	
	while(  (index2 = indexOf_shift(base.Txt,str.Txt,index1)) != -1  ) {
		index1 = index2+ length(str);
		count++;
	}
	
	return count;
}

int length(s_str base){
	assert(isvalid_s_str(base));
	return strlen(base.Txt);
	
}

void destroy_str(s_str str){
	
	assert( isvalid_s_str( str) );
	str.Id[0] = '\0';
	free(str.Txt);
	str.Txt = NULL;
}

s_str s_str_substring(s_str base, unsigned start, unsigned len){
	
	s_str     ret;
	int       base_len;
	int       i;

	base_len = strlen(base.Txt);


	assert (isvalid_s_str(base) );
	assert (base.Txt != NULL);
	assert (base_len >= (start+len) );

	ret = New_s_str(len+1);

	for(i=0; i<len; i++){
		ret.Txt[i] = base.Txt[start+i];
	}
	ret.Txt[i] = '\0';
	return ret;
}

s_str   catenate_s_str     (s_str dst, s_str x){
	int   len ;
	s_str retval;

	assert(isvalid_s_str(dst));
	assert(isvalid_s_str(x));
	
	len = strlen(x.Txt);
	assert(dst.Size >= len);



	strcat(dst.Txt, x.Txt);


	return dst;
}
