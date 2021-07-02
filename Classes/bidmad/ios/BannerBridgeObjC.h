//
//  BannerBridgeCpp.h
//  BidmadCocos2dxSample-mobile
//
//  Created by ADOP_Mac on 2021/06/29.
//

#ifndef BannerBridgeObjC_h
#define BannerBridgeObjC_h

#include "BannerBridgeCpp.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <BidmadSDK/Cocos2dxBanner.h>

static NSMutableDictionary* BidmadCocos2dxBannerDic;

@interface BannerBridgeObjC : NSObject <BIDMADBannerDelegate>{
    NSString* mZoneId;
    Cocos2dxBanner* mBanner;
    BannerBridgeCpp* mController;
}
- (id)initWithZoneId:(NSString *)zoneId controller:(BannerBridgeCpp *)controller;
+ (id)getInstance:(NSString *)zoneId;
- (void)load:(int)y;
- (void)load:(int)x :(int)y;
- (void)setInterval:(int)interval;
- (void)removeBanner;
- (void)hideBannerView;
- (void)showBannerView;

@end


#endif /* RewardBridgeObjC_h */
