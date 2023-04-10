#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stringmanip.h"
#include "list.h"

short endsWith (char * base, char* str) {
		
    int blen = strlen(base);
    int slen = strlen(str);
    return (blen >= slen) && (0 == strcmp(base + blen - slen, str));
}

short   startsWith  (char* base, char* str) {
	return (indexOf(base,str)== 0 );
}


	
int indexOf (char* base, char* str) {
    return indexOf_shift(base, str, 0);
}	

int  lastIndexOf (char* base, char * str) {
    
	int result;
	int start;
	int endinit;
	int end;
	int endtmp;
    
	// str should not longer than base
    if (strlen(str) > strlen(base)) {
        return  -1;
    }
        
	start   = 0;
    end     = strlen(base) - strlen(str);
	endtmp  = end;
	endinit = end;
	
    while(start != end) {
        start = indexOf_shift(base, str, start);
        end   = indexOf_shift(base, str, end);

        // not found from start
        if (start == -1) {
            return -1; // then break;
        }

        if (end == -1) {
            // found from start
            // but not found from end
            // move end to middle(cover 1/2 remaining space @ 1ce)
            // start remains where we found the first
            // n log n
            if (endtmp == (start+1)) {
            	//this happens if in the previous iteration
            	// you found from start(start remains) but not from end
            	//and there was no more free space 
            	//(endtmp was = start+1)
                end = start; // then break;
            } else {
                end = (endtmp + start) / 2;
                if (end <= start) {
                	// happens iff endtmp = start+1
                	// mid point becomes start with integer div
                    end = start+1;
                }
                endtmp = end;
            }
        } else {
            // found from both start and end
            // move start to end and
            // move end to base - strlen(str)
            start = end;
            end   = endinit;
            //while galivanting over huge spaces we could have left
            // matches between newly found end and initial end
        }
    }//end while
    result = start;
    return result;
}

int countOccurrence(char* base, char* str){
	
	int index1=0, index2, count=0;
	
	while(  (index2 = indexOf_shift(base, str,index1)) != -1  ) {
		index1 = index2+ strlen(str);
		count++;
	}
	
	return count;
}

StringArray split( char * base, char * str) {
	
	int     index1 = 0;
	int     index2 = 0, count = 0;
	char**  string_array;
	StringArray ret;
	
	count = countOccurrence(base, str) +1 ;
	ret.size = count;

	string_array = (char**) malloc(count*sizeof(char*));

	index1=0; index2=0; count = 0;

	while(  (index2 = indexOf_shift(base,str,index1)) != -1  ) {
		string_array[count] = substr(base,index1,index2-index1);
		index1 = index2 + strlen(str);
		count++;
	}
	
	index2 = strlen(base);
	string_array[count] = substr(base,index1,index2-index1);

	ret.List = string_array;
	return ret;
}

char * substr (char * base, unsigned start, unsigned len){
	
	char     *ret;
	int       base_len;
	int       i;

	base_len = strlen(base);


	assert (base != NULL);
	assert (base_len >= (start+len) );

	ret = (char *)malloc(len+1);

	for(i=0; i<len; i++){
		ret[i] = base[start+i];
	}
	ret[i] = '\0';
	return ret;
}


char charAtIndex ( char * base, int index){
	
	assert(index< strlen(base));
	return base[index];
}

char *str_alloc (int size_t){
	char * X;
	X= (char*) malloc (sizeof(char)* size_t);
	X[0] = '\0';
	return X;
}
