#include "mplinesection.h"

MpLineSection::MpLineSection( const MpLineSection &line )
    : MpLine(line), IMpLineSection(line)
{

}

MpLineSection::MpLineSection( MpLineSection &&line )
    : MpLine(std::move(line)), IMpLineSection(std::move(line))
{

}

MpLineSection::~MpLineSection()
{

}

nreal MpLineSection::length() const
{
    auto _d = ( this->stop_.x() - this->start_.x() )
            * ( this->stop_.x() - this->start_.x() )
            + ( this->stop_.y() - this->start_.y() )
            * ( this->stop_.y() - this->start_.y() );
    return nreal( sqrt( _d.toType() ) );
}

MpAngle MpLineSection::angle() const
{
    return MpPoint::angle( this->start_, this->stop_ );
}

bool MpLineSection::sectionOnSection( const MpLineSection &line ) const
{
    auto _point = this->intersectionLine( line );
    return this->pointToSection( _point ) && line.pointToSection( _point );
}

bool MpLineSection::pointToSection( const MpPoint &point ) const
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

MpPoint MpLineSection::midplane()
{
    nreal _two( 2.0 );
    return MpPoint( ( this->stop_.x() - this->start_.x() )
                    / _two + this->start_.x(),
                    ( this->stop_.y() - this->start_.y() )
                    / _two + this->start_.y() );
}

MpPoint MpLineSection::pointOnLine( const nreal &distance,
                                    bool &appertain ) const
{
    MpPoint _point;
    if( distance > this->length() )
    {
        appertain = false;
        return _point;
    }
    else
    {
        appertain = true;
        return MpPoint::newPoint( this->angle(), distance, this->start_ );
    }
}

bool MpLineSection::isInfinity() const
{
    return ( this->start_.isInfinity() || this->stop_.isInfinity() );
}

bool MpLineSection::isValid() const
{
    return ( this->start_.isValid() && this->stop_.isValid() );
}

nreal MpLineSection::lengthBrokerline( const QList<MpPoint> &list )
{
    int _count = list.count();
    if( _count < 2 )
        return nreal();
    nreal _len;
    for( int i = 1; i < _count; i++ )
        _len += list.at(i).distance( list.at(i - 1) );
    return _len;
}

MpLineSection &MpLineSection::operator=( const MpLineSection &line )
{
    MpLine::operator=( line );
    IMpLineSection::operator=( line );
    return *this;
}

MpLineSection &MpLineSection::operator=( MpLineSection &&line )
{
    MpLine::operator=( std::move( line ) );
    IMpLineSection::operator=( std::move( line ) );
    return *this;
}

void MpLineSection::equationLineQuick()
{
    auto _line = MpLine::equationLineQuick( this->start_, this->stop_ );
    this->a_ = _line.a();
    this->b_ = _line.b();
    this->c_ = _line.c();
}
