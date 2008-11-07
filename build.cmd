svn up .

IF EXIST ..\Boost\install GOTO gotboost
    IF EXIST ..\Boost GOTO boostbuild
        svn co svn://svn.felspar.com/external/Boost ..\Boost
    :boostbuild
    cd ..\Boost
    call build.cmd src
    cd ..\fost
:gotboost

IF EXIST OpenSSL GOTO gotopenssl
    svn co svn://svn.felspar.com/external/OpenSSL ..\OpenSSL
:gotopenssl

bjam -j%NUMBER_OF_PROCESSORS% release --toolset=msvc
..\dist\bin\ftest -b false ..\dist\bin\fost-core-test-smoke.dll ..\dist\bin\fost-crypto-test-smoke.dll

