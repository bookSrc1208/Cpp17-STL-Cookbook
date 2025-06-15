rem dir /b *.cpp

@echo off
set proStr1=TEMPLATE = app
set proStr2=CONFIG += console c++17
set proStr3=CONFIG -= app_bundle
set proStr4=CONFIG -= qt
set proStr5=SOURCES += \    
rem set name=dd
rem 预处理机制：批处理读取命令时是按行读取的（另外例如 for 命令等，其后用一对圆括号闭合的所有语句也当作一行），在处理之前要完成必要的预处理工作，这其中就包括对该行命令中的变量赋值。在不启用变量延迟，也不对变量动态捕获其扩展变化时，变量在预处理阶段不作改变
rem setlocal enabledelayedexpansion ，就是启用变量延迟，我们可以形象的认为是启用了“对变量动态捕获扩展变化”。而 ! 括起来的变量，就是要动态捕获扩展的目标变量，如果不需要，可以继续使用 % 括变量。

SETLOCAL ENABLEDELAYEDEXPANSION 
for /f "delims=" %%i in ('dir /a /b /on .\*.cpp') do (
echo %%i
set name=%%i
echo %name%
for /f "tokens=1* delims=." %%a in ("%name%") do (
	::输出第一个分段(令牌)
	rem echo %%a
	set pro=%%a.pro
	echo !pro!
	rem 将截取剩下的部分赋给变量remain，其实这里可以使用延迟变量开关
	echo %proStr1%>!pro!
	echo %proStr2%>>!pro!
	echo %proStr3%>>!pro!
	echo %proStr4%>>!pro!
	echo %proStr5%>>!pro!
	echo        %%i>>!pro!
	
	
)

)
pause