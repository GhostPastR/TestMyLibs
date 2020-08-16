#ifndef MPDISTANCE_H
#define MPDISTANCE_H

#include <ntype.h>

class MpSpeed;
class MpTime;

/**
 * @brief The MpDistance class - Класс предназначен для работы с величинами
 * характеризующие расстояние.
 */
class MpDistance
{
public:
    /**
     * @brief distance - Возвращает новое значения для экземпляра класса через скорость и время.
     * @param speed - новое значение скорости, time - новое значение времени.
     * @return экземпляр класса.
     */
    static MpDistance distance( const MpSpeed &speed, const MpTime &time)
                                                                       noexcept;

    MpDistance() noexcept;
    MpDistance( const nreal &m ) noexcept;
    MpDistance( const MpDistance &distance );
    MpDistance( MpDistance &&distance );

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
    MpDistance &setM( const nreal &m ) noexcept;
    /**
     * @brief setKm - Задает новое значения для экземпляра класса в километрах.
     * @param km - новое значение в километрах.
     * @return ссылка на экземпляр класса.
     */
    MpDistance &setKm( const nreal &km ) noexcept;
    /**
     * @brief setFt - Задает новое значения для экземпляра класса в футах.
     * @param ft - новое значение в футах.
     * @return ссылка на экземпляр класса.
     */
    MpDistance &setFt( const nreal &ft ) noexcept;
    /**
     * @brief setYard - Задает новое значения для экземпляра класса в ярдах.
     * @param yard - новое значение в ярдах.
     * @return ссылка на экземпляр класса.
     */
    MpDistance &setYard( const nreal &yard ) noexcept;
    /**
     * @brief setMp - Задает новое значения для экземпляра класса в милях.
     * @param mp - новое значение в милях.
     * @return ссылка на экземпляр класса.
     */
    MpDistance &setMp( const nreal &mp ) noexcept;
    /**
     * @brief setNp - Задает новое значения для экземпляра класса в морских
     * милях.
     * @param np - новое значение в морских милях.
     * @return ссылка на экземпляр класса.
     */
    MpDistance &setNp( const nreal &np ) noexcept;

    /**
     * @brief setDistance - Задает новое значения для экземпляра класса через
     * скорость и время.
     * @param speed - новое значение скорости, time - новое значение времени.
     * @return ссылка на экземпляр класса.
     */
    MpDistance &setDistance( const MpSpeed &speed, const MpTime &time )
                                                                       noexcept;

    MpDistance &operator=( const MpDistance &distance );
    MpDistance &operator=( MpDistance &&distance );

    bool operator ==( const MpDistance &value ) const noexcept;
    bool operator !=( const MpDistance &value ) const noexcept;
    bool operator >=( const MpDistance &value ) const noexcept;
    bool operator <=( const MpDistance &value ) const noexcept;
    bool operator >( const MpDistance &value ) const noexcept;
    bool operator <( const MpDistance &value ) const noexcept;

    MpDistance &operator +=( const MpDistance &value ) noexcept;
    MpDistance &operator -=( const MpDistance &value ) noexcept;
    MpDistance operator +( const MpDistance &value ) const noexcept;
    MpDistance operator -( const MpDistance &value ) const noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса
     * на 1.
     * @return экземпляр класса с новым значением.
     */
    MpDistance &operator++() noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса на
     * 1 и возвращающие старое значение.
     * @return  экземпляр класса со старым значением.
     */
    MpDistance operator++(int) noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1.
     * @return экземпляр класса с новым значением.
     */
    MpDistance &operator--() noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1
     * и возвращающие старое значение.
     * @return экземпляр класса со старыи значением.
     */
    MpDistance operator--(int) noexcept;

    friend MpDistance operator "" _m( long double m ) noexcept;
    friend MpDistance operator "" _km( long double km ) noexcept;
    friend MpDistance operator "" _ft( long double ft ) noexcept;
    friend MpDistance operator "" _yard( long double yard ) noexcept;
    friend MpDistance operator "" _mp( long double mp ) noexcept;
    friend MpDistance operator "" _np( long double np ) noexcept;

private:
    nreal value_;
};

inline MpDistance::MpDistance() noexcept
{

}

inline MpDistance::MpDistance( const nreal &m ) noexcept
{
    this->value_ = m;
}

inline MpDistance::MpDistance( const MpDistance &distance )
{
    this->value_ = distance.value_;
}

inline MpDistance::MpDistance( MpDistance &&distance )
{
    this->value_ = std::move( distance.value_ );
}

inline nreal MpDistance::m() const noexcept
{
    return this->value_;
}

inline nreal MpDistance::km() const noexcept
{
    return this->value_ * nreal( 0.001 );
}

inline nreal MpDistance::ft() const noexcept
{
    return this->value_ * nreal( 3.280839895 );
}

inline nreal MpDistance::yard() const noexcept
{
    return this->value_ * nreal( 1.0936132983 );
}

inline nreal MpDistance::mp() const noexcept
{
    return this->value_ * nreal( 0.00062137 );
}

inline nreal MpDistance::np() const noexcept
{
    return this->value_ * nreal( 0.0005399568 );
}

inline MpDistance &MpDistance::setM( const nreal &m ) noexcept
{
    this->value_ = m;
    return *this;
}

inline MpDistance &MpDistance::setKm( const nreal &km ) noexcept
{
    this->value_ = km * nreal( 1000.0 );
    return *this;
}

inline MpDistance &MpDistance::setFt( const nreal &ft ) noexcept
{
    this->value_ = ft / nreal( 3.280839895 );
    return *this;
}

inline MpDistance &MpDistance::setYard( const nreal &yard ) noexcept
{
    this->value_ = yard / nreal( 1.0936132983 );
    return *this;
}

inline MpDistance &MpDistance::setMp( const nreal &mp ) noexcept
{
    this->value_ = mp / nreal( 0.00062137 );
    return *this;
}

inline MpDistance &MpDistance::setNp( const nreal &np ) noexcept
{
    this->value_ = np / nreal( 0.0005399568 );
    return *this;
}

inline MpDistance &MpDistance::operator=( const MpDistance &distance )
{
    this->value_ = distance.value_;
    return *this;
}

inline MpDistance &MpDistance::operator=( MpDistance &&distance )
{
    this->value_ = std::move( distance.value_ );
    return *this;
}

inline bool MpDistance::operator ==( const MpDistance &value ) const noexcept
{
    return this->value_.compare( value.value_ );
}

inline bool MpDistance::operator !=( const MpDistance &value ) const noexcept
{
    return this->value_.unequal( value.value_ );
}

inline bool MpDistance::operator >=( const MpDistance &value ) const noexcept
{
    return this->value_.moreThan( value.value_ );
}

inline bool MpDistance::operator <=( const MpDistance &value ) const noexcept
{
    return this->value_.feverThan( value.value_ );
}

inline bool MpDistance::operator >( const MpDistance &value ) const noexcept
{
    return ( this->value_ > value.value_ );
}

inline bool MpDistance::operator <( const MpDistance &value ) const noexcept
{
    return ( this->value_ < value.value_ );
}

inline MpDistance &MpDistance::operator += ( const MpDistance &value ) noexcept
{
    this->value_ += value.value_;
    return *this;
}

inline MpDistance &MpDistance::operator -= ( const MpDistance &value ) noexcept
{
    this->value_ -= value.value_;
    return *this;
}

inline MpDistance MpDistance::operator +(
                                        const MpDistance &value ) const noexcept
{
    return MpDistance( this->value_ + value.value_ );
}

inline MpDistance MpDistance::operator -(
                                        const MpDistance &value ) const noexcept
{
    return MpDistance( this->value_ - value.value_ );
}

inline MpDistance &MpDistance::operator++() noexcept
{
        ++this->value_;
    return *this;
}

inline MpDistance MpDistance::operator++(int) noexcept
{
    MpDistance v = this->value_;
        ++(*this);
    return v;
}

inline MpDistance &MpDistance::operator--() noexcept
{
        --this->value_;
    return *this;
}

inline MpDistance MpDistance::operator--(int) noexcept
{
    MpDistance v = *this;
        --(*this);
    return v;
}

inline MpDistance operator "" _m( long double m ) noexcept
{
    return MpDistance( nreal( double( m ) ) );
}

inline MpDistance operator "" _km( long double km ) noexcept
{
    return MpDistance().setKm( nreal( double( km ) ) );
}

inline MpDistance operator "" _ft( long double ft ) noexcept
{
    return MpDistance().setFt( nreal( double( ft ) ) );
}

inline MpDistance operator "" _yard( long double yard ) noexcept
{
    return MpDistance().setYard( nreal( double( yard ) ) );
}

inline MpDistance operator "" _mp( long double mp ) noexcept
{
    return MpDistance().setMp( nreal( double( mp ) ) );
}

inline MpDistance operator "" _np( long double np ) noexcept
{
    return MpDistance().setNp( nreal( double( np ) ) );
}

#endif // MPDISTANCE_H

