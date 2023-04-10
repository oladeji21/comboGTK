Combo_C_SRC   =  Permutate.c MainController.c string-lib/str-common.c string-lib/stringmanip3.c string-lib/LinkedList.c 
Combo_CPP_SRC =  
Combo_RC_SRC  =  resource.rc 
Combo_LIB_SRC =  
Combo_O_SRC   =  $(patsubst %.c,%.o, $(Combo_C_SRC)) $(patsubst %.cpp,%.o,$(Combo_CPP_SRC)) $(patsubst %.rc,%.o, $(Combo_RC_SRC)) 




#Tools
RM       = rm.exe -f
CC       = tcc.exe -D__DEBUG__ -g
WINDRES  = windres.exe
ARCHIVE  = ar rcs


#Environment
LIBS    = -L C:/scripts/tcc/lib     `pkg-config --libs    gtk+-2.0` -luser32 -mwindows -m32 -g3 -Wl,-subsystem=gui
INC     = -I C:/scripts/tcc/include `pkg-config --cflags  gtk+-2.0`


Combo = Combo.exe

all:  $(Combo) 

touch: 
	touch  $(Combo_C_SRC) $(Combo_CPP_SRC) $(Combo_RC_SRC)

clean: 
	$(RM)  $(Combo_O_SRC) $(Combo)


$(Combo): $(Combo_O_SRC)
	$(CC) $(Combo_O_SRC)  -o $(Combo) $(Combo_LIB_SRC) $(LIBS) 

%.o: %.c
	$(CC) -c $(INC) -o $@ $^ $(warning creating c object $@)

%.o: %.cpp
	$(CC) -c $(INC) -o $@ $^ $(warning creating cpp object $@)


%.o: %.rc
	$(WINDRES)  -o $@ -i $^  $(warning creating rc object $@)


