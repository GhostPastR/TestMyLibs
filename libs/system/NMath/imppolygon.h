#ifndef IMPPOLYGON_H
#define IMPPOLYGON_H

#include <QList>

template<class P>
/**
 * @brief The IMpPolygon class - Класс интерфейс для новых классов
 * описывающие геометрический примитив полигон.
 */
class IMpPolygon
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
    IMpPolygon();
    IMpPolygon( int count );
    IMpPolygon( const QList<P> &points );
    IMpPolygon( const IMpPolygon &mpPolygon );
    IMpPolygon( IMpPolygon &&mpPolygon );
    ~IMpPolygon();

    IMpPolygon &operator=( const IMpPolygon &mpPolygon );
    IMpPolygon &operator=( IMpPolygon &&mpPolygon );

    /**
     * @brief points_ - Список точек полигона.
     */
    QList<P> points_;
};

template<class P>
inline IMpPolygon<P>::IMpPolygon()
{

}

template<class P>
inline IMpPolygon<P>::IMpPolygon( int count )
{
    for( int i = 0; i < count; i++ )
        this->points_.append( P() );
}

template<class P>
inline IMpPolygon<P>::IMpPolygon( const QList<P> &points )
{
    this->setPolygon( points );
}

template<class P>
inline IMpPolygon<P>::IMpPolygon( const IMpPolygon &mpPolygon )
{
    this->points_ = mpPolygon.points_;
}

template<class P>
inline IMpPolygon<P>::IMpPolygon( IMpPolygon &&mpPolygon )
{
    this->points_ = std::move( mpPolygon.points_ );
}

template<class P>
inline IMpPolygon<P>::~IMpPolygon()
{

}

template<class P>
inline IMpPolygon<P> &IMpPolygon<P>::operator=( const IMpPolygon &mpPolygon )
{
    this->points_ = mpPolygon.points_;
    return *this;
}

template<class P>
inline IMpPolygon<P> &IMpPolygon<P>::operator=( IMpPolygon &&mpPolygon )
{
    this->points_ = std::move( mpPolygon.points_ );
    return *this;
}

template<class P>
inline QList<P> &IMpPolygon<P>::points()
{
    return this->points_;
}

template<class P>
inline const QList<P> &IMpPolygon<P>::points() const
{
    return this->points_;
}

template<class P>
inline void IMpPolygon<P>::setPolygon( const QList<P> &points )
{
    this->points_ = points;
}

template<class P>
inline void IMpPolygon<P>::append( const P &point )
{
    this->points_.append( point );
}

template<class P>
inline void IMpPolygon<P>::clear()
{
    this->points_.clear();
}

template<class P>
inline bool IMpPolygon<P>::isValid() const
{
    return ( this->points_.count() > 2 );
}

#endif // IMPPOLYGON_H
