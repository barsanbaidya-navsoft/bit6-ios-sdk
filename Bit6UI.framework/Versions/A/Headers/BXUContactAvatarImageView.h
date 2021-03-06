//
//  BXUInternalContactAvatarView.h
//  Bit6UI
//
//  Created by Carlos Thurber on 03/10/16.
//  Copyright © 2016 Bit6. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString* const BXURefreshAvatarsNotification;
typedef NSData* _Nonnull (^BXUContactAvatarPreparationBlock) (NSString* uri, NSURL* originURL, NSData* imageData);

/*! Convenience subclass of UIImageView to show a profile picture for a contact. This class work together with <BXUContactSource> to know the NSURL of the image to download.
 @see <BXUContactSource>
 */
@interface BXUContactAvatarImageView : UIImageView

/*! Identity of the contact for this avatar. */
@property (strong, nonatomic) Bit6Address *address;

/*! Sets a block to perform after the avatar has been downloaded and before it is saved to cache. This allows to make some operations to the avatar image.
 @param preparationBlock block to execute before the avatar is saved to cache.
 */
+ (void)setImagePreparationBlock:(nullable BXUContactAvatarPreparationBlock)preparationBlock;

/*! Gets the block to perform after the avatar has been downloaded and before it is saved to cache.
 @return preparationBlock block to execute before the avatar is saved to cache.
 */
+ (nullable BXUContactAvatarPreparationBlock)preparationBlock;

@end

NS_ASSUME_NONNULL_END