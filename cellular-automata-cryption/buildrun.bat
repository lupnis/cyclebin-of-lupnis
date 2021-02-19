@echo off
g++ -c cac.cpp
g++ -c template.cpp
g++ template.o cac.o -o test
test
pause
cls
%0