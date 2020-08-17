#ifndef NFIGURE_H
#define NFIGURE_H

#include "narc.h"
#include "nlinesection.h"

//!

/**
 * @brief The NFigure class - Класс содержащий поля и методы для работы с 2-мя
 * геометрическими объектами линия и дуга, данный класс в определенный момент
 * времени содержит только один объект линию или дугу.
 */
class NFigure
{
public:
    NFigure();
    NFigure( const NLineSection &lineSection );
    NFigure( const NArc &arc );
    NFigure( const NFigure &figure );
    NFigure( NFigure &&figure );
    virtual ~NFigure();

    const NLineSection &lineSection() const;
    const NArc &arc() const;

    void setLineSection( const NLineSection &lineSection );
    void setLineSection( NLineSection &&lineSection );
    void setArc( const NArc &arc );
    void setArc( NArc &&arc );

    /**
     * @brief pointStart - метод возвращает начальную точку графического
     * объекта.
     * @return координаты начальной точки.
     */
    NPoint pointStart() const;
    /**
     * @brief pointStop - метод возвращает конечную точку графического объекта.
     * @return координаты конечной точки.
     */
    NPoint pointStop() const;

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
    static nreal lehghtFigure( const QList<NFigure> &figure );

    NFigure &operator=( const NFigure &NFigure );
    NFigure &operator=( NFigure &&NFigure );
protected:
    NLineSection *lineSection_;    //!Указатель на объект линия
    NArc *arc_;                    //!Указатель на объект дуга
};

inline NFigure::NFigure() : lineSection_(nullptr), arc_(nullptr){}

inline const NLineSection &NFigure::lineSection() const
{ return *this->lineSection_; }

inline const NArc &NFigure::arc() const
{ return *this->arc_; }

#endif // NFIGURE_H
