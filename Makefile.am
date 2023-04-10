
## Copyright (C) 2019 bisgsheun-Software Foundation, Inc.
## If you decided to switch over to libtool, you would have to
## change LIBRARIES to LTLIBRARIES  and .a to .la

bin_PROGRAMS= Combo.exe
lib_LIBRARIES=


INCLUDES =  -I ./include `pkg-config --cflags  gtk+-2.0` 
LDFLAGS  =  -L ./lib `pkg-config --libs   gtk+-2.0` 

Combo_exe_SOURCES=  Permutate.c resource.rc MainController.c string-lib/str-common.c string-lib/stringmanip3.c string-lib/LinkedList.c 


##Use C_ide to create automake.am and add some crucial missing files
##use autoscan to create configure.scan
##change it to configure.ac
##use automake to detect missing stuff in the configure.ac (RANLIb and AM_INIT)
##use autoheader to fill in the config.h.in
##use aclocal to bring in aclocal.m4 (without it automake will still not work)
##do automake --add-missing. Your makefile.in is created along with missing stuff
##Do autoconf and you have a solid configuration file
