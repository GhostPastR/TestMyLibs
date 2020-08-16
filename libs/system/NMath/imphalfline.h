#ifndef IMPHALFLINE_H
#define IMPHALFLINE_H

#include <mpangle.h>

template<class P>
/**
 * @brief The IMpHalfLine class - Класс интерфейс для новых классов
 * описывающие геометрический примитив луч.
 */
class IMpHalfLine
{
public: 
    const P &point() const noexcept;
    void setPoint( const P &point ) noexcept;

    const MpAngle &angle() const noexcept;
    void setAngle( const MpAngle &angle ) noexcept;

protected:
    IMpHalfLine();
    IMpHalfLine( const P &point, const MpAngle &angle );
    IMpHalfLine( const IMpHalfLine &mpHalfLine );
    IMpHalfLine( IMpHalfLine &&mpHalfLine );
    ~IMpHalfLine();

    IMpHalfLine &operator=( const IMpHalfLine &mpHalfLine );
    IMpHalfLine &operator=( IMpHalfLine &&mpHalfLine );

    /**
     * @brief start_ - Координаты точки луча.
     */
    P point_;
    /**
     * @brief angle_ - Направления луча.
     */
    MpAngle angle_;
};

template<class P>
inline IMpHalfLine<P>::IMpHalfLine()
{

}

template<class P>
inline IMpHalfLine<P>::IMpHalfLine( const P &point, const MpAngle &angle )
{
    this->point_ = point;
    this->angle_ = angle;
}

template<class P>
inline IMpHalfLine<P>::IMpHalfLine( const IMpHalfLine &mpHalfLine )
{
    this->point_ = mpHalfLine.point_;
    this->angle_ = mpHalfLine.angle_;
}

template<class P>
inline IMpHalfLine<P>::IMpHalfLine( IMpHalfLine &&mpHalfLine )
{
    this->point_ = std::move( mpHalfLine.point_ );
    this->angle_ = std::move( mpHalfLine.angle_ );
}

template<class P>
inline IMpHalfLine<P>::~IMpHalfLine()
{

}

template<class P>
inline IMpHalfLine<P> &IMpHalfLine<P>::operator=( const IMpHalfLine &mpHalfLine)
{
    this->point_ = mpHalfLine.point_;
    this->angle_ = mpHalfLine.angle_;
    return *this;
}

template<class P>
inline IMpHalfLine<P> &IMpHalfLine<P>::operator=( IMpHalfLine &&mpHalfLine )
{
    this->point_ = std::move( mpHalfLine.point_ );
    this->angle_ = std::move( mpHalfLine.angle_ );
    return *this;
}

template<class P>
inline const P &IMpHalfLine<P>::point() const noexcept
{
    return this->point_;
}

template<class P>
inline void IMpHalfLine<P>::setPoint( const P &point ) noexcept
{
    this->point_ = point;
}

template<class P>
inline const MpAngle &IMpHalfLine<P>::angle() const noexcept
{
    return this->angle_;
}

template<class P>
inline void IMpHalfLine<P>::setAngle( const MpAngle &angle ) noexcept
{
    this->angle_ = angle;
}

#endif // IMPHALFLINE_H
