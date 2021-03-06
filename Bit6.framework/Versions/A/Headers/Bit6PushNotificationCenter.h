//
//  Bit6PushNotificationCenter.h
//  Bit6
//
//  Created by Carlos Thurber Boaventura on 03/31/14.
//  Copyright (c) 2014 Bit6. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <PushKit/PushKit.h>
#import <UserNotifications/UserNotifications.h>

NS_ASSUME_NONNULL_BEGIN

/*! Bit6PushNotificationCenter is used to handle the remote notifications. */
@interface Bit6PushNotificationCenter : NSObject

/*! Unavailable init. Use Bit6.pushNotification instead.
 @return a new instance of the class.
 */
- (instancetype)init NS_UNAVAILABLE;

/*! Returns NO if the device is running in Sandbox. 
 @return NO if the device is running in Sandbox. */
+ (BOOL)isAppStoreEnvironment;

/*! The regular APNS push token for this device. */
@property (nullable, nonatomic, readonly) NSString* deviceToken;

/*! The VoIP APNS push token for this device. */
@property (nullable, nonatomic, readonly) NSString* voipToken;

/*! Should be called inside the -[UIApplicationDelegate application:didReceiveRemoteNotification:] and -[UIApplicationDelegate application:didReceiveLocalNotification:] implementation.
 @param userInfo A dictionary that contains information related to the remote notification, potentially including a badge number for the app icon, an alert sound, an alert message to display to the user, a notification identifier, and custom data. The provider originates it as a JSON-defined dictionary that iOS converts to an NSDictionary object; the dictionary may contain only property-list objects plus NSNull.
 */
- (void)didReceiveNotificationUserInfo:(NSDictionary*)userInfo;

/*! Should be called inside the -[UIApplicationDelegate application:didReceiveRemoteNotification:fetchCompletionHandler:] implementation.
 @param userInfo A dictionary that contains information related to the remote notification, potentially including a badge number for the app icon, an alert sound, an alert message to display to the user, a notification identifier, and custom data. The provider originates it as a JSON-defined dictionary that iOS converts to an NSDictionary object; the dictionary may contain only property-list objects plus NSNull.
 @param completionHandler The block to execute when the download operation is complete. When calling this block, pass in the fetch result value that best describes the results of your download operation. You must call this handler and should do so as soon as possible.
 */
- (void)didReceiveNotificationUserInfo:(NSDictionary *)userInfo fetchCompletionHandler:(nullable void (^)(UIBackgroundFetchResult))completionHandler;

/*! Should be called inside the -[UNUserNotificationCenterDelegate userNotificationCenter:didReceiveNotificationResponse:withCompletionHandler:] implementation.
 @param center The notification center that received the notification.
 @param response The user’s response to the notification. This object contains the original notification and the identifier string for the selected action. If the action allowed the user to provide a textual response, this object is an instance of the UNTextInputNotificationResponse class.
 @param completionHandler The block to execute when you have finished processing the user’s response. You must execute this block from your method and should call it as quickly as possible. The block has no return value or parameters.
 */
- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void(^)())completionHandler;

/*! Should be called inside the -[UNUserNotificationCenterDelegate userNotificationCenter:willPresentNotification:withCompletionHandler:] implementation.
 @param center The notification center that received the notification.
 @param notification The notification that is about to be delivered. Use the information in this object to determine an appropriate course of action. For example, you might use the arrival of the notification to fetch new content or update your app’s interface.
 @param completionHandler The block to execute with the presentation option for the notification. Always execute this block at some point during your implementation of this method. Specify an option indicating how you want the system to alert the user, if at all. 
 */
- (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler;

///---------------------------------------------------------------------------------------
/// @name ￼Actions
///---------------------------------------------------------------------------------------

/*! Register custom categories in the Push Notifications system. This method should be called before [Bit6 startWithApiKey:].
 @param notificationCategories array of categories to register.
 @note These identifiers cannot be used in custom categories/actions: com.bit6.actionDecline, com.bit6.actionAnswer, com.bit6.msgReply, com.bit6.incomingCall, reply.
 */
- (void)setNotificationCategories:(NSArray<UNNotificationCategory*>*)notificationCategories NS_AVAILABLE_IOS(10_0);

/*! Register custom categories in the Push Notifications system. This method should be called before [Bit6 startWithApiKey:].
 @param categories array of categories to register.
 @note These identifiers cannot be used in custom categories/actions: com.bit6.actionDecline, com.bit6.actionAnswer, com.bit6.msgReply, com.bit6.incomingCall, reply.
 */
- (void)setCategories:(NSArray<UIUserNotificationCategory*>*)categories;

/*! Should be called inside the -[UIApplicationDelegate application:handleActionWithIdentifier:forRemoteNotification:completionHandler:] and -[UIApplicationDelegate application:handleActionWithIdentifier:forLocalNotification:completionHandler:] implementations.
 @param identifier The identifier associated with the custom action.
 @param userInfo A dictionary that contains information related to the remote notification. This dictionary originates from the provider as a JSON-defined dictionary, which iOS converts to an NSDictionary object before calling this method. The contents of the dictionary are the push notification payload, which consists only of property-list objects plus NSNull.
 @param completionHandler The block to execute when you are finished performing the specified action. You must call this block at the end of your method.
 */
- (void)handleActionWithIdentifier:(nullable NSString *)identifier forNotificationUserInfo:(NSDictionary *)userInfo completionHandler:(void(^)())completionHandler;

/*! Should be called inside the -[UIApplicationDelegate application:handleActionWithIdentifier:forRemoteNotification:withResponseInfo:completionHandler:] and -[UIApplicationDelegate application:handleActionWithIdentifier:forLocalNotification:withResponseInfo:completionHandler:] implementation.
 @param identifier The identifier associated with the custom action.
 @param userInfo A dictionary that contains information related to the remote notification. This dictionary originates from the provider as a JSON-defined dictionary, which iOS converts to an NSDictionary object before calling this method. The contents of the dictionary are the push notification payload, which consists only of property-list objects plus NSNull.
 @param responseInfo The data dictionary sent by the action.
 @param completionHandler The block to execute when you are finished performing the specified action. You must call this block at the end of your method.
 */
- (void)handleActionWithIdentifier:(nullable NSString *)identifier forNotificationUserInfo:(NSDictionary *)userInfo withResponseInfo:(NSDictionary *)responseInfo completionHandler:(void(^)())completionHandler NS_AVAILABLE_IOS(9_0);

///---------------------------------------------------------------------------------------
/// @name ￼Registration
///---------------------------------------------------------------------------------------

/*! Should be called inside the -[UIApplicationDelegate application:didRegisterForRemoteNotificationsWithDeviceToken:] implementation.
 @param deviceToken A token that identifies the device to APS. The token is an opaque data type because that is the form that the provider needs to submit to the APS servers when it sends a notification to a device. The APS servers require a binary format for performance reasons.
 The size of a device token is 32 bytes.
 Note that the device token is different from the uniqueIdentifier property of UIDevice because, for security and privacy reasons, it must change when the device is wiped.
 */
- (void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

/*! Should be called inside the -[UIApplicationDelegate application:didFailToRegisterForRemoteNotificationsWithError:] implementation.
 @param error An NSError object that encapsulates information why registration did not succeed. The app can choose to display this information to the user.
 */
- (void)didFailToRegisterForRemoteNotificationsWithError:(NSError*)error;

///---------------------------------------------------------------------------------------
/// @name ￼Helpers
///---------------------------------------------------------------------------------------

/*! Used to know if a push notification refers to an incoming call
 @param userInfo A dictionary that contains information related to the remote notification.
 @return true if the push notification refers to an incoming call.
 */
+ (BOOL)isIncomingCallNotification:(NSDictionary*)userInfo;

/*! Used to know if a push notification refers to a missed incoming call.
 @param userInfo A dictionary that contains information related to the remote notification.
 @return true if the push notification refers to a missed incoming call.
 */
+ (BOOL)isMissedCallNotification:(NSDictionary*)userInfo;

/*! Used to know if a push notification refers to an incoming message.
 @param userInfo A dictionary that contains information related to the remote notification.
 @return true if the push notification refers to an incoming message.
 */
+ (BOOL)isIncomingMessageNotification:(NSDictionary*)userInfo;

/*! Gets the origin identity for the incoming message notification userInfo param.
 @param userInfo A dictionary that contains information related to the remote notification.
 @return the origin identity for the incoming message.
 */
+ (nullable Bit6Address*)addressForMessageNotification:(NSDictionary*)userInfo;

///---------------------------------------------------------------------------------------
/// @name ￼VoIP Push Notifications
///---------------------------------------------------------------------------------------

/*! This method is invoked when new credentials (including push token) have been received for the specified PKPushType.
 @param registry The PKPushRegistry instance responsible for the delegate callback.
 @param credentials The push credentials that can be used to send pushes to the device for the specified PKPushType.
 @param type This is a PKPushType NSString constant which is present in [registry desiredPushTypes].
 */
- (void)pushRegistry:(PKPushRegistry *)registry didUpdatePushCredentials:(PKPushCredentials *)credentials forType:(PKPushType)type;

/*! This method is invoked when a push notification has been received for the specified PKPushType.
 @param registry The PKPushRegistry instance responsible for the delegate callback.
 @param payload The push payload sent by a developer via APNS server API.
 @param type This is a PKPushType NSString constant which is present in [registry desiredPushTypes].
 */
- (void)pushRegistry:(PKPushRegistry *)registry didReceiveIncomingPushWithPayload:(PKPushPayload *)payload forType:(PKPushType)type;

@end

NS_ASSUME_NONNULL_END
