#ifndef MPTRIANGLE_H
#define MPTRIANGLE_H

#include "mppoint.h"

/**
 * @brief The MpVertex enum - Класс-перечисления для верчин треугольника.
 */
enum class MpVertex
{
    VERTEX_1 = 1,   //! 1-я вершина.
    VERTEX_2 = 2,   //! 2-я вершина.
    VERTEX_3 = 3,   //! 3-я вершина.
};

class MpTriangle
{
public:
    MpTriangle( const MpPoint &vertex1, const MpPoint &vertex2,
                const MpPoint &vertex3 );
    MpTriangle( const MpTriangle &triangle );
    MpTriangle( MpTriangle &&triangle );

    virtual ~MpTriangle();

    /**
     * @brief angle - Метод возвращает величину угла заданной вершины.
     * @param vertex - Вершина треугольника
     * @return Величина угла вершины.
     */
    MpAngle angle( MpVertex vertex ) const;

    MpTriangle &operator=( const MpTriangle &triangle );
    MpTriangle &operator=( MpTriangle &&triangle );

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
    MpPoint vertex1_;
    /**
     * @brief vertex2_ - 2-я вершина.
     */
    MpPoint vertex2_;
    /**
     * @brief vertex3_ - 3-я вершина.
     */
    MpPoint vertex3_;

    /**
     * @brief angle - Метод возвращает величину угла вершины vertex1.
     * @param vertex1 - 1-я вершина.
     * @param vertex2 - 2-я вершина.
     * @param vertex3 - 3-я вершина.
     * @return Величина угла вершины.
     */
    MpAngle angle( const MpPoint &vertex1, const MpPoint &vertex2,
                   const MpPoint &vertex3 ) const;
};

#endif // MPTRIANGLE_H
