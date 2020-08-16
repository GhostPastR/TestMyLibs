#ifndef MPRECTANGLEGEO_H
#define MPRECTANGLEGEO_H

#include "mppolygongeo.h"

class MpRelativePoint;

class MpRectangleGeo : public MpPolygonGeo
{
public:
    MpRectangleGeo( const MpPointGeo &leftTop, const MpPointGeo &rightBotton );
    MpRectangleGeo( const MpPointGeo &leftTop, const nreal &width,
                    const MpAngle &angleWidth, const nreal &height,
                    const MpAngle &angleHeight );
    MpRectangleGeo( const nreal &length, const nreal &width,
                    const MpPointGeo &center );
    MpRectangleGeo( const MpPolygonGeo &polygon );
    MpRectangleGeo( const MpRectangleGeo &mpRectangle );
    MpRectangleGeo( MpRectangleGeo &&mpRectangle );
    ~MpRectangleGeo();

    MpRectangleGeo &operator=( const MpRectangleGeo &mpRectangle );
    MpRectangleGeo &operator=( MpRectangleGeo &&mpRectangle );

    /**
     * @brief leftBottom - Метод возвращает левую нижнию вершину в
     * прямоугольники.
     * @return левая нижния вершина.
     */
    MpPointGeo leftBottom() const;
    /**
     * @brief leftTop - Метод возвращает левую верхнею вершину в
     * прямоугольники.
     * @return левая верхняя вершина.
     */
    MpPointGeo leftTop() const;
    /**
     * @brief rightTop - Метод возвращает правую верхнею вершину в
     * прямоугольники.
     * @return правая верхняя вершина.
     */
    MpPointGeo rightTop() const;
    /**
     * @brief rightBottom - Метод возвращает правую нижнию вершину в
     * прямоугольники.
     * @return правая нижняя вершина.
     */
    MpPointGeo rightBottom() const;

    /**
     * @brief center - метод возвращает центр полигона.
     * @return координаты центра полигона.
     */
    MpPointGeo center() const;

private:
    typedef MpRelativePoint RP;
};

#endif // MPRECTANGLEGEO_H
