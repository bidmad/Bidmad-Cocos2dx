# BidmadPlugin

BidmadPlugin은 모바일 앱 광고 SDK인 Bidmad를 Cocos2dx에서 사용하기 위한 Plugin입니다.<br>
Plugin을 사용하여 Cocos2dx 모바일 앱에서 전면 / 보상형 광고를 게재 할 수 있습니다.<br>

## 시작하기
- [최신 샘플 프로젝트 다운로드](https://github.com/bidmad/Bidmad-Cocos2dx/archive/master.zip)
- [최신 플러그인 다운로드](https://github.com/bidmad/Bidmad-Cocos2dx/releases)

### 1. Plugin 추가하기
#### 1.1 Android

1. 다운로드 받은 샘플 프로젝트의 Classes/bidmad 폴더를 게임 프로젝트로 복사합니다.<br>

*Android.mk를 사용하는 경우 bidmad source를 추가합니다.
```cpp
LOCAL_SRC_FILES := $(LOCAL_PATH)/hellocpp/main.cpp \
                   ...
                   $(LOCAL_PATH)/../../../Classes/bidmad/RewardInterface.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/InterstitialInterface.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/BannerInterface.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/CommonInterface.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/RewardController.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/RewardCallback.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/InterstitialController.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/InterstitialCallback.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/BannerController.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/BannerCallback.cpp \
                   $(LOCAL_PATH)/../../../Classes/bidmad/android/CommonController.cpp
```
*Cmake List를 사용하는 경우 아래와 같이 bidmad source를 추가합니다.
```cpp
list(APPEND GAME_SOURCE
     Classes/AppDelegate.cpp
     Classes/HelloWorldScene.cpp
     Classes/bidmad/CommonInterface.cpp
     Classes/bidmad/BannerInterface.cpp
     Classes/bidmad/InterstitialInterface.cpp
     Classes/bidmad/RewardInterface.cpp
     )
list(APPEND GAME_HEADER
     Classes/AppDelegate.h
     Classes/HelloWorldScene.h
     Classes/bidmad/CommonInterface.h
     Classes/bidmad/BannerInterface.h
     Classes/bidmad/InterstitialInterface.h
     Classes/bidmad/RewardInterface.h
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
         )
    list(APPEND GAME_HEADER
         Classes/bidmad/android/CommonController.h
         Classes/bidmad/android/BannerController.h
         Classes/bidmad/android/BannerCallback.h
         Classes/bidmad/android/InterstitialCallback.h
         Classes/bidmad/android/InterstitialController.h
         Classes/bidmad/android/RewardCallback.h
         Classes/bidmad/android/RewardController.h
         )
    ...
endif()
```

2. 다운로드 받은 샘플 프로젝트의 proj.android-studio/bidmad.gradle 파일을 게임 프로젝트로 복사합니다.<br>
3. proj.android-studio/build.gradle 파일에서 [apply plugin: 'com.android.application']를 찾아 아래 코드를 추가합니다.

```cpp
apply from: "bidmad.gradle"
```

4. proj.android-studio/app/AndroidManifest.xml 파일에 application 태그를 찾아 Google APPLICATION_ID를 추가합니다.
```cpp
<application
    ...
    <meta-data
        android:name="com.google.android.gms.ads.APPLICATION_ID"
        android:value="ca-app-pub-XXXXXX~XXXXXX"/>
</application>
```
*Bidmad는 AndroidX 라이브러리를 사용합니다. AndroidX 프로젝트가 아니라면 AndroidX로 마이그레이션 바랍니다.

#### 1.2 iOS

1. 다운로드 받은 샘플 프로젝트의 Classes/bidmad 폴더를 게임 프로젝트로 복사하고 Xcode에 추가합니다.<br>
*Cmake List를 사용하는 경우 아래와 같이 bidmad source를 추가합니다.
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
2. 게임 프로젝트의 Xcode에서 Build Settings에서 설정을 적용합니다.<br>
- Enable BitCode = No 설정 (Cocos2dx 기본 설정 = No)<br>
- Other Linker Flags = -ObjC 추가<br>
3. 다운로드 받은 샘플 프로젝트의 /proj.ios_mac/libBidmad 폴더를 게임 프로젝트로 복사, Xcode에 추가합니다.<br>
*libBidmad 내 모든 프레임워크는 Xcode 추가 시 Do not Embed 옵션으로 세팅합니다.
4. info.plist에 GADApplicationIdentifier를 추가합니다.<br>
*GADApplicationIdentifier는 Google Admob에서 확인할 수 있습니다. 
```
    <key>GADApplicationIdentifier</key>
    <string>ca-app-pub-XXXXXX~XXXXXX</string>
```

5. [가이드](https://github.com/bidmad/Bidmad-Cocos2dx/wiki/Preparing-for-iOS-14%5BKOR%5D)에 따라 앱 추적 투명성 승인 요청 팝업 및 SKAdNetwork를 적용합니다.<br>

*Apple Store에서 요구하는 개인정보 보호에 관한 가이드가 필요한 경우 [이곳](https://github.com/bidmad/Bidmad-Unity/wiki/Apple-privacy-survey%5BKOR%5D)을 참고하세요.

### 2. Plugin 사용하기

#### 2.2 전면

- 전면광고를 요청하기 위해 InterstitialInterface 생성합니다.
- 전면광고를 노출하기전에 isLoaded를 통해 광고 로드 여부를 체크합니다.
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

#### 2.3 보상형

- 보상형광고를 요청하기 위해 RewardInterface 생성합니다.
- 보상형광고를 노출하기전에 isLoaded를 통해 광고 로드 여부를 체크합니다.
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

#### 2.3 배너

- 배너광고를 요청하기 위해 BannerInterface 생성합니다.
- Android만 배너 광고를 지원합니다.
```cpp
#include "bidmad/BannerInterface.h"

void initBanner()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
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
- onResume / onPause 구현을 위해 Apllication을 상속 받아 applicationDidEnterBackground / applicationWillEnterForeground를 구현합니다.
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

### 3. Callback 사용하기

- Plugin에서는 광고 타입에 따라 Load / Show / Fail등 Callback을 제공합니다.<br>
- 해당 동작에 대해 별도 처리가 필요한 경우 함수를 등록하여 처리합니다.

#### 3.1 전면 Callback
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
#### 3.2 보상형 Callback
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

#### 3.3 배너 Callback
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

#### 4.1 전면

*전면 광고는 InterstitialInterface 통해 처리되며 이를 위한 함수 목록입니다.

Function|Description
---|---
public InterstitialInterface(char* zoneId)|InterstitialInterface 생성자, ZoneId를 설정합니다.
public void load()|생성자에서 입력한 ZoneId로 광고를 요청합니다.
public void show()|Load한 광고를 노출 시킵니다.
public bool isLoaded()|광고가 Load된 상태인지 체크합니다.
public void setOnLoadCallback(void (*_onLoadCallback) (char *))|Function을 등록했다면 전면광고를 Load 했을 때 등록한 Function을 실행합니다.
public void setOnShowCallback(void (*_onShowCallback) (char *))|Function을 등록했다면 전면광고를 Show 했을 때 등록한 Function을 실행합니다.
public void setOnFailCallback(void (*_onFailCallback) (char *))|Function을 등록했다면 전면광고 Load가 실패 했을 때 등록한 Function을 실행합니다.
public void setOnCloseCallback(void (*_onCloseCallback) (char *))|Function을 등록했다면 전면광고를 Close 했을 때 등록한 Function을 실행합니다.

#### 4.2 보상형

*보상형 광고는 RewardInterface 통해 처리되며 이를 위한 함수 목록입니다.

Function|Description
---|---
public RewardInterface(char* zoneId)|BidmadReward 생성자, ZoneId를 설정합니다.
public void load()|생성자에서 입력한 ZoneId로 광고를 요청합니다.
public void show()|Load한 광고를 노출 시킵니다.
public bool isLoaded()|광고가 Load된 상태인지 체크합니다.
public void setOnLoadCallback(void (*_onLoadCallback) (char *))|Function을 등록했다면 보상형광고를 Load 했을 때 등록한 Function을 실행합니다.
public void setOnShowCallback(void (*_onShowCallback) (char *))|Function을 등록했다면 보상형광고를 Show 했을 때 등록한 Function을 실행합니다.
public void setOnFailCallback(void (*_onFailCallback) (char *))|Function을 등록했다면 보상형광고 Load가 실패 했을 때 등록한 Function을 실행합니다.
public void setOnCompleteCallback(void (*_onCompleteCallback) (char *))|Function을 등록했다면 보상형광고의 리워드 지급기준을 충족 했을 때 등록한 Function을 실행합니다.
public void setOnSkipCallback(void (*_onSkipCallback) (char *))|Function을 등록했다면 보상형광고의 리워드 지급기준에 미달 했을 때 등록한 Function을 실행합니다.
public void setOnCloseCallback(void (*_onCloseCallback) (char *))|Function을 등록했다면 보상형광고를 Close 했을 때 등록한 Function을 실행합니다.

#### 4.3 배너

*배너 광고는 BannerInterface 통해 처리되며 이를 위한 함수 목록입니다.

Function|Description
---|---
public BannerInterface(char* zoneId)|BidmadBanner 생성자, ZoneId를 설정합니다.
public void setInterval()|Banner Refresh 주기를 설정합니다.(60s~120s)
public void load(int x)|생성자에서 입력한 ZoneId로 광고를 요청합니다.
public void load(int x, int y)|생성자에서 입력한 ZoneId로 광고를 요청합니다. 배너는 입력받은 x,y값을 기준으로 노출됩니다.
public void removeBanner()|Load된 배너를 제거합니다.
public bool hideBannerView()|Load된 배너 View를 숨깁니다.
public bool showBannerView()|Load된 배너 View를 노출시킵니다.
public bool onPause()|배너 광고를 정지 시킵니다. 주로 OnPause 이벤트 발생 시 호출하며, Android만 지원합니다.
public bool onResume()|배너 광고를 다시 시작합니다. 주로 OnResume 이벤트 발생 시 호출하며, Android만 지원합니다.
public void setOnLoadCallback(void (*_onLoadCallback) (char *))|Function을 등록했다면 배너광고를 Load 했을 때 등록한 Function을 실행합니다.
public void setOnFailCallback(void (*_onFailCallback) (char *))|Function을 등록했다면 배너광고 Load가 실패 했을 때 등록한 Function을 실행합니다.

#### 4.4 iOS14 앱 추적 투명성 승인 요청

*앱 추적 투명성 승인 요청에 관한 함수는 CommonInterface을 통해 제공됩니다.

Function|Description
---|---
public static void reqAdTrackingAuthorization(void (*_onAdTrackingAuthorizationResponse) (int))| 앱 추적 투명성 승인 요청 팝업을 발생시키고 결과를 callback으로 전달 합니다.
public static void setAdvertiserTrackingEnabled(bool)|reqAdTrackingAuthorization 이외의 함수로 앱 추적 투명성 승인 요청 팝업 동의/거절을 얻는 경우 이에 대한 결과를 설정합니다.
public static bool getAdvertiserTrackingEnabled()|설정된 앱 추적 투명성 승인 요청 팝업 동의/거절에 대한 결과를 조회합니다.

