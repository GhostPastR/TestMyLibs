#ifndef MPLSPEED_H
#define MPLSPEED_H

#include "mplimit.h"
#include "mpspeed.h"

class MpLSpeed : public MpLimit<MpSpeed>, public MpSpeed
{
public:
    MpLSpeed() noexcept;
    MpLSpeed( const MpSpeed &min, const MpSpeed &max,
              const MpSpeed &value ) noexcept;
    MpLSpeed( const MpLSpeed &lSpeed );
    MpLSpeed( MpLSpeed &&lSpeed );
    ~MpLSpeed();

    /**
     * @brief setMs - Задает новое значения для экземпляра класса в м/с и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param ms - новое значение в м/c.
     * @return ссылка на экземпляр класса.
     */
    MpLSpeed &setMs( const nreal &ms ) noexcept;
    /**
     * @brief setMm - Задает новое значения для экземпляра класса в м/мин и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param mm - новое значение в м/мин.
     * @return ссылка на экземпляр класса.
     */
    MpLSpeed &setMm( const nreal &mm ) noexcept;
    /**
     * @brief setMh - Задает новое значения для экземпляра класса в м/ч и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param mh - новое значение в м/ч.
     * @return ссылка на экземпляр класса.
     */
    MpLSpeed &setMh( const nreal &mh ) noexcept;

    /**
     * @brief setKms - Задает новое значения для экземпляра класса в км/с и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param kms - новое значение в км/с.
     * @return ссылка на экземпляр класса.
     */
    MpLSpeed &setKms( const nreal &kms ) noexcept;
    /**
     * @brief setKmm - Задает новое значения для экземпляра класса в км/мин и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param kmm - новое значение в км/мин.
     * @return ссылка на экземпляр класса.
     */
    MpLSpeed &setKmm( const nreal &kmm ) noexcept;
    /**
     * @brief setKmh - Задает новое значения для экземпляра класса в км/ч и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param kmh - новое значение в км/ч.
     * @return ссылка на экземпляр класса.
     */
    MpLSpeed &setKmh( const nreal &kmh ) noexcept;

    /**
     * @brief setFts - Задает новое значения для экземпляра класса в фут/c и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param fs - новое значение в фут/c.
     * @return ссылка на экземпляр класса.
     */
    MpLSpeed &setFts( const nreal &fs ) noexcept;
    /**
     * @brief setFtm - Задает новое значения для экземпляра класса в фут/мин и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param fm - новое значение в фут/мин.
     * @return ссылка на экземпляр класса.
     */
    MpLSpeed &setFtm( const nreal &fm ) noexcept;
    /**
     * @brief setFth - Задает новое значения для экземпляра класса в фут/ч и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param fh - новое значение в фут/ч.
     * @return ссылка на экземпляр класса.
     */
    MpLSpeed &setFth( const nreal &fh ) noexcept;

    /**
     * @brief setKt - Задает новое значения для экземпляра класса в узлах и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param kt - новое значение в узлах.
     * @return ссылка на экземпляр класса.
     */
    MpLSpeed &setKt( const nreal &kt ) noexcept;

    /**
     * @brief setMps - Задает новое значения для экземпляра класса в миль/с.
     * @param mps - новое значение в миль/с.
     * @return ссылка на экземпляр класса.
     */
    MpLSpeed &setMps( const nreal &mps ) noexcept;
    /**
     * @brief setMpm - Задает новое значения для экземпляра класса в миль/мин и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param mpm - новое значение в миль/мин.
     * @return ссылка на экземпляр класса.
     */
    MpLSpeed &setMpm( const nreal &mpm ) noexcept;
    /**
     * @brief setMph - Задает новое значения для экземпляра класса в миль/ч и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param mph - новое значение в миль/ч.
     * @return ссылка на экземпляр класса.
     */
    MpLSpeed &setMph( const nreal &mph ) noexcept;

    MpLSpeed &operator=( const MpLSpeed &lSpeed );
    MpLSpeed &operator=( MpLSpeed &&lSpeed );
};

inline MpLSpeed::MpLSpeed() noexcept
    : MpLimit<MpSpeed>( MpSpeed(), MpSpeed() ), MpSpeed()
{

}

inline MpLSpeed::MpLSpeed( const MpSpeed &min, const MpSpeed &max,
                           const MpSpeed &value ) noexcept
    : MpLimit<MpSpeed>( min, max ), MpSpeed(value)
{

}

inline MpLSpeed::MpLSpeed( const MpLSpeed &lSpeed )
    : MpLimit<MpSpeed>(lSpeed), MpSpeed (lSpeed)
{

}

inline MpLSpeed::MpLSpeed( MpLSpeed &&lSpeed )
    : MpLimit<MpSpeed>(lSpeed), MpSpeed (lSpeed)
{

}

inline MpLSpeed::~MpLSpeed()
{

}

inline MpLSpeed &MpLSpeed::setMs( const nreal &ms ) noexcept
{
    MpSpeed::setMs( ms );
    MpLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLSpeed &MpLSpeed::setMm( const nreal &mm ) noexcept
{
    MpSpeed::setMs( mm );
    MpLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLSpeed &MpLSpeed::setMh( const nreal &mh ) noexcept
{
    MpSpeed::setMs( mh );
    MpLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLSpeed &MpLSpeed::setKms( const nreal &kms ) noexcept
{
    MpSpeed::setMs( kms );
    MpLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLSpeed &MpLSpeed::setKmm( const nreal &kmm ) noexcept
{
    MpSpeed::setMs( kmm );
    MpLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLSpeed &MpLSpeed::setKmh( const nreal &kmh ) noexcept
{
    MpSpeed::setMs( kmh );
    MpLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLSpeed &MpLSpeed::setFts( const nreal &fs ) noexcept
{
    MpSpeed::setMs( fs );
    MpLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLSpeed &MpLSpeed::setFtm( const nreal &fm ) noexcept
{
    MpSpeed::setMs( fm );
    MpLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLSpeed &MpLSpeed::setFth( const nreal &fh ) noexcept
{
    MpSpeed::setMs( fh );
    MpLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLSpeed &MpLSpeed::setKt( const nreal &kt ) noexcept
{
    MpSpeed::setMs( kt );
    MpLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLSpeed &MpLSpeed::setMps( const nreal &mps ) noexcept
{
    MpSpeed::setMs( mps );
    MpLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLSpeed &MpLSpeed::setMpm( const nreal &mpm ) noexcept
{
    MpSpeed::setMs( mpm );
    MpLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLSpeed &MpLSpeed::setMph( const nreal &mph ) noexcept
{
    MpSpeed::setMs( mph );
    MpLSpeed::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLSpeed &MpLSpeed::operator=( const MpLSpeed &lSpeed )
{
    MpLimit::operator=( lSpeed );
    MpSpeed::operator=( lSpeed );
    return *this;
}

inline MpLSpeed &MpLSpeed::operator=( MpLSpeed &&lSpeed )
{
    MpLimit::operator=( std::move( lSpeed ) );
    MpSpeed::operator=( std::move( lSpeed ) );
    return *this;
}

#endif // MPLSPEED_H
