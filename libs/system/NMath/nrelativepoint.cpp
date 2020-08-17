#include "nrelativepoint.h"

NRelativePoint::NRelativePoint( const NPointGeo &tc, const NPointGeo &rm )
{
    this->tc_ = tc;
    this->rm_ = rm;
    auto _polar = NPointGeo::getPolarToTc( this->rm_, this->tc_ );
    this->cc_ = NPoint::newPoint( _polar.omnibearing(), _polar.range() );
}

NRelativePoint::NRelativePoint( const NPoint &cc, const NPointGeo &rm )
{
    this->cc_ = cc;
    this->rm_ = rm;
    this->tc_ = this->rm_.getNextGeoCoordinat( this->cc_.distance(),
                                               this->cc_.angleFromPoint() );
}

NRelativePoint::NRelativePoint( const NPointGeo &tc, const NPoint &cc )
{
    this->tc_ = tc;
    this->cc_ = cc;
    this->rm_ = NRelativePoint::randingMark( this->tc_, this->cc_ );
}

NRelativePoint::NRelativePoint( const NRelativePoint &NRelativePoint )
{
    this->tc_ = NRelativePoint.tc_;
    this->rm_ = NRelativePoint.rm_;
    this->cc_ = NRelativePoint.cc_;
}

NRelativePoint::NRelativePoint( NRelativePoint &&NRelativePoint )
{
    this->tc_ = std::move( NRelativePoint.tc_ );
    this->rm_ = std::move( NRelativePoint.rm_ );
    this->cc_ = std::move( NRelativePoint.cc_ );
}

NRelativePoint::~NRelativePoint()
{

}

void NRelativePoint::setCc( const NPoint &cc )
{
    this->cc_ = cc;
    this->tc_ =  this->rm_.getNextGeoCoordinat( this->cc_.distance(),
                                                this->cc_.angleFromPoint() );
}

void NRelativePoint::setTc( const NPointGeo &tc )
{
    this->tc_ = tc;
    auto _polar = NPointGeo::getPolarToTc( this->rm_, this->tc_ );
    this->cc_ = NPoint::newPoint( _polar.omnibearing(), _polar.range() );
}

void NRelativePoint::setRm( const NPointGeo &rm )
{
    this->rm_ = rm;
    auto _polar = NPointGeo::getPolarToTc( this->rm_, this->tc_ );
    this->cc_ = NPoint::newPoint( _polar.omnibearing(), _polar.range() );
}

NPointGeo NRelativePoint::randingMark( const NPointGeo &pointGeo,
                                         const NPoint &point )
{
    return pointGeo.getNextGeoCoordinat( point.distance(),
                                     point.angleFromPoint() + NAngle::pi() );
}

NPoint NRelativePoint::newCoord( const NPointGeo &point,
                                   const NPointGeo &rangingMark )
{
    NPoint _point;
    NPolarCoordinat _polar = NPointGeo::getPolarToTc( rangingMark, point );
    _point.setCoordinate( _polar.omnibearing(), _polar.range() );
    return _point;
}

NPointGeo NRelativePoint::newCoord( const NPoint &point,
                                      const NPointGeo &rangingMark )
{
    return rangingMark.getNextGeoCoordinat( point.distance(),
                                            point.angleFromPoint() );
}

NLineGeo NRelativePoint::newCoord( const NLineSection &line,
                                     const NPointGeo &rangingMark )
{
    return NLineGeo( NRelativePoint::newCoord( line.start(), rangingMark ),
                      NRelativePoint::newCoord( line.stop(), rangingMark ) );
}

NLineSection NRelativePoint::newCoord( const NLineGeo &line,
                                         const NPointGeo &rangingMark )
{
    return NLineSection( NRelativePoint::newCoord( line.start(),
         rangingMark ), NRelativePoint::newCoord( line.stop(), rangingMark ) );
}

NArcGeo NRelativePoint::newCoord( const NArc &arc,
                                    const NPointGeo &rangingMark )
{
    return NArcGeo( arc, rangingMark );
}

NArc NRelativePoint::newCoord( const NArcGeo &arc,
                                 const NPointGeo &rangingMark )
{
    return NArc( NRelativePoint::newCoord( arc.center(), rangingMark ),
                arc.radius(), arc.angleStart(), arc.angleStop(), arc.direct() );
}

QList<NPointGeo> NRelativePoint::newCoord( const QList<NPoint> &listPoint,
                                             const NPointGeo &rangingMark )
{
    QList<NPointGeo> _listPointGeo;
    int _count = listPoint.count();
    for( int i = 0; i < _count; i++ )
        _listPointGeo.append( rangingMark.getNextGeoCoordinat
                   ( listPoint[i].distance(), listPoint[i].angleFromPoint() ) );
    return _listPointGeo;
}

QList<NPoint> NRelativePoint::newCoord(const QList<NPointGeo> &listPointGeo,
                                         const NPointGeo &rangingMark )
{
    QList<NPoint> _listPoint;
    int _count = listPointGeo.count();
    for( int i = 0; i < _count; i++ )
        _listPoint.append( NRelativePoint::newCoord( listPointGeo[i],
                                                      rangingMark ) );
    return _listPoint;
}

QList<NLineGeo> NRelativePoint::newCoord
         ( const QList<NLineSection> &listLine, const NPointGeo &rangingMark )
{
    QList<NLineGeo> _listLine;
    int _count = listLine.count();
    for( int i = 0; i < _count; i++ )
    {
        NLineGeo _line( rangingMark.getNextGeoCoordinat
       ( listLine[i].start().distance(), listLine[i].start().angleFromPoint() ),
                         rangingMark.getNextGeoCoordinat
       ( listLine[i].stop().distance(), listLine[i].stop().angleFromPoint() ) );
        _listLine.append( _line );
    }
    return _listLine;
}

NPolygonGeo NRelativePoint::newCoord( const NPolygon &polygon,
                                        const NPointGeo &rangingMark )
{
    NPolygonGeo _polygon;
    int _count = polygon.points().count();
    for( int i = 0; i < _count; i++ )
        _polygon.points().append( rangingMark.getNextGeoCoordinat
     ( polygon.points()[i].distance(), polygon.points()[i].angleFromPoint() ) );
    return _polygon;
}

NPolygon NRelativePoint::newCoord( const NPolygonGeo &polygon,
                                     const NPointGeo &rangingMark )
{
    NPolygon _polygon;
    int _count = polygon.points().count();
    for( int i = 0; i < _count; i++ )
        _polygon.points().append(
                NRelativePoint::newCoord( polygon.points()[i], rangingMark ) );
    return _polygon;
}

QList<NPolygon> NRelativePoint::newCoord( const QList<NPolygonGeo> &polygon,
                                            const NPointGeo &rangingMark )
{
    QList<NPolygon> _listPolygon;
    int _count = polygon.count();
    for( int i = 0; i < _count; i++ )
        _listPolygon.append(
                        NRelativePoint::newCoord( polygon[i], rangingMark ) );
    return _listPolygon;
}

NRelativePoint &NRelativePoint::operator=
                                      ( const NRelativePoint &NRelativePoint )
{
    this->tc_ = NRelativePoint.tc_;
    this->rm_ = NRelativePoint.rm_;
    this->cc_ = NRelativePoint.cc_;
    return *this;
}

NRelativePoint &NRelativePoint::operator=( NRelativePoint &&NRelativePoint )
{
    this->tc_ = std::move( NRelativePoint.tc_ );
    this->rm_ = std::move( NRelativePoint.rm_ );
    this->cc_ = std::move( NRelativePoint.cc_ );
    return *this;
}
