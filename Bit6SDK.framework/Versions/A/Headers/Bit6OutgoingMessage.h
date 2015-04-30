//
//  Bit6OutgoingMessage.h
//  Bit6
//
//  Created by Carlos Thurber Boaventura on 03/23/14.
//  Copyright (c) 2014 Bit6. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>
#import "Bit6Message.h"
#import "Bit6Address.h"
#import "Bit6Constants.h"

/*! A Bit6OutgoingMessage object represents a message that will be sent by the user.
 
 How to create and send an outgoing message:

    Bit6OutgoingMessage *message = [[Bit6OutgoingMessage alloc] init];
    message.content = @"This is a text message";
    message.destination = [Bit6Address addressWithKind:Bit6AddressKind_USERNAME value:@"user2"];
    [message sendWithCompletionHandler:^(NSDictionary *response, NSError *error) {
        if (!error) {
            NSLog(@"Message Sent");
        }
        else {
            NSLog(@"Message Failed with Error: %@",error.localizedDescription);
        }
    }];
 
 */
@interface Bit6OutgoingMessage : Bit6Message

/*! Text content of the message. */
@property (nonatomic, copy) NSString *content;

/*! The <Bit6Address> object to reference the message's destination. */
@property (nonatomic, strong) Bit6Address *destination;

/*! Image to send as an attachment. */
@property (nonatomic, strong) UIImage *image;

/*! URL path to the video to be sent as an attachment.
 @note It supports the following URL paths: file:// and assets-library://
 */
@property (nonatomic, strong) NSURL *videoURL;

/*! Specifies the beginning of the time range, in seconds, to be sent from the video. */
@property (nonatomic, strong) NSNumber *videoCropStart;

/*! Specifies the end of the time range, in seconds, to be sent from the video. */
@property (nonatomic, strong) NSNumber *videoCropEnd;

/*! Location to send with the message
 */
@property (nonatomic, strong) CLLocation *location;

/*! Sends the message.
 @param completion block to be called when the operation is completed.
 */
- (void)sendWithCompletionHandler:(Bit6CompletionHandler)completion;

/*! Creates a copy of a sent message. This copy has a different identifier and it's ready to be forwarded.
 @param msg message to be copied
 @return copy of the message
 */
+ (Bit6OutgoingMessage*) outgoingCopyOfMessage:(Bit6Message*)msg;

@end
