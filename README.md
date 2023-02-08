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
*Cmake List를 사용하는 경우 아래와 같이 bidmad source를 추가합니다.
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
     Classes/bidmad/AdPosition.h
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

5. 프로젝트에서 Proguard를 적용하고 있다면 아래의 룰을 추가하세요.
```cpp
-keep class com.adop.sdk.** { *; }
-keep class ad.helper.openbidding.** { *; }
-keep class com.adop.adapter.fc.** { *; }
-keep class com.adop.adapter.fnc.** { *; }
-keepnames class * implements java.io.Serializable
-keepclassmembers class * implements java.io.Serializable {
    static final long serialVersionUID;
    private static final java.io.ObjectStreamField[] serialPersistentFields;
    !static !transient <fields>;
    private void writeObject(java.io.ObjectOutputStream);
    private void readObject(java.io.ObjectInputStream);
    java.lang.Object writeReplace();
    java.lang.Object readResolve();
}
-keepclassmembers class * {
    @android.webkit.JavascriptInterface <methods>;
}

# Pangle
-keep class com.bytedance.sdk.** { *; }
-keep class com.bykv.vk.openvk.component.video.api.** { *; }

# Tapjoy
-keep class com.tapjoy.** { *; }
-keep class com.moat.** { *; }
-keepattributes JavascriptInterface
-keepattributes *Annotation*
-keep class * extends java.util.ListResourceBundle {
protected Object[][] getContents();
}
-keep public class com.google.android.gms.common.internal.safeparcel.SafeParcelable {
public static final *** NULL;
}
-keepnames @com.google.android.gms.common.annotation.KeepName class *
-keepclassmembernames class * {
@com.google.android.gms.common.annotation.KeepName *;
}
-keepnames class * implements android.os.Parcelable {
public static final ** CREATOR;
}
-keep class com.google.android.gms.ads.identifier.** { *; }
-dontwarn com.tapjoy.**
```

6. 아동을 타겟으로 하고 PlayStore에 심사를 받는 앱은 인증된 광고 네트워크를 사용을 위해 추가 설정이 필요합니다.<br> 
앱이 아동을 타겟하고 있다면 추가 설정을 위해 [가이드](https://github.com/bidmad/Bidmad-Cocos2dx/wiki/PlayStore-%EC%95%B1-%ED%83%80%EA%B2%9F%ED%8C%85-%EC%97%B0%EB%A0%B9%EC%97%90-%EB%94%B0%EB%A5%B8-%EC%B6%94%EA%B0%80-%EC%84%A4%EC%A0%95.)를 확인하세요.<br>

7. Android 12버전을 Target하는 경우 [AD_ID 권한 추가 선언 가이드](https://github.com/bidmad/Bidmad-Cocos2dx/wiki/AD_ID-Permission-Guide%5BKOR%5D)를 확인바랍니다.

*Bidmad는 AndroidX 라이브러리를 사용합니다. AndroidX 프로젝트가 아니라면 AndroidX로 마이그레이션 바랍니다.

#### 1.2 iOS

1. 다운로드 받은 샘플 프로젝트의 Classes/bidmad 폴더를 게임 프로젝트로 복사하고 Xcode에 추가합니다.<br>
*Cmake List를 사용하는 경우 아래와 같이 bidmad source를 추가합니다.
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
     Classes/bidmad/AdPosition.h
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
             Classes/bidmad/ios/BidmadCocos2DXSharedState.h
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
             Classes/bidmad/ios/BidmadCocos2DXSharedState.m
             )
    elseif(MACOSX)
    ...
endif()
```
2. Classes/bidmad 폴더 추가 이후, 다음 임포트 가이드를 따라주십시오.
<details markdown="1">
<summary>Cocos2DX 4.X 이상 버전을 위한 임포트 가이드 (수동 라이브러리 임포트)</summary>
<br>

- Framework 수동 연동을 위해 [GitHub Release](https://github.com/bidmad/Bidmad-Cocos2dx/releases) 에서 iOS_Frameworks_Cocos2DX_1.10.0.zip 를 다운로드 받아 /proj.ios_mac 폴더 안에 libBidmad 폴더를 포함시킨 뒤, /proj.ios_mac/libBidmad 폴더를 Xcode 프로젝트로 복사해 Framework 를 추가합니다.
- Frameworks, Libraries, and Embedded Content 내부 OMSDK_Pubmatic.xcframework / AdFitSDK.framework / PrebidMobile.framework 는 Embed & Sign 옵션으로 체크합니다.
*OMSDK_Pubmatic, AdFitSDK, PrebidMobile 를 제외한 libBidmad 내 모든 프레임워크는 Xcode 추가 시 Do not Embed 옵션으로 세팅합니다.
- Classes → bidmad → ios 내부 BidmadSwiftSupport.swift 임포트, 이후 "Don't Create" 버튼 선택.<br>
- Xcode Project 내부, mobile 타겟 용 세팅에서 다음 값을 설정하십시오.
    - Build Settings → Other Linker Flags 내부, "-ObjC" 가 없을 경우, 추가
    - Build Settings → Bitcode Enable 을 NO 로 세팅
    - Build Settings → Swift Language Version 을 "Swift 5" 로 세팅
    - General → Deployment Info 내부, iOS 최소버전을 "iOS 11" 로 설정
- 다음 라이브러리를 추가하십시오. ( 타겟 빌드 세팅 → Build Phases 의 "Link Binary With Libraries" 내부에, 다음 라이브러리를 추가해주십시오) <br>
    - AppTrackingTransparency.framework <br>
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
    - JavaScriptCore.framework <br>
    - AudioToolbox.framework <br>
    - DeviceCheck.framework <br>
</details>

<details markdown="1">
<summary>Cocos2DX 3.X 버전을 위한 임포트 가이드 (CocoPods 라이브러리 임포트)</summary>
<br>

- Xcode Project를 닫은 뒤, terminal 에서 Xcode Project 가 담긴 폴더로 이동해, pod init 커맨드를 내리십시오. (커맨드 작동이 되지 않는다면, CocoaPods 설치를 부탁드립니다)
- 이후 Podfile 내부에 다음과 같이 작성해주십시오.
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
  pod 'BidmadSDK', '5.3.0'
  pod 'OpenBiddingHelper', '5.3.0'
  pod 'BidmadAdapterFNC', '5.3.0'
  pod 'BidmadAdapterFC', '5.3.0'

end

```
- 변경된 Podfile 저장 이후, terminal에서 Xcode Project 가 담긴 폴더 내부로 이동해, pod install 커맨드를 내리십시오.
- Xcode Project 내부, mobile 타겟 용 빌드 세팅에서 다음 값을 설정해주십시오.
    - ENABLE_BITCODE → NO
    - General → Deployment Info 내부, iOS 최소버전을 "iOS 11" 로 설정
- Xcode Project 내부, mobile 타겟 용 빌드 세팅에서 다음 값을 추가해주십시오.
    - GCC_PREPROCESSOR_DEFINITIONS → $(inherited)
    - LIBRARY_SEARCH_PATHS → $(inherited)
    - OTHER_LDFLAGS → $(inherited)
    - SWIFT_VERSION → Swift 5
</details>

3. Cocos2DX 버전에 따른 임포트 가이드 수행 이후, info.plist에 GADApplicationIdentifier를 추가합니다.<br>
*GADApplicationIdentifier는 Google Admob에서 확인할 수 있습니다. 
```
    <key>GADApplicationIdentifier</key>
    <string>ca-app-pub-XXXXXX~XXXXXX</string>
```

4. [가이드](https://github.com/bidmad/Bidmad-Cocos2dx/wiki/Preparing-for-iOS-14%5BKOR%5D)에 따라 앱 추적 투명성 승인 요청 팝업 및 SKAdNetwork를 적용합니다.<br>

*Apple Store에서 요구하는 개인정보 보호에 관한 가이드가 필요한 경우 [이곳](https://github.com/bidmad/Bidmad-Unity/wiki/Apple-privacy-survey%5BKOR%5D)을 참고하세요.

### 2. Plugin 사용하기

#### 2.1 Migration (Bidmad Cocos2DX Plugin 1.10.0 이하 버전에서 2.0.0 버전 이상으로 업데이트 할 경우)
앱 초기 구성에 앞서, 1.10.0 이하 버전에서 2.0.0 버전으로 업데이트하는 경우 [API Migration Guide](https://github.com/bidmad/Bidmad-Cocos2dx/wiki/v2.0.0-Migration-Guide) 를 참고해 앱 업데이트를 진행하십시오. 이후, 아래 initializeSdk 메서드 추가 과정도 거치십시오.<br>

#### 2.2 BidmadSDK 초기화
BidmadSDK 실행에 필요한 작업을 수행합니다. SDK는 initializeSdk 메서드를 호출하지 않은 경우 광고 로드를 허용하지 않습니다.<br>
initializeSdk 메서드는 ADOP Insight 에서 확인가능한 App Key 를 인자값으로 받고 있습니다. App Key 는 [App Key 찾기](https://github.com/bidmad/SDK/wiki/Find-your-app-key%5BKR%5D) 가이드를 참고해 가져올 수 있습니다.<br>
광고를 로드하기 전, 앱 실행 초기에 다음 예시와 같이 initializeSdk 메서드를 호출해주십시오.

```cpp
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CommonInterface::initializeSdk("IOS APP KEY");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    CommonInterface::initializeSdk("ANDROID APP KEY");
#endif
```

#### 2.3 전면

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

#### 2.4 보상형

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

#### 2.5 배너

- 배너광고를 요청하기 위해 BannerInterface 생성합니다.
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
- 2.0.0 이상 버전의 Bidmad Plugin을 사용하는 경우, Y 좌표 대신 광고 위치를 설정하는 것도 지원됩니다. 광고 위치 값에는 Center, Top, Bottom, Left, Right, TopLeft, TopRight, BottomLeft, BottomRight가 포함됩니다. 배너 광고의 광고 위치 설정은 다음 예시를 참고하세요.
```cpp
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    char *zoneId = (char*)"1c3e3085-333f-45af-8427-2810c26a72fc";
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    char *zoneId = (char*)"944fe870-fa3a-4d1b-9cc2-38e50b2aed43";
#endif

    // Banner Create
    bi = new BannerInterface(zoneId);
    
    // Load the banner with ad position from bottom
    bi->load(AdPosition::Bottom);
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
void InterstitialFail(char* zoneId, char* errorInfo)
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
void onRewardFail(char* zoneId, char* errorInfo)
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
void onBannerFail(char* zoneId, char* errorInfo)
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
public void setAutoReload(bool isAutoReload)|Show 이후 다음 광고를 Load 합니다. 해당 옵션은 기본 true로 적용되어있으며, failCallback을 수신한 경우에는 Reload 동작을 하지 않습니다.
public void setOnLoadCallback(void (*_onLoadCallback) (char *))|Function을 등록했다면 전면광고를 Load 했을 때 등록한 Function을 실행합니다.
public void setOnShowCallback(void (*_onShowCallback) (char *))|Function을 등록했다면 전면광고를 Show 했을 때 등록한 Function을 실행합니다.
public void setOnFailCallback(void (*_onFailCallback) (char *, char *))|Function을 등록했다면 전면광고 Load가 실패 했을 때 등록한 Function을 실행합니다.
public void setOnCloseCallback(void (*_onCloseCallback) (char *))|Function을 등록했다면 전면광고를 Close 했을 때 등록한 Function을 실행합니다.

#### 4.2 보상형

*보상형 광고는 RewardInterface 통해 처리되며 이를 위한 함수 목록입니다.

Function|Description
---|---
public RewardInterface(char* zoneId)|BidmadReward 생성자, ZoneId를 설정합니다.
public void load()|생성자에서 입력한 ZoneId로 광고를 요청합니다.
public void show()|Load한 광고를 노출 시킵니다.
public bool isLoaded()|광고가 Load된 상태인지 체크합니다.
public void setAutoReload(bool isAutoReload)|Show 이후 다음 광고를 Load 합니다. 해당 옵션은 기본 true로 적용되어있으며, failCallback을 수신한 경우에는 Reload 동작을 하지 않습니다.
public void setOnLoadCallback(void (*_onLoadCallback) (char *))|Function을 등록했다면 보상형광고를 Load 했을 때 등록한 Function을 실행합니다.
public void setOnShowCallback(void (*_onShowCallback) (char *))|Function을 등록했다면 보상형광고를 Show 했을 때 등록한 Function을 실행합니다.
public void setOnFailCallback(void (*_onFailCallback) (char *, char *))|Function을 등록했다면 보상형광고 Load가 실패 했을 때 등록한 Function을 실행합니다.
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
public void load(AdPosition position)|생성자에서 입력한 ZoneId로 광고를 요청합니다. 배너는 입력받은 위치를 기준으로 노출됩니다.
public void removeBanner()|Load된 배너를 제거합니다.
public bool hideBannerView()|Load된 배너 View를 숨깁니다.
public bool showBannerView()|Load된 배너 View를 노출시킵니다.
public bool onPause()|배너 광고를 정지 시킵니다. 주로 OnPause 이벤트 발생 시 호출하며, Android만 지원합니다.
public bool onResume()|배너 광고를 다시 시작합니다. 주로 OnResume 이벤트 발생 시 호출하며, Android만 지원합니다.
public void setOnLoadCallback(void (*_onLoadCallback) (char *))|Function을 등록했다면 배너광고를 Load 했을 때 등록한 Function을 실행합니다.
public void setOnFailCallback(void (*_onFailCallback) (char *, char *))|Function을 등록했다면 배너광고 Load가 실패 했을 때 등록한 Function을 실행합니다.

#### 4.4 기타 인터페이스
Function|Description
---|---
static char* pluginVersion|Bidmad 플러그인 버전을 가져옵니다.
static void setDebugMode(bool)|디버그 로그 출력을 세팅합니다.
static void setGoogleTestId(char *)|구글 애드몹 / 애드매니저 용 테스트 디바이스 세팅
static void setGdprConsent(bool, bool)|GDPR 동의 여부 세팅 (1st Param: 유저 동의여부, 2nd Param: EU 지역 여부)
static int getGdprConsent(bool)|GDPR 동의 여부 (Param: EU 지역 여부)
static const char* getPRIVACYURL()|Bidmad 개인정보 방침 웹 URL을 가져옵니다.
static void setCUID(char *)|모든 광고에 CUID를 세팅합니다.
static void initializeSdk(char *)|BidmadSDK 초기화 작업을 수행합니다.

#### 4.5 iOS14 앱 추적 투명성 승인 요청

*앱 추적 투명성 승인 요청에 관한 함수는 CommonInterface을 통해 제공됩니다.

Function|Description
---|---
public static void reqAdTrackingAuthorization(void (*_onAdTrackingAuthorizationResponse) (int))| 앱 추적 투명성 승인 요청 팝업을 발생시키고 결과를 callback으로 전달 합니다.
public static void setAdvertiserTrackingEnabled(bool)|reqAdTrackingAuthorization 이외의 함수로 앱 추적 투명성 승인 요청 팝업 동의/거절을 얻는 경우 이에 대한 결과를 설정합니다.
public static bool getAdvertiserTrackingEnabled()|설정된 앱 추적 투명성 승인 요청 팝업 동의/거절에 대한 결과를 조회합니다.

----
### 참고사항

- [GDPR 가이드](https://github.com/bidmad/Bidmad-Cocos2dx/wiki/Cocos2dx-GDPR-Guide-%5BKOR%5D)
