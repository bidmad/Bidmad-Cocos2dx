//
//  RewardBridgeCpp.h
//
//  Created by Kenneth on 2021/04/24.
//

#ifndef RewardBridgeCpp_h
#define RewardBridgeCpp_h

#include "cocos2d.h"

class RewardBridgeCpp{
private:
    void (*onLoadCallback) (char *) = nullptr;
    void (*onShowCallback) (char *) = nullptr;
    void (*onFailCallback) (char *) = nullptr;
    void (*onCompleteCallback) (char *) = nullptr;
    void (*onSkipCallback) (char *) = nullptr;
    void (*onCloseCallback) (char *) = nullptr;
    void (*onClickCallback) (char *) = nullptr;
    
    char* mZoneId;
public:
    RewardBridgeCpp(char*);
    void loadRewardVideo();
    void showRewardVideo();
    bool isLoaded();
    void setAutoReload(bool isAutoReload);
    void setOnLoadCallback(void (*_onLoadCallback) (char *));
    void setOnShowCallback(void (*_onShowCallback) (char *));
    void setOnFailCallback(void (*_onFailCallback) (char *));
    void setOnCompleteCallback(void (*_onCompleteCallback) (char *));
    void setOnSkipCallback(void (*_onSkipCallback) (char *));
    void setOnCloseCallback(void (*_onCloseCallback) (char *));
    void callCallback(char* callbackType, char* zoneId);
    
};

#endif /* RewardBridgeCpp_h */
