#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <malloc.h>
#include "string-lib/str-common.h" 
#include "string-lib/stringmanip3.h" 
#include "string-lib/macro-mapping3.h"  /* support macros for lib */

#include "Controller-Perm-Share.h"
#include "MainController.h"

_string  OutString ;


void button_click_cb(GtkWidget* w, gpointer data){
	_string      Buffer, stub,stub2;
	int          i,FreeCount,R,iCheck,Total;
	struct       TakenPosition T;
	StringArray  Items;
	GtkWidget   *dialog, *GBuffer;
	
	//get pattern
	Buffer = str_alloc(128);
	_g_strncpy(
		Buffer,
		gtk_entry_get_text (
			GTK_ENTRY(PaternEntry)
		), 127
	);

	//split pattern
	Items = split(Buffer,STR(",") );
	Total = Items.size;

	// 6 ! is usually large enough
	if(Total > 6){
	    Total = 6;
	}


	stub2 = str_alloc(10);
	
	_g_strcpy(
		stub2,
		gtk_entry_get_text (
			GTK_ENTRY(AvailSpacesBox)
		)
	);

	R =0;
  	sscanf(STR2(stub2), "%d", &R);

  	if(
	    0 >= R ||
	    R > Total
	){
		stub =str_alloc(128);
		_g_strcpy(stub,"");		
	    
	    g_snprintf(
	      STR2(stub), 
	      127,
	      "The value of R is %d (not OK) ", R
	    ); 

	    
		dialog = gtk_dialog_new_with_buttons (
			STR2(stub),
			GTK_WINDOW(Mainwindow),
			GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_STOCK_OK,
		    GTK_RESPONSE_ACCEPT,
		    GTK_STOCK_CANCEL,
		    GTK_RESPONSE_REJECT,
		    NULL
		);

		gtk_dialog_run (GTK_DIALOG(dialog));	    

	    str_free(stub);
	    return;
	}
	

	T.Taken = (int*) malloc(sizeof(int)*(Total));
	T.Total = Total;
	T.Count = 0;
	T.R     = R;

	for(i=0; i< T.Total; i++){
	T.Taken[i] = 0;
	}

	OutString =  str_alloc(65536);

	iCheck = gtk_toggle_button_get_active (
		GTK_TOGGLE_BUTTON(PermutateCheck)
	);

	_g_strcpy(Buffer,"");

	permutate( Buffer, Items.List, T, 0, iCheck );

	
	// Put the result into the result box

	GBuffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (ResultBox));

	gtk_text_buffer_set_text (
		GTK_TEXT_BUFFER(GBuffer),
		STR2(OutString) ,
		-1
	);

}//=======================================================




void permutate(_string stub,_string *Units, TPL T, int Index, int iCheck ){

	int i;
	_string NewStub;
	

	
	for(i=Index; i<T.Total; i++){ //scan units 0,1,2...
		if(! isTaken(i, T) ){ // is this string already taken?
			//then don't bother
			
			//Else append string to the given stub
			NewStub = str_alloc(strlen(stub)+strlen(Units[i])+ 2);
			strcpy(NewStub,stub);  
			strcat(NewStub,Units[i] );


			if((T.R -T.Count)>1){ //Not yet in the last position ?

				T.Taken[T.Count] = i; //specify the string recently taken
				T.Count += 1;  //Allow the next level to check specified 
				//string
				

				// Let the next position(s) be done for us
				
				if(iCheck){
					permutate( NewStub,Units,T,0, iCheck);
				}else{
					permutate( NewStub,Units,T,i, iCheck);
				}

				T.Count -= 1; //back to our own position
				//reduce number of strings to check back to previous
				str_free(NewStub);
			}else{
				strcat(OutString,NewStub);
				strcat(OutString,STR("\r\n") );	
				str_free(NewStub);
			}//~if last position

		}//~if taken
	}//Next
/****/
}
 
short isTaken(int Index, TPL T){
	int i;
	
	for (i=0; i<T.Count; i++){
		if(Index == T.Taken[i]){
			return (1==1);
		}
	}

	return (1==0);
}
