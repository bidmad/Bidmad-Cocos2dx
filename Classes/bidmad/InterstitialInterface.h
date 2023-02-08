#include "cocos2d.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "ios/InterstitialBridgeCpp.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "android/InterstitialController.h"
#endif

USING_NS_CC;

class InterstitialInterface{
private:
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    InterstitialBridgeCpp* interstitial;
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    InterstitialController* interstitial;
#endif
public:
    InterstitialInterface(char*);

    void load();
    void show();
    bool isLoaded();
    void setAutoReload(bool);

    void setOnLoadCallback(void (*_onLoadCallback) (char *));
    void setOnShowCallback(void (*_onShowCallback) (char *));
    void setOnFailCallback(void (*_onFailCallback) (char *, char *));
    void setOnCloseCallback(void (*_onCloseCallback) (char *));
};
