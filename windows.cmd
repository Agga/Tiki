@echo off

if not exist .\proj_win mkdir .\proj_win
pushd proj_win
cmake -G "Visual Studio 12 2013 Win64" ../src

for %%A in (%*) do (
	for %%B in (Debug, Release, Master) do (
		if "%%A" == "%%B" (
			call:build %%B
		)
	)
)

goto:end

:build
echo Build %1
CALL "%VS120COMNTOOLS%..\IDE\devenv.exe" tiki.sln /Build %1
goto:eof

:end
popd