#include "narc.h"

NArc::NArc( const NPoint &center, const nreal &radius,
              const NPoint &start, const NPoint &stop, NDirect direct )
{
    this->center_ = center;
    this->setRadius( radius );
    this->setDirect( direct );
    this->setStart( start );
    this->setStop( stop );
}

NArc::NArc( const NArc &arc ) : INArc(arc)
{

}

NArc::NArc( NArc &&arc ) : INArc(std::move(arc))
{

}

NArc::~NArc()
{

}

NPoint NArc::start() const
{
    return NPoint::newPoint( this->angleStart_, this->radius_, this->center_ );
}

NPoint NArc::stop() const
{
    return NPoint::newPoint( this->angleStop_, this->radius_, this->center_ );
}

void NArc::setStart( const NPoint &start )
{
    this->angleStart_ = NPoint::angle( this->center_, start );
}

void NArc::setStop( const NPoint &stop )
{
    this->angleStop_ = NPoint::angle( this->center_, stop );
}

nreal NArc::lengthArc() const
{
    NAngle _a1 = this->angleStart_;
    NAngle _a2 = this->angleStop_;
    if( _a1 == _a2 )
        return nreal();
    if( this->direct_ == NDirect::EN_D_LEFT )
    {
        if( _a1 < _a2 )
            return ( NAngle::piIn2() - _a2 + _a1 ).r() * this->radius_;
        else
            return ( _a1.r() - _a2.r() ) * this->radius_;
    }
    else
    {
        if( _a1 < _a2 )
            return ( _a2 - _a1 ).r() * this->radius_;
        else
            return ( NAngle::piIn2() - _a1 + _a2 ).r() * this->radius_;
    }
}

NPoint NArc::pointOnArc( const nreal &distance, bool &appertain ) const
{
    NPoint _point;
    if( distance > this->lengthArc() )
    {
        appertain = false;
        return _point;
    }
    else
    {
        appertain = true;
        NAngle _angle( distance / this->radius_ );
        NPoint _start = NPoint::newPoint( this->angleStart_, this->radius_,
                                            this->center_ );
        if( this->direct_ == NDirect::EN_D_LEFT )
            _point = NPoint::transormation( _start, -_angle, this->center_ );
        else
            _point = NPoint::transormation( _start, _angle, this->center_ );
        return _point;
    }
}

NPoint NArc::midplane()
{
    NAngle _angle;
    NAngle _angleStart = this->angleStart();
    NAngle _angleStop = this->angleStop();
    if( _angleStart > _angleStop )
    {
        if( this->direct() == NDirect::EN_D_RIGHT )
            _angle = ( NAngle::piIn2() - _angleStart + _angleStop ).r() / nreal( 2.0 );
        else
            _angle = ( _angleStart - _angleStop ).r() / 2.0;
    }
    else
    {
        if( this->direct() == NDirect::EN_D_RIGHT )
            _angle = ( _angleStop - _angleStart ).r() / 2.0;
        else
            _angle = ( NAngle::piIn2() - _angleStop + _angleStart ).r() / nreal( 2.0 );
    }
    return NPoint::newPoint( _angle, this->radius_, this->center_ );
}

NArc &NArc::operator=( const NArc &arc )
{
    INArc::operator=( arc );
    return *this;
}

NArc &NArc::operator=( NArc &&arc )
{
    INArc::operator=( std::move( arc ) );
    return *this;
}


