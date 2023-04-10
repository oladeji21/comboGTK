#include <stdio.h>
#include <stdarg.h>
#ifndef STRINGMANIP
#define STRINGMANIP
#include "str-common.h"

	struct _s_str {
	      char   Id[10];
	const gchar* Txt;
	      int    Size;
	};
	typedef struct _s_str _string;

	struct str_array{
		struct _s_str * List;
		int    size;
	};

	
	typedef struct _s_str s_str;
	typedef struct str_array StringArray;


	// creating/converting s-str
	short   isvalid_s_str(s_str str1);
	s_str   New_s_str        (int W);
	s_str   s_str_fromCharPtr(gchar* str);
	gchar   *charPtr_from_s_str  (s_str str);
	s_str   copy_s_str       (s_str dst, s_str x);
	s_str   copy_free_s_str  (s_str old, s_str x);
	void    destroy_str      ( s_str str);

	//New String-scheme equivalents of new functions
	short       starts_With (s_str base, s_str str);
	short       ends_With   (s_str base, s_str str);
	int         index_Of    (s_str base, s_str str);
	int         last_Index_Of (s_str base, s_str str);

	StringArray _split( s_str base, s_str str);
	int         count_Occurrence(s_str base, s_str str);
	char        char_At_Index   ( s_str base, int index);
	s_str       str_From_Char   (char a);
	s_str       s_str_substring (s_str base, unsigned start, unsigned len);

	s_str       dup_s_str     (s_str x); 
	int         length        (s_str base); 
	int         indexOf_shift (char* base, char* str, int startIndex);
	s_str       catenate_s_str(s_str dst, s_str x);




	/*
	I decided to rid myself of vprintf and the others
	1. I could use STR2()  to get the strings that will go into these functions
	2. Just like any other function that require string, STR2()
	3. If something is wrong with the string 
	I am trying to send into the functions STR2() will find it
	4. I cannot send s_str to function that need char *
	5. And if I do, it is only in vprintf and variants that it happens and 
	output will definitely show my mistake
	6. My stuff is only going to 
		i.  Prevent use of unallocated string
		ii. prevent using uninitialized string (setting to \0)
		iii. Notify me of memory leakage
	But then Java does not do more than that
	7. Note that external lib Functions that modify your buffer also have a
	mechanism for making sure that you can control the size of buffer they 
	can clobber, so use them well
	8. Use only snprintf, strncat and strncpy
	9. To prevent memory leakage from external libs, take note of those functions
	that allocate memory, (and thus need to release them before program terminates)
	and reroute them through macro to help update you reference count
	*/

	//more
	short   isGreater  (s_str str1, s_str str2);
	short   isLess     (s_str str1, s_str str2);
	short   isEqual    (s_str str1, s_str str2);

#endif
