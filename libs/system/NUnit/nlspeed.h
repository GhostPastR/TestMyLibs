#ifndef NLSPEED_H
#define NLSPEED_H

#include "nlimit.h"
#include "nspeed.h"

class NLSpeed : public NLimit<NSpeed>, public NSpeed
{
public:
    NLSpeed() noexcept;
    NLSpeed( const NSpeed &min, const NSpeed &max,
              const NSpeed &value ) noexcept;
    NLSpeed( const NLSpeed &lSpeed );
    NLSpeed( NLSpeed &&lSpeed );
    ~NLSpeed();

    /**
     * @brief setMs - Задает новое значения для экземпляра класса в м/с и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param ms - новое значение в м/c.
     * @return ссылка на экземпляр класса.
     */
    NLSpeed &setMs( const nreal &ms ) noexcept;
    /**
     * @brief setMm - Задает новое значения для экземпляра класса в м/мин и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param mm - новое значение в м/мин.
     * @return ссылка на экземпляр класса.
     */
    NLSpeed &setMm( const nreal &mm ) noexcept;
    /**
     * @brief setMh - Задает новое значения для экземпляра класса в м/ч и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param mh - новое значение в м/ч.
     * @return ссылка на экземпляр класса.
     */
    NLSpeed &setMh( const nreal &mh ) noexcept;

    /**
     * @brief setKms - Задает новое значения для экземпляра класса в км/с и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param kms - новое значение в км/с.
     * @return ссылка на экземпляр класса.
     */
    NLSpeed &setKms( const nreal &kms ) noexcept;
    /**
     * @brief setKmm - Задает новое значения для экземпляра класса в км/мин и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param kmm - новое значение в км/мин.
     * @return ссылка на экземпляр класса.
     */
    NLSpeed &setKmm( const nreal &kmm ) noexcept;
    /**
     * @brief setKmh - Задает новое значения для экземпляра класса в км/ч и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param kmh - новое значение в км/ч.
     * @return ссылка на экземпляр класса.
     */
    NLSpeed &setKmh( const nreal &kmh ) noexcept;

    /**
     * @brief setFts - Задает новое значения для экземпляра класса в фут/c и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param fs - новое значение в фут/c.
     * @return ссылка на экземпляр класса.
     */
    NLSpeed &setFts( const nreal &fs ) noexcept;
    /**
     * @brief setFtm - Задает новое значения для экземпляра класса в фут/мин и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param fm - новое значение в фут/мин.
     * @return ссылка на экземпляр класса.
     */
    NLSpeed &setFtm( const nreal &fm ) noexcept;
    /**
     * @brief setFth - Задает новое значения для экземпляра класса в фут/ч и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param fh - новое значение в фут/ч.
     * @return ссылка на экземпляр класса.
     */
    NLSpeed &setFth( const nreal &fh ) noexcept;

    /**
     * @brief setKt - Задает новое значения для экземпляра класса в узлах и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param kt - новое значение в узлах.
     * @return ссылка на экземпляр класса.
     */
    NLSpeed &setKt( const nreal &kt ) noexcept;

    /**
     * @brief setMps - Задает новое значения для экземпляра класса в миль/с.
     * @param mps - новое значение в миль/с.
     * @return ссылка на экземпляр класса.
     */
    NLSpeed &setMps( const nreal &mps ) noexcept;
    /**
     * @brief setMpm - Задает новое значения для экземпляра класса в миль/мин и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param mpm - новое значение в миль/мин.
     * @return ссылка на экземпляр класса.
     */
    NLSpeed &setMpm( const nreal &mpm ) noexcept;
    /**
     * @brief setMph - Задает новое значения для экземпляра класса в миль/ч и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param mph - новое значение в миль/ч.
     * @return ссылка на экземпляр класса.
     */
    NLSpeed &setMph( const nreal &mph ) noexcept;

    NLSpeed &operator=( const NLSpeed &lSpeed );
    NLSpeed &operator=( NLSpeed &&lSpeed );
};

inline NLSpeed::NLSpeed() noexcept
    : NLimit<NSpeed>( NSpeed(), NSpeed() ), NSpeed()
{

}

inline NLSpeed::NLSpeed( const NSpeed &min, const NSpeed &max,
                           const NSpeed &value ) noexcept
    : NLimit<NSpeed>( min, max ), NSpeed(value)
{

}

inline NLSpeed::NLSpeed( const NLSpeed &lSpeed )
    : NLimit<NSpeed>(lSpeed), NSpeed (lSpeed)
{

}

inline NLSpeed::NLSpeed( NLSpeed &&lSpeed )
    : NLimit<NSpeed>(lSpeed), NSpeed (lSpeed)
{

}

inline NLSpeed::~NLSpeed()
{

}

inline NLSpeed &NLSpeed::setMs( const nreal &ms ) noexcept
{
    NSpeed::setMs( ms );
    NLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLSpeed &NLSpeed::setMm( const nreal &mm ) noexcept
{
    NSpeed::setMs( mm );
    NLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLSpeed &NLSpeed::setMh( const nreal &mh ) noexcept
{
    NSpeed::setMs( mh );
    NLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLSpeed &NLSpeed::setKms( const nreal &kms ) noexcept
{
    NSpeed::setMs( kms );
    NLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLSpeed &NLSpeed::setKmm( const nreal &kmm ) noexcept
{
    NSpeed::setMs( kmm );
    NLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLSpeed &NLSpeed::setKmh( const nreal &kmh ) noexcept
{
    NSpeed::setMs( kmh );
    NLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLSpeed &NLSpeed::setFts( const nreal &fs ) noexcept
{
    NSpeed::setMs( fs );
    NLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLSpeed &NLSpeed::setFtm( const nreal &fm ) noexcept
{
    NSpeed::setMs( fm );
    NLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLSpeed &NLSpeed::setFth( const nreal &fh ) noexcept
{
    NSpeed::setMs( fh );
    NLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLSpeed &NLSpeed::setKt( const nreal &kt ) noexcept
{
    NSpeed::setMs( kt );
    NLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLSpeed &NLSpeed::setMps( const nreal &mps ) noexcept
{
    NSpeed::setMs( mps );
    NLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLSpeed &NLSpeed::setMpm( const nreal &mpm ) noexcept
{
    NSpeed::setMs( mpm );
    NLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLSpeed &NLSpeed::setMph( const nreal &mph ) noexcept
{
    NSpeed::setMs( mph );
    NLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLSpeed &NLSpeed::operator=( const NLSpeed &lSpeed )
{
    NLimit::operator=( lSpeed );
    NSpeed::operator=( lSpeed );
    return *this;
}

inline NLSpeed &NLSpeed::operator=( NLSpeed &&lSpeed )
{
    NLimit::operator=( std::move( lSpeed ) );
    NSpeed::operator=( std::move( lSpeed ) );
    return *this;
}

#endif // NLSPEED_H
