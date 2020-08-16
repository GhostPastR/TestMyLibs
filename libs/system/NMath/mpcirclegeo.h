#ifndef MPCIRCLEGEO_H
#define MPCIRCLEGEO_H

#include "mparc.h"
#include "mpcircle.h"
#include "mppointgeo.h"

/**
 * @brief The MpCircleGeo class - Класс содержащий методы и поля для работы с
 * геометрическим объектом окружность содержащие топографические координаты.
 */
class MpCircleGeo : public IMpCircle<MpPointGeo>
{
public:
    MpCircleGeo();
    MpCircleGeo( const MpPointGeo &center, const nreal &radius );
    MpCircleGeo( const MpCircle &circle, const MpPointGeo &rangingMark );
    MpCircleGeo( const MpCircleGeo &circleGeo );
    MpCircleGeo( MpCircleGeo &&circleGeo );
    virtual ~MpCircleGeo();

    MpCircleGeo &operator=( const MpCircleGeo &circleGeo );
    MpCircleGeo &operator=( MpCircleGeo &&circleGeo );
};

inline MpCircleGeo::MpCircleGeo(){}

inline MpCircleGeo::MpCircleGeo( const MpPointGeo &center,
                                 const nreal &radius )
    : IMpCircle( center, radius ){}





/**
 * @brief The MpArcGeo class - Класс содержащий методы и поля для работы с
 * геометрическим объектом дуга содержащие топографические координаты.
 */
class MpArcGeo : public IMpArc<MpPointGeo>
{
public:
    MpArcGeo();
    MpArcGeo( const MpPointGeo &center, const nreal &radius,
              const MpAngle &angleStart,
              const MpAngle &angleStop, MpDirect direct );
    MpArcGeo( const MpArc &arc, const MpPointGeo &rangingMark  );
    MpArcGeo( const MpArcGeo &arcGeo );
    MpArcGeo( MpArcGeo &&arcGeo );
    virtual ~MpArcGeo();

    MpPointGeo startArc() const;
    MpPointGeo stopArc() const;

    MpArcGeo &operator=( const MpArcGeo &arcGeo );
    MpArcGeo &operator=( MpArcGeo &&arcGeo );
};

inline MpArcGeo::MpArcGeo(){}

inline MpArcGeo::MpArcGeo( const MpPointGeo &center, const nreal &radius,
                           const MpAngle &angleStart, const MpAngle &angleStop,
                           MpDirect direct )
    : IMpArc( radius, angleStart, angleStop, direct )
{
    this->center_ = center;
}

#endif // MPCIRCLEGEO_H
