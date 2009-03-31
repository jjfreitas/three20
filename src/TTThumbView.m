#import "Three20/TTThumbView.h"
#import "Three20/TTImageView.h"
#import "Three20/TTStyledView.h"

@implementation TTThumbView

- (id)initWithFrame:(CGRect)frame {
	if (self = [super initWithFrame:frame]) {
    imageView = [[TTImageView alloc] initWithFrame:CGRectZero];
    imageView.opaque = YES;
    imageView.contentMode = UIViewContentModeScaleAspectFill;
    imageView.clipsToBounds = YES;
    imageView.userInteractionEnabled = NO;
    [self addSubview:imageView];

    borderView = [[TTStyledView alloc] initWithFrame:CGRectZero];
    borderView.opaque = NO;
    borderView.style = TTStyleFill;
    borderView.borderColor = [UIColor colorWithRed:0 green:0 blue:0 alpha:0.4];
    borderView.contentMode = UIViewContentModeRedraw;
    borderView.userInteractionEnabled = NO;
    [self addSubview:borderView];

    self.opaque = YES;
    self.backgroundColor = [UIColor colorWithWhite:0.95 alpha:1];
    self.clipsToBounds = YES;
	}
	return self;
}

- (void)dealloc {
  [imageView release];
  [borderView release];
	[super dealloc];
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// UIView

- (void)layoutSubviews {
  [super layoutSubviews];

  imageView.frame = self.bounds;
  borderView.frame = self.bounds;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

- (NSString*)thumbURL {
  return imageView.url;
}

- (void)setThumbURL:(NSString*)url {
  imageView.image = nil;
  imageView.url = url;
}

- (void)suspendLoading:(BOOL)suspended {
  if (suspended) {
    [imageView stopLoading];
  } else if (!imageView.image) {
    [imageView reload];
  }
}

@end
