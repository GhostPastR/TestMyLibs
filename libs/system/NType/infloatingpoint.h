#ifndef INFLOAT_H
#define INFLOAT_H

#include "intype.h"
#include "nint32.h"

template<class M, class T>
class INFloatingPoint : public INType<T>
{
public:   
    /**
     * @brief isInfinity - Метод, позволяющее определить, равен ли данный
     * экземпляр плюс или минус бесконечности.
     * @return Значение true, если данный экземпляр равен значению плюс
     * бесконечности или минус бесконечности, в противном случае — значение false.
     */
    bool isInfinity() const noexcept;

    /**
     * @brief isNaN - Метод, позволяющее определить, что данный экземпляр не
     * является числом.
     * @return Значение true, если если данный экземпляр равен неопределенному
     * значению, в противном случае — значение false.
     */
    bool isNaN() const noexcept;

    /**
     * @brief isNegativeInfinity - Метод, позволяющее определить, равен ли
     * данный экземпляр минус бесконечности.
     * @return Значение true, если данный экземпляр равен значению минус
     * бесконечности в противном случае — значение false.
     */
    bool isNegativeInfinity() const noexcept;

    /**
     * @brief isPositiveInfinity - Метод, позволяющее определить, равен ли
     * данный экземпляр плюс бесконечности.
     * @return Значение true, если данный экземпляр равен значению плюс
     * бесконечности в противном случае — значение false.
     */
    bool isPositiveInfinity() const noexcept;

    /**
     * @brief intervalStrict - Шаблонный метод, позволяющий определить попадания
     * данного экземпляра в замкнутый интервал(строгое равенство),
     * ограничевающими значениями left и right.
     * @param left - левая граница интервала.
     * @param right - правая граница интервала.
     * @return Значение true, если данный экземпляр попадает в интервал, в
     * противном случае — значение false.
     */
    bool intervalStrict( const M &left, const M &right,
                         NInt32 number = NInt32(6) ) const noexcept;

    /**
     * @brief intervalLeftStrict - Шаблонный метод, позволяющий определить
     * попадания данного экземпляра в полузамкнутый интервал по левому значению,
     * ограничевающими значениями left и right. Для левого значения используется
     * строгое равенство.
     * @param left - левая граница интервала.
     * @param right - правая граница интервала.
     * @return Значение true, если данный экземпляр попадает в интервал, в
     * противном случае — значение false.
     */
    bool intervalLeftStrict( const M &left, const M &right,
                             NInt32 number = NInt32(6) ) const noexcept;

    /**
     * @brief intervalRightStrict - Шаблонный метод, позволяющий определить,
     * попадания данного экземпляра в полузамкнутый интервал по правому
     * значению, ограничевающими значениями left и right. Для правого значения
     * используется строгое равенство.
     * @param left - левая граница интервала.
     * @param right - правая граница интервала.
     * @return  Значение true, если данный экземпляр попадает в интервал,
     * в противном случае — значение false.
     */
    bool intervalRightStrict( const M &left, const M &right,
                              NInt32 number = NInt32(6) ) const noexcept;

    /**
     * @brief intervalSlack - Шаблонный метод, позволяющее определить, попадания
     * данного экземпляра в открытый интервал(не строгое равенство),
     * ограничевающими значениями left и right.
     * @param left - левая граница интервала.
     * @param right - правая граница интервала.
     * @return Значение true, если данный экземпляр попадает в интервал, в
     * противном случае — значение false.
     */
    bool intervalSlack( const M &left, const M &right ) const noexcept;

    //! \brief abs - Шаблонный метод, позволяющий вернуть абсолютное значение
    //! экземпляра класса.
    //! \return абсолютное значение.
    M abs() const noexcept;

protected:
    INFloatingPoint() noexcept;
    INFloatingPoint( const INFloatingPoint &nFloat ) noexcept;
    INFloatingPoint( INFloatingPoint &&nFloat ) noexcept;
    ~INFloatingPoint() noexcept;

    INFloatingPoint &operator=( const INFloatingPoint &nFloat ) noexcept;
    INFloatingPoint &operator=( INFloatingPoint &&nFloat ) noexcept;
};

template<class M, class T>
inline bool INFloatingPoint<M, T>::isInfinity() const noexcept
{
    return M::isInfinity( static_cast<M>( *this ) );
}

template<class M, class T>
inline bool INFloatingPoint<M, T>::isNaN() const noexcept
{
    return M::isNaN( static_cast<M>( *this ) );
}

template<class M, class T>
inline bool INFloatingPoint<M, T>::isNegativeInfinity() const noexcept
{
    return M::isNegativeInfinity( static_cast<M>( *this ) );
}

template<class M, class T>
inline bool INFloatingPoint<M, T>::isPositiveInfinity() const noexcept
{
    return M::isPositiveInfinity( static_cast<M>( *this ) );
}

template<class M, class T>
inline bool INFloatingPoint<M, T>::intervalStrict( const M &left, const M &right,
                                           NInt32 number ) const noexcept
{
    return ( static_cast<M>( *this ).moreThan( left, number )
             && static_cast<M>( *this ).feverThan( right, number ) );
}

template<class M, class T>
inline bool INFloatingPoint<M, T>::intervalLeftStrict( const M &left, const M &right,
                                               NInt32 number ) const noexcept
{
    return ( static_cast<M>( *this ).moreThan( left, number )
             && ( static_cast<M>( *this ) < right ) );
}

template<class M, class T>
inline bool INFloatingPoint<M, T>::intervalRightStrict( const M &left, const M &right,
                                                NInt32 number ) const noexcept
{
    return ( ( left < static_cast<M>( *this ) )
             && static_cast<M>( *this ).feverThan( right, number ) );
}

template<class M, class T>
inline bool INFloatingPoint<M, T>::intervalSlack( const M &left, const M &right ) const noexcept
{
    return ( ( left < static_cast<M>( *this ) )
             && ( static_cast<M>( *this ) < right ) );
}

template<class M, class T>
inline M INFloatingPoint<M,T>::abs() const noexcept
{
    if( this->value_ < M().toType() )
        return M( -this->value_ );
    return M( this->value_ );
}

template<class M, class T>
inline INFloatingPoint<M,T>::INFloatingPoint() noexcept
{

}

template<class M, class T>
inline INFloatingPoint<M,T>::INFloatingPoint( const INFloatingPoint &nFloat ) noexcept
    : INType<T>(nFloat)
{

}

template<class M, class T>
inline INFloatingPoint<M,T>::INFloatingPoint( INFloatingPoint &&nFloat ) noexcept
    : INType<T>(nFloat)
{

}

template<class M, class T>
inline INFloatingPoint<M,T>::~INFloatingPoint() noexcept
{

}

template<class M, class T>
inline INFloatingPoint<M,T> &INFloatingPoint<M,T>::operator=
                                      ( const INFloatingPoint &nFloat ) noexcept
{
    INType<T>::operator=(nFloat);
    return *this;
}

template<class M, class T>
inline INFloatingPoint<M,T> &INFloatingPoint<M,T>::operator=
                                           ( INFloatingPoint &&nFloat ) noexcept
{
    INType<T>::operator=(nFloat);
    return *this;
}

#endif // INFloat_H


