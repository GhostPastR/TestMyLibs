#ifndef NARC_H
#define NARC_H

#include <QList>
#include "inarc.h"
#include "npoint.h"

/**
 * @brief The NArc class - Класс содержащий методы и поля для работы с
 * геометрическим объектом дуга
 */
class NArc : public INArc<NPoint>
{
public:
    NArc();
    NArc( const NPoint &center, const nreal &radius,
           const NAngle &courseStart, const NAngle &courseStop,
           NDirect direct );
    NArc( const NPoint &center, const nreal &radius, const NPoint &start,
           const NPoint &stop, NDirect direct );
    NArc( const NArc &arc );
    NArc( NArc &&arc );
    virtual ~NArc();

    NPoint start() const;
    NPoint stop() const;

    void setStart( const NPoint &start );
    void setStop( const NPoint &stop );

    /**
     * @brief lengthArc - метод возвращает длину дуги
     * @return  - длина дуги
     */
    nreal lengthArc() const;

    /**
     * @brief pointOnArc - метод возвращает координаты точки на дуге с заданным
     * расстоянием от начало.
     * @param distance - расстояние от начало дуги.
     * @param appertain - результат расчета(true - точка находится на дуге,
     * false - точка не на дуге).
     * @return  - координаты точки.
     */
    NPoint pointOnArc( const nreal &distance, bool &appertain ) const;

    /**
     * @brief midplane - метод возвращает координаты средней точки на дуге.
     * @return - координаты точки.
     */
    NPoint midplane();

    NArc &operator=( const NArc &arc );
    NArc &operator=( NArc &&arc );
};

inline NArc::NArc() : INArc() {}

inline NArc::NArc( const NPoint &center, const nreal &radius,
                     const NAngle &courseStart,const NAngle &courseStop,
                     NDirect direct )
    : INArc( radius, courseStart, courseStop, direct )
{
    this->setCenter( center );
}

#endif // NARC_H
