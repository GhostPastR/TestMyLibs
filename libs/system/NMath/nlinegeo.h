#ifndef NLINEGEO_H
#define NLINEGEO_H

#include "nlinesection.h"
#include "npointgeo.h"

/**
 * @brief The NLineGeo class - Класс содержащий методы и поля для работы с
 * геометрическим объектом линия содержащие топографические координаты.
 */
class NLineGeo : public INLineSection<NPointGeo>
{
public:
    NLineGeo();
    NLineGeo( const NPointGeo &start, const NPointGeo &end );

    /**
     * @brief NLineGeo - конструктор который преобразует отрезок из декартовых
     * координат в отрезок с топографическими координатами.
     * @param lineSection - отрезок в декартовых координатах.
     * @param randingMark - топографические координаты опорной точки.
     */
    NLineGeo( const NLineSection &lineSection, const NPointGeo &randingMark );
    NLineGeo( const NLineGeo &lineGeo );
    NLineGeo( NLineGeo &&lineGeo );
    virtual ~NLineGeo();

    /**
     * @brief intersectionLine - Метод определяет пересечение 2-х отрезков.
     * @param line - отрезок в топографических координатах.
     * @return точка пересечения в топографических координатах.
     */
    NPointGeo intersectionLine( const NLineGeo &line ) const;

    NLineGeo &operator=( const NLineGeo &lineGeo );
    NLineGeo &operator=( NLineGeo &&lineGeo );
};

inline NLineGeo::NLineGeo() : INLineSection(){}

inline NLineGeo::NLineGeo( const NPointGeo &start, const NPointGeo &end )
    : INLineSection( start, end ){}

#endif // NLINEGEO_H
