#include "ndouble.h"
#include <limits>

const NDouble NDouble::nan( std::numeric_limits<double>::quiet_NaN() );
const NDouble NDouble::nInfinity( -std::numeric_limits<double>::infinity() );
const NDouble NDouble::pInfinity( std::numeric_limits<double>::infinity() );
const NDouble NDouble::minValue( std::numeric_limits<double>::lowest() );
const NDouble NDouble::maxValue( std::numeric_limits<double>::max() );
const NDouble NDouble::epsilon( std::numeric_limits<double>::min() );
