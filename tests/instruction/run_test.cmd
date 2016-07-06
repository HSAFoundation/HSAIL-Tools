@echo on

set HSAILASM=%1
set NAME=%2
set DIR=%3

echo "Assembling"
%HSAILASM% -assemble %DIR%/%NAME%.hsail -o %NAME%_1.brig
if errorlevel 1 goto :error

echo "Disassembling"
%HSAILASM% -disassemble %NAME%_1.brig -o %NAME%_2.hsail
if errorlevel 1 goto :error

echo "Comparing with disassembly"
diff -u %DIR%/%NAME%.hsail %NAME%_2.hsail
if errorlevel 1 goto :error

echo "Decoding"
%HSAILASM% -decode %NAME%_1.brig -o %NAME%_3.yml
if errorlevel 1 goto :error

exit 0

:error
exit 1
