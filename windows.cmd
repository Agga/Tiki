@echo off &setlocal

if defined VS120COMNTOOLS (
	set generator=Visual Studio 12 2013
	set buildtool=VS120COMNTOOLS
	goto:createProjectFiles
)

if defined VS110COMNTOOLS (
	set generator=Visual Studio 11 2012
	set buildtool=VS110COMNTOOLS
	goto:createProjectFiles
)

echo no visual studio found
goto:end

:createProjectFiles

if not exist .\proj_win mkdir .\proj_win
pushd proj_win
cmake -G "%generator% Win64" ../src

for %%A in (%*) do (
	for %%B in (Debug, Release, Master) do (
		if "%%A" == "%%B" (
			call:build %%B
		)
	)
)

popd
goto:end

:build
echo Build %1
SETLOCAL ENABLEDELAYEDEXPANSION
CALL "!%buildtool%!..\IDE\devenv.exe" tiki.sln /Build %1
SETLOCAL DISABLEDELAYEDEXPANSION
goto:eof

:end

