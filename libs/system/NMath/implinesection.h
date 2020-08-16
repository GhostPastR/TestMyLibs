#ifndef IMPLINESECTION_H
#define IMPLINESECTION_H

#include <bits/move.h>

template<class P>
/**
 * @brief The IMpLineSection class - Класс интерфейс для новых классов
 * описывающие геометрический примитив отрезок.
 */
class IMpLineSection
{
public:   
    const P &start() const noexcept;
    const P &stop() const noexcept;

    void setStart( const P &start ) noexcept;
    void setStop( const P &stop ) noexcept;

    void setLine( const P &start, const P &stop ) noexcept;

protected:
    IMpLineSection();
    IMpLineSection( const P &start, const P &stop );
    IMpLineSection( const IMpLineSection &lineSection );
    IMpLineSection( IMpLineSection &&lineSection );
    ~IMpLineSection();

    IMpLineSection &operator=( const IMpLineSection &lineSection );
    IMpLineSection &operator=( IMpLineSection &&lineSection );

    /**
     * @brief start_ - Координаты 1-й точки отрезка.
     */
    P start_;
    /**
     * @brief end_ - Координаты 2-й точки отрезка.
     */
    P stop_;
};

template<class P>
inline IMpLineSection<P>::IMpLineSection()
{

}

template<class P>
inline IMpLineSection<P>::IMpLineSection( const P &start, const P &stop )
{
    this->setLine( start, stop );
}

template<class P>
inline IMpLineSection<P>::IMpLineSection( const IMpLineSection &lineSection )
{
    this->start_ = lineSection.start_;
    this->stop_ = lineSection.stop_;
}

template<class P>
inline IMpLineSection<P>::IMpLineSection( IMpLineSection &&lineSection )
{
    this->start_ = std::move( lineSection.start_ );
    this->stop_ = std::move( lineSection.stop_ );
}

template<class P>
inline IMpLineSection<P>::~IMpLineSection()
{

}

template<class P>
inline IMpLineSection<P> &IMpLineSection<P>::operator=
                                           ( const IMpLineSection &lineSection )
{
    this->start_ = lineSection.start_;
    this->stop_ = lineSection.stop_;
    return *this;
}

template<class P>
inline IMpLineSection<P> &IMpLineSection<P>::operator=
                                                ( IMpLineSection &&lineSection )
{
    this->start_ = std::move( lineSection.start_ );
    this->stop_ = std::move( lineSection.stop_ );
    return *this;
}

template<class P>
inline const P &IMpLineSection<P>::start() const noexcept
{
    return this->start_;
}

template<class P>
inline const P &IMpLineSection<P>::stop() const noexcept
{
    return this->stop_;
}

template<class P>
inline void IMpLineSection<P>::setStart( const P &start ) noexcept
{
    this->start_ = start;
}

template<class P>
inline void IMpLineSection<P>::setStop( const P &stop ) noexcept
{
    this->stop_ = stop;
}

template<class P>
inline void IMpLineSection<P>::setLine( const P &start, const P &stop ) noexcept
{
    this->start_ = start;
    this->stop_ = stop;
}

#endif // IMPLINESECTION_H
