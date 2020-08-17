#include "ndistance.h"

#include <ntime.h>
#include <nspeed.h>

NDistance NDistance::distance( const NSpeed &speed, const NTime &time )
                                                                        noexcept
{
    return NDistance( speed.ms() * time.sec().toDouble() );
}

NDistance &NDistance::setDistance( const NSpeed &speed, const NTime &time )
                                                                        noexcept
{
    *this = NDistance::distance( speed, time );
    return *this;
}
