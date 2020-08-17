#include "npoint.h"
#include <qdebug.h>

NPoint::NPoint( const NPoint &point )
{
    this->x_ = point.x_;
    this->y_ = point.y_;
}

NPoint::NPoint( NPoint &&point )
{
    this->x_ = std::move( point.x_ );
    this->y_ = std::move( point.y_ );
}

NPoint::~NPoint()
{

}

NAngle NPoint::angleToPoint( const NPoint &point ) const
{
    return NPoint::angle( *this, point );
}

NAngle NPoint::angleFromPoint( const NPoint &point ) const
{
    return NPoint::angle( point, *this );
}

nreal NPoint::distance( const NPoint &point ) const
{
    auto _d = ( point.x_ - this->x_ ) * ( point.x_ - this->x_ )
            + ( point.y_ - this->y_ ) * ( point.y_ - this->y_ );
    return nreal( sqrt( _d.toType() ) );
}

NPoint NPoint::point( const NAngle &omnibearing, const nreal &range ) const
{
    return NPoint( this->x_ + range * omnibearing.sin(),
                    this->y_ + range * omnibearing.cos() );
}

NPoint NPoint::transormation( const NAngle &angle,
                                const NPoint &start ) const
{
    return NPoint::transormation( *this, angle, start );
}

void NPoint::setCoordinate( const NAngle &omnibearing, const nreal &range )
{
    this->x_ = range * omnibearing.sin();
    this->y_ = range * omnibearing.cos();
}

bool NPoint::compare( const NPoint &point ) const
{
    return ( this->x_.compare( point.x_ ) && this->y_.compare( point.y_ ) );
}

NPoint NPoint::midplane( const NPoint &point ) const
{
    return NPoint( ( this->x_ + point.x_ ) / 2.0,
                    ( this->y_ + point.y_ ) / 2.0 );
}

bool NPoint::isInfinity() const
{
    return ( this->x_.isInfinity() || this->y_.isInfinity() );
}

bool NPoint::isValid() const
{
    return ( !this->x_.isNaN() && !this->y_.isNaN() );
}

NAngle NPoint::angle( const NPoint &start, const NPoint &stop )
{
    NAngle _angle( nreal( atan2( ( stop.x_ - start.x_ ).toType(),
                                    ( stop.y_ - start.y_ ).toType() ) ) );
    if( _angle < NAngle() )
        return ( _angle += NAngle::piIn2().r() );
    return _angle;
}

NPoint NPoint::transormation( const NPoint &point, const NAngle &angle,
                                const NPoint &start )
{
    nreal dx = point.x_ - start.x_;
    nreal dy = point.y_ - start.y_;
    nreal sinAngle = -angle.sin();
    nreal cosAngle = angle.cos();
    nreal x = dx * cosAngle - dy * sinAngle;
    nreal y = dx * sinAngle + dy * cosAngle;
    return NPoint( x + start.x_, y + start.y_ );
}

NPoint NPoint::newPoint( const NAngle &omnibearing, const nreal &range,
                           const NPoint &point )
{
    return NPoint(  point.x() + range * omnibearing.sin(),
                     point.y() + range * omnibearing.cos() );
}

NPoint &NPoint::operator=( const NPoint &point )
{
    this->x_ = point.x_;
    this->y_ = point.y_;
    return *this;
}

NPoint &NPoint::operator=( NPoint &&point )
{
    this->x_ = std::move( point.x_ );
    this->y_ = std::move( point.y_ );
    return *this;
}

bool NPoint::operator ==( const NPoint &point )
{
    return point.x().compare( this->x() )
            && point.y().compare( this->y() )
            && point.y().compare( this->y() );
}
