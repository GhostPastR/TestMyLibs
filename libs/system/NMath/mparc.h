#ifndef MPARC_H
#define MPARC_H

#include <QList>
#include "imparc.h"
#include "mppoint.h"

/**
 * @brief The MpArc class - Класс содержащий методы и поля для работы с
 * геометрическим объектом дуга
 */
class MpArc : public IMpArc<MpPoint>
{
public:
    MpArc();
    MpArc( const MpPoint &center, const nreal &radius,
           const MpAngle &courseStart, const MpAngle &courseStop,
           MpDirect direct );
    MpArc( const MpPoint &center, const nreal &radius, const MpPoint &start,
           const MpPoint &stop, MpDirect direct );
    MpArc( const MpArc &arc );
    MpArc( MpArc &&arc );
    virtual ~MpArc();

    MpPoint start() const;
    MpPoint stop() const;

    void setStart( const MpPoint &start );
    void setStop( const MpPoint &stop );

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
    MpPoint pointOnArc( const nreal &distance, bool &appertain ) const;

    /**
     * @brief midplane - метод возвращает координаты средней точки на дуге.
     * @return - координаты точки.
     */
    MpPoint midplane();

    MpArc &operator=( const MpArc &arc );
    MpArc &operator=( MpArc &&arc );
};

inline MpArc::MpArc() : IMpArc() {}

inline MpArc::MpArc( const MpPoint &center, const nreal &radius,
                     const MpAngle &courseStart,const MpAngle &courseStop,
                     MpDirect direct )
    : IMpArc( radius, courseStart, courseStop, direct )
{
    this->setCenter( center );
}

#endif // MPARC_H
