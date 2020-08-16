#include "mphalfline.h"

MpHalfLine::MpHalfLine() : MpLine(), IMpHalfLine()
{

}

MpHalfLine::MpHalfLine( const MpPoint &point, const MpAngle &angle )
    : MpLine(), IMpHalfLine( point, angle )
{
    auto _line = MpLine::equationLineQuick( point,
                                    MpPoint::newPoint( angle, nreal( 10 ) ) );
    this->a_ = _line.a();
    this->b_ = _line.b();
    this->c_ = _line.c();
}

MpHalfLine::MpHalfLine( const MpPoint &start, const MpPoint &stop )
    : MpLine(), IMpHalfLine( start, MpAngle() )
{
    auto _line = MpLine::equationLineQuick( start, stop );
    this->a_ = _line.a();
    this->b_ = _line.b();
    this->c_ = _line.c();
    this->setAngle( start.angleToPoint( stop ) );
}

MpHalfLine::MpHalfLine( const MpHalfLine &halfLine )
    : MpLine(halfLine), IMpHalfLine( halfLine )
{

}

MpHalfLine::MpHalfLine( MpHalfLine &&halfLine )
    : MpLine( std::move( halfLine ) ), IMpHalfLine( std::move( halfLine ) )
{

}

MpHalfLine::~MpHalfLine()
{

}

bool MpHalfLine::checkPointOnLine( const MpPoint point ) const
{
    if( this->getValueFunction( point ).compare( nreal() ) )
    {
        if( ( MpAngle() <= this->angle_ )
                && ( this->angle_ < MpAngle( nreal( 90.0 ), false ) ) )
            return ( this->point_.x().feverThan( point.x() )
                     && this->point_.y().feverThan( point.y() ) );
        if( ( MpAngle( nreal( 90 ), false ) <= this->angle_ )
                && ( this->angle_ < MpAngle( nreal( 180 ), false ) ) )
            return ( this->point_.x().feverThan( point.x() )
                     && this->point_.y().moreThan( point.y() ) );
        if( ( MpAngle( nreal( 180 ), false ) <= this->angle_ )
                && ( this->angle_ < MpAngle( nreal( 270 ), false ) ) )
            return ( this->point_.x().moreThan( point.x() )
                     && this->point_.y().moreThan( point.y() ) );
        if( ( MpAngle( nreal( 270 ), false ) <= this->angle_ )
                && ( this->angle_ < MpAngle( nreal( 360 ), false ) ) )
            return ( this->point_.x().moreThan( point.x() )
                     && this->point_.y().feverThan( point.y() ) );
    }
    return false;
}

MpPoint MpHalfLine::intersectionHalfLine( const MpHalfLine &halfLine ) const
{
    auto _point = intersectionLine( halfLine );
    if( this->checkPointOnLine( _point )
            && halfLine.checkPointOnLine( _point ) )
        return _point;
    return MpPoint( nreal::pInfinity, nreal::pInfinity );
}

bool MpHalfLine::halfLineOnHalfLine( const MpHalfLine &halfLine ) const
{
    auto _point = intersectionLine( halfLine );
    return this->checkPointOnLine( _point ) &&
            halfLine.checkPointOnLine( _point );
}

MpHalfLine &MpHalfLine::operator=( const MpHalfLine &halfLine )
{
    IMpHalfLine::operator=( halfLine );
    return *this;
}

MpHalfLine &MpHalfLine::operator=( MpHalfLine &&halfLine )
{
    IMpHalfLine::operator=( std::move( halfLine ) );
    return *this;
}
