//
//  BidmadIronSourceBridge.h
//  BidmadAdapterFC
//
//  Created by Seungsub Oh on 2022/02/16.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol BidmadBridgeISRewardedVideoDelegate <NSObject>

@required

- (void)rewardedVideoHasChangedAvailability:(BOOL)available;
- (void)didReceiveRewardForPlacement:(id)placementInfo;
- (void)rewardedVideoDidFailToShowWithError:(NSError *)error;
- (void)rewardedVideoDidOpen;
- (void)rewardedVideoDidClose;
- (void)rewardedVideoDidStart;
- (void)rewardedVideoDidEnd;
- (void)didClickRewardedVideo:(id)placementInfo;

@end

@protocol BidmadBridgeISInterstitialDelegate <NSObject>

@required

- (void)interstitialDidLoad;
- (void)interstitialDidFailToLoadWithError:(NSError *)error;
- (void)interstitialDidOpen;
- (void)interstitialDidClose;
- (void)interstitialDidShow;
- (void)interstitialDidFailToShowWithError:(NSError *)error;
- (void)didClickInterstitial;

@end

@protocol BidmadBridgeISBannerDelegate <NSObject>

@required

- (void)bannerDidLoad:(id)bannerView;
- (void)bannerDidFailToLoadWithError:(NSError *)error;
- (void)didClickBanner;
- (void)bannerWillPresentScreen;
- (void)bannerDidDismissScreen;
- (void)bannerWillLeaveApplication;

@end

typedef enum BidmadLogLevelValues
{
    BIDMAD_IS_LOG_NONE = -1,
    BIDMAD_IS_LOG_INTERNAL = 0,
    BIDMAD_IS_LOG_INFO = 1,
    BIDMAD_IS_LOG_WARNING = 2,
    BIDMAD_IS_LOG_ERROR = 3,
    BIDMAD_IS_LOG_CRITICAL = 4,
    
} BidmadISLogLevel;

typedef enum BidmadLogTagValue
{
    BIDMAD_TAG_API,
    BIDMAD_TAG_DELEGATE,
    BIDMAD_TAG_ADAPTER_API,
    BIDMAD_TAG_ADAPTER_DELEGATE,
    BIDMAD_TAG_NETWORK,
    BIDMAD_TAG_NATIVE,
    BIDMAD_TAG_INTERNAL,
    BIDMAD_TAG_EVENT
    
} BidmadLogTag;

@protocol BidmadISLogDelegate <NSObject>

@required

- (void)sendLog:(NSString *)log level:(BidmadISLogLevel)level tag:(BidmadLogTag)tag;

@end

@protocol BidmadISPlacementInfo <NSObject>

@required

@property (readonly) NSString *placementName;
@property (readonly) NSString *rewardName;
@property (readonly) NSNumber *rewardAmount;

@end

@interface BidmadIronSourceBridge : NSObject

+ (void)setRewardedVideoDelegate:(id<BidmadBridgeISRewardedVideoDelegate>)delegate;
+ (void)setInterstitialDelegate:(id<BidmadBridgeISInterstitialDelegate>)delegate;
+ (void)setBannerDelegate:(id<BidmadBridgeISBannerDelegate>)delegate;
+ (void)initWithAppKey:(NSString *)appKey;
+ (void)initWithAppKey:(NSString *)appKey adUnits:(NSArray<NSString *> *)adUnits;
+ (void)validateIntegration;

+ (NSString *)constBANNER;
+ (NSString *)constINTERSTITIAL;
+ (NSString *)constREWARDEDVIDEO;

+ (void)loadBannerWithViewController:(UIViewController *)viewController size:(CGSize)size;
+ (void)loadBannerWithViewController:(UIViewController *)viewController size:(CGSize)size placement:(nullable NSString *)placementName;
+ (void)loadInterstitial;
+ (BOOL)isRewardAdLoaded;
+ (void)setPrivacyIsGDPRConsent:(NSNumber * _Nullable)isGDPRConsent
                  isCCPAConsent:(NSNumber * _Nullable)isCCPAConsent
              isChildDirectedAd:(NSNumber * _Nullable)isChildDirectedAd;
+ (void)showInterstitial:(UIViewController *)viewController placement:(NSString *)placement;
+ (void)showReward:(UIViewController *)viewController placement:(nullable NSString *)placementName;
+ (void)destroyBanner:(id)banner;
+ (void)setIronSourceDebugLog:(BOOL)toggle;
+ (void)setIronSourceLogDelegate:(id<BidmadISLogDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
