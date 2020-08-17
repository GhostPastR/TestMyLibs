#ifndef NRELATIVEPOINT_H
#define NRELATIVEPOINT_H

#include "npolygon.h"
#include "ncirclegeo.h"
#include "nlinesection.h"
#include "nlinegeo.h"
#include "npolygongeo.h"

/**
 * @brief The NRelativePoint class - Класс содержащий методы и поля перевода
 * топографических координат в декартовые и обратно.
 */
class NRelativePoint
{
public:
    NRelativePoint();
    NRelativePoint( const NPointGeo &tc, const NPointGeo &rm );
    NRelativePoint( const NPoint &cc, const NPointGeo &rm );
    NRelativePoint( const NPointGeo &tc, const NPoint &cc );
    NRelativePoint( const NRelativePoint &NRelativePoint );
    NRelativePoint( NRelativePoint &&NRelativePoint );
    virtual ~NRelativePoint();

    /**
     * @brief cc - Возвращающий значения экземпляра класса в декартовых
     * координатах.
     * @return декартовые координаты экземпляра класса.
     */
    const NPoint &cc() const;
    /**
     * @brief tc - Возвращающий значения экземпляра класса в географических
     * координатах.
     * @return географические координаты экземпляра класса.
     */
    const NPointGeo &tc() const;
    /**
     * @brief rm - Возвращающий значения опорной точки относительно которой
     * перерасчитываются координаты.
     * @return географические координаты опорной точки.
     */
    const NPointGeo &rm() const;

    void setCc( const NPoint &cc );
    void setTc( const NPointGeo &tc );
    void setRm( const NPointGeo &rm );

    /**
     * @brief randingMark - статический метод возвращает географические
     * координаты опорной точки.
     * @param pointGeo - топографические координаты точки.
     * @param point - декартовые координаты точки.
     * @return топографические координаты опорной точки.
     */
    static NPointGeo randingMark( const NPointGeo &pointGeo,
                                   const NPoint &point );

    /**
     * @brief newCoord - статический метод возвращает декартовые координаты
     * точки.
     * @param point - топографические координаты точки.
     * @param rangingMark - топографические координаты опорной точки.
     * @return декартовые координаты точки.
     */
    static NPoint newCoord( const NPointGeo &point,
                             const NPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает топографические координаты
     * точки.
     * @param point - декартовые координаты точки.
     * @param rangingMark - топографические координаты опорной точки.
     * @return топографические координаты точки.
     */
    static NPointGeo newCoord( const NPoint &point,
                                const NPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает топографические координаты
     * отрезка.
     * @param line - отрезок в декартовых координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return топографические координаты отрезка.
     */
    static NLineGeo newCoord( const NLineSection &line,
                               const NPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает декартовые координаты
     * отрезка.
     * @param line - отрезок в топографических координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return декартовые координаты отрезка.
     */
    static NLineSection newCoord( const NLineGeo &line,
                                   const NPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает топографические координаты
     * дуги.
     * @param arc - дуга в географических координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return топографические координаты дуги.
     */
    static NArcGeo newCoord( const NArc &arc, const NPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает декартовые координаты
     * дуги.
     * @param arc - дуга в топографических координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return географические координаты дуги.
     */
    static NArc newCoord( const NArcGeo &arc, const NPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает топографические координаты
     * списка точек.
     * @param listPoint - список точек в декартовых координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return список точек с топографическими координатами.
     */
    static QList<NPointGeo> newCoord( const QList<NPoint> &listPoint,
                                       const NPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает топографические координаты
     * списка точек.
     * @param listPointGeo - список точек в топографических координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return список точек в декартовых координатах.
     */
    static QList<NPoint> newCoord( const QList<NPointGeo> &listPointGeo,
                                    const NPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает топографические координаты
     * списка отрезков.
     * @param listLine - список отрезков в декартовых координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return список отрезков с топографическими координатами.
     */
    static QList<NLineGeo> newCoord( const QList<NLineSection> &listLine,
                                      const NPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает топографические координаты
     * полигона.
     * @param polygon - полигон в декартовых координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return полигона в топографических координатах.
     */
    static NPolygonGeo newCoord( const NPolygon &polygon,
                                  const NPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает декартовые координаты
     * полигона.
     * @param polygon - полигон в топографических координаах координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return полигон в декартовых координатах.
     */
    static NPolygon newCoord( const NPolygonGeo &polygon,
                               const NPointGeo &rangingMark );

    /**
     * @brief newCoord - статический метод возвращает декартовые координаты
     * полигона.
     * @param polygon - список полигонов в топографических координаах
     * координатах.
     * @param rangingMark - топографические координаты опорной точки.
     * @return полигон в декартовых координатах.
     */
    static QList<NPolygon> newCoord( const QList<NPolygonGeo> &polygon,
                                      const NPointGeo &rangingMark );

    NRelativePoint &operator=( const NRelativePoint &NRelativePoint );
    NRelativePoint &operator=( NRelativePoint &&NRelativePoint );

protected:
    /**
     * @brief cc_ - Точка в декартовых координатах.
     */
    NPoint cc_;
    /**
     * @brief tc_ - Точка в топографических координатах.
     */
    NPointGeo tc_;
    /**
     * @brief rm_ - Опорная точка в топографических координатах.
     */
    NPointGeo rm_;
};

inline NRelativePoint::NRelativePoint() {}

inline const NPoint &NRelativePoint::cc() const
{
    return this->cc_;
}

inline const NPointGeo &NRelativePoint::tc() const
{
    return this->tc_;
}

inline const NPointGeo &NRelativePoint::rm() const
{
    return this->rm_;
}

#endif // NRELATIVEPOINT_H
