#include "mppolygongeo.h"
#include "mprelativepoint.h"

MpPolygonGeo::MpPolygonGeo( const MpPolygonGeo &polygonGeo )
    : IMpPolygon(polygonGeo)
{

}

MpPolygonGeo::MpPolygonGeo( MpPolygonGeo &&polygonGeo )
    : IMpPolygon(polygonGeo)
{

}

MpPolygonGeo::~MpPolygonGeo()
{

}

nreal MpPolygonGeo::length() const
{
    if( this->points_.count() < 3 )
        return nreal();
    return this->points().first().distance( this->points()[1] );
}

nreal MpPolygonGeo::width() const
{
    if( this->points_.count() < 3  )
        return nreal();
    return this->points()[1].distance( this->points()[2] );
}

MpAngle MpPolygonGeo::lengthCourse() const
{
    if( this->points_.count() < 3  )
        return nreal();
    return this->points().first().angle( this->points()[1] );
}

MpPolygonGeo &MpPolygonGeo::setPolygon( const MpPointGeo &center,
                                    const double &length , const double &width )
{
    this->points_.clear();
    nreal _dl( length / 2.0 );
    nreal _dw( width / 2.0 );
    this->points_.append( MpRelativePoint::newCoord( MpPoint( -_dw, -_dl ),
                                                                    center ) );
    this->points_.append( MpRelativePoint::newCoord( MpPoint( -_dw, _dl ),
                                                                    center ) );
    this->points_.append( MpRelativePoint::newCoord( MpPoint( _dw, _dl ),
                                                                    center ) );
    this->points_.append( MpRelativePoint::newCoord( MpPoint( _dw, -_dl ),
                                                                    center ) );
    return *this;
}

MpPolygonGeo MpPolygonGeo::polygonInRectangle() const
{
    if( this->points_.isEmpty() )
        return MpPolygonGeo();
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
        MpPolygonGeo _polygon;
        _polygon.points_.append( MpPointGeo( _minX, _maxY ) );
        _polygon.points_.append( MpPointGeo( _maxX, _maxY ) );
        _polygon.points_.append( MpPointGeo( _maxX, _minY ) );
        _polygon.points_.append( MpPointGeo( _minX, _minY ) );
        return _polygon;
    }
}

MpPointGeo MpPolygonGeo::leftUp() const
{
    if( this->points_.isEmpty() )
        return MpPointGeo();
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
        return MpPointGeo( maxLat, minLong );
    }
}

MpPointGeo MpPolygonGeo::rightDown() const
{
    if( this->points_.isEmpty() )
        return MpPointGeo();
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
        return MpPointGeo( minLat, maxLong );
    }
}

MpPointGeo MpPolygonGeo::pointCoupling( const MpPointGeo &pointGeo ) const
{
    return MpRelativePoint::newCoord(
                                    MpRelativePoint::newCoord( *this, pointGeo )
                                        .pointCoupling( MpPoint() ), pointGeo );
}

MpPolygonGeo MpPolygonGeo::scalePolygon( const nreal &distance ) const
{
    if( this->points_.isEmpty() )
        return MpPolygonGeo();
    MpPolygon _p = MpRelativePoint::newCoord( *this, this->points_.first() );
    return MpRelativePoint::newCoord( _p.scalePolygon( distance ),
                                      this->points_.first() );
}

bool MpPolygonGeo::pointAppertainPolygon( const MpPointGeo &pointGeo ) const
{
    return MpRelativePoint::newCoord( *this, pointGeo )
                                            .pointAppertainPolygon( MpPoint() );
}

bool MpPolygonGeo::polygonAppertainPolygon( const MpPolygonGeo &polygon ) const
{
    MpPolygon _p = MpRelativePoint::newCoord( *this, this->points_.first() );
    return _p.polugAppertainPartPolug( MpRelativePoint::newCoord( polygon,
                                                      this->points_.first() ) );
}

MpPointGeo MpPolygonGeo::center() const
{
    if( this->points_.isEmpty() )
        return MpPointGeo();
    MpPolygon _polygon = MpRelativePoint::newCoord( *this,
                                   this->points_.first() ).polygonInRectangle();
    return MpRelativePoint::newCoord( _polygon.center(),
                                      this->points_.first() );
}

MpPolygonGeo MpPolygonGeo::polygonCenter( const nreal &length,
                                          const nreal &width,
                                          const MpPointGeo &center )
{
    return MpRelativePoint::newCoord( MpPolygon::polygonCenter( length, width,
                                                          MpPoint() ), center );
}

MpPolygonGeo MpPolygonGeo::polygonWidth( const nreal &length,
                                         const nreal &width,
                                         const MpAngle &course,
                                         const MpPointGeo &point )
{
    MpPolygonGeo _polygon;
    nreal _w = width / 2.0;
    MpPointGeo _p = point.getNextGeoCoordinat( _w, course + MpAngle::piOn2() );
    _polygon.points().append( _p.getNextGeoCoordinat( length, course ) );
    _polygon.points().append( _p );
    _p = point.getNextGeoCoordinat( _w, course - MpAngle::piOn2() );
    _polygon.points().append( _p );
    _polygon.points().append( _p.getNextGeoCoordinat( length, course ) );
    return _polygon;
}

MpPolygonGeo MpPolygonGeo::polygonCenterCourse( const nreal &length,
                                                const nreal &width,
                                                const MpAngle &course,
                                                const MpPointGeo &center )
{
    MpPolygonGeo _polygon;
    nreal _w = width / 2.0;
    nreal _l = length / 2.0;
    MpPointGeo _p = center.getNextGeoCoordinat( _w,
                                               MpAngle::piIn3On2() + course );
    _polygon.points().append( _p.getNextGeoCoordinat
                                             ( _l, course + MpAngle::pi() ) );
    _polygon.points().append( _p.getNextGeoCoordinat( _l, course ) );
    _p = center.getNextGeoCoordinat( _w, MpAngle::piOn2() + course );
    _polygon.points().append( _p.getNextGeoCoordinat( _l, course ) );
    _polygon.points().append( _p.getNextGeoCoordinat
                                             ( _l, course + MpAngle::pi() ) );
    return _polygon;
}

MpPolygonGeo &MpPolygonGeo::operator=( const MpPolygonGeo &polygonGeo )
{
    IMpPolygon::operator=( polygonGeo );
    return *this;
}

MpPolygonGeo &MpPolygonGeo::operator=( MpPolygonGeo &&polygonGeo )
{
    IMpPolygon::operator=( std::move( polygonGeo ) );
    return *this;
}
