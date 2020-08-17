#ifndef NDISTANCE_H
#define NDISTANCE_H

#include <ntype.h>

class NSpeed;
class NTime;

/**
 * @brief The NDistance class - Класс предназначен для работы с величинами
 * характеризующие расстояние.
 */
class NDistance
{
public:
    /**
     * @brief distance - Возвращает новое значения для экземпляра класса через
     * скорость и время.
     * @param speed - новое значение скорости, time - новое значение времени.
     * @return экземпляр класса.
     */
    static NDistance distance( const NSpeed &speed, const NTime &time )
                                                                       noexcept;

    NDistance() noexcept;
    NDistance( const nreal &m ) noexcept;
    NDistance( const NDistance &distance );
    NDistance( NDistance &&distance );

    /**
     * @brief m - Возвращает значения экземпляра класса в метрах.
     * @return значение в метрах.
     */
    nreal m() const noexcept;
    /**
     * @brief km - Возвращает значения экземпляра класса в километрах.
     * @return значение в километрах.
     */
    nreal km() const noexcept;
    /**
     * @brief ft - Возвращает значения экземпляра класса в футах.
     * @return значение в футах.
     */
    nreal ft() const noexcept;
    /**
     * @brief yard - Возвращает значения экземпляра класса в ярдах.
     * @return значение в ярдах.
     */
    nreal yard() const noexcept;
    /**
     * @brief mp - Возвращает значения экземпляра класса в милях.
     * @return значение в милях.
     */
    nreal mp() const noexcept;
    /**
     * @brief np - Возвращает значения экземпляра класса в морских милях.
     * @return значение в морских милях.
     */
    nreal np() const noexcept;

    /**
     * @brief setM - Задает новое значения для экземпляра класса в метрах.
     * @param m - новое значение в метрах.
     * @return ссылка на экземпляр класса.
     */
    NDistance &setM( const nreal &m ) noexcept;
    /**
     * @brief setKm - Задает новое значения для экземпляра класса в километрах.
     * @param km - новое значение в километрах.
     * @return ссылка на экземпляр класса.
     */
    NDistance &setKm( const nreal &km ) noexcept;
    /**
     * @brief setFt - Задает новое значения для экземпляра класса в футах.
     * @param ft - новое значение в футах.
     * @return ссылка на экземпляр класса.
     */
    NDistance &setFt( const nreal &ft ) noexcept;
    /**
     * @brief setYard - Задает новое значения для экземпляра класса в ярдах.
     * @param yard - новое значение в ярдах.
     * @return ссылка на экземпляр класса.
     */
    NDistance &setYard( const nreal &yard ) noexcept;
    /**
     * @brief setMp - Задает новое значения для экземпляра класса в милях.
     * @param mp - новое значение в милях.
     * @return ссылка на экземпляр класса.
     */
    NDistance &setMp( const nreal &mp ) noexcept;
    /**
     * @brief setNp - Задает новое значения для экземпляра класса в морских
     * милях.
     * @param np - новое значение в морских милях.
     * @return ссылка на экземпляр класса.
     */
    NDistance &setNp( const nreal &np ) noexcept;

    /**
     * @brief setDistance - Задает новое значения для экземпляра класса через
     * скорость и время.
     * @param speed - новое значение скорости, time - новое значение времени.
     * @return ссылка на экземпляр класса.
     */
    NDistance &setDistance( const NSpeed &speed, const NTime &time ) noexcept;

    NDistance &operator=( const NDistance &distance );
    NDistance &operator=( NDistance &&distance );

    bool operator ==( const NDistance &value ) const noexcept;
    bool operator !=( const NDistance &value ) const noexcept;
    bool operator >=( const NDistance &value ) const noexcept;
    bool operator <=( const NDistance &value ) const noexcept;
    bool operator >( const NDistance &value ) const noexcept;
    bool operator <( const NDistance &value ) const noexcept;

    NDistance &operator +=( const NDistance &value ) noexcept;
    NDistance &operator -=( const NDistance &value ) noexcept;
    NDistance operator +( const NDistance &value ) const noexcept;
    NDistance operator -( const NDistance &value ) const noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса
     * на 1.
     * @return экземпляр класса с новым значением.
     */
    NDistance &operator++() noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса на
     * 1 и возвращающие старое значение.
     * @return  экземпляр класса со старым значением.
     */
    NDistance operator++(int) noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1.
     * @return экземпляр класса с новым значением.
     */
    NDistance &operator--() noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1
     * и возвращающие старое значение.
     * @return экземпляр класса со старыи значением.
     */
    NDistance operator--(int) noexcept;

    friend NDistance operator "" _m( long double m ) noexcept;
    friend NDistance operator "" _km( long double km ) noexcept;
    friend NDistance operator "" _ft( long double ft ) noexcept;
    friend NDistance operator "" _yard( long double yard ) noexcept;
    friend NDistance operator "" _mp( long double mp ) noexcept;
    friend NDistance operator "" _np( long double np ) noexcept;

private:
    nreal value_;
};

inline NDistance::NDistance() noexcept
{

}

inline NDistance::NDistance( const nreal &m ) noexcept
{
    this->value_ = m;
}

inline NDistance::NDistance( const NDistance &distance )
{
    this->value_ = distance.value_;
}

inline NDistance::NDistance( NDistance &&distance )
{
    this->value_ = std::move( distance.value_ );
}

inline nreal NDistance::m() const noexcept
{
    return this->value_;
}

inline nreal NDistance::km() const noexcept
{
    return this->value_ * nreal( 0.001 );
}

inline nreal NDistance::ft() const noexcept
{
    return this->value_ * nreal( 3.280839895 );
}

inline nreal NDistance::yard() const noexcept
{
    return this->value_ * nreal( 1.0936132983 );
}

inline nreal NDistance::mp() const noexcept
{
    return this->value_ * nreal( 0.00062137 );
}

inline nreal NDistance::np() const noexcept
{
    return this->value_ * nreal( 0.0005399568 );
}

inline NDistance &NDistance::setM( const nreal &m ) noexcept
{
    this->value_ = m;
    return *this;
}

inline NDistance &NDistance::setKm( const nreal &km ) noexcept
{
    this->value_ = km * nreal( 1000.0 );
    return *this;
}

inline NDistance &NDistance::setFt( const nreal &ft ) noexcept
{
    this->value_ = ft / nreal( 3.280839895 );
    return *this;
}

inline NDistance &NDistance::setYard( const nreal &yard ) noexcept
{
    this->value_ = yard / nreal( 1.0936132983 );
    return *this;
}

inline NDistance &NDistance::setMp( const nreal &mp ) noexcept
{
    this->value_ = mp / nreal( 0.00062137 );
    return *this;
}

inline NDistance &NDistance::setNp( const nreal &np ) noexcept
{
    this->value_ = np / nreal( 0.0005399568 );
    return *this;
}

inline NDistance &NDistance::operator=( const NDistance &distance )
{
    this->value_ = distance.value_;
    return *this;
}

inline NDistance &NDistance::operator=( NDistance &&distance )
{
    this->value_ = std::move( distance.value_ );
    return *this;
}

inline bool NDistance::operator ==( const NDistance &value ) const noexcept
{
    return this->value_.compare( value.value_ );
}

inline bool NDistance::operator !=( const NDistance &value ) const noexcept
{
    return this->value_.unequal( value.value_ );
}

inline bool NDistance::operator >=( const NDistance &value ) const noexcept
{
    return this->value_.moreThan( value.value_ );
}

inline bool NDistance::operator <=( const NDistance &value ) const noexcept
{
    return this->value_.feverThan( value.value_ );
}

inline bool NDistance::operator >( const NDistance &value ) const noexcept
{
    return ( this->value_ > value.value_ );
}

inline bool NDistance::operator <( const NDistance &value ) const noexcept
{
    return ( this->value_ < value.value_ );
}

inline NDistance &NDistance::operator += ( const NDistance &value ) noexcept
{
    this->value_ += value.value_;
    return *this;
}

inline NDistance &NDistance::operator -= ( const NDistance &value ) noexcept
{
    this->value_ -= value.value_;
    return *this;
}

inline NDistance NDistance::operator +(
                                        const NDistance &value ) const noexcept
{
    return NDistance( this->value_ + value.value_ );
}

inline NDistance NDistance::operator -(
                                        const NDistance &value ) const noexcept
{
    return NDistance( this->value_ - value.value_ );
}

inline NDistance &NDistance::operator++() noexcept
{
        ++this->value_;
    return *this;
}

inline NDistance NDistance::operator++(int) noexcept
{
    NDistance v = this->value_;
        ++(*this);
    return v;
}

inline NDistance &NDistance::operator--() noexcept
{
        --this->value_;
    return *this;
}

inline NDistance NDistance::operator--(int) noexcept
{
    NDistance v = *this;
        --(*this);
    return v;
}

inline NDistance operator "" _m( long double m ) noexcept
{
    return NDistance( nreal( double( m ) ) );
}

inline NDistance operator "" _km( long double km ) noexcept
{
    return NDistance().setKm( nreal( double( km ) ) );
}

inline NDistance operator "" _ft( long double ft ) noexcept
{
    return NDistance().setFt( nreal( double( ft ) ) );
}

inline NDistance operator "" _yard( long double yard ) noexcept
{
    return NDistance().setYard( nreal( double( yard ) ) );
}

inline NDistance operator "" _mp( long double mp ) noexcept
{
    return NDistance().setMp( nreal( double( mp ) ) );
}

inline NDistance operator "" _np( long double np ) noexcept
{
    return NDistance().setNp( nreal( double( np ) ) );
}

#endif // NDISTANCE_H

