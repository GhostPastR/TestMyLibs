#ifndef MPLINEGEO_H
#define MPLINEGEO_H

#include "mplinesection.h"
#include "mppointgeo.h"

/**
 * @brief The MpLineGeo class - Класс содержащий методы и поля для работы с
 * геометрическим объектом линия содержащие топографические координаты.
 */
class MpLineGeo : public IMpLineSection<MpPointGeo>
{
public:
    MpLineGeo();
    MpLineGeo( const MpPointGeo &start, const MpPointGeo &end );

    /**
     * @brief MpLineGeo - конструктор который преобразует отрезок из декартовых
     * координат в отрезок с топографическими координатами.
     * @param lineSection - отрезок в декартовых координатах.
     * @param randingMark - топографические координаты опорной точки.
     */
    MpLineGeo( const MpLineSection &lineSection, const MpPointGeo &randingMark );
    MpLineGeo( const MpLineGeo &lineGeo );
    MpLineGeo( MpLineGeo &&lineGeo );
    virtual ~MpLineGeo();

    /**
     * @brief intersectionLine - Метод определяет пересечение 2-х отрезков.
     * @param line - отрезок в топографических координатах.
     * @return точка пересечения в топографических координатах.
     */
    MpPointGeo intersectionLine( const MpLineGeo &line ) const;

    MpLineGeo &operator=( const MpLineGeo &lineGeo );
    MpLineGeo &operator=( MpLineGeo &&lineGeo );
};

inline MpLineGeo::MpLineGeo() : IMpLineSection(){}

inline MpLineGeo::MpLineGeo( const MpPointGeo &start, const MpPointGeo &end )
    : IMpLineSection( start, end ){}

#endif // MPLINEGEO_H
