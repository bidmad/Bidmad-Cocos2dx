//
//  RewardBridgeObjc.mm
//  BidmadiOS
//
//  Created by Kenneth on 2021/04/24.
//

#include "RewardBridgeObjC.h"

@implementation RewardBridgeObjC

- (id)initWithZoneId:(NSString *)zoneId controller:(RewardBridgeCpp*) controller;
{
    if(BidmadCocos2dxRewardDic == nil){
        BidmadCocos2dxRewardDic = [[NSMutableDictionary alloc] init];
    }
    
    mZoneId = zoneId;
    mController = controller;
    
    mRewardVideo = [[Cocos2dxReward alloc] initWithZoneId:zoneId];
    [mRewardVideo setDelegate:self];
    
    [BidmadCocos2dxRewardDic setObject:self forKey:zoneId];
    
    return self;
    
}

+ (id)getInstance:(NSString *)zoneId
{
    return [BidmadCocos2dxRewardDic objectForKey:zoneId];
}

- (void) loadRewardVideo {
    [mRewardVideo load];
}

- (void) showRewardVideo {
    [mRewardVideo show];
}

- (BOOL) isLoaded {
    return [mRewardVideo isLoaded];
}

- (void)BIDMADRewardVideoLoad:(BIDMADRewardVideo *)core {
    char* zoneId = (char *)[core.zoneID UTF8String];
    char* type = (char *)[@"onLoad" UTF8String];
    mController->callCallback(type, zoneId);
    
}
- (void)BIDMADRewardVideoShow:(BIDMADRewardVideo *)core {
    char* zoneId = (char *)[core.zoneID UTF8String];
    char* type = (char *)[@"onShow" UTF8String];
    mController->callCallback(type, zoneId);
}
- (void)BIDMADRewardVideoSucceed:(BIDMADRewardVideo *)core {
    char* zoneId = (char *)[core.zoneID UTF8String];
    char* type = (char *)[@"onComplete" UTF8String];
    mController->callCallback(type, zoneId);;
}
- (void)BIDMADRewardSkipped:(BIDMADRewardVideo *)core {
    char* zoneId = (char *)[core.zoneID UTF8String];
    char* type = (char *)[@"onSkip" UTF8String];
    mController->callCallback(type, zoneId);
}
- (void)BIDMADRewardVideoAllFail:(BIDMADRewardVideo *)core {
    char* zoneId = (char *)[core.zoneID UTF8String];
    char* type = (char *)[@"onFail" UTF8String];
    mController->callCallback(type, zoneId);
}
- (void)BIDMADRewardVideoClose:(BIDMADRewardVideo *)core {
    char* zoneId = (char *)[core.zoneID UTF8String];
    char* type = (char *)[@"onClose" UTF8String];
    mController->callCallback(type, zoneId);
}

@end
