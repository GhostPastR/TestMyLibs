#ifndef INNUMBER_H
#define INNUMBER_H

#include "intype.h"

template<class M, class T>
class INNumber : public INType<T>
{
public:
    /**
     * @brief intervalStrict - Шаблонный метод, позволяющий определить попадания
     * данного экземпляра класса в замкнутый интервал(строгое равенство),
     * ограничевающими значениями left и right.
     * @param left - левая граница интервала.
     * @param right - правая граница интервала.
     * @return Значение true, если данный экземпляр попадает в интервал, в
     * противном случае — значение false.
     */
    bool intervalStrict( const M &left, const M &right ) const noexcept;

    /**
     * @brief intervalLeftStrict - Шаблонный метод, позволяющий определить
     * попадания данного экземпляра в полузамкнутый интервал по левому значению,
     * ограничевающими значениями left и right.
     * @param left - левая граница интервала.
     * @param right - правая граница интервала.
     * @return Значение true, если данный экземпляр попадает в интервал, в
     * противном случае — значение false.
     */
    bool intervalLeftStrict( const M &left, const M &right ) const noexcept;

    /**
     * @brief intervalRightStrict - Шаблонный метод, позволяющий определить,
     * попадания данного экземпляра в полузамкнутый интервал по правому
     * значению, ограничевающими значениями left и right.
     * @param left - левая граница интервала.
     * @param right - правая граница интервала.
     * @return  Значение true, если данный экземпляр попадает в интервал, в
     * противном случае — значение false.
     */
    bool intervalRightStrict( const M &left, const M &right ) const noexcept;

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

    /**
     * @brief abs - Шаблонный метод, позволяющий вернуть абсолютное значение
     * экземпляра класса.
     * @return абсолютное значение.
     */
    M abs() const noexcept;

protected:    
    INNumber() noexcept;
    INNumber( const INNumber &nNumber ) noexcept;
    INNumber( INNumber &&nNumber ) noexcept;
    ~INNumber() noexcept;

    INNumber &operator=( const INNumber &nNumber ) noexcept;
    INNumber &operator=( INNumber &&nNumber ) noexcept;
};

template<class M, class T>
inline bool INNumber<M,T>::intervalStrict( const M &left,
                                    const M &right ) const noexcept
{
    return ( ( left <= *this ) && ( *this <= right ) );
}

template<class M, class T>
inline bool INNumber<M,T>::intervalLeftStrict( const M &left,
                                        const M &right ) const noexcept
{
    return ( ( left <= *this ) && ( *this < right ) );
}

template<class M, class T>
inline bool INNumber<M,T>::intervalRightStrict( const M &left,
                                         const M &right ) const noexcept
{
    return ( ( left < *this ) && ( *this <= right ) );
}

template<class M, class T>
inline bool INNumber<M,T>::intervalSlack( const M &left,
                                   const M &right ) const noexcept
{
    return ( ( left < *this ) && ( *this < right ) );
}

template<class M, class T>
inline M INNumber<M,T>::abs() const noexcept
{
    if( this->value_ < M().toType() )
        return M( -this->value_ );
    return M( this->value_ );
}

template<class M, class T>
inline INNumber<M,T>::INNumber() noexcept : INType<T>()
{

}

template<class M, class T>
inline INNumber<M,T>::INNumber( const INNumber &nNumber ) noexcept
    : INType<T>(nNumber)
{

}

template<class M, class T>
inline INNumber<M,T>::INNumber( INNumber &&nNumber ) noexcept
    : INType<T>(nNumber)
{

}

template<class M, class T>
inline INNumber<M,T>::~INNumber() noexcept
{

}

template<class M, class T>
inline INNumber<M,T> &INNumber<M,T>::operator=
                                            ( const INNumber &nNumber ) noexcept
{
    INType<T>::operator=( nNumber );
    return *this;
}

template<class M, class T>
inline INNumber<M,T> &INNumber<M,T>::operator=( INNumber &&nNumber ) noexcept
{
    INType<T>::operator=( nNumber );
    return *this;
}

#endif // INNUMBER_H
