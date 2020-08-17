#ifndef NSPEED_H
#define NSPEED_H

#include <ntype.h>

class NDistance;
class NTime;
/**
 * @brief The NSpeed class - Класс предназначен для работы с величинами
 * характеризующие скорость.
 */
class NSpeed
{
public:
    /**
     * @brief speed - Возвращает новое значения для экземпляра через дистанцию и время.
     * @param distance - новое значение расстояния, time - новое значение времени.
     * @return экземпляр класса.
     */
    static NSpeed speed( const NDistance &distance, const NTime &time )
                                                                       noexcept;

    NSpeed() noexcept;
    NSpeed( const nreal &ms ) noexcept;
    NSpeed( const NSpeed &speed );
    NSpeed( NSpeed &&speed );

    /**
     * @brief ms - Возвращает значения экземпляра класса в м/c.
     * @return значение в м/с.
     */
    nreal ms() const noexcept;
    /**
     * @brief mm - Возвращает значения экземпляра класса в м/мин.
     * @return значение в м/м.
     */
    nreal mm() const noexcept;
    /**
     * @brief mh - Возвращает значения экземпляра класса в м/ч.
     * @return значение в м/ч.
     */
    nreal mh() const noexcept;

    /**
     * @brief kms - Возвращает значения экземпляра класса в км/с.
     * @return значение в км/с.
     */
    nreal kms() const noexcept;
    /**
     * @brief kmm - Возвращает значения экземпляра класса в км/м.
     * @return значение в км/м.
     */
    nreal kmm() const noexcept;
    /**
     * @brief kmh - Возвращает значения экземпляра класса в км/ч.
     * @return значение в км/ч.
     */
    nreal kmh() const noexcept;

    /**
     * @brief fts - Возвращает значения экземпляра класса в узлах.
     * @return значение в узлах.
     */
    nreal fts() const noexcept;
    /**
     * @brief ftm - Возвращает значения экземпляра класса в фут/с.
     * @return значение в фут/с.
     */
    nreal ftm() const noexcept;
    /**
     * @brief fth - Возвращает значения экземпляра класса в фут/мин.
     * @return значение в фут/мин.
     */
    nreal fth() const noexcept;

    /**
     * @brief kt - Возвращает значения экземпляра класса в фут/ч.
     * @return значение в фут/ч.
     */
    nreal kt() const noexcept;

    /**
     * @brief mps - Возвращает значения экземпляра класса в миль/с.
     * @return значение в миль/с.
     */
    nreal mps() const noexcept;
    /**
     * @brief mpm - Возвращает значения экземпляра класса в миль/мин.
     * @return значение в миль/мин.
     */
    nreal mpm() const noexcept;
    /**
     * @brief mph - Возвращает значения экземпляра класса в миль/ч.
     * @return значение в миль/ч.
     */
    nreal mph() const noexcept;

    /**
     * @brief setMs - Задает новое значения для экземпляра класса в м/с.
     * @param ms - новое значение в м/c.
     * @return ссылка на экземпляр класса.
     */
    NSpeed &setMs( const nreal &ms ) noexcept;
    /**
     * @brief setMm - Задает новое значения для экземпляра класса в м/мин.
     * @param mm - новое значение в м/мин.
     * @return ссылка на экземпляр класса.
     */
    NSpeed &setMm( const nreal &mm ) noexcept;
    /**
     * @brief setMh - Задает новое значения для экземпляра класса в м/ч.
     * @param mh - новое значение в м/ч.
     * @return ссылка на экземпляр класса.
     */
    NSpeed &setMh( const nreal &mh ) noexcept;

    /**
     * @brief setKms - Задает новое значения для экземпляра класса в км/с.
     * @param kms - новое значение в км/с.
     * @return ссылка на экземпляр класса.
     */
    NSpeed &setKms( const nreal &kms ) noexcept;
    /**
     * @brief setKmm - Задает новое значения для экземпляра класса в км/мин.
     * @param kmm - новое значение в км/мин.
     * @return ссылка на экземпляр класса.
     */
    NSpeed &setKmm( const nreal &kmm ) noexcept;
    /**
     * @brief setKmh - Задает новое значения для экземпляра класса в км/ч.
     * @param kmh - новое значение в км/ч.
     * @return ссылка на экземпляр класса.
     */
    NSpeed &setKmh( const nreal &kmh ) noexcept;

    /**
     * @brief setFts - Задает новое значения для экземпляра класса в фут/c.
     * @param fs - новое значение в фут/c.
     * @return ссылка на экземпляр класса.
     */
    NSpeed &setFts( const nreal &fs ) noexcept;
    /**
     * @brief setFtm - Задает новое значения для экземпляра класса в фут/мин.
     * @param fm - новое значение в фут/мин.
     * @return ссылка на экземпляр класса.
     */
    NSpeed &setFtm( const nreal &fm ) noexcept;
    /**
     * @brief setFth - Задает новое значения для экземпляра класса в фут/ч.
     * @param fh - новое значение в фут/ч.
     * @return ссылка на экземпляр класса.
     */
    NSpeed &setFth( const nreal &fh ) noexcept;

    /**
     * @brief setKt - Задает новое значения для экземпляра класса в узлах.
     * @param kt - новое значение в узлах.
     * @return ссылка на экземпляр класса.
     */
    NSpeed &setKt( const nreal &kt ) noexcept;

    /**
     * @brief setMps - Задает новое значения для экземпляра класса в миль/с.
     * @param mps - новое значение в миль/с.
     * @return ссылка на экземпляр класса.
     */
    NSpeed &setMps( const nreal &mps ) noexcept;
    /**
     * @brief setMpm - Задает новое значения для экземпляра класса в миль/мин.
     * @param mpm - новое значение в миль/мин.
     * @return ссылка на экземпляр класса.
     */
    NSpeed &setMpm( const nreal &mpm ) noexcept;
    /**
     * @brief setMph - Задает новое значения для экземпляра класса в миль/ч.
     * @param mph - новое значение в миль/ч.
     * @return ссылка на экземпляр класса.
     */
    NSpeed &setMph( const nreal &mph ) noexcept;

    /**
     * @brief setSpeed - Задает новое значения для экземпляра через дистанцию и
     * время.
     * @param distance - новое значение расстояния, time - новое значение
     * времени.
     * @return экземпляр класса.
     */
    NSpeed &setSpeed( const NDistance &distance, const NTime &time ) noexcept;

    NSpeed &operator=( const NSpeed &speed );
    NSpeed &operator=( NSpeed &&speed );

    bool operator ==( const NSpeed &value ) const noexcept;
    bool operator !=( const NSpeed &value ) const noexcept;
    bool operator >=( const NSpeed &value ) const noexcept;
    bool operator <=( const NSpeed &value ) const noexcept;
    bool operator >( const NSpeed &value ) const noexcept;
    bool operator <( const NSpeed &value ) const noexcept;

    friend NSpeed operator "" _ms( long double ms ) noexcept;
    friend NSpeed operator "" _mm( long double mm ) noexcept;
    friend NSpeed operator "" _mh( long double mh ) noexcept;
    friend NSpeed operator "" _kms( long double kms ) noexcept;
    friend NSpeed operator "" _kmm( long double kmm ) noexcept;
    friend NSpeed operator "" _kmh( long double kmh ) noexcept;
    friend NSpeed operator "" _fts( long double fts ) noexcept;
    friend NSpeed operator "" _ftm( long double ftm ) noexcept;
    friend NSpeed operator "" _fth( long double fth ) noexcept;
    friend NSpeed operator "" _kt( long double kt ) noexcept;
    friend NSpeed operator "" _mps( long double mps ) noexcept;
    friend NSpeed operator "" _mpm( long double mpm ) noexcept;
    friend NSpeed operator "" _mph( long double mph ) noexcept;
private:
    nreal value_;
};

inline NSpeed::NSpeed() noexcept
{

}

inline NSpeed::NSpeed( const nreal &ms ) noexcept
{
    this->value_ = ms;
}

inline NSpeed::NSpeed( const NSpeed &speed )
{
    this->value_ = speed.value_;
}

inline NSpeed::NSpeed( NSpeed &&speed )
{
    this->value_ = std::move( speed.value_ );
}

inline nreal NSpeed::ms() const noexcept
{
    return this->value_;
}

inline nreal NSpeed::mm() const noexcept
{
    return this->value_ * nreal( 60.0 );
}

inline nreal NSpeed::mh() const noexcept
{
    return this->value_ * nreal( 3600.0 );
}

inline nreal NSpeed::kms() const noexcept
{
    return this->value_ * nreal( 0.001 );
}

inline nreal NSpeed::kmm() const noexcept
{
    return this->value_ * nreal( 0.06 );
}

inline nreal NSpeed::kmh() const noexcept
{
    return this->value_ * nreal( 3.6 );
}

inline nreal NSpeed::fts() const noexcept
{
    return this->value_ * nreal( 3.28084 );
}

inline nreal NSpeed::ftm() const noexcept
{
    return this->value_ * nreal( 196.8504 );
}

inline nreal NSpeed::fth() const noexcept
{
    return this->value_ * nreal( 11811.024 );
}

inline nreal NSpeed::kt() const noexcept
{
    return this->value_ * nreal( 1.9438445 );
}

inline nreal NSpeed::mps() const noexcept
{
    return this->value_ * nreal( 0.000621 );
}

inline nreal NSpeed::mpm() const noexcept
{
    return this->value_ * nreal( 0.037282 );
}

inline nreal NSpeed::mph() const noexcept
{
    return this->value_ * nreal( 2.236936 );
}

inline NSpeed &NSpeed::setMs( const nreal &ms ) noexcept
{
    this->value_ = ms;
    return *this;
}

inline NSpeed &NSpeed::setMm( const nreal &mm ) noexcept
{
    this->value_ = mm / nreal( 60.0 );
    return *this;
}

inline NSpeed &NSpeed::setMh( const nreal &mh ) noexcept
{
    this->value_ = mh / nreal( 3600.0 );
    return *this;
}

inline NSpeed &NSpeed::setKms( const nreal &kms ) noexcept
{
    this->value_ = kms / nreal( 0.001 );
    return *this;
}

inline NSpeed &NSpeed::setKmm( const nreal &kmm ) noexcept
{
    this->value_ = kmm / nreal( 0.06 );
    return *this;
}

inline NSpeed &NSpeed::setKmh( const nreal &kmh ) noexcept
{
    this->value_ = kmh / nreal( 3.6 );
    return *this;
}

inline NSpeed &NSpeed::setFts( const nreal &fps ) noexcept
{
    this->value_ = fps / nreal( 3.28084 );
    return *this;
}

inline NSpeed &NSpeed::setFtm( const nreal &fpm ) noexcept
{
    this->value_ = fpm / nreal( 196.8504 );
    return *this;
}

inline NSpeed &NSpeed::setFth( const nreal &fph ) noexcept
{
    this->value_ = fph / nreal( 11811.024 );
    return *this;
}

inline NSpeed &NSpeed::setKt( const nreal &kt ) noexcept
{
    this->value_ = kt / nreal( 1.9438445 );
    return *this;
}

inline NSpeed &NSpeed::setMps( const nreal &mps ) noexcept
{
    this->value_ = mps / nreal( 0.000621 );
    return *this;
}

inline NSpeed &NSpeed::setMpm( const nreal &mpm ) noexcept
{
    this->value_ = mpm / nreal( 0.037282 );
    return *this;
}

inline NSpeed &NSpeed::setMph( const nreal &mph ) noexcept
{
    this->value_ = mph / nreal( 2.236936 );
    return *this;
}

inline NSpeed &NSpeed::operator=( const NSpeed &speed )
{
    this->value_ = speed.value_;
    return *this;
}

inline NSpeed &NSpeed::operator=( NSpeed &&speed )
{
    this->value_ = std::move( speed.value_ );
    return *this;
}

inline bool NSpeed::operator ==( const NSpeed &value ) const noexcept
{
    return this->value_.compare( value.value_ );
}

inline bool NSpeed::operator !=( const NSpeed &value ) const noexcept
{
    return this->value_.unequal( value.value_ );
}

inline bool NSpeed::operator >=( const NSpeed &value ) const noexcept
{
    return this->value_.moreThan( value.value_ );
}

inline bool NSpeed::operator <=( const NSpeed &value ) const noexcept
{
    return this->value_.feverThan( value.value_ );
}

inline bool NSpeed::operator >( const NSpeed &value ) const noexcept
{
    return ( this->value_ > value.value_ );
}

inline bool NSpeed::operator <( const NSpeed &value ) const noexcept
{
    return ( this->value_ < value.value_ );
}

inline NSpeed operator "" _ms( long double ms ) noexcept
{
    return NSpeed( nreal( double( ms ) ) );
}

inline NSpeed operator "" _mm( long double mm ) noexcept
{
    return NSpeed().setMm( nreal( double( mm ) ) );
}

inline NSpeed operator "" _mh( long double mh ) noexcept
{
    return NSpeed().setMh( nreal( double( mh ) ) );
}

inline NSpeed operator "" _kms( long double kms ) noexcept
{
    return NSpeed().setKms( nreal( double( kms ) ) );
}

inline NSpeed operator "" _kmm( long double kmm ) noexcept
{
    return NSpeed().setKmm( nreal( double( kmm ) ) );
}

inline NSpeed operator "" _kmh( long double kmh ) noexcept
{
    return NSpeed().setKmh( nreal( double( kmh ) ) );
}

inline NSpeed operator "" _fts( long double fts ) noexcept
{
    return NSpeed().setFts( nreal( double( fts ) ) );
}

inline NSpeed operator "" _ftm( long double ftm ) noexcept
{
    return NSpeed().setFtm( nreal( double( ftm ) ) );
}

inline NSpeed operator "" _fth( long double fth ) noexcept
{
    return NSpeed().setFth( nreal( double( fth ) ) );
}

inline NSpeed operator "" _kt( long double kt ) noexcept
{
    return NSpeed().setKt( nreal( double( kt ) ) );
}

inline NSpeed operator "" _mps( long double mps ) noexcept
{
    return NSpeed().setMps( nreal( double( mps ) ) );
}

inline NSpeed operator "" _mpm( long double mpm ) noexcept
{
    return NSpeed().setMpm( nreal( double( mpm ) ) );
}

inline NSpeed operator "" _mph( long double mph ) noexcept
{
    return NSpeed().setMph( nreal( double( mph ) ) );
}

#endif // NSPEED_H
