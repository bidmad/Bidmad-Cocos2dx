#include "cocos2d.h"
#include "RewardCallback.h"

USING_NS_CC;

class RewardController{
private:
    jobject jObj;
    JniMethodInfo jniM;
    jclass jCls;

    void deleteLocalRefMember();
    void getInstance();

public:
    RewardCallback* callback;
    char* mZoneId;

    RewardController(char *);
    void setActivity();
    void makeReward();
    void setAdInfo(char*);
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
    static void callCallback(char* callbackType, char* zoneId);
};