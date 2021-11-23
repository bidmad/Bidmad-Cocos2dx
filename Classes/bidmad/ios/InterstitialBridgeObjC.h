//
//  RewardBridgeObjC.h
//
//  Created by Kenneth on 2021/04/24.
//

#ifndef RewardBridgeObjC_h
#define RewardBridgeObjC_h

#include "InterstitialBridgeCpp.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <OpenBiddingHelper/OpenBiddingInterstitial.h>
#import <OpenBiddingHelper/OpenBiddingCocos2dxInterstitial.h>

static NSMutableDictionary* BidmadCocos2dxInterstitialDic;

@interface InterstitialBridgeObjC : NSObject <BIDMADOpenBiddingInterstitialDelegate>{
    NSString* mZoneId;
    OpenBiddingCocos2dxInterstitial* mInterstitialVideo;
    InterstitialBridgeCpp* mController;
}
- (id)initWithZoneId:(NSString *)zoneId controller:(InterstitialBridgeCpp*) controller;
+ (id)getInstance:(NSString*) zoneId;
- (void)loadInterstitial;
- (void)showInterstitial;
- (BOOL)isLoaded;
- (void)setAutoReload:(bool)isAutoReload;

@end


#endif /* RewardBridgeObjC_h */
