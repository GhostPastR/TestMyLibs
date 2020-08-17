#ifndef NCIRCLE_H
#define NCIRCLE_H

#include <QList>
#include "incircle.h"
#include "nlinesection.h"

/**
 * @brief The NCircle class - Класс содержащий поля и методы для работы с
 * геометрической объектом окружность.
 */
class NCircle : public INCircle<NPoint>
{
public:
    NCircle();
    NCircle( const NPoint &center, const nreal &radius = nreal( 1.0 ) );
    NCircle( const NCircle &circle );
    NCircle( NCircle &&circle );
    virtual ~NCircle();

    /**
     * @brief pertain - Метод определяет попадает ли точка в окружность.
     * @param point - точка для которой происходит проверка.
     * @return - результат проверки(true - точка попадает в окружность,
     * false - точка не попадает в окружность).
     */
    bool pertain( const NPoint &point );

    /**
     * @brief lineToCircle - Метод определяет точки пересечения окружности с
     * прямой.
     * @param line - прямая для которой происходит проверка.
     * @return - список точек которые пересекает прямая, если список пуст то
     * прямая не пересекает окружность.
     */
    QList<NPoint> lineToCircle( const NLine &line );

    /**
     * @brief sectionToCircle - Метод находит точки пересечения окружности с
     * отрезком.
     * @param lineSection - отрезок для которого происходит проверка.
     * @return - список точек которые пересекает отрезок, если список пуст то
     * отрезок не пересекает окружность.
     */
    QList<NPoint> sectionToCircle( const NLineSection &lineSection );

    /**
     * @brief circleToCircle - Метод находит точки пересечение окружности с
     * окружностью.
     * @param circle - окружность для которого происходит проверка.
     * @return - список точек которые пересекает окружность, если список пуст,
     *  то окружность не пересекает окружность или совпадает с ней.
     */
    QList<NPoint> circleToCircle( const NCircle &circle );

    /**
     * @brief scalingTangentOut - Статический метод возвращает одну из внешних
     * касательных(ограниченая 2-мя точками) 2-х окружностей.
     * @param circle1 - 1-я окружность.
     * @param circle2 - 2-я окружность.
     * @param direct - параметр показывающий какую касательную нужно вернуть
     * (1 - правая касательная относительно курса от центра 1-й окружности ко
     * 2-й, -1 - левая касательная относительно курса от центра 1-й окружности
     * ко 2-й).
     * @return - внешнюю касательную
     */
    static NLineSection scalingTangentOut( const NCircle &circle1,
                                          const NCircle &circle2, int direct );

    /**
     * @brief scalingTangentInboard - Статический метод возвращает одну из
     * внутрених касательных(ограниченая 2-мя точками) 2-х окружностей.
     * @param circle1 - 1-я окружность.
     * @param circle2 - 2-я окружность.
     * @param direct - параметр показывающий какую касательную нужно вернуть
     * (1 - правая касательная относительно курса от центра 1-й окружности ко
     * 2-й,-1 - левая касательная относительно курса от центра 1-й окружности
     * ко 2-й).
     * @return - внутренюю касательную
     */
    static NLineSection scalingTangentInboard( const NCircle &circle1,
                                          const NCircle &circle2, int direct );

    /**
     * @brief centrCircleInLine - Статический метод возвращает центры
     * окружностей, которые образуют прямую перпендикулярную заданной прямой и
     * пересекают в заданной точке.
     * @param lineSection - прямой перпендикулярна к центрам окружностям, если
     * центры окружности принять как начало и конец линии.
     * @param pointOnLine - точка пересечения прямой и и прямой состоящей из
     * точек центра окружности.
     * @param radius - радиус окружностей.
     * @return - центры окружностей.
     */
    static QPair<NPoint, NPoint> centrCircleInLine(
            const NLineSection &lineSection, const NPoint &pointOnLine,
            const double &radius );

    NCircle &operator=( const NCircle &circle );
    NCircle &operator=( NCircle &&circle );
};

inline NCircle::NCircle() : INCircle()
{
}

inline NCircle::NCircle( const NPoint &center, const nreal &radius)
    : INCircle( center, radius ){}

#endif // NCIRCLE_H
