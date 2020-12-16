REM - Script to tag all the git repositories

REM - This is the tag that will be applied to the repository
REM - for official releases, use x.y.z version number
REM - for beta releases, use x.y.z_beta_n 
REM SET TAG=6.0.0_beta_4
REM git tag %TAG% isn't working so the takes are explicit... use search/replace to update in all places

cd \ARP\BEToolbox\
git tag 6.0.0_beta_4
git push
git push --tags

cd \ARP\BEToolboxExtensions\
git tag 6.0.0_beta_4
git push
git push --tags

cd \ARP\Barlist\
git tag 6.0.0_beta_4
git push
git push --tags

cd \ARP\PGSuper\
git tag 6.0.0_beta_4
git push
git push --tags

cd \ARP\XBRate\
git tag 6.0.0_beta_4
git push
git push --tags

cd \ARP\WBFL\
git tag 6.0.0_beta_4
git push
git push --tags

cd \ARP\BridgeLink\
git tag 6.0.0_beta_4
git push
git push --tags

