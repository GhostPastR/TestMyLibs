#include "mprectangle.h"
#include "mptriangle.h"

MpRectangle::MpRectangle( const MpPoint &leftTop, const MpPoint &rightBotton )
    : MpPolygon ()
{
    nreal _w = ( rightBotton.x() - leftTop.x() ).abs();
    this->append( leftTop );
    this->append( leftTop.point( MpAngle::piOn2(), _w ) );
    this->append( rightBotton );
    this->append( rightBotton.point( MpAngle::piIn3On2(), _w ) );
}

MpRectangle::MpRectangle( const MpPoint &leftTop, const nreal &width,
                          const MpAngle &angleWidth, const nreal &height,
                          const MpAngle &angleHeight )
    : MpPolygon ()
{
    this->append( leftTop );
    this->append( leftTop.point( angleWidth, width ) );
    this->append( this->points().last().point( angleHeight, height ) );
    this->append( this->points().last().point( angleWidth - MpAngle::pi(),
                                               width ) );
}

MpRectangle::MpRectangle( const nreal &length, const nreal &width,
                          const MpPoint &center )
{
    nreal l = length / 2.0;
    nreal w = width / 2.0;

    this->append( center.point( MpAngle(), w ).point( -MpAngle::piOn2(), l ) );
    this->append( center.point( MpAngle(), w ).point( MpAngle::piOn2(), l ) );
    this->append( center.point( MpAngle::pi(), w )
                                                .point( MpAngle::piOn2(), l ) );
    this->append( center.point( MpAngle::pi(), w )
                  .point( -MpAngle::piOn2(), l ) );
}

MpRectangle::MpRectangle( const MpPolygon &polygon )
    : MpPolygon ( polygon )
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
    auto _angle = MpAngle::piOn2();
    if( MpTriangle( _s1, _s2, _s3 ).angle( MpVertex::VERTEX_1 ) != _angle )
        std::wcerr << "Error! Range not a rectangular." << std::endl;
    else if( MpTriangle( _s2, _s3, _s4 ).angle( MpVertex::VERTEX_1 ) != _angle )
        std::wcerr << "Error! Range not a rectangular." << std::endl;
    else if( MpTriangle( _s3, _s4, _s1 ).angle( MpVertex::VERTEX_1 ) != _angle )
        std::wcerr << "Error! Range not a rectangular." << std::endl;
    else if( MpTriangle( _s4, _s1, _s2 ).angle( MpVertex::VERTEX_1 ) != _angle )
        std::wcerr << "Error! Range not a rectangular." << std::endl;
}

MpRectangle::MpRectangle( const MpRectangle &mpRectangle )
    : MpPolygon (mpRectangle)
{

}

MpRectangle::MpRectangle( MpRectangle &&mpRectangle )
    : MpPolygon ( std::move( mpRectangle ) )
{

}

MpRectangle::~MpRectangle()
{

}

MpRectangle &MpRectangle::operator=( const MpRectangle &mpRectangle )
{
    MpPolygon::operator=( mpRectangle );
    return *this;
}

MpRectangle &MpRectangle::operator=( MpRectangle &&mpRectangle )
{
    MpPolygon::operator=( std::move( mpRectangle ) );
    return *this;
}

MpPoint MpRectangle::leftBottom() const
{
    auto _m1 = []( const nreal &a, const nreal &b ) { return ( a < b ); };
    return this->vertixRect( _m1, _m1 );
}

MpPoint MpRectangle::leftTop() const
{
    auto _m1 = []( const nreal &a, const nreal &b ) { return ( a > b ); };
    auto _m2 = []( const nreal &a, const nreal &b ) { return ( a < b ); };
    return this->vertixRect( _m1, _m2 );
}

MpPoint MpRectangle::rightTop() const
{
    auto _m1 = []( const nreal &a, const nreal &b ) { return ( a > b ); };
    return this->vertixRect( _m1, _m1 );
}

MpPoint MpRectangle::rightBottom() const
{
    auto _m1 = []( const nreal &a, const nreal &b ) { return ( a < b ); };
    auto _m2 = []( const nreal &a, const nreal &b ) { return ( a > b ); };
    return this->vertixRect( _m1, _m2 );
}

MpPoint MpRectangle::center() const
{
    return MpLineSection( this->points_[0], this->points_[2] ).midplane();
}
