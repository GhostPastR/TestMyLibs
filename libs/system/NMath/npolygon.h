#ifndef NPOLYGON_H
#define NPOLYGON_H

#include "inpolygon.h"
#include "nlinesection.h"

/**
 * @brief The NPolygon class - Класс содержащий поля и методы для работы с
 * геометрической объектом полигон.
 */
class NPolygon : public INPolygon<NPoint>
{
public:
    NPolygon( );
    NPolygon( int count );
    NPolygon( const QList<NPoint> &points );
    NPolygon( const NPolygon &polygon );
    NPolygon( NPolygon &&polygon );
    virtual ~NPolygon();

    void compact( const nreal &distans );

    /**
     * @brief getLine - метод возвращает список отрезков, из которого состоит
     * полигон.
     * @return - список отрезков.
     */
    QList<NLineSection> getLine() const;

    /**
     * @brief pointAppertainPolygon - метод определяет попадает ли точка в
     * полигон.
     * @param point - точка для которой определяется попадание.
     * @return результат проверки(true - точка попадает в полигон, false - точка
     * не попадает в полигон).
     */
    bool pointAppertainPolygon( const NPoint &point ) const;

    /**
     * @brief polygonAppertainPolygon - метод определяет пересикает ли полигон
     * другой полигон.
     * @param polygon - полигон для которой определяется пересечения.
     * @return - результат проверки(true - полигоны пересекаются,
     * false - полигоны не пересекаются).
     */
    bool polygonAppertainPolygon( const NPolygon &polygon ) const;

    /**
     * @brief polygonAppertainSection - метод определяет попадает ли отрезок в
     * полигон.
     * @param section - отрезок для которой определяется попадание.
     * @return - результат проверки(true - отрезок попадает в полигон,
     * false - отрезок не попадает в полигон).
     */
    bool polygonAppertainSection( const NLineSection &section ) const;

    /**
     * @brief polygonApertainLine - метод определяет пересечение линии со
     * сторонами прямоугольника.
     * @param section - линия.
     * @return список точек пересечения с линией.
     */
    QList<NPoint> polygonApertainLine( const NLineSection &section ) const;

    /**
     * @brief polygonApertainLineSection - метод определяет пересечение отрезока
     * со сторонами прямоугольника.
     * @param section - отрезок.
     * @return список точек пересечения с линией.
     */
    bool polygonApertainLineSection( const NLineSection &section ) const;

    /**
     * @brief pointCoupling - метод стягивает произвольную точку к ближайшей
     * стороне полигона.
     * @param point - произвольная точка на плоскости.
     * @return новая точка находящаяся на стороне полигона.
     */
    NPoint pointCoupling( const NPoint &point ) const;

    /**
     * @brief polygonInRectangle - метод возвращает прямоугольник в который
     * вписан полигон.
     * @return прямоугольник.
     */
    NPolygon polygonInRectangle() const;

    /**
     * @brief polygonInRectangleMin - метод возвращает минимальный прямоугольник
     * в который вписан полигон.
     * @return прямоугольник.
     */
    NPolygon polygonInRectangleMin() const;

    /**
     * @brief scalePolygon - метод расширяет правельный многоугольник на
     * заданное расстояния от границы.
     * @param distance - расстояние от границы многоугольника.
     * @return новый многоугольник подобный данному.
     */
    NPolygon scalePolygon( const nreal &distance ) const;

    /**
     * @brief polugAppertainPolug - метод определяет попадает ли полигон в
     * полигон.
     * @param polygon - полигон для которой определяется попадание.
     * @return результат проверки(true - полигон находится внутри другого
     * полигона, false - полигоны находится частично внутри или вне полигона).
     */
    bool polugAppertainPolug( const NPolygon &polygon ) const;

    /**
     * @brief polugAppertainPartPolug - метод определяет частичное попадание
     * полигона в полигон.
     * @param polygon - полигон для которой определяется частичное попадание.
     * @return результат проверки(true - полигон частично находится внутри
     * другого полигона, false - полигоны находится вне полигона).
     */
    bool polugAppertainPartPolug( const NPolygon &polygon ) const;

    /**
     * @brief center - метод находит центр полигона если он прямоугольник.
     * @return центр прямоугольника.
     */
    NPoint center() const;

    /**
     * @brief moveListPoint - метод ориентирует прямоугольник по заданному углу.
     * @param course - угол для ориетирования.
     * @return ссылка на класс.
     */
    NPolygon &moveListPoint( const NAngle &course );

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
     * @brief polygonCenter - метод строит прямоугольник по центру и сторонам.
     * @param length - длина прямоугольника.
     * @param width - ширина прямоугольника.
     * @param center - центр прямоугольника.
     * @return новый прямоугольник.
     */
    static NPolygon polygonCenter( const nreal &length, const nreal &width,
                                    const NPoint &center );

    NPolygon &operator=( const NPolygon &polygon );
    NPolygon &operator=( NPolygon &&polygon );

private:
    /**
     * @brief minMaxPoint - Метод возвращает две точки с минимальными и
     * максимальными координатами. Координаты соответствуют вершинам полигона.
     * @return две точки с минимальными и максимальными координатами.
     */
    QPair<NPoint, NPoint> minMaxPoint() const;

    template<typename M1, typename M2>
    /**
     * @brief vertixRect - Шаблонный метод который возвращает вершиныв по 2-м
     * условиям в прямоугольнике.
     * @param method1 - Метод для 1-го условия по координате y.
     * @param method2 - Метод для 2-го условия по координате x.
     * @return вершина прямоугольники.
     */
    NPoint vertixRect( M1 method1, M2 method2 ) const;
};

inline NPolygon::NPolygon() : INPolygon(){}

inline NPolygon::NPolygon( const QList<NPoint> &points )
    : INPolygon(points){}

template<typename M1, typename M2>
inline NPoint NPolygon::vertixRect( M1 method1, M2 method2 ) const
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

#endif // NPOLYGON_H
