#include "nangle.h"

NAngle::NAngle( const nreal &value, bool radian )
{
    if( radian )
        this->setR( value );
    else
        this->setD( value );
}

NAngle::NAngle( const NAngle &angle )
{
    this->a_ = angle.a_;
}

NAngle::NAngle( NAngle &&angle )
{
    this->a_ = std::move( angle.a_ );
}

NAngle::~NAngle()
{

}

NAngle &NAngle::operator=( const NAngle &angle )
{
    this->a_ = angle.a_;
    return *this;
}

NAngle &NAngle::operator=( NAngle &&angle )
{
    this->a_ = std::move( angle.a_ );
    return *this;
}

nreal NAngle::grade( const nreal &value )
{
    return value / NAngle::piOn180().r();
}

nreal NAngle::radian( const nreal &value )
{
    return value * NAngle::piOn180().r();
}

nreal NAngle::gradeMod( const nreal &value )
{
    return ( value / NAngle::piOn180().r() ).ceil() % nreal( 360 );
}

NAngle &NAngle::operator=( const nreal &value )
{
    this->a_ = value;
    return *this;
}

bool NAngle::operator>=( const NAngle &value ) const
{
    return this->a_.moreThan( value.a_ );
}

bool NAngle::operator<=( const NAngle &value ) const
{
    return this->a_.feverThan( value.a_ );
}
