REM - Script to commit, tag, and push all the git repositories for a release

REM - The tag is version_x.y.z.b, from WBFL_VERSION_STRING in WBFL\Include\WBFLVersion.h
call %ARPDIR%\BridgeLink\GetVersion.bat
if errorlevel 1 exit /B 1
SET TAG=version_%ARP_VERSION%
SET MESSAGE=Updated version numbers for %ARP_VERSION% release

cd /d %ARPDIR%\BEToolbox\
git commit -a -m "%MESSAGE%"
git tag %TAG%
git push
git push --tags

cd /d %ARPDIR%\BEToolboxExtensions\
git commit -a -m "%MESSAGE%"
git tag %TAG%
git push
git push --tags

cd /d %ARPDIR%\Barlist\
git commit -a -m "%MESSAGE%"
git tag %TAG%
git push
git push --tags

cd /d %ARPDIR%\PGSuper\
git commit -a -m "%MESSAGE%"
git tag %TAG%
git push
git push --tags

cd /d %ARPDIR%\PGSuperIfcExtensions\
git commit -a -m "%MESSAGE%"
git tag %TAG%
git push
git push --tags

cd /d %ARPDIR%\XBeamRate\
git commit -a -m "%MESSAGE%"
git tag %TAG%
git push
git push --tags

cd /d %ARPDIR%\WBFL\
git commit -a -m "%MESSAGE%"
git tag %TAG%
git push
git push --tags

cd /d %ARPDIR%\BridgeLink\
git commit -a -m "%MESSAGE%"
git tag %TAG%
git push
git push --tags
