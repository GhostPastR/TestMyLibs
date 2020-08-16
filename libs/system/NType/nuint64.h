#ifndef NUINT64_H
#define NUINT64_H

#include "ininteger.h"

/** \brief The MpDouble class - Класс представляет целое число размером 4 байта.
 */
class NUInt64 : public INInteger<NUInt64, uint64_t>
{
public:        
    /**
     * @brief minValue - Представляет минимально допустимое значение типа .
     * NUInt64.
     */
    const static NUInt64 minValue;
    /**
     * @brief maxValue - Представляет наибольшее возможное значение типа NUInt64.
     */
    const static NUInt64 maxValue;

    /** \brief NUInt64 - Инициализирует новый экземпляр класса целого числа со
     * значением 0.
     */
    NUInt64() noexcept;

    /**
     * @brief NUInt64 - Инициализирует новый экземпляр класса целого числа с
     * заданым значением.
     * @param value - целое число стандартного типа uint64_t.
     */
    NUInt64( uint64_t value ) noexcept;

    /**
     * @brief NUInt64 - Инициализирует новый экземпляр класса целого числа с
     * заданым значением.
     * @param value - целое число типа NUInt64.
     */
    NUInt64( const NUInt64 &value ) noexcept;

    /**
     * @brief NUInt64 - Инициализирует новый экземпляр класса целого числа с
     * заданым значением, реализующий семантику перемещения.
     * @param value - целое число типа NUInt64.
     */
    NUInt64( NUInt64 &&value ) noexcept;

    ~NUInt64() noexcept{}

    /**
     * @brief operator = - Оператор, позволяющий, присвоить значения
     * стандартного типа uint64_t к данному экземпляру.
     * @param value - целое число стандартного типа uint64_t.
     * @return экземпляр класса с новым значением.
     */
    NUInt64 &operator =( uint64_t value ) noexcept;

    /**
     * @brief operator = - Оператор, позволяющий, присвоить значения
     * стандартного типа uint64_t к данному экземпляру.
     * @param value - целое число типа NUInt64.
     * @return экземпляр класса с новым значением.
     */
    NUInt64 &operator =( const NUInt64 &value ) noexcept;

    /**
     * @brief operator = - Оператор, позволяющий, присвоить значения
     * стандартного типа uint64_t к данному экземпляру, реализующий семантику
     * перемещения.
     * @param value - целое число типа NUInt64.
     * @return экземпляр класса с новым значением.
     */
    NUInt64 &operator =( NUInt64 &&value ) noexcept;

    /**
     * @brief operator + -  Оператор, возвращающий, сумму чисел значений NUInt64.
     * @param value - целое число типа NUInt64.
     * @return сумма чисел типа NUInt64.
     */
    NUInt64 operator +( const NUInt64 &value ) const noexcept;

    /**
     * @brief operator + - Оператор, возвращающий, сумму чисел значений данного
     * экземпляра и заданого числа стандартного типа uint64_t.
     * @param value - целое число стандартного типа uint64_t.
     * @return сумма чисел типа NUInt64.
     */
    NUInt64 operator +( uint64_t value ) const noexcept;

    /**
     * @brief operator - Оператор, возвращающий, разность чисел значений NUInt64.
     * @param value - целое число типа NUInt64.
     * @return разность чисел типа NUInt64.
     */
    NUInt64 operator -( const NUInt64 &value ) const noexcept;

    /**
     * @brief operator - - Оператор, возвращающий, разность чисел значений
     * данного экземпляра и заданого числа стандартного типа uint64_t.
     * @param value - целое число стандартного типа uint64_t.
     * @return разность чисел типа NUInt64.
     */
    NUInt64 operator -( uint64_t value ) const noexcept;

    /**
     * @brief operator * - Оператор, возвращающий, произведения чисел значений
     * NUInt64.
     * @param value - целое число типа NUInt64.
     * @return произведения чисел типа NUInt64.
     */
    NUInt64 operator *( const NUInt64 &value ) const noexcept;

    /**
     * @brief operator * - Оператор, возвращающий, произведение чисел значений
     * данного экземпляра и заданого числа стандартного типа uint64_t.
     * @param value - целое число стандартного типа uint64_t.
     * @return произведения чисел типа NUInt64.
     */
    NUInt64 operator *( uint64_t value ) const noexcept;

    /**
     * @brief operator / - Оператор, возвращающий, частное чисел значений
     * NUInt64.
     * @param value - целое число типа NUInt64.
     * @return частное чисел типа NUInt64.
     */
    NUInt64 operator /( const NUInt64 &value ) const noexcept;

    /**
     * @brief operator / - Оператор, возвращающий, частнок чисел значений
     * данного экземпляра и заданого числа.
     * @param value - целое число стандартного типа uint64_t.
     * @return частное чисел типа NUInt64.
     */
    NUInt64 operator /( uint64_t value ) const noexcept;

    /**
     * @brief operator % - Оператор, возвращающий, остаток от деления на число
     * типа NUInt64.
     * @param value - целое число типа NUInt64.
     * @return частное чисел типа NUInt64.
     */
    NUInt64 operator %( const NUInt64 &value ) const noexcept;

    /**
     * @brief operator % - Оператор, возвращающий, остаток от деления на число
     * стандартного типа uint64_t.
     * @param value - целое число стандартного типа uint64_t.
     * @return остаток от деления чисел типа NUInt64.
     */
    NUInt64 operator %( uint64_t value ) const noexcept;

    /**
     * @brief operator += - Оператор, позволяющий вернуть, результат операции
     * '+=' двух чисел типа NUInt64, конечный результат присваивается экземпляру
     * класса.
     * @param value - целое число типа NUInt64.
     * @return экземпляр класса с новым значением.
     */
    NUInt64 &operator +=( const NUInt64 &value ) noexcept;

    /**
     * @brief operator += - Оператор, позволяющий вернуть, результат операции
     * '+=' двух чисел данного экземпляра и числом стандартного типа uint64_t,
     * конечный результат присваивается экземпляру класса.
     * @param value - целое число стандартного типа uint64_t.
     * @return экземпляр класса с новым значением.
     */
    NUInt64 &operator +=( uint64_t value ) noexcept;

    /**
     * @brief operator -= - Оператор, позволяющий вернуть, результат операции
     * '-=' двух чисел типа NUInt64 и, конечный результат присваивается
     * экземпляру класса.
     * @param value - целое число типа NUInt64.
     * @return экземпляр класса с новым значением.
     */
    NUInt64 &operator -=( const NUInt64 &value ) noexcept;

    /**
     * @brief operator -= - Оператор, позволяющий вернуть, результат операции
     * '-=' двух чисел данного экземпляра и числом стандартного типа uint64_t,
     * конечный результат присваивается экземпляру класса.
     * @param value - целое число стандартного типа uint64_t.
     * @return экземпляр класса с новым значением.
     */
    NUInt64 &operator -=( uint64_t value ) noexcept;

    /**
     * @brief operator *= - Оператор, позволяющий вернуть, результат операции
     * '*=' двух чисел типа NUInt64, конечный результат присваивается экземпляру
     * класса.
     * @param value - целое число типа NUInt64.
     * @return экземпляр класса с новым значением.
     */
    NUInt64 &operator *=( const NUInt64 &value ) noexcept;

    /**
     * @brief operator *= - Оператор, позволяющий вернуть, результат операции
     * '*=' двух чисел данного экземпляра и числом стандартного типа uint64_t,
     * конечный результат присваивается экземпляру класса.
     * @param value - целое число стандартного типа uint64_t.
     * @return экземпляр класса с новым значением.
     */
    NUInt64 &operator *=( uint64_t value ) noexcept;

    /**
     * @brief operator /= - Оператор, позволяющий вернуть, результат операции
     * '/=' двух чисел типа NUInt64, конечный результат присваивается экземпляру
     * класса.
     * @param value - целое число типа NUInt64.
     * @return экземпляр класса с новым значением.
     */
    NUInt64 &operator /=( const NUInt64 &value ) noexcept;

    /**
     * @brief operator /= - Оператор, позволяющий вернуть, результат операции
     * '/=' двух чисел данного экземпляра и числом стандартного типа uint64_t,
     * конечный результат присваивается экземпляру класса.
     * @param value - целое число стандартного типа uint64_t.
     * @return экземпляр класса с новым значением.
     */
    NUInt64 &operator /=( uint64_t value ) noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса
     * на 1.
     * @return экземпляр класса с новым значением.
     */
    NUInt64 &operator++() noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса на
     * 1 и возвращающие старое значение.
     * @return  экземпляр класса со старым значением.
     */
    NUInt64 operator++(int) noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1.
     * @return экземпляр класса с новым значением.
     */
    NUInt64 &operator--() noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1
     * и возвращающие старое значение.
     * @return экземпляр класса со старыи значением.
     */
    NUInt64 operator--(int) noexcept;

    /**
     * @brief operator == - Оператор, указывающий, равны ли два заданных
     * значения типа NUInt64.
     * @param value - целое число типа NUInt64.
     * @return Значение true, если значения равны в противном случае —
     * значение false.
     */
    bool operator ==( const NUInt64 &value ) const noexcept;

    /**
     * @brief operator == - Оператор, указывающий, равны ли два заданных
     * значения данного экземпляра и число стандартного типа uint64_t.
     * @param value - целое число стандартного типа uint64_t.
     * @return Значение true, если значения равны в противном случае — значение
     * false.
     */
    bool operator ==( uint64_t value ) const noexcept;

    /**
     * @brief operator != - Оператор, указывающий, не равны ли два заданных
     * значения типа NUInt64.
     * @param value - целое число типа NUInt64.
     * @return Значение true, если значения не равны в противном случае —
     * значение false.
     */
    bool operator !=( const NUInt64 &value ) const noexcept;

    /**
     * @brief operator != - Оператор, указывающий, не равны ли заданных значения
     * данного экземпляра и число стандартного типа uint64_t.
     * @param value - целое число стандартного типа uint64_t.
     * @return Значение true, если значения не равны в противном случае —
     * значение false.
     */
    bool operator !=( uint64_t value ) const noexcept;

    /**
     * @brief operator > - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра больше заданному значению типа NUInt64.
     * @param value - целое число типа NUInt64.
     * @return Значение true, если данного экземпляра больше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator >( const NUInt64 &value ) const noexcept;

    /**
     * @brief operator > - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра больше заданному значению стандартного типа
     * uint64_t.
     * @param value - целое число стандартного типа uint64_t.
     * @return Значение true, если данного экземпляра больше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator >( uint64_t value ) const noexcept;

    /**
     * @brief operator >= - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра больше или равно заданному значению типа
     * NUInt64.
     * @param value - целое число типа NUInt64.
     * @return  Значение true, если данного экземпляра больше или равно
     * заданному значению в противном случае — значение false.
     */
    bool operator >=( const NUInt64 &value ) const noexcept;

    /**
     * @brief operator >= - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра больше или равно заданному значению
     * стандартного типа uint64_t.
     * @param value - число двойной точности с плавающей запятой стандартного типа uint64_t.
     * @return Значение true, если данного экземпляра больше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator >=( uint64_t value ) const noexcept;

    /**
     * @brief operator < - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра меньше заданному значению типа NUInt64.
     * @param value - целое число типа NUInt64.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator <( const NUInt64 &value ) const noexcept;

    /**
     * @brief operator < - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра меньше заданному значению стандартного типа
     * uint64_t.
     * @param value - целое число стандартного типа uint64_t.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator <( uint64_t value ) const noexcept;

    /**
     * @brief operator <= - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра меньше или равно заданному значению типа
     * NUInt64.
     * @param value - целое число типа NUInt64.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     *  значению в противном случае — значение false.
     */
    bool operator <=( const NUInt64 &value ) const noexcept;

    /**
     * @brief operator <= - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра меньше или равно заданному значению
     * стандартного типа uint64_t.
     * @param value - целое число стандартного типа uint64_t.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator <=( uint64_t value ) const noexcept;

    /**
     * @brief operator & - Оператор, реализующий, операцию побитовое 'и' двух
     * чисел типа NUInt64.
     * @param value - целое число типа NUInt64.
     * @return новое значение типа NUInt64.
     */
    NUInt64 operator &( const NUInt64 &value ) const noexcept;

    /**
     * @brief operator & - Оператор, реализующий, операцию побитовое 'и' двух
     * чисел типа NUInt64.
     * @param value - целое число стандартного типа uint64_t.
     * @return новое значение типа NUInt64.
     */
    NUInt64 operator &( uint64_t value ) const noexcept;

    /**
     * @brief operator | - Оператор, реализующий, операцию побитовое 'или' двух
     * чисел типа NUInt64.
     * @param value - целое число типа NUInt64.
     * @return новое значение типа NUInt64.
     */
    NUInt64 operator |( const NUInt64 &value ) const noexcept;

    /**
     * @brief operator | - Оператор, реализующий, операцию побитовое 'или'
     * заданного класса и числа стандарного типа uint64_t.
     * @param value - целое число стандартного типа uint64_t.
     * @return новое значение типа NUInt64.
     */
    NUInt64 operator |( uint64_t value ) const noexcept;

    /**
     * @brief operator ^ - Оператор, реализующий, операцию исключающие 'или'
     * двух чисел типа NUInt64.
     * @param value - целое число типа NUInt64.
     * @return новое значение типа NUInt64.
     */
    NUInt64 operator ^( const NUInt64 &value ) const noexcept;

    /**
     * @brief operator ^ -  Оператор, реализующий, операцию исключающие 'или'
     * заданного класса и числа стандарного типа uint64_t.
     * @param value - целое число стандартного типа uint64_t.
     * @return новое значение типа NUInt64.
     */
    NUInt64 operator ^( uint64_t value ) const noexcept;

    /**
     * @brief operator &= - Оператор, реализующий, операцию побитовое 'и' двух
     * чисел типа NUInt64, результат сохраняется в экземпляре класса.
     * @param value - целое число типа NUInt64.
     * @return новое значение типа NUInt64.
     */
    NUInt64 &operator &=( const NUInt64 &value ) noexcept;

    /**
     * @brief operator &= - Оператор, реализующий, операцию побитовое 'и'
     * заданного класса и числа стандарного типа uint64_t, результат сохраняется
     * в экземпляре класса.
     * @param value - целое число стандартного типа uint64_t.
     * @return новое значение типа NUInt64.
     */
    NUInt64 &operator &=( uint64_t value ) noexcept;

    /**
     * @brief operator |= - Оператор, реализующий, операцию побитовое 'или' двух
     * чисел типа NUInt64 результат сохраняется в экземпляре класса.
     * @param value - целое число типа NUInt64.
     * @return новое значение типа NUInt64.
     */
    NUInt64 &operator |=( const NUInt64 &value ) noexcept;

    /**
     * @brief operator |= - Оператор, реализующий, операцию побитовое 'или'
     * заданного класса и числа стандарного типа uint64_t, результат сохраняется
     * в экземпляре класса.
     * @param value - целое число стандартного типа uint64_t.
     * @return новое значение типа NUInt64.
     */
    NUInt64 &operator |=( uint64_t value ) noexcept;

    /**
     * @brief operator ^= - Оператор, реализующий, операцию исключающие 'или'
     * двух чисел типа NUInt64, результат сохраняется в экземпляре класса.
     * @param value - целое число типа NUInt64.
     * @return новое значение типа NUInt64.
     */
    NUInt64 &operator ^=( const NUInt64 &value ) noexcept;

    /**
     * @brief operator ^= -  Оператор, реализующий, операцию исключающие 'или'
     * заданного класса и числа стандарного типа uint64_t, результат сохраняется
     * в экземпляре класса.
     * @param value - целое число стандартного типа uint64_t.
     * @return новое значение типа NUInt64.
     */
    NUInt64 &operator ^=( uint64_t value ) noexcept;

    /**
     * @brief operator >> -  Оператор, реализующий, операцию циклических сдвиг
     * вправо на значение value.
     * @param value - целое число типа NUInt64.
     * @return новое значение типа NUInt64.
     */
    NUInt64 operator >>( const NUInt64 &value ) const noexcept;

    /**
     * @brief operator >> -  Оператор, реализующий, операцию циклических сдвиг
     * вправо на значение value.
     * @param value - целое число стандартного типа uint64_t.
     * @return новое значение типа NUInt64.
     */
    NUInt64 operator >>( uint64_t value ) const noexcept;

    /**
     * @brief operator << - Оператор, реализующий, операцию циклических сдвиг
     * влево на значение value.
     * @param value - целое число типа NUInt64.
     * @return новое значение типа NUInt64.
     */
    NUInt64 operator <<( const NUInt64 &value ) const noexcept;

    /**
     * @brief operator << - Оператор, реализующий, операцию циклических сдвиг
     * влево на значение value.
     * @param value - целое число стандартного типа uint64_t.
     * @return новое значение типа NUInt64.
     */
    NUInt64 operator <<( uint64_t value ) const noexcept;

    /**
     * @brief operator + - Оператор, возвращающий, сумму чисел типа NUInt64 и
     * типа uint64_t.
     * @param value1 - целое число стандартного типа uint64_t.
     * @param value2 - целое число типа NUInt64.
     * @return сумма чисел типа NUInt64.
     */
    friend NUInt64 operator +( uint64_t value1, const NUInt64 &value2 ) noexcept;

    /**
     * @brief operator - - Оператор, возвращающий, разность чисел типа uint64_t и
     * типа NUInt64.
     * @param value1 - целое число стандартного типа uint64_t.
     * @param value2 - целое число типа NUInt64.
     * @return разность чисел типа NUInt64.
     */
    friend NUInt64 operator -( uint64_t value1, const NUInt64 &value2 ) noexcept;

    /**
     * @brief operator * - Оператор, возвращающий, произведение чисел типа
     * uint64_t и типа NUInt64.
     * @param value1 - целое число стандартного типа uint64_t.
     * @param value2 - целое число типа NUInt64.
     * @return произведения чисел типа NUInt64.
     */
    friend NUInt64 operator *( uint64_t value1, const NUInt64 &value2 ) noexcept;

    /**
     * @brief operator / - Оператор, возвращающий, частнок чисел типа uint64_t и
     * типа NUInt64.
     * @param value1 - целое число стандартного типа uint64_t.
     * @param value2 - целое число типа NUInt64.
     * @return частное чисел типа NUInt64.
     */
    friend NUInt64 operator /( uint64_t value1, const NUInt64 &value2 ) noexcept;

    /**
     * @brief operator % - Оператор, возвращающий, остаток от деления чисел типа
     * uint64_t и типа NUInt64.
     * @param value1 - целое число стандартного типа uint64_t.
     * @param value2 - целое число типа NUInt64.
     * @return остаток от деления чисел тип NUInt64.
     */
    friend NUInt64 operator %( uint64_t value1, const NUInt64 &value2 ) noexcept;

    /**
     * @brief operator != - Оператор, указывающий, не равны ли два заданных
     * значения типа uint64_t и типа NUInt64.
     * @param value1 - целое число стандартного типа uint64_t.
     * @param value2 - целое число типа NUInt64.
     * @return Значение true, если значения не равны в противном случае —
     * значение false.
     */
    friend bool operator !=( uint64_t value1, const NUInt64 &value2 ) noexcept;

    /**
     * @brief operator > - Оператор, указывающий, действительно ли значение типа
     * uint64_t больше значению типа NUInt64.
     * @param value1 - целое число стандартного типа uint64_t.
     * @param value2 - целое число типа NUInt64.
     * @return Значение true, если данного экземпляра больше или равно заданному
     * значению в противном случае — значение false.
     */
    friend bool operator >( uint64_t value1, const NUInt64 &value2 ) noexcept;

    /**
     * @brief operator >= - Оператор, указывающий, действительно ли заданное
     * значение типа uint64_t больше или равно значению типа NUInt64.
     * @param value1 - целое число стандартного типа uint64_t.
     * @param value2 - целое число типа NUInt64.
     * @return  Значение true, если данного экземпляра больше или равно
     * заданному значению в противном случае — значение false.
     */
    friend bool operator >=( uint64_t value1, const NUInt64 &value2 ) noexcept;

    /**
     * @brief operator < - Оператор, указывающий, действительно ли заданное
     * значение типа uint64_t меньше значению типа NUInt64.
     * @param value1 - целое число стандартного типа uint64_t.
     * @param value2 - целое число типа NUInt64.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае — значение false.
     */
    friend bool operator <( uint64_t value1, const NUInt64 &value2 ) noexcept;

    /**
     * @brief operator <= - Оператор, указывающий, действительно ли заданное
     * значение типа uint64_t меньше или равно значению типа NUInt64.
     * @param value1 - целое число стандартного типа uint64_t.
     * @param value2 - целое число типа NUInt64.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае — значение false.
     */
    friend bool operator <=( uint64_t value1, const NUInt64 &value2 ) noexcept;

    /**
     * @brief operator & - Оператор, реализующий, операцию побитовое 'и' двух
     * чисел типа uint64_t и типа NUInt64.
     * @param value1 - целое число стандартного типа uint64_t.
     * @param value2 - целое число типа NUInt64.
     * @return новое значение типа NUInt64.
     */
    friend NUInt64 operator &( uint64_t value1, const NUInt64 &value2 ) noexcept;

    /**
     * @brief operator | - Оператор, реализующий, операцию побитовое 'или' двух
     * чисел типа uint64_t и типа NUInt64.
     * @param value1 - целое число стандартного типа uint64_t.
     * @param value2 - целое число типа NUInt64.
     * @return новое значение типа NUInt64.
     */
    friend NUInt64 operator |( uint64_t value1, const NUInt64 &value2 ) noexcept;

    /**
     * @brief operator ^ - Оператор, реализующий, операцию исключающие 'или'
     * двух чисел uint64_t и типа NUInt64.
     * @param value1 - целое число стандартного типа uint64_t.
     * @param value2 - целое число типа NUInt64.
     * @return новое значение типа NUInt64.
     */
    friend NUInt64 operator ^( uint64_t value1, const NUInt64 &value2 ) noexcept;

    /**
     * @brief operator >> -  Оператор, реализующий, операцию циклических сдвиг
     * вправо значения uint64_t на значение типа NUInt64.
     * @param value1 - целое число стандартного типа uint64_t.
     * @param value2 - целое число типа NUInt64.
     * @return новое значение типа NUInt64.
     */
    friend NUInt64 operator >>( uint64_t value1, const NUInt64 &value2 ) noexcept;

    /**
     * @brief operator << - Оператор, реализующий, операцию циклических сдвиг
     * влево значения uint64_t на значение типа NUInt64.
     * @param value1 - целое число стандартного типа uint64_t.
     * @param value2 - целое число типа NUInt64.
     * @return новое значение типа NUInt64.
     */
    friend NUInt64 operator <<( uint64_t value1, const NUInt64 &value2 ) noexcept;

};

inline NUInt64::NUInt64() noexcept : INInteger<NUInt64, uint64_t>()
{
    this->value_ = 0;
}

inline NUInt64::NUInt64( uint64_t value ) noexcept : INInteger<NUInt64, uint64_t>()
{
    this->value_ = value;
}

inline NUInt64::NUInt64( const NUInt64 &value ) noexcept : INInteger<NUInt64, uint64_t>()
{
    this->value_ = value.value_;
}

inline NUInt64::NUInt64( NUInt64 &&value ) noexcept : INInteger<NUInt64, uint64_t>()
{
    this->value_ = value.value_;
}

inline NUInt64 &NUInt64::operator =( uint64_t value ) noexcept
{
    this->value_ = value;
    return *this;
}

inline NUInt64 &NUInt64::operator =( const NUInt64 &value ) noexcept
{
    this->value_ = value.value_;
    return *this;
}

inline NUInt64 &NUInt64::operator =( NUInt64 &&value ) noexcept
{
    this->value_ = std::move( value.value_ );
    return *this;
}

inline NUInt64 NUInt64::operator +( const NUInt64 &value ) const noexcept
{
    return *this + value.value_;
}

inline NUInt64 NUInt64::operator +( uint64_t value ) const noexcept
{
    return this->sum( this->value_, value, NUInt64::minValue, NUInt64::maxValue );
}

inline NUInt64 NUInt64::operator -( const NUInt64 &value ) const noexcept
{
    return *this - value.value_;
}

inline NUInt64 NUInt64::operator -( uint64_t value ) const noexcept
{
    return this->diff( this->value_, value, NUInt64::minValue,
                       NUInt64::maxValue );
}

inline NUInt64 NUInt64::operator *( const NUInt64 &value ) const noexcept
{
    return *this * value.value_;
}

inline NUInt64 NUInt64::operator *( uint64_t value ) const noexcept
{
    return this->mul( this->value_, value, NUInt64::minValue, NUInt64::maxValue );
}

inline NUInt64 NUInt64::operator /( const NUInt64 &value ) const noexcept
{
    return *this / value.value_;
}

inline NUInt64 NUInt64::operator /( uint64_t value ) const noexcept
{
    return this->div( this->value_, value, NUInt64::minValue, NUInt64::maxValue );
}

inline NUInt64 NUInt64::operator %( const NUInt64 &value ) const noexcept
{
    return *this % value.value_;
}

inline NUInt64 NUInt64::operator %( uint64_t value ) const noexcept
{
    if( value != 0 )
        return NUInt64( this->value_ % value );
    std::wcerr << "Error! 0 divide! value1 = " << this->value_
               << " and value2 = " << value << std::endl;
    return *this;
}

inline NUInt64 &NUInt64::operator +=( const NUInt64 &value ) noexcept
{
    *this += value.value_;
    return *this;
}

inline NUInt64 &NUInt64::operator +=( uint64_t value ) noexcept
{
    this->value_ += value;
    return *this;
}

inline NUInt64 &NUInt64::operator -=( const NUInt64 &value ) noexcept
{
    *this -= value.value_;
    return *this;
}

inline NUInt64 &NUInt64::operator -=( uint64_t value ) noexcept
{
    this->value_ -= value;
    return *this;
}

inline NUInt64 &NUInt64::operator *=( const NUInt64 &value ) noexcept
{
    *this *= value.value_;
    return *this;
}

inline NUInt64 &NUInt64::operator *=( uint64_t value ) noexcept
{
    this->value_ *= value;
    return *this;
}

inline NUInt64 &NUInt64::operator /=( const NUInt64 &value ) noexcept
{
    *this /= value.value_;
    return *this;
}

inline NUInt64 &NUInt64::operator /=( uint64_t value ) noexcept
{
    this->value_ /= value;
    return *this;
}


inline NUInt64 &NUInt64::operator++() noexcept
{
    if( NUInt64::maxValue == this->value_ )
        std::wcerr << "Error! Overflow! this->value_ = "
                   << this->value_ << std::endl;
    else
        ++this->value_;
    return *this;
}

inline NUInt64 NUInt64::operator++(int) noexcept
{
    NUInt64 v = *this;
    if( v == NUInt64::maxValue )
        std::wcerr << "Error! Overflow! this->value_ = "
                   << this->value_ << std::endl;
    else
        ++(*this);
    return v;
}

inline NUInt64 &NUInt64::operator--() noexcept
{
    if( NUInt64::minValue == this->value_  )
        std::wcerr << "Error! Overflow! this->value_ = "
                   << this->value_ << std::endl;
    else
        --this->value_;
    return *this;
}

inline NUInt64 NUInt64::operator--(int) noexcept
{
    NUInt64 v = *this;
    if( v == NUInt64::minValue )
        std::wcerr << "Error! Overflow! this->value_ = "
                   << this->value_ << std::endl;
    else
        --(*this);
    return v;
}

inline bool NUInt64::operator ==( const NUInt64 &value ) const noexcept
{
    return ( *this == value.value_ );
}

inline bool NUInt64::operator ==( uint64_t value ) const noexcept
{
    return ( this->value_ == value );
}

inline bool NUInt64::operator !=( const NUInt64 &value ) const noexcept
{
    return ( *this != value.value_ );
}

inline bool NUInt64::operator !=( uint64_t value ) const noexcept
{
    return ( this->value_ != value );
}

inline bool NUInt64::operator >( const NUInt64 &value ) const noexcept
{
    return ( *this > value.value_ );
}

inline bool NUInt64::operator >( uint64_t value ) const noexcept
{
    return ( this->value_ > value );
}

inline bool NUInt64::operator >=( const NUInt64 &value ) const noexcept
{
    return ( *this >= value.value_ );
}

inline bool NUInt64::operator >=( uint64_t value ) const noexcept
{
    return ( this->value_ >= value );
}

inline bool NUInt64::operator <( const NUInt64 &value ) const noexcept
{
    return ( *this < value.value_ );
}

inline bool NUInt64::operator <( uint64_t value ) const noexcept
{
    return ( this->value_ < value );
}

inline bool NUInt64::operator <=( const NUInt64 &value ) const noexcept
{
    return ( *this <= value.value_ );
}

inline bool NUInt64::operator <=( uint64_t value ) const noexcept
{
    return ( this->value_ <= value );
}

inline NUInt64 NUInt64::operator &( const NUInt64 &value ) const noexcept
{
    return *this & value.value_;
}

inline NUInt64 NUInt64::operator &( uint64_t value ) const noexcept
{
    return NUInt64( this->value_ & value );
}

inline NUInt64 NUInt64::operator |( const NUInt64 &value ) const noexcept
{
    return *this | value.value_;
}

inline NUInt64 NUInt64::operator |( uint64_t value ) const noexcept
{
    return NUInt64( this->value_ | value );
}

inline NUInt64 NUInt64::operator ^( const NUInt64 &value ) const noexcept
{
    return *this ^ value.value_;
}

inline NUInt64 NUInt64::operator ^( uint64_t value ) const noexcept
{
    return NUInt64( this->value_ ^ value );
}

inline NUInt64 &NUInt64::operator &=( const NUInt64 &value ) noexcept
{
    *this &= value.value_;
    return *this;
}

inline NUInt64 &NUInt64::operator &=( uint64_t value ) noexcept
{
    this->value_ &= value;
    return *this;
}

inline NUInt64 &NUInt64::operator |=( const NUInt64 &value ) noexcept
{
    *this |= value.value_;
    return *this;
}

inline NUInt64 &NUInt64::operator |=( uint64_t value ) noexcept
{
    this->value_ |= value;
    return *this;
}

inline NUInt64 &NUInt64::operator ^=( const NUInt64 &value ) noexcept
{
    *this ^= value.value_;
    return *this;
}

inline NUInt64 &NUInt64::operator ^=( uint64_t value ) noexcept
{
    this->value_ ^= value;
    return *this;
}

inline NUInt64 NUInt64::operator >>( const NUInt64 &value ) const noexcept
{
    return *this >> value.value_;
}

inline NUInt64 NUInt64::operator >>( uint64_t value ) const noexcept
{
    return NUInt64( this->value_ >> value );
}

inline NUInt64 NUInt64::operator <<( const NUInt64 &value ) const noexcept
{
    return *this << value.value_;
}

inline NUInt64 NUInt64::operator <<( uint64_t value ) const noexcept
{
    return NUInt64( this->value_ << value );
}

inline NUInt64 operator +( uint64_t value1, const NUInt64 &value2 ) noexcept
{
    return value2 + value1;
}

inline NUInt64 operator -( uint64_t value1, const NUInt64 &value2 ) noexcept
{
    return NUInt64( value1 ) + value2;
}

inline NUInt64 operator *( uint64_t value1, const NUInt64 &value2 ) noexcept
{
    return value2 * value1;
}

inline NUInt64 operator /( uint64_t value1, const NUInt64 &value2 ) noexcept
{
    return NUInt64( value1 ) / value2;
}

inline NUInt64 operator %( uint64_t value1, const NUInt64 &value2 ) noexcept
{
    return NUInt64( value1 ) % value2;
}

inline bool operator !=( uint64_t value1, const NUInt64 &value2 ) noexcept
{
    return value2 != value1;
}

inline bool operator >( uint64_t value1, const NUInt64 &value2 ) noexcept
{
    return value2 < value1;
}

inline bool operator >=( uint64_t value1, const NUInt64 &value2 ) noexcept
{
    return value2 <= value1;
}

inline bool operator <( uint64_t value1, const NUInt64 &value2 ) noexcept
{
    return value2 > value1;
}

inline bool operator <=( uint64_t value1, const NUInt64 &value2 ) noexcept
{
    return value2 >= value1;
}

inline NUInt64 operator &( uint64_t value1, const NUInt64 &value2 ) noexcept
{
    return NUInt64( value1 ) & value2;
}

inline NUInt64 operator |( uint64_t value1, const NUInt64 &value2 ) noexcept
{
    return NUInt64( value1 ) | value2;
}

inline NUInt64 operator ^( uint64_t value1, const NUInt64 &value2 ) noexcept
{
    return NUInt64( value1 ) ^ value2;
}

inline NUInt64 operator >>( uint64_t value1, const NUInt64 &value2 ) noexcept
{
    return NUInt64( value1 ) >> value2;
}

inline NUInt64 operator <<( uint64_t value1, const NUInt64 &value2 ) noexcept
{
    return NUInt64( value1 ) << value2;
}

#endif // NUINT64_H
