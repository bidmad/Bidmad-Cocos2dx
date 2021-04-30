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
                   $(LOCAL_PATH)/../../../Classes/bidmad/CommonInterface.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/RewardController.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/RewardCallback.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/InterstitialController.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/InterstitialCallback.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/CommonController.cpp
```
*If using Cmake List, add bidmad source as below.
```cpp
list(APPEND GAME_SOURCE
     Classes/AppDelegate.cpp
     Classes/HelloWorldScene.cpp
     Classes/bidmad/CommonInterface.cpp
     Classes/bidmad/InterstitialInterface.cpp
     Classes/bidmad/RewardInterface.cpp
     )
list(APPEND GAME_HEADER
     Classes/AppDelegate.h
     Classes/HelloWorldScene.h
     Classes/bidmad/CommonInterface.h
     Classes/bidmad/InterstitialInterface.h
     Classes/bidmad/RewardInterface.h
     )
if(ANDROID)
    ...
    list(APPEND GAME_SOURCE
         proj.android/app/jni/hellocpp/main.cpp
         Classes/bidmad/android/CommonController.cpp
         Classes/bidmad/android/InterstitialCallback.cpp
         Classes/bidmad/android/InterstitialController.cpp
         Classes/bidmad/android/RewardCallback.cpp
         Classes/bidmad/android/RewardController.cpp
         )
    list(APPEND GAME_HEADER
         Classes/bidmad/android/CommonController.h
         Classes/bidmad/android/InterstitialCallback.h
         Classes/bidmad/android/InterstitialController.h
         Classes/bidmad/android/RewardCallback.h
         Classes/bidmad/android/RewardController.h
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
*Bidmad uses the AndroidX library. If it is not an AndroidX project, please migrate to AndroidX.

#### 1.2 iOS

1. Copy the Classes/bidmad folder of the downloaded sample project to your game project and add it to Xcode.<br>
*If using Cmake List, add bidmad source as below.
```cpp
list(APPEND GAME_SOURCE
     Classes/AppDelegate.cpp
     Classes/HelloWorldScene.cpp
     Classes/bidmad/CommonInterface.cpp
     Classes/bidmad/InterstitialInterface.cpp
     Classes/bidmad/RewardInterface.cpp
     )
list(APPEND GAME_HEADER
     Classes/AppDelegate.h
     Classes/HelloWorldScene.h
     Classes/bidmad/CommonInterface.h
     Classes/bidmad/InterstitialInterface.h
     Classes/bidmad/RewardInterface.h
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
             Classes/bidmad/ios/InterstitialBridgeCpp.h
             Classes/bidmad/ios/InterstitialBridgeObjC.h
             Classes/bidmad/ios/RewardBridgeCpp.h
             Classes/bidmad/ios/RewardBridgeObjC.h
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
             Classes/bidmad/ios/InterstitialBridgeCpp.mm
             Classes/bidmad/ios/InterstitialBridgeObjC.mm
             Classes/bidmad/ios/RewardBridgeCpp.mm
             Classes/bidmad/ios/RewardBridgeObjC.mm
             )
    elseif(MACOSX)
    ...
endif()
```
2. Apply the settings in Build Settings in Xcode of your game project.<br>
- Set Enable BitCode = No (Cocos2dx default setting = No)<br>
- Add Other Linker Flags = -ObjC<br>
3. Copy the /proj.ios_mac/libBidmad folder of the downloaded sample project to the game project and add it to Xcode.<br>
*All frameworks within libBidmad are Do not Embed.
4. Add GADApplicationIdentifier to info.plist.<br>
*GADApplicationIdentifier can be found in Google Admob.
```
    <key>GADApplicationIdentifier</key>
    <string>ca-app-pub-XXXXXX~XXXXXX</string>
```

5. Follow the [guide](https://github.com/bidmad/Bidmad-Cocos2dx/wiki/Preparing-for-iOS-14%5BENG%5D) to apply app tracking transparency approval request pop-up and SKAdNetwork.

If you're looking for a guide to the privacy requirements of the Apple Store, [see here](https://github.com/bidmad/Bidmad-Cocos2dx/wiki/Apple-privacy-survey%5BENG%5D).

### 2. Using Plugin

#### 2.1 Interstitial

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

#### 2.2 Reward

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
### 4. Plugin Function

#### 4.1 Interstitial

*Interstitial ads are handled through InterstitialInterface, which is a list of functions for this.

Function|Description
---|---
public InterstitialInterface(char* zoneId)|This is the BidmadInterstitial constructor, Set the ZoneId
public void load()|Request an ad with the ZoneId entered in the constructor.
public void show()|Display the loaded advertisement.
public bool isLoaded()|Check if the ad is loaded.
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
public void setOnLoadCallback(void (*_onLoadCallback) (char *))|If an Function is registered, the registered Function is executed when the reward ad is loaded.
public void setOnShowCallback(void (*_onShowCallback) (char *))|If an Function is registered, the registered Function is executed when the reward ad is shown.
public void setOnFailCallback(void (*_onFailCallback) (char *))|If an Function is registered, the registered Function is executed when the load of reward ad through ZoneId fails.
public void setOnCompleteCallback(void (*_onCompleteCallback) (char *))|If an Function is registered, the registered Function is executed when the reward payment criteria of the reward ad are met.
public void setOnSkipCallback(void (*_onSkipCallback) (char *))|If an Function is registered, the registered Function is executed when the reward payment standard of the reward ad is not met.
public void setOnCloseCallback(void (*_onCloseCallback) (char *))|If an Function is registered, the registered Function is executed when the reward ad is closed.

#### 4.3 iOS14 AppTrackingTransparencyAuthorization

*AppTrackingTransparencyAuthorization functions are provided through BidmadCommon.

Function|Description
---|---
public static void reqAdTrackingAuthorization(void (*_onAdTrackingAuthorizationResponse) (int))| App Tracking Transparency Displays the approval request popup and passes the result to the callback.
public static void setAdvertiserTrackingEnabled(bool)| Set the result for app tracking transparency approval request pop-up consent/rejection obtained with a function other than reqAdTrackingAuthorization.
public static bool getAdvertiserTrackingEnabled()| Set app tracking transparency approval request popup inquires the result of consent/rejection.