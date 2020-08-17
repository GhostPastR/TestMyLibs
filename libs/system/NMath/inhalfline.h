#ifndef INHALFLINE_H
#define INHALFLINE_H

#include <nangle.h>

template<class P>
/**
 * @brief The INHalfLine class - Класс интерфейс для новых классов
 * описывающие геометрический примитив луч.
 */
class INHalfLine
{
public: 
    const P &point() const noexcept;
    void setPoint( const P &point ) noexcept;

    const NAngle &angle() const noexcept;
    void setAngle( const NAngle &angle ) noexcept;

protected:
    INHalfLine();
    INHalfLine( const P &point, const NAngle &angle );
    INHalfLine( const INHalfLine &NHalfLine );
    INHalfLine( INHalfLine &&NHalfLine );
    ~INHalfLine();

    INHalfLine &operator=( const INHalfLine &NHalfLine );
    INHalfLine &operator=( INHalfLine &&NHalfLine );

    /**
     * @brief start_ - Координаты точки луча.
     */
    P point_;
    /**
     * @brief angle_ - Направления луча.
     */
    NAngle angle_;
};

template<class P>
inline INHalfLine<P>::INHalfLine()
{

}

template<class P>
inline INHalfLine<P>::INHalfLine( const P &point, const NAngle &angle )
{
    this->point_ = point;
    this->angle_ = angle;
}

template<class P>
inline INHalfLine<P>::INHalfLine( const INHalfLine &NHalfLine )
{
    this->point_ = NHalfLine.point_;
    this->angle_ = NHalfLine.angle_;
}

template<class P>
inline INHalfLine<P>::INHalfLine( INHalfLine &&NHalfLine )
{
    this->point_ = std::move( NHalfLine.point_ );
    this->angle_ = std::move( NHalfLine.angle_ );
}

template<class P>
inline INHalfLine<P>::~INHalfLine()
{

}

template<class P>
inline INHalfLine<P> &INHalfLine<P>::operator=( const INHalfLine &NHalfLine)
{
    this->point_ = NHalfLine.point_;
    this->angle_ = NHalfLine.angle_;
    return *this;
}

template<class P>
inline INHalfLine<P> &INHalfLine<P>::operator=( INHalfLine &&NHalfLine )
{
    this->point_ = std::move( NHalfLine.point_ );
    this->angle_ = std::move( NHalfLine.angle_ );
    return *this;
}

template<class P>
inline const P &INHalfLine<P>::point() const noexcept
{
    return this->point_;
}

template<class P>
inline void INHalfLine<P>::setPoint( const P &point ) noexcept
{
    this->point_ = point;
}

template<class P>
inline const NAngle &INHalfLine<P>::angle() const noexcept
{
    return this->angle_;
}

template<class P>
inline void INHalfLine<P>::setAngle( const NAngle &angle ) noexcept
{
    this->angle_ = angle;
}

#endif // INHalfLine_H
