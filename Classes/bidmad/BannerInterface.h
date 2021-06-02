#include "cocos2d.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "android/BannerController.h"
#endif

USING_NS_CC;

class BannerInterface{
private:
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    BannerController* banner;
#endif
public:
    BannerInterface(char*);

    void setInterval(int);
    void load(int);
    void load(int, int);
    void removeBanner();
    void hideBannerView();
    void showBannerView();
    void onPause();
    void onResume();

    void setOnLoadCallback(void (*_onLoadCallback) (char *));
    void setOnFailCallback(void (*_onFailCallback) (char *));
};
