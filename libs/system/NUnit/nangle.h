#ifndef NANGLE_H
#define NANGLE_H

#include <cmath>
#include <ntype.h>

/**
 * @brief The NAngle class - Класс предназначен для работы с угловыми
 * величинами(радианы и градусы).
 */
class NAngle
{
public:
    /**
     * @brief piOn180 - Статический метод возвращающая значения угла Пи/180.
     * @return Значения угла.
     */
    static NAngle piOn180() noexcept;
    /**
     * @brief piOn2 - Статический метод возвращающая значения угла Пи/2.
     * @return Значения угла.
     */
    static NAngle piOn2() noexcept;
    /**
     * @brief piOn4 - Статический метод возвращающая значения угла Пи/4.
     * @return Значения угла.
     */
    static NAngle piOn4() noexcept;
    /**
     * @brief piOn6 - Статический метод возвращающая значения угла Пи/6.
     * @return Значения угла.
     */
    static NAngle piOn6() noexcept;
    /**
     * @brief pi - Статический метод возвращающая значения угла Пи.
     * @return Значения угла.
     */
    static NAngle pi() noexcept;
    /**
     * @brief piIn3On2 - Статический метод возвращающая значения угла 3*Пи/2.
     * @return Значения угла.
     */
    static NAngle piIn3On2() noexcept;
    /**
     * @brief piIn2 - Статический метод возвращающая значения угла 2*Пи.
     * @return Значения угла.
     */
    static NAngle piIn2() noexcept;

    /**
     * @brief grade - Статический метод для перевода радиан в градусы
     * @param value - значения в радианах
     * @return - значения в градусах
     */
    static nreal grade( const nreal &value );

    /**
     * @brief radian - Статический метод для перевода градусов в радианы
     * @param value - значения в градусах
     * @return - значения в радианах
     */
    static nreal radian( const nreal &value );

    /**
     * @brief gradeMod - Статический метод для перевода радиан в градусы
     * @param value - значения в радианах
     * @return - значения в градусах
     */
    static nreal gradeMod( const nreal &value );

    NAngle( const nreal &value = nreal( 0.0 ), bool radian = true );
    NAngle( const NAngle &angle );
    NAngle( NAngle &&angle );
    virtual ~NAngle();

    /**
     * @brief r - метод возвращает величину в радианах
     * @return величина в радианах
     */
    nreal r() const;
    /**
     * @brief d - метод возвращает величину в градусах
     * @return величина в градусах
     */
    nreal d() const;
    /**
     * @brief setR - метод задает величину в радианах
     * @param radian величина в радианах
     */
    void setR( const nreal &radian );
    /**
     * @brief setD - метод задает величину в градусах
     * @param degree величина в градусах
     */
    void setD( const nreal &degree );

    /**
     * @brief asin - Метод задает значения угла через арксинус числа(Значения
     * числа должно лечать в пределах[-1;1]).
     * @param value - Число из которого будет браться арксинус.
     * @return экземпляр класса.
     */
    NAngle &asin( const nreal &value );
    /**
     * @brief acos - Метод задает значения угла через арккосинус числа(Значения
     * числа должно лечать в пределах[-1;1]).
     * @param value - Число из которого будет браться арккосинус.
     * @return экземпляр класса.
     */
    NAngle &acos( const nreal &value );
    /**
     * @brief atan - Метод задает значения угла через арктангенс числа.
     * @param value - Число из которого будет браться арктангенс.
     * @return экземпляр класса.
     */
    NAngle &atan( const nreal &value );
    /**
     * @brief actan - Метод задает значения угла через арккотангенс числа.
     * @param value - Число из которого будет браться арккотангенс.
     * @return экземпляр класса.
     */
    NAngle &actan( const nreal &value );

    /**
     * @brief sin - Методы вычисляет синус угла.
     * @return значения синуса угла.
     */
    nreal sin() const;
    /**
     * @brief cos - Методы вычисляет косинус угла.
     * @return значения косинуса угла.
     */
    nreal cos() const;
    /**
     * @brief tan - Методы вычисляет тангенс угла.
     * @return значения тангенса угла.
     */
    nreal tan() const;
    /**
     * @brief ctan - Методы вычисляет котангинс угла.
     * @return значения котангенса угла.
     */
    nreal ctan() const;

    /**
     * @brief intervalStrict - Метод, позволяющий определить попадания данного
     * экземпляра в замкнутый интервал(строгое равенство), ограничевающими
     * значениями left и right(left<=value, value<=right).
     * @param left - левая граница интервала.
     * @param right - правая граница интервала.
     * @return Значение true, если данный экземпляр попадает в интервал, в
     * противном случае — значение false.
     */
    bool intervalStrict( const NAngle &left,
                         const NAngle &right ) const noexcept;

    /**
     * @brief intervalLeftStrict - Метод, позволяющий определить попадания
     * данного экземпляра в полузамкнутый интервал по левому значению,
     * ограничевающими значениями left и right. Для левого значения используется
     * строгое равенство(left<=value, value<right).
     * @param left - левая граница интервала.
     * @param right - правая граница интервала.
     * @return Значение true, если данный экземпляр попадает в интервал, в
     * противном случае — значение false.
     */
    bool intervalLeftStrict( const NAngle &left,
                             const NAngle &right ) const noexcept;

    /**
     * @brief intervalRightStrict - Метод, позволяющий определить, попадания
     * данного экземпляра в полузамкнутый интервал по правому значению,
     * ограничевающими значениями left и right. Для правого значения
     * используется строгое равенство(left<value, value<=right).
     * @param left - левая граница интервала.
     * @param right - правая граница интервала.
     * @return  Значение true, если данный экземпляр попадает в интервал,
     * в противном случае — значение false.
     */
    bool intervalRightStrict( const NAngle &left,
                              const NAngle &right ) const noexcept;

    /**
     * @brief intervalSlack - Метод, позволяющее определить, попадания данного
     * экземпляра в открытый интервал(не строгое равенство), ограничевающими
     * значениями left и right(left<value, value<right).
     * @param left - левая граница интервала.
     * @param right - правая граница интервала.
     * @return Значение true, если данный экземпляр попадает в интервал, в
     * противном случае — значение false.
     */
    bool intervalSlack( const NAngle &left,
                        const NAngle &right ) const noexcept;

    NAngle &operator=( const NAngle &angle );
    NAngle &operator=( NAngle &&angle );

    NAngle &operator=( const nreal &value );
    NAngle &operator-();

    NAngle operator+( const NAngle &angle ) const;
    NAngle operator-( const NAngle &angle ) const;
    NAngle operator*( const nreal &value ) const;
    NAngle operator/( const nreal &value ) const;
    nreal operator/( const NAngle &angle ) const;

    NAngle &operator +=( const NAngle &angle );
    NAngle &operator -=( const NAngle &angle );

    bool operator>( const NAngle &value ) const;
    bool operator<( const NAngle &value ) const;
    bool operator==( const NAngle &value ) const;
    bool operator!=( const NAngle &value ) const;
    bool operator>=( const NAngle &value ) const;
    bool operator<=( const NAngle &value ) const;

    friend NAngle operator*( const nreal &value, const NAngle &angle );

    friend NAngle operator "" _deg( long double deg );
    friend NAngle operator "" _rad( long double rad );

private:
    /**
     * @brief a_ - Величина в радианах.
     */
    nreal a_;
};

inline NAngle NAngle::piOn180() noexcept
{
    return NAngle( nreal( 0.01745329251994329577 ) );
}

inline NAngle NAngle::piOn2() noexcept
{
    return NAngle( nreal( 1.57079632679489661923 ) );
}

inline NAngle NAngle::piOn4() noexcept
{
    return NAngle( nreal( 0.78539816339744830962 ) );
}

inline NAngle NAngle::piOn6() noexcept
{
    return NAngle( nreal( 0.52359877559829887308 ) );
}

inline NAngle NAngle::pi() noexcept
{
    return NAngle( nreal( 3.14159265358979323846 ) );
}

inline NAngle NAngle::piIn3On2() noexcept
{
    return NAngle( nreal( 4.71238898038468985769 ) );
}

inline NAngle NAngle::piIn2() noexcept
{
    return NAngle( nreal( 6.28318530717958647692 ) );
}

inline nreal NAngle::r() const
{
    return this->a_;
}

inline nreal NAngle::d() const
{
    return this->a_ / NAngle::piOn180().r();
}

inline void NAngle::setR( const nreal &radian )
{
    this->a_ = radian;
}

inline void NAngle::setD( const nreal &degree )
{
    this->a_ = degree * NAngle::piOn180().r();
}

inline NAngle &NAngle::asin( const nreal &value )
{
    if( value.intervalStrict( nreal( -1 ), nreal( 1 ) ) )
        this->a_ = ::asin( value.toType() );
    else
        std::cerr << "Inadmissible value arcsin" << std::endl;
    return *this;
}

inline NAngle &NAngle::acos( const nreal &value )
{
    if( value.intervalStrict( nreal( -1 ), nreal( 1 ) ) )
        this->a_ = ::acos( value.toType() );
    else
        std::cerr << "Inadmissible value arccos" << std::endl;
    return *this;
}

inline NAngle &NAngle::atan( const nreal &value )
{
    this->a_ = ::atan( value.toType() );
    return *this;
}

inline NAngle &NAngle::actan( const nreal &value )
{
    this->a_ = NAngle::piOn2().r() + ::atan( -value.toType() );
    return *this;
}

inline nreal NAngle::sin() const
{
    return nreal( ::sin( this->a_.toType() ) );
}

inline nreal NAngle::cos() const
{
    return nreal( ::cos( this->a_.toType() ) );
}

inline nreal NAngle::tan() const
{
    return nreal( ::tan( this->a_.toType() ) );
}

inline nreal NAngle::ctan() const
{
    return nreal( 1.0 ) / ::tan( this->a_.toType() );
}

inline bool NAngle::intervalStrict( const NAngle &left,
                                     const NAngle &right ) const noexcept
{
    return ( ( left <= *this ) && ( *this <= right ) );
}

inline bool NAngle::intervalLeftStrict( const NAngle &left,
                                          const NAngle &right ) const noexcept
{
    return ( ( left <= *this ) && ( *this < right ) );
}

inline bool NAngle::intervalRightStrict( const NAngle &left,
                                          const NAngle &right ) const noexcept
{
    return ( ( left < *this ) && ( *this <= right ) );
}

inline bool NAngle::intervalSlack( const NAngle &left,
                                    const NAngle &right ) const noexcept
{
    return ( ( left < *this ) && ( *this < right ) );
}

inline NAngle &NAngle::operator -()
{
    this->a_ = -this->a_;
    return *this;
}

inline NAngle NAngle::operator+( const NAngle &angle ) const
{
    return NAngle( this->a_ + angle.a_ );
}

inline NAngle NAngle::operator-( const NAngle &angle ) const
{
    return NAngle( this->a_ - angle.a_ );
}

inline NAngle NAngle::operator*( const nreal &value ) const
{
    return NAngle( this->a_ * value );
}

inline NAngle NAngle::operator/( const nreal &value ) const
{
    return NAngle( this->a_ / value );
}

inline nreal NAngle::operator/( const NAngle &angle ) const
{
    return this->a_ / angle.a_;
}

inline NAngle &NAngle::operator +=( const NAngle &angle )
{
    this->a_ += angle.a_;
    return *this;
}

inline NAngle &NAngle::operator -=( const NAngle &angle )
{
    this->a_ -= angle.a_;
    return *this;
}

inline bool NAngle::operator>( const NAngle &value ) const
{
    return ( this->a_ > value.a_ );
}

inline bool NAngle::operator<( const NAngle &value ) const
{
    return ( this->a_ < value.a_ );
}

inline bool NAngle::operator==( const NAngle &value ) const
{
    return this->a_.compare( value.a_ );
}

inline bool NAngle::operator!=(const NAngle &value) const
{
    return this->a_.unequal( value.a_ );
}

inline NAngle operator*( const nreal &value, const NAngle &angle )
{
    return angle * value;
}

inline NAngle operator "" _deg( long double deg )
{
    return NAngle( nreal( double( deg ) ), false );
}

inline NAngle operator "" _rad( long double rad )
{
    return NAngle( nreal( double( rad ) ) );
}


#endif // NANGLE_H
