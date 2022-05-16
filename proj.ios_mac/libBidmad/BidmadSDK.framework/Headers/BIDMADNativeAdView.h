//
//  BIDMADNativeAdView.h
//  BidmadSDK
//
//  Created by Seungsub Oh on 2021/08/17.
//  Copyright © 2021 ADOP Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GoogleMobileAds/GADNativeAd.h>

NS_ASSUME_NONNULL_BEGIN

@interface BIDMADNativeAdView : GADNativeAdView

@property(nonatomic, weak, nullable) IBOutlet UIImageView* iconViewCustom;
@property(nonatomic, weak, nullable) IBOutlet UILabel* headlineViewCustom;
@property(nonatomic, weak, nullable) IBOutlet UILabel* advertiserViewCustom;
@property(nonatomic, weak, nullable) IBOutlet UIView* starRatingViewCustom;
@property(nonatomic, weak, nullable) IBOutlet UILabel* bodyViewCustom;
@property(nonatomic, weak, nullable) IBOutlet UIView* mediaViewCustom;
@property(nonatomic, weak, nullable) IBOutlet UILabel* priceViewCustom;
@property(nonatomic, weak, nullable) IBOutlet UILabel* storeViewCustom;
@property(nonatomic, weak, nullable) IBOutlet UIButton* callToActionViewCustom;

- (void)setup;
- (void)cleanUp:(NSString *)adNetworkNm;
- (GADMediaView* _Nonnull)setupForGoogleAd:(GADMediaView* _Nullable)mediaViewToSetup;

@end

NS_ASSUME_NONNULL_END
