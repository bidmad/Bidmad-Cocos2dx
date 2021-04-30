#include "cocos2d.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "ios/RewardBridgeCpp.h"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "android/RewardController.h"
#endif

USING_NS_CC;

class RewardInterface{
private:
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    RewardBridgeCpp* reward;
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    RewardController* reward;
#endif
public:
    RewardInterface(char*);

    void load();
    void show();
    bool isLoaded();

    void setOnLoadCallback(void (*_onLoadCallback) (char *));
    void setOnShowCallback(void (*_onShowCallback) (char *));
    void setOnFailCallback(void (*_onFailCallback) (char *));
    void setOnCompleteCallback(void (*_onCompleteCallback) (char *));
    void setOnSkipCallback(void (*_onSkipCallback) (char *));
    void setOnCloseCallback(void (*_onCloseCallback) (char *));
};
