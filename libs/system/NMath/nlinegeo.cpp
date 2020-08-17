#include "nlinegeo.h"
#include "nrelativepoint.h"

NLineGeo::NLineGeo( const NLineSection &lineSection,
                      const NPointGeo &randingMark ) : INLineSection()
{
    this->start_ = randingMark.getNextGeoCoordinat(
         lineSection.start().distance(), lineSection.start().angleFromPoint() );
    this->stop_ = randingMark.getNextGeoCoordinat(
           lineSection.stop().distance(), lineSection.stop().angleFromPoint() );
}

NLineGeo::NLineGeo( const NLineGeo &lineGeo ) : INLineSection(lineGeo)
{

}

NLineGeo::NLineGeo( NLineGeo &&lineGeo )
    : INLineSection(std::move(lineGeo))
{

}

NLineGeo::~NLineGeo()
{

}

NPointGeo NLineGeo::intersectionLine( const NLineGeo &line ) const
{
    NLine _line1 = NRelativePoint::newCoord( *this, this->start() );
    NLine _line2 = NRelativePoint::newCoord( line, this->start() );
    return NRelativePoint::newCoord( _line1.intersectionLine( _line2 ),
                                      this->start() );
}

NLineGeo &NLineGeo::operator=( const NLineGeo &lineGeo )
{
    INLineSection::operator=( lineGeo );
    return *this;
}

NLineGeo &NLineGeo::operator=( NLineGeo &&lineGeo )
{
    INLineSection::operator=( std::move(lineGeo) );
    return *this;
}
