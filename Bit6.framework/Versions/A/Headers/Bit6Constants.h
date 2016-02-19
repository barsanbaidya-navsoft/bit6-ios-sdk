//
//  Bit6Constants.h
//  Bit6
//
//  Created by Carlos Thurber Boaventura on 03/31/14.
//  Copyright (c) 2014 Bit6. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^Bit6CompletionHandler) (NSDictionary<id,id>* _Nullable response, NSError* _Nullable error);
typedef void (^Bit6ActionNotificationCompletionHandler) (void);

extern NSString* _Nonnull const Bit6LoginCompletedNotification;
extern NSString* _Nonnull const Bit6LogoutCompletedNotification;

extern NSString* _Nonnull const Bit6RTConnectionStatusChangedNotification;
extern NSString* _Nonnull const Bit6CustomRtNotification;
extern NSString* _Nonnull const Bit6PresenceRtNotification;

extern NSString* _Nonnull const Bit6IncomingCallNotification;
extern NSString* _Nonnull const Bit6IncomingCallKey;
extern NSString* _Nonnull const Bit6TappedIncomingMessageNotification;

extern NSString* _Nonnull const Bit6AudioPlayingNotification;

extern NSString* _Nonnull const Bit6MessagesChangedNotification;
extern NSString* _Nonnull const Bit6ConversationsChangedNotification;
extern NSString* _Nonnull const Bit6GroupsChangedNotification;
extern NSString* _Nonnull const Bit6ObjectKey;
extern NSString* _Nonnull const Bit6ChangeKey;
extern NSString* _Nonnull const Bit6AddedKey;
extern NSString* _Nonnull const Bit6UpdatedKey;
extern NSString* _Nonnull const Bit6DeletedKey;

extern NSString* _Nonnull const Bit6TypingDidBeginRtNotification;
extern NSString* _Nonnull const Bit6TypingDidEndRtNotification;

extern NSString* _Nonnull const Bit6TransferUpdateNotification;
extern NSString* _Nonnull const Bit6ProgressKey;
extern NSString* _Nonnull const Bit6TransferStartedKey;
extern NSString* _Nonnull const Bit6TransferProgressKey;
extern NSString* _Nonnull const Bit6TransferEndedKey;
extern NSString* _Nonnull const Bit6TransferEndedWithErrorKey;

/*! Bit6 error constants */
typedef NS_ENUM(NSInteger, Bit6Error) {
    /*! The recipient was not found. */
    Bit6Error_RecipientNotFound=500,
    /*! Internet connection not found. */
    Bit6Error_NotConnectedToInternet = NSURLErrorNotConnectedToInternet,
    /*! Restricted access to the Microphone. */
    Bit6Error_MicNotAllowed=-6001,
    /*! Restricted access to the Camera. */
    Bit6Error_CameraNotAllowed=-6002,
    /*! Restricted access to Location. */
    Bit6Error_LocationNotAllowed=-6003,
    /*! Session hasn't being initiated. */
    Bit6Error_SessionNotInitiated=-6011,
    /*! Invalid Address. */
    Bit6Error_InvalidAddress=-6012,
    /*! Insuficient Parameters. */
    Bit6Error_InsuficientParameters=-6013,
    /*! Invalid Session Provider. */
    Bit6Error_InvalidSessionProvider=-6014,
    /*! Attachment wasn't saved to cache. */
    Bit6Error_SaveToCacheFailed=-6021,
    /*! Attachment doesn't exist in cache. */
    Bit6Error_FileDoesNotExists=-6022,
    /*! Attachment doesn't exist in cache, but it is being downloaded. */
    Bit6Error_FileDoesNotExistsWillDownload=-6023,
    /*! Attachment doesn't exist in the server, probably because an error during the upload process. */
    Bit6Error_FileDoesNotExistsOnServer=-6024,
    /*! Can't delete a message with status Sending. */
    Bit6Error_UnableToDeleteSendingMessage=-631,
    /*! Couldn't make changes to the group. */
    Bit6Error_UnableToUpdateGroup=-632,
    /*! The group wasn't found in the server. Probably because of not enough permissions to see it. */
    Bit6Error_GroupNotAccessible=-633,
    /*! An HTTP status = 5xx occur when interacting with the server. */
    Bit6Error_HTTPServerError=-6031,
    /*! An HTTP status = 4xx occur when interacting with the server. */
    Bit6Error_HTTPClientError=-6032,
    /*! Failed to Start the call. */
    Bit6Error_FailedToStartTheCallError=-6041,
    /*! Can't answer the call because another call is in progress. */
    Bit6Error_CallInProgressError=-6042,
    /*! An HTTP status = 4xx occur when interacting with the server. */
    Bit6Error_InvalidRESTAPICall=-6051,
    
    /*! The <Bit6Transfer> failed because the data channel wasn't open. */
    Bit6Error_TransferDataChannelNotOpenError=-10001,
    
    /*! The <Bit6Transfer> failed because of an unknown error. */
    Bit6Error_TransferDataChannelUnknownError=-10002,
    
    /*! The <Bit6Transfer> failed because of an buffer overflow error. */
    Bit6Error_TransferDataChannelBufferOverflowError=-10003
};

/*! Web Socket connection status. */
typedef NS_ENUM(NSInteger, Bit6RTStatus) {
    /*! Web Socket is disconnected. */
    Bit6RTStatus_DISCONNECTED = 0,
    /*! Web Socket is tring to connect. */
    Bit6RTStatus_CONNECTING,
    /*! Web Socket is connected. */
    Bit6RTStatus_CONNECTED
};