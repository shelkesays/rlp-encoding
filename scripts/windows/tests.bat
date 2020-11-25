:: Execute tests cases

:: Add Unit Test cases execution
echo [Running]: Unit Test Cases
IF exist %TESTDIR% (
    echo [Info]: Utils Test Case Execution starts
    START %TESTDIR%\Debug\utilstest.exe
    echo [Success]: Utils Test Case Execution ends
) ELSE (
    echo [Error]: Tests directory is not generated
)
echo [Info]: Unit Test Case execution complete
