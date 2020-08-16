#ifndef NUINT32_H
#define NUINT32_H

#include "ininteger.h"
#include <QDebug>

class NUInt32 : public INInteger<NUInt32, uint32_t>
{
public:
    /**
     * @brief minValue - Представляет минимально допустимое значение типа .
     * NUInt32.
     */
    const static NUInt32 minValue;
    /**
     * @brief maxValue - Представляет наибольшее возможное значение типа NUInt32.
     */
    const static NUInt32 maxValue;

    /** \brief NUInt32 - Инициализирует новый экземпляр класса целого числа со
     * значением 0.
     */
    NUInt32() noexcept;

    /**
     * @brief NUInt32 - Инициализирует новый экземпляр класса целого числа с
     * заданым значением.
     * @param value - целое число стандартного типа uint32_t.
     */
    NUInt32( uint32_t value ) noexcept;

    /**
     * @brief NUInt32 - Инициализирует новый экземпляр класса целого числа с
     * заданым значением.
     * @param value - целое число типа NUInt32.
     */
    NUInt32( const NUInt32 &value ) noexcept;

    /**
     * @brief NUInt32 - Инициализирует новый экземпляр класса целого числа с
     * заданым значением, реализующий семантику перемещения.
     * @param value - целое число типа NUInt32.
     */
    NUInt32( NUInt32 &&value ) noexcept;

    ~NUInt32() noexcept{}

    /**
     * @brief operator = - Оператор, позволяющий, присвоить значения
     * стандартного типа uint32_t к данному экземпляру.
     * @param value - целое число стандартного типа uint32_t.
     * @return экземпляр класса с новым значением.
     */
    NUInt32 &operator =( uint32_t value ) noexcept;

    /**
     * @brief operator = - Оператор, позволяющий, присвоить значения
     * стандартного типа uint32_t к данному экземпляру.
     * @param value - целое число типа NUInt32.
     * @return экземпляр класса с новым значением.
     */
    NUInt32 &operator =( const NUInt32 &value ) noexcept;

    /**
     * @brief operator = - Оператор, позволяющий, присвоить значения
     * стандартного типа uint32_t к данному экземпляру, реализующий семантику
     * перемещения.
     * @param value - целое число типа NUInt32.
     * @return экземпляр класса с новым значением.
     */
    NUInt32 &operator =( NUInt32 &&value ) noexcept;

    /**
     * @brief operator + -  Оператор, возвращающий, сумму чисел значений NUInt32.
     * @param value - целое число типа NUInt32.
     * @return сумма чисел типа NUInt32.
     */
    NUInt32 operator +( const NUInt32 &value ) const noexcept;

    /**
     * @brief operator + - Оператор, возвращающий, сумму чисел значений данного
     * экземпляра и заданого числа стандартного типа uint32_t.
     * @param value - целое число стандартного типа uint32_t.
     * @return сумма чисел типа NUInt32.
     */
    NUInt32 operator +( uint32_t value ) const noexcept;

    /**
     * @brief operator - Оператор, возвращающий, разность чисел значений NUInt32.
     * @param value - целое число типа NUInt32.
     * @return разность чисел типа NUInt32.
     */
    NUInt32 operator -( const NUInt32 &value ) const noexcept;

    /**
     * @brief operator - - Оператор, возвращающий, разность чисел значений
     * данного экземпляра и заданого числа стандартного типа uint32_t.
     * @param value - целое число стандартного типа uint32_t.
     * @return разность чисел типа NUInt32.
     */
    NUInt32 operator -( uint32_t value ) const noexcept;

    /**
     * @brief operator * - Оператор, возвращающий, произведения чисел значений
     * NUInt32.
     * @param value - целое число типа NUInt32.
     * @return произведения чисел типа NUInt32.
     */
    NUInt32 operator *( const NUInt32 &value ) const noexcept;

    /**
     * @brief operator * - Оператор, возвращающий, произведение чисел значений
     * данного экземпляра и заданого числа стандартного типа uint32_t.
     * @param value - целое число стандартного типа uint32_t.
     * @return произведения чисел типа NUInt32.
     */
    NUInt32 operator *( uint32_t value ) const noexcept;

    /**
     * @brief operator / - Оператор, возвращающий, частное чисел значений
     * NUInt32.
     * @param value - целое число типа NUInt32.
     * @return частное чисел типа NUInt32.
     */
    NUInt32 operator /( const NUInt32 &value ) const noexcept;

    /**
     * @brief operator / - Оператор, возвращающий, частнок чисел значений
     * данного экземпляра и заданого числа.
     * @param value - целое число стандартного типа uint32_t.
     * @return частное чисел типа NUInt32.
     */
    NUInt32 operator /( uint32_t value ) const noexcept;

    /**
     * @brief operator % - Оператор, возвращающий, остаток от деления на число
     * типа NUInt32.
     * @param value - целое число типа NUInt32.
     * @return частное чисел типа NUInt32.
     */
    NUInt32 operator %( const NUInt32 &value ) const noexcept;

    /**
     * @brief operator % - Оператор, возвращающий, остаток от деления на число
     * стандартного типа uint32_t.
     * @param value - целое число стандартного типа uint32_t.
     * @return частное чисел типа NUInt32.
     */
    NUInt32 operator %( uint32_t value ) const noexcept;

    /**
     * @brief operator += - Оператор, позволяющий вернуть, результат операции
     * '+=' двух чисел типа NUInt32, конечный результат присваивается экземпляру
     * класса.
     * @param value - целое число типа NUInt32.
     * @return экземпляр класса с новым значением.
     */
    NUInt32 &operator +=( const NUInt32 &value ) noexcept;

    /**
     * @brief operator += - Оператор, позволяющий вернуть, результат операции
     * '+=' двух чисел данного экземпляра и числом стандартного типа uint32_t,
     * конечный результат присваивается экземпляру класса.
     * @param value - целое число стандартного типа uint32_t.
     * @return экземпляр класса с новым значением.
     */
    NUInt32 &operator +=( uint32_t value ) noexcept;

    /**
     * @brief operator -= - Оператор, позволяющий вернуть, результат операции
     * '-=' двух чисел типа NUInt32 и, конечный результат присваивается
     * экземпляру класса.
     * @param value - целое число типа NUInt32.
     * @return экземпляр класса с новым значением.
     */
    NUInt32 &operator -=( const NUInt32 &value ) noexcept;

    /**
     * @brief operator -= - Оператор, позволяющий вернуть, результат операции
     * '-=' двух чисел данного экземпляра и числом стандартного типа uint32_t,
     * конечный результат присваивается экземпляру класса.
     * @param value - целое число стандартного типа uint32_t.
     * @return экземпляр класса с новым значением.
     */
    NUInt32 &operator -=( uint32_t value ) noexcept;

    /**
     * @brief operator *= - Оператор, позволяющий вернуть, результат операции
     * '*=' двух чисел типа NUInt32, конечный результат присваивается экземпляру
     * класса.
     * @param value - целое число типа NUInt32.
     * @return экземпляр класса с новым значением.
     */
    NUInt32 &operator *=( const NUInt32 &value ) noexcept;

    /**
     * @brief operator *= - Оператор, позволяющий вернуть, результат операции
     * '*=' двух чисел данного экземпляра и числом стандартного типа uint32_t,
     * конечный результат присваивается экземпляру класса.
     * @param value - целое число стандартного типа uint32_t.
     * @return экземпляр класса с новым значением.
     */
    NUInt32 &operator *=( uint32_t value ) noexcept;

    /**
     * @brief operator /= - Оператор, позволяющий вернуть, результат операции
     * '/=' двух чисел типа NUInt32, конечный результат присваивается экземпляру
     * класса.
     * @param value - целое число типа NUInt32.
     * @return экземпляр класса с новым значением.
     */
    NUInt32 &operator /=( const NUInt32 &value ) noexcept;

    /**
     * @brief operator /= - Оператор, позволяющий вернуть, результат операции
     * '/=' двух чисел данного экземпляра и числом стандартного типа uint32_t,
     * конечный результат присваивается экземпляру класса.
     * @param value - целое число стандартного типа uint32_t.
     * @return экземпляр класса с новым значением.
     */
    NUInt32 &operator /=( uint32_t value ) noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса
     * на 1.
     * @return экземпляр класса с новым значением.
     */
    NUInt32 &operator++() noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса на
     * 1 и возвращающие старое значение.
     * @return  экземпляр класса со старым значением.
     */
    NUInt32 operator++(int) noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1.
     * @return экземпляр класса с новым значением.
     */
    NUInt32 &operator--() noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1
     * и возвращающие старое значение.
     * @return экземпляр класса со старыи значением.
     */
    NUInt32 operator--(int) noexcept;

    /**
     * @brief operator == - Оператор, указывающий, равны ли два заданных
     * значения типа NUInt32.
     * @param value - целое число типа NUInt32.
     * @return Значение true, если значения равны в противном случае —
     * значение false.
     */
    bool operator ==( const NUInt32 &value ) const noexcept;

    /**
     * @brief operator == - Оператор, указывающий, равны ли два заданных
     * значения данного экземпляра и число стандартного типа uint32_t.
     * @param value - целое число стандартного типа uint32_t.
     * @return Значение true, если значения равны в противном случае — значение
     * false.
     */
    bool operator ==( uint32_t value ) const noexcept;

    /**
     * @brief operator != - Оператор, указывающий, не равны ли два заданных
     * значения типа NUInt32.
     * @param value - целое число типа NUInt32.
     * @return Значение true, если значения не равны в противном случае —
     * значение false.
     */
    bool operator !=( const NUInt32 &value ) const noexcept;

    /**
     * @brief operator != - Оператор, указывающий, не равны ли заданных значения
     * данного экземпляра и число стандартного типа uint32_t.
     * @param value - целое число стандартного типа uint32_t.
     * @return Значение true, если значения не равны в противном случае —
     * значение false.
     */
    bool operator !=( uint32_t value ) const noexcept;

    /**
     * @brief operator > - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра больше заданному значению типа NUInt32.
     * @param value - целое число типа NUInt32.
     * @return Значение true, если данного экземпляра больше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator >( const NUInt32 &value ) const noexcept;

    /**
     * @brief operator > - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра больше заданному значению стандартного типа
     * uint32_t.
     * @param value - целое число стандартного типа uint32_t.
     * @return Значение true, если данного экземпляра больше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator >( uint32_t value ) const noexcept;

    /**
     * @brief operator >= - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра больше или равно заданному значению типа
     * NUInt32.
     * @param value - целое число типа NUInt32.
     * @return  Значение true, если данного экземпляра больше или равно
     * заданному значению в противном случае — значение false.
     */
    bool operator >=( const NUInt32 &value ) const noexcept;

    /**
     * @brief operator >= - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра больше или равно заданному значению
     * стандартного типа uint32_t.
     * @param value - число двойной точности с плавающей запятой стандартного типа uint32_t.
     * @return Значение true, если данного экземпляра больше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator >=( uint32_t value ) const noexcept;

    /**
     * @brief operator < - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра меньше заданному значению типа NUInt32.
     * @param value - целое число типа NUInt32.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator <( const NUInt32 &value ) const noexcept;

    /**
     * @brief operator < - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра меньше заданному значению стандартного типа
     * uint32_t.
     * @param value - целое число стандартного типа uint32_t.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator <( uint32_t value ) const noexcept;

    /**
     * @brief operator <= - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра меньше или равно заданному значению типа
     * NUInt32.
     * @param value - целое число типа NUInt32.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     *  значению в противном случае — значение false.
     */
    bool operator <=( const NUInt32 &value ) const noexcept;

    /**
     * @brief operator <= - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра меньше или равно заданному значению
     * стандартного типа uint32_t.
     * @param value - целое число стандартного типа uint32_t.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator <=( uint32_t value ) const noexcept;

    /**
     * @brief operator & - Оператор, реализующий, операцию побитовое 'и' двух
     * чисел типа NUInt32.
     * @param value - целое число типа NUInt32.
     * @return новое значение типа NUInt32.
     */
    NUInt32 operator &( const NUInt32 &value ) const noexcept;

    /**
     * @brief operator & - Оператор, реализующий, операцию побитовое 'и' двух
     * чисел типа NUInt32.
     * @param value - целое число стандартного типа uint32_t.
     * @return новое значение типа NUInt32.
     */
    NUInt32 operator &( uint32_t value ) const noexcept;

    /**
     * @brief operator | - Оператор, реализующий, операцию побитовое 'или' двух
     * чисел типа NUInt32.
     * @param value - целое число типа NUInt32.
     * @return новое значение типа NUInt32.
     */
    NUInt32 operator |( const NUInt32 &value ) const noexcept;

    /**
     * @brief operator | - Оператор, реализующий, операцию побитовое 'или'
     * заданного класса и числа стандарного типа uint32_t.
     * @param value - целое число стандартного типа uint32_t.
     * @return новое значение типа NUInt32.
     */
    NUInt32 operator |( uint32_t value ) const noexcept;

    /**
     * @brief operator ^ - Оператор, реализующий, операцию исключающие 'или'
     * двух чисел типа NUInt32.
     * @param value - целое число типа NUInt32.
     * @return новое значение типа NUInt32.
     */
    NUInt32 operator ^( const NUInt32 &value ) const noexcept;

    /**
     * @brief operator ^ -  Оператор, реализующий, операцию исключающие 'или'
     * заданного класса и числа стандарного типа uint32_t.
     * @param value - целое число стандартного типа uint32_t.
     * @return новое значение типа NUInt32.
     */
    NUInt32 operator ^( uint32_t value ) const noexcept;

    /**
     * @brief operator &= - Оператор, реализующий, операцию побитовое 'и' двух
     * чисел типа NUInt32, результат сохраняется в экземпляре класса.
     * @param value - целое число типа NUInt32.
     * @return новое значение типа NUInt32.
     */
    NUInt32 &operator &=( const NUInt32 &value ) noexcept;

    /**
     * @brief operator &= - Оператор, реализующий, операцию побитовое 'и'
     * заданного класса и числа стандарного типа uint32_t, результат сохраняется
     * в экземпляре класса.
     * @param value - целое число стандартного типа uint32_t.
     * @return новое значение типа NUInt32.
     */
    NUInt32 &operator &=( uint32_t value ) noexcept;

    /**
     * @brief operator |= - Оператор, реализующий, операцию побитовое 'или' двух
     * чисел типа NUInt32 результат сохраняется в экземпляре класса.
     * @param value - целое число типа NUInt32.
     * @return новое значение типа NUInt32.
     */
    NUInt32 &operator |=( const NUInt32 &value ) noexcept;

    /**
     * @brief operator |= - Оператор, реализующий, операцию побитовое 'или'
     * заданного класса и числа стандарного типа uint32_t, результат сохраняется
     * в экземпляре класса.
     * @param value - целое число стандартного типа uint32_t.
     * @return новое значение типа NUInt32.
     */
    NUInt32 &operator |=( uint32_t value ) noexcept;

    /**
     * @brief operator ^= - Оператор, реализующий, операцию исключающие 'или'
     * двух чисел типа NUInt32, результат сохраняется в экземпляре класса.
     * @param value - целое число типа NUInt32.
     * @return новое значение типа NUInt32.
     */
    NUInt32 &operator ^=( const NUInt32 &value ) noexcept;

    /**
     * @brief operator ^= -  Оператор, реализующий, операцию исключающие 'или'
     * заданного класса и числа стандарного типа uint32_t, результат сохраняется
     * в экземпляре класса.
     * @param value - целое число стандартного типа uint32_t.
     * @return новое значение типа NUInt32.
     */
    NUInt32 &operator ^=( uint32_t value ) noexcept;

    /**
     * @brief operator >> -  Оператор, реализующий, операцию циклических сдвиг
     * вправо на значение value.
     * @param value - целое число типа NUInt32.
     * @return новое значение типа NUInt32.
     */
    NUInt32 operator >>( const NUInt32 &value ) const noexcept;

    /**
     * @brief operator >> -  Оператор, реализующий, операцию циклических сдвиг
     * вправо на значение value.
     * @param value - целое число стандартного типа uint32_t.
     * @return новое значение типа NUInt32.
     */
    NUInt32 operator >>( uint32_t value ) const noexcept;

    /**
     * @brief operator << - Оператор, реализующий, операцию циклических сдвиг
     * влево на значение value.
     * @param value - целое число типа NUInt32.
     * @return новое значение типа NUInt32.
     */
    NUInt32 operator <<( const NUInt32 &value ) const noexcept;

    /**
     * @brief operator << - Оператор, реализующий, операцию циклических сдвиг
     * влево на значение value.
     * @param value - целое число стандартного типа uint32_t.
     * @return новое значение типа NUInt32.
     */
    NUInt32 operator <<( uint32_t value ) const noexcept;

    /**
     * @brief operator + - Оператор, возвращающий, сумму чисел типа NUInt32 и
     * типа uint32_t.
     * @param value1 - целое число стандартного типа uint32_t.
     * @param value2 - целое число типа NUInt32.
     * @return сумма чисел типа NUInt32.
     */
    friend NUInt32 operator +( uint32_t value1, const NUInt32 &value2 ) noexcept;

    /**
     * @brief operator - - Оператор, возвращающий, разность чисел типа uint32_t и
     * типа NUInt32.
     * @param value1 - целое число стандартного типа uint32_t.
     * @param value2 - целое число типа NUInt32.
     * @return разность чисел типа NUInt32.
     */
    friend NUInt32 operator -( uint32_t value1, const NUInt32 &value2 ) noexcept;

    /**
     * @brief operator * - Оператор, возвращающий, произведение чисел типа
     * uint32_t и типа NUInt32.
     * @param value1 - целое число стандартного типа uint32_t.
     * @param value2 - целое число типа NUInt32.
     * @return произведения чисел типа NUInt32.
     */
    friend NUInt32 operator *( uint32_t value1, const NUInt32 &value2 ) noexcept;

    /**
     * @brief operator / - Оператор, возвращающий, частнок чисел типа uint32_t и
     * типа NUInt32.
     * @param value1 - целое число стандартного типа uint32_t.
     * @param value2 - целое число типа NUInt32.
     * @return частное чисел типа NUInt32.
     */
    friend NUInt32 operator /( uint32_t value1, const NUInt32 &value2 ) noexcept;

    /**
     * @brief operator % - Оператор, возвращающий, остаток от деления чисел типа
     * uint32_t и типа NUInt32.
     * @param value1 - целое число стандартного типа uint32_t.
     * @param value2 - целое число типа NUInt32.
     * @return остаток от деления чисел тип NUInt32.
     */
    friend NUInt32 operator %( uint32_t value1, const NUInt32 &value2 ) noexcept;

    /**
     * @brief operator != - Оператор, указывающий, не равны ли два заданных
     * значения типа uint32_t и типа NUInt32.
     * @param value1 - целое число стандартного типа uint32_t.
     * @param value2 - целое число типа NUInt32.
     * @return Значение true, если значения не равны в противном случае —
     * значение false.
     */
    friend bool operator !=( uint32_t value1, const NUInt32 &value2 ) noexcept;

    /**
     * @brief operator > - Оператор, указывающий, действительно ли значение типа
     * uint32_t больше значению типа NUInt32.
     * @param value1 - целое число стандартного типа uint32_t.
     * @param value2 - целое число типа NUInt32.
     * @return Значение true, если данного экземпляра больше или равно заданному
     * значению в противном случае — значение false.
     */
    friend bool operator >( uint32_t value1, const NUInt32 &value2 ) noexcept;

    /**
     * @brief operator >= - Оператор, указывающий, действительно ли заданное
     * значение типа uint32_t больше или равно значению типа NUInt32.
     * @param value1 - целое число стандартного типа uint32_t.
     * @param value2 - целое число типа NUInt32.
     * @return  Значение true, если данного экземпляра больше или равно
     * заданному значению в противном случае — значение false.
     */
    friend bool operator >=( uint32_t value1, const NUInt32 &value2 ) noexcept;

    /**
     * @brief operator < - Оператор, указывающий, действительно ли заданное
     * значение типа uint32_t меньше значению типа NUInt32.
     * @param value1 - целое число стандартного типа uint32_t.
     * @param value2 - целое число типа NUInt32.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае — значение false.
     */
    friend bool operator <( uint32_t value1, const NUInt32 &value2 ) noexcept;

    /**
     * @brief operator <= - Оператор, указывающий, действительно ли заданное
     * значение типа uint32_t меньше или равно значению типа NUInt32.
     * @param value1 - целое число стандартного типа uint32_t.
     * @param value2 - целое число типа NUInt32.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае — значение false.
     */
    friend bool operator <=( uint32_t value1, const NUInt32 &value2 ) noexcept;

    /**
     * @brief operator & - Оператор, реализующий, операцию побитовое 'и' двух
     * чисел типа uint32_t и типа NUInt32.
     * @param value1 - целое число стандартного типа uint32_t.
     * @param value2 - целое число типа NUInt32.
     * @return новое значение типа NUInt32.
     */
    friend NUInt32 operator &( uint32_t value1, const NUInt32 &value2 ) noexcept;

    /**
     * @brief operator | - Оператор, реализующий, операцию побитовое 'или' двух
     * чисел типа uint32_t и типа NUInt32.
     * @param value1 - целое число стандартного типа uint32_t.
     * @param value2 - целое число типа NUInt32.
     * @return новое значение типа NUInt32.
     */
    friend NUInt32 operator |( uint32_t value1, const NUInt32 &value2 ) noexcept;

    /**
     * @brief operator ^ - Оператор, реализующий, операцию исключающие 'или'
     * двух чисел uint32_t и типа NUInt32.
     * @param value1 - целое число стандартного типа uint32_t.
     * @param value2 - целое число типа NUInt32.
     * @return новое значение типа NUInt32.
     */
    friend NUInt32 operator ^( uint32_t value1, const NUInt32 &value2 ) noexcept;

    /**
     * @brief operator >> -  Оператор, реализующий, операцию циклических сдвиг
     * вправо значения uint32_t на значение типа NUInt32.
     * @param value1 - целое число стандартного типа uint32_t.
     * @param value2 - целое число типа NUInt32.
     * @return новое значение типа NUInt32.
     */
    friend NUInt32 operator >>( uint32_t value1, const NUInt32 &value2 ) noexcept;

    /**
     * @brief operator << - Оператор, реализующий, операцию циклических сдвиг
     * влево значения uint32_t на значение типа NUInt32.
     * @param value1 - целое число стандартного типа uint32_t.
     * @param value2 - целое число типа NUInt32.
     * @return новое значение типа NUInt32.
     */
    friend NUInt32 operator <<( uint32_t value1, const NUInt32 &value2 ) noexcept;

};

inline NUInt32::NUInt32() noexcept : INInteger<NUInt32, uint32_t>()
{
    this->value_ = 0;
}

inline NUInt32::NUInt32( uint32_t value ) noexcept : INInteger<NUInt32, uint32_t>()
{
    this->value_ = value;
}

inline NUInt32::NUInt32( const NUInt32 &value ) noexcept : INInteger<NUInt32, uint32_t>()
{
    this->value_ = value.value_;
}

inline NUInt32::NUInt32( NUInt32 &&value ) noexcept : INInteger<NUInt32, uint32_t>()
{
    this->value_ = value.value_;
}

inline NUInt32 &NUInt32::operator =( uint32_t value ) noexcept
{
    this->value_ = value;
    return *this;
}

inline NUInt32 &NUInt32::operator =( const NUInt32 &value ) noexcept
{
    this->value_ = value.value_;
    return *this;
}

inline NUInt32 &NUInt32::operator =( NUInt32 &&value ) noexcept
{
    this->value_ = std::move( value.value_ );
    return *this;
}

inline NUInt32 NUInt32::operator +( const NUInt32 &value ) const noexcept
{
    return *this + value.value_;
}

inline NUInt32 NUInt32::operator +( uint32_t value ) const noexcept
{
    return this->sum( this->value_, value, NUInt32::minValue,
                      NUInt32::maxValue );
}

inline NUInt32 NUInt32::operator -( const NUInt32 &value ) const noexcept
{
    NUInt32 v = *this - value.value_;
    return v;
}

inline NUInt32 NUInt32::operator -( uint32_t value ) const noexcept
{
    return this->diff( this->value_, value, NUInt32::minValue,
                       NUInt32::maxValue );
}

inline NUInt32 NUInt32::operator *( const NUInt32 &value ) const noexcept
{
    return *this * value.value_;
}

inline NUInt32 NUInt32::operator *( uint32_t value ) const noexcept
{
    return this->mul( this->value_, value, NUInt32::minValue, NUInt32::maxValue );
}

inline NUInt32 NUInt32::operator /( const NUInt32 &value ) const noexcept
{
    return *this / value.value_;
}

inline NUInt32 NUInt32::operator /( uint32_t value ) const noexcept
{
    return this->div( this->value_, value, NUInt32::minValue, NUInt32::maxValue );
}

inline NUInt32 NUInt32::operator %( const NUInt32 &value ) const noexcept
{
    return *this % value.value_;
}

inline NUInt32 NUInt32::operator %( uint32_t value ) const noexcept
{
    if( value != 0 )
    {
        NUInt32 _r( this->value_ % value );
        return _r;
    }
    std::wcerr << "Error! 0 divide! value1 = " << this->value_
               << " and value2 = " << value << std::endl;
    return *this;
}

inline NUInt32 &NUInt32::operator +=( uint32_t value ) noexcept
{
    this->value_ += value;
    return *this;
}

inline NUInt32 &NUInt32::operator +=( const NUInt32 &value ) noexcept
{
    *this += value.value_;
    return *this;
}

inline NUInt32 &NUInt32::operator -=( uint32_t value ) noexcept
{
    this->value_ -= value;
    return *this;
}

inline NUInt32 &NUInt32::operator -=( const NUInt32 &value ) noexcept
{
    *this -= value.value_;
    return *this;
}

inline NUInt32 &NUInt32::operator *=( uint32_t value ) noexcept
{
    this->value_ *= value;
    return *this;
}

inline NUInt32 &NUInt32::operator *=( const NUInt32 &value ) noexcept
{
    *this *= value.value_;
    return *this;
}

inline NUInt32 &NUInt32::operator /=( const NUInt32 &value ) noexcept
{
    *this /= value.value_;
    return *this;
}

inline NUInt32 &NUInt32::operator /=( uint32_t value ) noexcept
{
    this->value_ /= value;
    return *this;
}


inline NUInt32 &NUInt32::operator++() noexcept
{
    if( NUInt32::maxValue == this->value_ )
        std::wcerr << "Error! Overflow! this->value_ = "
                   << this->value_ << std::endl;
    else
        ++this->value_;
    return *this;
}

inline NUInt32 NUInt32::operator++(int) noexcept
{
    NUInt32 v = *this;
    if( v == NUInt32::maxValue )
        std::wcerr << "Error! Overflow! this->value_ = "
                   << this->value_ << std::endl;
    else
        ++(*this);
    return v;
}

inline NUInt32 &NUInt32::operator--() noexcept
{
    if( NUInt32::minValue == this->value_ )
        std::wcerr << "Error! Overflow! this->value_ = "
                   << this->value_ << std::endl;
    else
        --this->value_;
    return *this;
}

inline NUInt32 NUInt32::operator--(int) noexcept
{
    NUInt32 v = *this;
    if( v == NUInt32::minValue )
        std::wcerr << "Error! Overflow! this->value_ = "
                   << this->value_ << std::endl;
    else
        --(*this);
    return v;
}

inline bool NUInt32::operator ==( const NUInt32 &value ) const noexcept
{
    return ( *this == value.value_ );
}

inline bool NUInt32::operator ==( uint32_t value ) const noexcept
{
    return ( this->value_ == value );
}

inline bool NUInt32::operator !=( const NUInt32 &value ) const noexcept
{
    return ( *this != value.value_ );
}

inline bool NUInt32::operator !=( uint32_t value ) const noexcept
{
    return ( this->value_ != value );
}

inline bool NUInt32::operator >( const NUInt32 &value ) const noexcept
{
    return ( *this > value.value_ );
}

inline bool NUInt32::operator >( uint32_t value ) const noexcept
{
    return ( this->value_ > value );
}

inline bool NUInt32::operator >=( const NUInt32 &value ) const noexcept
{
    return ( *this >= value.value_ );
}

inline bool NUInt32::operator >=( uint32_t value ) const noexcept
{
    return ( this->value_ >= value );
}

inline bool NUInt32::operator <( const NUInt32 &value ) const noexcept
{
    return ( *this < value.value_ );
}

inline bool NUInt32::operator <( uint32_t value ) const noexcept
{
    return ( this->value_ < value );
}

inline bool NUInt32::operator <=( const NUInt32 &value ) const noexcept
{
    return ( *this <= value.value_ );
}

inline bool NUInt32::operator <=( uint32_t value ) const noexcept
{
    return ( this->value_ <= value );
}

inline NUInt32 NUInt32::operator &( const NUInt32 &value ) const noexcept
{
    return *this & value.value_;
}

inline NUInt32 NUInt32::operator &( uint32_t value ) const noexcept
{
    return NUInt32( this->value_ & value );
}

inline NUInt32 NUInt32::operator |( const NUInt32 &value ) const noexcept
{
    return *this | value.value_;
}

inline NUInt32 NUInt32::operator |( uint32_t value ) const noexcept
{
    return NUInt32( this->value_ | value );
}

inline NUInt32 NUInt32::operator ^( const NUInt32 &value ) const noexcept
{
    return *this ^ value.value_;
}

inline NUInt32 NUInt32::operator ^( uint32_t value ) const noexcept
{
    return NUInt32( this->value_ ^ value );
}

inline NUInt32 &NUInt32::operator &=( const NUInt32 &value ) noexcept
{
    *this &= value.value_;
    return *this;
}

inline NUInt32 &NUInt32::operator &=( uint32_t value ) noexcept
{
    this->value_ &= value;
    return *this;
}

inline NUInt32 &NUInt32::operator |=( const NUInt32 &value ) noexcept
{
    *this |= value.value_;
    return *this;
}

inline NUInt32 &NUInt32::operator |=( uint32_t value ) noexcept
{
    this->value_ |= value;
    return *this;
}

inline NUInt32 &NUInt32::operator ^=( const NUInt32 &value ) noexcept
{
    *this ^= value.value_;
    return *this;
}

inline NUInt32 &NUInt32::operator ^=( uint32_t value ) noexcept
{
    this->value_ ^= value;
    return *this;
}

inline NUInt32 NUInt32::operator >>( const NUInt32 &value ) const noexcept
{
    return *this >> value.value_;
}

inline NUInt32 NUInt32::operator >>( uint32_t value ) const noexcept
{
    return NUInt32( this->value_ >> value );
}

inline NUInt32 NUInt32::operator <<( const NUInt32 &value ) const noexcept
{
    return *this << value.value_;
}

inline NUInt32 NUInt32::operator <<( uint32_t value ) const noexcept
{
    return NUInt32( this->value_ << value );
}

inline NUInt32 operator +( uint32_t value1, const NUInt32 &value2 ) noexcept
{
    return value2 + value1;
}

inline NUInt32 operator -( uint32_t value1, const NUInt32 &value2 ) noexcept
{
    return NUInt32( value1 ) + value2;
}

inline NUInt32 operator *( uint32_t value1, const NUInt32 &value2 ) noexcept
{
    return value2 * value1;
}

inline NUInt32 operator /( uint32_t value1, const NUInt32 &value2 ) noexcept
{
    return NUInt32( value1 ) / value2;
}

inline NUInt32 operator %( uint32_t value1, const NUInt32 &value2 ) noexcept
{
    return NUInt32( value1 ) % value2;
}

inline bool operator !=( uint32_t value1, const NUInt32 &value2 ) noexcept
{
    return value2 != value1;
}

inline bool operator >( uint32_t value1, const NUInt32 &value2 ) noexcept
{
    return value2 < value1;
}

inline bool operator >=( uint32_t value1, const NUInt32 &value2 ) noexcept
{
    return value2 <= value1;
}

inline bool operator <( uint32_t value1, const NUInt32 &value2 ) noexcept
{
    return value2 > value1;
}

inline bool operator <=( uint32_t value1, const NUInt32 &value2 ) noexcept
{
    return value2 >= value1;
}

inline NUInt32 operator &( uint32_t value1, const NUInt32 &value2 ) noexcept
{
    return NUInt32( value1 ) & value2;
}

inline NUInt32 operator |( uint32_t value1, const NUInt32 &value2 ) noexcept
{
    return NUInt32( value1 ) | value2;
}

inline NUInt32 operator ^( uint32_t value1, const NUInt32 &value2 ) noexcept
{
    return NUInt32( value1 ) ^ value2;
}

inline NUInt32 operator >>( uint32_t value1, const NUInt32 &value2 ) noexcept
{
    return NUInt32( value1 ) >> value2;
}

inline NUInt32 operator <<( uint32_t value1, const NUInt32 &value2 ) noexcept
{
    return NUInt32( value1 ) << value2;
}

#endif // NUINT32_H
