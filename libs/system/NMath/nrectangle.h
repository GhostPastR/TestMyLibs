#ifndef NRECTANGLE_H
#define NRECTANGLE_H

#include "npolygon.h"
#include "npoint.h"

class NRectangle : public NPolygon
{
public:
    NRectangle( const NPoint &leftTop, const NPoint &rightBotton );
    NRectangle( const NPoint &leftTop, const nreal &width,
                 const NAngle &angleWidth, const nreal &height,
                 const NAngle &angleHeight );
    /**
     * @brief NRectangle - Конструктор задаёт прямоугольник по центру (точка
     * пересечения диагоналей) и сторонам.
     * @param length - длина прямоугольника.
     * @param width - ширина прямоугольника.
     * @param center - центр прямоугольника.
     */
    NRectangle( const nreal &length, const nreal &width,
                 const NPoint &center );
    NRectangle( const NPolygon &polygon );
    NRectangle( const NRectangle &NRectangle );
    NRectangle( NRectangle &&NRectangle );
    ~NRectangle();

    NRectangle &operator=( const NRectangle &NRectangle );
    NRectangle &operator=( NRectangle &&NRectangle );

    /**
     * @brief leftBottom - Метод возвращает левую нижнию вершину в
     * прямоугольники.
     * @return левая нижния вершина.
     */
    NPoint leftBottom() const;
    /**
     * @brief leftTop - Метод возвращает левую верхнею вершину в
     * прямоугольники.
     * @return левая верхняя вершина.
     */
    NPoint leftTop() const;
    /**
     * @brief rightTop - Метод возвращает правую верхнею вершину в
     * прямоугольники.
     * @return правая верхняя вершина.
     */
    NPoint rightTop() const;
    /**
     * @brief rightBottom - Метод возвращает правую нижнию вершину в
     * прямоугольники.
     * @return правая нижняя вершина.
     */
    NPoint rightBottom() const;

    /**
     * @brief center - метод находит координаты центра прямоугольника.
     * @return центр прямоугольника.
     */
    NPoint center() const;

private:

    /**
     * @brief vertixRect - Шаблонный метод который возвращает вершиныв по 2-м
     * условиям в прямоугольнике.
     * @param method1 - Метод для 1-го условия по координате y.
     * @param method2 - Метод для 2-го условия по координате x.
     * @return вершина прямоугольники.
     */
    template<typename M1, typename M2>
    NPoint vertixRect( M1 method1, M2 method2 ) const;
};

template<typename M1, typename M2>
inline NPoint NRectangle::vertixRect( M1 method1, M2 method2 ) const
{
    if( !this->isValid() )
        return NPoint();
    QPair<NPoint,NPoint> _pair;
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

#endif // NRECTANGLE_H
