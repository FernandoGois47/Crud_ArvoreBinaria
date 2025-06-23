@echo off
title Arvore Binaria - Compilador
echo ==========================================================
echo                COMPILADOR ARVORE BINARIA                
echo ==========================================================
echo.

echo Verificando GCC...
gcc --version >nul 2>&1
if %errorlevel% neq 0 (
    echo ERRO: GCC nao encontrado!
    echo.
    echo Instale o MinGW, Dev-C++ ou Code::Blocks
    echo.
    pause
    exit /b 1
)

echo GCC encontrado!
echo.

echo Compilando...
gcc -Wall -std=c99 main.c ArvoreBinaria.c -o programa.exe

if %errorlevel% neq 0 (
    echo.
    echo ERRO na compilacao!
    echo Verifique o codigo e tente novamente.
    echo.
    pause
    exit /b 1
)

echo.
echo Compilacao bem-sucedida!
echo.
echo Executando programa...
echo.
pause

start "Arvore Binaria" programa.exe

echo.
echo Programa executado em nova janela!
echo.
pause
