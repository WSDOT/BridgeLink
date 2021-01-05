REM - Script to tag all the git repositories

REM - This is the tag that will be applied to the repository
REM - for official releases, use x.y.z version number
REM - for beta releases, use x.y.z_beta_n 
REM SET TAG=6.0.0_beta_5
REM git tag %TAG% isn't working so the takes are explicit... use search/replace to update in all places

cd \ARP\BEToolbox\
git commit -a -m "Updated version numbers for 6.0 Beta 5"
git tag 6.0.0_beta_5
git push
git push --tags

cd \ARP\BEToolboxExtensions\
git commit -a -m "Updated version numbers for 6.0 Beta 5"
git tag 6.0.0_beta_5
git push
git push --tags

cd \ARP\Barlist\
git commit -a -m "Updated version numbers for 6.0 Beta 5"
git tag 6.0.0_beta_5
git push
git push --tags

cd \ARP\PGSuper\
git commit -a -m "Updated version numbers for 6.0 Beta 5"
git tag 6.0.0_beta_5
git push
git push --tags

cd \ARP\XBRate\
git commit -a -m "Updated version numbers for 6.0 Beta 5"
git tag 6.0.0_beta_5
git push
git push --tags

cd \ARP\WBFL\
git commit -a -m "Updated version numbers for 6.0 Beta 5"
git tag 6.0.0_beta_5
git push
git push --tags

cd \ARP\BridgeLink\
git commit -a -m "Updated version numbers for 6.0 Beta 5"
git tag 6.0.0_beta_5
git push
git push --tags
