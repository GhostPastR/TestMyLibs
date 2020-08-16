#ifndef INTYPE_H
#define INTYPE_H

#include <iostream>
#include <math.h>

#define ERROR 0

class NDouble;
class NInt32;
class NUInt32;
class NInt64;
class NUInt64;

template <class T>
class INType
{
public:
    /**
     * @brief toBool - Метод конвертирует значения экземпляра класса в тип bool.
     * Если размер заданного типа больше bool, то произойдет потеря данных.
     * @return значения типа bool.
     */
    bool toBool() const noexcept;
    /**
     * @brief toChar - Метод конвертирует значения экземпляра класса в тип char.
     * Если размер заданного типа больше char, то произойдет потеря данных.
     * @return значения типа char.
     */
    char toChar() const noexcept;
    /**
     * @brief toByte - Метод конвертирует значения экземпляра класса в тип
     * unsigned char. Если размер заданного типа больше char, то произойдет
     * потеря данных.
     * @return значения типа unsigned char.
     */
    unsigned char toByte() const noexcept;
    /**
     * @brief toInt16 - Метод конвертирует значения экземпляра класса в тип
     * short. Если размер заданного типа больше short, то произойдет потеря
     * данных.
     * @return значения типа short.
     */
    short toInt16() const noexcept;
    /**
     * @brief toUInt16 - Метод конвертирует значения экземпляра класса в тип
     * unsigned short. Если размер заданного типа больше unsigned short, то
     * произойдет потеря данных.
     * @return значения типа unsigned short.
     */
    unsigned short toUInt16() const noexcept;
    /**
     * @brief toInt32 - Метод конвертирует значения экземпляра класса в тип int.
     * Если размер заданного типа больше int, то произойдет потеря данных.
     * @return значения типа int.
     */
    int toInt32() const noexcept;
    /**
     * @brief toUInt32 - Метод конвертирует значения экземпляра класса в тип
     * unsigned int. Если размер заданного типа больше unsigned int, то
     * произойдет потеря данных.
     * @return значения типа unsigned int.
     */
    unsigned int toUInt32() const noexcept;
    /**
     * @brief toInt64 - Метод конвертирует значения экземпляра класса в тип
     * long long. Если размер заданного типа больше long long, то произойдет
     * потеря данных.
     * @return значения типа long long.
     */
    long long toInt64() const noexcept;
    /**
     * @brief toUInt64 - Метод конвертирует значения экземпляра класса в тип
     * unsigned long long. Если размер заданного типа больше unsigned long long,
     * то произойдет потеря данных.
     * @return значения типа unsigned long long.
     */
    unsigned long long toUInt64() const noexcept;
    /**
     * @brief toFloat - Метод конвертирует значения экземпляра класса в тип
     * float. Если размер заданного типа больше float, то произойдет потеря
     * данных.
     * @return значения типа float.
     */
    float toFloat() const noexcept;
    /**
     * @brief toDouble - Метод конвертирует значения экземпляра класса в тип
     * double. Если размер заданного типа больше double, то произойдет потеря
     * данных.
     * @return значения типа double.
     */
    double toDouble() const noexcept;

    /**
     * @brief toType - Метод возвращает значения данного экземпляра приводить в
     * стандартный тип T.
     * @return значения стандартного типа.
     */
    T toType() const noexcept;

    /**
     * @brief toConvert - Шаблонный метод конвертирует экземпляр класса в тип
     * заданный шаблонном M, являющимся потомком класса INType.
     * @return экземпляр класса M.
     */
    template <class M>
    M toConvert();

    /** \brief operator T - Шаблонный оператор, позволяющий, значения данного
     * экземпляра приводить в стандартны тип T.
     */
    operator T() const noexcept;

protected:
    INType() noexcept;
    INType( const INType &type ) noexcept;
    INType( INType &&type ) noexcept;
    ~INType() noexcept;

    INType &operator=( const INType &type ) noexcept;
    INType &operator=( INType &&type ) noexcept;

    T value_;
};

template <class T>
inline bool INType<T>::toBool() const noexcept
{
    return static_cast<bool>( this->value_ );
}

template <class T>
inline char INType<T>::toChar() const noexcept
{
    return static_cast<char>( this->value_ );
}

template <class T>
inline unsigned char INType<T>::toByte() const noexcept
{
    return static_cast<unsigned char>( this->value_ );
}

template <class T>
inline short INType<T>::toInt16() const noexcept
{
    return static_cast<short>( this->value_ );
}

template <class T>
inline unsigned short INType<T>::toUInt16() const noexcept
{
    return static_cast<unsigned short>( this->value_ );
}

template <class T>
inline int INType<T>::toInt32() const noexcept
{
    return static_cast<int>( this->value_ );
}

template <class T>
inline unsigned int INType<T>::toUInt32() const noexcept
{
    return static_cast<unsigned>( this->value_ );
}

template <class T>
inline long long INType<T>::toInt64() const noexcept
{
    return static_cast<long long>( this->value_ );
}

template <class T>
unsigned long long INType<T>::toUInt64() const noexcept
{
    return static_cast<unsigned long long>( this->value_ );
}

template <class T>
inline float INType<T>::toFloat() const noexcept
{
    return static_cast<float>( this->value_ );
}

template <class T>
inline double INType<T>::toDouble() const noexcept
{
    return static_cast<double>( this->value_ );
}

template<class T>
inline T INType<T>::toType() const noexcept
{
    return this->operator T();
}

template<class T>
inline INType<T>::INType() noexcept
{

}

template<class T>
inline INType<T>::INType( const INType &type ) noexcept
{
    this->value_ = type.value_;
}

template<class T>
inline INType<T>::INType( INType &&type ) noexcept
{
    this->value_ = std::move( type.value_ );
}

template<class T>
INType<T>::~INType() noexcept
{

}

template<class T>
inline INType<T> &INType<T>::operator=( const INType &type ) noexcept
{
    this->value_ = type.value_;
    return *this;
}

template<class T>
inline INType<T> &INType<T>::operator=( INType &&type ) noexcept
{
    this->value_ = std::move( type.value_ );
    return *this;
}

template <class T>
inline INType<T>::operator T() const noexcept
{
    return this->value_;
}

template <class T>
template <class M>
inline M INType<T>::toConvert()
{
    return M( this->operator T() );
}

#endif // INTYPE_H


