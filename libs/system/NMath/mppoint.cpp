#include "mppoint.h"
#include <qdebug.h>

MpPoint::MpPoint( const MpPoint &point )
{
    this->x_ = point.x_;
    this->y_ = point.y_;
}

MpPoint::MpPoint( MpPoint &&point )
{
    this->x_ = std::move( point.x_ );
    this->y_ = std::move( point.y_ );
}

MpPoint::~MpPoint()
{

}

MpAngle MpPoint::angleToPoint( const MpPoint &point ) const
{
    return MpPoint::angle( *this, point );
}

MpAngle MpPoint::angleFromPoint( const MpPoint &point ) const
{
    return MpPoint::angle( point, *this );
}

nreal MpPoint::distance( const MpPoint &point ) const
{
    auto _d = ( point.x_ - this->x_ ) * ( point.x_ - this->x_ )
            + ( point.y_ - this->y_ ) * ( point.y_ - this->y_ );
    return nreal( sqrt( _d.toType() ) );
}

MpPoint MpPoint::point( const MpAngle &omnibearing, const nreal &range ) const
{
    return MpPoint( this->x_ + range * omnibearing.sin(),
                    this->y_ + range * omnibearing.cos() );
}

MpPoint MpPoint::transormation( const MpAngle &angle,
                                const MpPoint &start ) const
{
    return MpPoint::transormation( *this, angle, start );
}

void MpPoint::setCoordinate( const MpAngle &omnibearing, const nreal &range )
{
    this->x_ = range * omnibearing.sin();
    this->y_ = range * omnibearing.cos();
}

bool MpPoint::compare( const MpPoint &point ) const
{
    return ( this->x_.compare( point.x_ ) && this->y_.compare( point.y_ ) );
}

MpPoint MpPoint::midplane( const MpPoint &point ) const
{
    return MpPoint( ( this->x_ + point.x_ ) / 2.0,
                    ( this->y_ + point.y_ ) / 2.0 );
}

bool MpPoint::isInfinity() const
{
    return ( this->x_.isInfinity() || this->y_.isInfinity() );
}

bool MpPoint::isValid() const
{
    return ( !this->x_.isNaN() && !this->y_.isNaN() );
}

MpAngle MpPoint::angle( const MpPoint &start, const MpPoint &stop )
{
    MpAngle _angle( nreal( atan2( ( stop.x_ - start.x_ ).toType(),
                                    ( stop.y_ - start.y_ ).toType() ) ) );
    if( _angle < MpAngle() )
        return ( _angle += MpAngle::piIn2().r() );
    return _angle;
}

MpPoint MpPoint::transormation( const MpPoint &point, const MpAngle &angle,
                                const MpPoint &start )
{
    nreal dx = point.x_ - start.x_;
    nreal dy = point.y_ - start.y_;
    nreal sinAngle = -angle.sin();
    nreal cosAngle = angle.cos();
    nreal x = dx * cosAngle - dy * sinAngle;
    nreal y = dx * sinAngle + dy * cosAngle;
    return MpPoint( x + start.x_, y + start.y_ );
}

MpPoint MpPoint::newPoint( const MpAngle &omnibearing, const nreal &range,
                           const MpPoint &point )
{
    return MpPoint(  point.x() + range * omnibearing.sin(),
                     point.y() + range * omnibearing.cos() );
}

MpPoint &MpPoint::operator=( const MpPoint &point )
{
    this->x_ = point.x_;
    this->y_ = point.y_;
    return *this;
}

MpPoint &MpPoint::operator=( MpPoint &&point )
{
    this->x_ = std::move( point.x_ );
    this->y_ = std::move( point.y_ );
    return *this;
}

bool MpPoint::operator ==( const MpPoint &point )
{
    return point.x().compare( this->x() )
            && point.y().compare( this->y() )
            && point.y().compare( this->y() );
}
