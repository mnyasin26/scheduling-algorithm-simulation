@REM COMMAND UNTUK BUILD PROGRAM BY MUHAMAD NUR YASIN AMADUDIN
ECHO OFF

@REM add directory untuk folder
SET dir1="%cd%\PrioSchedulingNonPreemptive\*.c"
SET dir2="%cd%\RoundRobin\*.c"
SET dir3="%cd%\SJFNonPreemptive\*.c"
ECHO building program...
gcc.exe -g "%cd%\*.c" %dir1% %dir2% %dir3% -o "%cd%\run.exe"
ECHO build finished
ECHO program name="run.exe"
PAUSE
