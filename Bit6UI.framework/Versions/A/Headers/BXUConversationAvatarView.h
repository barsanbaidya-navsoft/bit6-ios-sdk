//
//  BXUConversationAvatarView.h
//  Bit6UI
//
//  Created by Carlos Thurber on 12/26/15.
//  Copyright © 2015 Bit6. All rights reserved.
//

#import <UIKit/UIKit.h>

extern NSString* const _Nonnull BXURefreshGroupAvatarsNotification;

/*! Convenience subclass of UIView to show a profile picture for an identity. In case of a group identity this view will show two profiles pictures if an image is not provided for the group using <BXUContactSource>. 
 @see <BXUContactAvatarImageView>
 */
@interface BXUConversationAvatarView : UIView

/*! Identity of the contact for this avatar. */
@property (nonnull, strong, nonatomic) Bit6Address *address;

@end
