# BidmadPlugin

BidmadPlugin is a plugin for using Bidmad, a mobile app advertisement SDK, in Unity.<br>
You can use the plugin to serve banner/interstitial/reward ads in your Unity mobile app.<br>

## Getting started
- [Download the latest sample project](https://github.com/bidmad/Bidmad-Cocos2dx/archive/master.zip)
- [Download the latest plugin](https://github.com/bidmad/Bidmad-Cocos2dx/releases)

### 1. Add Plugin
#### 1.1 Android

1. Copy the Classes/bidmad folder of the downloaded sample project to your game project.<br>

*If using Android.mk, add bidmad source.
```cpp
LOCAL_SRC_FILES := $(LOCAL_PATH)/hellocpp/main.cpp \
                   ...
                   $(LOCAL_PATH)/../../../Classes/bidmad/RewardInterface.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/InterstitialInterface.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/BannerInterface.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/CommonInterface.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/GoogleGDPRInterface.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/RewardController.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/RewardCallback.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/InterstitialController.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/InterstitialCallback.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/BannerController.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/BannerCallback.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/CommonController.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/GoogleGDPRController.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/GoogleGDPRCallback.cpp
```
*If using Cmake List, add bidmad source as below.
```cpp
list(APPEND GAME_SOURCE
     Classes/AppDelegate.cpp
     Classes/HelloWorldScene.cpp
     Classes/bidmad/CommonInterface.cpp
     Classes/bidmad/BannerInterface.cpp
     Classes/bidmad/InterstitialInterface.cpp
     Classes/bidmad/RewardInterface.cpp
     Classes/bidmad/GoogleGDPRInterface.cpp
     )
list(APPEND GAME_HEADER
     Classes/AppDelegate.h
     Classes/HelloWorldScene.h
     Classes/bidmad/CommonInterface.h
     Classes/bidmad/BannerInterface.h
     Classes/bidmad/InterstitialInterface.h
     Classes/bidmad/RewardInterface.h
     Classes/bidmad/GoogleGDPRInterface.h
     )
if(ANDROID)
    ...
    list(APPEND GAME_SOURCE
         proj.android/app/jni/hellocpp/main.cpp
         Classes/bidmad/android/CommonController.cpp
         Classes/bidmad/android/BannerController.cpp
         Classes/bidmad/android/BannerCallback.cpp
         Classes/bidmad/android/InterstitialCallback.cpp
         Classes/bidmad/android/InterstitialController.cpp
         Classes/bidmad/android/RewardCallback.cpp
         Classes/bidmad/android/RewardController.cpp
         Classes/bidmad/android/GoogleGDPRCallback.cpp
         Classes/bidmad/android/GoogleGDPRController.cpp
         )
    list(APPEND GAME_HEADER
         Classes/bidmad/android/CommonController.h
         Classes/bidmad/android/BannerController.h
         Classes/bidmad/android/BannerCallback.h
         Classes/bidmad/android/InterstitialCallback.h
         Classes/bidmad/android/InterstitialController.h
         Classes/bidmad/android/RewardCallback.h
         Classes/bidmad/android/RewardController.h
         Classes/bidmad/android/GoogleGDPRCallback.h
         Classes/bidmad/android/GoogleGDPRController.h
         )
    ...
endif()
```

2. Copy the proj.android-studio/bidmad.gradle file of the downloaded sample project to the game project.<br>
3. Find [apply plugin:'com.android.application'] in proj.android-studio/build.gradle file and add the code below.

```cpp
apply from: "bidmad.gradle"
```

4. Find the application tag in the proj.android-studio/app/AndroidManifest.xml file and add the Google APPLICATION_ID.
```cpp
<application
    ...
    <meta-data
        android:name="com.google.android.gms.ads.APPLICATION_ID"
        android:value="ca-app-pub-XXXXXX~XXXXXX"/>
</application>
```

5. Apps that target children and are vetted by the PlayStore require additional setup to use certified ad networks.<br> 
If your app is targeting children, check out our [guide](https://github.com/bidmad/Bidmad-Cocos2dx/wiki/Additional-setup-guide-for-PlayStore-app-targeting-by-age.) for further setup.<br>

6. If targeting Android 12 version, please check [AD_ID Permission Guide](https://github.com/bidmad/Bidmad-Cocos2dx/wiki/AD_ID-Permission-Guide%5BENG%5D).

*Bidmad uses the AndroidX library. If it is not an AndroidX project, please migrate to AndroidX.

#### 1.2 iOS

1. Copy the Classes/bidmad folder of the downloaded sample project to your game project and add it to Xcode.<br>
*If using Cmake List, add bidmad source as below.
```cpp
list(APPEND GAME_SOURCE
     Classes/AppDelegate.cpp
     Classes/HelloWorldScene.cpp
     Classes/bidmad/CommonInterface.cpp
     Classes/bidmad/BannerInterface.cpp
     Classes/bidmad/InterstitialInterface.cpp
     Classes/bidmad/RewardInterface.cpp
     Classes/bidmad/GoogleGDPRInterface.cpp
     )
list(APPEND GAME_HEADER
     Classes/AppDelegate.h
     Classes/HelloWorldScene.h
     Classes/bidmad/CommonInterface.h
     Classes/bidmad/BannerInterface.h
     Classes/bidmad/InterstitialInterface.h
     Classes/bidmad/RewardInterface.h
     Classes/bidmad/GoogleGDPRInterface.h
     )
if(ANDROID)
    ...
elseif(APPLE)
    if(IOS)
        list(APPEND GAME_HEADER
             proj.ios_mac/ios/AppController.h
             proj.ios_mac/ios/RootViewController.h
             Classes/bidmad/ios/CommonBridgeCpp.h
             Classes/bidmad/ios/CommonBridgeObjC.h
             Classes/bidmad/ios/BannerBridgeCpp.h
             Classes/bidmad/ios/BannerBridgeObjC.h
             Classes/bidmad/ios/InterstitialBridgeCpp.h
             Classes/bidmad/ios/InterstitialBridgeObjC.h
             Classes/bidmad/ios/RewardBridgeCpp.h
             Classes/bidmad/ios/RewardBridgeObjC.h
             Classes/bidmad/ios/GoogleGDPRBridgeCpp.h
             Classes/bidmad/ios/GoogleGDPRBridgeObjC.h
             )
        set(APP_UI_RES
            proj.ios_mac/ios/LaunchScreen.storyboard
            proj.ios_mac/ios/LaunchScreenBackground.png
            proj.ios_mac/ios/Images.xcassets
            )
        list(APPEND GAME_SOURCE
             proj.ios_mac/ios/main.m
             proj.ios_mac/ios/AppController.mm
             proj.ios_mac/ios/RootViewController.mm
             proj.ios_mac/ios/Prefix.pch
             ${APP_UI_RES}
             Classes/bidmad/ios/CommonBridgeCpp.mm
             Classes/bidmad/ios/CommonBridgeObjC.mm
             Classes/bidmad/ios/BannerBridgeCpp.mm
             Classes/bidmad/ios/BannerBridgeObjC.mm
             Classes/bidmad/ios/InterstitialBridgeCpp.mm
             Classes/bidmad/ios/InterstitialBridgeObjC.mm
             Classes/bidmad/ios/RewardBridgeCpp.mm
             Classes/bidmad/ios/RewardBridgeObjC.mm
             Classes/bidmad/ios/GoogleGDPRBridgeCpp.mm
             Classes/bidmad/ios/GoogleGDPRBridgeObjC.mm
             )
    elseif(MACOSX)
    ...
endif()
```
2. After adding the Classes/bidmad folder, please follow the import guide below.

<details markdown="1">
<summary>Import guide for Cocos2DX 4.X and above (Manual Library Import)</summary>
<br>

- Copy the /proj.ios_mac/libBidmad folder of the downloaded sample project to the game project and add it to Xcode.<br>
*All frameworks in libBidmad are set to the Do not Embed option when adding Xcode.
- Inside Classes / bidmad / ios, BidmadSwiftSupport.swift file should be imported, and select "Don't Create" button.<br>
- Inside Xcode Project, under settings for mobile target, please set the following:
    - Build Settings → Other Linker Flags → if no "-ObjC", add it.
    - General → Deployment Info → iOS Minimum Requirement is set to "iOS 11".  
    - Build Settings → Bitcode Enable is set to NO.
    - Build Settings → Swift Language Version is set to "Swift 5".
- Add the following library: (Inside "Link Binary With Libraries" in Target Build Settings → Build Phases, add the following library) <br>
    - StoreKit.framework <br>
    - MobileCoreServices.framework <br>
    - WebKit.framework <br>
    - MediaPlayer.framework <br>
    - CoreMedia.framework <br>
    - AVFoundation.framework <br>
    - CoreTelephony.framework <br>
    - SystemConfiguration.framework <br>
    - AdSupport.framework <br>
    - CoreMotion.framework <br>
    - Accelerate.framework <br>
    - libresolv.9.tbd <br>
    - libc++.tbd <br>
    - libz.tbd <br>
    - libsqlite3.tbd <br>
    - libbz2.tbd <br>
    - libxml2.tbd <br>
    - libiconv.tbd <br>
    - libc++abi.tbd (newly required from sdk v3.5.0.0) <br>
    - Security.framework <br>
</details>

<details markdown="1">
<summary>Import guide for Cocos2DX 3.X (CocoaPods Library Import)</summary>
<br>

- After closing the Xcode Project, go to the folder containing the Xcode Project in the terminal and issue the pod init command. (If the command does not work, please install CocoaPods)
- After that, write the following inside the Podfile.
```
platform :ios, '11.0'

target 'MyGame-desktop' do
  # Comment the next line if you don't want to use dynamic frameworks
  use_frameworks!

  # Pods for MyGame-desktop

end

target 'MyGame-mobile' do
  use_frameworks! :linkage => :static

  # Pods for MyGame-mobile
  pod 'BidmadSDK', '4.0.1.1'
  pod 'OpenBiddingHelper', '4.0.1.1'
  pod 'BidmadAdapterFNC/ForGame', '4.0.0.2'
  pod 'BidmadAdapterFC', '4.0.0.0'

end

```
- After saving the changed Podfile, go to the folder containing the Xcode Project in the terminal and issue the pod install command.
- In the Xcode Project, in the build settings for mobile target, set the following values.
    - ENABLE_BITCODE → NO
    - General → Deployment Info → iOS Minimum Requirement is set to "iOS 11".
- Inside the Xcode Project, in the build settings for mobile target, add the following values:
    - GCC_PREPROCESSOR_DEFINITIONS → $(inherited)
    - LIBRARY_SEARCH_PATHS → $(inherited)
    - OTHER_LDFLAGS → $(inherited)
    - SWIFT_VERSION → Swift 5
</details>

3. After performing the import guide according to the Cocos2DX version, add GADApplicationIdentifier to info.plist.<br>
*GADApplicationIdentifier can be found in Google Admob.
```
    <key>GADApplicationIdentifier</key>
    <string>ca-app-pub-XXXXXX~XXXXXX</string>
```

4. Follow the [guide](https://github.com/bidmad/Bidmad-Cocos2dx/wiki/Preparing-for-iOS-14%5BENG%5D) to apply app tracking transparency approval request pop-up and SKAdNetwork.<br>

If you're looking for a guide to the privacy requirements of the Apple Store, [see here](https://github.com/bidmad/Bidmad-Cocos2dx/wiki/Apple-privacy-survey%5BENG%5D).

### 2. Using Plugin

#### 2.1 BidmadSDK Initialization

- Upon starting point of your app, please call initalizeSdk() Function from CommonInterface.
- If initializeSdk is not being called, SDK will intialize itself upon loading your first ad, which subsequently may delay your first loading.
```
    CommonInterface::initializeSdk()
```

- For interstitial or rewarded ads, intead of calling initializeSdk(),
at the starting point of your app, load your ad, and show it at the point of your choice.
  

#### 2.2 Interstitial

- Create InterstitialInterface to request interstitial ad.
- Before displaying an interstitial ad, check whether the ad is loaded through isLoaded.
```cpp
#include "bidmad/InterstitialInterface.h"

InterstitialInterface ii;
void loadInterstitial()
{
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    char *interstitialZoneId = (char*)"228b95a9-6f42-46d8-a40d-60f17f751eb1";
    #elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    char *interstitialZoneId = (char*)"e9acd7fc-a962-40e4-aaad-9feab1b4f821";
    #endif
    
    //Interstitial Create
    ii = new InterstitialInterface(interstitialZoneId);
    
    //Callback Setting
    ii->setOnLoadCallback(onInterstitialLoad);
    ii->setOnShowCallback(onInterstitialShow);
    ii->setOnFailCallback(InterstitialFail);
    ii->setOnCloseCallback(InterstitialClose);

    ii->load();
}
void showInterstitial()
{
    if(ii->isLoaded()){
        ii->show();
    }
}
```

#### 2.3 Reward

- RewardInterface is created to request a reward ad.
- Before displaying an reward ad, check whether the ad is loaded through isLoaded.
```cpp
#include "bidmad/RewardInterface.h"

RewardInterface ri;
void loadReward()
{
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    char* rewardZoneId = (char*)"29e1ef67-98d2-47b3-9fa2-9192327dd75d";
    #elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    char *rewardZoneId = (char*)"7d9a2c9e-5755-4022-85f1-6d4fc79e4418";
    #endif
    
    ri = new RewardInterface(rewardZoneId);
    
    //Callback Setting
    ri->setOnLoadCallback(onRewardLoad);
    ri->setOnShowCallback(onRewardShow);
    ri->setOnCompleteCallback(onRewardComplete);
    ri->setOnCloseCallback(onRewardClose);
    ri->setOnFailCallback(onRewardFail);
    ri->setOnSkipCallback(onRewardSkip);

    ri->load();
}
void showReward()
{
    if(ri->isLoaded()){
        ri->show();
    }
}
```

#### 2.4 Banner

- Create a BannerInterface to request banner ads.
```cpp
#include "bidmad/BannerInterface.h"

void initBanner()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    char *banner50 = (char*)"1c3e3085-333f-45af-8427-2810c26a72fc";
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    char *banner50 = (char*)"944fe870-fa3a-4d1b-9cc2-38e50b2aed43";
#endif

    //Banner Create
    bi = new BannerInterface(banner50);

    bi->setInterval(90);

    //Callback Setting
    bi->setOnLoadCallback(onBannerLoad);
    bi->setOnFailCallback(onBannerFail);
}
void loadBanner(posX, posY)
{
    bi->load(posY);
    // bi->load(posX, posY);
}
void removeBanner()
{
    bi->removeBanner();
}
void hideBanner()
{
    bi->hideBannerView();
}
void showBanner()
{
    bi->showBannerView();
}
```
- To implement onResume/onPause, inherit Apllication and implement applicationDidEnterBackground/applicationWillEnterForeground.
```cpp
#include "bidmad/BannerInterface.h"

class BannerSampleScene : public cocos2d::Scene, Application
{
public:
    ...
    virtual bool applicationDidFinishLaunching();
    virtual void applicationDidEnterBackground();
    virtual void applicationWillEnterForeground();
};

...

void BannerSampleScene::applicationDidEnterBackground() {
    if(bi != nullptr)
        bi->onPause();
}

void BannerSampleScene::applicationWillEnterForeground() {
    if(bi != nullptr)
        bi->onResume();
}
```

### 3 Callback

- Plugin provides Callback such as Load / Show / Fail according to the advertisement type.<br>
- If separate processing is required for the corresponding action, register a function to handle it.

#### 3.1 Interstitial Callback
```cpp
void onInterstitialLoad(char* zoneId)
{
    CCLOG("onInterstitialLoad");
}
void onInterstitialShow(char* zoneId)
{
    CCLOG("onInterstitialShow");
}
void InterstitialClose(char* zoneId)
{
    CCLOG("InterstitialClose");
}
void InterstitialFail(char* zoneId)
{
    CCLOG("InterstitialFail");
}
...
    ii->setOnLoadCallback(onInterstitialLoad);
    ii->setOnShowCallback(onInterstitialShow);
    ii->setOnFailCallback(InterstitialFail);
    ii->setOnCloseCallback(InterstitialClose);
...
```
#### 3.2 Reward Callback
```cpp
void onRewardLoad(char* zoneId)
{
    CCLOG("onRewardLoad");
}
void onRewardShow(char* zoneId)
{
    CCLOG("onRewardShow");
}
void onRewardComplete(char* zoneId)
{
    CCLOG("onRewardComplete");
}
void onRewardSkip(char* zoneId)
{
    CCLOG("onRewardSkip");
}
void onRewardClose(char* zoneId)
{
    CCLOG("onRewardClose");
}
void onRewardFail(char* zoneId)
{
    CCLOG("onRewardFail");
}

...
    ri->setOnLoadCallback(onRewardLoad);
    ri->setOnShowCallback(onRewardShow);
    ri->setOnCompleteCallback(onRewardComplete);
    ri->setOnCloseCallback(onRewardClose);
    ri->setOnFailCallback(onRewardFail);
    ri->setOnSkipCallback(onRewardSkip);
...
```

#### 3.3 Banner Callback
```cpp
void onBannerLoad(char* zoneId)
{
    CCLOG("onBannerLoad");
}
void onBannerFail(char* zoneId)
{
    CCLOG("onBannerFail");
}

...
    bi->setOnLoadCallback(onBannerLoad);
    bi->setOnFailCallback(onBannerFail);
...
```

### 4. Plugin Function

#### 4.1 Interstitial

*Interstitial ads are handled through InterstitialInterface, which is a list of functions for this.

Function|Description
---|---
public InterstitialInterface(char* zoneId)|This is the BidmadInterstitial constructor, Set the ZoneId
public void load()|Request an ad with the ZoneId entered in the constructor.
public void show()|Display the loaded advertisement.
public bool isLoaded()|Check if the ad is loaded.
public void setAutoReload(bool isAutoReload)|Load the next ad after Show. This option defaults to true, and if a failCallback is received, the reload operation is not performed.
public void setCUID(char*)|Setting CUID Property of each ad type
public void setOnLoadCallback(void (*_onLoadCallback) (char *))|If an Function is registered, the registered Function is executed when the interstitial ad is loaded.
public void setOnShowCallback(void (*_onShowCallback) (char *))|If an Function is registered, the registered Function is executed when the interstitial ad is shown.
public void setOnFailCallback(void (*_onFailCallback) (char *))|If an Function is registered, the registered Function is executed when the load of interstitial ad through ZoneId fails.
public void setOnCloseCallback(void (*_onCloseCallback) (char *))|If an Function is registered, the registered Function is executed when the interstitial ad is closed.

#### 4.2 Reward

*Rewarded ads are processed through RewardInterface, and this is a list of functions for this.

Function|Description
---|---
public RewardInterface(char* zoneId)|This is the BidmadReward constructor, Set the ZoneId
public void load()|Request an ad with the ZoneId entered in the constructor.
public void show()|Display the loaded advertisement.
public bool isLoaded()|Check if the ad is loaded.
public void setAutoReload(bool isAutoReload)|Load the next ad after Show. This option defaults to true, and if a failCallback is received, the reload operation is not performed.
public void setCUID(char*)|Setting CUID Property of each ad type
public void setOnLoadCallback(void (*_onLoadCallback) (char *))|If an Function is registered, the registered Function is executed when the reward ad is loaded.
public void setOnShowCallback(void (*_onShowCallback) (char *))|If an Function is registered, the registered Function is executed when the reward ad is shown.
public void setOnFailCallback(void (*_onFailCallback) (char *))|If an Function is registered, the registered Function is executed when the load of reward ad through ZoneId fails.
public void setOnCompleteCallback(void (*_onCompleteCallback) (char *))|If an Function is registered, the registered Function is executed when the reward payment criteria of the reward ad are met.
public void setOnSkipCallback(void (*_onSkipCallback) (char *))|If an Function is registered, the registered Function is executed when the reward payment standard of the reward ad is not met.
public void setOnCloseCallback(void (*_onCloseCallback) (char *))|If an Function is registered, the registered Function is executed when the reward ad is closed.

#### 4.3 Banner

*Banner ads are handled via the BannerInterface, which is a list of functions for this.

Function|Description
---|---
public BannerInterface(char* zoneId)|BidmadBanner constructor, Set ZoneId
public void setInterval()|Set the banner refresh cycle.(60s~120s)
public void load(int x)|Request an ad with the ZoneId entered in the constructor.
public void load(int x, int y)|Request an ad with the ZoneId entered in the constructor. The banner is exposed based on the input x and y values.
public void setCUID(char*)|Setting CUID Property of each ad type
public void removeBanner()|Remove the loaded banner.
public bool hideBannerView()|Hide the loaded banner view.
public bool showBannerView()|Expose the loaded banner view.
public bool onPause()|Banner ads are stopped. It is mainly called when the OnPause event occurs. Only Android is supported.
public bool onResume()|Restart banner ads. It is mainly called when the OnResume event occurs. Only Android is supported.
public void setOnLoadCallback(void (*_onLoadCallback) (char *))|If a function is registered, the registered function is executed when the banner ad is loaded.
public void setOnFailCallback(void (*_onFailCallback) (char *))|If a function is registered, the registered function is executed when the banner ad load fails.

#### 4.4 기타 인터페이스
Function|Description
---|---
static char* pluginVersion|Get Bidmad Plugin Version.
static void setDebugMode(bool)|Set whether to expose Debug Log.
static void setGoogleTestId(char *)|Test Device Setting function for AdMob / AdManager
static void setGdprConsent(bool, bool)|Set if user consented in regard to GDPR (1st Param: User Consent, 2nd Param: is EU Region)
static int getGdprConsent(bool)|GDPR Consent Status (Param: is EU Region)
static const char* getPRIVACYURL()|Get Bidmad Privacy URL.
static void initializeSdk()|Perform BidmadSDK initialization.

#### 4.5 iOS14 AppTrackingTransparencyAuthorization

*AppTrackingTransparencyAuthorization functions are provided through BidmadCommon.

Function|Description
---|---
public static void reqAdTrackingAuthorization(void (*_onAdTrackingAuthorizationResponse) (int))| App Tracking Transparency Displays the approval request popup and passes the result to the callback.
public static void setAdvertiserTrackingEnabled(bool)| Set the result for app tracking transparency approval request pop-up consent/rejection obtained with a function other than reqAdTrackingAuthorization.
public static bool getAdvertiserTrackingEnabled()| Set app tracking transparency approval request popup inquires the result of consent/rejection.

----
### Reference

- [GDPR Guide](https://github.com/bidmad/Bidmad-Cocos2dx/wiki/Cocos2dx-GDPR-Guide-%5BENG%5D)
