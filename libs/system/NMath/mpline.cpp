#include "mpline.h"

MpLine::MpLine(const nreal &a, const nreal &b, const nreal &c )
    : a_(a), b_(b), c_(c)
{

}

MpLine::MpLine( const MpLine &line )
{
    this->a_ = line.a_;
    this->b_ = line.b_;
    this->c_ = line.c_;
}

MpLine::MpLine( MpLine &&line )
{
    this->a_ = std::move( line.a_ );
    this->b_ = std::move( line.b_ );
    this->c_ = std::move( line.c_ );
}

MpLine::~MpLine()
{

}

void MpLine::setCoefficientEquation( const nreal &a, const nreal &b,
                                     const nreal &c )
{
    this->a_ = a;
    this->b_ = b;
    this->c_ = c;
}

nreal MpLine::distanceToLine( const MpPoint &point ) const
{
    auto _d = this->a_ * this->a_ + this->b_ * this->b_;
    return nreal( ( this->a_ * point.x() + this->b_ * point.y() + this->c_ )
                    / ( sqrt( _d.toType() ) ) );
}

nreal MpLine::getValueFunction( const MpPoint &point ) const
{
    return nreal( point.x() * this->a_ + point.y() * this->b_ + this->c_ );
}

MpPoint MpLine::intersectionLine( const MpLine &line ) const
{
    nreal _c = this->a() * line.b() - line.a() * this->b();
    if( _c.compare( nreal() ) )
        return MpPoint( nreal::pInfinity, nreal::pInfinity );
    else
        return MpPoint( ( this->b() * line.c() - line.b() * this->c() ) / _c,
                        ( this->c() * line.a() - line.c() * this->a() ) / _c );
}

bool MpLine::checkPointOnLine( const MpPoint point ) const
{
    return this->getValueFunction( point ).compare( nreal() );
}

MpLine MpLine::parallelLine( const nreal &distance ) const
{
    MpLine _line;
    auto _d = this->a_ * this->a_ + this->b_ * this->b_;
    _line.setCoefficientEquation( this->a_, this->b_, this->c_ - distance *
                                  ( -sqrt( _d.toType() ) ) );
    return _line;
}

MpPoint MpLine::pointPerpendicular( const MpPoint &point ) const
{       
    nreal _a2 = this->a_ * this->a_;
    nreal _b2 = this->b_ * this->b_;
    MpPoint _point;
    _point.setX( ( point.x() * _b2 - this->a_ * this->b_ *
                   ( point.y() - ( -this->c_ / this->b_ ) ) ) / ( _a2 + _b2 ) );
    _point.setY( ( -this->b_ * ( point.x() - _point.x() ) / this->a_ )
                                                                  + point.y() );
    return _point;
}

MpLine &MpLine::operator=( const MpLine &line )
{
    this->a_ = line.a_;
    this->b_ = line.b_;
    this->c_ = line.c_;
    return *this;
}

MpLine &MpLine::operator=( MpLine &line )
{
    this->a_ = std::move( line.a_ );
    this->b_ = std::move( line.b_ );
    this->c_ = std::move( line.c_ );
    return *this;
}

MpLine MpLine::equationLineQuick( const MpPoint &point1, const MpPoint &point2 )
{
    nreal _a = point1.y() - point2.y();
    nreal _b = point2.x() - point1.x();
    nreal _c = -_b * point1.y() - _a * point1.x();
    return MpLine( _a, _b, _c );
}
