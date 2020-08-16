#ifndef MPLDISTANCE_H
#define MPLDISTANCE_H

#include "mplimit.h"
#include "mpdistance.h"

class MpLDistance : public MpLimit<MpDistance>, public MpDistance
{
public:
    MpLDistance() noexcept;
    MpLDistance( const MpDistance &min, const MpDistance &max,
                 const MpDistance &value ) noexcept;
    MpLDistance( const MpLDistance &ldistance );
    MpLDistance( MpLDistance &&ldistance );
    ~MpLDistance();

    /**
     * @brief setM - Задает новое значения для экземпляра класса в метрах и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param m - новое значение в метрах.
     * @return ссылка на экземпляр класса.
     */
    MpLDistance &setM( const nreal &m ) noexcept;
    /**
     * @brief setKm - Задает новое значения для экземпляра класса в километрах
     * и осуществляет проверку на вхождения значения в диапазон.
     * @param km - новое значение в километрах.
     * @return ссылка на экземпляр класса.
     */
    MpLDistance &setKm( const nreal &km ) noexcept;
    /**
     * @brief setFt - Задает новое значения для экземпляра класса в футах и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param ft - новое значение в футах.
     * @return ссылка на экземпляр класса.
     */
    MpLDistance &setFt( const nreal &ft ) noexcept;
    /**
     * @brief setYard - Задает новое значения для экземпляра класса в ярдах и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param yard - новое значение в ярдах.
     * @return ссылка на экземпляр класса.
     */
    MpLDistance &setYard( const nreal &yard ) noexcept;
    /**
     * @brief setMp - Задает новое значения для экземпляра класса в милях и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param mp - новое значение в милях.
     * @return ссылка на экземпляр класса.
     */
    MpLDistance &setMp( const nreal &mp ) noexcept;
    /**
     * @brief setNp - Задает новое значения для экземпляра класса в морских
     * милях и осуществляет проверку на вхождения значения в диапазон.
     * @param np - новое значение в морских милях.
     * @return ссылка на экземпляр класса.
     */
    MpLDistance &setNp( const nreal &np ) noexcept;

    MpLDistance &operator=( const MpLDistance &ldistance );
    MpLDistance &operator=( MpLDistance &&ldistance );
};

inline MpLDistance::MpLDistance() noexcept
    : MpLimit<MpDistance>( MpDistance(), MpDistance() ), MpDistance()
{

}

inline MpLDistance::MpLDistance( const MpDistance &min, const MpDistance &max,
                                 const MpDistance &value ) noexcept
    : MpLimit<MpDistance>( min, max ), MpDistance(value)
{

}

inline MpLDistance::MpLDistance( const MpLDistance &ldistance )
    : MpLimit<MpDistance>( ldistance ), MpDistance ( ldistance )
{

}

inline MpLDistance::MpLDistance( MpLDistance &&ldistance )
    : MpLimit<MpDistance>( std::move( ldistance ) ),
      MpDistance ( std::move( ldistance ) )
{

}

inline MpLDistance::~MpLDistance()
{

}

inline MpLDistance &MpLDistance::setM( const nreal &m ) noexcept
{
    MpDistance::setM( m );
    MpLDistance::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLDistance &MpLDistance::setKm( const nreal &km ) noexcept
{
    MpDistance::setKm( km );
    MpLDistance::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLDistance &MpLDistance::setFt( const nreal &ft ) noexcept
{
    MpDistance::setFt( ft );
    MpLDistance::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLDistance &MpLDistance::setYard( const nreal &yard ) noexcept
{
    MpDistance::setYard( yard );
    MpLDistance::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLDistance &MpLDistance::setMp( const nreal &mp ) noexcept
{
    MpDistance::setMp( mp );
    MpLDistance::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLDistance &MpLDistance::setNp( const nreal &np ) noexcept
{
    MpDistance::setNp( np );
    MpLDistance::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline MpLDistance &MpLDistance::operator=( const MpLDistance &ldistance )
{
    MpLimit::operator=( ldistance );
    MpDistance::operator=( ldistance );
    return *this;
}

inline MpLDistance &MpLDistance::operator=( MpLDistance &&ldistance )
{
    MpLimit::operator=( std::move( ldistance ) );
    MpDistance::operator=( std::move( ldistance ) );
    return *this;
}

#endif // MPLDISTANCE_H
