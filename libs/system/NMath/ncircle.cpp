#include "ncircle.h"
#include "nquadratic.h"

NCircle::NCircle( const NCircle &circle ) : INCircle(circle)
{

}

NCircle::NCircle( NCircle &&circle ) : INCircle(std::move(circle))
{

}

NCircle::~NCircle()
{

}

bool NCircle::pertain( const NPoint &point )
{
    nreal _x( point.x() - this->center_.x() );
    nreal _y( point.y() - this->center_.y() );
    return ( ( _x * _x + _y * _y ) < ( this->radius_ * this->radius_ ) );
}

QList<NPoint> NCircle::lineToCircle( const NLine &line )
{
    QList<NPoint> _points;
    nreal _A = line.c() + line.b() * this->center_.y();
    nreal _a = line.a() * line.a() + line.b() * line.b();
    nreal _b = nreal( 2.0 ) * ( line.a() * _A
                                    - line.b() * line.b() * this->center_.x() );
    nreal _c = line.b() * line.b() * ( this->center_.x() * this->center_.x()
                                    - this->radius_ * this->radius_ ) + _A * _A;
    NQuadratic _quadratic( _a, _b, _c );
    nreal _D = _quadratic.d();
    if( _D < 0.0 )
        return _points;
    if( _D.compare( 0.0 ) )
    {
        NPoint _point( _quadratic.rRoot().first, nreal() );
        _point.setY( ( -line.a() *  _point.x() - line.c() ) / line.b() );
        _points.append( _point );
    }
    else
    {
        auto _rRoot = _quadratic.rRoot();
        NPoint _point( _rRoot.first, nreal() );
        _point.setY( ( -line.a() * _point.x() - line.c() ) / line.b() );
        _points.append( _point );
        _point.setX( _rRoot.second );
        _point.setY( ( -line.a() * _point.x() - line.c() ) / line.b() );
        _points.append( _point );
    }

    return _points;
}

QList<NPoint> NCircle::sectionToCircle( const NLineSection &lineSection )
{
    QList<NPoint> _points = this->lineToCircle( lineSection );
    if( _points.isEmpty() )
        return _points;
    for( int i = 0; i < _points.count(); i++ )
    {
        if( !lineSection.pointToSection( _points[i] ) )
        {
            _points.removeAt( i );
            i--;
        }
    }
    return _points;
}

QList<NPoint> NCircle::circleToCircle( const NCircle &circle )
{
    QList<NPoint> _points;
    nreal _x = circle.center_.x() - this->center_.x();
    nreal _y = circle.center_.y() - this->center_.y();
    nreal _a = nreal( -2.0 ) * _x;
    nreal _b = nreal( -2.0 ) * _y;
    nreal _A = this->radius_ * this->radius_ + _x * _x + _y * _y
                 - circle.radius_ * circle.radius_;
    nreal _ya = ( _b * _b + _a * _a );
    if( _ya.compare( 0.0 ) )
        return _points;
    NQuadratic _quadratic( _ya, nreal( nreal( 2.0 ) * _A * _a ),
                            _A * _A - _b * _b * this->radius_ * this->radius_ );
    if( _quadratic.d() < 0.0 )
        return _points;
    if( _quadratic.d().compare( 0.0 ) )
    {
        NPoint _point( _quadratic.rRoot().first, nreal() );
        _point.setY( -( _A + _a * _point.x() ) / _b + this->center_.y() );
        _point.setX( _point.x() + this->center_.x() );
        _points.append( _point );
    }
    else
    {
        auto _rRoot = _quadratic.rRoot();
        NPoint _point( _rRoot.first, nreal() );
        _point.setY( -( _A + _a * _point.x() ) / _b + this->center_.y() );
        _point.setX( _point.x() + this->center_.x() );
        _points.append( _point );

        _point.setX( _rRoot.second );
        _point.setY( -( _A + _a * _point.x() ) / _b + this->center_.y() );
        _point.setX( _point.x() + this->center_.x() );
        _points.append( _point );
    }
    return _points;
}

NLineSection NCircle::scalingTangentOut( const NCircle &circle1,
                                           const NCircle &circle2, int direct )
{
    if( direct != -1 )
        direct = 1;
    NLineSection _lineSection( NPoint(),
                              NPoint( nreal::maxValue, nreal::maxValue ) );
    NAngle _angle;
    nreal _dradius = circle1.radius_ - circle2.radius_;
    nreal _len = circle1.center_.distance( circle2.center_  );
    if( ( circle1.radius_ - circle2.radius_ ).abs() > _len )
        return _lineSection;
    if( _dradius < nreal() )
        _angle = NPoint::angle( circle1.center_, circle2.center_ );
    else
        _angle = NPoint::angle( circle2.center_, circle1.center_ );
    NAngle _curse = _angle +
                 ( NAngle::pi() - NAngle().acos( _dradius.abs() / _len ) )
                        * nreal( direct );

    _lineSection.setStart( NPoint::newPoint( _curse, circle1.radius_,
                                              circle1.center_ ) );
    _lineSection.setStop( NPoint::newPoint( _curse, circle2.radius_,
                                             circle2.center_ ) );
    return _lineSection;
}

NLineSection NCircle::scalingTangentInboard( const NCircle &circle1,
                                           const NCircle &circle2, int direct )
{
    if( direct != -1 )
        direct = 1;
    NLineSection _lineSection( NPoint(),
                              NPoint( nreal::maxValue, nreal::maxValue ) );
    NAngle _course;
    nreal _len = circle1.center_.distance( circle2.center_ );
    nreal _sumRadius = circle1.radius_ + circle2.radius_;
    if( _sumRadius > _len )
        return _lineSection;
    if( circle1.radius_ > circle2.radius_ )
    {
        _course = NPoint::angle( circle2.center_, circle1.center_ );
        NAngle _angle = _course +
                        ( NAngle::pi() - NAngle().acos( _sumRadius / _len ) )
                            * nreal( direct );
        _lineSection.setStart( NPoint::newPoint( _angle, circle1.radius_,
                                                  circle1.center_ ) );
        _lineSection.setStop( NPoint::newPoint( _angle + NAngle::pi(),
                                           circle2.radius_, circle2.center_ ) );
    }
    else
    {
        _course = NPoint::angle( circle1.center_, circle2.center_ );
        NAngle _angle = _course +
                        ( NAngle::pi() - NAngle().acos( _sumRadius / _len ) )
                                * nreal( direct );

        _lineSection.setStart( NPoint::newPoint( _angle + NAngle::pi().r(),
                                           circle1.radius_, circle1.center_ ) );
        _lineSection.setStop( NPoint::newPoint( _angle, circle2.radius_,
                                                 circle2.center_ ) );
    }
    return _lineSection;
}

QPair<NPoint, NPoint> NCircle::centrCircleInLine
                ( const NLineSection &lineSection, const NPoint &pointOnLine,
                  const double &radius )
{
    nreal _radius( 1.0 );
    if( nreal() < radius )
        _radius = radius;
    QPair<NPoint, NPoint> _pairCenter;
    NAngle _angle = NPoint::angle( lineSection.start(), lineSection.stop() );
    _pairCenter.first = NPoint::newPoint( _angle - NAngle::piOn2(),
                                           _radius, pointOnLine );
    _pairCenter.second = NPoint::newPoint( _angle + NAngle::piOn2(),
                                            _radius, pointOnLine );
    return _pairCenter;
}

NCircle &NCircle::operator=( const NCircle &circle )
{
    INCircle::operator=( circle );
    return *this;
}

NCircle &NCircle::operator=( NCircle &&circle )
{
    INCircle::operator=( std::move( circle ) );
    return *this;
}
