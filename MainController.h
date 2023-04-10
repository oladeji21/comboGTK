struct TakenPosition{
	int *Taken;
	int Total;
	int Count;
	int R;
};

typedef struct TakenPosition TPL;

_string OutString;
short   isTaken(int Index, TPL T);
void    permutate( _string stub,_string *Units, TPL T,int Index, int iCheck );

extern GtkWidget* PermutateCheck;
extern GtkWidget* Mainwindow;
extern GtkWidget* PaternEntry;
extern GtkWidget* AvailSpacesBox;
extern GtkWidget* PermutateCheck;
extern GtkWidget* ResultBox;