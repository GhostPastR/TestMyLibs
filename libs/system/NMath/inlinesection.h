#ifndef INLINESECTION_H
#define INLINESECTION_H

#include <bits/move.h>

template<class P>
/**
 * @brief The INLineSection class - Класс интерфейс для новых классов
 * описывающие геометрический примитив отрезок.
 */
class INLineSection
{
public:   
    const P &start() const noexcept;
    const P &stop() const noexcept;

    void setStart( const P &start ) noexcept;
    void setStop( const P &stop ) noexcept;

    void setLine( const P &start, const P &stop ) noexcept;

protected:
    INLineSection();
    INLineSection( const P &start, const P &stop );
    INLineSection( const INLineSection &lineSection );
    INLineSection( INLineSection &&lineSection );
    ~INLineSection();

    INLineSection &operator=( const INLineSection &lineSection );
    INLineSection &operator=( INLineSection &&lineSection );

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
inline INLineSection<P>::INLineSection()
{

}

template<class P>
inline INLineSection<P>::INLineSection( const P &start, const P &stop )
{
    this->setLine( start, stop );
}

template<class P>
inline INLineSection<P>::INLineSection( const INLineSection &lineSection )
{
    this->start_ = lineSection.start_;
    this->stop_ = lineSection.stop_;
}

template<class P>
inline INLineSection<P>::INLineSection( INLineSection &&lineSection )
{
    this->start_ = std::move( lineSection.start_ );
    this->stop_ = std::move( lineSection.stop_ );
}

template<class P>
inline INLineSection<P>::~INLineSection()
{

}

template<class P>
inline INLineSection<P> &INLineSection<P>::operator=
                                           ( const INLineSection &lineSection )
{
    this->start_ = lineSection.start_;
    this->stop_ = lineSection.stop_;
    return *this;
}

template<class P>
inline INLineSection<P> &INLineSection<P>::operator=
                                                ( INLineSection &&lineSection )
{
    this->start_ = std::move( lineSection.start_ );
    this->stop_ = std::move( lineSection.stop_ );
    return *this;
}

template<class P>
inline const P &INLineSection<P>::start() const noexcept
{
    return this->start_;
}

template<class P>
inline const P &INLineSection<P>::stop() const noexcept
{
    return this->stop_;
}

template<class P>
inline void INLineSection<P>::setStart( const P &start ) noexcept
{
    this->start_ = start;
}

template<class P>
inline void INLineSection<P>::setStop( const P &stop ) noexcept
{
    this->stop_ = stop;
}

template<class P>
inline void INLineSection<P>::setLine( const P &start, const P &stop ) noexcept
{
    this->start_ = start;
    this->stop_ = stop;
}

#endif // INLINESECTION_H
