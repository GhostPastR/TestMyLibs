#ifndef MPMASS_H
#define MPMASS_H

#include <ntype.h>

/**
 * @brief The MpMass class - Класс предназначен для работы с величинами
 * характеризующие вес.
 */
class MpMass
{
public:
    MpMass() noexcept;
    MpMass( const nreal &kg ) noexcept;
    MpMass( const MpMass &mass );
    MpMass( MpMass &&mass );

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
    MpMass &setG( const nreal &g ) noexcept;
    /**
     * @brief setKg - Задает новое значения для экземпляра класса в килограммах.
     * @param kg - новое значение в килограммах.
     * @return ссылка на экземпляр класса.
     */
    MpMass &setKg( const nreal &kg ) noexcept;
    /**
     * @brief setT - Задает новое значения для экземпляра класса в тоннах.
     * @param t - новое значение в тоннах.
     * @return ссылка на экземпляр класса.
     */
    MpMass &setT( const nreal &t ) noexcept;

    MpMass &operator=( const MpMass &mass );
    MpMass &operator=( MpMass &&mass );

    bool operator ==( const MpMass &value ) const noexcept;
    bool operator !=( const MpMass &value ) const noexcept;
    bool operator >=( const MpMass &value ) const noexcept;
    bool operator <=( const MpMass &value ) const noexcept;
    bool operator >( const MpMass &value ) const noexcept;
    bool operator <( const MpMass &value ) const noexcept;

    MpMass operator +( const MpMass &value ) const noexcept;
    MpMass operator -( const MpMass &value ) const noexcept;
    MpMass &operator +=( const MpMass &value ) noexcept;
    MpMass &operator -=( const MpMass &value ) noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса
     * на 1.
     * @return экземпляр класса с новым значением.
     */
    MpMass &operator++() noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса на
     * 1 и возвращающие старое значение.
     * @return  экземпляр класса со старым значением.
     */
    MpMass operator++(int) noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1.
     * @return экземпляр класса с новым значением.
     */
    MpMass &operator--() noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1
     * и возвращающие старое значение.
     * @return экземпляр класса со старыи значением.
     */
    MpMass operator--(int) noexcept;

    friend MpMass operator "" _g( long double g ) noexcept;
    friend MpMass operator "" _kg( long double kg ) noexcept;
    friend MpMass operator "" _t( long double t ) noexcept;

private:
    nreal value_;
};

inline MpMass::MpMass() noexcept
{

}

inline MpMass::MpMass(const nreal &kg ) noexcept
{
    this->value_ = kg;
}

inline MpMass::MpMass( const MpMass &mass )
{
    this->value_ = mass.value_;
}

inline MpMass::MpMass( MpMass &&mass )
{
    this->value_ = std::move( mass.value_ );
}

inline nreal MpMass::g() const noexcept
{
    return this->value_* nreal( 1000.0 );
}

inline nreal MpMass::kg() const noexcept
{
    return this->value_;
}

inline nreal MpMass::t() const noexcept
{
    return this->value_ * nreal( 0.001 );
}

inline MpMass &MpMass::setG( const nreal &g ) noexcept
{
    this->value_ = g / nreal( 1000.0 );
    return *this;
}

inline MpMass &MpMass::setKg( const nreal &kg ) noexcept
{
    this->value_ = kg;
    return *this;
}

inline MpMass &MpMass::setT( const nreal &t ) noexcept
{
    this->value_ = t * nreal( 1000.0 );
    return *this;
}

inline MpMass &MpMass::operator=( const MpMass &mass )
{
    this->value_ = mass.value_;
    return *this;
}

inline MpMass &MpMass::operator=( MpMass &&mass )
{
    this->value_ = std::move( mass.value_ );
    return *this;
}

inline bool MpMass::operator ==( const MpMass &value ) const noexcept
{
    return this->value_.compare( value.value_ );
}

inline bool MpMass::operator !=( const MpMass &value ) const noexcept
{
    return this->value_.unequal( value.value_ );
}

inline bool MpMass::operator >=( const MpMass &value ) const noexcept
{
    return this->value_.moreThan( value.value_ );
}

inline bool MpMass::operator <=( const MpMass &value ) const noexcept
{
    return this->value_.feverThan( value.value_ );
}

inline bool MpMass::operator >( const MpMass &value ) const noexcept
{
    return ( this->value_ > value.value_ );
}

inline bool MpMass::operator <( const MpMass &value ) const noexcept
{
    return ( this->value_ < value.value_ );
}

inline MpMass MpMass::operator +( const MpMass &value ) const noexcept
{
    return MpMass(this->value_ + value.value_);
}

inline MpMass MpMass::operator -( const MpMass &value ) const noexcept
{
    return MpMass(this->value_ - value.value_);
}

inline MpMass &MpMass::operator += ( const MpMass &value ) noexcept
{
    this->value_ += value.value_;
    return *this;
}

inline MpMass &MpMass::operator -= ( const MpMass &value ) noexcept
{
    this->value_ -= value.value_;
    return *this;
}

inline MpMass &MpMass::operator++() noexcept
{
        ++this->value_;
    return *this;
}

inline MpMass MpMass::operator++(int) noexcept
{
    MpMass v = this->value_;
        ++(*this);
    return v;
}

inline MpMass &MpMass::operator--() noexcept
{
        --this->value_;
    return *this;
}

inline MpMass MpMass::operator--(int) noexcept
{
    MpMass v = *this;
        --(*this);
    return v;
}

inline MpMass operator "" _g( long double g ) noexcept
{
    return MpMass().setG( nreal( double( g ) ) );
}

inline MpMass operator "" _kg( long double kg ) noexcept
{
    return MpMass( nreal( double( kg ) ) );
}

inline MpMass operator "" _t( long double t ) noexcept
{
    return MpMass().setT( nreal( double( t ) ) );
}

#endif // MPMASS_H

