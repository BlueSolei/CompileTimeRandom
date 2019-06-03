pushd %~dp0
cd build\bin
if "%1"=="tests" (CompileTimeRandomTest.exe) else (CompileTimeRandom.exe)
popd
