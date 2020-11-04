#include "activity.h"

// Default less operator - sorts by start time first.
bool Activity::operator<(const Activity &a) const {
	return (start < a.start || (start == a.start && finish < a.finish));
}

// Default equal operator.
bool Activity::operator==(const Activity &a) const {
	return (start == a.start && finish == a.finish);
}
