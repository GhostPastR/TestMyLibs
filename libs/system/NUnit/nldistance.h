#ifndef NLDISTANCE_H
#define NLDISTANCE_H

#include "nlimit.h"
#include "ndistance.h"

class NLDistance : public NLimit<NDistance>, public NDistance
{
public:
    NLDistance() noexcept;
    NLDistance( const NDistance &min, const NDistance &max,
                 const NDistance &value ) noexcept;
    NLDistance( const NLDistance &ldistance );
    NLDistance( NLDistance &&ldistance );
    ~NLDistance();

    /**
     * @brief setM - Задает новое значения для экземпляра класса в метрах и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param m - новое значение в метрах.
     * @return ссылка на экземпляр класса.
     */
    NLDistance &setM( const nreal &m ) noexcept;
    /**
     * @brief setKm - Задает новое значения для экземпляра класса в километрах
     * и осуществляет проверку на вхождения значения в диапазон.
     * @param km - новое значение в километрах.
     * @return ссылка на экземпляр класса.
     */
    NLDistance &setKm( const nreal &km ) noexcept;
    /**
     * @brief setFt - Задает новое значения для экземпляра класса в футах и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param ft - новое значение в футах.
     * @return ссылка на экземпляр класса.
     */
    NLDistance &setFt( const nreal &ft ) noexcept;
    /**
     * @brief setYard - Задает новое значения для экземпляра класса в ярдах и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param yard - новое значение в ярдах.
     * @return ссылка на экземпляр класса.
     */
    NLDistance &setYard( const nreal &yard ) noexcept;
    /**
     * @brief setMp - Задает новое значения для экземпляра класса в милях и
     * осуществляет проверку на вхождения значения в диапазон.
     * @param mp - новое значение в милях.
     * @return ссылка на экземпляр класса.
     */
    NLDistance &setMp( const nreal &mp ) noexcept;
    /**
     * @brief setNp - Задает новое значения для экземпляра класса в морских
     * милях и осуществляет проверку на вхождения значения в диапазон.
     * @param np - новое значение в морских милях.
     * @return ссылка на экземпляр класса.
     */
    NLDistance &setNp( const nreal &np ) noexcept;

    NLDistance &operator=( const NLDistance &ldistance );
    NLDistance &operator=( NLDistance &&ldistance );
};

inline NLDistance::NLDistance() noexcept
    : NLimit<NDistance>( NDistance(), NDistance() ), NDistance()
{

}

inline NLDistance::NLDistance( const NDistance &min, const NDistance &max,
                                 const NDistance &value ) noexcept
    : NLimit<NDistance>( min, max ), NDistance(value)
{

}

inline NLDistance::NLDistance( const NLDistance &ldistance )
    : NLimit<NDistance>( ldistance ), NDistance ( ldistance )
{

}

inline NLDistance::NLDistance( NLDistance &&ldistance )
    : NLimit<NDistance>( std::move( ldistance ) ),
      NDistance ( std::move( ldistance ) )
{

}

inline NLDistance::~NLDistance()
{

}

inline NLDistance &NLDistance::setM( const nreal &m ) noexcept
{
    NDistance::setM( m );
    NLDistance::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLDistance &NLDistance::setKm( const nreal &km ) noexcept
{
    NDistance::setKm( km );
    NLDistance::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLDistance &NLDistance::setFt( const nreal &ft ) noexcept
{
    NDistance::setFt( ft );
    NLDistance::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLDistance &NLDistance::setYard( const nreal &yard ) noexcept
{
    NDistance::setYard( yard );
    NLDistance::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLDistance &NLDistance::setMp( const nreal &mp ) noexcept
{
    NDistance::setMp( mp );
    NLDistance::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLDistance &NLDistance::setNp( const nreal &np ) noexcept
{
    NDistance::setNp( np );
    NLDistance::checkValue( this->min(), this->max(), *this );
    return *this;
}

inline NLDistance &NLDistance::operator=( const NLDistance &ldistance )
{
    NLimit::operator=( ldistance );
    NDistance::operator=( ldistance );
    return *this;
}

inline NLDistance &NLDistance::operator=( NLDistance &&ldistance )
{
    NLimit::operator=( std::move( ldistance ) );
    NDistance::operator=( std::move( ldistance ) );
    return *this;
}

#endif // NLDISTANCE_H
