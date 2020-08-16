#ifndef MPSPEED_H
#define MPSPEED_H

#include <ntype.h>

class MpDistance;
class MpTime;
/**
 * @brief The MpSpeed class - Класс предназначен для работы с величинами
 * характеризующие скорость.
 */
class MpSpeed
{
public:
    /**
     * @brief speed - Возвращает новое значения для экземпляра через дистанцию и время.
     * @param distance - новое значение расстояния, time - новое значение времени.
     * @return экземпляр класса.
     */
    static MpSpeed speed( const MpDistance &distance, const MpTime &time )
                                                                       noexcept;

    MpSpeed() noexcept;
    MpSpeed( const nreal &ms ) noexcept;
    MpSpeed( const MpSpeed &speed );
    MpSpeed( MpSpeed &&speed );

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
    MpSpeed &setMs( const nreal &ms ) noexcept;
    /**
     * @brief setMm - Задает новое значения для экземпляра класса в м/мин.
     * @param mm - новое значение в м/мин.
     * @return ссылка на экземпляр класса.
     */
    MpSpeed &setMm( const nreal &mm ) noexcept;
    /**
     * @brief setMh - Задает новое значения для экземпляра класса в м/ч.
     * @param mh - новое значение в м/ч.
     * @return ссылка на экземпляр класса.
     */
    MpSpeed &setMh( const nreal &mh ) noexcept;

    /**
     * @brief setKms - Задает новое значения для экземпляра класса в км/с.
     * @param kms - новое значение в км/с.
     * @return ссылка на экземпляр класса.
     */
    MpSpeed &setKms( const nreal &kms ) noexcept;
    /**
     * @brief setKmm - Задает новое значения для экземпляра класса в км/мин.
     * @param kmm - новое значение в км/мин.
     * @return ссылка на экземпляр класса.
     */
    MpSpeed &setKmm( const nreal &kmm ) noexcept;
    /**
     * @brief setKmh - Задает новое значения для экземпляра класса в км/ч.
     * @param kmh - новое значение в км/ч.
     * @return ссылка на экземпляр класса.
     */
    MpSpeed &setKmh( const nreal &kmh ) noexcept;

    /**
     * @brief setFts - Задает новое значения для экземпляра класса в фут/c.
     * @param fs - новое значение в фут/c.
     * @return ссылка на экземпляр класса.
     */
    MpSpeed &setFts( const nreal &fs ) noexcept;
    /**
     * @brief setFtm - Задает новое значения для экземпляра класса в фут/мин.
     * @param fm - новое значение в фут/мин.
     * @return ссылка на экземпляр класса.
     */
    MpSpeed &setFtm( const nreal &fm ) noexcept;
    /**
     * @brief setFth - Задает новое значения для экземпляра класса в фут/ч.
     * @param fh - новое значение в фут/ч.
     * @return ссылка на экземпляр класса.
     */
    MpSpeed &setFth( const nreal &fh ) noexcept;

    /**
     * @brief setKt - Задает новое значения для экземпляра класса в узлах.
     * @param kt - новое значение в узлах.
     * @return ссылка на экземпляр класса.
     */
    MpSpeed &setKt( const nreal &kt ) noexcept;

    /**
     * @brief setMps - Задает новое значения для экземпляра класса в миль/с.
     * @param mps - новое значение в миль/с.
     * @return ссылка на экземпляр класса.
     */
    MpSpeed &setMps( const nreal &mps ) noexcept;
    /**
     * @brief setMpm - Задает новое значения для экземпляра класса в миль/мин.
     * @param mpm - новое значение в миль/мин.
     * @return ссылка на экземпляр класса.
     */
    MpSpeed &setMpm( const nreal &mpm ) noexcept;
    /**
     * @brief setMph - Задает новое значения для экземпляра класса в миль/ч.
     * @param mph - новое значение в миль/ч.
     * @return ссылка на экземпляр класса.
     */
    MpSpeed &setMph( const nreal &mph ) noexcept;

    /**
     * @brief setSpeed - Задает новое значения для экземпляра через дистанцию и
     * время.
     * @param distance - новое значение расстояния, time - новое значение
     * времени.
     * @return экземпляр класса.
     */
    MpSpeed &setSpeed( const MpDistance &distance, const MpTime &time )
                                                                       noexcept;

    MpSpeed &operator=( const MpSpeed &speed );
    MpSpeed &operator=( MpSpeed &&speed );

    bool operator ==( const MpSpeed &value ) const noexcept;
    bool operator !=( const MpSpeed &value ) const noexcept;
    bool operator >=( const MpSpeed &value ) const noexcept;
    bool operator <=( const MpSpeed &value ) const noexcept;
    bool operator >( const MpSpeed &value ) const noexcept;
    bool operator <( const MpSpeed &value ) const noexcept;

    friend MpSpeed operator "" _ms( long double ms ) noexcept;
    friend MpSpeed operator "" _mm( long double mm ) noexcept;
    friend MpSpeed operator "" _mh( long double mh ) noexcept;
    friend MpSpeed operator "" _kms( long double kms ) noexcept;
    friend MpSpeed operator "" _kmm( long double kmm ) noexcept;
    friend MpSpeed operator "" _kmh( long double kmh ) noexcept;
    friend MpSpeed operator "" _fts( long double fts ) noexcept;
    friend MpSpeed operator "" _ftm( long double ftm ) noexcept;
    friend MpSpeed operator "" _fth( long double fth ) noexcept;
    friend MpSpeed operator "" _kt( long double kt ) noexcept;
    friend MpSpeed operator "" _mps( long double mps ) noexcept;
    friend MpSpeed operator "" _mpm( long double mpm ) noexcept;
    friend MpSpeed operator "" _mph( long double mph ) noexcept;
private:
    nreal value_;
};

inline MpSpeed::MpSpeed() noexcept
{

}

inline MpSpeed::MpSpeed( const nreal &ms ) noexcept
{
    this->value_ = ms;
}

inline MpSpeed::MpSpeed( const MpSpeed &speed )
{
    this->value_ = speed.value_;
}

inline MpSpeed::MpSpeed( MpSpeed &&speed )
{
    this->value_ = std::move( speed.value_ );
}

inline nreal MpSpeed::ms() const noexcept
{
    return this->value_;
}

inline nreal MpSpeed::mm() const noexcept
{
    return this->value_ * nreal( 60.0 );
}

inline nreal MpSpeed::mh() const noexcept
{
    return this->value_ * nreal( 3600.0 );
}

inline nreal MpSpeed::kms() const noexcept
{
    return this->value_ * nreal( 0.001 );
}

inline nreal MpSpeed::kmm() const noexcept
{
    return this->value_ * nreal( 0.06 );
}

inline nreal MpSpeed::kmh() const noexcept
{
    return this->value_ * nreal( 3.6 );
}

inline nreal MpSpeed::fts() const noexcept
{
    return this->value_ * nreal( 3.28084 );
}

inline nreal MpSpeed::ftm() const noexcept
{
    return this->value_ * nreal( 196.8504 );
}

inline nreal MpSpeed::fth() const noexcept
{
    return this->value_ * nreal( 11811.024 );
}

inline nreal MpSpeed::kt() const noexcept
{
    return this->value_ * nreal( 1.9438445 );
}

inline nreal MpSpeed::mps() const noexcept
{
    return this->value_ * nreal( 0.000621 );
}

inline nreal MpSpeed::mpm() const noexcept
{
    return this->value_ * nreal( 0.037282 );
}

inline nreal MpSpeed::mph() const noexcept
{
    return this->value_ * nreal( 2.236936 );
}

inline MpSpeed &MpSpeed::setMs( const nreal &ms ) noexcept
{
    this->value_ = ms;
    return *this;
}

inline MpSpeed &MpSpeed::setMm( const nreal &mm ) noexcept
{
    this->value_ = mm / nreal( 60.0 );
    return *this;
}

inline MpSpeed &MpSpeed::setMh( const nreal &mh ) noexcept
{
    this->value_ = mh / nreal( 3600.0 );
    return *this;
}

inline MpSpeed &MpSpeed::setKms( const nreal &kms ) noexcept
{
    this->value_ = kms / nreal( 0.001 );
    return *this;
}

inline MpSpeed &MpSpeed::setKmm( const nreal &kmm ) noexcept
{
    this->value_ = kmm / nreal( 0.06 );
    return *this;
}

inline MpSpeed &MpSpeed::setKmh( const nreal &kmh ) noexcept
{
    this->value_ = kmh / nreal( 3.6 );
    return *this;
}

inline MpSpeed &MpSpeed::setFts( const nreal &fps ) noexcept
{
    this->value_ = fps / nreal( 3.28084 );
    return *this;
}

inline MpSpeed &MpSpeed::setFtm( const nreal &fpm ) noexcept
{
    this->value_ = fpm / nreal( 196.8504 );
    return *this;
}

inline MpSpeed &MpSpeed::setFth( const nreal &fph ) noexcept
{
    this->value_ = fph / nreal( 11811.024 );
    return *this;
}

inline MpSpeed &MpSpeed::setKt( const nreal &kt ) noexcept
{
    this->value_ = kt / nreal( 1.9438445 );
    return *this;
}

inline MpSpeed &MpSpeed::setMps( const nreal &mps ) noexcept
{
    this->value_ = mps / nreal( 0.000621 );
    return *this;
}

inline MpSpeed &MpSpeed::setMpm( const nreal &mpm ) noexcept
{
    this->value_ = mpm / nreal( 0.037282 );
    return *this;
}

inline MpSpeed &MpSpeed::setMph( const nreal &mph ) noexcept
{
    this->value_ = mph / nreal( 2.236936 );
    return *this;
}

inline MpSpeed &MpSpeed::operator=( const MpSpeed &speed )
{
    this->value_ = speed.value_;
    return *this;
}

inline MpSpeed &MpSpeed::operator=( MpSpeed &&speed )
{
    this->value_ = std::move( speed.value_ );
    return *this;
}

inline bool MpSpeed::operator ==( const MpSpeed &value ) const noexcept
{
    return this->value_.compare( value.value_ );
}

inline bool MpSpeed::operator !=( const MpSpeed &value ) const noexcept
{
    return this->value_.unequal( value.value_ );
}

inline bool MpSpeed::operator >=( const MpSpeed &value ) const noexcept
{
    return this->value_.moreThan( value.value_ );
}

inline bool MpSpeed::operator <=( const MpSpeed &value ) const noexcept
{
    return this->value_.feverThan( value.value_ );
}

inline bool MpSpeed::operator >( const MpSpeed &value ) const noexcept
{
    return ( this->value_ > value.value_ );
}

inline bool MpSpeed::operator <( const MpSpeed &value ) const noexcept
{
    return ( this->value_ < value.value_ );
}

inline MpSpeed operator "" _ms( long double ms ) noexcept
{
    return MpSpeed( nreal( double( ms ) ) );
}

inline MpSpeed operator "" _mm( long double mm ) noexcept
{
    return MpSpeed().setMm( nreal( double( mm ) ) );
}

inline MpSpeed operator "" _mh( long double mh ) noexcept
{
    return MpSpeed().setMh( nreal( double( mh ) ) );
}

inline MpSpeed operator "" _kms( long double kms ) noexcept
{
    return MpSpeed().setKms( nreal( double( kms ) ) );
}

inline MpSpeed operator "" _kmm( long double kmm ) noexcept
{
    return MpSpeed().setKmm( nreal( double( kmm ) ) );
}

inline MpSpeed operator "" _kmh( long double kmh ) noexcept
{
    return MpSpeed().setKmh( nreal( double( kmh ) ) );
}

inline MpSpeed operator "" _fts( long double fts ) noexcept
{
    return MpSpeed().setFts( nreal( double( fts ) ) );
}

inline MpSpeed operator "" _ftm( long double ftm ) noexcept
{
    return MpSpeed().setFtm( nreal( double( ftm ) ) );
}

inline MpSpeed operator "" _fth( long double fth ) noexcept
{
    return MpSpeed().setFth( nreal( double( fth ) ) );
}

inline MpSpeed operator "" _kt( long double kt ) noexcept
{
    return MpSpeed().setKt( nreal( double( kt ) ) );
}

inline MpSpeed operator "" _mps( long double mps ) noexcept
{
    return MpSpeed().setMps( nreal( double( mps ) ) );
}

inline MpSpeed operator "" _mpm( long double mpm ) noexcept
{
    return MpSpeed().setMpm( nreal( double( mpm ) ) );
}

inline MpSpeed operator "" _mph( long double mph ) noexcept
{
    return MpSpeed().setMph( nreal( double( mph ) ) );
}


#endif // MPSPEED_H
