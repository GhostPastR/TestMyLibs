#include "mppolygon.h"
#include <vector>

MpPolygon::MpPolygon( const MpPolygon &polygon )
    : IMpPolygon(polygon)
{

}

MpPolygon::MpPolygon( MpPolygon &&polygon )
    : IMpPolygon( std::move( polygon) )
{

}

MpPolygon::~MpPolygon()
{

}

void MpPolygon::compact( const nreal &distans )
{
    for( int i = 1; i < this->points().count(); i++ )
    {
        if( ( ( this->points()[i - 1].x() - this->points()[i].x() ).abs()
                                                                < distans ) &&
            ( ( this->points()[i - 1].y() - this->points()[i].y() ).abs()
                                                                < distans ) )
        {
            this->points().removeAt( i );
            i--;
        }
    }
}

QList<MpLineSection> MpPolygon::getLine() const
{
    QList<MpLineSection> _listLine;
    int _count = this->points_.count() - 1;
    for( int i = 0; i < _count; i++ )
        _listLine.append( std::move( MpLineSection( this->points_[i],
                                                    this->points_[i + 1] ) ) );
    if( !this->points_.isEmpty() )
        _listLine.append( std::move( MpLineSection( this->points_.last(),
                                                    this->points_.first() ) ) );
    return _listLine;
}

bool MpPolygon::pointAppertainPolygon( const MpPoint &point ) const
{
    size_t _count = static_cast<size_t>( this->points_.count() );
    std::vector<MpPoint> _pointMas;
    for( int i = 0; i < this->points_.count(); i++ )
        _pointMas.push_back( this->points_[i] );
    if( _count < 2 )
        return false;
    MpLineSection _halfLine( point, MpPoint( point.x() + 1.0, point.y() ) );
    int crosscut = 0;
    for( size_t i = 0; i < _count; i++ )
    {
        if( point.x().compare( _pointMas[i].x() )
                && point.y().compare( _pointMas[i].y() ) )
            return true;
        if( _halfLine.getValueFunction( _pointMas[i] ).compare( nreal() ) )
            _pointMas[i].setY( _pointMas[i].y() - 0.1 );
        MpLineSection _line;
        if( i == 0 )
        {
            if( point.x().compare( _pointMas[_count - 1].x() )
                    && point.y().compare( _pointMas[_count - 1].y() ) )
                return true;
            if( _halfLine.getValueFunction( _pointMas[_count - 1] )
                    .compare( 0.0 ) )
                _pointMas[_count - 1].setY( _pointMas[_count - 1].y() - 0.1 );
            _line.setLine( _pointMas[_count - 1], _pointMas[i] );
            MpPoint _m = _halfLine.intersectionLine( _line );
            if( ( _m.x() > point.x() ) && ( _line.pointToSection( _m ) ) )
               crosscut++;
        }
        else
        {
            _line.setLine( _pointMas[i - 1], _pointMas[i] );
            MpPoint _m = _halfLine.intersectionLine( _line );
            if( ( _m.x() > point.x() ) && ( _line.pointToSection( _m ) ) )
                crosscut++;
        }
    }
    if( ( crosscut % 2 ) == 1 )
        return true;
    return false;
}

bool MpPolygon::polygonAppertainPolygon( const MpPolygon &polygon ) const
{
    MpPolygon _polygon = polygon;
    QList<MpLineSection> _listLine_1 = this->getLine();
    QList<MpLineSection> _listLine_2 = _polygon.getLine();
    int _count_1 = _listLine_1.count();
    int _count_2 = _listLine_2.count();
    for( int i = 0; i < _count_1; i++ )
        for( int j = 0; j < _count_2; j++ )
            if( _listLine_1[i].sectionOnSection( _listLine_2[j] ) )
                return true;
    return false;
}

bool MpPolygon::polygonAppertainSection( const MpLineSection &section ) const
{
    QList<MpLineSection> _listLine = this->getLine();
    MpLineSection _section = section;
    int _count = _listLine.count();
    for( int i = 0; i < _count; i++ )
    {
        MpPoint _point = _listLine[i].intersectionLine( section );

        if( !( _point.compare( _section.start() )
               || _point.compare( _section.stop() )
               || _point.compare( _listLine[i].start() )
               || _point.compare( _listLine[i].stop() ) ) )
        {
            if( _section.pointToSection( _point )
                    && _listLine[i].pointToSection( _point ) )
                return false;
        }
    }
    return ( this->pointAppertainPolygon( section.start() )
             && this->pointAppertainPolygon( section.stop() ) );
}

QList<MpPoint> MpPolygon::polygonApertainLine
                                          ( const MpLineSection &section ) const
{
    QList<MpPoint> _points;
    QList<MpLineSection> _line = this->getLine();
    for( int i = 0; i < _line.count(); i++ )
    {
        MpPoint _point = section.intersectionLine( _line.at( i ) );
        if( _line.at( i ).pointToSection( _point ) )
            _points.append( _point );
    }
    return _points;
}
bool MpPolygon::polygonApertainLineSection( const MpLineSection &section ) const
{
    QList<MpLineSection> _listLine = this->getLine();
    MpLineSection _section = section;
    int _count = _listLine.count();
    for( int i = 0; i < _count; i++ )
    {
        MpPoint _point = _listLine[i].intersectionLine( section );
        if( _section.pointToSection( _point )
                && _listLine[i].pointToSection( _point ) )
            return true;
    }
    return ( this->pointAppertainPolygon( section.start() )
             && this->pointAppertainPolygon( section.stop() ) );
}

MpPoint MpPolygon::pointCoupling( const MpPoint &point ) const
{
    QList<MpLineSection> _linePolygon = this->getLine();
    QList<MpPoint> _listPoint;
    int _count = _linePolygon.count();
    for( int i = 0; i < _count; i++ )
    {
        MpPoint _point = _linePolygon[i].pointPerpendicular( point );
        if( _linePolygon[i].pointToSection( _point ) )
            _listPoint.append( _point );
    }
    _count = this->points_.count();
    for( int i = 0; i < _count; i++ )
        _listPoint.append( this->points_[i] );
    int _index = 0;
    nreal _min = point.distance( _listPoint.first() );
    _count = _listPoint.count();
    for( int i = 1; i < _count; i++ )
    {
        nreal _len = point.distance( _listPoint[i] );
        if( _min > _len )
        {
            _min = _len;
            _index = i;
        }
    }
    return _listPoint[_index];
}

MpPolygon MpPolygon::polygonInRectangle() const
{
    if( this->points_.isEmpty() )
        return MpPolygon();
    else
    {
        nreal _k;
        auto _pair = this->minMaxPoint();
        nreal _maxX = _pair.second.x();
        nreal _minX = _pair.first.x();
        nreal _maxY = _pair.second.y();
        nreal _minY = _pair.first.y();
        MpPolygon _polygon;
        _polygon.points_.append( MpPoint( _minX - _k, _maxY + _k ) );
        _polygon.points_.append( MpPoint( _maxX + _k, _maxY + _k ) );
        _polygon.points_.append( MpPoint( _maxX + _k, _minY - _k ) );
        _polygon.points_.append( MpPoint( _minX - _k, _minY - _k ) );
        return _polygon;
    }
}

MpPolygon MpPolygon::polygonInRectangleMin() const
{
    MpPolygon _polygon;
    if( !this->isValid() )
        return _polygon;
    _polygon = this->polygonInRectangle();
    nreal _content = _polygon.points_[0].distance( _polygon.points_[1] ) *
                       _polygon.points_[1].distance( _polygon.points_[2] );
    MpAngle _angleMin;
    MpPoint _pointMin;
    QPair<MpPoint, MpPoint> _pairMin;
    bool _flagMin = false;
    for ( int j = 0, _count = this->points_.count(); j < _count; j++ )
    {
        const auto &_p = this->points_[j];
        QList<MpAngle> _mAngle;
        QList<nreal> _mDistance;
        for ( int i = 0; i < _count; i++ )
        {
            if( j == i )
                continue;
            _mAngle.append( _p.angleToPoint( this->points_[i] ) );
            _mDistance.append( _p.distance( this->points_[i] ) );
        }
        MpAngle _angle;
        if( j == _mAngle.count() )
            _angle = _mAngle[0];
        else
            _angle = _mAngle[j];
        MpPolygon _vp;
        for ( int i = 0, _index = 0; i < _count; i++ )
        {
            if( j == i )
            {
                _vp.append( _p );
                continue;
            }
            auto _a = _mAngle[_index] - _angle;
            _vp.append( _p.point( _a, _mDistance[_index] ) );
            _index++;
        }
        auto _pair = _vp.minMaxPoint();
        nreal _s = ( _pair.second.x() - _pair.first.x() ) *
                     ( _pair.second.y() - _pair.first.y() );
        if( _s < _content )
        {
            _content = _s;
            _angleMin = _angle;
            _pointMin = _p;
            _pairMin = _pair;
            _flagMin = true;
        }
    }
    if( _flagMin )
    {
        QList<MpPoint> _points;
        _points.append( _pairMin.first );
        _points.append( MpPoint( _pairMin.second.x(), _pairMin.first.y() ) );
        _points.append( _pairMin.second );
        _points.append( MpPoint( _pairMin.first.x(), _pairMin.second.y() ) );
        MpPolygon _result;
        for( int i = 0, _count = _points.count(); i < _count; i++)
        {
            auto _angle = _pointMin.angleToPoint( _points[i] );
            auto _distance = _pointMin.distance( _points[i] );
            _result.append( _pointMin.point( _angle + _angleMin, _distance ) );
        }
        return _result;
    }
    return _polygon;
}

MpPolygon MpPolygon::scalePolygon( const nreal &distance ) const
{
    MpPolygon _polygon;
    QList<MpLineSection> _listLine = this->getLine();
    if( !_listLine.isEmpty() )
    {
        nreal _distance = distance;
        MpPoint _point = MpPoint::newPoint( _listLine.first().angle()
                                        + MpAngle::piOn2(), nreal( 0.00001 ),
                                                _listLine.first().midplane() );
        if( this->pointAppertainPolygon( _point ) )
            _distance = -_distance;
        QList<MpLine> _parall;
        for( int i = 0, _count = _listLine.count(); i < _count; i++ )
            _parall.append( _listLine[i].parallelLine( _distance ) );
        for( int i = 0, _count = _parall.count() - 1; i < _count; i++ )
            _polygon.append( _parall[i].intersectionLine( _parall[i + 1] ) );
        _polygon.append( _parall.last().intersectionLine( _parall.first() ) );
    }
    return _polygon;
}

bool MpPolygon::polugAppertainPolug( const MpPolygon &polygon ) const
{
    int _count = polygon.points_.count();
    for( int i = 0; i < _count; i++ )
        if( !this->pointAppertainPolygon( polygon.points_.at( i ) ) )
            return false;
    return true;
}

bool MpPolygon::polugAppertainPartPolug( const MpPolygon &polygon ) const
{
    int _count = polygon.points_.count();
    for( int i = 0; i < _count; i++ )
        if( this->pointAppertainPolygon( polygon.points_.at( i ) ) )
            return true;
    return false;
}

MpPoint MpPolygon::center() const
{
    return MpLineSection( this->points_[0], this->points_[2] ).midplane();
}

MpPolygon &MpPolygon::moveListPoint( const MpAngle &course )
{
    if( this->points_.isEmpty() )
        return *this;
    MpAngle _course = MpAngle( course.r() % MpAngle::piIn2().r() );
    if( _course < MpAngle() )
        _course += MpAngle::piIn2().r();
    if( ( _course > ( MpAngle::piOn2() * nreal( 7.0 ) ) )
        || _course.intervalStrict( MpAngle(), MpAngle::piOn4() ) )
    {
        this->points_.insert( 0, this->points_.last() );
        this->points_.removeLast();
    }
    else if( _course.intervalSlack( MpAngle::piOn4() * nreal( 3.0 ),
                                    MpAngle::piOn4() * nreal( 5.0 ) ) )
    {
        this->points_.append( this->points_.first() );
        this->points_.removeFirst();
    }
    else if( _course.intervalSlack( MpAngle::piOn4() * nreal( 3.0 ),
                                    MpAngle::piOn4() * nreal( 35.0 ) ) )
    {
        this->points_.append( this->points_.first() );
        this->points_.removeFirst();
        this->points_.append( this->points_.first() );
        this->points_.removeFirst();
    }
    return *this;
}

MpPoint MpPolygon::leftBottom() const
{
    auto _m1 = []( const nreal &a, const nreal &b ) { return ( a < b ); };
    return this->vertixRect( _m1, _m1 );
}

MpPoint MpPolygon::leftTop() const
{
    auto _m1 = []( const nreal &a, const nreal &b ) { return ( a > b ); };
    auto _m2 = []( const nreal &a, const nreal &b ) { return ( a < b ); };
    return this->vertixRect( _m1, _m2 );
}

MpPoint MpPolygon::rightTop() const
{
    auto _m1 = []( const nreal &a, const nreal &b ) { return ( a > b ); };
    return this->vertixRect( _m1, _m1 );
}

MpPoint MpPolygon::rightBottom() const
{
    auto _m1 = []( const nreal &a, const nreal &b ) { return ( a < b ); };
    auto _m2 = []( const nreal &a, const nreal &b ) { return ( a > b ); };
    return this->vertixRect( _m1, _m2 );
}


MpPolygon MpPolygon::polygonCenter( const nreal &length, const nreal &width,
                                    const MpPoint &center )
{
    nreal _l = length / 2.0;
    nreal _w = width / 2.0;
    MpPolygon _polygon;
    _polygon.points().append( MpPoint::newPoint( -MpAngle::piOn2(), _l,
                              MpPoint::newPoint( MpAngle(), _w, center ) ) );
    _polygon.points().append( MpPoint::newPoint( MpAngle::piOn2(), _l,
                              MpPoint::newPoint( MpAngle(), _w, center ) ) );
    _polygon.points().append( MpPoint::newPoint( MpAngle::piOn2(), _l,
                           MpPoint::newPoint( MpAngle::pi(), _w, center ) ) );
    _polygon.points().append( MpPoint::newPoint( -MpAngle::piOn2(), _l,
                           MpPoint::newPoint( MpAngle::pi(), _w, center ) ) );
    return _polygon;
}

MpPolygon &MpPolygon::operator=( const MpPolygon &polygon )
{
    IMpPolygon::operator=( polygon );
    return *this;
}

MpPolygon &MpPolygon::operator=( MpPolygon &&polygon )
{
    IMpPolygon::operator=( std::move( polygon ) );
    return *this;
}

QPair<MpPoint, MpPoint> MpPolygon::minMaxPoint() const
{
    MpPoint _min = this->points_.first();
    MpPoint _max = this->points_.first();
    int _count = this->points_.count();
    for( int i = 1; i < _count; i++ )
    {
        if( _max.x() < this->points_[i].x() )
            _max.setX( this->points_[i].x() );
        if( _min.x() > this->points_[i].x() )
            _min.setX( this->points_[i].x() );
        if( _max.y() < this->points_[i].y() )
            _max.setY( this->points_[i].y() );
        if( _min.y() > this->points_[i].y() )
            _min.setY( this->points_[i].y() );
    }
    return QPair<MpPoint, MpPoint>( _min, _max );
}
