#ifndef MPFIGURE_H
#define MPFIGURE_H

#include "mparc.h"
#include "mplinesection.h"

//!

/**
 * @brief The MpFigure class - Класс содержащий поля и методы для работы с 2-мя
 * геометрическими объектами линия и дуга, данный класс в определенный момент
 * времени содержит только один объект линию или дугу.
 */
class MpFigure
{
public:
    MpFigure();
    MpFigure( const MpLineSection &lineSection );
    MpFigure( const MpArc &arc );
    MpFigure( const MpFigure &figure );
    MpFigure( MpFigure &&figure );
    virtual ~MpFigure();

    const MpLineSection &lineSection() const;
    const MpArc &arc() const;

    void setLineSection( const MpLineSection &lineSection );
    void setLineSection( MpLineSection &&lineSection );
    void setArc( const MpArc &arc );
    void setArc( MpArc &&arc );

    /**
     * @brief pointStart - метод возвращает начальную точку графического
     * объекта.
     * @return координаты начальной точки.
     */
    MpPoint pointStart() const;
    /**
     * @brief pointStop - метод возвращает конечную точку графического объекта.
     * @return координаты конечной точки.
     */
    MpPoint pointStop() const;

    /**
     * @brief figureArc - метод показывает, что в классе хранится объект дуга.
     * @return true - если в классе есть дуга, false - если дуги нет.
     */
    bool figureArc() const;

    /**
     * @brief figureLineSection - метод показывает, что в классе хранится объект
     * линия.
     * @return true - если в классе есть линия, false - если линии нет.
     */
    bool figureLineSection() const;

    /**
     * @brief deleteLineSection - метод удаляет объект линии из класса.
     */
    void deleteLineSection();
    /**
     * @brief deleteArc - метод удаляет объект дуги из класса
     */
    void deleteArc();

    /**
     * @brief lehghtFigure - статический метод возвращает длину списка фигур.
     * @param figure - список фигур.
     * @return длина списка фигур.
     */
    static nreal lehghtFigure( const QList<MpFigure> &figure );

    MpFigure &operator=( const MpFigure &mpFigure );
    MpFigure &operator=( MpFigure &&mpFigure );
protected:
    MpLineSection *lineSection_;    //!Указатель на объект линия
    MpArc *arc_;                    //!Указатель на объект дуга
};

inline MpFigure::MpFigure() : lineSection_(nullptr), arc_(nullptr){}

inline const MpLineSection &MpFigure::lineSection() const
{ return *this->lineSection_; }

inline const MpArc &MpFigure::arc() const
{ return *this->arc_; }

#endif // MPFIGURE_H
