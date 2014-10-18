Flurry Bunch Cocos2dx
---

It's Unity3d implementation of Flurry for Native Gateway.

Native Gateway
---

Native Gateway allows you to create flexible native extension for cross-platform engines in easy way.

See implemetation of flurry integration as an example: https://github.com/vedi/flurry-bunch

Getting Started
---

> Before start with Flurry integration, please go through this document in order to integrate Native Gateway to your project: https://github.com/vedi/native-gateway-cocos2dx

> Draw your attention this repository includes all needed dependency including Flurry libs as well.

### iOS

Drag&Drop repository folder to your project in XCode.


### Android

1. In `Android.mk` of your project include files from `cocos2dx` folder to your sources,
2. Add jar-files from `android` folder to `libs` of your project.
3. Add `google-play-services_lib` from `android` folder as dependency of your project.

### General Hints

1. Add repository as submodule of your project typing in your `Classes` folder:
```
git submodule add https://github.com/vedi/flurry-bunch-cocos2dx.git flurry-bunch
```
2. Create static links for jars in `proj.android/libs` instead of copying:
```
ln -s ../../Classes/flurry-bunch/android/FlurryAnalytics-4.1.0.jar FlurryAnalytics-4.1.0.jar
ln -s ../../Classes/flurry-bunch/android/flurry-bunch.jar native-gateway-common.jar
```
3. Create a static link for `google-play-services_lib` (I put it to `android_deps` folder at roo of my project):
```
ln -s ../Classes/flurry-bunch/android/google-play-services_lib google-play-services_lib
```
4. Put new record to your `project.properties`. In my case it's:
```
android.library.reference.2=../android_deps/google-play-services_lib
```

### Configuration

Initialize FlurryBunch with your api key:
```cpp
#include "CCFlurryBunch.h"
...
CCFlurryBunch::initialize("XXX");
```

### What's the next

Explore `CCFlurryBunch.h`. You'll find the simple things here, which reflect well to flurry API.

Related projects
---

This repository includes prebuild native libraries, the sources are available at the following URLs:

* https://github.com/vedi/flurry-bunch-android
* https://github.com/vedi/flurry-bunch-ios
