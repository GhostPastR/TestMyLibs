#ifndef MPPOLYGON_H
#define MPPOLYGON_H

#include "imppolygon.h"
#include "mplinesection.h"

/**
 * @brief The MpPolygon class - Класс содержащий поля и методы для работы с
 * геометрической объектом полигон.
 */
class MpPolygon : public IMpPolygon<MpPoint>
{
public:
    MpPolygon( );
    MpPolygon( int count );
    MpPolygon( const QList<MpPoint> &points );
    MpPolygon( const MpPolygon &polygon );
    MpPolygon( MpPolygon &&polygon );
    virtual ~MpPolygon();

    void compact( const nreal &distans );

    /**
     * @brief getLine - метод возвращает список отрезков, из которого состоит
     * полигон.
     * @return - список отрезков.
     */
    QList<MpLineSection> getLine() const;

    /**
     * @brief pointAppertainPolygon - метод определяет попадает ли точка в
     * полигон.
     * @param point - точка для которой определяется попадание.
     * @return результат проверки(true - точка попадает в полигон, false - точка
     * не попадает в полигон).
     */
    bool pointAppertainPolygon( const MpPoint &point ) const;

    /**
     * @brief polygonAppertainPolygon - метод определяет пересикает ли полигон
     * другой полигон.
     * @param polygon - полигон для которой определяется пересечения.
     * @return - результат проверки(true - полигоны пересекаются,
     * false - полигоны не пересекаются).
     */
    bool polygonAppertainPolygon( const MpPolygon &polygon ) const;

    /**
     * @brief polygonAppertainSection - метод определяет попадает ли отрезок в
     * полигон.
     * @param section - отрезок для которой определяется попадание.
     * @return - результат проверки(true - отрезок попадает в полигон,
     * false - отрезок не попадает в полигон).
     */
    bool polygonAppertainSection( const MpLineSection &section ) const;

    /**
     * @brief polygonApertainLine - метод определяет пересечение линии со
     * сторонами прямоугольника.
     * @param section - линия.
     * @return список точек пересечения с линией.
     */
    QList<MpPoint> polygonApertainLine( const MpLineSection &section ) const;

    /**
     * @brief polygonApertainLineSection - метод определяет пересечение отрезока
     * со сторонами прямоугольника.
     * @param section - отрезок.
     * @return список точек пересечения с линией.
     */
    bool polygonApertainLineSection( const MpLineSection &section ) const;

    /**
     * @brief pointCoupling - метод стягивает произвольную точку к ближайшей
     * стороне полигона.
     * @param point - произвольная точка на плоскости.
     * @return новая точка находящаяся на стороне полигона.
     */
    MpPoint pointCoupling( const MpPoint &point ) const;

    /**
     * @brief polygonInRectangle - метод возвращает прямоугольник в который
     * вписан полигон.
     * @return прямоугольник.
     */
    MpPolygon polygonInRectangle() const;

    /**
     * @brief polygonInRectangleMin - метод возвращает минимальный прямоугольник
     * в который вписан полигон.
     * @return прямоугольник.
     */
    MpPolygon polygonInRectangleMin() const;

    /**
     * @brief scalePolygon - метод расширяет правельный многоугольник на
     * заданное расстояния от границы.
     * @param distance - расстояние от границы многоугольника.
     * @return новый многоугольник подобный данному.
     */
    MpPolygon scalePolygon( const nreal &distance ) const;

    /**
     * @brief polugAppertainPolug - метод определяет попадает ли полигон в
     * полигон.
     * @param polygon - полигон для которой определяется попадание.
     * @return результат проверки(true - полигон находится внутри другого
     * полигона, false - полигоны находится частично внутри или вне полигона).
     */
    bool polugAppertainPolug( const MpPolygon &polygon ) const;

    /**
     * @brief polugAppertainPartPolug - метод определяет частичное попадание
     * полигона в полигон.
     * @param polygon - полигон для которой определяется частичное попадание.
     * @return результат проверки(true - полигон частично находится внутри
     * другого полигона, false - полигоны находится вне полигона).
     */
    bool polugAppertainPartPolug( const MpPolygon &polygon ) const;

    /**
     * @brief center - метод находит центр полигона если он прямоугольник.
     * @return центр прямоугольника.
     */
    MpPoint center() const;

    /**
     * @brief moveListPoint - метод ориентирует прямоугольник по заданному углу.
     * @param course - угол для ориетирования.
     * @return ссылка на класс.
     */
    MpPolygon &moveListPoint( const MpAngle &course );

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
     * @brief polygonCenter - метод строит прямоугольник по центру и сторонам.
     * @param length - длина прямоугольника.
     * @param width - ширина прямоугольника.
     * @param center - центр прямоугольника.
     * @return новый прямоугольник.
     */
    static MpPolygon polygonCenter( const nreal &length, const nreal &width,
                                    const MpPoint &center );

    MpPolygon &operator=( const MpPolygon &polygon );
    MpPolygon &operator=( MpPolygon &&polygon );

private:
    /**
     * @brief minMaxPoint - Метод возвращает две точки с минимальными и
     * максимальными координатами. Координаты соответствуют вершинам полигона.
     * @return две точки с минимальными и максимальными координатами.
     */
    QPair<MpPoint, MpPoint> minMaxPoint() const;

    template<typename M1, typename M2>
    /**
     * @brief vertixRect - Шаблонный метод который возвращает вершиныв по 2-м
     * условиям в прямоугольнике.
     * @param method1 - Метод для 1-го условия по координате y.
     * @param method2 - Метод для 2-го условия по координате x.
     * @return вершина прямоугольники.
     */
    MpPoint vertixRect( M1 method1, M2 method2 ) const;
};

inline MpPolygon::MpPolygon() : IMpPolygon(){}

inline MpPolygon::MpPolygon( const QList<MpPoint> &points )
    : IMpPolygon(points){}

template<typename M1, typename M2>
inline MpPoint MpPolygon::vertixRect( M1 method1, M2 method2 ) const
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

#endif // MPPOLYGON_H
