#ifndef NINT32_H
#define NINT32_H

#include <stdint.h>
#include "ininteger.h"

/** \brief The MpDouble class - Класс представляет целое число размером 4 байта.
 */
class NInt32 : public INInteger<NInt32, int32_t>
{
public:        
    /**
     * @brief minValue - Представляет минимально допустимое значение типа .
     * NInt32.
     */
    const static NInt32 minValue;
    /**
     * @brief maxValue - Представляет наибольшее возможное значение типа NInt32.
     */
    const static NInt32 maxValue;

    /** \brief NInt32 - Инициализирует новый экземпляр класса целого числа со
     * значением 0.
     */
    NInt32() noexcept;

    /**
     * @brief NInt32 - Инициализирует новый экземпляр класса целого числа с
     * заданым значением.
     * @param value - целое число стандартного типа int32_t.
     */
    NInt32( int32_t value ) noexcept;

    /**
     * @brief NInt32 - Инициализирует новый экземпляр класса целого числа с
     * заданым значением.
     * @param value - целое число типа NInt32.
     */
    NInt32( const NInt32 &value ) noexcept;

    /**
     * @brief NInt32 - Инициализирует новый экземпляр класса целого числа с
     * заданым значением, реализующий семантику перемещения.
     * @param value - целое число типа NInt32.
     */
    NInt32( NInt32 &&value ) noexcept;

    ~NInt32() noexcept{}

    /**
     * @brief operator = - Оператор, позволяющий, присвоить значения
     * стандартного типа int32_t к данному экземпляру.
     * @param value - целое число стандартного типа int32_t.
     * @return экземпляр класса с новым значением.
     */
    NInt32 &operator =( int32_t value ) noexcept;

    /**
     * @brief operator = - Оператор, позволяющий, присвоить значения
     * стандартного типа int32_t к данному экземпляру.
     * @param value - целое число типа NInt32.
     * @return экземпляр класса с новым значением.
     */
    NInt32 &operator =( const NInt32 &value ) noexcept;

    /**
     * @brief operator = - Оператор, позволяющий, присвоить значения
     * стандартного типа int32_t к данному экземпляру, реализующий семантику
     * перемещения.
     * @param value - целое число типа NInt32.
     * @return экземпляр класса с новым значением.
     */
    NInt32 &operator =( NInt32 &&value ) noexcept;

    /**
     * @brief operator + -  Оператор, возвращающий, сумму чисел значений NInt32.
     * @param value - целое число типа NInt32.
     * @return сумма чисел типа NInt32.
     */
    NInt32 operator +( const NInt32 &value ) const noexcept;

    /**
     * @brief operator + - Оператор, возвращающий, сумму чисел значений данного
     * экземпляра и заданого числа стандартного типа int32_t.
     * @param value - целое число стандартного типа int32_t.
     * @return сумма чисел типа NInt32.
     */
    NInt32 operator +( int32_t value ) const noexcept;

    /**
     * @brief operator - Оператор, возвращающий, разность чисел значений NInt32.
     * @param value - целое число типа NInt32.
     * @return разность чисел типа NInt32.
     */
    NInt32 operator -( const NInt32 &value ) const noexcept;

    /**
     * @brief operator - - Оператор, возвращающий, разность чисел значений
     * данного экземпляра и заданого числа стандартного типа int32_t.
     * @param value - целое число стандартного типа int32_t.
     * @return разность чисел типа NInt32.
     */
    NInt32 operator -( int32_t value ) const noexcept;

    /**
     * @brief operator * - Оператор, возвращающий, произведения чисел значений
     * NInt32.
     * @param value - целое число типа NInt32.
     * @return произведения чисел типа NInt32.
     */
    NInt32 operator *( const NInt32 &value ) const noexcept;

    /**
     * @brief operator * - Оператор, возвращающий, произведение чисел значений
     * данного экземпляра и заданого числа стандартного типа int32_t.
     * @param value - целое число стандартного типа int32_t.
     * @return произведения чисел типа NInt32.
     */
    NInt32 operator *( int32_t value ) const noexcept;

    /**
     * @brief operator / - Оператор, возвращающий, частное чисел значений
     * NInt32.
     * @param value - целое число типа NInt32.
     * @return частное чисел типа NInt32.
     */
    NInt32 operator /( const NInt32 &value ) const noexcept;

    /**
     * @brief operator / - Оператор, возвращающий, частнок чисел значений
     * данного экземпляра и заданого числа.
     * @param value - целое число стандартного типа int32_t.
     * @return частное чисел типа NInt32.
     */
    NInt32 operator /( int32_t value ) const noexcept;

    /**
     * @brief operator % - Оператор, возвращающий, остаток от деления на число
     * типа NInt32.
     * @param value - целое число типа NInt32.
     * @return остаток от деления чисел тип NInt32.
     */
    NInt32 operator %( const NInt32 &value ) const noexcept;

    /**
     * @brief operator % - Оператор, возвращающий, остаток от деления на число
     * стандартного типа int32_t.
     * @param value - целое число стандартного типа int32_t.
     * @return остаток от деления чисел тип NInt32.
     */
    NInt32 operator %( int32_t value ) const noexcept;

    /**
     * @brief operator += - Оператор, позволяющий вернуть, результат операции
     * '+=' двух чисел типа NInt32, конечный результат присваивается экземпляру
     * класса.
     * @param value - целое число типа NInt32.
     * @return экземпляр класса с новым значением.
     */
    NInt32 &operator +=( const NInt32 &value ) noexcept;

    /**
     * @brief operator += - Оператор, позволяющий вернуть, результат операции
     * '+=' двух чисел данного экземпляра и числом стандартного типа int32_t,
     * конечный результат присваивается экземпляру класса.
     * @param value - целое число стандартного типа int32_t.
     * @return экземпляр класса с новым значением.
     */
    NInt32 &operator +=( int32_t value ) noexcept;

    /**
     * @brief operator -= - Оператор, позволяющий вернуть, результат операции
     * '-=' двух чисел типа NInt32 и, конечный результат присваивается
     * экземпляру класса.
     * @param value - целое число типа NInt32.
     * @return экземпляр класса с новым значением.
     */
    NInt32 &operator -=( const NInt32 &value ) noexcept;

    /**
     * @brief operator -= - Оператор, позволяющий вернуть, результат операции
     * '-=' двух чисел данного экземпляра и числом стандартного типа int32_t,
     * конечный результат присваивается экземпляру класса.
     * @param value - целое число стандартного типа int32_t.
     * @return экземпляр класса с новым значением.
     */
    NInt32 &operator -=( int32_t value ) noexcept;

    /**
     * @brief operator *= - Оператор, позволяющий вернуть, результат операции
     * '*=' двух чисел типа NInt32, конечный результат присваивается экземпляру
     * класса.
     * @param value - целое число типа NInt32.
     * @return экземпляр класса с новым значением.
     */
    NInt32 &operator *=( const NInt32 &value ) noexcept;

    /**
     * @brief operator *= - Оператор, позволяющий вернуть, результат операции
     * '*=' двух чисел данного экземпляра и числом стандартного типа int32_t,
     * конечный результат присваивается экземпляру класса.
     * @param value - целое число стандартного типа int32_t.
     * @return экземпляр класса с новым значением.
     */
    NInt32 &operator *=( int32_t value ) noexcept;

    /**
     * @brief operator /= - Оператор, позволяющий вернуть, результат операции
     * '/=' двух чисел типа NInt32, конечный результат присваивается экземпляру
     * класса.
     * @param value - целое число типа NInt32.
     * @return экземпляр класса с новым значением.
     */
    NInt32 &operator /=( const NInt32 &value ) noexcept;

    /**
     * @brief operator /= - Оператор, позволяющий вернуть, результат операции
     * '/=' двух чисел данного экземпляра и числом стандартного типа int32_t,
     * конечный результат присваивается экземпляру класса.
     * @param value - целое число стандартного типа int32_t.
     * @return экземпляр класса с новым значением.
     */
    NInt32 &operator /=( int32_t value ) noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса
     * на 1.
     * @return экземпляр класса с новым значением.
     */
    NInt32 &operator++() noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса на
     * 1 и возвращающие старое значение.
     * @return  экземпляр класса со старым значением.
     */
    NInt32 operator++(int32_t) noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1.
     * @return экземпляр класса с новым значением.
     */
    NInt32 &operator--() noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1
     * и возвращающие старое значение.
     * @return экземпляр класса со старыи значением.
     */
    NInt32 operator--(int32_t) noexcept;

    /**
     * @brief operator == - Оператор, указывающий, равны ли два заданных
     * значения типа NInt32.
     * @param value - целое число типа NInt32.
     * @return Значение true, если значения равны в противном случае —
     * значение false.
     */
    bool operator ==( const NInt32 &value ) const noexcept;

    /**
     * @brief operator == - Оператор, указывающий, равны ли два заданных
     * значения данного экземпляра и число стандартного типа int32_t.
     * @param value - целое число стандартного типа int32_t.
     * @return Значение true, если значения равны в противном случае — значение
     * false.
     */
    bool operator ==( int32_t value ) const noexcept;

    /**
     * @brief operator != - Оператор, указывающий, не равны ли два заданных
     * значения типа NInt32.
     * @param value - целое число типа NInt32.
     * @return Значение true, если значения не равны в противном случае —
     * значение false.
     */
    bool operator !=( const NInt32 &value ) const noexcept;

    /**
     * @brief operator != - Оператор, указывающий, не равны ли заданных значения
     * данного экземпляра и число стандартного типа int32_t.
     * @param value - целое число стандартного типа int32_t.
     * @return Значение true, если значения не равны в противном случае —
     * значение false.
     */
    bool operator !=( int32_t value ) const noexcept;

    /**
     * @brief operator > - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра больше заданному значению типа NInt32.
     * @param value - целое число типа NInt32.
     * @return Значение true, если данного экземпляра больше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator >( const NInt32 &value ) const noexcept;

    /**
     * @brief operator > - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра больше заданному значению стандартного типа
     * int32_t.
     * @param value - целое число стандартного типа int32_t.
     * @return Значение true, если данного экземпляра больше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator >( int32_t value ) const noexcept;

    /**
     * @brief operator >= - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра больше или равно заданному значению типа
     * NInt32.
     * @param value - целое число типа NInt32.
     * @return  Значение true, если данного экземпляра больше или равно
     * заданному значению в противном случае — значение false.
     */
    bool operator >=( const NInt32 &value ) const noexcept;

    /**
     * @brief operator >= - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра больше или равно заданному значению
     * стандартного типа int32_t.
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа int32_t.
     * @return Значение true, если данного экземпляра больше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator >=( int32_t value ) const noexcept;

    /**
     * @brief operator < - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра меньше заданному значению типа NInt32.
     * @param value - целое число типа NInt32.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator <( const NInt32 &value ) const noexcept;

    /**
     * @brief operator < - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра меньше заданному значению стандартного типа
     * int32_t.
     * @param value - целое число стандартного типа int32_t.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator <( int32_t value ) const noexcept;

    /**
     * @brief operator <= - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра меньше или равно заданному значению типа
     * NInt32.
     * @param value - целое число типа NInt32.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     *  значению в противном случае — значение false.
     */
    bool operator <=( const NInt32 &value ) const noexcept;

    /**
     * @brief operator <= - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра меньше или равно заданному значению
     * стандартного типа int32_t.
     * @param value - целое число стандартного типа int32_t.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator <=( int32_t value ) const noexcept;

    /**
     * @brief operator & - Оператор, реализующий, операцию побитовое 'и' двух
     * чисел типа NInt32.
     * @param value - целое число типа NInt32.
     * @return новое значение типа NInt32.
     */
    NInt32 operator &( const NInt32 &value ) const noexcept;

    /**
     * @brief operator & - Оператор, реализующий, операцию побитовое 'и' двух
     * чисел типа NInt32.
     * @param value - целое число стандартного типа int32_t.
     * @return новое значение типа NInt32.
     */
    NInt32 operator &( int32_t value ) const noexcept;

    /**
     * @brief operator | - Оператор, реализующий, операцию побитовое 'или' двух
     * чисел типа NInt32.
     * @param value - целое число типа NInt32.
     * @return новое значение типа NInt32.
     */
    NInt32 operator |( const NInt32 &value ) const noexcept;

    /**
     * @brief operator | - Оператор, реализующий, операцию побитовое 'или'
     * заданного класса и числа стандарного типа int32_t.
     * @param value - целое число стандартного типа int32_t.
     * @return новое значение типа NInt32.
     */
    NInt32 operator |( int32_t value ) const noexcept;

    /**
     * @brief operator ^ - Оператор, реализующий, операцию исключающие 'или'
     * двух чисел типа NInt32.
     * @param value - целое число типа NInt32.
     * @return новое значение типа NInt32.
     */
    NInt32 operator ^( const NInt32 &value ) const noexcept;

    /**
     * @brief operator ^ -  Оператор, реализующий, операцию исключающие 'или'
     * заданного класса и числа стандарного типа int32_t.
     * @param value - целое число стандартного типа int32_t.
     * @return новое значение типа NInt32.
     */
    NInt32 operator ^( int32_t value ) const noexcept;

    /**
     * @brief operator &= - Оператор, реализующий, операцию побитовое 'и' двух
     * чисел типа NInt32, результат сохраняется в экземпляре класса.
     * @param value - целое число типа NInt32.
     * @return новое значение типа NInt32.
     */
    NInt32 &operator &=( const NInt32 &value ) noexcept;

    /**
     * @brief operator &= - Оператор, реализующий, операцию побитовое 'и'
     * заданного класса и числа стандарного типа int32_t, результат сохраняется
     * в экземпляре класса.
     * @param value - целое число стандартного типа int32_t.
     * @return новое значение типа NInt32.
     */
    NInt32 &operator &=( int32_t value ) noexcept;

    /**
     * @brief operator |= - Оператор, реализующий, операцию побитовое 'или' двух
     * чисел типа NInt32 результат сохраняется в экземпляре класса.
     * @param value - целое число типа NInt32.
     * @return новое значение типа NInt32.
     */
    NInt32 &operator |=( const NInt32 &value ) noexcept;

    /**
     * @brief operator |= - Оператор, реализующий, операцию побитовое 'или'
     * заданного класса и числа стандарного типа int32_t, результат сохраняется
     * в экземпляре класса.
     * @param value - целое число стандартного типа int32_t.
     * @return новое значение типа NInt32.
     */
    NInt32 &operator |=( int32_t value ) noexcept;

    /**
     * @brief operator ^= - Оператор, реализующий, операцию исключающие 'или'
     * двух чисел типа NInt32, результат сохраняется в экземпляре класса.
     * @param value - целое число типа NInt32.
     * @return новое значение типа NInt32.
     */
    NInt32 &operator ^=( const NInt32 &value ) noexcept;

    /**
     * @brief operator ^= -  Оператор, реализующий, операцию исключающие 'или'
     * заданного класса и числа стандарного типа int32_t, результат сохраняется
     * в экземпляре класса.
     * @param value - целое число стандартного типа int32_t.
     * @return новое значение типа NInt32.
     */
    NInt32 &operator ^=( int32_t value ) noexcept;

    /**
     * @brief operator - - Оператор, реализующий, операцию отрицания.
     * @return новое значение типа NInt32.
     */
    NInt32 operator -() const noexcept;

    /**
     * @brief operator >> -  Оператор, реализующий, операцию циклических сдвиг
     * вправо на значение value.
     * @param value - целое число типа NInt32.
     * @return новое значение типа NInt32.
     */
    NInt32 operator >>( const NInt32 &value ) const noexcept;

    /**
     * @brief operator >> -  Оператор, реализующий, операцию циклических сдвиг
     * вправо на значение value.
     * @param value - целое число стандартного типа int32_t.
     * @return новое значение типа NInt32.
     */
    NInt32 operator >>( int32_t value ) const noexcept;

    /**
     * @brief operator << - Оператор, реализующий, операцию циклических сдвиг
     * влево на значение value.
     * @param value - целое число типа NInt32.
     * @return новое значение типа NInt32.
     */
    NInt32 operator <<( const NInt32 &value ) const noexcept;

    /**
     * @brief operator << - Оператор, реализующий, операцию циклических сдвиг
     * влево на значение value.
     * @param value - целое число стандартного типа int32_t.
     * @return новое значение типа NInt32.
     */
    NInt32 operator <<( int32_t value ) const noexcept;

    /**
     * @brief operator + - Оператор, возвращающий, сумму чисел типа NInt32 и
     * типа int32_t.
     * @param value1 - целое число стандартного типа int32_t.
     * @param value2 - целое число типа NInt32.
     * @return сумма чисел типа NInt32.
     */
    friend NInt32 operator +( int32_t value1, const NInt32 &value2 ) noexcept;

    /**
     * @brief operator - - Оператор, возвращающий, разность чисел типа int32_t и
     * типа NInt32.
     * @param value1 - целое число стандартного типа int32_t.
     * @param value2 - целое число типа NInt32.
     * @return разность чисел типа NInt32.
     */
    friend NInt32 operator -( int32_t value1, const NInt32 &value2 ) noexcept;

    /**
     * @brief operator * - Оператор, возвращающий, произведение чисел типа
     * int32_t и типа NInt32.
     * @param value1 - целое число стандартного типа int32_t.
     * @param value2 - целое число типа NInt32.
     * @return произведения чисел типа NInt32.
     */
    friend NInt32 operator *( int32_t value1, const NInt32 &value2 ) noexcept;

    /**
     * @brief operator / - Оператор, возвращающий, частнок чисел типа int32_t и
     * типа NInt32.
     * @param value1 - целое число стандартного типа int32_t.
     * @param value2 - целое число типа NInt32.
     * @return частное чисел типа NInt32.
     */
    friend NInt32 operator /( int32_t value1, const NInt32 &value2 ) noexcept;

    /**
     * @brief operator % - Оператор, возвращающий, остаток от деления чисел типа
     * int32_t и типа NInt32.
     * @param value1 - целое число стандартного типа int32_t.
     * @param value2 - целое число типа NInt32.
     * @return остаток от деления чисел тип NInt32.
     */
    friend NInt32 operator %( int32_t value1, const NInt32 &value2 ) noexcept;

    /**
     * @brief operator != - Оператор, указывающий, не равны ли два заданных
     * значения типа int32_t и типа NInt32.
     * @param value1 - целое число стандартного типа int32_t.
     * @param value2 - целое число типа NInt32.
     * @return Значение true, если значения не равны в противном случае —
     * значение false.
     */
    friend bool operator !=( int32_t value1, const NInt32 &value2 ) noexcept;

    /**
     * @brief operator > - Оператор, указывающий, действительно ли значение типа
     * int32_t больше значению типа NInt32.
     * @param value1 - целое число стандартного типа int32_t.
     * @param value2 - целое число типа NInt32.
     * @return Значение true, если данного экземпляра больше или равно заданному
     * значению в противном случае — значение false.
     */
    friend bool operator >( int32_t value1, const NInt32 &value2 ) noexcept;

    /**
     * @brief operator >= - Оператор, указывающий, действительно ли заданное
     * значение типа int32_t больше или равно значению типа NInt32.
     * @param value1 - целое число стандартного типа int32_t.
     * @param value2 - целое число типа NInt32.
     * @return  Значение true, если данного экземпляра больше или равно
     * заданному значению в противном случае — значение false.
     */
    friend bool operator >=( int32_t value1, const NInt32 &value2 ) noexcept;

    /**
     * @brief operator < - Оператор, указывающий, действительно ли заданное
     * значение типа int32_t меньше значению типа NInt32.
     * @param value1 - целое число стандартного типа int32_t.
     * @param value2 - целое число типа NInt32.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае — значение false.
     */
    friend bool operator <( int32_t value1, const NInt32 &value2 ) noexcept;

    /**
     * @brief operator <= - Оператор, указывающий, действительно ли заданное
     * значение типа int32_t меньше или равно значению типа NInt32.
     * @param value1 - целое число стандартного типа int32_t.
     * @param value2 - целое число типа NInt32.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае — значение false.
     */
    friend bool operator <=( int32_t value1, const NInt32 &value2 ) noexcept;

    /**
     * @brief operator & - Оператор, реализующий, операцию побитовое 'и' двух
     * чисел типа int32_t и типа NInt32.
     * @param value1 - целое число стандартного типа int32_t.
     * @param value2 - целое число типа NInt32.
     * @return новое значение типа NInt32.
     */
    friend NInt32 operator &( int32_t value1, const NInt32 &value2 ) noexcept;

    /**
     * @brief operator | - Оператор, реализующий, операцию побитовое 'или' двух
     * чисел типа int32_t и типа NInt32.
     * @param value1 - целое число стандартного типа int32_t.
     * @param value2 - целое число типа NInt32.
     * @return новое значение типа NInt32.
     */
    friend NInt32 operator |( int32_t value1, const NInt32 &value2 ) noexcept;

    /**
     * @brief operator ^ - Оператор, реализующий, операцию исключающие 'или'
     * двух чисел int32_t и типа NInt32.
     * @param value1 - целое число стандартного типа int32_t.
     * @param value2 - целое число типа NInt32.
     * @return новое значение типа NInt32.
     */
    friend NInt32 operator ^( int32_t value1, const NInt32 &value2 ) noexcept;

    /**
     * @brief operator >> -  Оператор, реализующий, операцию циклических сдвиг
     * вправо значения int32_t на значение типа NInt32.
     * @param value1 - целое число стандартного типа int32_t.
     * @param value2 - целое число типа NInt32.
     * @return новое значение типа NInt32.
     */
    friend NInt32 operator >>( int32_t value1, const NInt32 &value2 ) noexcept;

    /**
     * @brief operator << - Оператор, реализующий, операцию циклических сдвиг
     * влево значения int32_t на значение типа NInt32.
     * @param value1 - целое число стандартного типа int32_t.
     * @param value2 - целое число типа NInt32.
     * @return новое значение типа NInt32.
     */
    friend NInt32 operator <<( int32_t value1, const NInt32 &value2 ) noexcept;
};

inline NInt32::NInt32() noexcept : INInteger<NInt32, int32_t>()
{
    this->value_ = 0;
}

inline NInt32::NInt32( int32_t value ) noexcept : INInteger<NInt32, int32_t>()
{
    this->value_ = value;
}

inline NInt32::NInt32( const NInt32 &value ) noexcept
    : INInteger<NInt32, int32_t>()
{
    this->value_ = value.value_;
}

inline NInt32::NInt32( NInt32 &&value ) noexcept : INInteger<NInt32, int32_t>()
{
    this->value_ = value.value_;
}

inline NInt32 &NInt32::operator =( int32_t value ) noexcept
{
    this->value_ = value;
    return *this;
}

inline NInt32 &NInt32::operator =( const NInt32 &value ) noexcept
{
    *this = value.value_;
    return *this;
}

inline NInt32 &NInt32::operator =( NInt32 &&value ) noexcept
{
    this->value_ = std::move( value.value_ );
    return *this;
}

inline NInt32 NInt32::operator +( const NInt32 &value ) const noexcept
{
    return *this + value.value_;
}

inline NInt32 NInt32::operator +( int32_t value ) const noexcept
{
    return this->sum( this->value_, value, NInt32::minValue, NInt32::maxValue );
}

inline NInt32 NInt32::operator -( const NInt32 &value ) const noexcept
{
    NInt32 v = *this - value.value_;
    return v;
}

inline NInt32 NInt32::operator -( int32_t value ) const noexcept
{
    return this->diff( this->value_, value, NInt32::minValue,
                       NInt32::maxValue );
}

inline NInt32 NInt32::operator *( const NInt32 &value ) const noexcept
{
    return *this * value.value_;
}

inline NInt32 NInt32::operator *( int32_t value ) const noexcept
{
    return this->mul( this->value_, value, NInt32::minValue, NInt32::maxValue );
}

inline NInt32 NInt32::operator /( const NInt32 &value ) const noexcept
{
    return *this / value.value_;
}

inline NInt32 NInt32::operator /( int32_t value ) const noexcept
{
    return this->div( this->value_, value, NInt32::minValue, NInt32::maxValue );
}

inline NInt32 NInt32::operator %( const NInt32 &value ) const noexcept
{
    return *this % value.value_;
}

inline NInt32 NInt32::operator %( int32_t value ) const noexcept
{
    if( value != 0 )
    {
        NInt32 _r( this->value_ % value );
        if( this->value_ < 0 )
            return NInt32( value ).abs() - _r.abs();
        return _r;
    }
    std::wcerr << "Error! 0 divide! value1 = " << this->value_
               << " and value2 = " << value << std::endl;
    return *this;
}

inline NInt32 &NInt32::operator +=( const NInt32 &value ) noexcept
{
    *this += value.value_;
    return *this;
}

inline NInt32 &NInt32::operator +=( int32_t value ) noexcept
{
    this->value_ += value;
    return *this;
}

inline NInt32 &NInt32::operator -=( const NInt32 &value ) noexcept
{
    *this -= value.value_;
    return *this;
}

inline NInt32 &NInt32::operator -=( int32_t value ) noexcept
{
    this->value_ -= value;
    return *this;
}

inline NInt32 &NInt32::operator *=( const NInt32 &value ) noexcept
{
    *this *= value.value_;
    return *this;
}

inline NInt32 &NInt32::operator *=( int32_t value ) noexcept
{
    this->value_ *= value;
    return *this;
}

inline NInt32 &NInt32::operator /=( const NInt32 &value ) noexcept
{
    *this /= value.value_;
    return *this;
}

inline NInt32 &NInt32::operator /=( int32_t value ) noexcept
{
    this->value_ /= value;
    return *this;
}

inline NInt32 &NInt32::operator++() noexcept
{
    if( NInt32::maxValue == this->value_ )
        std::wcerr << "Error! Overflow! this->value_ = "
                   << this->value_ << std::endl;
    else
        ++this->value_;
    return *this;
}

inline NInt32 NInt32::operator++(int) noexcept
{
    NInt32 v = *this;
    if( v == NInt32::maxValue )
        std::wcerr << "Error! Overflow! this->value_ = "
                   << this->value_ << std::endl;
    else
        ++(*this);
    return v;
}

inline NInt32 &NInt32::operator--() noexcept
{
    if( NInt32::minValue == this->value_ )
        std::wcerr << "Error! Overflow! this->value_ = "
                   << this->value_ << std::endl;
    else
        --this->value_;
    return *this;
}

inline NInt32 NInt32::operator--(int) noexcept
{
    NInt32 v = *this;
    if( v == NInt32::minValue )
        std::wcerr << "Error! Overflow! this->value_ = "
                   << this->value_ << std::endl;
    else
        --(*this);
    return v;
}

inline bool NInt32::operator ==( const NInt32 &value ) const noexcept
{
    return ( *this == value.value_ );
}

inline bool NInt32::operator ==( int32_t value ) const noexcept
{
    return ( this->value_ == value );
}

inline bool NInt32::operator !=( const NInt32 &value ) const noexcept
{
    return ( *this != value.value_ );
}

inline bool NInt32::operator !=( int32_t value ) const noexcept
{
    return ( this->value_ != value );
}

inline bool NInt32::operator >( const NInt32 &value ) const noexcept
{
    return ( *this > value.value_ );
}

inline bool NInt32::operator >( int32_t value ) const noexcept
{
    return ( this->value_ > value );
}

inline bool NInt32::operator >=( const NInt32 &value ) const noexcept
{
    return ( *this >= value.value_ );
}

inline bool NInt32::operator >=( int32_t value ) const noexcept
{
    return ( this->value_ >= value );
}

inline bool NInt32::operator <( const NInt32 &value ) const noexcept
{
    return ( *this < value.value_ );
}

inline bool NInt32::operator <( int32_t value ) const noexcept
{
    return ( this->value_ < value );
}

inline bool NInt32::operator <=( const NInt32 &value ) const noexcept
{
    return ( *this <= value.value_ );
}

inline bool NInt32::operator <=( int32_t value ) const noexcept
{
    return ( this->value_ <= value );
}

inline NInt32 NInt32::operator &( const NInt32 &value ) const noexcept
{
    return *this & value.value_;
}

inline NInt32 NInt32::operator &( int32_t value ) const noexcept
{
    return NInt32( this->value_ & value );
}

inline NInt32 NInt32::operator |( const NInt32 &value ) const noexcept
{
    return *this | value.value_;
}

inline NInt32 NInt32::operator |( int32_t value ) const noexcept
{
    return NInt32( this->value_ | value );
}

inline NInt32 NInt32::operator ^( const NInt32 &value ) const noexcept
{
    return *this ^ value.value_;
}

inline NInt32 NInt32::operator ^( int32_t value ) const noexcept
{
    return NInt32( this->value_ ^ value );
}

inline NInt32 &NInt32::operator &=( const NInt32 &value ) noexcept
{
    *this &= value.value_;
    return *this;
}

inline NInt32 &NInt32::operator &=( int32_t value ) noexcept
{
    this->value_ &= value;
    return *this;
}

inline NInt32 &NInt32::operator |=( const NInt32 &value ) noexcept
{
    *this |= value.value_;
    return *this;
}

inline NInt32 &NInt32::operator |=( int32_t value ) noexcept
{
    this->value_ |= value;
    return *this;
}

inline NInt32 &NInt32::operator ^=( const NInt32 &value ) noexcept
{
    *this ^= value.value_;
    return *this;
}

inline NInt32 &NInt32::operator ^=( int32_t value ) noexcept
{
    this->value_ ^= value;
    return *this;
}

inline NInt32 NInt32::operator -() const noexcept
{
    return NInt32( -this->value_ );
}

inline NInt32 NInt32::operator >>( const NInt32 &value ) const noexcept
{
    return *this >> value.value_;
}

inline NInt32 NInt32::operator >>( int32_t value ) const noexcept
{
    return NInt32( this->value_ >> value );
}

inline NInt32 NInt32::operator <<( const NInt32 &value ) const noexcept
{
    return *this << value.value_;
}

inline NInt32 NInt32::operator <<( int32_t value ) const noexcept
{
    return NInt32( this->value_ << value );
}

inline NInt32 operator +( int32_t value1, const NInt32 &value2 ) noexcept
{
    return value2 + value1;
}

inline NInt32 operator -( int32_t value1, const NInt32 &value2 ) noexcept
{
    return NInt32( value1 ) + value2;
}

inline NInt32 operator *( int32_t value1, const NInt32 &value2 ) noexcept
{
    return value2 * value1;
}

inline NInt32 operator /( int32_t value1, const NInt32 &value2 ) noexcept
{
    return NInt32( value1 ) / value2;
}

inline NInt32 operator %( int32_t value1, const NInt32 &value2 ) noexcept
{
    return NInt32( value1 ) % value2;
}

inline bool operator !=( int32_t value1, const NInt32 &value2 ) noexcept
{
    return value2 != value1;
}

inline bool operator >( int32_t value1, const NInt32 &value2 ) noexcept
{
    return value2 < value1;
}

inline bool operator >=( int32_t value1, const NInt32 &value2 ) noexcept
{
    return value2 <= value1;
}

inline bool operator <( int32_t value1, const NInt32 &value2 ) noexcept
{
    return value2 > value1;
}

inline bool operator <=( int32_t value1, const NInt32 &value2 ) noexcept
{
    return value2 >= value1;
}

inline NInt32 operator &( int32_t value1, const NInt32 &value2 ) noexcept
{
    return NInt32( value1 ) & value2;
}

inline NInt32 operator |( int32_t value1, const NInt32 &value2 ) noexcept
{
    return NInt32( value1 ) | value2;
}

inline NInt32 operator ^( int32_t value1, const NInt32 &value2 ) noexcept
{
    return NInt32( value1 ) ^ value2;
}

inline NInt32 operator >>( int32_t value1, const NInt32 &value2 ) noexcept
{
    return NInt32( value1 ) >> value2;
}

inline NInt32 operator <<( int32_t value1, const NInt32 &value2 ) noexcept
{
    return NInt32( value1 ) << value2;
}

#endif // NINT32_H
