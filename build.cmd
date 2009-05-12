@svn up .
@echo off

IF EXIST ..\dist (
    rmdir /s /q ..\dist
)

IF EXIST ..\Boost\install GOTO gotboost
    IF EXIST ..\Boost GOTO boostbuild
        svn co svn://svn.felspar.com/external/Boost ..\Boost
    :boostbuild
    pushd ..\Boost
    call build.cmd src
    popd
:gotboost

IF EXIST ..\OpenSSL GOTO gotopenssl
    svn co svn://svn.felspar.com/external/OpenSSL ..\OpenSSL
:gotopenssl

call compile.cmd %*
