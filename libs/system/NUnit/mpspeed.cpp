#include "mpspeed.h"
#include <mpdistance.h>
#include <mptime.h>

MpSpeed MpSpeed::speed( const MpDistance &distance, const MpTime &time )
                                                                        noexcept
{
    return MpSpeed( distance.m() / time.sec().toDouble() );
}

MpSpeed &MpSpeed::setSpeed( const MpDistance &distance, const MpTime &time )
                                                                        noexcept
{
    *this = MpSpeed::speed( distance, time );
    return *this;
}
