#ifndef MPPOLYGONGEO_H
#define MPPOLYGONGEO_H

#include "imppolygon.h"
#include "mppointgeo.h"

/**
 * @brief The MpPolygonGeo class - Класс содержащий методы и поля для работы с
 * геометрическим объектом полигон содержащие топографические координаты.
 */
class MpPolygonGeo : public IMpPolygon<MpPointGeo>
{
public:
    MpPolygonGeo();
    MpPolygonGeo( const QList<MpPointGeo> &points );
    MpPolygonGeo( const MpPolygonGeo &polygonGeo );
    MpPolygonGeo( MpPolygonGeo &&polygonGeo );
    virtual ~MpPolygonGeo();

    nreal length() const;

    nreal width() const;

    MpAngle lengthCourse() const;

    /**
     * @brief setPolygon - метод создает прямоугольник на основе точки
     * пересечения диагоналей и размеров прямоугольника.
     * @param center - точка пересечения диагоналей.
     * @param length - длина прямоугольника.
     * @param width - ширина прямоугольника.
     * @return ссылка на класс.
     */
    MpPolygonGeo &setPolygon( const MpPointGeo &center, const double &length, const double &width );
    /**
     * @brief polygonInRectangle - метод возвращает прямоугольник в который
     * вписан полигон.
     * @return прямоугольник.
     */
    MpPolygonGeo polygonInRectangle() const;
    /**
     * @brief leftUp - метод возвращает левый верхний угол.
     * @return координаты верхнего левого угла.
     */
    MpPointGeo leftUp() const;
    /**
     * @brief rightDown - метод возвращает правый нижний угол.
     * @return координаты правого нижнего угла.
     */
    MpPointGeo rightDown() const;
    /**
     * @brief pointCoupling - метод стягивает произвольную точку к ближайшей
     * стороне полигона.
     * @param pointGeo - произвольная точка с географическими координатами.
     * @return новая точка находящаяся на стороне полигона.
     */
    MpPointGeo pointCoupling( const MpPointGeo &pointGeo ) const;
    /**
     * @brief scalePolygon - метод расширяет правельный многоугольник на
     * заданное расстояния от границы.
     * @param distance - расстояние от границы многоугольника.
     * @return новый многоугольник подобный данному.
     */
    MpPolygonGeo scalePolygon( const nreal &distance ) const;
    /**
     * @brief pointAppertainPolygon - метод определяет попадает ли точка в
     * полигон.
     * @param pointGeo - точка для которой определяется попадание.
     * @return результат проверки(true - точка попадает в полигон,
     * false - точка не попадает в полигон)
     */
    bool pointAppertainPolygon( const MpPointGeo &pointGeo ) const;
    /**
     * @brief polygonAppertainPolygon - метод определяет попадает ли точка в
     * полигон.
     * @param polygon - точка для которой определяется попадание.
     * @return результат проверки(true - точка попадает в полигон,
     * false - точка не попадает в полигон).
     */
    bool polygonAppertainPolygon( const MpPolygonGeo &polygon ) const;
    /**
     * @brief center - метод возвращает центр полигона.
     * @return координаты центра полигона.
     */
    MpPointGeo center() const;
    /**
     * @brief polygonCenter - метод строит прямоугольник по центру и длинам
     * сторон прямоугольника.
     * @param length - длина прямоугольника.
     * @param width - ширина прямоугольника.
     * @param center - центр прямоугольника.
     * @return новый прямоугольник.
     */
    static MpPolygonGeo polygonCenter( const nreal &length,
                               const nreal &width, const MpPointGeo &center );
    /**
     * @brief polygonWidth - метод строит прямоугольник по точке лещаший на
     * одной стороне и длинам сторон прямоугольника.
     * @param length - длина прямоугольника.
     * @param width - ширина прямоугольника.
     * @param course - точка на стороне прямоугольника.
     * @param point - направление прямоугольника.
     * @return новый прямоугольник.
     */
    static MpPolygonGeo polygonWidth( const nreal &length,
                                      const nreal &width,
                                      const MpAngle &course,
                                      const MpPointGeo &point );


    static MpPolygonGeo polygonCenterCourse( const nreal &length,
                                             const nreal &width,
                                             const MpAngle &course,
                                             const MpPointGeo &center );

    MpPolygonGeo &operator=( const MpPolygonGeo &polygonGeo );
    MpPolygonGeo &operator=( MpPolygonGeo &&polygonGeo );
};

inline MpPolygonGeo::MpPolygonGeo() : IMpPolygon(){}

inline MpPolygonGeo::MpPolygonGeo( const QList<MpPointGeo> &points )
    : IMpPolygon(points){}

#endif // MPPOLYGONGEO_H
