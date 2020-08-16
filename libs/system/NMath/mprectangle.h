#ifndef MPRECTANGLE_H
#define MPRECTANGLE_H

#include "mppolygon.h"
#include "mppoint.h"

class MpRectangle : public MpPolygon
{
public:
    MpRectangle( const MpPoint &leftTop, const MpPoint &rightBotton );
    MpRectangle( const MpPoint &leftTop, const nreal &width,
                 const MpAngle &angleWidth, const nreal &height,
                 const MpAngle &angleHeight );
    /**
     * @brief MpRectangle - Конструктор задаёт прямоугольник по центру (точка
     * пересечения диагоналей) и сторонам.
     * @param length - длина прямоугольника.
     * @param width - ширина прямоугольника.
     * @param center - центр прямоугольника.
     */
    MpRectangle( const nreal &length, const nreal &width,
                 const MpPoint &center );
    MpRectangle( const MpPolygon &polygon );
    MpRectangle( const MpRectangle &mpRectangle );
    MpRectangle( MpRectangle &&mpRectangle );
    ~MpRectangle();

    MpRectangle &operator=( const MpRectangle &mpRectangle );
    MpRectangle &operator=( MpRectangle &&mpRectangle );

    /**
     * @brief leftBottom - Метод возвращает левую нижнию вершину в
     * прямоугольники.
     * @return левая нижния вершина.
     */
    MpPoint leftBottom() const;
    /**
     * @brief leftTop - Метод возвращает левую верхнею вершину в
     * прямоугольники.
     * @return левая верхняя вершина.
     */
    MpPoint leftTop() const;
    /**
     * @brief rightTop - Метод возвращает правую верхнею вершину в
     * прямоугольники.
     * @return правая верхняя вершина.
     */
    MpPoint rightTop() const;
    /**
     * @brief rightBottom - Метод возвращает правую нижнию вершину в
     * прямоугольники.
     * @return правая нижняя вершина.
     */
    MpPoint rightBottom() const;

    /**
     * @brief center - метод находит координаты центра прямоугольника.
     * @return центр прямоугольника.
     */
    MpPoint center() const;

private:

    /**
     * @brief vertixRect - Шаблонный метод который возвращает вершиныв по 2-м
     * условиям в прямоугольнике.
     * @param method1 - Метод для 1-го условия по координате y.
     * @param method2 - Метод для 2-го условия по координате x.
     * @return вершина прямоугольники.
     */
    template<typename M1, typename M2>
    MpPoint vertixRect( M1 method1, M2 method2 ) const;
};

template<typename M1, typename M2>
inline MpPoint MpRectangle::vertixRect( M1 method1, M2 method2 ) const
{
    if( !this->isValid() )
        return MpPoint();
    QPair<MpPoint,MpPoint> _pair;
    _pair.first = this->points_.at(0);
    _pair.second = this->points_.at(1);
    if( !method1( _pair.first.y(), _pair.second.y() ) )
        std::swap( _pair.first, _pair.second );
    for ( int i = 2, count = this->points_.count(); i < count; i++ )
    {
        if( method1( this->points_.at(i).y(), _pair.second.y() ) )
        {
            if( method1( this->points_.at(i).y(), _pair.first.y() ) )
            {
                _pair.second = _pair.first;
                _pair.first = this->points_.at(i);
            }
            else
            {
                _pair.second = this->points_.at(i);
            }
        }
    }
    if( method2( _pair.first.x(), _pair.second.x() ) )
        return _pair.first;
    return  _pair.second;
}

#endif // MPRECTANGLE_H
