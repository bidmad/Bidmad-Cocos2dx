#include "cocos2d.h"
#include "BannerCallback.h"
#include "../AdPosition.h"

USING_NS_CC;

class BannerController{
private:
    jobject jObj;
    JniMethodInfo jniM;
    jclass jCls;

    void deleteLocalRefMember();
    void getInstance();

public:
    BannerCallback* callback;
    char* mZoneId;
    BannerController(char *);

    void setActivity();
    void makeAdView();
    void setInterval(int);

    void load(AdPosition);
    void load(int);
    void load(int, int);
    void removeBanner();
    void hideBannerView();
    void showBannerView();
    void onPause();
    void onResume();
    void setOnLoadCallback(void (*_onLoadCallback) (char *));
    void setOnFailCallback(void (*_onFailCallback) (char *, char* errorInfo));
    static void callCallback(char* callbackType, char* zoneId, char* errorInfo);
};
