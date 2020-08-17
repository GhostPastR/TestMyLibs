#ifndef NTRIANGLE_H
#define NTRIANGLE_H

#include "npoint.h"

/**
 * @brief The NVertex enum - Класс-перечисления для верчин треугольника.
 */
enum class NVertex
{
    VERTEX_1 = 1,   //! 1-я вершина.
    VERTEX_2 = 2,   //! 2-я вершина.
    VERTEX_3 = 3,   //! 3-я вершина.
};

class NTriangle
{
public:
    NTriangle( const NPoint &vertex1, const NPoint &vertex2,
                const NPoint &vertex3 );
    NTriangle( const NTriangle &triangle );
    NTriangle( NTriangle &&triangle );

    virtual ~NTriangle();

    /**
     * @brief angle - Метод возвращает величину угла заданной вершины.
     * @param vertex - Вершина треугольника
     * @return Величина угла вершины.
     */
    NAngle angle( NVertex vertex ) const;

    NTriangle &operator=( const NTriangle &triangle );
    NTriangle &operator=( NTriangle &&triangle );

    /**
     * @brief checkExistence - Метод проверяет существования треугольнника
     * заданый 3 вершинами.
     * @return Результат проверки(true - треугольник существует,
     * false - треугольник не существует).
     */
    bool checkExistence() const;
private:
    /**
     * @brief vertex1_ - 1-я вершина.
     */
    NPoint vertex1_;
    /**
     * @brief vertex2_ - 2-я вершина.
     */
    NPoint vertex2_;
    /**
     * @brief vertex3_ - 3-я вершина.
     */
    NPoint vertex3_;

    /**
     * @brief angle - Метод возвращает величину угла вершины vertex1.
     * @param vertex1 - 1-я вершина.
     * @param vertex2 - 2-я вершина.
     * @param vertex3 - 3-я вершина.
     * @return Величина угла вершины.
     */
    NAngle angle( const NPoint &vertex1, const NPoint &vertex2,
                   const NPoint &vertex3 ) const;
};

#endif // NTRIANGLE_H
