#include "nspeed.h"
#include <ndistance.h>
#include <ntime.h>

NSpeed NSpeed::speed( const NDistance &distance, const NTime &time ) noexcept
{
    return NSpeed( distance.m() / time.sec().toDouble() );
}

NSpeed &NSpeed::setSpeed( const NDistance &distance, const NTime &time )
                                                                        noexcept
{
    *this = NSpeed::speed( distance, time );
    return *this;
}
