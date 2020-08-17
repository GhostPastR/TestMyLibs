#ifndef NCIRCLEGEO_H
#define NCIRCLEGEO_H

#include "narc.h"
#include "ncircle.h"
#include "npointgeo.h"

/**
 * @brief The NCircleGeo class - Класс содержащий методы и поля для работы с
 * геометрическим объектом окружность содержащие топографические координаты.
 */
class NCircleGeo : public INCircle<NPointGeo>
{
public:
    NCircleGeo();
    NCircleGeo( const NPointGeo &center, const nreal &radius );
    NCircleGeo( const NCircle &circle, const NPointGeo &rangingMark );
    NCircleGeo( const NCircleGeo &circleGeo );
    NCircleGeo( NCircleGeo &&circleGeo );
    virtual ~NCircleGeo();

    NCircleGeo &operator=( const NCircleGeo &circleGeo );
    NCircleGeo &operator=( NCircleGeo &&circleGeo );
};

inline NCircleGeo::NCircleGeo(){}

inline NCircleGeo::NCircleGeo( const NPointGeo &center,
                                 const nreal &radius )
    : INCircle( center, radius ){}





/**
 * @brief The NArcGeo class - Класс содержащий методы и поля для работы с
 * геометрическим объектом дуга содержащие топографические координаты.
 */
class NArcGeo : public INArc<NPointGeo>
{
public:
    NArcGeo();
    NArcGeo( const NPointGeo &center, const nreal &radius,
              const NAngle &angleStart,
              const NAngle &angleStop, NDirect direct );
    NArcGeo( const NArc &arc, const NPointGeo &rangingMark  );
    NArcGeo( const NArcGeo &arcGeo );
    NArcGeo( NArcGeo &&arcGeo );
    virtual ~NArcGeo();

    NPointGeo startArc() const;
    NPointGeo stopArc() const;

    NArcGeo &operator=( const NArcGeo &arcGeo );
    NArcGeo &operator=( NArcGeo &&arcGeo );
};

inline NArcGeo::NArcGeo(){}

inline NArcGeo::NArcGeo( const NPointGeo &center, const nreal &radius,
                           const NAngle &angleStart, const NAngle &angleStop,
                           NDirect direct )
    : INArc( radius, angleStart, angleStop, direct )
{
    this->center_ = center;
}

#endif // NCIRCLEGEO_H
