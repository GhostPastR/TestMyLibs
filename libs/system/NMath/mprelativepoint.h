#ifndef MPRELATIVEPOINT_H
#define MPRELATIVEPOINT_H

#include "mppolygon.h"
#include "mpcirclegeo.h"
#include "mplinesection.h"
#include "mplinegeo.h"
#include "mppolygongeo.h"

/**
 * @brief The MpRelativePoint class - Класс содержащий методы и поля перевода
 * топографических координат в декартовые и обратно.
 */
class MpRelativePoint
{
public:
    MpRelativePoint();
    MpRelativePoint( const MpPointGeo &tc, const MpPointGeo &rm );
    MpRelativePoint( const MpPoint &cc, const MpPointGeo &rm );
    MpRelativePoint( const MpPointGeo &tc, const MpPoint &cc );
    MpRelativePoint( const MpRelativePoint &mpRelativePoint );
    MpRelativePoint( MpRelativePoint &&mpRelativePoint );
    virtual ~MpRelativePoint();

    /**
     * @brief cc - Возвращающий значения экземпляра класса в декартовых
     * координатах.
     * @return декартовые координаты экземпляра класса.
     */
    const MpPoint &cc() const;
    /**
     * @brief tc - Возвращающий значения экземпляра класса в географических
     * координатах.
     * @return географические координаты экземпляра класса.
     */
    const MpPointGeo &tc() const;
    /**
     * @brief rm - Возвращающий значения опорной точки относительно которой
     * перерасчитываются координаты.
     * @return географические координаты опорной точки.
     */
    const MpPointGeo &rm() const;

    void setCc( const MpPoint &cc );
    void setTc( const MpPointGeo &tc );
    void setRm( const MpPointGeo &rm );

    /**
     * @brief randingMark - статический метод возвращает географические
     * координаты опорной точки.
     * @param pointGeo - топографические координаты точки.
     * @param point - декартовые координаты точки.
     * @return топографические координаты опорной точки.
     */
    static MpPointGeo randingMark( const MpPointGeo &pointGeo,
                                   const MpPoint &point );

    /**
     * @brief newCoord - статический метод возвращает декартовые координаты
     * точки.
     * @param point - топографические координаты точки.
     * @param rangingMark - топографические координаты опорной точки.
     * @return декартовые координаты точки.
     */
    static MpPoint newCoord( const MpPointGeo &point,
                             const MpPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает топографические координаты
     * точки.
     * @param point - декартовые координаты точки.
     * @param rangingMark - топографические координаты опорной точки.
     * @return топографические координаты точки.
     */
    static MpPointGeo newCoord( const MpPoint &point,
                                const MpPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает топографические координаты
     * отрезка.
     * @param line - отрезок в декартовых координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return топографические координаты отрезка.
     */
    static MpLineGeo newCoord( const MpLineSection &line,
                               const MpPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает декартовые координаты
     * отрезка.
     * @param line - отрезок в топографических координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return декартовые координаты отрезка.
     */
    static MpLineSection newCoord( const MpLineGeo &line,
                                   const MpPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает топографические координаты
     * дуги.
     * @param arc - дуга в географических координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return топографические координаты дуги.
     */
    static MpArcGeo newCoord( const MpArc &arc, const MpPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает декартовые координаты
     * дуги.
     * @param arc - дуга в топографических координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return географические координаты дуги.
     */
    static MpArc newCoord( const MpArcGeo &arc, const MpPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает топографические координаты
     * списка точек.
     * @param listPoint - список точек в декартовых координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return список точек с топографическими координатами.
     */
    static QList<MpPointGeo> newCoord( const QList<MpPoint> &listPoint,
                                       const MpPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает топографические координаты
     * списка точек.
     * @param listPointGeo - список точек в топографических координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return список точек в декартовых координатах.
     */
    static QList<MpPoint> newCoord( const QList<MpPointGeo> &listPointGeo,
                                    const MpPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает топографические координаты
     * списка отрезков.
     * @param listLine - список отрезков в декартовых координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return список отрезков с топографическими координатами.
     */
    static QList<MpLineGeo> newCoord( const QList<MpLineSection> &listLine,
                                      const MpPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает топографические координаты
     * полигона.
     * @param polygon - полигон в декартовых координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return полигона в топографических координатах.
     */
    static MpPolygonGeo newCoord( const MpPolygon &polygon,
                                  const MpPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает декартовые координаты
     * полигона.
     * @param polygon - полигон в топографических координаах координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return полигон в декартовых координатах.
     */
    static MpPolygon newCoord( const MpPolygonGeo &polygon,
                               const MpPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает декартовые координаты
     * полигона.
     * @param polygon - список полигонов в топографических координаах
     * координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return полигон в декартовых координатах.
     */
    static QList<MpPolygon> newCoord( const QList<MpPolygonGeo> &polygon,
                                      const MpPointGeo &rangingMark );

    MpRelativePoint &operator=( const MpRelativePoint &mpRelativePoint );
    MpRelativePoint &operator=( MpRelativePoint &&mpRelativePoint );

protected:
    /**
     * @brief cc_ - Точка в декартовых координатах.
     */
    MpPoint cc_;
    /**
     * @brief tc_ - Точка в топографических координатах.
     */
    MpPointGeo tc_;
    /**
     * @brief rm_ - Опорная точка в топографических координатах.
     */
    MpPointGeo rm_;
};

inline MpRelativePoint::MpRelativePoint() {}

inline const MpPoint &MpRelativePoint::cc() const
{
    return this->cc_;
}

inline const MpPointGeo &MpRelativePoint::tc() const
{
    return this->tc_;
}

inline const MpPointGeo &MpRelativePoint::rm() const
{
    return this->rm_;
}

#endif // MPRELATIVEPOINT_H
