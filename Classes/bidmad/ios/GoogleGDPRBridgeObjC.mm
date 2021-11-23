//
//  GoogleGDPRBridgeObjC.m
//  BidmadCocos2dxSample-mobile
//
//  Created by ADOP_Mac on 2021/11/19.
//

#import "GoogleGDPRBridgeObjC.h"

@interface GoogleGDPRBridgeObjC() <BIDMADGDPRforGoogleProtocol> {
    
}

@end

@implementation GoogleGDPRBridgeObjC

+ (id _Nonnull)sharedInstance {
    static GoogleGDPRBridgeObjC *sharedInstance = nil;
    static dispatch_once_t pred;

    if (sharedInstance) return sharedInstance;

    dispatch_once(&pred, ^{
        sharedInstance = [GoogleGDPRBridgeObjC alloc];
        sharedInstance = [sharedInstance init];
    });

    return sharedInstance;
}

- (id _Nonnull)init {
    self = [super init];
    
    if (self) {
        [[Cocos2dxGDPRforGoogle sharedInstance] setListener];
        [[Cocos2dxGDPRforGoogle sharedInstance] setDelegate: self];
    }
    
    return self;
}

- (void)setCallbackController:(GoogleGDPRBridgeCpp *)controller {
    self->mController = controller;
}

- (void)setDebug:(char* _Nonnull)testDeviceId isEEA:(bool)isEEA {
    [[Cocos2dxGDPRforGoogle sharedInstance] setDebug:testDeviceId isTestEurope:isEEA];
}

- (void)requestConsentInfoUpdate {
    [[Cocos2dxGDPRforGoogle sharedInstance] requestConsentInfoUpdate];
}

- (bool)isConsentFormAvailable {
    return [[Cocos2dxGDPRforGoogle sharedInstance] isConsentFormAvailable];
}

- (void)loadForm {
    [[Cocos2dxGDPRforGoogle sharedInstance] loadForm];
}

- (int)getConsentStatus {
    return [[Cocos2dxGDPRforGoogle sharedInstance] getConsentStatus];
}

- (void)reset {
    [[Cocos2dxGDPRforGoogle sharedInstance] reset];
}

- (void)showForm {
    [[Cocos2dxGDPRforGoogle sharedInstance] showForm];
}

- (void)onConsentFormDismissed:(NSError *)formError {
    char *callbackType = (char*)[@"onConsentFormDismissedCallback" UTF8String];
    char * errorFormattedString = (char *)[@"Form closed" UTF8String];
    if (formError != nil) {
        NSString* errorCode = [[NSNumber numberWithInteger:[formError code]] stringValue];
        NSString* errorReason = [formError localizedDescription];
        errorFormattedString = (char *)[[NSString stringWithFormat:@"Error [Message : %@][Code : %@]", errorReason, errorCode] UTF8String];
    }
    
    mController->callCallback(callbackType, errorFormattedString);
}

- (void)onConsentFormLoadFailure:(NSError *)formError {
    char* type = (char *)[@"onConsentFormLoadFailureCallback" UTF8String];
    NSString* errorCode = [[NSNumber numberWithInteger:[formError code]] stringValue];
    NSString* errorReason = [formError localizedDescription];
    char * errorFormattedString = (char *)[[NSString stringWithFormat:@"Error [Message : %@][Code : %@]", errorReason, errorCode] UTF8String];
    
    mController->callCallback(type, errorFormattedString);
}

- (void)onConsentFormLoadSuccess {
    char *type = (char *)[@"onConsentFormLoadSuccessCallback" UTF8String];
    mController->callCallback(type, nil);
}

- (void)onConsentInfoUpdateFailure:(NSError *)formError {
    char *type = (char *)[@"onConsentInfoUpdateFailureCallback" UTF8String];
    NSString* errorCode = [[NSNumber numberWithInteger:[formError code]] stringValue];
    NSString* errorReason = [formError localizedDescription];
    char * errorFormattedString = (char *)[[NSString stringWithFormat:@"Error [Message : %@][Code : %@]", errorReason, errorCode] UTF8String];
    
    mController->callCallback(type, errorFormattedString);
}

- (void)onConsentInfoUpdateSuccess {
    char *type = (char *)[@"onConsentInfoUpdateSuccessCallback" UTF8String];
    mController->callCallback(type, nil);
}

@end
