#ifndef MPHALFLINE_H
#define MPHALFLINE_H

#include "imphalfline.h"
#include "mppoint.h"
#include "mpline.h"

class MpHalfLine : public MpLine, public IMpHalfLine<MpPoint>
{
public:
    MpHalfLine();
    MpHalfLine( const MpPoint &point, const MpAngle &angle );
    MpHalfLine( const MpPoint &start, const MpPoint &stop );
    MpHalfLine( const MpHalfLine &halfLine );
    MpHalfLine( MpHalfLine &&halfLine );
    virtual ~MpHalfLine();

    /**
     * @brief checkPointOnLine - метод проверяет принадлежит ли точка лучу.
     * @param point - точка для которой происходит проверка.
     * @return - результат проверки(true - точка пренадлежит луч, false -
     * точка не пренадлежит луч).
     */
    bool checkPointOnLine( const MpPoint point ) const;

    /**
     * @brief intersectionHalfLine - метод возвращает точку пересечения 2-х
     * лучей.
     * @param halfLine - луч для которой определяется пересечение.
     * @return - координаты точки пересечения(Координаты точки равны
     * бесконечности, если лучи не пересекаются).
     */
    MpPoint intersectionHalfLine( const MpHalfLine &halfLine ) const;

    /**
     * @brief halfLineOnHalfLine - метод проверяет пересекаются ли 2 луча.
     * @param halfLine - луч для которой определяется пересечение.
     * @return - результат проверки(true - лучи пересекаются, false - лучи не
     * пересекаются).
     */
    bool halfLineOnHalfLine( const MpHalfLine &halfLine) const;


    MpHalfLine &operator=( const MpHalfLine &halfLine );
    MpHalfLine &operator=( MpHalfLine &&halfLine );
};

#endif // MPHALFLINE_H
