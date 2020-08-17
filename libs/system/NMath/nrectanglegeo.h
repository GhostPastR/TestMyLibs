#ifndef NRECTANGLEGEO_H
#define NRECTANGLEGEO_H

#include "npolygongeo.h"

class NRelativePoint;

class NRectangleGeo : public NPolygonGeo
{
public:
    NRectangleGeo( const NPointGeo &leftTop, const NPointGeo &rightBotton );
    NRectangleGeo( const NPointGeo &leftTop, const nreal &width,
                    const NAngle &angleWidth, const nreal &height,
                    const NAngle &angleHeight );
    NRectangleGeo( const nreal &length, const nreal &width,
                    const NPointGeo &center );
    NRectangleGeo( const NPolygonGeo &polygon );
    NRectangleGeo( const NRectangleGeo &NRectangle );
    NRectangleGeo( NRectangleGeo &&NRectangle );
    ~NRectangleGeo();

    NRectangleGeo &operator=( const NRectangleGeo &NRectangle );
    NRectangleGeo &operator=( NRectangleGeo &&NRectangle );

    /**
     * @brief leftBottom - Метод возвращает левую нижнию вершину в
     * прямоугольники.
     * @return левая нижния вершина.
     */
    NPointGeo leftBottom() const;
    /**
     * @brief leftTop - Метод возвращает левую верхнею вершину в
     * прямоугольники.
     * @return левая верхняя вершина.
     */
    NPointGeo leftTop() const;
    /**
     * @brief rightTop - Метод возвращает правую верхнею вершину в
     * прямоугольники.
     * @return правая верхняя вершина.
     */
    NPointGeo rightTop() const;
    /**
     * @brief rightBottom - Метод возвращает правую нижнию вершину в
     * прямоугольники.
     * @return правая нижняя вершина.
     */
    NPointGeo rightBottom() const;

    /**
     * @brief center - метод возвращает центр полигона.
     * @return координаты центра полигона.
     */
    NPointGeo center() const;

private:
    typedef NRelativePoint RP;
};

#endif // NRECTANGLEGEO_H
