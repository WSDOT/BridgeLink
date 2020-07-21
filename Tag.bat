REM - Script to tag all the git repositories

REM - This is the tag that will be applied to the repository
REM - for official releases, use x.y.z version number
REM - for beta releases, use x.y.z_beta_n 
SET TAG=6.0.0_beta_0

cd \ARP\BEToolbox\
git tag %TAG%
git push --tags

cd \ARP\BEToolboxExtensions\
git tag %TAG%
git push --tags

cd \ARP\Barlist\
git tag %TAG%
git push --tags

cd \ARP\PGSuper\
git tag %TAG%
git push --tags

cd \ARP\XBRate\
git tag %TAG%
git push --tags

cd \ARP\WBFL\
git tag %TAG%
git push --tags

cd \ARP\BridgeLink\
git tag %TAG%
git push --tags

