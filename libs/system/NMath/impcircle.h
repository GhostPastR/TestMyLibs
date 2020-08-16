#ifndef IMPCIRCLE_H
#define IMPCIRCLE_H

#include "mpangle.h"
#include "mppoint.h"

template<class P>
/**
 * @brief The IMpCircle class - Класс интерфейс для новых классов описывающие
 * геометрический примитив окружность.
 */
class IMpCircle
{
public:
    const P &center() const noexcept;
    void setCenter( const P &center ) noexcept;

    const nreal &radius() const noexcept;
    void setRadius( const nreal &radius ) noexcept;

protected:
    IMpCircle();
    IMpCircle( const P &center, const nreal &radius = nreal( 1.0 ) );
    IMpCircle( const IMpCircle &mpCircle );
    IMpCircle( IMpCircle &&mpCircle );
    ~IMpCircle();

    IMpCircle &operator=( const IMpCircle &mpCircle );
    IMpCircle &operator=( IMpCircle &&mpCircle );

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
inline IMpCircle<P>::IMpCircle()
{
    this->radius_ = 0.0;
}

template<class P>
inline IMpCircle<P>::IMpCircle( const P &center, const nreal &radius )
    : center_(center), radius_(radius)
{

}

template<class P>
inline IMpCircle<P>::IMpCircle( const IMpCircle &mpCircle )
{
    this->center_ = mpCircle.center_;
    this->radius_ = mpCircle.radius_;
}

template<class P>
inline IMpCircle<P>::IMpCircle( IMpCircle &&mpCircle )
{
    this->center_ = std::move( mpCircle.center_ );
    this->radius_ = std::move( mpCircle.radius_ );
}

template<class P>
inline IMpCircle<P>::~IMpCircle()
{

}

template<class P>
inline IMpCircle<P> &IMpCircle<P>::operator=( const IMpCircle &mpCircle )
{
    this->center_ = mpCircle.center_;
    this->radius_ = mpCircle.radius_;
    return *this;
}

template<class P>
inline IMpCircle<P> &IMpCircle<P>::operator=( IMpCircle &&mpCircle )
{
    this->center_ = std::move( mpCircle.center_ );
    this->radius_ = std::move( mpCircle.radius_ );
    return *this;
}

template<class P>
inline const P &IMpCircle<P>::center() const noexcept
{
    return this->center_;
}

template<class P>
inline void IMpCircle<P>::setCenter( const P &center ) noexcept
{
    this->center_ = center;
}

template<class P>
inline const nreal &IMpCircle<P>::radius() const noexcept
{
    return this->radius_;
}

template<class P>
inline void IMpCircle<P>::setRadius( const nreal &radius ) noexcept
{
    if( radius > nreal() )
        this->radius_ = radius;
    else
    {
        std::wcerr << "Error! MpCircle radius <= 0!" << std::endl;
        this->radius_ = 1.0;
    }
}


#endif // IMPCIRCLE_H
