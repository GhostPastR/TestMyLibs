#include "mprelativepoint.h"

MpRelativePoint::MpRelativePoint( const MpPointGeo &tc, const MpPointGeo &rm )
{
    this->tc_ = tc;
    this->rm_ = rm;
    auto _polar = MpPointGeo::getPolarToTc( this->rm_, this->tc_ );
    this->cc_ = MpPoint::newPoint( _polar.omnibearing(), _polar.range() );
}

MpRelativePoint::MpRelativePoint( const MpPoint &cc, const MpPointGeo &rm )
{
    this->cc_ = cc;
    this->rm_ = rm;
    this->tc_ = this->rm_.getNextGeoCoordinat( this->cc_.distance(),
                                               this->cc_.angleFromPoint() );
}

MpRelativePoint::MpRelativePoint( const MpPointGeo &tc, const MpPoint &cc )
{
    this->tc_ = tc;
    this->cc_ = cc;
    this->rm_ = MpRelativePoint::randingMark( this->tc_, this->cc_ );
}

MpRelativePoint::MpRelativePoint( const MpRelativePoint &mpRelativePoint )
{
    this->tc_ = mpRelativePoint.tc_;
    this->rm_ = mpRelativePoint.rm_;
    this->cc_ = mpRelativePoint.cc_;
}

MpRelativePoint::MpRelativePoint( MpRelativePoint &&mpRelativePoint )
{
    this->tc_ = std::move( mpRelativePoint.tc_ );
    this->rm_ = std::move( mpRelativePoint.rm_ );
    this->cc_ = std::move( mpRelativePoint.cc_ );
}

MpRelativePoint::~MpRelativePoint()
{

}

void MpRelativePoint::setCc( const MpPoint &cc )
{
    this->cc_ = cc;
    this->tc_ =  this->rm_.getNextGeoCoordinat( this->cc_.distance(),
                                                this->cc_.angleFromPoint() );
}

void MpRelativePoint::setTc( const MpPointGeo &tc )
{
    this->tc_ = tc;
    auto _polar = MpPointGeo::getPolarToTc( this->rm_, this->tc_ );
    this->cc_ = MpPoint::newPoint( _polar.omnibearing(), _polar.range() );
}

void MpRelativePoint::setRm( const MpPointGeo &rm )
{
    this->rm_ = rm;
    auto _polar = MpPointGeo::getPolarToTc( this->rm_, this->tc_ );
    this->cc_ = MpPoint::newPoint( _polar.omnibearing(), _polar.range() );
}

MpPointGeo MpRelativePoint::randingMark( const MpPointGeo &pointGeo,
                                         const MpPoint &point )
{
    return pointGeo.getNextGeoCoordinat( point.distance(),
                                     point.angleFromPoint() + MpAngle::pi() );
}

MpPoint MpRelativePoint::newCoord( const MpPointGeo &point,
                                   const MpPointGeo &rangingMark )
{
    MpPoint _point;
    MpPolarCoordinat _polar = MpPointGeo::getPolarToTc( rangingMark, point );
    _point.setCoordinate( _polar.omnibearing(), _polar.range() );
    return _point;
}

MpPointGeo MpRelativePoint::newCoord( const MpPoint &point,
                                      const MpPointGeo &rangingMark )
{
    return rangingMark.getNextGeoCoordinat( point.distance(),
                                            point.angleFromPoint() );
}

MpLineGeo MpRelativePoint::newCoord( const MpLineSection &line,
                                     const MpPointGeo &rangingMark )
{
    return MpLineGeo( MpRelativePoint::newCoord( line.start(), rangingMark ),
                      MpRelativePoint::newCoord( line.stop(), rangingMark ) );
}

MpLineSection MpRelativePoint::newCoord( const MpLineGeo &line,
                                         const MpPointGeo &rangingMark )
{
    return MpLineSection( MpRelativePoint::newCoord( line.start(),
         rangingMark ), MpRelativePoint::newCoord( line.stop(), rangingMark ) );
}

MpArcGeo MpRelativePoint::newCoord( const MpArc &arc,
                                    const MpPointGeo &rangingMark )
{
    return MpArcGeo( arc, rangingMark );
}

MpArc MpRelativePoint::newCoord( const MpArcGeo &arc,
                                 const MpPointGeo &rangingMark )
{
    return MpArc( MpRelativePoint::newCoord( arc.center(), rangingMark ),
                arc.radius(), arc.angleStart(), arc.angleStop(), arc.direct() );
}

QList<MpPointGeo> MpRelativePoint::newCoord( const QList<MpPoint> &listPoint,
                                             const MpPointGeo &rangingMark )
{
    QList<MpPointGeo> _listPointGeo;
    int _count = listPoint.count();
    for( int i = 0; i < _count; i++ )
        _listPointGeo.append( rangingMark.getNextGeoCoordinat
                   ( listPoint[i].distance(), listPoint[i].angleFromPoint() ) );
    return _listPointGeo;
}

QList<MpPoint> MpRelativePoint::newCoord(const QList<MpPointGeo> &listPointGeo,
                                         const MpPointGeo &rangingMark )
{
    QList<MpPoint> _listPoint;
    int _count = listPointGeo.count();
    for( int i = 0; i < _count; i++ )
        _listPoint.append( MpRelativePoint::newCoord( listPointGeo[i],
                                                      rangingMark ) );
    return _listPoint;
}

QList<MpLineGeo> MpRelativePoint::newCoord
         ( const QList<MpLineSection> &listLine, const MpPointGeo &rangingMark )
{
    QList<MpLineGeo> _listLine;
    int _count = listLine.count();
    for( int i = 0; i < _count; i++ )
    {
        MpLineGeo _line( rangingMark.getNextGeoCoordinat
       ( listLine[i].start().distance(), listLine[i].start().angleFromPoint() ),
                         rangingMark.getNextGeoCoordinat
       ( listLine[i].stop().distance(), listLine[i].stop().angleFromPoint() ) );
        _listLine.append( _line );
    }
    return _listLine;
}

MpPolygonGeo MpRelativePoint::newCoord( const MpPolygon &polygon,
                                        const MpPointGeo &rangingMark )
{
    MpPolygonGeo _polygon;
    int _count = polygon.points().count();
    for( int i = 0; i < _count; i++ )
        _polygon.points().append( rangingMark.getNextGeoCoordinat
     ( polygon.points()[i].distance(), polygon.points()[i].angleFromPoint() ) );
    return _polygon;
}

MpPolygon MpRelativePoint::newCoord( const MpPolygonGeo &polygon,
                                     const MpPointGeo &rangingMark )
{
    MpPolygon _polygon;
    int _count = polygon.points().count();
    for( int i = 0; i < _count; i++ )
        _polygon.points().append(
                MpRelativePoint::newCoord( polygon.points()[i], rangingMark ) );
    return _polygon;
}

QList<MpPolygon> MpRelativePoint::newCoord( const QList<MpPolygonGeo> &polygon,
                                            const MpPointGeo &rangingMark )
{
    QList<MpPolygon> _listPolygon;
    int _count = polygon.count();
    for( int i = 0; i < _count; i++ )
        _listPolygon.append(
                        MpRelativePoint::newCoord( polygon[i], rangingMark ) );
    return _listPolygon;
}

MpRelativePoint &MpRelativePoint::operator=
                                      ( const MpRelativePoint &mpRelativePoint )
{
    this->tc_ = mpRelativePoint.tc_;
    this->rm_ = mpRelativePoint.rm_;
    this->cc_ = mpRelativePoint.cc_;
    return *this;
}

MpRelativePoint &MpRelativePoint::operator=( MpRelativePoint &&mpRelativePoint )
{
    this->tc_ = std::move( mpRelativePoint.tc_ );
    this->rm_ = std::move( mpRelativePoint.rm_ );
    this->cc_ = std::move( mpRelativePoint.cc_ );
    return *this;
}
