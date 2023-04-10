// New macros


#define str_alloc    New_s_str	
#define str_free     destroy_str
#define STR(str)     s_str_fromCharPtr(str)
#define STR2(str)    charPtr_from_s_str(str)



//Macro Mapping

#define g_strcpy     copy_s_str
#define g_strdup     dup_s_str
#define strcat       catenate_s_str
#define strcpy       copy_s_str
#define split        _split
#define strlen       length