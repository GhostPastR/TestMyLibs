#include "nline.h"

NLine::NLine(const nreal &a, const nreal &b, const nreal &c )
    : a_(a), b_(b), c_(c)
{

}

NLine::NLine( const NLine &line )
{
    this->a_ = line.a_;
    this->b_ = line.b_;
    this->c_ = line.c_;
}

NLine::NLine( NLine &&line )
{
    this->a_ = std::move( line.a_ );
    this->b_ = std::move( line.b_ );
    this->c_ = std::move( line.c_ );
}

NLine::~NLine()
{

}

void NLine::setCoefficientEquation( const nreal &a, const nreal &b,
                                     const nreal &c )
{
    this->a_ = a;
    this->b_ = b;
    this->c_ = c;
}

nreal NLine::distanceToLine( const NPoint &point ) const
{
    auto _d = this->a_ * this->a_ + this->b_ * this->b_;
    return nreal( ( this->a_ * point.x() + this->b_ * point.y() + this->c_ )
                    / ( sqrt( _d.toType() ) ) );
}

nreal NLine::getValueFunction( const NPoint &point ) const
{
    return nreal( point.x() * this->a_ + point.y() * this->b_ + this->c_ );
}

NPoint NLine::intersectionLine( const NLine &line ) const
{
    nreal _c = this->a() * line.b() - line.a() * this->b();
    if( _c.compare( nreal() ) )
        return NPoint( nreal::pInfinity, nreal::pInfinity );
    else
        return NPoint( ( this->b() * line.c() - line.b() * this->c() ) / _c,
                        ( this->c() * line.a() - line.c() * this->a() ) / _c );
}

bool NLine::checkPointOnLine( const NPoint point ) const
{
    return this->getValueFunction( point ).compare( nreal() );
}

NLine NLine::parallelLine( const nreal &distance ) const
{
    NLine _line;
    auto _d = this->a_ * this->a_ + this->b_ * this->b_;
    _line.setCoefficientEquation( this->a_, this->b_, this->c_ - distance *
                                  ( -sqrt( _d.toType() ) ) );
    return _line;
}

NPoint NLine::pointPerpendicular( const NPoint &point ) const
{       
    nreal _a2 = this->a_ * this->a_;
    nreal _b2 = this->b_ * this->b_;
    NPoint _point;
    _point.setX( ( point.x() * _b2 - this->a_ * this->b_ *
                   ( point.y() - ( -this->c_ / this->b_ ) ) ) / ( _a2 + _b2 ) );
    _point.setY( ( -this->b_ * ( point.x() - _point.x() ) / this->a_ )
                                                                  + point.y() );
    return _point;
}

NLine &NLine::operator=( const NLine &line )
{
    this->a_ = line.a_;
    this->b_ = line.b_;
    this->c_ = line.c_;
    return *this;
}

NLine &NLine::operator=( NLine &line )
{
    this->a_ = std::move( line.a_ );
    this->b_ = std::move( line.b_ );
    this->c_ = std::move( line.c_ );
    return *this;
}

NLine NLine::equationLineQuick( const NPoint &point1, const NPoint &point2 )
{
    nreal _a = point1.y() - point2.y();
    nreal _b = point2.x() - point1.x();
    nreal _c = -_b * point1.y() - _a * point1.x();
    return NLine( _a, _b, _c );
}
