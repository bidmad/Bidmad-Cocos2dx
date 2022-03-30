//
//  BidmadInMobiInterface.h
//  BidmadAdapterFC
//
//  Created by Seungsub Oh on 2022/03/14.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

static NSString * const BIDMAD_IM_GDPR_CONSENT_AVAILABLE = @"gdpr_consent_available";
static NSString * const BIDMAD_IM_GDPR_CONSENT_IAB = @"gdpr_consent";
static NSString * const BIDMAD_IM_SUBJECT_TO_GDPR = @"gdpr";
static NSString * const BIDMAD_IM_PARTNER_GDPR_CONSENT_AVAILABLE = @"partner_gdpr_consent_available";
static NSString * const BIDMAD_IM_PARTNER_GDPR_APPLIES = @"partner_gdpr_applies";

typedef NS_ENUM(NSInteger, BidmadIMSDKLogLevel) {
    kBidmadIMSDKLogLevelNone,
    kBidmadIMSDKLogLevelError,
    kBidmadIMSDKLogLevelDebug
};

@protocol BidmadIMBannerDelegate <NSObject>

-(void)bannerDidFinishLoading:(id)banner;
-(void)banner:(id)banner didFailToLoadWithError:(id)error;
-(void)banner:(id)banner didInteractWithParams:(id)params;

@end

@protocol BidmadIMPublic <NSObject>

+(void)initWithAccountID:(NSString *)accountID consentDictionary:(nullable NSDictionary*) consentDictionary andCompletionHandler:(void (^ _Nullable)( NSError * _Nullable )) completionBlock;
+(void)setLogLevel:(BidmadIMSDKLogLevel)desiredLogLevel;

@end

@protocol BidmadIMBanner <NSObject>

-(instancetype)initWithFrame:(CGRect)frame placementId:(long long)placementId delegate:(id<BidmadIMBannerDelegate>)delegate;
-(void)load;
-(void)shouldAutoRefresh:(BOOL)refresh;

-(void)removeFromSuperview;
@property (nonatomic) BOOL isHidden;

@end

@protocol BidmadIMInterstitialDelegate <NSObject>

-(void)interstitialDidFinishLoading:(id)interstitial;
-(void)interstitial:(id)interstitial didFailToLoadWithError:(id)error;
-(void)interstitialDidPresent:(id)interstitial;
-(void)interstitial:(id)interstitial didFailToPresentWithError:(id)error;
-(void)interstitialDidDismiss:(id)interstitial;
-(void)interstitial:(id)interstitial didInteractWithParams:(id)params;
-(void)interstitial:(id)interstitial rewardActionCompletedWithRewards:(id)rewards;

@end

@protocol BidmadIMInterstitial <NSObject>

-(id)initWithPlacementId:(long long)placementId delegate:(id<BidmadIMInterstitialDelegate>)delegate;
-(void)load;
-(void)showFromViewController:(UIViewController *)viewController;

@end

@interface BidmadInMobiInterface : NSObject

@end

NS_ASSUME_NONNULL_END
