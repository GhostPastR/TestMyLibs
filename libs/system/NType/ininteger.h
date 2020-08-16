#ifndef IINTEGER_H
#define IINTEGER_H

#include "innumber.h"

template<class M, class T>
class INInteger : public INNumber<M,T>
{
protected:
    INInteger() noexcept;
    INInteger( const INInteger &nInteger ) noexcept;
    INInteger( INInteger &&nInteger ) noexcept;
    ~INInteger() noexcept;

    INInteger &operator=( const INInteger &nInteger ) noexcept;
    INInteger &operator=( INInteger &&nInteger ) noexcept;

    /**
     * @brief sum - Статический метод, реализующий суммирования 2-х чисел,
     * заданного типа. При этом производит проверку переполнения и присваивает
     * значения min или max выходному значению.
     * @param value1 - 1-е значение.
     * @param value2 - 2-е значение.
     * @param min - Минимальное значения заданного типа.
     * @param max - Максимальное значения заданного типа.
     * @return Результат суммирования 2-х чисел. Если происходит переполнение по
     * отрицательным числам, то возвращается min. Если переполнения по
     * положительным числами, то возвращает max. При переполнении выводится
     * сообщение об ошибки.
     */
    static M sum( const T &value1, const T &value2, const M &min,
                  const M &max ) noexcept;
    /**
     * @brief diff - Статический метод, реализующий разность 2-х чисел,
     * заданного типа. При этом производит проверку переполнения и присваивает
     * значения min или max выходному значению.
     * @param value1 - 1-е значение.
     * @param value2 - 2-е значение.
     * @param min - Минимальное значения заданного типа.
     * @param max - Максимальное значения заданного типа.
     * @return Результат разности 2-х чисел. Если происходит перепелнения по
     * отрицательным числам, то возвращается min. Если переполнения по
     * положительным числами, то возвращает max.При переполнении выводится
     * сообщение об ошибки.
     */
    static M diff( const T &value1, const T &value2, const M &min,
                   const M &max ) noexcept;
    /**
     * @brief mul - Статический метод, реализующий произведение 2-х чисел,
     * заданного типа. При этом производит проверку переполнения и присваивает
     * значения min или max выходному значению.
     * @param value1 - 1-е значение.
     * @param value2 - 2-е значение.
     * @param min - Минимальное значения заданного типа.
     * @param max - Максимальное значения заданного типа.
     * @return Результат произведения 2-х чисел. Если происходит перепелнения по
     * отрицательным числам, то возвращается min. Если переполнения по
     * положительным числами, то возвращает max. При переполнении выводится
     * сообщение об ошибки.
     */
    static M mul( const T &value1, const T &value2, const M &min,
                  const M &max ) noexcept;
    /**
     * @brief div - Статический метод, реализующий частное 2-х чисел,
     * заданного типа. При этом производит проверку переполнения(при деление на
     * ноль) и присваивает значения min или max выходному значению.
     * @param value1 - 1-е значение.
     * @param value2 - 2-е значение.
     * @param min - Минимальное значения заданного типа.
     * @param max - Максимальное значения заданного типа.
     * @return Результат частного 2-х чисел. Если происходит деления на 0, то
     * выводится сообщение об ошибке. При делении на 0 возвращается min значения
     * в том случаи если 1-е значение отрицательно, возвращается max значения
     * в том случаи если 1-е значение положительное, возвращается 0, если
     * 1-е значение равно 0.
     */
    static M div( const T &value1, const T &value2, const M &min,
                  const M &max ) noexcept;
};

template<class M, class T>
inline INInteger<M,T>::INInteger() noexcept : INNumber<M,T>()
{

}


template<class M, class T>
inline INInteger<M,T>::INInteger( const INInteger &nInteger ) noexcept
    : INNumber<M,T>(nInteger)
{

}

template<class M, class T>
inline INInteger<M,T>::INInteger(INInteger &&nInteger) noexcept
    : INNumber<M,T>(nInteger)
{

}

template<class M, class T>
inline INInteger<M,T>::~INInteger() noexcept
{

}

template<class M, class T>
inline INInteger<M,T> &INInteger<M,T>::operator=
                                          ( const INInteger &nInteger ) noexcept
{
    INNumber<M,T>::operator=( nInteger );
    return *this;
}

template<class M, class T>
inline INInteger<M,T> &INInteger<M,T>::operator=
                                               ( INInteger &&nInteger ) noexcept
{
    INNumber<M,T>::operator=( nInteger );
    return *this;
}

template<class M, class T>
inline M INInteger<M, T>::sum(const T &value1, const T &value2 , const M &min,
                       const M &max ) noexcept
{
    T _value = value1 + value2;
    if( ( value1 > 0 ) && ( value2 > 0 ) )
    {
        if( _value < value1 )
        {
            std::wcerr << "Error! Overflow! value1 = " << value1
                       << " and value2 = " << value2 << std::endl;
            return max;
        }
    }
    if( ( value1 < 0 ) && ( value2 < 0 ) )
    {
        if( _value > value1 )
        {
            std::wcerr << "Error! Overflow! value1 = " << value1
                       << " and value2 = " << value2 << std::endl;
            return min;
        }
    }
    return M( _value );
}

template<class M, class T>
inline M INInteger<M, T>::diff( const T &value1, const T &value2, const M &min,
                                const M &max ) noexcept
{
    T _value = value1 - value2;
    if( ( value1 > 0 ) && ( value2 < 0 ) )
    {
        if( _value < value1 )
        {
            std::wcerr << "Error! Overflow! value1 = " << value1
                       << " and value2 = " << value2 << std::endl;
            return max;
        }
    }
    if( ( value1 < 0 ) && ( value2 > 0 ) )
    {
        if( _value > value1 )
        {
            std::wcerr << "Error! Overflow! value1 = " << value1
                       << " and value2 = " << value2 << std::endl;
            return min;
        }
    }
    if( ( value1 > 0 ) && ( value2 > 0 ) )
    {
        if( _value > value1 )
        {
            std::wcerr << "Error! Overflow! value1 = " << value1
                       << " and value2 = " << value2 << std::endl;
            return min;
        }
    }
    return M( _value );
}

template<class M, class T>
inline M INInteger<M,T>::mul( const T &value1, const T &value2, const M &min,
                              const M &max ) noexcept
{
    if( value2 != 0 )
    {
        if( ( value1 > 0 ) && ( value2 > 0 ) )
        {
            T v = max / value2;
            if( value1 > v )
            {
                std::wcerr << "Error! Overflow! value1 = " << value1
                           << " and value2 = " << value2 << std::endl;
                return max;
            }
        }
        if( ( value1 < 0 ) && ( value2 < 0 ) )
        {
            T v = max / value2;
            if( value1 < v )
            {
                std::wcerr << "Error! Overflow! value1 = " << value1
                           << " and value2 = " << value2 << std::endl;
                return max;
            }
        }
        if( ( value1 > 0 ) && ( value2 < 0 ) )
        {
            T v = min / value2;
            if( value1 > v )
            {
                std::wcerr << "Error! Overflow! value1 = " << value1
                           << " and value2 = " << value2 << std::endl;
                return min;
            }
        }
        if( ( value1 < 0 ) && ( value2 > 0 ) )
        {
            T v = min / value2;
            if( value1 < v )
            {
                std::wcerr << "Error! Overflow! value1 = " << value1
                           << " and value2 = " << value2 << std::endl;
                return min;
            }
        }
        return M( value1 * value2 );
    }
    return M();
}

template<class M, class T>
inline M INInteger<M, T>::div( const T &value1, const T &value2, const M &min,
                               const M &max ) noexcept
{
    if( value2 == 0 )
    {
        if( value1 < 0 )
        {
            std::wcerr << "Error! 0 divide! value1 = " << value1
                       << " and value2 = " << value2 << std::endl;
            return min;
        }
        if( value1 > 0 )
        {
            std::wcerr << "Error! 0 divide! value1 = " << value1
                       << " and value2 = " << value2 << std::endl;
            return max;
        }
        if( value1 == 0 )
        {
            std::wcerr << "Error! 0 divide! value1 = " << value1
                       << " and value2 = " << value2 << std::endl;
            return M();
        }
    }
    return M( value1 / value2 );
}

#endif // IINTEGER_H
