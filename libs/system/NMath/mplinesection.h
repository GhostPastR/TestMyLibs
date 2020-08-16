#ifndef MPLINESECTION_H
#define MPLINESECTION_H

#include <QList>
#include "mpline.h"
#include "implinesection.h"

class MpLineSection : public MpLine, public IMpLineSection<MpPoint>
{
public:
    MpLineSection();
    MpLineSection( const MpPoint &start, const MpPoint &end );
    MpLineSection( const MpLineSection &line );
    MpLineSection( MpLineSection &&line );
    ~MpLineSection();

    void setLine( const MpPoint &start, const MpPoint &end );

    /**
     * @brief length - метод возвращает длинну отрезка, если в классе заданы
     * точки начало и конца отрезка.
     * @return - длину отрезка
     */
    nreal length() const;

    /**
     * @brief angle - метод возвращает направление отрезка.
     * @return - направление отрезка в радианах.
     */
    MpAngle angle() const;

    /**
     * @brief sectionOnSection - метод проверяет пересекаются ли 2 отрезка.
     * @param line - отрезок для которой определяется пересечение.
     * @return - результат проверки(true - отрезки пересекаются, false - отрезки
     * не пересекаются).
     */
    bool sectionOnSection( const MpLineSection &line ) const;

    /**
     * @brief pointToSection - метод проверяет принадлежит ли точка отрезку.
     * @param point - точка для которой происходит проверка.
     * @return - результат проверки(true - точка пренадлежит отрезку, false -
     * точка не пренадлежит отрезку).
     */
    bool pointToSection( const MpPoint &point ) const;

    /**
     * @brief midplane - метод возвращает среднию точку на отрезки.
     * @return - координаты средней точки.
     */
    MpPoint midplane();

    /**
     * @brief pointOnLine - метод возвращает координаты точки на отрезки с
     * заданным расстоянием от начало отрезка.
     * @param distance - расстояние от начало отрезка.
     * @param appertain - параметр показывающий, что заданное расстояние
     * превышает длину отрезка (true - заданное расстояние не превышает длину
     * отрезка, false - заданное расстояние превышает длину отрезка).
     * @return - координаты точки на отрезки.
     */
    MpPoint pointOnLine( const nreal &distance, bool &appertain ) const;

    /**
     * @brief isInfinity - Метод определяет равны ли координаты точек начала и
     * конца отрезка бесконечности.
     * @return результат проверки(true - точка начало или точка окончания
     * отрезка равны бесконечности, false - точка начало или точка окончания не
     * равны бесконечности).
     */
    bool isInfinity() const;

    /**
     * @brief isValid - Метод определяет корректны ли значения координат точек.
     * @return результат проверки(true - координаты точек корректны,
     * false - одна из координат точек равна nan.
     */
    bool isValid() const;

    static nreal lengthBrokerline( const QList<MpPoint> &list );

    MpLineSection &operator=( const MpLineSection &line );
    MpLineSection &operator=( MpLineSection &&line );

protected:
    /**
     * @brief equationLineQuick - метод расчитывает коэффициенты канонического
     * уравнения прямой.
     */
    void equationLineQuick();
};

inline MpLineSection::MpLineSection() : MpLine(), IMpLineSection(){}

inline MpLineSection::MpLineSection( const MpPoint &start, const MpPoint &end )
    : MpLine(), IMpLineSection( start, end )
{
    this->equationLineQuick();
}

inline void MpLineSection::setLine( const MpPoint &start, const MpPoint &end )
{
    IMpLineSection::setLine( start, end );
    this->equationLineQuick();
}

#endif // MPLINESECTION_H
