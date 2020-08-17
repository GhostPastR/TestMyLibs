#ifndef NAPPROXIMATION_H
#define NAPPROXIMATION_H

#include <memory>
#include "nfigure.h"

class NApproximationPrivat;

class NApproximation
{
public:
    NApproximation( const NLineSection &lineSection,
                     const nreal &interval );
    NApproximation( const NArc &arc, const nreal &interval );
    NApproximation( const NFigure &figure, const nreal &interval );
    NApproximation( const QList<NFigure> &listFigure,
                     const nreal &interval );

    /**
     * @brief setInterval - Метод задает новое значение интервала. Если значение
     * интервала меньше или равно 0, то занчение будет выставлено в 1.
     * @param interval - Новое значение интервала.
     * @return Экземпляр класса.
     */
    NApproximation &setInterval( const nreal &interval = nreal( 1.0 ) );
    const nreal &interval() const;

    /**
     * @brief approximation - Метод разбивает геометрический объект на отдельны
     * точки.
     * @param equidistant - Параметр задает способ разбиения(true - равномерное
     * разбиение объекта на точки с перерасчетам интервала между точками,
     * false - без перерасчета интервала между точками).
     * @return Список точек.
     */
    QList<NPoint> approximation( bool equidistant ) const;

private:
    /**
     * @brief interval_ - Интервал между точками при разбиение фигуры на точки.
     */
    nreal interval_;

    /**
     * @brief ptr_ - Контейнер хранящий фигуру для которой будет осуществлять
     * разбиение на точки.
     */
    std::shared_ptr<NApproximationPrivat> ptr_;

    /**
     * @brief approximation - Метод разбивает отрезок на отдельны точки.
     * @param line - Отрезок.
     * @param equidistant - Параметр задает способ разбиения(true - равномерное
     * разбиение объекта на точки с перерасчетам интервала между точками,
     * false - без перерасчета интервала между точками).
     * @return Список точек.
     */
    QList<NPoint> approximation( const NLineSection &line,
                                  bool equidistant ) const;
    /**
     * @brief approximation - Метод разбивает дугу на отдельны точки.
     * @param arc - Дуга.
     * @param equidistant - Параметр задает способ разбиения(true - равномерное
     * разбиение объекта на точки с перерасчетам интервала между точками,
     * false - без перерасчета интервала между точками).
     * @return Список точек.
     */
    QList<NPoint> approximation( const NArc &arc, bool equidistant ) const;
    /**
     * @brief approximation - Метод разбивает фигуру на отдельны точки.
     * @param figure - Фигура(Соержащие отрезок или дугу).
     * @param equidistant - Параметр задает способ разбиения(true - равномерное
     * разбиение объекта на точки с перерасчетам интервала между точками,
     * false - без перерасчета интервала между точками).
     * @return Список точек.
     */
    QList<NPoint> approximation( const NFigure &figure,
                                  bool equidistant ) const;
    /**
     * @brief approximation - Метод разбивает список фигур на отдельны точки.
     * @param lFigure - Список фигур.
     * @param equidistant - Параметр задает способ разбиения(true - равномерное
     * разбиение объекта на точки с перерасчетам интервала между точками,
     * false - без перерасчета интервала между точками).
     * @return Список точек.
     */
    QList<NPoint> approximation( const QList<NFigure> &lFigure,
                                  bool equidistant ) const;
    /**
     * @brief equidistantIterval - Метод перерасчитывает интервал между точками.
     * @param length - длина участка.
     * @return Новый интервал между точками.
     */
    nreal equidistantIterval( const nreal &length ) const;

    /**
     * @brief calcPointLineSection - Метод заполняет контейнер новыми точками
     * для отрезка.
     * @param lineSection - Отрезок.
     * @param listPoint - Контейнер где будут храниться точки.
     * @param lenIterator - Изменяющийся интервал от начало отрезка и
     * увеличивающийся с каждой точки на велечину interval.
     * @param lenStage - Длинна линии.
     * @param interval - Интервал между точками.
     */
    void calcPointLineSection( const NLineSection &lineSection,
                               QList<NPoint> &listPoint, nreal &lenIterator,
                               const nreal &lenStage,
                               const nreal &interval ) const;
    /**
     * @brief calcPointArc - Метод заполняет контейнер новыми точками для дуги.
     * @param arc - Дуга.
     * @param listPoint - Контейнер где будут храниться точки.
     * @param lenIterator - Изменяющийся интервал от начало отрезка и
     * увеличивающийся с каждой точки на велечину interval.
     * @param lenStage - Длинна дуги.
     * @param interval - Интервал между точками.
     * @param angleStart - Направления на начало дуги от центра.
     */
    void calcPointArc( const NArc &arc, QList<NPoint> &listPoint,
                       NAngle &lenIterator, const nreal &lenStage,
                       const NAngle &interval,
                       const NAngle &angleStart ) const;
};

inline NApproximation &NApproximation::setInterval( const nreal &interval )
{
    if( interval > nreal() )
        this->interval_ = interval;
    else
    {
        this->interval_ = nreal( 1.0 );
        std::cout << "The interval should be more than 0" << std::endl;
    }
    return *this;
}

inline const nreal &NApproximation::interval() const
{
    return this->interval_;
}


#endif // NAPPROXIMATION_H
