#include "mpcirclegeo.h"

MpCircleGeo::MpCircleGeo( const MpCircle &circle,
                          const MpPointGeo &rangingMark )
    : IMpCircle( MpPointGeo(), circle.radius() )
{
    this->center_ = rangingMark.getNextGeoCoordinat( circle.center().distance(),
                                             circle.center().angleFromPoint() );
}

MpCircleGeo::MpCircleGeo( const MpCircleGeo &circleGeo ) : IMpCircle(circleGeo)
{

}

MpCircleGeo::MpCircleGeo( MpCircleGeo &&circleGeo )
 : IMpCircle(std::move(circleGeo))
{

}

MpCircleGeo::~MpCircleGeo()
{

}

MpCircleGeo &MpCircleGeo::operator=( const MpCircleGeo &circleGeo )
{
    IMpCircle::operator=( circleGeo );
    return *this;
}

MpCircleGeo &MpCircleGeo::operator=( MpCircleGeo &&circleGeo )
{
    IMpCircle::operator=( std::move( circleGeo ) );
    return *this;
}





MpArcGeo::MpArcGeo( const MpArc &arc, const MpPointGeo &rangingMark )
    : IMpArc( arc.radius(), arc.angleStart(), arc.angleStop(), arc.direct() )
{
    this->center_ = rangingMark.getNextGeoCoordinat( arc.center().distance(),
                                                arc.center().angleFromPoint() );
}

MpArcGeo::MpArcGeo( const MpArcGeo &arcGeo ) : IMpArc(arcGeo)
{

}

MpArcGeo::MpArcGeo( MpArcGeo &&arcGeo ) : IMpArc(std::move(arcGeo))
{

}

MpArcGeo::~MpArcGeo()
{

}

MpPointGeo MpArcGeo::startArc() const
{
    return this->center_.getNextGeoCoordinat( this->radius_, this->angleStart_ );
}

MpPointGeo MpArcGeo::stopArc() const
{
    return this->center_.getNextGeoCoordinat( this->radius_, this->angleStop_ );
}

MpArcGeo &MpArcGeo::operator=( const MpArcGeo &arcGeo )
{
    IMpArc::operator=( arcGeo );
    return *this;
}

MpArcGeo &MpArcGeo::operator=( MpArcGeo &&arcGeo )
{
    IMpArc::operator=( std::move( arcGeo ) );
    return *this;
}
