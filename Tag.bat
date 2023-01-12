REM - Script to tag all the git repositories

REM - This is the tag that will be applied to the repository
REM - for official releases, use version_x.y.z version
REM - for beta releases, use x.y.z_beta_n 
REM SET TAG=version_7.0.3
REM git tag %TAG% isn't working so the tags are explicit... use search/replace to update in all places

cd \ARP\BEToolbox\
git commit -a -m "Updated version numbers for 7.0.3 release"
git tag version_7.0.3
git push
git push --tags

cd \ARP\BEToolboxExtensions\
git commit -a -m "Updated version numbers for 7.0.3 release"
git tag version_7.0.3
git push
git push --tags

cd \ARP\Barlist\
git commit -a -m "Updated version numbers for 7.0.3 release"
git tag version_7.0.3
git push
git push --tags

cd \ARP\PGSuper\
git commit -a -m "Updated version numbers for 7.0.3 release"
git tag version_7.0.3
git push
git push --tags

cd \ARP\PGSuperIfcExtensions\
git commit -a -m "Updated version numbers for 7.0.3 release"
git tag version_7.0.3
git push
git push --tags

cd \ARP\XBeamRate\
git commit -a -m "Updated version numbers for 7.0.3 release"
git tag version_7.0.3
git push
git push --tags

cd \ARP\WBFL\
git commit -a -m "Updated version numbers for 7.0.3 release"
git tag version_7.0.3
git push
git push --tags

cd \ARP\BridgeLink\
git commit -a -m "Updated version numbers for 7.0.3 release"
git tag version_7.0.3
git push
git push --tags
