#include "mprectanglegeo.h"
#include "mprelativepoint.h"
#include "mprectangle.h"
#include "mptriangle.h"

MpRectangleGeo::MpRectangleGeo( const MpPointGeo &leftTop,
                                const MpPointGeo &rightBotton )
    : MpPolygonGeo()
{
    auto _point = RP::newCoord( rightBotton, leftTop );
    MpRectangle _rect( MpPoint(), _point );
    *this = RP::newCoord( _rect, leftTop );
}

MpRectangleGeo::MpRectangleGeo( const MpPointGeo &leftTop, const nreal &width,
                                const MpAngle &angleWidth,
                                const nreal &height,
                                const MpAngle &angleHeight )
    : MpPolygonGeo()
{
    MpRectangle _rect( MpPoint(), width, angleWidth, height, angleHeight );
    *this = RP::newCoord( _rect, leftTop );
}

MpRectangleGeo::MpRectangleGeo( const nreal &length, const nreal &width,
                                const MpPointGeo &center )
    : MpPolygonGeo()
{
    auto _rect = MpRectangle( length, width, MpPoint() );
    auto _rectgeo = MpRelativePoint::newCoord( _rect, center );
    *this = _rectgeo;
}

MpRectangleGeo::MpRectangleGeo( const MpPolygonGeo &polygon )
    : MpPolygonGeo()
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

MpRectangleGeo::MpRectangleGeo( const MpRectangleGeo &mpRectangle )
    : MpPolygonGeo(mpRectangle)
{

}

MpRectangleGeo::MpRectangleGeo( MpRectangleGeo &&mpRectangle )
    : MpPolygonGeo( std::move(mpRectangle) )
{

}

MpRectangleGeo::~MpRectangleGeo()
{

}

MpRectangleGeo &MpRectangleGeo::operator=( const MpRectangleGeo &mpRectangle )
{
    MpPolygonGeo::operator=( mpRectangle );
    return *this;
}

MpRectangleGeo &MpRectangleGeo::operator=( MpRectangleGeo &&mpRectangle )
{
    MpPolygonGeo::operator=( std::move( mpRectangle ) );
    return *this;
}

MpPointGeo MpRectangleGeo::leftBottom() const
{
    typedef MpRelativePoint RP;
    auto _rect = MpRectangle( RP::newCoord( *this, this->points().first() ) );
    auto _point = _rect.leftBottom();
    return RP::newCoord( _point, this->points().first() );
}

MpPointGeo MpRectangleGeo::leftTop() const
{
    typedef MpRelativePoint RP;
    auto _rect = MpRectangle( RP::newCoord( *this, this->points().first() ) );
    auto _point = _rect.leftTop();
    return RP::newCoord( _point, this->points().first() );
}

MpPointGeo MpRectangleGeo::rightTop() const
{
    typedef MpRelativePoint RP;
    auto _rect = MpRectangle( RP::newCoord( *this, this->points().first() ) );
    auto _point = _rect.rightTop();
    return RP::newCoord( _point, this->points().first() );
}

MpPointGeo MpRectangleGeo::rightBottom() const
{
    typedef MpRelativePoint RP;
    auto _rect = MpRectangle( RP::newCoord( *this, this->points().first() ) );
    auto _point = _rect.rightBottom();
    return RP::newCoord( _point, this->points().first() );
}

MpPointGeo MpRectangleGeo::center() const
{
    auto _polygon = MpRelativePoint::newCoord( *this, this->points_.first() )
                    .polygonInRectangle();
    return MpRelativePoint::newCoord( MpRectangle( _polygon ).center(),
                                      this->points_.first() );
}
