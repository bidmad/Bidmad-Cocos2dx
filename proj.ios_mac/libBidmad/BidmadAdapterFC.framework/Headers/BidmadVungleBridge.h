//
//  BidmadVungleBridge.h
//  BidmadAdapterFC
//
//  Created by Seungsub Oh on 2022/02/21.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, BidmadVungleFullscreen) {
    BidmadVungleFullscreenFailed,
    BidmadVungleFullscreenSuccess,
    BidmadVungleFullscreenRewarded,
    BidmadVungleFullscreenClosed
};

typedef void (^BidmadVungleInitAction)(NSError * _Nullable);
typedef void (^BidmadVungleLoadAction)(NSError * _Nullable);
typedef void (^BidmadVungleClickAction)(void);
typedef void (^BidmadVungleShowAction)(BidmadVungleFullscreen);

@interface BidmadVungleBridge : NSObject

- (BOOL)isSDKInitialized;
- (void)startWithAppId:(nonnull NSString *)appID completion:(BidmadVungleInitAction _Nonnull)action;
- (void)loadBannerWithPlacementID:(NSString * _Nonnull)placementID withSize:(CGSize)bannerSize completion:(BidmadVungleLoadAction _Nonnull)action;
- (void)loadInterstitialWithPlacementID:(NSString * _Nonnull)placementID completion:(BidmadVungleLoadAction _Nonnull)action;
- (void)showInterstitialWithViewController:(UIViewController *)parentVC placementID:(NSString *)placementID showActions:(BidmadVungleShowAction)showAction;
- (NSError * _Nullable)showBannerWithParentView:(UIView *)containerView placementID:(NSString * _Nonnull)placementID;
- (void)clickCallbackTracker:(BidmadVungleClickAction)action;
- (void)setPrivacyIsGDPRConsent:(NSNumber * _Nullable)isGDPRConsent
                  isCCPAConsent:(NSNumber * _Nullable)isCCPAConsent;
- (void)removeAll;

@end

NS_ASSUME_NONNULL_END
