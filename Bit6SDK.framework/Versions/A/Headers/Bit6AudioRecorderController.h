//
//  AVRecorderController.h
//  Bit6
//
//  Created by Carlos Thurber Boaventura on 12/13/13.
//  Copyright (c) 2014 Bit6. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Bit6OutgoingMessage.h"

@protocol Bit6AudioRecorderControllerDelegate;

/*! Bit6AudioRecorderController is used to record an audio file and attach it to a message. */
@interface Bit6AudioRecorderController : NSObject

/*! Tries to start to record an audio file showing an <UIAlertView> object as the UI control to cancel or finish the recording.
 @param msg a <Bit6OutgoingMessage> object where the audio file will be included.
 @param maxDuration maximum allowed duration (in seconds) of the audio file to be recorded.
 @param delegate the delegate to be notified when the recording has been completed or canceled. For details about the methods that can be implemented by the delegate, see <Bit6AudioRecorderControllerDelegate> Protocol Reference.
 @param defaultPrompt if YES then a default UIAlertView will be shown to handle the recording. If NO then you need to provide a custom UI to handle the recording.
 @param errorHandler block to call if an error occurs
 */
- (void) startRecordingAudioForMessage:(Bit6OutgoingMessage*)msg maxDuration:(NSTimeInterval)maxDuration delegate:(id <Bit6AudioRecorderControllerDelegate>)delegate defaultPrompt:(BOOL)defaultPrompt errorHandler:(void (^)(NSError *error))errorHandler;

/*! Gets the length of the current recording. */
@property (nonatomic, readonly) double duration;

/*! Cancel a recording without saving the audio file. */
- (void) cancelRecording;

/*! Finish the recording and saves the audio file to cache. */
- (void) stopRecording;

/*! Used to know if there's a recording in process. */
@property (nonatomic, readonly) BOOL isRecording;

@end

/*! The Bit6AudioRecorderControllerDelegate protocol defines the methods a delegate of a <Bit6AudioRecorderController> object should implement. The methods of this protocol notify the delegate when the recording was either completed or canceled by the user.
 */
@protocol Bit6AudioRecorderControllerDelegate <NSObject>

/*! Called when a user has completed the recording prccess.
 @param b6rc The controller object recording the audio file.
 @param message Message object set in <[Bit6AudioRecorderController startRecordingAudioForMessage:maxDuration:delegate:defaultPrompt:errorHandler:]> with the audio file set.
 */
- (void) doneRecorderController:(Bit6AudioRecorderController*)b6rc message:(Bit6OutgoingMessage*)message;

@optional
/*! Called when a user has cancelled the recording process.
 @param b6rc The controller object recording the audio file.
 */
- (void) cancelRecorderController:(Bit6AudioRecorderController*)b6rc;

@end