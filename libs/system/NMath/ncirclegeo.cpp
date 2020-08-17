#include "ncirclegeo.h"

NCircleGeo::NCircleGeo( const NCircle &circle,
                          const NPointGeo &rangingMark )
    : INCircle( NPointGeo(), circle.radius() )
{
    this->center_ = rangingMark.getNextGeoCoordinat( circle.center().distance(),
                                             circle.center().angleFromPoint() );
}

NCircleGeo::NCircleGeo( const NCircleGeo &circleGeo ) : INCircle(circleGeo)
{

}

NCircleGeo::NCircleGeo( NCircleGeo &&circleGeo )
 : INCircle(std::move(circleGeo))
{

}

NCircleGeo::~NCircleGeo()
{

}

NCircleGeo &NCircleGeo::operator=( const NCircleGeo &circleGeo )
{
    INCircle::operator=( circleGeo );
    return *this;
}

NCircleGeo &NCircleGeo::operator=( NCircleGeo &&circleGeo )
{
    INCircle::operator=( std::move( circleGeo ) );
    return *this;
}





NArcGeo::NArcGeo( const NArc &arc, const NPointGeo &rangingMark )
    : INArc( arc.radius(), arc.angleStart(), arc.angleStop(), arc.direct() )
{
    this->center_ = rangingMark.getNextGeoCoordinat( arc.center().distance(),
                                                arc.center().angleFromPoint() );
}

NArcGeo::NArcGeo( const NArcGeo &arcGeo ) : INArc(arcGeo)
{

}

NArcGeo::NArcGeo( NArcGeo &&arcGeo ) : INArc(std::move(arcGeo))
{

}

NArcGeo::~NArcGeo()
{

}

NPointGeo NArcGeo::startArc() const
{
    return this->center_.getNextGeoCoordinat( this->radius_, this->angleStart_ );
}

NPointGeo NArcGeo::stopArc() const
{
    return this->center_.getNextGeoCoordinat( this->radius_, this->angleStop_ );
}

NArcGeo &NArcGeo::operator=( const NArcGeo &arcGeo )
{
    INArc::operator=( arcGeo );
    return *this;
}

NArcGeo &NArcGeo::operator=( NArcGeo &&arcGeo )
{
    INArc::operator=( std::move( arcGeo ) );
    return *this;
}
