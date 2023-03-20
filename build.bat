@REM COMMAND UNTUK BUILD PROGRAM BY MUHAMAD NUR YASIN AMADUDIN
ECHO OFF

@REM add directory untuk folder
SET dir1="%cd%\PrioSchedulingNonPreemptive\*.c"
ECHO building program...
gcc.exe -g "%cd%\*.c" %dir1%  -o "%cd%\run.exe"
ECHO build finished
ECHO program name="run.exe"
PAUSE
