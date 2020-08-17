#ifndef NHALFLINE_H
#define NHALFLINE_H

#include "inhalfline.h"
#include "npoint.h"
#include "nline.h"

class NHalfLine : public NLine, public INHalfLine<NPoint>
{
public:
    NHalfLine();
    NHalfLine( const NPoint &point, const NAngle &angle );
    NHalfLine( const NPoint &start, const NPoint &stop );
    NHalfLine( const NHalfLine &halfLine );
    NHalfLine( NHalfLine &&halfLine );
    virtual ~NHalfLine();

    /**
     * @brief checkPointOnLine - метод проверяет принадлежит ли точка лучу.
     * @param point - точка для которой происходит проверка.
     * @return - результат проверки(true - точка пренадлежит луч, false -
     * точка не пренадлежит луч).
     */
    bool checkPointOnLine( const NPoint point ) const;

    /**
     * @brief intersectionHalfLine - метод возвращает точку пересечения 2-х
     * лучей.
     * @param halfLine - луч для которой определяется пересечение.
     * @return - координаты точки пересечения(Координаты точки равны
     * бесконечности, если лучи не пересекаются).
     */
    NPoint intersectionHalfLine( const NHalfLine &halfLine ) const;

    /**
     * @brief halfLineOnHalfLine - метод проверяет пересекаются ли 2 луча.
     * @param halfLine - луч для которой определяется пересечение.
     * @return - результат проверки(true - лучи пересекаются, false - лучи не
     * пересекаются).
     */
    bool halfLineOnHalfLine( const NHalfLine &halfLine) const;


    NHalfLine &operator=( const NHalfLine &halfLine );
    NHalfLine &operator=( NHalfLine &&halfLine );
};

#endif // NHALFLINE_H
