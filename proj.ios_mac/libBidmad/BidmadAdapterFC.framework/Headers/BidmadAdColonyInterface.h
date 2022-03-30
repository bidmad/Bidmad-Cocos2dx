//
//  BidmadAdColonyInterface.h
//  BidmadAdapterFC
//
//  Created by Seungsub Oh on 2022/03/07.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

#define BIDMAD_ADC_GDPR @"GDPR"
#define BIDMAD_ADC_CCPA @"CCPA"
#define BIDMAD_ADC_COPPA @"COPPA"

struct BidmadAdColonyAdSize {
    CGFloat width;
    CGFloat height;
};
typedef struct BidmadAdColonyAdSize BidmadAdColonyAdSize;

@protocol BidmadADCAdViewDelegate <NSObject>

@required
- (void)adColonyAdViewDidLoad:(UIView * _Nonnull)adView;
- (void)adColonyAdViewDidFailToLoad:(id _Nonnull)error;

@optional
- (void)adColonyAdViewWillLeaveApplication:(UIView * _Nonnull)adView;
- (void)adColonyAdViewWillOpen:(UIView * _Nonnull)adView;
- (void)adColonyAdViewDidClose:(UIView * _Nonnull)adView;
- (void)adColonyAdViewDidReceiveClick:(UIView * _Nonnull)adView;

@end

@protocol BidmadADCAppOptions <NSObject>
- (id _Nonnull)init;
- (id _Nonnull)setPrivacyFrameworkOfType:(NSString *)type isRequired:(BOOL)required;
- (id _Nonnull)setPrivacyConsentString:(NSString *)consentString forType:(NSString *)type;
- (BOOL)getPrivacyFrameworkRequiredForType:(NSString *)type;
- (NSString *)getPrivacyConsentStringForType:(NSString *)type;
@end

@protocol BidmadADCInterstitial <NSObject>
@property (atomic, assign, readonly) BOOL expired;
- (BOOL)showWithPresentingViewController:(UIViewController *)viewController;
- (void)cancel;
@end

@protocol BidmadADCInterstitialDelegate <NSObject>
@required
- (void)adColonyInterstitialDidLoad:(id<BidmadADCInterstitial> _Nonnull)interstitial;
- (void)adColonyInterstitialDidFailToLoad:(id _Nonnull)error;

@optional
- (void)adColonyInterstitialWillOpen:(id<BidmadADCInterstitial> _Nonnull)interstitial;
- (void)adColonyInterstitialDidClose:(id<BidmadADCInterstitial> _Nonnull)interstitial;
- (void)adColonyInterstitialExpired:(id<BidmadADCInterstitial> _Nonnull)interstitial;
- (void)adColonyInterstitialWillLeaveApplication:(id<BidmadADCInterstitial> _Nonnull)interstitial;
- (void)adColonyInterstitialDidReceiveClick:(id<BidmadADCInterstitial> _Nonnull)interstitial;
@end

@protocol BidmadADCZone <NSObject>
@property (nonatomic, readonly) BOOL rewarded;
- (void)setReward:(nullable void (^)(BOOL success, NSString *name, int amount))reward;
@end

@protocol BidmadADCPublic <NSObject>
+ (void)configureWithAppID:(NSString *)appID zoneIDs:(NSArray<NSString *> *)zoneIDs options:(nullable id)options completion:(nullable void (^)(NSArray *zones))completion;
+ (void)requestAdViewInZone:(NSString *)zoneID withSize:(BidmadAdColonyAdSize)size viewController:(UIViewController *)viewController andDelegate:(id<BidmadADCAdViewDelegate>)delegate;
+ (void)requestAdViewInZone:(NSString *)zoneID withSize:(BidmadAdColonyAdSize)size andOptions:(nullable id)options viewController:(UIViewController *)viewController andDelegate:(id<BidmadADCAdViewDelegate>)delegate;
+ (void)requestInterstitialInZone:(NSString *)zoneID options:(nullable id)options andDelegate:(id<BidmadADCInterstitialDelegate> _Nonnull)delegate;
@end

@interface BidmadAdColonyInterface : NSObject

@end

NS_ASSUME_NONNULL_END
