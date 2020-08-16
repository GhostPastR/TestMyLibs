#include "mpcircle.h"
#include "mpquadratic.h"

MpCircle::MpCircle( const MpCircle &circle ) : IMpCircle(circle)
{

}

MpCircle::MpCircle( MpCircle &&circle ) : IMpCircle(std::move(circle))
{

}

MpCircle::~MpCircle()
{

}

bool MpCircle::pertain( const MpPoint &point )
{
    nreal _x( point.x() - this->center_.x() );
    nreal _y( point.y() - this->center_.y() );
    return ( ( _x * _x + _y * _y ) < ( this->radius_ * this->radius_ ) );
}

QList<MpPoint> MpCircle::lineToCircle( const MpLine &line )
{
    QList<MpPoint> _points;
    nreal _A = line.c() + line.b() * this->center_.y();
    nreal _a = line.a() * line.a() + line.b() * line.b();
    nreal _b = nreal( 2.0 ) * ( line.a() * _A
                                    - line.b() * line.b() * this->center_.x() );
    nreal _c = line.b() * line.b() * ( this->center_.x() * this->center_.x()
                                    - this->radius_ * this->radius_ ) + _A * _A;
    MpQuadratic _quadratic( _a, _b, _c );
    nreal _D = _quadratic.d();
    if( _D < 0.0 )
        return _points;
    if( _D.compare( 0.0 ) )
    {
        MpPoint _point( _quadratic.rRoot().first, nreal() );
        _point.setY( ( -line.a() *  _point.x() - line.c() ) / line.b() );
        _points.append( _point );
    }
    else
    {
        auto _rRoot = _quadratic.rRoot();
        MpPoint _point( _rRoot.first, nreal() );
        _point.setY( ( -line.a() * _point.x() - line.c() ) / line.b() );
        _points.append( _point );
        _point.setX( _rRoot.second );
        _point.setY( ( -line.a() * _point.x() - line.c() ) / line.b() );
        _points.append( _point );
    }

    return _points;
}

QList<MpPoint> MpCircle::sectionToCircle( const MpLineSection &lineSection )
{
    QList<MpPoint> _points = this->lineToCircle( lineSection );
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

QList<MpPoint> MpCircle::circleToCircle( const MpCircle &circle )
{
    QList<MpPoint> _points;
    nreal _x = circle.center_.x() - this->center_.x();
    nreal _y = circle.center_.y() - this->center_.y();
    nreal _a = nreal( -2.0 ) * _x;
    nreal _b = nreal( -2.0 ) * _y;
    nreal _A = this->radius_ * this->radius_ + _x * _x + _y * _y
                 - circle.radius_ * circle.radius_;
    nreal _ya = ( _b * _b + _a * _a );
    if( _ya.compare( 0.0 ) )
        return _points;
    MpQuadratic _quadratic( _ya, nreal( nreal( 2.0 ) * _A * _a ),
                            _A * _A - _b * _b * this->radius_ * this->radius_ );
    if( _quadratic.d() < 0.0 )
        return _points;
    if( _quadratic.d().compare( 0.0 ) )
    {
        MpPoint _point( _quadratic.rRoot().first, nreal() );
        _point.setY( -( _A + _a * _point.x() ) / _b + this->center_.y() );
        _point.setX( _point.x() + this->center_.x() );
        _points.append( _point );
    }
    else
    {
        auto _rRoot = _quadratic.rRoot();
        MpPoint _point( _rRoot.first, nreal() );
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

MpLineSection MpCircle::scalingTangentOut( const MpCircle &circle1,
                                           const MpCircle &circle2, int direct )
{
    if( direct != -1 )
        direct = 1;
    MpLineSection _lineSection( MpPoint(),
                              MpPoint( nreal::maxValue, nreal::maxValue ) );
    MpAngle _angle;
    nreal _dradius = circle1.radius_ - circle2.radius_;
    nreal _len = circle1.center_.distance( circle2.center_  );
    if( ( circle1.radius_ - circle2.radius_ ).abs() > _len )
        return _lineSection;
    if( _dradius < nreal() )
        _angle = MpPoint::angle( circle1.center_, circle2.center_ );
    else
        _angle = MpPoint::angle( circle2.center_, circle1.center_ );
    MpAngle _curse = _angle +
                 ( MpAngle::pi() - MpAngle().acos( _dradius.abs() / _len ) )
                        * nreal( direct );

    _lineSection.setStart( MpPoint::newPoint( _curse, circle1.radius_,
                                              circle1.center_ ) );
    _lineSection.setStop( MpPoint::newPoint( _curse, circle2.radius_,
                                             circle2.center_ ) );
    return _lineSection;
}

MpLineSection MpCircle::scalingTangentInboard( const MpCircle &circle1,
                                           const MpCircle &circle2, int direct )
{
    if( direct != -1 )
        direct = 1;
    MpLineSection _lineSection( MpPoint(),
                              MpPoint( nreal::maxValue, nreal::maxValue ) );
    MpAngle _course;
    nreal _len = circle1.center_.distance( circle2.center_ );
    nreal _sumRadius = circle1.radius_ + circle2.radius_;
    if( _sumRadius > _len )
        return _lineSection;
    if( circle1.radius_ > circle2.radius_ )
    {
        _course = MpPoint::angle( circle2.center_, circle1.center_ );
        MpAngle _angle = _course +
                        ( MpAngle::pi() - MpAngle().acos( _sumRadius / _len ) )
                            * nreal( direct );
        _lineSection.setStart( MpPoint::newPoint( _angle, circle1.radius_,
                                                  circle1.center_ ) );
        _lineSection.setStop( MpPoint::newPoint( _angle + MpAngle::pi(),
                                           circle2.radius_, circle2.center_ ) );
    }
    else
    {
        _course = MpPoint::angle( circle1.center_, circle2.center_ );
        MpAngle _angle = _course +
                        ( MpAngle::pi() - MpAngle().acos( _sumRadius / _len ) )
                                * nreal( direct );

        _lineSection.setStart( MpPoint::newPoint( _angle + MpAngle::pi().r(),
                                           circle1.radius_, circle1.center_ ) );
        _lineSection.setStop( MpPoint::newPoint( _angle, circle2.radius_,
                                                 circle2.center_ ) );
    }
    return _lineSection;
}

QPair<MpPoint, MpPoint> MpCircle::centrCircleInLine
                ( const MpLineSection &lineSection, const MpPoint &pointOnLine,
                  const double &radius )
{
    nreal _radius( 1.0 );
    if( nreal() < radius )
        _radius = radius;
    QPair<MpPoint, MpPoint> _pairCenter;
    MpAngle _angle = MpPoint::angle( lineSection.start(), lineSection.stop() );
    _pairCenter.first = MpPoint::newPoint( _angle - MpAngle::piOn2(),
                                           _radius, pointOnLine );
    _pairCenter.second = MpPoint::newPoint( _angle + MpAngle::piOn2(),
                                            _radius, pointOnLine );
    return _pairCenter;
}

MpCircle &MpCircle::operator=( const MpCircle &circle )
{
    IMpCircle::operator=( circle );
    return *this;
}

MpCircle &MpCircle::operator=( MpCircle &&circle )
{
    IMpCircle::operator=( std::move( circle ) );
    return *this;
}
