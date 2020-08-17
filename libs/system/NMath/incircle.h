#ifndef INCIRCLE_H
#define INCIRCLE_H

#include "nangle.h"
#include "npoint.h"

template<class P>
/**
 * @brief The INCircle class - Класс интерфейс для новых классов описывающие
 * геометрический примитив окружность.
 */
class INCircle
{
public:
    const P &center() const noexcept;
    void setCenter( const P &center ) noexcept;

    const nreal &radius() const noexcept;
    void setRadius( const nreal &radius ) noexcept;

protected:
    INCircle();
    INCircle( const P &center, const nreal &radius = nreal( 1.0 ) );
    INCircle( const INCircle &NCircle );
    INCircle( INCircle &&NCircle );
    ~INCircle();

    INCircle &operator=( const INCircle &NCircle );
    INCircle &operator=( INCircle &&NCircle );

    /**
     * @brief center_ - Координаты центра окружности.
     */
    P center_;
    /**
     * @brief radius_ - Радиус окружности.
     */
    nreal radius_;
};

template<class P>
inline INCircle<P>::INCircle()
{
    this->radius_ = 0.0;
}

template<class P>
inline INCircle<P>::INCircle( const P &center, const nreal &radius )
    : center_(center), radius_(radius)
{

}

template<class P>
inline INCircle<P>::INCircle( const INCircle &NCircle )
{
    this->center_ = NCircle.center_;
    this->radius_ = NCircle.radius_;
}

template<class P>
inline INCircle<P>::INCircle( INCircle &&NCircle )
{
    this->center_ = std::move( NCircle.center_ );
    this->radius_ = std::move( NCircle.radius_ );
}

template<class P>
inline INCircle<P>::~INCircle()
{

}

template<class P>
inline INCircle<P> &INCircle<P>::operator=( const INCircle &NCircle )
{
    this->center_ = NCircle.center_;
    this->radius_ = NCircle.radius_;
    return *this;
}

template<class P>
inline INCircle<P> &INCircle<P>::operator=( INCircle &&NCircle )
{
    this->center_ = std::move( NCircle.center_ );
    this->radius_ = std::move( NCircle.radius_ );
    return *this;
}

template<class P>
inline const P &INCircle<P>::center() const noexcept
{
    return this->center_;
}

template<class P>
inline void INCircle<P>::setCenter( const P &center ) noexcept
{
    this->center_ = center;
}

template<class P>
inline const nreal &INCircle<P>::radius() const noexcept
{
    return this->radius_;
}

template<class P>
inline void INCircle<P>::setRadius( const nreal &radius ) noexcept
{
    if( radius > nreal() )
        this->radius_ = radius;
    else
    {
        std::wcerr << "Error! NCircle radius <= 0!" << std::endl;
        this->radius_ = 1.0;
    }
}


#endif // INCIRCLE_H
