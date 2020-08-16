#ifndef MPLINE_H
#define MPLINE_H

#include "mppoint.h"

/**
 * @brief The MpLine class - Класс содержащий поля и методы для работы с
 * геометрической объектом прямая.
 */
class MpLine
{
public:
    MpLine();
    MpLine( const nreal &a, const nreal &b, const nreal &c );
    MpLine( const MpLine &line );
    MpLine( MpLine &&line );
    virtual ~MpLine();

    const nreal &a() const;
    const nreal &b() const;
    const nreal &c() const;

    /**
     * @brief setCoefficientEquation - метод задает коэффициенты уравнения
     * прямой.
     * @param a - коэффициент A уравнения Ax + By + C = 0.
     * @param b - коэффициент B уравнения Ax + By + C = 0.
     * @param c - коэффициент C уравнения Ax + By + C = 0.
     */
    void setCoefficientEquation( const nreal &a, const nreal &b,
                                 const nreal &c );

    /**
     * @brief distanceToLine - метод возвращает кратчайшие расстояние от точки
     * до прямой.
     * @param point - точка для которой нужно рассчитать расстояние.
     * @return - расстояние от точкм до прямой.
     */
    nreal distanceToLine( const MpPoint &point ) const;

    /**
     * @brief getValueFunction - метод возвращает значение функции
     * f(x,y) = Ax + By + C.
     * @param point - точка для которой вычисляется значение функции.
     * @return - значение функции.
     */
    nreal getValueFunction( const MpPoint &point ) const;

    /**
     * @brief intersectionLine - метод возвращает точку пересечения 2-х прямых.
     * @param line - прямая для которой определяется пересечение.
     * @return - координаты точки пересечения(Координаты точки равны
     * бесконечности, если лучи не пересекаются).
     */
    MpPoint intersectionLine( const MpLine &line ) const;

    /**
     * @brief checkPointOnLine - метод проверяет принадлежит ли точка прямой.
     * @param point - точка для которой происходит проверка.
     * @return - результат проверки(true - точка пренадлежит прямой, false -
     * точка не пренадлежит прямой).
     */
    bool checkPointOnLine( const MpPoint point ) const;

    /**
     * @brief parallelLine - метод возвращает параллельную прямую, находящиеся
     * на заданом расстоянии от данной прямой(если distance < 0, то прямая будет
     * расположена с лево, в других случаях с право).
     * @param distance - расстоянии от прямой.
     * @return - прямую параллельную данной.
     */
    MpLine parallelLine( const nreal &distance ) const;

    /**
     * @brief pointPerpendicular - метод возвращает точку основания
     * перпендикуляра, опущенную из заданной точки на прямую.
     * @param point - точка от которой опускается перпендикуляр к прямой.
     * @return - координаты точки основания перпендикуляра.
     */
    MpPoint pointPerpendicular( const MpPoint &point ) const;

    MpLine &operator=( const MpLine &line );
    MpLine &operator=( MpLine &line );

    /**
     * @brief equationLineQuick - метод расчитывает коэффициенты канонического
     * уравнения прямой.
     * @param point1 - 1-я точка прямой.
     * @param point2 - 2-я точка прямой.
     * @return геометрический объект прямая.
     */
    static MpLine equationLineQuick( const MpPoint &point1,
                                     const MpPoint &point2 );

protected:
    /**
     * @brief a_ - Коэффициент A уравнения Ax + By + C = 0.
     */
    nreal a_;
    /**
     * @brief b_ - Коэффициент B уравнения Ax + By + C = 0.
     */
    nreal b_;
    /**
     * @brief c_ - Коэффициент C уравнения Ax + By + C = 0.
     */
    nreal c_;
};

inline MpLine::MpLine(){}

inline const nreal &MpLine::a() const
{
    return this->a_;
}

inline const nreal &MpLine::b() const
{
    return this->b_;
}

inline const nreal &MpLine::c() const
{
    return this->c_;
}

#endif // MPLINE_H
