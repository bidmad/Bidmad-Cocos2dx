#include "cocos2d.h"
#include "InterstitialCallback.h"

USING_NS_CC;

class InterstitialController{
private:
    jobject jObj;
    JniMethodInfo jniM;
    jclass jCls;

    void deleteLocalRefMember();
    void getInstance();

public:
    InterstitialCallback* callback;
    char* mZoneId;

    InterstitialController(char *);
    void setActivity();
    void makeInterstitial();
    void setAdInfo(char*);
    void setCUID(char*);
    void load();
    void show();
    bool isLoaded();
    void setAutoReload(bool);
    void setOnLoadCallback(void (*_onLoadCallback) (char *));
    void setOnShowCallback(void (*_onShowCallback) (char *));
    void setOnFailCallback(void (*_onFailCallback) (char *));
    void setOnCompleteCallback(void (*_onCompleteCallback) (char *));
    void setOnSkipCallback(void (*_onSkipCallback) (char *));
    void setOnCloseCallback(void (*_onCloseCallback) (char *));
    void setOnClickCallback(void (*_onClickCallback) (char *));
    static void callCallback(char* callbackType, char* zoneId);
};