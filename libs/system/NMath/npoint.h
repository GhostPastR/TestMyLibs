#ifndef NPOINT_H
#define NPOINT_H

#include "nbase.h"
#include <nangle.h>

/**
 * @brief The NPoint class - Класс содержащий поля и методы для работы с
 * геометрической объектом точка(декартовые координаты)
 */
class NPoint
{
public:
    NPoint();
    NPoint( const nreal &x, const nreal &y );
    NPoint( const NPoint &point );
    NPoint( NPoint &&point );
    virtual ~NPoint();

    const nreal &x() const;
    const nreal &y() const;

    void setX( const nreal &x );
    void setY( const nreal &y );
    void setXY( const nreal &x, const nreal &y );

    /**
     * @brief angleToPoint - возвращает направление отрезка от текущей точки
     * до заданной точки(входной параметр методы).
     * @param point - точка для которой определяют направления.
     * @return угол в радианах.
     */
    NAngle angleToPoint( const NPoint &point ) const;

    /**
     * @brief angleFromPoint - возвращает направление отрезка от заданной
     * точки(входной параметр методы) до текущей точки.
     * @param point - точка от которой определяются направления.
     * @return угол в радианах.
     */
    NAngle angleFromPoint( const NPoint &point = NPoint() ) const;

    /**
     * @brief distance - возвращает длину между 2-мя точками.
     * @param point - точка до которой определяют точка.
     * @return расстояние между точками.
     */
    nreal distance( const NPoint &point = NPoint() ) const;

    /**
     * @brief newPoint - метод расчитывает координаты новой точки относительно
     * экземпляра класса по направлению и дальности до точки
     * @param omnibearing - направление на новую точку.
     * @param range - расстояния до новой точки.
     * @return координаты новой точки.
     */
    NPoint point( const NAngle &omnibearing, const nreal &range ) const;

    /**
     * @brief transormation - метод преобразует текущие координаты относительно
     * заданной точки и угла поворота(текущие координаты точки внутри класса
     * не меняются).
     * @param angle - угол поворота в радианах.
     * @param start - точка относительно которой происходит поворот.
     * @return новые координаты точки.
     */
    NPoint transormation( const NAngle &angle,
                           const NPoint &start = NPoint() ) const;

    /**
     * @brief setCoordinate - метод задает координаты относительно нулевой точки
     *  с учетом пеленга и дальности на точку.
     * @param omnibearing - пеленг на точку в радианах.
     * @param range расстояние до точки.
     */
    void setCoordinate( const NAngle &omnibearing, const nreal &range );

    /**
     * @brief compare - метод проверяет совпадают ли точки.
     * @param point - точка с которой сравнивают.
     * @return результат проверки( true - точки совпадают, false - точки не
     * совпадают ).
     */
    bool compare( const NPoint &point ) const;

    /**
     * @brief midplane - метод возвращает среднию точку между точками.
     * @param point - точка относительно которой будет определена средняя точка.
     * @return координаты cредней точки.
     */
    NPoint midplane( const NPoint &point ) const;

    /**
     * @brief isInfinity - Метод определяет равны ли значения X или Y
     * бесконечности.
     * @return результат проверки(true - X или Y равен бесконечности, false -
     * X и Y не равны бесконечности).
     */
    bool isInfinity() const;

    /**
     * @brief isValid - Метод определяет корректны ли значения координат точки.
     * @return результат проверки(true - координаты точки корректны,
     * false - одна из координат равна nan.
     */
    bool isValid() const;

    /**
     * @brief angle - статический метод определяет направление от точки 'start'
     * до точки 'stop'.
     * @param start - точка от которой определяется напрвление.
     * @param stop - точка до которой определяется напрвление.
     * @return направления точки относительно точки 'start'.
     */
    static NAngle angle( const NPoint &start, const NPoint &stop );

    /**
     * @brief transormation - статический метод преобразует текущие координаты
     * точки 'point' относительно заданной точки 'start' и угла поворота(текущие
     * координаты точки внутри класса не меняются).
     * @param point - текущие координаты точки.
     * @param angle - угол поворота в радианах.
     * @param start - точка относительно которой происходит поворот.
     * @return новые координаты точки.
     */
    static NPoint transormation( const NPoint &point, const NAngle &angle,
                                  const NPoint &start = NPoint() );

    /**
     * @brief newPoint - статический метод возвращает координаты относительно
     * заданной точки 'point' с учетом пеленга и дальности на новую точку.
     * @param omnibearing - направление на новую точку в радианах.
     * @param range - расстояния на новую точку.
     * @param point - точко относительно, которой рассчитывается новая точка.
     * @return координаты новой точки.
     */
    static NPoint newPoint( const NAngle &omnibearing, const nreal &range,
                             const NPoint &point = NPoint() );

    NPoint &operator=( const NPoint &point );
    NPoint &operator=( NPoint &&point );

    bool operator ==( const NPoint &point );

protected:
    nreal x_;  //!Декартовая координата X
    nreal y_;  //!Декартовая координата Y
};

inline NPoint::NPoint( ) : x_(nreal(0.0)), y_(nreal(0.0)){}

inline NPoint::NPoint( const nreal &x, const nreal &y  )
    : x_( x ), y_( y ){}

inline const nreal &NPoint::x() const
{
    return this->x_;
}

inline const nreal &NPoint::y() const
{
    return this->y_;
}

inline void NPoint::setX( const nreal &x )
{
    this->x_ = x;
}

inline void NPoint::setY( const nreal &y )
{
    this->y_ = y;
}

inline void NPoint::setXY( const nreal &x, const nreal &y )
{
    this->x_ = x;
    this->y_ = y;
}

#endif // NPOINT_H
