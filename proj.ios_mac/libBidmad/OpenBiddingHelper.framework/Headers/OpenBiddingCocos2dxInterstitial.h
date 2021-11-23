//
//  Cocos2dxInterstitial.h
//  BidmadSDK
//
//  Created by Kenneth on 2021/04/27.
//  Copyright © 2021 ADOP Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BidmadSDK/BIDMADSetting.h>
#import "OpenBiddingInterstitial.h"

@interface OpenBiddingCocos2dxInterstitial : NSObject <BIDMADOpenBiddingInterstitialDelegate>{
    NSString* mZoneId;
    UIViewController *rootVC;
    id<BIDMADOpenBiddingInterstitialDelegate> delegate;
    @public OpenBiddingInterstitial* bidmadInterstitial;
}

- (id)initWithZoneId:(NSString *)zoneId viewController:(UIViewController *)rootVC;
- (void)setDelegate:(id) param;
- (void)load;
- (void)show;
- (bool)isLoaded;
- (void)setAutoReoad:(bool)isAutoReload;

@end
