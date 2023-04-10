@echo off

if 0%1%==01 goto perfom_task1
if 0%1%==02 goto perfom_task2
if 0%1%==03 goto perfom_task3
if 0%1%==04 goto perfom_task4
if 0%1%==05 goto perfom_task5
if 0%1%==06 goto perfom_task6

echo Usage:  MakeTarget index 
echo where index = 1 - 6

echo 1. make Permutate.o 
echo 2. make resource.o 
echo 3. make MainController.o 
echo 4. make string-lib/str-common.o 
echo 5. make string-lib/stringmanip3.o 
echo 6. make string-lib/LinkedList.o 

goto done_all

:perfom_task1
cls
make Permutate.o
goto done_all

:perfom_task2
cls
make resource.o
goto done_all

:perfom_task3
cls
make MainController.o
goto done_all

:perfom_task4
cls
make string-lib/str-common.o
goto done_all

:perfom_task5
cls
make string-lib/stringmanip3.o
goto done_all

:perfom_task6
cls
make string-lib/LinkedList.o
goto done_all


:done_all
echo done
