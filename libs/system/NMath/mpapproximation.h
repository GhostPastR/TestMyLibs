#ifndef MPAPPROXIMATION_H
#define MPAPPROXIMATION_H

#include <memory>
#include "mpfigure.h"

class MpApproximationPrivat;

class MpApproximation
{
public:
    MpApproximation( const MpLineSection &lineSection,
                     const nreal &interval );
    MpApproximation( const MpArc &arc, const nreal &interval );
    MpApproximation( const MpFigure &figure, const nreal &interval );
    MpApproximation( const QList<MpFigure> &listFigure,
                     const nreal &interval );

    /**
     * @brief setInterval - Метод задает новое значение интервала. Если значение
     * интервала меньше или равно 0, то занчение будет выставлено в 1.
     * @param interval - Новое значение интервала.
     * @return Экземпляр класса.
     */
    MpApproximation &setInterval( const nreal &interval = nreal( 1.0 ) );
    const nreal &interval() const;

    /**
     * @brief approximation - Метод разбивает геометрический объект на отдельны
     * точки.
     * @param equidistant - Параметр задает способ разбиения(true - равномерное
     * разбиение объекта на точки с перерасчетам интервала между точками,
     * false - без перерасчета интервала между точками).
     * @return Список точек.
     */
    QList<MpPoint> approximation( bool equidistant ) const;

private:
    /**
     * @brief interval_ - Интервал между точками при разбиение фигуры на точки.
     */
    nreal interval_;

    /**
     * @brief ptr_ - Контейнер хранящий фигуру для которой будет осуществлять
     * разбиение на точки.
     */
    std::shared_ptr<MpApproximationPrivat> ptr_;

    /**
     * @brief approximation - Метод разбивает отрезок на отдельны точки.
     * @param line - Отрезок.
     * @param equidistant - Параметр задает способ разбиения(true - равномерное
     * разбиение объекта на точки с перерасчетам интервала между точками,
     * false - без перерасчета интервала между точками).
     * @return Список точек.
     */
    QList<MpPoint> approximation( const MpLineSection &line,
                                  bool equidistant ) const;
    /**
     * @brief approximation - Метод разбивает дугу на отдельны точки.
     * @param arc - Дуга.
     * @param equidistant - Параметр задает способ разбиения(true - равномерное
     * разбиение объекта на точки с перерасчетам интервала между точками,
     * false - без перерасчета интервала между точками).
     * @return Список точек.
     */
    QList<MpPoint> approximation( const MpArc &arc, bool equidistant ) const;
    /**
     * @brief approximation - Метод разбивает фигуру на отдельны точки.
     * @param figure - Фигура(Соержащие отрезок или дугу).
     * @param equidistant - Параметр задает способ разбиения(true - равномерное
     * разбиение объекта на точки с перерасчетам интервала между точками,
     * false - без перерасчета интервала между точками).
     * @return Список точек.
     */
    QList<MpPoint> approximation( const MpFigure &figure,
                                  bool equidistant ) const;
    /**
     * @brief approximation - Метод разбивает список фигур на отдельны точки.
     * @param lFigure - Список фигур.
     * @param equidistant - Параметр задает способ разбиения(true - равномерное
     * разбиение объекта на точки с перерасчетам интервала между точками,
     * false - без перерасчета интервала между точками).
     * @return Список точек.
     */
    QList<MpPoint> approximation( const QList<MpFigure> &lFigure,
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
    void calcPointLineSection( const MpLineSection &lineSection,
                               QList<MpPoint> &listPoint, nreal &lenIterator,
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
    void calcPointArc( const MpArc &arc, QList<MpPoint> &listPoint,
                       MpAngle &lenIterator, const nreal &lenStage,
                       const MpAngle &interval,
                       const MpAngle &angleStart ) const;
};

inline MpApproximation &MpApproximation::setInterval( const nreal &interval )
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

inline const nreal &MpApproximation::interval() const
{
    return this->interval_;
}


#endif // MPAPPROXIMATION_H
