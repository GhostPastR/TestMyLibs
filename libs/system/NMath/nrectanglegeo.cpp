#include "nrectanglegeo.h"
#include "nrelativepoint.h"
#include "nrectangle.h"
#include "ntriangle.h"

NRectangleGeo::NRectangleGeo( const NPointGeo &leftTop,
                                const NPointGeo &rightBotton )
    : NPolygonGeo()
{
    auto _point = RP::newCoord( rightBotton, leftTop );
    NRectangle _rect( NPoint(), _point );
    *this = RP::newCoord( _rect, leftTop );
}

NRectangleGeo::NRectangleGeo( const NPointGeo &leftTop, const nreal &width,
                                const NAngle &angleWidth,
                                const nreal &height,
                                const NAngle &angleHeight )
    : NPolygonGeo()
{
    NRectangle _rect( NPoint(), width, angleWidth, height, angleHeight );
    *this = RP::newCoord( _rect, leftTop );
}

NRectangleGeo::NRectangleGeo( const nreal &length, const nreal &width,
                                const NPointGeo &center )
    : NPolygonGeo()
{
    auto _rect = NRectangle( length, width, NPoint() );
    auto _rectgeo = NRelativePoint::newCoord( _rect, center );
    *this = _rectgeo;
}

NRectangleGeo::NRectangleGeo( const NPolygonGeo &polygon )
    : NPolygonGeo()
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
    auto _s1 = RP::newCoord( polygon.points()[0], polygon.points()[0] );
    auto _s2 = RP::newCoord( polygon.points()[1], polygon.points()[0] );
    auto _s3 = RP::newCoord( polygon.points()[2], polygon.points()[0] );
    auto _s4 = RP::newCoord( polygon.points()[3], polygon.points()[0] );
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

NRectangleGeo::NRectangleGeo( const NRectangleGeo &NRectangle )
    : NPolygonGeo(NRectangle)
{

}

NRectangleGeo::NRectangleGeo( NRectangleGeo &&NRectangle )
    : NPolygonGeo( std::move(NRectangle) )
{

}

NRectangleGeo::~NRectangleGeo()
{

}

NRectangleGeo &NRectangleGeo::operator=( const NRectangleGeo &NRectangle )
{
    NPolygonGeo::operator=( NRectangle );
    return *this;
}

NRectangleGeo &NRectangleGeo::operator=( NRectangleGeo &&NRectangle )
{
    NPolygonGeo::operator=( std::move( NRectangle ) );
    return *this;
}

NPointGeo NRectangleGeo::leftBottom() const
{
    typedef NRelativePoint RP;
    auto _rect = NRectangle( RP::newCoord( *this, this->points().first() ) );
    auto _point = _rect.leftBottom();
    return RP::newCoord( _point, this->points().first() );
}

NPointGeo NRectangleGeo::leftTop() const
{
    typedef NRelativePoint RP;
    auto _rect = NRectangle( RP::newCoord( *this, this->points().first() ) );
    auto _point = _rect.leftTop();
    return RP::newCoord( _point, this->points().first() );
}

NPointGeo NRectangleGeo::rightTop() const
{
    typedef NRelativePoint RP;
    auto _rect = NRectangle( RP::newCoord( *this, this->points().first() ) );
    auto _point = _rect.rightTop();
    return RP::newCoord( _point, this->points().first() );
}

NPointGeo NRectangleGeo::rightBottom() const
{
    typedef NRelativePoint RP;
    auto _rect = NRectangle( RP::newCoord( *this, this->points().first() ) );
    auto _point = _rect.rightBottom();
    return RP::newCoord( _point, this->points().first() );
}

NPointGeo NRectangleGeo::center() const
{
    auto _polygon = NRelativePoint::newCoord( *this, this->points_.first() )
                    .polygonInRectangle();
    return NRelativePoint::newCoord( NRectangle( _polygon ).center(),
                                      this->points_.first() );
}
