#ifndef NMASS_H
#define NMASS_H

#include <ntype.h>

/**
 * @brief The NMass class - Класс предназначен для работы с величинами
 * характеризующие вес.
 */
class NMass
{
public:
    NMass() noexcept;
    NMass( const nreal &kg ) noexcept;
    NMass( const NMass &mass );
    NMass( NMass &&mass );

    /**
     * @brief g - Возвращает значения экземпляра класса в граммах.
     * @return значение в граммах.
     */
    nreal g() const noexcept;
    /**
     * @brief kg - Возвращает значения экземпляра класса в килограммах.
     * @return значение в килограммах.
     */
    nreal kg() const noexcept;
    /**
     * @brief t - Возвращает значения экземпляра класса в тоннах.
     * @return значение в тоннах.
     */
    nreal t() const noexcept;

    /**
     * @brief setG - Задает новое значения для экземпляра класса в граммах.
     * @param g - новое значение в граммах.
     * @return ссылка на экземпляр класса.
     */
    NMass &setG( const nreal &g ) noexcept;
    /**
     * @brief setKg - Задает новое значения для экземпляра класса в килограммах.
     * @param kg - новое значение в килограммах.
     * @return ссылка на экземпляр класса.
     */
    NMass &setKg( const nreal &kg ) noexcept;
    /**
     * @brief setT - Задает новое значения для экземпляра класса в тоннах.
     * @param t - новое значение в тоннах.
     * @return ссылка на экземпляр класса.
     */
    NMass &setT( const nreal &t ) noexcept;

    NMass &operator=( const NMass &mass );
    NMass &operator=( NMass &&mass );

    bool operator ==( const NMass &value ) const noexcept;
    bool operator !=( const NMass &value ) const noexcept;
    bool operator >=( const NMass &value ) const noexcept;
    bool operator <=( const NMass &value ) const noexcept;
    bool operator >( const NMass &value ) const noexcept;
    bool operator <( const NMass &value ) const noexcept;

    NMass operator +( const NMass &value ) const noexcept;
    NMass operator -( const NMass &value ) const noexcept;
    NMass &operator +=( const NMass &value ) noexcept;
    NMass &operator -=( const NMass &value ) noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса
     * на 1.
     * @return экземпляр класса с новым значением.
     */
    NMass &operator++() noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса на
     * 1 и возвращающие старое значение.
     * @return  экземпляр класса со старым значением.
     */
    NMass operator++(int) noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1.
     * @return экземпляр класса с новым значением.
     */
    NMass &operator--() noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1
     * и возвращающие старое значение.
     * @return экземпляр класса со старыи значением.
     */
    NMass operator--(int) noexcept;

    friend NMass operator "" _g( long double g ) noexcept;
    friend NMass operator "" _kg( long double kg ) noexcept;
    friend NMass operator "" _t( long double t ) noexcept;

private:
    nreal value_;
};

inline NMass::NMass() noexcept
{

}

inline NMass::NMass(const nreal &kg ) noexcept
{
    this->value_ = kg;
}

inline NMass::NMass( const NMass &mass )
{
    this->value_ = mass.value_;
}

inline NMass::NMass( NMass &&mass )
{
    this->value_ = std::move( mass.value_ );
}

inline nreal NMass::g() const noexcept
{
    return this->value_* nreal( 1000.0 );
}

inline nreal NMass::kg() const noexcept
{
    return this->value_;
}

inline nreal NMass::t() const noexcept
{
    return this->value_ * nreal( 0.001 );
}

inline NMass &NMass::setG( const nreal &g ) noexcept
{
    this->value_ = g / nreal( 1000.0 );
    return *this;
}

inline NMass &NMass::setKg( const nreal &kg ) noexcept
{
    this->value_ = kg;
    return *this;
}

inline NMass &NMass::setT( const nreal &t ) noexcept
{
    this->value_ = t * nreal( 1000.0 );
    return *this;
}

inline NMass &NMass::operator=( const NMass &mass )
{
    this->value_ = mass.value_;
    return *this;
}

inline NMass &NMass::operator=( NMass &&mass )
{
    this->value_ = std::move( mass.value_ );
    return *this;
}

inline bool NMass::operator ==( const NMass &value ) const noexcept
{
    return this->value_.compare( value.value_ );
}

inline bool NMass::operator !=( const NMass &value ) const noexcept
{
    return this->value_.unequal( value.value_ );
}

inline bool NMass::operator >=( const NMass &value ) const noexcept
{
    return this->value_.moreThan( value.value_ );
}

inline bool NMass::operator <=( const NMass &value ) const noexcept
{
    return this->value_.feverThan( value.value_ );
}

inline bool NMass::operator >( const NMass &value ) const noexcept
{
    return ( this->value_ > value.value_ );
}

inline bool NMass::operator <( const NMass &value ) const noexcept
{
    return ( this->value_ < value.value_ );
}

inline NMass NMass::operator +( const NMass &value ) const noexcept
{
    return NMass(this->value_ + value.value_);
}

inline NMass NMass::operator -( const NMass &value ) const noexcept
{
    return NMass(this->value_ - value.value_);
}

inline NMass &NMass::operator += ( const NMass &value ) noexcept
{
    this->value_ += value.value_;
    return *this;
}

inline NMass &NMass::operator -= ( const NMass &value ) noexcept
{
    this->value_ -= value.value_;
    return *this;
}

inline NMass &NMass::operator++() noexcept
{
        ++this->value_;
    return *this;
}

inline NMass NMass::operator++(int) noexcept
{
    NMass v = this->value_;
        ++(*this);
    return v;
}

inline NMass &NMass::operator--() noexcept
{
        --this->value_;
    return *this;
}

inline NMass NMass::operator--(int) noexcept
{
    NMass v = *this;
        --(*this);
    return v;
}

inline NMass operator "" _g( long double g ) noexcept
{
    return NMass().setG( nreal( double( g ) ) );
}

inline NMass operator "" _kg( long double kg ) noexcept
{
    return NMass( nreal( double( kg ) ) );
}

inline NMass operator "" _t( long double t ) noexcept
{
    return NMass().setT( nreal( double( t ) ) );
}

#endif // NMASS_H

