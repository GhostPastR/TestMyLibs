#include "nhalfline.h"

NHalfLine::NHalfLine() : NLine(), INHalfLine()
{

}

NHalfLine::NHalfLine( const NPoint &point, const NAngle &angle )
    : NLine(), INHalfLine( point, angle )
{
    auto _line = NLine::equationLineQuick( point,
                                    NPoint::newPoint( angle, nreal( 10 ) ) );
    this->a_ = _line.a();
    this->b_ = _line.b();
    this->c_ = _line.c();
}

NHalfLine::NHalfLine( const NPoint &start, const NPoint &stop )
    : NLine(), INHalfLine( start, NAngle() )
{
    auto _line = NLine::equationLineQuick( start, stop );
    this->a_ = _line.a();
    this->b_ = _line.b();
    this->c_ = _line.c();
    this->setAngle( start.angleToPoint( stop ) );
}

NHalfLine::NHalfLine( const NHalfLine &halfLine )
    : NLine(halfLine), INHalfLine( halfLine )
{

}

NHalfLine::NHalfLine( NHalfLine &&halfLine )
    : NLine( std::move( halfLine ) ), INHalfLine( std::move( halfLine ) )
{

}

NHalfLine::~NHalfLine()
{

}

bool NHalfLine::checkPointOnLine( const NPoint point ) const
{
    if( this->getValueFunction( point ).compare( nreal() ) )
    {
        if( ( NAngle() <= this->angle_ )
                && ( this->angle_ < NAngle( nreal( 90.0 ), false ) ) )
            return ( this->point_.x().feverThan( point.x() )
                     && this->point_.y().feverThan( point.y() ) );
        if( ( NAngle( nreal( 90 ), false ) <= this->angle_ )
                && ( this->angle_ < NAngle( nreal( 180 ), false ) ) )
            return ( this->point_.x().feverThan( point.x() )
                     && this->point_.y().moreThan( point.y() ) );
        if( ( NAngle( nreal( 180 ), false ) <= this->angle_ )
                && ( this->angle_ < NAngle( nreal( 270 ), false ) ) )
            return ( this->point_.x().moreThan( point.x() )
                     && this->point_.y().moreThan( point.y() ) );
        if( ( NAngle( nreal( 270 ), false ) <= this->angle_ )
                && ( this->angle_ < NAngle( nreal( 360 ), false ) ) )
            return ( this->point_.x().moreThan( point.x() )
                     && this->point_.y().feverThan( point.y() ) );
    }
    return false;
}

NPoint NHalfLine::intersectionHalfLine( const NHalfLine &halfLine ) const
{
    auto _point = intersectionLine( halfLine );
    if( this->checkPointOnLine( _point )
            && halfLine.checkPointOnLine( _point ) )
        return _point;
    return NPoint( nreal::pInfinity, nreal::pInfinity );
}

bool NHalfLine::halfLineOnHalfLine( const NHalfLine &halfLine ) const
{
    auto _point = intersectionLine( halfLine );
    return this->checkPointOnLine( _point ) &&
            halfLine.checkPointOnLine( _point );
}

NHalfLine &NHalfLine::operator=( const NHalfLine &halfLine )
{
    INHalfLine::operator=( halfLine );
    return *this;
}

NHalfLine &NHalfLine::operator=( NHalfLine &&halfLine )
{
    INHalfLine::operator=( std::move( halfLine ) );
    return *this;
}
