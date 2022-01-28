//
//  BIDMADBanner.h
//  BIDMADMobileAds
//
//  Created by 김선정 on 2015. 7. 13..
//  Copyright (c) 2015년 ADOP Co., Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BIDMADUtil.h"
#import "BIDMADSetting.h"
#import "BIDMADAtom.h"
#import "BIDMADAdmob.h"
#import "BIDMADAdmanager.h"

@protocol BIDMADBannerDelegate;

@protocol BIDMADBannerInnerDelegate <NSObject>

@optional

- (void)onBannerAllFail;
- (void)onBannerError:(NSString *)error failType:(NSString *)failType;
- (void)onBannerClosed;
- (void)onBannerLoad;
- (void)onBannerClick;

@end

@interface BIDMADBanner : UIView<BIDMADBannerInnerDelegate>

@property (assign, nonatomic) SEL requestSelector;
@property (strong, nonatomic) NSDictionary* ads_dic;
@property (nonatomic) bannerSizeType bannerType;
@property (strong, nonatomic) id<BIDMADBannerDelegate> delegate;
@property (strong, nonatomic) id<BIDMADBannerInnerDelegate> innerDelegate;

@property (strong, nonatomic) NSDictionary* ecpm_rev_info;
@property (strong, nonatomic) NSDictionary* area_info;

@property (strong, nonatomic) NSDictionary* change_info;
@property (strong, nonatomic) NSDictionary* date;

@property (nonatomic) int mediationNumber;

@property (nonatomic) BOOL isLabelService;

@property (nonatomic) BOOL isLabelServiceAdmin;

@property (nonatomic) NSString* realZoneId;

@property (nonatomic) NSString* zoneID;

@property (nonatomic, assign) int refreshInterval;

@property (nonatomic, strong) NSString* houseBannerImgPath;

@property (nonatomic) BOOL isRepeat; //default YES

@property (nonatomic, strong) NSString* currentAdNetwork;

@property (nonatomic, strong) NSString * _Nullable CUID;

/// Banner Size Parameter is no longer supported, Please use initWithParentViewController:(UIViewController *):(CGPoint)
- (id)initWithParentViewController:(UIViewController *)parentVC adsPosition:(CGPoint)point bannerSize:(bannerSizeType)bannerTypeParam __deprecated;
/// Banner Size Parameter is no longer supported, Please use initWithParentViewController:(UIViewController *):(UIView *)
- (id)initWithParentViewController:(UIViewController *)parentVC rootView:(UIView *)view bannerSize:(bannerSizeType) bannerTypeParam __deprecated;

- (id)initWithParentViewController:(UIViewController *)parentVC adsPosition:(CGPoint)point;
- (id)initWithParentViewController:(UIViewController *)parentVC rootView:(UIView *)view;
- (id)initWithParentViewController:(UIViewController *)parentVC yPoint:(int)yPoint;
- (instancetype)initWithZoneID:(NSString * _Nonnull)zoneID
          parentViewController:(UIViewController * _Nonnull)parentVC
                    parentView:(UIView * _Nullable)parentView
                   instanceOBH:(id _Nullable)instanceOBH
                     sessionID:(NSString * _Nonnull)sessionID
                     xPosition:(NSNumber * _Nullable)xPosition
                     yPosition:(NSNumber * _Nullable)yPosition
                       adsDict:(NSDictionary * _Nullable)adsDict
                   revInfoECPM:(NSDictionary * _Nullable)revInfoECPM
                      areaInfo:(NSDictionary * _Nullable)areaInfo
                    changeInfo:(NSDictionary * _Nullable)changeInfo
                          date:(NSDictionary * _Nullable)date
                isLabelService:(NSNumber * _Nullable)isLabelService
           isLabelServiceAdmin:(NSNumber * _Nullable)isLabelServiceAdmin
                    realZoneID:(NSString * _Nonnull)realZoneID;
/// REQUEST ADS
- (void)requestBannerView;
/// DELETE ADS
- (void)removeAds;
/// This method sorts the dictionary of compass ads data from the least floor price to the highest.
/// It returns the NSError if necessary properties are not available nor nil.
/// If success, it lastly calls selectAds with the first ad with the highest floor price.
- (NSError * _Nullable)sortBasedOnFloorPriceAndSelectFirstAd;
- (NSError * _Nullable)withoutSortingJustSelectFirstAd;
- (void)selectAds:(NSDictionary *)lv_dic isAdsExist:(BOOL)isAds;
- (void)runAds;
- (void)setParentController:(UIViewController *)parentVC;
- (void)hideView;
- (void)showView;

@end

@protocol BIDMADBannerDelegate <NSObject>

@optional

- (void)BIDMADBannerAllFail:(BIDMADBanner *)core;
- (void)BIDMADBannerError:(BIDMADBanner *)core code:(NSString *)error;
- (void)BIDMADBannerClosed:(BIDMADBanner *)core;
- (void)BIDMADBannerLoad:(BIDMADBanner *)core;
- (void)BIDMADBannerClick:(BIDMADBanner*) core;

@end
