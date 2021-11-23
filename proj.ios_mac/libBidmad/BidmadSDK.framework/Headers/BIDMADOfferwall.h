//
//  BIDMADOfferwall.h
//  BidmadSDK
//
//  Created by Kenneth on 2021/02/05.
//  Copyright © 2021 ADOP Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BIDMADUtil.h"
#import "BIDMADSetting.h"

@protocol BIDMADOfferwallDelegate;
@protocol BIDMADOfferwallInnerDelegate;

@interface BIDMADOfferwall : NSObject

@property (nonatomic, strong) id<BIDMADOfferwallDelegate> delegate;
@property (nonatomic, strong) id<BIDMADOfferwallInnerDelegate> innerDelegate;

@property (nonatomic, strong) UIViewController* parentViewController;
@property (strong, nonatomic) NSDictionary* ads_dic;
@property (strong, nonatomic) NSDictionary* ecpm_rev_info;
@property (strong, nonatomic) NSDictionary* area_info;
@property (strong, nonatomic) NSDictionary* change_info;
@property (strong, nonatomic) NSDictionary* date;

@property (nonatomic) NSString * zoneID;
@property (nonatomic) bool justLoading;
@property (nonatomic) int mediationNumber;
@property (nonatomic) BOOL isLabelService;
@property (nonatomic) BOOL isLabelServiceAdmin;
@property (nonatomic) NSString* realZoneId;
@property (nonatomic) BOOL isLoaded;

- (id)initWithZoneId:(NSString *)zoneId;
- (void)loadOfferwall;
- (void)showOfferwall;
- (void)getCurrencyBalance;
- (void)spendCurrency:(int)amount;
- (void)selectAds:(NSDictionary *)lv_dic;
- (NSNumber *)getGDPRStatusWrapper;

- (void)onInitSuccess;
- (void)onInitFailWithError:(NSString *)error;
- (void)onLoadAd;
- (void)onShowAd;
- (void)onFailedAdWithCode:(NSString *)errorCode failType:(NSString *)failType;
- (void)onCloseAd;
- (void)onGetCurrencyBalanceSuccessWithCurrencyInfo:(NSString *)currencyName balance:(NSNumber *)balance;
- (void)onGetCurrencyBalanceFailWithError:(NSString *)errorString;
- (void)onSpendCurrencySuccessWithCurrencyInfo:(NSString *)currencyName balance:(NSNumber *)balance;
- (void)onSpendCurrencyFailWithError:(NSString *)errorString;

@end

@protocol BIDMADOfferwallDelegate <NSObject>
@optional

- (void)BIDMADOfferwallInitSuccess:(BIDMADOfferwall *)core;
- (void)BIDMADOfferwallInitFail:(BIDMADOfferwall *)core error:(NSString *)error;

- (void)BIDMADOfferwallLoadAd:(BIDMADOfferwall *)core;
- (void)BIDMADOfferwallShowAd:(BIDMADOfferwall *)core;
- (void)BIDMADOfferwallFailedAd:(BIDMADOfferwall *)core;
- (void)BIDMADOfferwallCloseAd:(BIDMADOfferwall *)core;

- (void)BIDMADOfferwallGetCurrencyBalanceSuccess:(BIDMADOfferwall *)core currencyName:(NSString *)currencyName balance:(int)balance;
- (void)BIDMADOfferwallGetCurrencyBalanceFail:(BIDMADOfferwall *)core error:(NSString *)error;
- (void)BIDMADOfferwallSpendCurrencySuccess:(BIDMADOfferwall *)core currencyName:(NSString *)currencyName balance:(int)balance;
- (void)BIDMADOfferwallSpendCurrencyFail:(BIDMADOfferwall *)core error:(NSString *)error;

@end

