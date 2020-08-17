#ifndef NPOLARCOORDINAT_H
#define NPOLARCOORDINAT_H

#include "npoint.h"

/**
 * @brief The NPolarCoordinat class - Класс содержащий поля и методы для работы
 * с геометрической объектом точка(полярные координаты).
 */
class NPolarCoordinat
{
public:
    NPolarCoordinat();
    NPolarCoordinat( const nreal &range, const NAngle &omnibearing );
    NPolarCoordinat( const NPolarCoordinat &polarCoordinat );
    NPolarCoordinat( NPolarCoordinat &&polarCoordinat );
    virtual ~NPolarCoordinat();

    const nreal &range() const;
    const NAngle &omnibearing() const;

    void setRange( const nreal &range );
    void setOmnibearing( const NAngle &omnibearing );

    /**
     * @brief setPoint - Метод задает полярные координаты через декартовые
     * относительно опорной точки.
     * @param point - декартовые координаты.
     * @param start - опорная точка.
     */
    void setPoint( const NPoint &point, const NPoint &start = NPoint() );

    /**
     * @brief point - Метод возвращает приобразованные полярные координаты в
     * декартовые.
     * @param start - опорная точка.
     * @return декартовые координаты.
     */
    NPoint point( const NPoint &start = NPoint() ) const;

    NPolarCoordinat &operator=( const NPolarCoordinat &polarCoordinat );
    NPolarCoordinat &operator=( NPolarCoordinat &&polarCoordinat );

protected:
    nreal range_;          //!Расстояние до точки
    NAngle omnibearing_;    //!Угол на точку
};

inline NPolarCoordinat::NPolarCoordinat(){}

inline NPolarCoordinat::NPolarCoordinat( const nreal &range,
                                           const NAngle &omnibearing )
{
    this->setRange( range );
    this->setOmnibearing( omnibearing );
}

inline const nreal &NPolarCoordinat::range() const
{
    return this->range_;
}

inline const NAngle &NPolarCoordinat::omnibearing() const
{
    return this->omnibearing_;
}

inline void NPolarCoordinat::setRange( const nreal &range )
{
    this->range_ = range;
}

inline void NPolarCoordinat::setOmnibearing( const NAngle &omnibearing )
{
    this->omnibearing_ = omnibearing;
}

#endif // NPOLARCOORDINAT_H
