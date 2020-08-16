#include "nint64.h"
#include <limits>

const NInt64 NInt64::minValue( std::numeric_limits<int64_t>::min() );
const NInt64 NInt64::maxValue( std::numeric_limits<int64_t>::max() );
