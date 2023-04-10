#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stringmanip2.h"

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

s_str s_str_fromCharPtr(const gchar* str){

	char*   Id     = "string";
	int     len    = strlen(str)+1;
	s_str   retval   ;

	retval.Txt = str;
	g_strcpy(retval.Id, Id);
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

s_str   dup_s_str     (s_str x){
	int   len ;
	s_str retval;
	assert(isvalid_s_str(x));
	
	len    = strlen(x.Txt);
	retval = New_s_str(len+1);
	if(retval.Txt==NULL){
		printf("Could not allocate string");
		exit(0);
	}
	
	strcpy(retval.Txt, x.Txt);
	return retval;
}

void destroy_str(s_str str){
	
	assert( isvalid_s_str( str) );
	str.Id[0] = '\0';
	free(str.Txt);
	str.Txt = NULL;
}


short ends_With (s_str base, s_str str) {
	assert(isvalid_s_str(base));
	assert(isvalid_s_str(str));
	
    int blen = strlen(base.Txt);
    int slen = strlen(str.Txt);
    return (blen >= slen) && (0 == strcmp(base.Txt + blen - slen, str.Txt));
}

int length(s_str base){
	assert(isvalid_s_str(base));
	return strlen(base.Txt);
	
}



int  index_Of (s_str base, s_str str) {
	assert(isvalid_s_str(base));
	assert(isvalid_s_str(str));
	
    return indexOf_shift(base.Txt, str.Txt, 0);
}
/** use two index to search in two part to prevent the worst case
 * (assume search 'aaa' in 'aaaaaaaa', you cannot skip three char each time)
 */
int last_Index_Of (s_str base, s_str str) {
    
	int result;
	int start;
	int endinit;
	int end;
	int endtmp;
    
	assert(isvalid_s_str(base));
	assert(isvalid_s_str(str));
	// str should not longer than base
    if (strlen(str.Txt) > strlen(base.Txt)) {
        result = -1;
    } else {
        
		start   = 0;
        endinit = strlen(base.Txt) - strlen(str.Txt);
        end     = endinit;
		endtmp  = endinit;
		
        while(start != end) {
            start = indexOf_shift(base.Txt, str.Txt, start);
            end   = indexOf_shift(base.Txt, str.Txt, end);

            // not found from start
            if (start == -1) {
                end = -1; // then break;
            } else if (end == -1) {
                // found from start
                // but not found from end
                // move end to middle
                if (endtmp == (start+1)) {
                    end = start; // then break;
                } else {
                    end = endtmp - (endtmp - start) / 2;
                    if (end <= start) {
                        end = start+1;
                    }
                    endtmp = end;
                }
            } else {
                // found from both start and end
                // move start to end and
                // move end to base - strlen(str)
                start = end;
                end = endinit;
            }
        }//end while
        result = start;
    }//end if(strlen(str.Txt) > strlen(base.Txt))
    return result;
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


char    char_At_Index( s_str base, int index){
	
	assert(isvalid_s_str(base) );
	assert(index< strlen(base.Txt));
	
	return base.Txt[index];
}

short starts_With (s_str base, s_str str){
	
	assert(isvalid_s_str(base) );
	assert(isvalid_s_str(str)  );
	
	return ( indexOf_shift(base.Txt, str.Txt, 0)== 0 );
}
