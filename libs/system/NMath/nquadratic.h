#ifndef NQUADRATIC_H
#define NQUADRATIC_H

#include <ntype.h>
#include <QPair>

/**
 * @brief The NQuadratic class - класс содержащие методы и поля для работы с
 * квадратным уравнением a1*x^2+a2*x+a3=0.
 */
class NQuadratic
{
public:
    NQuadratic( const nreal &a = nreal( 1.0 ) );
    NQuadratic( const nreal &a1, const nreal &a2, const nreal &a3 );
    NQuadratic( const NQuadratic &qudratic );
    NQuadratic( NQuadratic &&qudratic );
    virtual ~NQuadratic();

    const nreal &a1() const;
    /**
     * @brief setA1 - Метод задает 1-й коэффициент уравнением a1*x^2+a2*x+a3=0.
     * @param a1 - Значение первого коэффициента.
     */
    void setA1( const nreal &a1 );

    const nreal &a2() const;
    void setA2( const nreal &a2 );

    const nreal &a3() const;
    void setA3( const nreal &a3 );

    nreal d();

    /**
     * @brief rRoot - Метод вычисляет вещественные корни уравнения, если корни
     * уравнения комплексные то значения корней будет nan.
     * @return вещественные корни уравнения.
     */
    QPair<nreal, nreal> rRoot();

    NQuadratic &operator=( const NQuadratic &qudratic );
    NQuadratic &operator=( NQuadratic &&qudratic );

protected:
    /**
     * @brief discriminant - Метод вычисляет дискриминант квадратного уравнения
     * по формуле -a2^2-4*a1*a3.
     */
    void discriminant();

private:
    /**
     * @brief a1_ - 1-й коэффициент уравнения a1*x^2+a2*x+a3=0.
     */
    nreal a1_;
    /**
     * @brief a2_ - 2-й коэффициент уравнения a1*x^2+a2*x+a3=0.
     */
    nreal a2_;
    /**
     * @brief a3_ - 3-й коэффициент уравнения a1*x^2+a2*x+a3=0.
     */
    nreal a3_;
    /**
     * @brief d_ - дискриминант уравнения a1*x^2+a2*x+a3=0, при инициализации
     * равен nan;
     */
    nreal d_;
};

inline const nreal &NQuadratic::a1() const
{
    return this->a1_;
}

inline const nreal &NQuadratic::a2() const
{
    return this->a2_;
}

inline const nreal &NQuadratic::a3() const
{
    return this->a3_;
}

#endif // NQUADRATIC_H
