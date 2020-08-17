#include "nrectangle.h"
#include "ntriangle.h"

NRectangle::NRectangle( const NPoint &leftTop, const NPoint &rightBotton )
    : NPolygon ()
{
    nreal _w = ( rightBotton.x() - leftTop.x() ).abs();
    this->append( leftTop );
    this->append( leftTop.point( NAngle::piOn2(), _w ) );
    this->append( rightBotton );
    this->append( rightBotton.point( NAngle::piIn3On2(), _w ) );
}

NRectangle::NRectangle( const NPoint &leftTop, const nreal &width,
                          const NAngle &angleWidth, const nreal &height,
                          const NAngle &angleHeight )
    : NPolygon ()
{
    this->append( leftTop );
    this->append( leftTop.point( angleWidth, width ) );
    this->append( this->points().last().point( angleHeight, height ) );
    this->append( this->points().last().point( angleWidth - NAngle::pi(),
                                               width ) );
}

NRectangle::NRectangle( const nreal &length, const nreal &width,
                          const NPoint &center )
{
    nreal l = length / 2.0;
    nreal w = width / 2.0;

    this->append( center.point( NAngle(), w ).point( -NAngle::piOn2(), l ) );
    this->append( center.point( NAngle(), w ).point( NAngle::piOn2(), l ) );
    this->append( center.point( NAngle::pi(), w )
                                                .point( NAngle::piOn2(), l ) );
    this->append( center.point( NAngle::pi(), w )
                  .point( -NAngle::piOn2(), l ) );
}

NRectangle::NRectangle( const NPolygon &polygon )
    : NPolygon ( polygon )
{
    if( polygon.points().count() != 4 )
    {
        std::wcerr << "Error! Range not a rectangular." << std::endl;
        return;
    }
    nreal _w1 = polygon.points()[0].distance( polygon.points()[1] );
    nreal _w2 = polygon.points()[2].distance( polygon.points()[3] );
    if( _w1.unequal( _w1 ) )
    {
        std::wcerr << "Error! Range not a rectangular." << std::endl;
        return;
    }
    nreal _h1 = polygon.points()[1].distance( polygon.points()[2] );
    nreal _h2 = polygon.points()[0].distance( polygon.points()[3] );
    if( _h1.unequal( _h1 ) )
    {
        std::wcerr << "Error! Range not a rectangular." << std::endl;
        return;
    }
    auto _s1 = polygon.points()[0];
    auto _s2 = polygon.points()[1];
    auto _s3 = polygon.points()[2];
    auto _s4 = polygon.points()[3];
    auto _angle = NAngle::piOn2();
    if( NTriangle( _s1, _s2, _s3 ).angle( NVertex::VERTEX_1 ) != _angle )
        std::wcerr << "Error! Range not a rectangular." << std::endl;
    else if( NTriangle( _s2, _s3, _s4 ).angle( NVertex::VERTEX_1 ) != _angle )
        std::wcerr << "Error! Range not a rectangular." << std::endl;
    else if( NTriangle( _s3, _s4, _s1 ).angle( NVertex::VERTEX_1 ) != _angle )
        std::wcerr << "Error! Range not a rectangular." << std::endl;
    else if( NTriangle( _s4, _s1, _s2 ).angle( NVertex::VERTEX_1 ) != _angle )
        std::wcerr << "Error! Range not a rectangular." << std::endl;
}

NRectangle::NRectangle( const NRectangle &NRectangle )
    : NPolygon (NRectangle)
{

}

NRectangle::NRectangle( NRectangle &&NRectangle )
    : NPolygon ( std::move( NRectangle ) )
{

}

NRectangle::~NRectangle()
{

}

NRectangle &NRectangle::operator=( const NRectangle &NRectangle )
{
    NPolygon::operator=( NRectangle );
    return *this;
}

NRectangle &NRectangle::operator=( NRectangle &&NRectangle )
{
    NPolygon::operator=( std::move( NRectangle ) );
    return *this;
}

NPoint NRectangle::leftBottom() const
{
    auto _m1 = []( const nreal &a, const nreal &b ) { return ( a < b ); };
    return this->vertixRect( _m1, _m1 );
}

NPoint NRectangle::leftTop() const
{
    auto _m1 = []( const nreal &a, const nreal &b ) { return ( a > b ); };
    auto _m2 = []( const nreal &a, const nreal &b ) { return ( a < b ); };
    return this->vertixRect( _m1, _m2 );
}

NPoint NRectangle::rightTop() const
{
    auto _m1 = []( const nreal &a, const nreal &b ) { return ( a > b ); };
    return this->vertixRect( _m1, _m1 );
}

NPoint NRectangle::rightBottom() const
{
    auto _m1 = []( const nreal &a, const nreal &b ) { return ( a < b ); };
    auto _m2 = []( const nreal &a, const nreal &b ) { return ( a > b ); };
    return this->vertixRect( _m1, _m2 );
}

NPoint NRectangle::center() const
{
    return NLineSection( this->points_[0], this->points_[2] ).midplane();
}
