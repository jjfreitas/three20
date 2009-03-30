#import "Three20/TTTableViewCell.h"

@class TTTableField, TTStyleView, TTErrorView, TTActivityLabel, TTHTMLView;

@interface TTTableFieldCell : TTTableViewCell {
  TTTableField* _field;
  UILabel* _label;
}
@end

@interface TTTextTableFieldCell : TTTableFieldCell
@end

@interface TTTitledTableFieldCell : TTTableFieldCell {
  UILabel* _titleLabel;
}
@end

@interface TTSubtextTableFieldCell : TTTableFieldCell {
  UILabel* _subtextLabel;
}
@end

@interface TTMoreButtonTableFieldCell : TTTableFieldCell {
  UIActivityIndicatorView* _spinnerView;
  UILabel* _subtitleLabel;
  BOOL _animating;
}

@property(nonatomic) BOOL animating;

@end

@interface TTIconTableFieldCell : TTTableFieldCell {
  TTStyleView* _iconView;
}
@end

@interface TTImageTableFieldCell : TTIconTableFieldCell

@end

@interface TTActivityTableFieldCell : TTTableFieldCell {
  TTActivityLabel* _activityLabel;
}

@end

@interface TTErrorTableFieldCell : TTTableViewCell {
  TTTableField* _field;
  TTErrorView* _errorView;
}
@end

@interface TTTextFieldTableFieldCell : TTTableFieldCell <UITextFieldDelegate>  {
  UITextField* _textField;
}

@property(nonatomic,readonly) UITextField* textField;

@end

@interface TTTextViewTableFieldCell : TTTableViewCell <UITextViewDelegate> {
  TTTableField* _field;
  UITextView* _textView;
}

@property(nonatomic,readonly) UITextView* textView;

@end

@interface TTSwitchTableFieldCell : TTTableFieldCell {
  UISwitch* _switch;
}

@end

@interface TTHTMLTableFieldCell : TTTableFieldCell {
  TTHTMLView* _htmlView;
}

@end
