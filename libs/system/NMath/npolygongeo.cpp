#include "npolygongeo.h"
#include "nrelativepoint.h"

NPolygonGeo::NPolygonGeo( const NPolygonGeo &polygonGeo )
    : INPolygon(polygonGeo)
{

}

NPolygonGeo::NPolygonGeo( NPolygonGeo &&polygonGeo )
    : INPolygon(polygonGeo)
{

}

NPolygonGeo::~NPolygonGeo()
{

}

nreal NPolygonGeo::length() const
{
    if( this->points_.count() < 3 )
        return nreal();
    return this->points().first().distance( this->points()[1] );
}

nreal NPolygonGeo::width() const
{
    if( this->points_.count() < 3  )
        return nreal();
    return this->points()[1].distance( this->points()[2] );
}

NAngle NPolygonGeo::lengthCourse() const
{
    if( this->points_.count() < 3  )
        return nreal();
    return this->points().first().angle( this->points()[1] );
}

NPolygonGeo &NPolygonGeo::setPolygon( const NPointGeo &center,
                                    const double &length , const double &width )
{
    this->points_.clear();
    nreal _dl( length / 2.0 );
    nreal _dw( width / 2.0 );
    this->points_.append( NRelativePoint::newCoord( NPoint( -_dw, -_dl ),
                                                                    center ) );
    this->points_.append( NRelativePoint::newCoord( NPoint( -_dw, _dl ),
                                                                    center ) );
    this->points_.append( NRelativePoint::newCoord( NPoint( _dw, _dl ),
                                                                    center ) );
    this->points_.append( NRelativePoint::newCoord( NPoint( _dw, -_dl ),
                                                                    center ) );
    return *this;
}

NPolygonGeo NPolygonGeo::polygonInRectangle() const
{
    if( this->points_.isEmpty() )
        return NPolygonGeo();
    else
    {
        nreal _maxX = this->points_.first().latitude().d();
        nreal _minX = this->points_.first().latitude().d();
        nreal _maxY = this->points_.first().longitude().d();
        nreal _minY = this->points_.first().longitude().d();
        int _count = this->points_.count();
        for( int i = 1; i < _count; i++ )
        {
            if( _maxX < this->points_[i].latitude().d() )
                _maxX = this->points_[i].latitude().d();
            if( _minX > this->points_[i].latitude().d() )
                _minX = this->points_[i].latitude().d();
            if( _maxY < this->points_[i].longitude().d() )
                _maxY = this->points_[i].longitude().d();
            if( _minY > this->points_[i].longitude().d() )
                _minY = this->points_[i].longitude().d();
        }
        NPolygonGeo _polygon;
        _polygon.points_.append( NPointGeo( _minX, _maxY ) );
        _polygon.points_.append( NPointGeo( _maxX, _maxY ) );
        _polygon.points_.append( NPointGeo( _maxX, _minY ) );
        _polygon.points_.append( NPointGeo( _minX, _minY ) );
        return _polygon;
    }
}

NPointGeo NPolygonGeo::leftUp() const
{
    if( this->points_.isEmpty() )
        return NPointGeo();
    else
    {
        nreal maxLat = this->points_.first().latitude().d();
        nreal minLong = this->points_.first().longitude().d();
        for( int i = 1; i < this->points_.count(); i++ )
        {
            if( this->points_[i].latitude().d() > maxLat )
                maxLat = this->points_[i].latitude().d();
            if( this->points_[i].longitude().d() < minLong )
                minLong = this->points_[i].longitude().d();
        }
        return NPointGeo( maxLat, minLong );
    }
}

NPointGeo NPolygonGeo::rightDown() const
{
    if( this->points_.isEmpty() )
        return NPointGeo();
    else
    {
        nreal minLat = this->points_.first().latitude().d();
        nreal maxLong = this->points_.first().longitude().d();
        for( int i = 1; i < this->points_.count(); i++ )
        {
            if( this->points_[i].latitude().d() < minLat )
                minLat = this->points_[i].latitude().d();
            if( this->points_[i].longitude().d() > maxLong )
                maxLong = this->points_[i].longitude().d();
        }
        return NPointGeo( minLat, maxLong );
    }
}

NPointGeo NPolygonGeo::pointCoupling( const NPointGeo &pointGeo ) const
{
    return NRelativePoint::newCoord(
                                    NRelativePoint::newCoord( *this, pointGeo )
                                        .pointCoupling( NPoint() ), pointGeo );
}

NPolygonGeo NPolygonGeo::scalePolygon( const nreal &distance ) const
{
    if( this->points_.isEmpty() )
        return NPolygonGeo();
    NPolygon _p = NRelativePoint::newCoord( *this, this->points_.first() );
    return NRelativePoint::newCoord( _p.scalePolygon( distance ),
                                      this->points_.first() );
}

bool NPolygonGeo::pointAppertainPolygon( const NPointGeo &pointGeo ) const
{
    return NRelativePoint::newCoord( *this, pointGeo )
                                            .pointAppertainPolygon( NPoint() );
}

bool NPolygonGeo::polygonAppertainPolygon( const NPolygonGeo &polygon ) const
{
    NPolygon _p = NRelativePoint::newCoord( *this, this->points_.first() );
    return _p.polugAppertainPartPolug( NRelativePoint::newCoord( polygon,
                                                      this->points_.first() ) );
}

NPointGeo NPolygonGeo::center() const
{
    if( this->points_.isEmpty() )
        return NPointGeo();
    NPolygon _polygon = NRelativePoint::newCoord( *this,
                                   this->points_.first() ).polygonInRectangle();
    return NRelativePoint::newCoord( _polygon.center(),
                                      this->points_.first() );
}

NPolygonGeo NPolygonGeo::polygonCenter( const nreal &length,
                                          const nreal &width,
                                          const NPointGeo &center )
{
    return NRelativePoint::newCoord( NPolygon::polygonCenter( length, width,
                                                          NPoint() ), center );
}

NPolygonGeo NPolygonGeo::polygonWidth( const nreal &length,
                                         const nreal &width,
                                         const NAngle &course,
                                         const NPointGeo &point )
{
    NPolygonGeo _polygon;
    nreal _w = width / 2.0;
    NPointGeo _p = point.getNextGeoCoordinat( _w, course + NAngle::piOn2() );
    _polygon.points().append( _p.getNextGeoCoordinat( length, course ) );
    _polygon.points().append( _p );
    _p = point.getNextGeoCoordinat( _w, course - NAngle::piOn2() );
    _polygon.points().append( _p );
    _polygon.points().append( _p.getNextGeoCoordinat( length, course ) );
    return _polygon;
}

NPolygonGeo NPolygonGeo::polygonCenterCourse( const nreal &length,
                                                const nreal &width,
                                                const NAngle &course,
                                                const NPointGeo &center )
{
    NPolygonGeo _polygon;
    nreal _w = width / 2.0;
    nreal _l = length / 2.0;
    NPointGeo _p = center.getNextGeoCoordinat( _w,
                                               NAngle::piIn3On2() + course );
    _polygon.points().append( _p.getNextGeoCoordinat
                                             ( _l, course + NAngle::pi() ) );
    _polygon.points().append( _p.getNextGeoCoordinat( _l, course ) );
    _p = center.getNextGeoCoordinat( _w, NAngle::piOn2() + course );
    _polygon.points().append( _p.getNextGeoCoordinat( _l, course ) );
    _polygon.points().append( _p.getNextGeoCoordinat
                                             ( _l, course + NAngle::pi() ) );
    return _polygon;
}

NPolygonGeo &NPolygonGeo::operator=( const NPolygonGeo &polygonGeo )
{
    INPolygon::operator=( polygonGeo );
    return *this;
}

NPolygonGeo &NPolygonGeo::operator=( NPolygonGeo &&polygonGeo )
{
    INPolygon::operator=( std::move( polygonGeo ) );
    return *this;
}
