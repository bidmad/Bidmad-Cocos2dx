//
//  RewardBridgeCpp.h
//
//  Created by Kenneth on 2021/04/24.
//

#ifndef InterstitialBridgeCpp_h
#define InterstitialBridgeCpp_h

#include "cocos2d.h"

class InterstitialBridgeCpp{
private:
    void (*onLoadCallback) (char *) = nullptr;
    void (*onShowCallback) (char *) = nullptr;
    void (*onFailCallback) (char *) = nullptr;
    void (*onCloseCallback) (char *) = nullptr;
    
    char* mZoneId;
public:
    InterstitialBridgeCpp(char*);
    void loadInterstitial();
    void showInterstitial();
    bool isLoaded();
    void setAutoReload(bool isAutoReload);
    void setOnLoadCallback(void (*_onLoadCallback) (char *));
    void setOnShowCallback(void (*_onShowCallback) (char *));
    void setOnFailCallback(void (*_onFailCallback) (char *));
    void setOnCloseCallback(void (*_onCloseCallback) (char *));
    void callCallback(char* callbackType, char* zoneId);
    
};

#endif /* InterstitialBridgeCpp_h */
