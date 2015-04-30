//
//  Bit6Transfer.h
//  Bit6
//
//  Created by Carlos Thurber on 04/07/15.
//  Copyright (c) 2015 Bit6. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*! Type of <Bit6Transfer>. */
typedef NS_ENUM(NSInteger, Bit6TransferType) {
    /*! Incoming transfer. */
    Bit6TransferType_INCOMING,
    /*! Outoing transfer. */
    Bit6TransferType_OUTGOING
};

/*! States for a <Bit6Transfer>. */
typedef NS_ENUM(NSInteger, Bit6TransferState) {
    /*! The transfer is new. */
    Bit6TransferState_NEW,
    /*! The transfer has started. */
    Bit6TransferState_STARTED,
    /*! The transfer ended successfully. */
    Bit6TransferState_ENDED,
    /*! The transfer ended with an error. */
    Bit6TransferState_ENDED_WITH_ERROR
};

/*! A Bit6Transfer object represents a peer to peer data transfer. */
@interface Bit6Transfer : NSObject

/*! Initializes an outgoing Bit6Transfer object.
 @param data data to send.
 @param name name of the file. If nil a random name is given.
 @param mimeType MIME type of the file to send.
 @return a Bit6Transfer object representing an outgoing transfer.
 */
- (instancetype)initOutgoingTransferWithData:(NSData*)data name:(NSString*)name mimeType:(NSString*)mimeType;

/*! Sender state as a value of the <Bit6TransferState> enumeration. */
@property (nonatomic, readonly) Bit6TransferState state;

/*! Sender type as a value of the <Bit6TransferType> enumeration. */
@property (nonatomic, readonly) Bit6TransferType type;

/*! For <Bit6TransferType_OUTGOING> transfers this is the data to be sent. For <Bit6TransferType_INCOMING> transfers this is the data received at the moment. */
@property (nonatomic, readonly) NSData *data;

/*! File name. */
@property (nonatomic, readonly) NSString *name;

/*! MIME type of the file. */
@property (nonatomic, readonly) NSString *mimeType;

/*! Size of an outgoing file or final size of an incoming file. */
@property (nonatomic, readonly) NSUInteger size;

/*! Amount of data sent. Only for <Bit6TransferType_OUTGOING>. */
@property (nonatomic, readonly) NSUInteger offset;

/*! Transfer progress as a value between 0 and 1. */
@property (nonatomic, readonly) CGFloat progress;

/*! Transfer error. It's nil if state != Bit6TransferState_ENDED_WITH_ERROR. */
@property (nonatomic, readonly) NSError *error;

@end
