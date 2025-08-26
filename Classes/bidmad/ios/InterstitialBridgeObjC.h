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
#import <BidmadSDK/BidmadSDK.h>
#import <BidmadSDK/BidmadSDK-Swift.h>
#import <OpenBiddingHelper/OpenBiddingHelper.h>
#import <OpenBiddingHelper/OpenBiddingHelper-Swift.h>
#import <OpenBiddingHelper/BidmadInterstitialAdForGame.h>

static NSMutableDictionary* BidmadCocos2dxInterstitialDic;

@interface InterstitialBridgeObjC : NSObject <BIDMADOpenBiddingInterstitialDelegate> {
    InterstitialBridgeCpp* mController;
}

@property (nonatomic, strong) NSString * _Nonnull mZoneId;

+ (void)initialSetupWithZoneId:(NSString *)zoneId controller:(InterstitialBridgeCpp *)controller;
+ (id)getInstance:(NSString*) zoneId;
- (void)loadInterstitial;
- (void)showInterstitial;
- (BOOL)isLoaded;
- (void)setAutoReload:(bool)isAutoReload;

@end


#endif /* RewardBridgeObjC_h */
