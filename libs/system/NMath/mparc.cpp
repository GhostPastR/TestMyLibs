#include "mparc.h"

MpArc::MpArc( const MpPoint &center, const nreal &radius,
              const MpPoint &start, const MpPoint &stop, MpDirect direct )
{
    this->center_ = center;
    this->setRadius( radius );
    this->setDirect( direct );
    this->setStart( start );
    this->setStop( stop );
}

MpArc::MpArc( const MpArc &arc ) : IMpArc(arc)
{

}

MpArc::MpArc( MpArc &&arc ) : IMpArc(std::move(arc))
{

}

MpArc::~MpArc()
{

}

MpPoint MpArc::start() const
{
    return MpPoint::newPoint( this->angleStart_, this->radius_, this->center_ );
}

MpPoint MpArc::stop() const
{
    return MpPoint::newPoint( this->angleStop_, this->radius_, this->center_ );
}

void MpArc::setStart( const MpPoint &start )
{
    this->angleStart_ = MpPoint::angle( this->center_, start );
}

void MpArc::setStop( const MpPoint &stop )
{
    this->angleStop_ = MpPoint::angle( this->center_, stop );
}

nreal MpArc::lengthArc() const
{
    MpAngle _a1 = this->angleStart_;
    MpAngle _a2 = this->angleStop_;
    if( _a1 == _a2 )
        return nreal();
    if( this->direct_ == MpDirect::EN_D_LEFT )
    {
        if( _a1 < _a2 )
            return ( MpAngle::piIn2() - _a2 + _a1 ).r() * this->radius_;
        else
            return ( _a1.r() - _a2.r() ) * this->radius_;
    }
    else
    {
        if( _a1 < _a2 )
            return ( _a2 - _a1 ).r() * this->radius_;
        else
            return ( MpAngle::piIn2() - _a1 + _a2 ).r() * this->radius_;
    }
}

MpPoint MpArc::pointOnArc( const nreal &distance, bool &appertain ) const
{
    MpPoint _point;
    if( distance > this->lengthArc() )
    {
        appertain = false;
        return _point;
    }
    else
    {
        appertain = true;
        MpAngle _angle( distance / this->radius_ );
        MpPoint _start = MpPoint::newPoint( this->angleStart_, this->radius_,
                                            this->center_ );
        if( this->direct_ == MpDirect::EN_D_LEFT )
            _point = MpPoint::transormation( _start, -_angle, this->center_ );
        else
            _point = MpPoint::transormation( _start, _angle, this->center_ );
        return _point;
    }
}

MpPoint MpArc::midplane()
{
    MpAngle _angle;
    MpAngle _angleStart = this->angleStart();
    MpAngle _angleStop = this->angleStop();
    if( _angleStart > _angleStop )
    {
        if( this->direct() == MpDirect::EN_D_RIGHT )
            _angle = ( MpAngle::piIn2() - _angleStart + _angleStop ).r() / nreal( 2.0 );
        else
            _angle = ( _angleStart - _angleStop ).r() / 2.0;
    }
    else
    {
        if( this->direct() == MpDirect::EN_D_RIGHT )
            _angle = ( _angleStop - _angleStart ).r() / 2.0;
        else
            _angle = ( MpAngle::piIn2() - _angleStop + _angleStart ).r() / nreal( 2.0 );
    }
    return MpPoint::newPoint( _angle, this->radius_, this->center_ );
}

MpArc &MpArc::operator=( const MpArc &arc )
{
    IMpArc::operator=( arc );
    return *this;
}

MpArc &MpArc::operator=( MpArc &&arc )
{
    IMpArc::operator=( std::move( arc ) );
    return *this;
}


