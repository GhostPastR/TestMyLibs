#ifndef MPANGLE_H
#define MPANGLE_H

#include <cmath>
#include <ntype.h>

/**
 * @brief The MpAngle class - Класс предназначен для работы с угловыми
 * величинами(радианы и градусы).
 */
class MpAngle
{
public:
    /**
     * @brief piOn180 - Статический метод возвращающая значения угла Пи/180.
     * @return Значения угла.
     */
    static MpAngle piOn180() noexcept;
    /**
     * @brief piOn2 - Статический метод возвращающая значения угла Пи/2.
     * @return Значения угла.
     */
    static MpAngle piOn2() noexcept;
    /**
     * @brief piOn4 - Статический метод возвращающая значения угла Пи/4.
     * @return Значения угла.
     */
    static MpAngle piOn4() noexcept;
    /**
     * @brief piOn6 - Статический метод возвращающая значения угла Пи/6.
     * @return Значения угла.
     */
    static MpAngle piOn6() noexcept;
    /**
     * @brief pi - Статический метод возвращающая значения угла Пи.
     * @return Значения угла.
     */
    static MpAngle pi() noexcept;
    /**
     * @brief piIn3On2 - Статический метод возвращающая значения угла 3*Пи/2.
     * @return Значения угла.
     */
    static MpAngle piIn3On2() noexcept;
    /**
     * @brief piIn2 - Статический метод возвращающая значения угла 2*Пи.
     * @return Значения угла.
     */
    static MpAngle piIn2() noexcept;

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

    MpAngle( const nreal &value = nreal( 0.0 ), bool radian = true );
    MpAngle( const MpAngle &angle );
    MpAngle( MpAngle &&angle );
    virtual ~MpAngle();

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
    MpAngle &asin( const nreal &value );
    /**
     * @brief acos - Метод задает значения угла через арккосинус числа(Значения
     * числа должно лечать в пределах[-1;1]).
     * @param value - Число из которого будет браться арккосинус.
     * @return экземпляр класса.
     */
    MpAngle &acos( const nreal &value );
    /**
     * @brief atan - Метод задает значения угла через арктангенс числа.
     * @param value - Число из которого будет браться арктангенс.
     * @return экземпляр класса.
     */
    MpAngle &atan( const nreal &value );
    /**
     * @brief actan - Метод задает значения угла через арккотангенс числа.
     * @param value - Число из которого будет браться арккотангенс.
     * @return экземпляр класса.
     */
    MpAngle &actan( const nreal &value );

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
    bool intervalStrict( const MpAngle &left,
                         const MpAngle &right ) const noexcept;

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
    bool intervalLeftStrict( const MpAngle &left,
                             const MpAngle &right ) const noexcept;

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
    bool intervalRightStrict( const MpAngle &left,
                              const MpAngle &right ) const noexcept;

    /**
     * @brief intervalSlack - Метод, позволяющее определить, попадания данного
     * экземпляра в открытый интервал(не строгое равенство), ограничевающими
     * значениями left и right(left<value, value<right).
     * @param left - левая граница интервала.
     * @param right - правая граница интервала.
     * @return Значение true, если данный экземпляр попадает в интервал, в
     * противном случае — значение false.
     */
    bool intervalSlack( const MpAngle &left,
                        const MpAngle &right ) const noexcept;

    MpAngle &operator=( const MpAngle &angle );
    MpAngle &operator=( MpAngle &&angle );

    MpAngle &operator=( const nreal &value );
    MpAngle &operator-();

    MpAngle operator+( const MpAngle &angle ) const;
    MpAngle operator-( const MpAngle &angle ) const;
    MpAngle operator*( const nreal &value ) const;
    MpAngle operator/( const nreal &value ) const;
    nreal operator/( const MpAngle &angle ) const;

    MpAngle &operator +=( const MpAngle &angle );
    MpAngle &operator -=( const MpAngle &angle );

    bool operator>( const MpAngle &value ) const;
    bool operator<( const MpAngle &value ) const;
    bool operator==( const MpAngle &value ) const;
    bool operator!=( const MpAngle &value ) const;
    bool operator>=( const MpAngle &value ) const;
    bool operator<=( const MpAngle &value ) const;

    friend MpAngle operator*( const nreal &value, const MpAngle &angle );

    friend MpAngle operator "" _deg( long double deg );
    friend MpAngle operator "" _rad( long double rad );

private:
    /**
     * @brief a_ - Величина в радианах.
     */
    nreal a_;
};

inline MpAngle MpAngle::piOn180() noexcept
{
    return MpAngle( nreal( 0.01745329251994329577 ) );
}

inline MpAngle MpAngle::piOn2() noexcept
{
    return MpAngle( nreal( 1.57079632679489661923 ) );
}

inline MpAngle MpAngle::piOn4() noexcept
{
    return MpAngle( nreal( 0.78539816339744830962 ) );
}

inline MpAngle MpAngle::piOn6() noexcept
{
    return MpAngle( nreal( 0.52359877559829887308 ) );
}

inline MpAngle MpAngle::pi() noexcept
{
    return MpAngle( nreal( 3.14159265358979323846 ) );
}

inline MpAngle MpAngle::piIn3On2() noexcept
{
    return MpAngle( nreal( 4.71238898038468985769 ) );
}

inline MpAngle MpAngle::piIn2() noexcept
{
    return MpAngle( nreal( 6.28318530717958647692 ) );
}

inline nreal MpAngle::r() const
{
    return this->a_;
}

inline nreal MpAngle::d() const
{
    return this->a_ / MpAngle::piOn180().r();
}

inline void MpAngle::setR( const nreal &radian )
{
    this->a_ = radian;
}

inline void MpAngle::setD( const nreal &degree )
{
    this->a_ = degree * MpAngle::piOn180().r();
}

inline MpAngle &MpAngle::asin( const nreal &value )
{
    if( value.intervalStrict( nreal( -1 ), nreal( 1 ) ) )
        this->a_ = ::asin( value.toType() );
    else
        std::cerr << "Inadmissible value arcsin" << std::endl;
    return *this;
}

inline MpAngle &MpAngle::acos( const nreal &value )
{
    if( value.intervalStrict( nreal( -1 ), nreal( 1 ) ) )
        this->a_ = ::acos( value.toType() );
    else
        std::cerr << "Inadmissible value arccos" << std::endl;
    return *this;
}

inline MpAngle &MpAngle::atan( const nreal &value )
{
    this->a_ = ::atan( value.toType() );
    return *this;
}

inline MpAngle &MpAngle::actan( const nreal &value )
{
    this->a_ = MpAngle::piOn2().r() + ::atan( -value.toType() );
    return *this;
}

inline nreal MpAngle::sin() const
{
    return nreal( ::sin( this->a_.toType() ) );
}

inline nreal MpAngle::cos() const
{
    return nreal( ::cos( this->a_.toType() ) );
}

inline nreal MpAngle::tan() const
{
    return nreal( ::tan( this->a_.toType() ) );
}

inline nreal MpAngle::ctan() const
{
    return nreal( 1.0 ) / ::tan( this->a_.toType() );
}

inline bool MpAngle::intervalStrict( const MpAngle &left,
                                     const MpAngle &right ) const noexcept
{
    return ( ( left <= *this ) && ( *this <= right ) );
}

inline bool MpAngle::intervalLeftStrict( const MpAngle &left,
                                          const MpAngle &right ) const noexcept
{
    return ( ( left <= *this ) && ( *this < right ) );
}

inline bool MpAngle::intervalRightStrict( const MpAngle &left,
                                          const MpAngle &right ) const noexcept
{
    return ( ( left < *this ) && ( *this <= right ) );
}

inline bool MpAngle::intervalSlack( const MpAngle &left,
                                    const MpAngle &right ) const noexcept
{
    return ( ( left < *this ) && ( *this < right ) );
}

inline MpAngle &MpAngle::operator -()
{
    this->a_ = -this->a_;
    return *this;
}

inline MpAngle MpAngle::operator+( const MpAngle &angle ) const
{
    return MpAngle( this->a_ + angle.a_ );
}

inline MpAngle MpAngle::operator-( const MpAngle &angle ) const
{
    return MpAngle( this->a_ - angle.a_ );
}

inline MpAngle MpAngle::operator*( const nreal &value ) const
{
    return MpAngle( this->a_ * value );
}

inline MpAngle MpAngle::operator/( const nreal &value ) const
{
    return MpAngle( this->a_ / value );
}

inline nreal MpAngle::operator/( const MpAngle &angle ) const
{
    return this->a_ / angle.a_;
}

inline MpAngle &MpAngle::operator +=( const MpAngle &angle )
{
    this->a_ += angle.a_;
    return *this;
}

inline MpAngle &MpAngle::operator -=( const MpAngle &angle )
{
    this->a_ -= angle.a_;
    return *this;
}

inline bool MpAngle::operator>( const MpAngle &value ) const
{
    return ( this->a_ > value.a_ );
}

inline bool MpAngle::operator<( const MpAngle &value ) const
{
    return ( this->a_ < value.a_ );
}

inline bool MpAngle::operator==( const MpAngle &value ) const
{
    return this->a_.compare( value.a_ );
}

inline bool MpAngle::operator!=(const MpAngle &value) const
{
    return this->a_.unequal( value.a_ );
}

inline MpAngle operator*( const nreal &value, const MpAngle &angle )
{
    return angle * value;
}

inline MpAngle operator "" _deg( long double deg )
{
    return MpAngle( nreal( double( deg ) ), false );
}

inline MpAngle operator "" _rad( long double rad )
{
    return MpAngle( nreal( double( rad ) ) );
}


#endif // MPANGLE_H
