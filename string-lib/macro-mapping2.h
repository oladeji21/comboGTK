// New macros

#define _string      s_str
#define str_alloc    New_s_str	
#define str_free     destroy_str
#define STR(str)     s_str_fromCharPtr(str)
#define STR2(str)    charPtr_from_s_str(str)



//Macro Mapping

#define g_strcpy     copy_s_str
#define g_strdup     dup_s_str
#define strcat       catenate_s_str
#define endsWith     ends_With
#define strlen       length
#define indexOf      index_Of
#define lastIndexOf  last_Index_Of
#define substr       s_str_substring
#define split        _split
#define strFromChar  str_From_Char
#define charAtIndex  char_At_Index   
#define countOccurrence count_Occurrence
#define startsWith  starts_With
