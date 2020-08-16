#include <ntype.h>

class MpSpeed;
class MpDistance;
/**
 * @brief The MpTime class - Класс предназначен для работы с величинами
 * характеризующие время.
 */
class MpTime
{
public:
    /**
     * @brief time - Возвращает новое значения для экземпляра через дистанцию и скорость.
     * @param distance - новое значение расстояния, speed - новое значение скорости.
     * @return экземпляр класса.
     */
    static MpTime time( const MpDistance &distance, const MpSpeed &speed ) noexcept;

    MpTime() noexcept;
    MpTime( const nulong &sec ) noexcept;
    MpTime( const MpTime &time );
    MpTime( MpTime &&time );

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
    MpTime &setTime( const MpDistance &distance, const MpSpeed &speed ) noexcept;
    /**
     * @brief setSec - Задает новое значения для экземпляра класса в секундах.
     * @param sec - новое значение в секундах.
     * @return ссылка на экземпляр класса.
     */
    MpTime &setSec( const nulong &sec ) noexcept;
    /**
     * @brief setMin - Задает новое значения для экземпляра класса в минутах.
     * @param min - новое значение в минутах.
     * @return ссылка на экземпляр класса.
     */
    MpTime &setMin( const nulong &min ) noexcept;
    /**
     * @brief setHour - Задает новое значения для экземпляра класса в часах.
     * @param hour - новое значение в часах.
     * @return ссылка на экземпляр класса.
     */
    MpTime &setHour( const nulong &hour ) noexcept;
    /**
     * @brief setDay - Задает новое значения для экземпляра класса в днях.
     * @param day - новое значение в часах.
     * @return ссылка на экземпляр класса.
     */
    MpTime &setDay( const nulong &day ) noexcept;

    MpTime &operator=( const MpTime &time );
    MpTime &operator=( MpTime &&time );

    bool operator ==( const MpTime &value ) const noexcept;
    bool operator !=( const MpTime &value ) const noexcept;
    bool operator >=( const MpTime &value ) const noexcept;
    bool operator <=( const MpTime &value ) const noexcept;
    bool operator >( const MpTime &value ) const noexcept;
    bool operator <( const MpTime &value ) const noexcept;

    MpTime operator +( const MpTime &value ) const noexcept;
    MpTime operator -( const MpTime &value ) const noexcept;
    MpTime &operator +=( const MpTime &value ) noexcept;
    MpTime &operator -=( const MpTime &value ) noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса
     * на 1.
     * @return экземпляр класса с новым значением.
     */
    MpTime &operator++() noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса на
     * 1 и возвращающие старое значение.
     * @return  экземпляр класса со старым значением.
     */
    MpTime operator++(int) noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1.
     * @return экземпляр класса с новым значением.
     */
    MpTime &operator--() noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1
     * и возвращающие старое значение.
     * @return экземпляр класса со старыи значением.
     */
    MpTime operator--(int) noexcept;

    friend MpTime operator "" _sec( unsigned long long sec ) noexcept;
    friend MpTime operator "" _min( unsigned long long min ) noexcept;
    friend MpTime operator "" _hour( unsigned long long hour ) noexcept;
    friend MpTime operator "" _day( unsigned long long day ) noexcept;

private:
    nulong value_;
};

inline MpTime::MpTime() noexcept
{

}

inline MpTime::MpTime(const nulong &sec ) noexcept
{
    this->value_ = sec;
}

inline MpTime::MpTime( const MpTime &time )
{
    this->value_ = time.value_;
}

inline MpTime::MpTime( MpTime &&time )
{
    this->value_ = std::move( time.value_ );
}

inline nulong MpTime::sec() const noexcept
{
    return this->value_;
}

inline nulong MpTime::min() const noexcept
{
    return this->value_ / nulong( 60.0 );
}

inline nulong MpTime::hour() const noexcept
{
    return this->value_ / nulong( 3600.0 );
}

inline nulong MpTime::day() const noexcept
{
    return this->value_ / nulong( 86400.0 );
}

inline MpTime &MpTime::setSec( const nulong &sec ) noexcept
{
    this->value_ = sec;
    return *this;
}

inline MpTime &MpTime::setMin( const nulong &min ) noexcept
{
    this->value_ = min * nulong( 60.0 );
    return *this;
}

inline MpTime &MpTime::setHour( const nulong &hour ) noexcept
{
    this->value_ = hour * nulong( 3600.0 );
    return *this;
}

inline MpTime &MpTime::setDay( const nulong &day ) noexcept
{
    this->value_ = day * nulong( 86400.0 );
    return *this;
}

inline MpTime &MpTime::operator=( const MpTime &time )
{
    this->value_ = time.value_;
    return *this;
}

inline MpTime &MpTime::operator=( MpTime &&time )
{
    this->value_ = std::move( time.value_ );
    return *this;
}

inline bool MpTime::operator ==( const MpTime &value ) const noexcept
{
    return ( this->value_ == value.value_ );
}

inline bool MpTime::operator !=( const MpTime &value ) const noexcept
{
    return ( this->value_ != value.value_ );
}

inline bool MpTime::operator >=( const MpTime &value ) const noexcept
{
    return ( this->value_ >= value.value_ );
}

inline bool MpTime::operator <=( const MpTime &value ) const noexcept
{
    return ( this->value_ <= value.value_ );
}

inline bool MpTime::operator >( const MpTime &value ) const noexcept
{
    return ( this->value_ > value.value_ );
}

inline bool MpTime::operator <( const MpTime &value ) const noexcept
{
    return ( this->value_ < value.value_ );
}

inline MpTime MpTime::operator +( const MpTime &value ) const noexcept
{
    return MpTime(this->value_ + value.value_);
}

inline MpTime MpTime::operator -( const MpTime &value ) const noexcept
{
    return MpTime(this->value_ - value.value_);
}

inline MpTime &MpTime::operator += ( const MpTime &value ) noexcept
{
    this->value_ += value.value_;
    return *this;
}

inline MpTime &MpTime::operator -= ( const MpTime &value ) noexcept
{
    this->value_ -= value.value_;
    return *this;
}

inline MpTime &MpTime::operator++() noexcept
{
    ++this->value_;
    return *this;
}

inline MpTime MpTime::operator++(int) noexcept
{
    MpTime v = this->value_;
    ++(*this);
    return v;
}

inline MpTime &MpTime::operator--() noexcept
{
    --this->value_;
    return *this;
}

inline MpTime MpTime::operator--(int) noexcept
{
    MpTime v = *this;
    --(*this);
    return v;
}

inline MpTime operator "" _sec( unsigned long long sec ) noexcept
{
    return MpTime( nulong( sec ) );
}

inline MpTime operator "" _min( unsigned long long min ) noexcept
{
    return MpTime().setMin( nulong( min ) );
}

inline MpTime operator "" _hour( unsigned long long hour ) noexcept
{
    return MpTime().setHour( nulong( hour ) );
}

inline MpTime operator "" _day( unsigned long long day ) noexcept
{
    return MpTime().setDay( nulong( day ) );
}

