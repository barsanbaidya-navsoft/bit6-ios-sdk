//
//  BXUFileDownloader.h
//  Bit6UI
//
//  Created by Carlos Thurber on 12/28/15.
//  Copyright © 2015 Bit6. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*! Bit6FileDownloader handles the downloads of the framework using NSOperationQueue and NSURLSessionDownloadTask. */
@interface Bit6FileDownloader : NSObject

/*! Cancels all pending download operations. */
+ (void)cancelOperations;

/*! Download a file. It can be set to replace any file in the indicated path if necessary. When running from an extension, a copy of the file will be saved in the SDK group container.
 @param url remote URL address of the file to download.
 @param filePath local path where to save the file.
 @param replace the file will be downloaded and will replace the file in cache.
 @param preparationBlock block to process the downloaded data before saving it to the filePath.
 @param priority the execution priority of the operation in the operation queue.
 @param completionHandler Block to call after the operation has been completed. The "error" value can be use to know if the file was downloaded and saved in cache.
 @see +[Bit6 setAppGroupIdentifier:].
 */
+ (void)downloadFileAtURL:(NSURL*)url toFilePath:(NSString*)filePath canReplace:(BOOL)replace preparationBlock:(nullable NSData* (^)(NSData* data))preparationBlock priority:(NSOperationQueuePriority)priority completionHandler:(nullable void(^)(NSURL * _Nullable location, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/*! Query is a URL is being downloaded.
 @param url remote URL address of the file.
 @return true if the specified URL is being downloaded.
 */
+ (BOOL)isDownloadingFileAtURL:(NSURL*)url;

/*! Get the full path for a file in the ~/Cache/bit6 directory.
 @param fileName name of the file.
 @return full path for a file in the Bit6 cache directory.
 */
+ (NSString*)pathForFileName:(NSString*)fileName;

@end

NS_ASSUME_NONNULL_END
