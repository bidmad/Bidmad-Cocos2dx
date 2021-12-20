// Generated by Apple Swift version 5.5.2 (swiftlang-1300.0.47.5 clang-1300.0.29.30)
#ifndef BIDMADSDK_SWIFT_H
#define BIDMADSDK_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import CoreGraphics;
@import Foundation;
@import GoogleMobileAds;
@import ObjectiveC;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="BidmadSDK",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif


SWIFT_CLASS("_TtC9BidmadSDK8AreaInfo")
@interface AreaInfo : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class NSString;
@class NSNumber;
@class BIDMADNativeAdView;
@class UIViewController;

SWIFT_CLASS("_TtC9BidmadSDK19BIDMADAdmobNativeAd")
@interface BIDMADAdmobNativeAd : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull TEST_ADMOB_NATIVEAD;)
+ (NSString * _Nonnull)TEST_ADMOB_NATIVEAD SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull TEST_ADX_NATIVEAD;)
+ (NSString * _Nonnull)TEST_ADX_NATIVEAD SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic) BOOL isAdMob;
@property (nonatomic, strong) BIDMADNativeAdView * _Nullable nativeAdView;
- (nonnull instancetype)initWith:(NSString * _Nonnull)appid placementId:(NSString * _Nullable)placementId nativeAdMediationManager:(id _Nonnull)nativeAdMediationManager rootViewController:(UIViewController * _Nonnull)rootViewController nativeAdView:(id _Nonnull)nativeAdView isDebug:(BOOL)isDebug isChildDirectedAds:(NSNumber * _Nullable)isChildDirectedAds OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end

@class GADAdLoader;

@interface BIDMADAdmobNativeAd (SWIFT_EXTENSION(BidmadSDK)) <GADAdLoaderDelegate>
- (void)adLoader:(GADAdLoader * _Nonnull)adLoader didFailToReceiveAdWithError:(NSError * _Nonnull)error;
- (void)adLoaderDidFinishLoading:(GADAdLoader * _Nonnull)adLoader;
@end

@class GADNativeAd;

@interface BIDMADAdmobNativeAd (SWIFT_EXTENSION(BidmadSDK)) <GADNativeAdLoaderDelegate>
- (void)adLoader:(GADAdLoader * _Nonnull)adLoader didReceiveNativeAd:(GADNativeAd * _Nonnull)nativeAd;
@end

@class GADVideoController;

@interface BIDMADAdmobNativeAd (SWIFT_EXTENSION(BidmadSDK)) <GADVideoControllerDelegate>
- (void)videoControllerDidPlayVideo:(GADVideoController * _Nonnull)videoController;
- (void)videoControllerDidEndVideoPlayback:(GADVideoController * _Nonnull)videoController;
@end


SWIFT_PROTOCOL("_TtP9BidmadSDK29BIDMADNativeAdCommonInterface_")
@protocol BIDMADNativeAdCommonInterface
- (nonnull instancetype)initWith:(NSString * _Nonnull)appid placementId:(NSString * _Nullable)placementId nativeAdMediationManager:(id _Nonnull)nativeAdMediationManager rootViewController:(UIViewController * _Nonnull)rootViewController nativeAdView:(id _Nonnull)nativeAdView isDebug:(BOOL)isDebug isChildDirectedAds:(NSNumber * _Nullable)isChildDirectedAds;
- (void)loadNativeAd;
- (void)showNativeAd;
- (void)hideNativeAd;
- (void)remove;
@end


@interface BIDMADAdmobNativeAd (SWIFT_EXTENSION(BidmadSDK)) <BIDMADNativeAdCommonInterface>
- (void)loadNativeAd;
- (void)showNativeAd;
- (void)hideNativeAd;
- (void)remove;
@end


@interface BIDMADAdmobNativeAd (SWIFT_EXTENSION(BidmadSDK)) <GADNativeAdDelegate>
- (void)nativeAdDidRecordImpression:(GADNativeAd * _Nonnull)nativeAd;
- (void)nativeAdDidRecordClick:(GADNativeAd * _Nonnull)nativeAd;
- (void)nativeAdWillPresentScreen:(GADNativeAd * _Nonnull)nativeAd;
- (void)nativeAdWillDismissScreen:(GADNativeAd * _Nonnull)nativeAd;
- (void)nativeAdDidDismissScreen:(GADNativeAd * _Nonnull)nativeAd;
@end

@protocol BIDMADNativeAdDelegate;
@class UIImage;

SWIFT_CLASS("_TtC9BidmadSDK14BIDMADNativeAd")
@interface BIDMADNativeAd : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull AD_TYPE;)
+ (NSString * _Nonnull)AD_TYPE SWIFT_WARN_UNUSED_RESULT;
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull TEST_NATIVEAD_ZONEID;)
+ (NSString * _Nonnull)TEST_NATIVEAD_ZONEID SWIFT_WARN_UNUSED_RESULT;
@property (nonatomic, readonly, copy) NSString * _Nonnull zoneID;
@property (nonatomic, readonly, strong) UIViewController * _Nonnull rootViewController;
@property (nonatomic, weak) id <BIDMADNativeAdDelegate> _Nullable delegate;
@property (nonatomic, strong) BIDMADNativeAdView * _Nullable userCreatedNativeAdView;
@property (nonatomic, copy) NSDictionary<NSString *, UIImage *> * _Nullable starRatingImage;
- (nonnull instancetype)initWith:(NSString * _Nonnull)zoneID on:(UIViewController * _Nonnull)rootViewController OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end



SWIFT_PROTOCOL("_TtP9BidmadSDK26CompassDataRequestDelegate_")
@protocol CompassDataRequestDelegate
- (void)DataRequestSuccess;
- (void)DataRequestFail:(NSString * _Nonnull)errorReason;
@end


@interface BIDMADNativeAd (SWIFT_EXTENSION(BidmadSDK)) <CompassDataRequestDelegate>
- (void)DataRequestSuccess;
- (void)DataRequestFail:(NSString * _Nonnull)errorReason;
@end


SWIFT_PROTOCOL("_TtP9BidmadSDK27BIDMADNativeAdInnerDelegate_")
@protocol BIDMADNativeAdInnerDelegate
- (void)onLoad;
- (void)onShow;
- (void)onClick;
- (void)onFail:(NSString * _Nonnull)errorString;
@end


@interface BIDMADNativeAd (SWIFT_EXTENSION(BidmadSDK)) <BIDMADNativeAdInnerDelegate>
- (void)onLoad;
- (void)onShow;
- (void)onFail:(NSString * _Nonnull)errorString;
- (void)onClick;
@end

@class ReceivedAd;

SWIFT_PROTOCOL("_TtP9BidmadSDK14BidmadAdCommon_")
@protocol BidmadAdCommon
- (nonnull instancetype)initWith:(NSString * _Nonnull)zoneID on:(UIViewController * _Nonnull)rootViewController;
- (void)request;
- (void)selectWithAd:(ReceivedAd * _Nonnull)ad;
- (void)remove;
@end


@interface BIDMADNativeAd (SWIFT_EXTENSION(BidmadSDK)) <BidmadAdCommon>
- (void)request;
- (void)selectWithAd:(ReceivedAd * _Nonnull)ad;
- (void)remove;
- (void)show;
- (void)hide;
@end


@class NSError;

SWIFT_PROTOCOL("_TtP9BidmadSDK22BIDMADNativeAdDelegate_")
@protocol BIDMADNativeAdDelegate
- (void)bidmadNativeAdLoad;
- (void)bidmadNativeAdShow;
- (void)bidmadNativeAdClick;
- (void)bidmadNativeAdAllFail:(NSError * _Nonnull)error;
@end




SWIFT_CLASS("_TtC9BidmadSDK12BidmadAdInfo")
@interface BidmadAdInfo : NSObject
@property (nonatomic, copy) NSDictionary<NSString *, id> * _Nonnull adInfoDict;
@property (nonatomic, readonly, copy) NSString * _Nonnull adInfoKey;
@property (nonatomic, readonly, copy) NSString * _Nonnull adNetworkType;
@property (nonatomic) float floorPrice;
@property (nonatomic, readonly, copy) NSString * _Nonnull appID;
@property (nonatomic, readonly, copy) NSString * _Nonnull pubID;
@property (nonatomic, readonly) BOOL isOBH;
@property (nonatomic, readonly) NSInteger originalOrder;
/// ads_dic[currentAd][] adv_price
- (nonnull instancetype)initWithAdInfoDict:(NSDictionary<NSString *, id> * _Nonnull)adInfoDict adInfoKey:(NSString * _Nonnull)adInfoKey adNetworkType:(NSString * _Nullable)adNetworkType floorPrice:(NSNumber * _Nullable)floorPrice appID:(NSString * _Nullable)appID pubID:(NSString * _Nullable)pubID isOBH:(NSNumber * _Nullable)isOBH originalOrder:(NSNumber * _Nullable)originalOrder OBJC_DESIGNATED_INITIALIZER;
@property (nonatomic, readonly, copy) NSString * _Nonnull description;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_PROTOCOL("_TtP9BidmadSDK29BidmadAdapterBannerAdditional_")
@protocol BidmadAdapterBannerAdditional
- (void)setBannerSize:(NSString * _Nonnull)sizeString;
- (void)hide;
@end

@class UIView;

SWIFT_PROTOCOL("_TtP9BidmadSDK22BidmadAdapterEssential_")
@protocol BidmadAdapterEssential
- (nonnull instancetype)initWithAppID:(NSString * _Nonnull)appID pubID:(NSString * _Nullable)pubID rootVC:(UIViewController * _Nonnull)rootVC parentView:(UIView * _Nullable)parentView isChild:(NSNumber * _Nullable)isChild isGDPRConsent:(NSNumber * _Nullable)isGDPRConsent isCCPAConsent:(NSNumber * _Nullable)isCCPAConsent;
- (void)load;
- (void)setBidmadController:(id _Nonnull)bidmadController;
- (void)show;
- (void)remove;
- (void)setIsDebug:(BOOL)isDebug;
@end


SWIFT_PROTOCOL("_TtP9BidmadSDK29BidmadAdapterRewardAdditional_")
@protocol BidmadAdapterRewardAdditional
- (void)setIsRewardedAd:(BOOL)isRewardedAd;
@end

@class CompassReceivedData;

SWIFT_CLASS("_TtC9BidmadSDK13BidmadNetwork")
@interface BidmadNetwork : NSObject
@property (nonatomic, copy) NSString * _Nullable realZoneID;
@property (nonatomic, strong) CompassReceivedData * _Nullable adData;
- (nonnull instancetype)initWithDelegate:(id <CompassDataRequestDelegate> _Nonnull)delegateArg OBJC_DESIGNATED_INITIALIZER;
- (NSDictionary<NSString *, id> * _Nullable)objcCompatible SWIFT_WARN_UNUSED_RESULT;
- (void)requestForZoneID:(NSString * _Nonnull)zoneID;
- (void)remove;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@class UIEvent;
@class NSCoder;

SWIFT_CLASS("_TtC9BidmadSDK18BidmadParentUIView")
@interface BidmadParentUIView : UIView
- (UIView * _Nullable)hitTest:(CGPoint)point withEvent:(UIEvent * _Nullable)event SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC9BidmadSDK13BidmadUtility")
@interface BidmadUtility : NSObject
/// If nil, the app does not have to be compliant under GDPR.
/// But if the app did set GDPR Consent Status, it will either return true or false in NSNumber format.
+ (NSNumber * _Nullable)gdprSettingToOptionalBool SWIFT_WARN_UNUSED_RESULT;
+ (NSArray<BidmadAdInfo *> * _Nonnull)bidmadSwiftSort:(NSArray<BidmadAdInfo *> * _Nonnull)adInfoArray SWIFT_WARN_UNUSED_RESULT;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC9BidmadSDK10ChangeInfo")
@interface ChangeInfo : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end



SWIFT_CLASS("_TtC9BidmadSDK19CompassReceivedData")
@interface CompassReceivedData : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC9BidmadSDK8DateInfo")
@interface DateInfo : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC9BidmadSDK11ECPMRevInfo")
@interface ECPMRevInfo : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC9BidmadSDK12LabelService")
@interface LabelService : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


SWIFT_CLASS("_TtC9BidmadSDK18MediationTableView")
@interface MediationTableView : UIView
- (nonnull instancetype)initWithFrame:(CGRect)frame adOrder:(NSArray<NSString *> * _Nonnull)adOrder adEcpm:(NSArray<NSString *> * _Nonnull)adEcpm adFill:(NSArray<NSString *> * _Nonnull)adFill tableViewCellHeight:(NSInteger)tableViewCellHeight OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithFrame:(CGRect)frame SWIFT_UNAVAILABLE;
@end

@class UITableView;
@class NSIndexPath;

@interface MediationTableView (SWIFT_EXTENSION(BidmadSDK)) <UITableViewDelegate>
- (CGFloat)tableView:(UITableView * _Nonnull)tableView heightForRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath SWIFT_WARN_UNUSED_RESULT;
@end

@class UITableViewCell;

@interface MediationTableView (SWIFT_EXTENSION(BidmadSDK)) <UITableViewDataSource>
- (NSInteger)tableView:(UITableView * _Nonnull)tableView numberOfRowsInSection:(NSInteger)section SWIFT_WARN_UNUSED_RESULT;
- (UITableViewCell * _Nonnull)tableView:(UITableView * _Nonnull)tableView cellForRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath SWIFT_WARN_UNUSED_RESULT;
@end


SWIFT_CLASS("_TtC9BidmadSDK10ReceivedAd")
@interface ReceivedAd : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@interface UIDevice (SWIFT_EXTENSION(BidmadSDK))
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, copy) NSString * _Nonnull bidmadModelNameChecker;)
+ (NSString * _Nonnull)bidmadModelNameChecker SWIFT_WARN_UNUSED_RESULT;
@end

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif
