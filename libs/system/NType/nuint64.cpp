#include "nuint64.h"
#include <limits>

const NUInt64 NUInt64::minValue( std::numeric_limits<uint64_t>::min() );
const NUInt64 NUInt64::maxValue( std::numeric_limits<uint64_t>::max() );
