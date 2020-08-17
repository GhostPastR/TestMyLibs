#include "nlinesection.h"

NLineSection::NLineSection( const NLineSection &line )
    : NLine(line), INLineSection(line)
{

}

NLineSection::NLineSection( NLineSection &&line )
    : NLine(std::move(line)), INLineSection(std::move(line))
{

}

NLineSection::~NLineSection()
{

}

nreal NLineSection::length() const
{
    auto _d = ( this->stop_.x() - this->start_.x() )
            * ( this->stop_.x() - this->start_.x() )
            + ( this->stop_.y() - this->start_.y() )
            * ( this->stop_.y() - this->start_.y() );
    return nreal( sqrt( _d.toType() ) );
}

NAngle NLineSection::angle() const
{
    return NPoint::angle( this->start_, this->stop_ );
}

bool NLineSection::sectionOnSection( const NLineSection &line ) const
{
    auto _point = this->intersectionLine( line );
    return this->pointToSection( _point ) && line.pointToSection( _point );
}

bool NLineSection::pointToSection( const NPoint &point ) const
{
    bool _flagX;
    bool _flagY;
    if( this->start_.x() < this->stop_.x() )
        _flagX = point.x().intervalStrict( this->start_.x(), this->stop_.x() );
    else
        _flagX = point.x().intervalStrict( this->stop_.x(), this->start_.x() );
    if( this->start_.y() < this->stop_.y() )
        _flagY = point.y().intervalStrict( this->start_.y(), this->stop_.y() );
    else
        _flagY = point.y().intervalStrict( this->stop_.y(), this->start_.y() );
    if( _flagX && _flagY )
        return ( this->getValueFunction( point ).compare( nreal() ) );
    else
        return false;
}

NPoint NLineSection::midplane()
{
    nreal _two( 2.0 );
    return NPoint( ( this->stop_.x() - this->start_.x() )
                    / _two + this->start_.x(),
                    ( this->stop_.y() - this->start_.y() )
                    / _two + this->start_.y() );
}

NPoint NLineSection::pointOnLine( const nreal &distance,
                                    bool &appertain ) const
{
    NPoint _point;
    if( distance > this->length() )
    {
        appertain = false;
        return _point;
    }
    else
    {
        appertain = true;
        return NPoint::newPoint( this->angle(), distance, this->start_ );
    }
}

bool NLineSection::isInfinity() const
{
    return ( this->start_.isInfinity() || this->stop_.isInfinity() );
}

bool NLineSection::isValid() const
{
    return ( this->start_.isValid() && this->stop_.isValid() );
}

nreal NLineSection::lengthBrokerline( const QList<NPoint> &list )
{
    int _count = list.count();
    if( _count < 2 )
        return nreal();
    nreal _len;
    for( int i = 1; i < _count; i++ )
        _len += list.at(i).distance( list.at(i - 1) );
    return _len;
}

NLineSection &NLineSection::operator=( const NLineSection &line )
{
    NLine::operator=( line );
    INLineSection::operator=( line );
    return *this;
}

NLineSection &NLineSection::operator=( NLineSection &&line )
{
    NLine::operator=( std::move( line ) );
    INLineSection::operator=( std::move( line ) );
    return *this;
}

void NLineSection::equationLineQuick()
{
    auto _line = NLine::equationLineQuick( this->start_, this->stop_ );
    this->a_ = _line.a();
    this->b_ = _line.b();
    this->c_ = _line.c();
}
