#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "list.h"
#include "str-common.h"


int indexOf_shift (char* base, char* str, int startIndex) {
    int    result;
    int    baselen = strlen(base);
	char* pos;
	// str should not longer than base
    if (strlen(str) > baselen || startIndex > baselen) {
		result = -1;
    } else {
        if (startIndex < 0 ) {
            startIndex = 0;
        }
        pos = strstr(base+startIndex, str);
        if (pos == NULL) {
            result = -1;
        } else {			
            result = pos - base;
        }
    }
    return result;
}


longstring   getLongString(FILE* fp){
#define CHUNK_SIZE 1024
#define MAX_LEN	   65536

	printf("%p\n",fp);
	char * listr ;
	List     List1;
	Iterator L1_Itr;
	int  i,    n=0, count = 0, total=0;
	longstring H;
	List1  = list_Init();	

	do{
		listr = (char*) malloc(CHUNK_SIZE);
		
		
		fgets(listr,CHUNK_SIZE,fp);
		
		//printf("\n%s",listr);
			
		listAddString(List1,listr);
		n = strlen(listr);
		printf("\n%d",n);
		total += n;
		count +=1;
	}while (n>=CHUNK_SIZE-1 && total< MAX_LEN);
	
	listr = (char*) malloc(total+1);
	strcpy(listr,"");
	
	L1_Itr = iterator_Init(List1);
	
	for(i=0 ;  i< count; i++){
		strcat(listr,iteratorGetNextString( L1_Itr)  );
	}

	H.String = listr;
	H.length = total;
	freeList(List1);
	
	return H;
}