# BidmadPlugin

BidmadPlugin은 모바일 앱 광고 SDK인 Bidmad를 Cocos2dx에서 사용하기 위한 Plugin입니다.<br>
Plugin을 사용하여 Cocos2dx 모바일 앱에서 전면 / 보상형 광고를 게재 할 수 있습니다.<br>

## 시작하기
- [최신 샘플 프로젝트 다운로드](https://github.com/bidmad/Bidmad-Cocos2dx/archive/master.zip)
- [최신 플러그인 다운로드](https://github.com/bidmad/Bidmad-Cocos2dx/releases)

> [!IMPORTANT]
> 2.4.0 버전부터는 기존에 사용하던 **Appkey가 AppDomain으로 변경**되었습니다.<br>
> **AppDomain은 기존 Appkey와 호환이 되지 않아 initiaize를 위해서는 AppDomain을 새로 발급받으셔야 합니다.**<br>
> 2.4.0 버전으로 업데이트 하시는 경우에는 **테크랩스 플랫폼 사업부 운영팀에 연락 부탁 드립니다.**<br>

### 1. Plugin 추가하기
#### 1.1 Android

1. 다운로드 받은 샘플 프로젝트의 Classes/bidmad 폴더를 게임 프로젝트로 복사합니다.<br>

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
-keep class com.adop.sdk.adapter.**{ *; }
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

#### Bidmad Plugin 임포트 가이드

- Cocos2DX 4.X 버전 사용 시, 다음과 같은 Xcode Project 생성 터미널 커맨드가 필요합니다.

<details markdown="1">
<summary>Cocos2DX 4.X 버전 Xcode Project 생성 터미널 커맨드</summary>
<br>

1. 터미널 앱을 실행하세요.
2. 게임 프로젝트 루트 폴더로 cd (change directory) 하세요.
3. 다음 커맨드를 실행하십시오: mkdir ios-build && cd ios-build
4. 다음 커맨드를 실행하십시오: cmake .. -GXcode -DCMAKE_SYSTEM_NAME=iOS -DCMAKE_OSX_SYSROOT=iphoneos
5. 아래 가이드된 CocoaPods 섹션을 따라하십시오.

</details>

- 터미널에서 Xcode Project 가 담긴 폴더로 이동해, pod init 커맨드를 내리십시오. (커맨드 작동이 되지 않는다면, CocoaPods 설치를 부탁드립니다)
- 이후 Podfile 내부에 다음과 같이 작성해주십시오.

<details markdown="1">
<summary>Cocos2DX 3.X 버전 Podfile</summary>
<br>

```
platform :ios, '12.0'

target 'MyGame-desktop' do
  # Comment the next line if you don't want to use dynamic frameworks
  use_frameworks!

  # Pods for MyGame-desktop

end

target 'MyGame-mobile' do
  use_frameworks! :linkage => :static

  pod "BidmadSDK", "6.12.4"
  pod "OpenBiddingHelper", "6.12.3"

  pod "BidmadAdFitAdapter", "3.12.7.11.0"
  pod "BidmadAdmixerAdapter", "2.0.2.11.1"
  pod "BidmadAppLovinAdapter", "13.3.1.11.0"
  pod "BidmadFyberAdapter", "8.3.7.11.0"
  pod "BidmadGoogleAdManagerAdapter", "12.6.0.11.0"
  pod "BidmadGoogleAdMobAdapter", "12.6.0.11.0"
  pod "BidmadMobwithAdapter", "1.0.0.11.2"
  pod "BidmadORTBAdapter", "1.0.0.11.2"
  pod "BidmadPangleAdapter", "7.2.0.5.11.0"
  pod "BidmadTaboolaAdapter", "3.8.33.11.2"
  pod "BidmadTeadsAdapter", "5.2.0.11.2"
  pod "BidmadUnityAdsAdapter", "4.15.0.11.0"
  pod "BidmadVungleAdapter", "7.5.1.11.0"
  pod "BidmadPartners/AdMobBidding", "1.0.7"

end
```

</details>

<details markdown="1">
<summary>Cocos2DX 4.X 버전 Podfile</summary>
<br>

```
# *** IMPORTANT: iOS 버전명을 반드시 12.0 혹은 이상으로 기입하십시오 ***
platform :ios, '12.0'

target 'cocos2d' do
  # Comment the next line if you don't want to use dynamic frameworks
  use_frameworks!

  # Pods for cocos2d

end

# *** IMPORTANT: 오직 프로젝트명으로 지명된 타겟에만 아래 Pod 커맨드를 추가하십시오 ***
target 'CocosSampleProject' do
  # Comment the next line if you don't want to use dynamic frameworks
  use_frameworks!

  pod "BidmadSDK", "6.12.4"
  pod "OpenBiddingHelper", "6.12.3"

  pod "BidmadAdFitAdapter", "3.12.7.11.0"
  pod "BidmadAdmixerAdapter", "2.0.2.11.1"
  pod "BidmadAppLovinAdapter", "13.3.1.11.0"
  pod "BidmadFyberAdapter", "8.3.7.11.0"
  pod "BidmadGoogleAdManagerAdapter", "12.6.0.11.0"
  pod "BidmadGoogleAdMobAdapter", "12.6.0.11.0"
  pod "BidmadMobwithAdapter", "1.0.0.11.2"
  pod "BidmadORTBAdapter", "1.0.0.11.2"
  pod "BidmadPangleAdapter", "7.2.0.5.11.0"
  pod "BidmadTaboolaAdapter", "3.8.33.11.2"
  pod "BidmadTeadsAdapter", "5.2.0.11.2"
  pod "BidmadUnityAdsAdapter", "4.15.0.11.0"
  pod "BidmadVungleAdapter", "7.5.1.11.0"
  pod "BidmadPartners/AdMobBidding", "1.0.7"

end

...
```

</details>

- 변경된 Podfile 저장 이후, terminal에서 Xcode Project 가 담긴 폴더 내부로 이동해, pod install 커맨드를 내리십시오.
- 이후, iOS 프로젝트 폴더에 생성된 "xcworkspace" 확장자를 가진 프로젝트 파일을 오픈한 뒤, 사용하시는 Cocos2DX 버전에 맞게 아래 세팅을 진행하세요.
    
<details markdown="1">
<summary>Cocos2DX 3.X 버전 Xcode Build 세팅</summary>
<br>

- Xcode Project 내부, mobile 타겟 용 빌드 세팅에서 다음 값을 설정해주십시오.
    - ENABLE_BITCODE → NO
    - General → Deployment Info 내부, iOS 최소버전을 "iOS 13" 로 설정
- Xcode Project 내부, mobile 타겟 용 빌드 세팅에서 다음 값을 추가해주십시오.
    - GCC_PREPROCESSOR_DEFINITIONS → $(inherited)
    - LIBRARY_SEARCH_PATHS → $(inherited)
    - OTHER_LDFLAGS → $(inherited)
    - SWIFT_VERSION → Swift 5
    
</details>

<details markdown="1">
<summary>Cocos2DX 4.X 버전 Xcode Build 세팅</summary>
<br>

- Xcode Project iOS Deployment Target 12.0 으로 세팅
![XCODEBUILD0](https://i.imgur.com/AhqGPXn.png)
- Xcode Project iOS 앱 타겟 클릭 -> Build Phases 클릭 -> Target Dependencies 섹션 오픈 -> ZERO_CHECK(타겟명) 클릭 -> 제거 버튼 클릭
![XCODEBUILD1](https://i.imgur.com/dU4Whr6.png)
- Xcode Project iOS 앱 타겟 클릭 -> Build Settings 클릭 -> Debug / Release용 Framework Search Path에 ${PODS_CONFIGURATION_BUILD_DIR}를 기입
![XCODEBUILD2](https://i.imgur.com/QWB7TlM.png)
- Xcode Project 폴더 -> Pods 폴더 -> Target Support Files 폴더 -> Pods-#프로젝트명# 폴더 -> Pods-#프로젝트명#-frameworks.sh 파일 내 아래 기존 스크립트를 다음과 같이 수정:
![XCODEBUILD3](https://i.imgur.com/TCkGszP.png)

**기존 스크립트** (30번째 줄 ~ 42번째 줄)
```
# This protects against multiple targets copying the same framework dependency at the same time. The solution
# was originally proposed here: https://lists.samba.org/archive/rsync/2008-February/020158.html
RSYNC_PROTECT_TMP_FILES=(--filter "P .*.??????")

# Copies and strips a vendored framework
install_framework()
{
  if [ -r "${BUILT_PRODUCTS_DIR}/$1" ]; then
    local source="${BUILT_PRODUCTS_DIR}/$1"
  elif [ -r "${BUILT_PRODUCTS_DIR}/$(basename "$1")" ]; then
    local source="${BUILT_PRODUCTS_DIR}/$(basename "$1")"
  elif [ -r "$1" ]; then
    local source="$1"
  fi
```

**수정 스크립트** (위 기존 스크립트를 아래 수정 스크립트로 수정해주세요)
```
# This protects against multiple targets copying the same framework dependency at the same time. The solution
# was originally proposed here: https://lists.samba.org/archive/rsync/2008-February/020158.html
RSYNC_PROTECT_TMP_FILES=(--filter "P .*.??????")

# Copies and strips a vendored framework
install_framework()
{
  if [ -r "${BUILT_PRODUCTS_DIR}/$1" ]; then
    local source="${BUILT_PRODUCTS_DIR}/$1"
  elif [ -r "${BUILT_PRODUCTS_DIR}/$(basename "$1")" ]; then
    local source="${BUILT_PRODUCTS_DIR}/$(basename "$1")"
  elif [ -r "${PODS_CONFIGURATION_BUILD_DIR}/$(basename "$1" .framework)/$(basename "$1")" ]; then
    local source="${PODS_CONFIGURATION_BUILD_DIR}/$(basename "$1" .framework)/$(basename "$1")"
  elif [ "$(basename "$1")" = "FBLPromises.framework" ] && [ -r "${PODS_CONFIGURATION_BUILD_DIR}/PromisesObjC/FBLPromises.framework" ]; then
    local source="${PODS_CONFIGURATION_BUILD_DIR}/PromisesObjC/FBLPromises.framework"
  elif [ -r "$1" ]; then
    local source="$1"
  fi
```
    
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
initializeSdk 메서드는 App Domain를 인자값으로 받고 있으며 광고를 로드하기 전, 앱 실행 초기에 다음 예시와 같이 initializeSdk 메서드를 호출해주십시오.<br>
(*App Domain을 발급받으시려면 테크랩스 플랫폼 운영팀으로 연락 부탁 드립니다.)

```cpp
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CommonInterface::initializeSdk("IOS APP DOMAIN");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    CommonInterface::initializeSdk("ANDROID APP DOMAIN");
#endif
```

혹은, 2.1.0 이상 버전의 Bidmad Plugin을 사용하는 경우, bool 타입을 인자값으로 받는 함수를 initializeSdk 메서드의 인자값으로 넣어 초기화 여부를 확인할 수 있습니다.

```cpp
void initializeBidmadPlugin()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CommonInterface::initializeSdkWithCallback("IOS APP DOMAIN", onInitialized);
    
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    CommonInterface::initializeSdkWithCallback("ANDROID APP DOMAIN", onInitialized);

#endif
}

// get callback checking whether the sdk is initialized
void onInitialized(bool isInitialized) {
    if (isInitialized == true) {
        CCLOG("Initialized? YES");
    } else {
        CCLOG("Initialized? NO");
    }
}
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
static void initializeSdkWithCallback(char *appDomain, void (*_onInitialized) (bool)) |BidmadSDK 환경 설정을 초기화하고, 전면 및 리워드 광고를 프리로드합니다. 콜백 함수로 초기화 여부를 받습니다.
static bool isAdFree()|쿠팡 광고네트워크에 의한 광고 차단 여부를 확인합니다.
static void setAdFreeEventCallback(void (*_onAdFree) (bool))|쿠팡 광고네트워크에 의한 광고차단 상태 변경 정보를 받기 위해 콜백 함수를 설정합니다.

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
- [쿠팡 네트워크 광고 차단 인터페이스 가이드](https://github.com/bidmad/Bidmad-Cocos2dx/wiki/쿠팡-네트워크-광고-차단-인터페이스-가이드)
