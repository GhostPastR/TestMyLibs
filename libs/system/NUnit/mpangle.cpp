#include "mpangle.h"

MpAngle::MpAngle( const nreal &value, bool radian )
{
    if( radian )
        this->setR( value );
    else
        this->setD( value );
}

MpAngle::MpAngle( const MpAngle &angle )
{
    this->a_ = angle.a_;
}

MpAngle::MpAngle( MpAngle &&angle )
{
    this->a_ = std::move( angle.a_ );
}

MpAngle::~MpAngle()
{

}

MpAngle &MpAngle::operator=( const MpAngle &angle )
{
    this->a_ = angle.a_;
    return *this;
}

MpAngle &MpAngle::operator=( MpAngle &&angle )
{
    this->a_ = std::move( angle.a_ );
    return *this;
}

nreal MpAngle::grade( const nreal &value )
{
    return value / MpAngle::piOn180().r();
}

nreal MpAngle::radian( const nreal &value )
{
    return value * MpAngle::piOn180().r();
}

nreal MpAngle::gradeMod( const nreal &value )
{
    return ( value / MpAngle::piOn180().r() ).ceil() % nreal( 360 );
}

MpAngle &MpAngle::operator=( const nreal &value )
{
    this->a_ = value;
    return *this;
}

bool MpAngle::operator>=( const MpAngle &value ) const
{
    return this->a_.moreThan( value.a_ );
}

bool MpAngle::operator<=( const MpAngle &value ) const
{
    return this->a_.feverThan( value.a_ );
}
