#ifndef INPOLYGON_H
#define INPOLYGON_H

#include <QList>

template<class P>
/**
 * @brief The INPolygon class - Класс интерфейс для новых классов
 * описывающие геометрический примитив полигон.
 */
class INPolygon
{
public:
    QList<P> &points();
    const QList<P> &points() const;
    void setPolygon( const QList<P> &points );
    void append( const P &point );
    void clear();

    /**
     * @brief isValid - метод проверяет корректный ли полигон.
     * @return результат проверки(true - полигон корректный, false - полигон не
     * корректный).
     */
    bool isValid() const;

protected:
    INPolygon();
    INPolygon( int count );
    INPolygon( const QList<P> &points );
    INPolygon( const INPolygon &NPolygon );
    INPolygon( INPolygon &&NPolygon );
    ~INPolygon();

    INPolygon &operator=( const INPolygon &NPolygon );
    INPolygon &operator=( INPolygon &&NPolygon );

    /**
     * @brief points_ - Список точек полигона.
     */
    QList<P> points_;
};

template<class P>
inline INPolygon<P>::INPolygon()
{

}

template<class P>
inline INPolygon<P>::INPolygon( int count )
{
    for( int i = 0; i < count; i++ )
        this->points_.append( P() );
}

template<class P>
inline INPolygon<P>::INPolygon( const QList<P> &points )
{
    this->setPolygon( points );
}

template<class P>
inline INPolygon<P>::INPolygon( const INPolygon &NPolygon )
{
    this->points_ = NPolygon.points_;
}

template<class P>
inline INPolygon<P>::INPolygon( INPolygon &&NPolygon )
{
    this->points_ = std::move( NPolygon.points_ );
}

template<class P>
inline INPolygon<P>::~INPolygon()
{

}

template<class P>
inline INPolygon<P> &INPolygon<P>::operator=( const INPolygon &NPolygon )
{
    this->points_ = NPolygon.points_;
    return *this;
}

template<class P>
inline INPolygon<P> &INPolygon<P>::operator=( INPolygon &&NPolygon )
{
    this->points_ = std::move( NPolygon.points_ );
    return *this;
}

template<class P>
inline QList<P> &INPolygon<P>::points()
{
    return this->points_;
}

template<class P>
inline const QList<P> &INPolygon<P>::points() const
{
    return this->points_;
}

template<class P>
inline void INPolygon<P>::setPolygon( const QList<P> &points )
{
    this->points_ = points;
}

template<class P>
inline void INPolygon<P>::append( const P &point )
{
    this->points_.append( point );
}

template<class P>
inline void INPolygon<P>::clear()
{
    this->points_.clear();
}

template<class P>
inline bool INPolygon<P>::isValid() const
{
    return ( this->points_.count() > 2 );
}

#endif // INPOLYGON_H
