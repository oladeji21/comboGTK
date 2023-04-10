@echo off

if (%1%==1) then goto perfom_task1
if (%1%==2) then goto perfom_task1
if (%1%==3) then goto perfom_task1
if (%1%==4) then goto perfom_task1
if (%1%==5) then goto perfom_task1

echo "Usage = MTarget <index> "
echo where index = 1 - 5
echo 1. Permutate.o
echo 2. MainController.o
echo 3. string-lib/str-common.o
echo 4. string-lib/stringmanip3.o
echo 5. resource.o

goto done_all



:perfom_task1
cls
make Permutate.o
goto done_all

:perfom_task2
cls
make MainController.o
goto done_all

:perfom_task3
cls
make string-lib/str-common.o
goto done_all

:perfom_task4
cls
make string-lib/stringmanip3.o
goto done_all

:perfom_task5
cls
make resource.o
goto done_all

:done_all
echo done
