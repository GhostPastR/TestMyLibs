#include "mpdistance.h"

#include <mptime.h>
#include <mpspeed.h>

MpDistance MpDistance::distance( const MpSpeed &speed, const MpTime &time )
                                                                        noexcept
{
    return MpDistance( speed.ms() * time.sec().toDouble() );
}

MpDistance &MpDistance::setDistance( const MpSpeed &speed, const MpTime &time )
                                                                        noexcept
{
    *this = MpDistance::distance( speed, time );
    return *this;
}
