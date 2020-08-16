#include "mplinegeo.h"
#include "mprelativepoint.h"

MpLineGeo::MpLineGeo( const MpLineSection &lineSection,
                      const MpPointGeo &randingMark ) : IMpLineSection()
{
    this->start_ = randingMark.getNextGeoCoordinat(
         lineSection.start().distance(), lineSection.start().angleFromPoint() );
    this->stop_ = randingMark.getNextGeoCoordinat(
           lineSection.stop().distance(), lineSection.stop().angleFromPoint() );
}

MpLineGeo::MpLineGeo( const MpLineGeo &lineGeo ) : IMpLineSection(lineGeo)
{

}

MpLineGeo::MpLineGeo( MpLineGeo &&lineGeo )
    : IMpLineSection(std::move(lineGeo))
{

}

MpLineGeo::~MpLineGeo()
{

}

MpPointGeo MpLineGeo::intersectionLine( const MpLineGeo &line ) const
{
    MpLine _line1 = MpRelativePoint::newCoord( *this, this->start() );
    MpLine _line2 = MpRelativePoint::newCoord( line, this->start() );
    return MpRelativePoint::newCoord( _line1.intersectionLine( _line2 ),
                                      this->start() );
}

MpLineGeo &MpLineGeo::operator=( const MpLineGeo &lineGeo )
{
    IMpLineSection::operator=( lineGeo );
    return *this;
}

MpLineGeo &MpLineGeo::operator=( MpLineGeo &&lineGeo )
{
    IMpLineSection::operator=( std::move(lineGeo) );
    return *this;
}
