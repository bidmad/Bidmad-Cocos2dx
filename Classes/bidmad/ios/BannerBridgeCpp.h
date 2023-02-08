//
//  BannerBridgeCpp.h
//  BidmadCocos2dxSample-mobile
//
//  Created by ADOP_Mac on 2021/06/29.
//

#ifndef BannerBridgeCpp_h
#define BannerBridgeCpp_h

#include "cocos2d.h"

class BannerBridgeCpp{
private:
    void (*onLoadCallback) (char *) = nullptr;
    void (*onFailCallback) (char *, char *) = nullptr;
    
    char* mZoneId;
public:
    BannerBridgeCpp(char* zoneId);
    void load(int y);
    void load(int x, int y);
    void loadWithPosition(int adPosition);
    void setInterval(int interval);
    void removeBanner();
    void hideBannerView();
    void showBannerView();
    void setOnLoadCallback(void (*_onLoadCallback)( char *));
    void setOnFailCallback(void (*_onFailCallback)(char *, char *));
    void callCallback(char* callbackType, char* zoneId, char* errorReason);
};

#endif /* InterstitialBridgeCpp_h */
