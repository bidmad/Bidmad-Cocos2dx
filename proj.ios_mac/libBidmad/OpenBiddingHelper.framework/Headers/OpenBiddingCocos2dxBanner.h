//
//  Cocos2dxBanner.h
//  BidmadSDK
//
//  Created by ADOP_Mac on 2021/06/29.
//  Copyright © 2021 ADOP Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OpenBiddingBanner.h"

@interface OpenBiddingCocos2dxBanner : NSObject<BIDMADOpenBiddingBannerDelegate>

@property (nonatomic, strong) id<BIDMADOpenBiddingBannerDelegate> delegate;
@property (nonatomic, strong) NSNumber *refreshInterval;

- (id)initWithZoneID:(NSString*)zoneId;
- (void)load:(int)y;
- (void)load:(int)x :(int)y;
- (void)setInterval:(int)interval;
- (void)removeBanner;
- (void)hideBannerView;
- (void)showBannerView;
- (void)setCUID:(NSString *)cuid;

- (void)BIDMADOpenBiddingBannerAllFail:(OpenBiddingBanner *)core;
- (void)BIDMADOpenBiddingBannerClosed:(OpenBiddingBanner *)core;
- (void)BIDMADOpenBiddingBannerLoad:(OpenBiddingBanner *)core;
- (void)BIDMADOpenBiddingBannerClick:(OpenBiddingBanner*)core;

@end
