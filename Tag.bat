REM - Script to tag all the git repositories

REM - This is the tag that will be applied to the repository
REM - for official releases, use version_x.y.z version
REM - for beta releases, use x.y.z_beta_n 
REM SET TAG=version_7.1.0_beta_0
REM git tag %TAG% isn't working so the tags are explicit... use search/replace to update in all places

cd \ARP\BEToolbox\
REM git commit -a -m "Updated version numbers for 7.1.0 release"
git tag version_7.1.0_beta_0
git push
git push --tags

cd \ARP\BEToolboxExtensions\
REM git commit -a -m "Updated version numbers for 7.1.0 release"
git tag version_7.1.0_beta_0
git push
git push --tags

cd \ARP\Barlist\
REM git commit -a -m "Updated version numbers for 7.1.0 release"
git tag version_7.1.0_beta_0
git push
git push --tags

cd \ARP\PGSuper\
REM git commit -a -m "Updated version numbers for 7.1.0 release"
git tag version_7.1.0_beta_0
git push
git push --tags

cd \ARP\PGSuperExperimental\
REM git commit -a -m "Updated version numbers for 7.1.0 release"
git tag version_7.1.0_beta_0
git push
git push --tags

cd \ARP\XBeamRate\
REM git commit -a -m "Updated version numbers for 7.1.0 release"
git tag version_7.1.0_beta_0
git push
git push --tags

cd \ARP\WBFL\
REM git commit -a -m "Updated version numbers for 7.1.0 release"
git tag version_7.1.0_beta_0
git push
git push --tags

cd \ARP\BridgeLink\
REM git commit -a -m "Updated version numbers for 7.1.0 release"
git tag version_7.1.0_beta_0
git push
git push --tags
