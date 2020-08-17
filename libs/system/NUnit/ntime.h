#ifndef NTIME_H
#define NTIME_H

#include <ntype.h>

class NSpeed;
class NDistance;
/**
 * @brief The NTime class - Класс предназначен для работы с величинами
 * характеризующие время.
 */
class NTime
{
public:
    /**
     * @brief time - Возвращает новое значения для экземпляра через дистанцию и скорость.
     * @param distance - новое значение расстояния, speed - новое значение скорости.
     * @return экземпляр класса.
     */
    static NTime time( const NDistance &distance, const NSpeed &speed )
                                                                       noexcept;

    NTime() noexcept;
    NTime( const nulong &sec ) noexcept;
    NTime( const NTime &time );
    NTime( NTime &&time );

    /**
     * @brief sec - Возвращает значения экземпляра класса в секундах.
     * @return значение в граммах.
     */
    nulong sec() const noexcept;
    /**
     * @brief min - Возвращает значения экземпляра класса в минутах.
     * @return значение в минутах.
     */
    nulong min() const noexcept;
    /**
     * @brief hour - Возвращает значения экземпляра класса в часах.
     * @return значение в часах.
     */
    nulong hour() const noexcept;
    /**
     * @brief day - Возвращает значения экземпляра класса в днях.
     * @return значение в днях.
     */
    nulong day() const noexcept;
    /**
     * @brief toString - Возвращает значения экземпляра класса в виде строки.
     * @param format - формат вывода данных.
     * d - день, hh/h - час, mm/m - минута, ss/s - секунда
     * в качестве разделителя допустимы любые одиночные символы
     * @return значение в виде строки.
     */
    QString toString( const QString &format = "hh:mm:ss" ) noexcept;
    /**
     * @brief setTime - Задает новое значения для экземпляра через дистанцию и скорость.
     * @param distance - новое значение расстояния, speed - новое значение скорости.
     * @return экземпляр класса.
     */
    NTime &setTime( const NDistance &distance, const NSpeed &speed ) noexcept;
    /**
     * @brief setSec - Задает новое значения для экземпляра класса в секундах.
     * @param sec - новое значение в секундах.
     * @return ссылка на экземпляр класса.
     */
    NTime &setSec( const nulong &sec ) noexcept;
    /**
     * @brief setMin - Задает новое значения для экземпляра класса в минутах.
     * @param min - новое значение в минутах.
     * @return ссылка на экземпляр класса.
     */
    NTime &setMin( const nulong &min ) noexcept;
    /**
     * @brief setHour - Задает новое значения для экземпляра класса в часах.
     * @param hour - новое значение в часах.
     * @return ссылка на экземпляр класса.
     */
    NTime &setHour( const nulong &hour ) noexcept;
    /**
     * @brief setDay - Задает новое значения для экземпляра класса в днях.
     * @param day - новое значение в часах.
     * @return ссылка на экземпляр класса.
     */
    NTime &setDay( const nulong &day ) noexcept;

    NTime &operator=( const NTime &time );
    NTime &operator=( NTime &&time );

    bool operator ==( const NTime &value ) const noexcept;
    bool operator !=( const NTime &value ) const noexcept;
    bool operator >=( const NTime &value ) const noexcept;
    bool operator <=( const NTime &value ) const noexcept;
    bool operator >( const NTime &value ) const noexcept;
    bool operator <( const NTime &value ) const noexcept;

    NTime operator +( const NTime &value ) const noexcept;
    NTime operator -( const NTime &value ) const noexcept;
    NTime &operator +=( const NTime &value ) noexcept;
    NTime &operator -=( const NTime &value ) noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса
     * на 1.
     * @return экземпляр класса с новым значением.
     */
    NTime &operator++() noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса на
     * 1 и возвращающие старое значение.
     * @return  экземпляр класса со старым значением.
     */
    NTime operator++(int) noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1.
     * @return экземпляр класса с новым значением.
     */
    NTime &operator--() noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1
     * и возвращающие старое значение.
     * @return экземпляр класса со старыи значением.
     */
    NTime operator--(int) noexcept;

    friend NTime operator "" _sec( unsigned long long sec ) noexcept;
    friend NTime operator "" _min( unsigned long long min ) noexcept;
    friend NTime operator "" _hour( unsigned long long hour ) noexcept;
    friend NTime operator "" _day( unsigned long long day ) noexcept;

private:
    nulong value_;
};

inline NTime::NTime() noexcept
{

}

inline NTime::NTime(const nulong &sec ) noexcept
{
    this->value_ = sec;
}

inline NTime::NTime( const NTime &time )
{
    this->value_ = time.value_;
}

inline NTime::NTime( NTime &&time )
{
    this->value_ = std::move( time.value_ );
}

inline nulong NTime::sec() const noexcept
{
    return this->value_;
}

inline nulong NTime::min() const noexcept
{
    return this->value_ / nulong( 60.0 );
}

inline nulong NTime::hour() const noexcept
{
    return this->value_ / nulong( 3600.0 );
}

inline nulong NTime::day() const noexcept
{
    return this->value_ / nulong( 86400.0 );
}

inline NTime &NTime::setSec( const nulong &sec ) noexcept
{
    this->value_ = sec;
    return *this;
}

inline NTime &NTime::setMin( const nulong &min ) noexcept
{
    this->value_ = min * nulong( 60.0 );
    return *this;
}

inline NTime &NTime::setHour( const nulong &hour ) noexcept
{
    this->value_ = hour * nulong( 3600.0 );
    return *this;
}

inline NTime &NTime::setDay( const nulong &day ) noexcept
{
    this->value_ = day * nulong( 86400.0 );
    return *this;
}

inline NTime &NTime::operator=( const NTime &time )
{
    this->value_ = time.value_;
    return *this;
}

inline NTime &NTime::operator=( NTime &&time )
{
    this->value_ = std::move( time.value_ );
    return *this;
}

inline bool NTime::operator ==( const NTime &value ) const noexcept
{
    return ( this->value_ == value.value_ );
}

inline bool NTime::operator !=( const NTime &value ) const noexcept
{
    return ( this->value_ != value.value_ );
}

inline bool NTime::operator >=( const NTime &value ) const noexcept
{
    return ( this->value_ >= value.value_ );
}

inline bool NTime::operator <=( const NTime &value ) const noexcept
{
    return ( this->value_ <= value.value_ );
}

inline bool NTime::operator >( const NTime &value ) const noexcept
{
    return ( this->value_ > value.value_ );
}

inline bool NTime::operator <( const NTime &value ) const noexcept
{
    return ( this->value_ < value.value_ );
}

inline NTime NTime::operator +( const NTime &value ) const noexcept
{
    return NTime(this->value_ + value.value_);
}

inline NTime NTime::operator -( const NTime &value ) const noexcept
{
    return NTime(this->value_ - value.value_);
}

inline NTime &NTime::operator += ( const NTime &value ) noexcept
{
    this->value_ += value.value_;
    return *this;
}

inline NTime &NTime::operator -= ( const NTime &value ) noexcept
{
    this->value_ -= value.value_;
    return *this;
}

inline NTime &NTime::operator++() noexcept
{
    ++this->value_;
    return *this;
}

inline NTime NTime::operator++(int) noexcept
{
    NTime v = this->value_;
    ++(*this);
    return v;
}

inline NTime &NTime::operator--() noexcept
{
    --this->value_;
    return *this;
}

inline NTime NTime::operator--(int) noexcept
{
    NTime v = *this;
    --(*this);
    return v;
}

inline NTime operator "" _sec( unsigned long long sec ) noexcept
{
    return NTime( nulong( sec ) );
}

inline NTime operator "" _min( unsigned long long min ) noexcept
{
    return NTime().setMin( nulong( min ) );
}

inline NTime operator "" _hour( unsigned long long hour ) noexcept
{
    return NTime().setHour( nulong( hour ) );
}

inline NTime operator "" _day( unsigned long long day ) noexcept
{
    return NTime().setDay( nulong( day ) );
}

#endif // NTIME_H
