#ifndef NLINESECTION_H
#define NLINESECTION_H

#include <QList>
#include "nline.h"
#include "inlinesection.h"

class NLineSection : public NLine, public INLineSection<NPoint>
{
public:
    NLineSection();
    NLineSection( const NPoint &start, const NPoint &end );
    NLineSection( const NLineSection &line );
    NLineSection( NLineSection &&line );
    ~NLineSection();

    void setLine( const NPoint &start, const NPoint &end );

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
    NAngle angle() const;

    /**
     * @brief sectionOnSection - метод проверяет пересекаются ли 2 отрезка.
     * @param line - отрезок для которой определяется пересечение.
     * @return - результат проверки(true - отрезки пересекаются, false - отрезки
     * не пересекаются).
     */
    bool sectionOnSection( const NLineSection &line ) const;

    /**
     * @brief pointToSection - метод проверяет принадлежит ли точка отрезку.
     * @param point - точка для которой происходит проверка.
     * @return - результат проверки(true - точка пренадлежит отрезку, false -
     * точка не пренадлежит отрезку).
     */
    bool pointToSection( const NPoint &point ) const;

    /**
     * @brief midplane - метод возвращает среднию точку на отрезки.
     * @return - координаты средней точки.
     */
    NPoint midplane();

    /**
     * @brief pointOnLine - метод возвращает координаты точки на отрезки с
     * заданным расстоянием от начало отрезка.
     * @param distance - расстояние от начало отрезка.
     * @param appertain - параметр показывающий, что заданное расстояние
     * превышает длину отрезка (true - заданное расстояние не превышает длину
     * отрезка, false - заданное расстояние превышает длину отрезка).
     * @return - координаты точки на отрезки.
     */
    NPoint pointOnLine( const nreal &distance, bool &appertain ) const;

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

    static nreal lengthBrokerline( const QList<NPoint> &list );

    NLineSection &operator=( const NLineSection &line );
    NLineSection &operator=( NLineSection &&line );

protected:
    /**
     * @brief equationLineQuick - метод расчитывает коэффициенты канонического
     * уравнения прямой.
     */
    void equationLineQuick();
};

inline NLineSection::NLineSection() : NLine(), INLineSection(){}

inline NLineSection::NLineSection( const NPoint &start, const NPoint &end )
    : NLine(), INLineSection( start, end )
{
    this->equationLineQuick();
}

inline void NLineSection::setLine( const NPoint &start, const NPoint &end )
{
    INLineSection::setLine( start, end );
    this->equationLineQuick();
}

#endif // NLINESECTION_H
