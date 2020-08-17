#include "npointgeo.h"

const nreal NPointGeo::stSemiminorAxis( 6356751.362 );
const nreal NPointGeo::stSemimajorAxis( 6378136 );

NPointGeo::NPointGeo( const NAngle &latitude, const NAngle &longitude,
                        const nreal &altitude )
{
    this->setLatitude( latitude );
    this->setLongitude( longitude );
    this->setAltitude( altitude );
}

NPointGeo::NPointGeo( const NPointGeo &pointGeo )
{
    this->latitude_ = pointGeo.latitude_;
    this->longitude_ = pointGeo.longitude_;
    this->altitude_ = pointGeo.altitude_;
}

NPointGeo::NPointGeo( NPointGeo &&pointGeo )
{
    this->latitude_ = std::move( pointGeo.latitude_ );
    this->longitude_ = std::move( pointGeo.longitude_ );
    this->altitude_ = std::move( pointGeo.altitude_ );
}

NPointGeo::~NPointGeo()
{

}

void NPointGeo::setLatitude( const NAngle &latitude )
{
    if( ( -NAngle::piOn2() <= latitude ) && ( latitude <= NAngle::piOn2() ) )
        this->latitude_ = latitude;
    else
        std::cerr << "Warning MpLibs class NPointGeo, method setLatitude()!!! "
                     "latitude < -90.0 || latitude > 90.0" << std::endl;
}

void NPointGeo::setLongitude( const NAngle &longitude )
{
    if( ( -NAngle::pi() <= longitude ) && ( longitude <= NAngle::pi() ) )
        this->longitude_ = longitude;
    else
        std::cerr << "Warning MpLibs class NPointGeo, method "
                     "setLongitude()!!! longitude < -180.0 || "
                     "longitude > 180.0" << std::endl;
}

void NPointGeo::setAltitude( const nreal &altitude )
{
    if( altitude.intervalStrict( nreal( 0.0 ), nreal( 40000.0 ) ) )
        this->altitude_ = altitude;
}

QString NPointGeo::latitudeString( bool sec ) const
{       
    if( sec )
    {
        auto _coord = NGradeMinSecMsec::convert( this->latitude_ );
        if( this->latitude_.d() < 0.0 )
        {
            return QString( "%1°%2\'%3\'\'%4" )
                    .arg( _coord.grade().toInt32(), 2, 10, QLatin1Char('0') )
                    .arg( _coord.minute().toInt32(), 2, 10, QLatin1Char('0') )
                    .arg( _coord.second().toInt32(), 2, 10, QLatin1Char('0') )
                    .arg( " S" );
        }
        else
        {
            return QString( "%1°%2\'%3\'\'%4" )
                    .arg( _coord.grade().toInt32(), 2, 10, QLatin1Char('0') )
                    .arg( _coord.minute().toInt32(), 2, 10, QLatin1Char('0') )
                    .arg( _coord.second().toInt32(), 2, 10, QLatin1Char('0') )
                    .arg( " N" );
        }
    }
    else
    {
        auto _grade = this->latitude_.d().entier();
        auto _min = this->latitude_.d().fraction() * 60.0;
        auto _minute = _min.entier();
        auto _dmin = _min.fraction() * 1000.0;
        if( this->latitude_.d() < 0.0 )
        {
            return QString( "%1°%2.%3\'%4" )
                    .arg( _grade.toInt32(), 2, 10, QLatin1Char('0') )
                    .arg( _minute.toInt32(), 2, 10, QLatin1Char('0') )
                    . arg( _dmin.toInt32(), 3, 10, QLatin1Char('0') )
                    .arg( " S" );
        }
        else
        {
            return QString( "%1°%2.%3\'%4" )
                    .arg( _grade.toInt32(), 2, 10, QLatin1Char('0') )
                    .arg( _minute.toInt32(), 2, 10, QLatin1Char('0') )
                    .arg( _dmin.toInt32(), 3, 10, QLatin1Char('0') )
                    .arg( " N" );
        }
    }
}
QString NPointGeo::longitudeString( bool sec ) const
{
    if( sec )
    {
        NGradeMinSecMsec _coord = NGradeMinSecMsec::convert( this->longitude_ );
        if( this->longitude_.d() < 0.0 )
        {
            return QString( "%1°%2.%3\'%4" )
                    .arg( _coord.grade().toInt32(), 2, 10, QLatin1Char('0') )
                    .arg( _coord.minute().toInt32(), 2, 10, QLatin1Char('0') )
                    . arg( _coord.second().toInt32(), 3, 10, QLatin1Char('0') )
                    .arg( " W" );
        }
        else
        {
            return QString( "%1°%2.%3\'%4" )
                    .arg( _coord.grade().toInt32(), 2, 10, QLatin1Char('0') )
                    .arg( _coord.minute().toInt32(), 2, 10, QLatin1Char('0') )
                    .arg( _coord.second().toInt32(), 3, 10, QLatin1Char('0') )
                    .arg( " E" );
        }
    }
    else
    {
        auto _grade = this->latitude_.d().entier();
        auto _min = this->latitude_.d().fraction() * 60.0;
        auto _minute = _min.entier();
        auto _dmin = _min.fraction() * 1000.0;
        if( this->latitude_.d() < 0.0 )
        {
            return QString( "%1°%2.%3\'%4" )
                    .arg( _grade.toInt32(), 2, 10, QLatin1Char('0') )
                    .arg( _minute.toInt32(), 2, 10, QLatin1Char('0') )
                    . arg( _dmin.toInt32(), 3, 10, QLatin1Char('0') )
                    .arg( " S" );
        }
        else
        {
            return QString( "%1°%2.%3\'%4" )
                    .arg( _grade.toInt32(), 2, 10, QLatin1Char('0') )
                    .arg( _minute.toInt32(), 2, 10, QLatin1Char('0') )
                    .arg( _dmin.toInt32(), 3, 10, QLatin1Char('0') )
                    .arg( " N" );
        }
    }
}

nreal NPointGeo::distance( const NPointGeo &stop ) const
{
    NPolarCoordinat _polar;
    NPointGeo::geographicInverse( *this, stop, _polar );
    return _polar.range();
}

NAngle NPointGeo::angle( const NPointGeo &stop ) const
{
    NPolarCoordinat _polar;
    NPointGeo::geographicInverse( *this, stop, _polar );
    return _polar.omnibearing();
}

NPointGeo NPointGeo::midplane( const NPointGeo &point ) const
{
    NPolarCoordinat _polar = this->getPolarToTc( point );
    return this->getNextGeoCoordinat( _polar.range() / 2.0,
                                      _polar.omnibearing() );
}

NGradeMinSecMsec NPointGeo::getGradeMinSecMsec( Coordinate coord ) const
{
    NAngle _coord;
    if( coord == NPointGeo::LATITUDE )
        _coord = this->latitude_;
    if( coord == NPointGeo::LONGITUDE )
        _coord = this->longitude_;
    return NGradeMinSecMsec::convert( _coord );
}

void NPointGeo::setGradeMinSecMsec( const NGradeMinSecMsec &latitude,
                                     const NGradeMinSecMsec &longitude )
{
    auto _d = latitude.grade().toDouble() + latitude.minute().toDouble() / 60
            + latitude.second().toDouble() / 3600
            + latitude.msecond().toDouble() / 3600000;

    this->latitude_ = NAngle( nreal( _d ), false );
    if( latitude.direction() )
        this->latitude_ = -this->latitude_;
    _d = longitude.grade().toDouble()
            + longitude.minute().toDouble() / 60.0 +
            longitude.second().toDouble() / 3600
            + longitude.msecond().toDouble() / 3600000;
    this->longitude_ = NAngle( nreal( _d ), false );
    if( longitude.direction() )
        this->longitude_ = -this->longitude_;
}

NPointGeo NPointGeo::getNextGeoCoordinat( const nreal &range,
                                            const NAngle &omnibearing ) const
{
    NPointGeo geo;
    NPointGeo::commonSurveyComp( range, omnibearing, *this, geo );
    return geo;
}

NPolarCoordinat NPointGeo::getPolarToTc( const NPointGeo &pointGeo ) const
{
    NPolarCoordinat _polar;
    NPointGeo::geographicInverse( *this, pointGeo, _polar );
    return _polar;
}

NPolarCoordinat NPointGeo::getPolarFromTc( const NPointGeo &pointGeo ) const
{
    NPolarCoordinat _polar;
    NPointGeo::geographicInverse( pointGeo, *this, _polar );
    return _polar;
}

NPolarCoordinat NPointGeo::getPolarToTc( const NPointGeo &start,
                                           const NPointGeo &stop )
{
    NPolarCoordinat _polar;
    NPointGeo::geographicInverse( start, stop, _polar );
    return _polar;
}

NPointGeo &NPointGeo::operator=( const NPointGeo &pointGeo )
{
    this->latitude_ = pointGeo.latitude_;
    this->longitude_ = pointGeo.longitude_;
    this->altitude_ = pointGeo.altitude_;
    return *this;
}

NPointGeo &NPointGeo::operator=( NPointGeo &&pointGeo )
{
    this->latitude_ = std::move( pointGeo.latitude_ );
    this->longitude_ = std::move( pointGeo.longitude_ );
    this->altitude_ = std::move( pointGeo.altitude_ );
    return *this;
}

bool NPointGeo::operator ==( const NPointGeo &pointGeo ) const
{
    return ( this->latitude_ == pointGeo.latitude_ ) &&
           ( this->longitude_ == pointGeo.longitude_ );
}

nreal NPointGeo::eccentricity2_1()
{
    return ( NPointGeo::stSemimajorAxis * NPointGeo::stSemimajorAxis
               - NPointGeo::stSemiminorAxis * NPointGeo::stSemiminorAxis )
             / ( NPointGeo::stSemimajorAxis * NPointGeo::stSemimajorAxis );
}

nreal NPointGeo::eccentricity2_2()
{
    return ( NPointGeo::stSemimajorAxis * NPointGeo::stSemimajorAxis
                   - NPointGeo::stSemiminorAxis * NPointGeo::stSemiminorAxis )
                / ( NPointGeo::stSemiminorAxis * NPointGeo::stSemiminorAxis );
}


void NPointGeo::commonSurveyComp( const nreal &range,
                                   const NAngle &omnibearing,
                                   const NPointGeo &start, NPointGeo &stop )
{
    if( ( range.compare( nreal() ) ) && ( omnibearing == NAngle() ) )
    {
        stop = start;
        return;
    }
    double _rLatitude = start.latitude().r().toType();
    double _rLongitude = start.longitude().r().toType();
    double _e2 = NPointGeo::eccentricity2_1().toType();
    double _sinLat = sin( _rLatitude );
    double _os = sqrt( 1.0 - _e2 * _sinLat * _sinLat );
    double _sqrtE2 = sqrt( 1.0 - _e2 );
    nreal _sinU1( _sinLat * _sqrtE2 / _os );
    double _cosU1 = cos( _rLatitude ) / _os;
    double _cosOmn = cos( omnibearing.r().toType() );
    double _sinOmn = sin( omnibearing.r().toType() );

    double _a0 = asin( _cosU1 * _sinOmn );
    double _sin2q1 = 0.0;
    double _cos2q1 = 1.0;
    if( _sinU1.unequal( nreal() ) )
    {
        double _ctgQ1 = _cosU1 * _cosOmn / _sinU1.toType();
        _sin2q1 = 2.0 * _ctgQ1 / ( _ctgQ1 * _ctgQ1 + 1.0 );
        _cos2q1 = ( _ctgQ1 * _ctgQ1 - 1.0 ) / ( _ctgQ1 * _ctgQ1 + 1.0 );
    }

    double _cos2a0 = cos( _a0 ) * cos( _a0 );
    double _k2 = NPointGeo::eccentricity2_2().toType() * _cos2a0;

    double _k2_2 = _k2 * _k2;
    double _kA = 1.0 + _k2 / 4.0 - 3.0 * _k2_2 / 64.0;
    double _kBA = ( _k2 / 4.0 - _k2_2 / 16.0 ) / _kA;
    double _kC = _k2_2 / 128.0;

    double _q = range.toType()
            / ( _kA * NPointGeo::stSemiminorAxis.toType() );
    double _qD = _q;
    double _cos2q1_q = _cos2q1 * cos( _q ) - _sin2q1 * sin( _q );
    _q = _qD + _kBA * sin( _q ) * _cos2q1_q;
   _cos2q1_q = _cos2q1 * cos( _q ) - _sin2q1 * sin( _q );
//Возможен цикл
   double _cos4q1_2q = 2 * _cos2q1_q * _cos2q1_q - 1;
   _q = _qD + _kBA * sin( _q ) * _cos2q1_q
           + ( _kC / _kA ) * sin( 2 * _q ) * _cos4q1_2q;
   _cos2q1_q = _cos2q1 * cos( _q ) - _sin2q1 * sin( _q );
//конец цикла

    double _cosQ = cos( _q );
    double _sinQ = sin( _q ) * _cosOmn;

    double _cosU2 = _cosU1 * _cosQ - _sinU1.toType() * _sinQ;
    double _dY = atan2( sin( _q ) * _sinOmn , _cosU2 );
    double _sinU2 = _sinU1.toType() * _cosQ + _cosU1 * _sinQ;

    stop.latitude_ = NAngle( nreal( atan( _sinU2 * cos( _dY )
                                        / ( _sqrtE2 * _cosU2 ) ) ) );
    stop.longitude_ = NAngle( nreal( _rLongitude + _dY - sin( _a0 ) *
            ( ( 0.5 + _e2 / 8.0 - ( _e2 / 16.0 ) * _cos2a0 ) * _e2 * _q +
              _e2 * _e2 * _cos2a0 / 16.0 * sin( _q ) * _cos2q1_q ) ) );
    if( stop.longitude_.r() > M_PI )
        while( stop.longitude_.r() > M_PI )
            stop.longitude_ += -NAngle::piIn2().r();
    else
        while( stop.longitude_.r() < -M_PI )
            stop.longitude_ += NAngle::piIn2().r();
}

void NPointGeo::geographicInverse( const NPointGeo &start,
                                    const NPointGeo &stop,
                                    NPolarCoordinat &polar )
{
    if( start == stop )
    {
        polar.setRange( nreal() );
        polar.setOmnibearing( NAngle() );
        return;
    }
    double _rLatitude1 = start.latitude_.r().toType();
    double _rLongitude1 = start.longitude_.r().toType();
    double _rLatitude2 = stop.latitude_.r().toType();
    double _rLongitude2 = stop.longitude_.r().toType();
    double _e2 = NPointGeo::eccentricity2_1().toType();
    double _sinLat = sin( _rLatitude1 );
    double _os = sqrt( 1.0 - _e2 * _sinLat * _sinLat );
    double _sinU1 = _sinLat * sqrt( 1.0 - _e2 ) / _os;
    double _cosU1 = cos( _rLatitude1 ) / _os;
    _sinLat = sin( _rLatitude2 );
    _os = sqrt( 1.0 - _e2 * _sinLat * _sinLat );
    double _sinU2 = _sinLat * sqrt( 1.0 - _e2 ) / _os;
    double _cosU2 =  cos( _rLatitude2 ) / _os;

    double _dL = _rLongitude2 - _rLongitude1;

    double _p = _cosU2 * sin( _dL );
    double _q = _cosU1 * _sinU2 - _sinU1 * _cosU2 * cos( _dL );
    double _n = _sinU1 * _sinU2 + _cosU1 * _cosU2 * cos( _dL );
    double _omnibearing = atan2( _p , _q );
    double _g = acos( _n );
    double _sinA0 = _cosU1 * sin( _omnibearing );
    double _a0 = cos( asin( _sinA0 ) );
    _a0 *= _a0;
//Возможен цикл
    double _dY = _dL + _sinA0 * ( 0.5 + _e2 / 8.0 - ( _e2 / 16.0 ) * _a0 )
            * _e2 * _g;

    _p = _cosU2 * sin( _dY );
    _q = _cosU1 * _sinU2 - _sinU1 * _cosU2 * cos( _dY );
    _n = _sinU1 * _sinU2 + _cosU1 * _cosU2 * cos( _dY );
    _omnibearing = atan2( _p , _q );
    _g = acos( _n );
    _a0 =  cos( asin( sin( _omnibearing ) * _cosU1 ) );
    _a0 *= _a0;

//конец цикла
    if( _omnibearing < 0 )
    {
        _omnibearing += 2 * M_PI;
    }
    double _g1 = atan2( _sinU1 , ( _cosU1 * cos( _omnibearing ) ) );
    double _e2h = NPointGeo::eccentricity2_2().toType();
    double _k2 = _e2h * _a0;
    double _k2_2 = _k2 * _k2;
    double _range = ( 1.0 + _k2 / 4.0 - 3.0 * _k2_2 / 64.0 )
            * NPointGeo::stSemiminorAxis.toType() * _g - ( _k2 / 4.0 - _k2_2 / 16.0 )
            * NPointGeo::stSemiminorAxis.toType() * sin( _g ) * cos( 2 * _g1 + _g ) -
                    ( _k2_2 / 128.0 ) * NPointGeo::stSemiminorAxis.toType()
                    * sin( 2 * _g ) * cos( 4 * _g1 + 2 * _g );
    polar.setRange( nreal( _range ) );
    polar.setOmnibearing( NAngle( nreal( _omnibearing ) ) );
}
