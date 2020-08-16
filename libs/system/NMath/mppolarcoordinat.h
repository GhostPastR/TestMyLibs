#ifndef MPPOLARCOORDINAT_H
#define MPPOLARCOORDINAT_H

#include "mppoint.h"

/**
 * @brief The MpPolarCoordinat class - Класс содержащий поля и методы для работы
 * с геометрической объектом точка(полярные координаты).
 */
class MpPolarCoordinat
{
public:
    MpPolarCoordinat();
    MpPolarCoordinat( const nreal &range, const MpAngle &omnibearing );
    MpPolarCoordinat( const MpPolarCoordinat &polarCoordinat );
    MpPolarCoordinat( MpPolarCoordinat &&polarCoordinat );
    virtual ~MpPolarCoordinat();

    const nreal &range() const;
    const MpAngle &omnibearing() const;

    void setRange( const nreal &range );
    void setOmnibearing( const MpAngle &omnibearing );

    /**
     * @brief setPoint - Метод задает полярные координаты через декартовые
     * относительно опорной точки.
     * @param point - декартовые координаты.
     * @param start - опорная точка.
     */
    void setPoint( const MpPoint &point, const MpPoint &start = MpPoint() );

    /**
     * @brief point - Метод возвращает приобразованные полярные координаты в
     * декартовые.
     * @param start - опорная точка.
     * @return декартовые координаты.
     */
    MpPoint point( const MpPoint &start = MpPoint() ) const;

    MpPolarCoordinat &operator=( const MpPolarCoordinat &polarCoordinat );
    MpPolarCoordinat &operator=( MpPolarCoordinat &&polarCoordinat );

protected:
    nreal range_;          //!Расстояние до точки
    MpAngle omnibearing_;    //!Угол на точку
};

inline MpPolarCoordinat::MpPolarCoordinat(){}

inline MpPolarCoordinat::MpPolarCoordinat( const nreal &range,
                                           const MpAngle &omnibearing )
{
    this->setRange( range );
    this->setOmnibearing( omnibearing );
}

inline const nreal &MpPolarCoordinat::range() const
{
    return this->range_;
}

inline const MpAngle &MpPolarCoordinat::omnibearing() const
{
    return this->omnibearing_;
}

inline void MpPolarCoordinat::setRange( const nreal &range )
{
    this->range_ = range;
}

inline void MpPolarCoordinat::setOmnibearing( const MpAngle &omnibearing )
{
    this->omnibearing_ = omnibearing;
}

#endif // MPPOLARCOORDINAT_H
