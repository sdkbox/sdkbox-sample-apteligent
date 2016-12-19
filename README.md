
# How to run sdkbox samples

Steps:

~~~bash
mkdir samples
cd samples

# must clone this repo
git clone --depth 1 https://github.com/sdkbox/sdkbox-cocos2d-x-binary.git

# clone sample repo
git clone --depth 1 https://github.com/sdkbox/sdkbox-sample-apteligent.git

# run sample with specified language and platform
# eg: cpp and ios
## or
cd cpp && cocos run -p ios

./sdkbox-cocos2d-x-binary/run_sample.sh apteligent cpp ios
# javascript and android
## or
cd js && cocos run -p android

./sdkbox-cocos2d-x-binary/run_sample.sh apteligent js android

# <optional> if exists "download-depends.sh" in sample repo, execute it
# ./sdkbox-sample-apteligent/download-depends.sh

~~~

Memo:

1.  Sample repo and cocos2dx repo must be in same level directory

~~~
+-- sdkbox-cocos2d-x-binary
+-- sdkbox-sample-apteligent
| +-- cpp
| +-- lua
| \-- js
~~~
