#ifndef NPOLYGONGEO_H
#define NPOLYGONGEO_H

#include "inpolygon.h"
#include "npointgeo.h"

/**
 * @brief The NPolygonGeo class - Класс содержащий методы и поля для работы с
 * геометрическим объектом полигон содержащие топографические координаты.
 */
class NPolygonGeo : public INPolygon<NPointGeo>
{
public:
    NPolygonGeo();
    NPolygonGeo( const QList<NPointGeo> &points );
    NPolygonGeo( const NPolygonGeo &polygonGeo );
    NPolygonGeo( NPolygonGeo &&polygonGeo );
    virtual ~NPolygonGeo();

    nreal length() const;

    nreal width() const;

    NAngle lengthCourse() const;

    /**
     * @brief setPolygon - метод создает прямоугольник на основе точки
     * пересечения диагоналей и размеров прямоугольника.
     * @param center - точка пересечения диагоналей.
     * @param length - длина прямоугольника.
     * @param width - ширина прямоугольника.
     * @return ссылка на класс.
     */
    NPolygonGeo &setPolygon( const NPointGeo &center, const double &length, const double &width );
    /**
     * @brief polygonInRectangle - метод возвращает прямоугольник в который
     * вписан полигон.
     * @return прямоугольник.
     */
    NPolygonGeo polygonInRectangle() const;
    /**
     * @brief leftUp - метод возвращает левый верхний угол.
     * @return координаты верхнего левого угла.
     */
    NPointGeo leftUp() const;
    /**
     * @brief rightDown - метод возвращает правый нижний угол.
     * @return координаты правого нижнего угла.
     */
    NPointGeo rightDown() const;
    /**
     * @brief pointCoupling - метод стягивает произвольную точку к ближайшей
     * стороне полигона.
     * @param pointGeo - произвольная точка с географическими координатами.
     * @return новая точка находящаяся на стороне полигона.
     */
    NPointGeo pointCoupling( const NPointGeo &pointGeo ) const;
    /**
     * @brief scalePolygon - метод расширяет правельный многоугольник на
     * заданное расстояния от границы.
     * @param distance - расстояние от границы многоугольника.
     * @return новый многоугольник подобный данному.
     */
    NPolygonGeo scalePolygon( const nreal &distance ) const;
    /**
     * @brief pointAppertainPolygon - метод определяет попадает ли точка в
     * полигон.
     * @param pointGeo - точка для которой определяется попадание.
     * @return результат проверки(true - точка попадает в полигон,
     * false - точка не попадает в полигон)
     */
    bool pointAppertainPolygon( const NPointGeo &pointGeo ) const;
    /**
     * @brief polygonAppertainPolygon - метод определяет попадает ли точка в
     * полигон.
     * @param polygon - точка для которой определяется попадание.
     * @return результат проверки(true - точка попадает в полигон,
     * false - точка не попадает в полигон).
     */
    bool polygonAppertainPolygon( const NPolygonGeo &polygon ) const;
    /**
     * @brief center - метод возвращает центр полигона.
     * @return координаты центра полигона.
     */
    NPointGeo center() const;
    /**
     * @brief polygonCenter - метод строит прямоугольник по центру и длинам
     * сторон прямоугольника.
     * @param length - длина прямоугольника.
     * @param width - ширина прямоугольника.
     * @param center - центр прямоугольника.
     * @return новый прямоугольник.
     */
    static NPolygonGeo polygonCenter( const nreal &length,
                               const nreal &width, const NPointGeo &center );
    /**
     * @brief polygonWidth - метод строит прямоугольник по точке лещаший на
     * одной стороне и длинам сторон прямоугольника.
     * @param length - длина прямоугольника.
     * @param width - ширина прямоугольника.
     * @param course - точка на стороне прямоугольника.
     * @param point - направление прямоугольника.
     * @return новый прямоугольник.
     */
    static NPolygonGeo polygonWidth( const nreal &length,
                                      const nreal &width,
                                      const NAngle &course,
                                      const NPointGeo &point );


    static NPolygonGeo polygonCenterCourse( const nreal &length,
                                             const nreal &width,
                                             const NAngle &course,
                                             const NPointGeo &center );

    NPolygonGeo &operator=( const NPolygonGeo &polygonGeo );
    NPolygonGeo &operator=( NPolygonGeo &&polygonGeo );
};

inline NPolygonGeo::NPolygonGeo() : INPolygon(){}

inline NPolygonGeo::NPolygonGeo( const QList<NPointGeo> &points )
    : INPolygon(points){}

#endif // NPOLYGONGEO_H
