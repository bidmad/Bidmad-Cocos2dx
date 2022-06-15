//
//  BidmadSendLogDelegate.h
//  ADOPUtility
//
//  Created by Seungsub Oh on 2022/06/03.
//

#import <Foundation/Foundation.h>

@protocol BidmadSendLogDelegate <NSObject>

@optional
- (void)bidmadSendLogWithType:(NSString * _Nonnull)logType sessionId:(NSString * _Nonnull)sessionId;

@end
