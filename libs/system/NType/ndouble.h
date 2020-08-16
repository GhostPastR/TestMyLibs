#ifndef NDOUBLE_H
#define NDOUBLE_H

#include "infloatingpoint.h"
#include "nint32.h"

/** \brief The NDouble class - Класс представляет число двойной точности с плавающей запятой.
 */
class NDouble : public INFloatingPoint<NDouble,double>
{
public:
    /**
     * @brief nan - Представляет значение, не являющееся числом (nan).
     */
    const static NDouble nan;
    /**
     * @brief nInfinity - Представляет минус бесконечность.
     */
    const static NDouble nInfinity;
    /**
     * @brief pInfinity - Представляет плюс бесконечность.
     */
    const static NDouble pInfinity;
    /**
     * @brief minValue - Представляет минимально допустимое значение типа
     * NDouble.
     */
    const static NDouble minValue;
    /**
     * @brief maxValue - Представляет наибольшее возможное значение типа
     * NDouble.
     */
    const static NDouble maxValue;
    /**
     * @brief epsilon - Представляет наименьшее положительное значение NDouble.
     */
    const static NDouble epsilon;

    /**
     * @brief isInfinity - Статический метод, позволяющее определить, равно ли
     * данное число плюс или минус бесконечности.
     * @param value - число двойной точности с плавающей запятой.
     * @return значение true, если параметр value равен значению
     * NDouble::pInfinity или NDouble::nInfinity; в противном случае — значение
     * false.
     */
    static bool isInfinity( const NDouble &value ) noexcept;

    /**
     * @brief isNaN - Статический метод, показывающее, что указанное значение не
     * является числом.
     * @param value - число двойной точности с плавающей запятой.
     * @return значение true, если значение параметра value равно значению
     * NDouble::nan, в противном случае — значение false.
     */
    static bool isNaN( const NDouble &value ) noexcept;

    /**
     * @brief isNegativeInfinity - Статический метод, позволяющее определить,
     * равно ли данное число минус бесконечности.
     * @param value - число двойной точности с плавающей запятой.
     * @return значение true, если значение параметра value равно значению
     * NDouble::nInfinity; в противном случае — значение false.
     */
    static bool isNegativeInfinity( const NDouble &value ) noexcept;

    /**
     * @brief isPositiveInfinity - Статический метод, позволяющее определить,
     * равно ли данное число плюс бесконечности.
     * @param value - число двойной точности с плавающей запятой.
     * @return значение true, если значение параметра value равно значению
     * NDouble::pInfinity, в противном случае — значение false.
     */
    static bool isPositiveInfinity( const NDouble &value ) noexcept;

    /**
     * @brief NDouble - Инициализирует новый экземпляр класса числа с плавающий
     * запятой со значением 0.0.
     */
    NDouble() noexcept;

    /**
     * @brief NDouble - Инициализирует новый экземпляр класса числа с плавающий
     * запятой с заданым значением.
     * @param value - число с плавающий запятой.
     */
    explicit NDouble( const double &value ) noexcept;

    /**
     * @brief NDouble - Инициализирует новый экземпляр класса числа с плавающий
     * запятой с заданым значением.
     * @param value - число с плавающий запятой.
     */
    NDouble( const NDouble &value ) noexcept;

    /**
     * @brief NDouble - Инициализирует новый экземпляр класса числа с плавающий
     * запятой с заданым значением используя семантику перемещения.
     * @param value - число с плавающий запятой.
     */
    explicit NDouble( NDouble &&value ) noexcept;

    using INFloatingPoint::isInfinity;

    using INFloatingPoint::isNaN;

    using INFloatingPoint::isNegativeInfinity;

    using INFloatingPoint::isPositiveInfinity;

    /**
     * @brief entier - Извлекает целую часть из данного экземпляра класса.
     * @return целая часть числа с плавающей запятой.
     */
    NDouble entier() const noexcept;

    /**
     * @brief fraction - Извлекает дробную часть из данного экземпляра класса.
     * @return дробная часть числа с плавающей запятой.
     */
    NDouble fraction() const noexcept;

    /**
     * @brief compare - Проверяет равны ли два заданных значения данного
     * экземпляра и числом двойной точности с плавающей запятой стандартного
     * типа double(операция ==).
     * @param value число двойной точности с плавающей запятой стандартного
     * типа double.
     * @param number - количество значемых цифр для сравнения.
     * @return Значение true, если значения равны в противном случае
     * значение false.
     */
    bool compare( const double &value,
                  NInt32 number = NInt32( 6 ) ) const noexcept;

    /**
     * @brief compare - Проверяет равны ли два заданных значения данного
     * экземпляра и числом двойной точности с плавающей запятой(операция ==).
     * @param value - число двойной точности с плавающей запятой.
     * @param number - количество значемых цифр для сравнения.
     * @return Значение true, если значения равны в противном случае
     * значение false.
     */
    bool compare( const NDouble &value,
                  NInt32 number = NInt32( 6 ) ) const noexcept;

    /**
     * @brief unequal - Проверяет не равны ли два заданных значения данного
     * экземпляра и числом двойной
     * точности с плавающей запятой стандартного типа double(операция !=).
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @param number - количество значемых цифр для сравнения.
     * @return Значение true, если значения не равны в противном случае
     * значение false.
     */
    bool unequal( const double &value,
                  NInt32 number = NInt32( 6 ) ) const noexcept;

    /**
     * @brief unequal - Проверяет не равны ли два заданных значения данного
     * экземпляра и числом двойной точности с плавающей запятой(операция !=).
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @param number - количество значемых цифр для сравнения.
     * @return Значение true, если значения не равны в противном случае
     * значение false.
     */
    bool unequal( const NDouble &value,
                  NInt32 number = NInt32( 6 ) ) const noexcept;

    /**
     * @brief moreThan - Проверяет действительно ли заданное значение данного
     * экземпляра больше или равно заданному значению(операция >=).
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @param number - количество значемых цифр для сравнения.
     * @return Значение true, если данного экземпляра больше или равно
     * заданному значению, в противном случае значение false.
     */
    bool moreThan( const double &value,
                   NInt32 number = NInt32( 6 ) ) const noexcept;

    /**
     * @brief moreThan - Проверяет действительно ли заданное значение данного
     * экземпляра больше или равно заданному значению(операция >=).
     * @param value - число двойной точности с плавающей запятой.
     * @param number - количество значемых цифр для сравнения.
     * @return Значение true, если данного экземпляра больше или равно
     * заданному значению в противном случае значение false.
     */
    bool moreThan( const NDouble &value,
                   NInt32 number = NInt32( 6 ) ) const noexcept;

    /**
     * @brief feverThan - Проверяет действительно ли заданное значение данного
     * экземпляра меньше или равно заданному значению(операция <=).
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @param number - количество значемых цифр для сравнения.
     * @return  Значение true, если данного экземпляра меньше или равно
     * заданному значению в противном случае — значение false.
     */
    bool feverThan( const double &value,
                    NInt32 number = NInt32( 6 ) ) const noexcept;

    /**
     * @brief feverThan - Проверяет действительно ли заданное значение данного
     * экземпляра меньше или равно заданному значению(операция <=).
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @param number - количество значемых цифр для сравнения.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае значение false.
     */
    bool feverThan( const NDouble &value,
                    NInt32 number = NInt32( 6 ) ) const noexcept;

    /**
     * @brief ceil - Метод округляет значения экземпляра класса до ближайшего
     * большего целого числа.
     * @return результат округления.
     */
    NDouble ceil();

    /**
     * @brief operator = - Оператор, позволяющий, присвоить значения
     * стандартного типа double к данному экземпляру.
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @return экземпляр класса с новым значением.
     */
    NDouble &operator =( const double &value ) noexcept;

    /**
     * @brief operator = - Оператор, позволяющий, присвоить значения типа
     * NDouble к данному экземпляру.
     * @param value - число двойной точности с плавающей запятой типа NDouble.
     * @return экземпляр класса с новым значением.
     */
    NDouble &operator =( const NDouble &value ) noexcept;

    /**
     * @brief operator = - Оператор, позволяющий, присвоить значения
     * стандартного типа double к данному экземпляру используя семантику
     * перемещения.
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @return экземпляр класса с новым значением.
     */
    NDouble &operator =( NDouble &&value ) noexcept;

    /**
     * @brief operator + - Оператор, возвращающий, сумму чисел значений данного
     * экземпляра и заданого числа.
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @return сумма чисел.
     */
    NDouble operator +( const double &value ) const noexcept;

    /**
     * @brief operator + - Оператор, возвращающий, сумму чисел значений NDouble.
     * @param value - число двойной точности с плавающей запятой.
     * @return сумма чисел значений NDouble.
     */
    NDouble operator +( const NDouble &value ) const noexcept;

    /**
     * @brief operator - - Оператор, возвращающий, разность чисел значений
     * данного экземпляра и заданого числа.
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @return разность чисел.
     */
    NDouble operator -( const double &value ) const noexcept;

    /**
     * @brief operator - - Оператор, возвращающий, разность чисел значений
     * NDouble.
     * @param value - число двойной точности с плавающей запятой.
     * @return разность чисел значений NDouble.
     */
    NDouble operator -( const NDouble &value ) const noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса
     * на 1.
     * @return экземпляр класса с новым значением.
     */
    NDouble &operator++() noexcept;

    /**
     * @brief operator ++ - Оператор, увеличивающие значение данного класса на
     * 1 и возвращающие старое значение.
     * @return  экземпляр класса со старым значением.
     */
    NDouble operator++(int) noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1.
     * @return экземпляр класса с новым значением.
     */
    NDouble &operator--() noexcept;

    /**
     * @brief operator -- - Оператор, уменьшающие значение данного класса на 1
     * и возвращающие старое значение.
     * @return экземпляр класса со старыи значением.
     */
    NDouble operator--(int) noexcept;

    /**
     * @brief operator * - Оператор, возвращающий, произведение чисел значений
     * данного экземпляра и заданого числа.
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @return произведения чисел.
     */
    NDouble operator *( const double &value ) const noexcept;

    /**
     * @brief operator * - Оператор, возвращающий, произведения чисел значений
     * NDouble.
     * @param value - число двойной точности с плавающей запятой.
     * @return произведения чисел значений NDouble.
     */
    NDouble operator *( const NDouble &value ) const noexcept;

    /**
     * @brief operator / - Оператор, возвращающий, частное чисел значений
     * данного экземпляра и заданого числа. Если результат получается плюс или
     * минус бесконечность, то возвражается максимальное число со знаком.
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @return частное чисел.
     */
    NDouble operator /( const double &value ) const noexcept;

    /**
     * @brief operator / - Оператор, возвращающий, частное чисел значений
     * NDouble.
     * @param value - число двойной точности с плавающей запятой.
     * @return частное чисел значений NDouble.
     */
    NDouble operator /( const NDouble &value ) const noexcept;

    /**
     * @brief operator % Оператор, возвращающий, остаток от деления чисел
     * данного экземпляра и заданого числа.
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @return остаток от деления(всегда полочительный).
     */
    NDouble operator %( const double &value ) const noexcept;

    /**
     * @brief operator % Оператор, возвращающий, остаток от деления чисел
     * данного экземпляра и заданого числа.
     * @param value - число двойной точности с плавающей запятой.
     * @return остаток от деления(всегда полочительный).
     */
    NDouble operator %( const NDouble &value ) const noexcept;

    /**
     * @brief operator += - Оператор, позволяющий вернуть, результат операции
     * '+=' двух чисел данного экземпляра и числом двойной точности с плавающей
     * запятой стандартного типа double, конечный результат присваивается
     * экземпляру класса.
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @return экземпляр класса с новым значением.
     */
    NDouble &operator +=( const double &value ) noexcept;

    /**
     * @brief operator += - Оператор, позволяющий вернуть, результат операции
     * '+=' двух чисел данного экземпляра и числом двойной точности с плавающей
     * запятой, конечный результат присваивается экземпляру класса.
     * @param value - число двойной точности с плавающей запятой.
     * @return экземпляр класса с новым значением.
     */
    NDouble &operator +=( const NDouble &value ) noexcept;

    /**
     * @brief operator -= - Оператор, позволяющий вернуть, результат операции
     * '-=' двух чисел данного экземпляра и числом двойной точности с плавающей
     * запятой стандартного типа double, конечный результат присваивается
     * экземпляру класса.
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @return экземпляр класса с новым значением.
     */
    NDouble &operator -=( const double &value ) noexcept;

    /**
     * @brief operator -= - Оператор, позволяющий вернуть, результат операции
     * '-=' двух чисел данного экземпляра и числом двойной точности с плавающей
     * запятой, конечный результат присваивается экземпляру класса.
     * @param value - число двойной точности с плавающей запятой.
     * @return экземпляр класса с новым значением.
     */
    NDouble &operator -=( const NDouble &value ) noexcept;

    /**
     * @brief operator *= - Оператор, позволяющий вернуть, результат операции
     * '*=' двух чисел данного экземпляра и числом двойной точности с плавающей
     * запятой стандартного типа double, конечный результат присваивается
     * экземпляру класса.
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @return экземпляр класса с новым значением.
     */
    NDouble &operator *=( const double &value ) noexcept;

    /**
     * @brief operator *= - Оператор, позволяющий вернуть, результат операции
     * '*=' двух чисел данного экземпляра и числом двойной точности с плавающей
     * запятой, конечный результат присваивается экземпляру класса.
     * @param value - число двойной точности с плавающей запятой.
     * @return экземпляр класса с новым значением.
     */
    NDouble &operator *=( const NDouble &value ) noexcept;

    /**
     * @brief operator /= - Оператор, позволяющий вернуть, результат операции
     * '/=' двух чисел данного экземпляра и числом двойной точности с плавающей
     * запятой стандартного типа double, конечный результат присваивается
     * экземпляру класса.
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @return экземпляр класса с новым значением.
     */
    NDouble &operator /=( const double &value ) noexcept;

    /**
     * @brief operator /= - Оператор, позволяющий вернуть, результат операции
     * '/=' двух чисел данного экземпляра и числом двойной точности с плавающей
     * запятой, конечный результат присваивается экземпляру класса.
     * @param value - число двойной точности с плавающей запятой.
     * @return экземпляр класса с новым значением.
     */
    NDouble &operator /=( const NDouble &value ) noexcept;

    /**
     * @brief operator > - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра больше заданному значению.
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @return Значение true, если данного экземпляра больше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator >( const double &value ) const noexcept;

    /**
     * @brief operator > - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра больше заданному значению.
     * @param value - число двойной точности с плавающей запятой.
     * @return Значение true, если данного экземпляра больше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator >( const NDouble &value ) const noexcept;

    /**
     * @brief operator < - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра меньше заданному значению.
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator <( const double &value ) const noexcept;

    /**
     * @brief operator < - Оператор, указывающий, действительно ли заданное
     * значение данного экземпляра меньше заданному значению.
     * @param value - число двойной точности с плавающей запятой.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае — значение false.
     */
    bool operator <( const NDouble &value ) const noexcept;

    /**
     * @brief operator == - Оператор проверяет равны ли два заданных значения
     * данного экземпляра и числом двойной точности с плавающей запятой
     * стандартного типа double. Точность 6 знаков.
     * @param value - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @return Значение true, если значения равны в противном случае значение
     * false.
     */
    bool operator ==( const double &value ) const;

    /**
     * @brief operator == - Оператор проверяет равны ли два заданных значения
     * данного экземпляра и числом двойной точности с плавающей запятой.
     * Точность 6 знаков.
     * @param value - число двойной точности с плавающей запятой.
     * @return Значение true, если значения равны в противном случае значение
     * false.
     */
    bool operator ==( const NDouble &value ) const;

    /**
     * @brief operator - - Оператор, реализующий, операцию отрицания.
     * @return новое значение типа NDouble.
     */
    NDouble operator -() const noexcept;

    /**
     * @brief operator + - Оператор, возвращающий, сумму числа типа double и
     * число типа NDouble.
     * @param value1 - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @param value2 - число двойной точности с плавающей запятой.
     * @return сумма чисел значений NDouble.
     */
    friend NDouble operator +( const double &value1,
                               const NDouble &value2 ) noexcept;

    /**
     * @brief operator - - Оператор, возвращающий, разность числа типа double и
     * число типа NDouble.
     * @param value1 - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @param value2 - число двойной точности с плавающей запятой.
     * @return разность чисел значений NDouble.
     */
    friend NDouble operator -( const double &value1,
                               const NDouble &value2 ) noexcept;

    /**
     * @brief operator * - Оператор, возвращающий, произведения числа типа
     * double и число типа NDouble.
     * @param value1 - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @param value2 - число двойной точности с плавающей запятой.
     * @return произведения чисел значений NDouble.
     */
    friend NDouble operator *( const double &value1,
                               const NDouble &value2 ) noexcept;

    /**
     * @brief operator / - Оператор, возвращающий, частное числа типа double и
     * число типа NDouble.
     * @param value1 - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @param value2 - число двойной точности с плавающей запятой.
     * @return частное чисел значений NDouble.
     */
    friend NDouble operator /( const double &value1,
                               const NDouble &value2 ) noexcept;

    /**
     * @brief operator % Оператор, возвращающий, остаток от деления числа
     * типа double на число типа NDouble.
     * @param value1 - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @param value2 - число двойной точности с плавающей запятой.
     * @return остаток от деления(всегда полочительный).
     */
    friend NDouble operator %( const double &value1,
                               const NDouble &value2 ) noexcept;

    /**
     * @brief operator > - Оператор, указывающий, действительно ли заданное
     * значение числа типа double больше значения числа типа NDouble.
     * @param value1 - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @param value2 - число двойной точности с плавающей запятой.
     * @return Значение true, если данного экземпляра больше или равно заданному
     * значению в противном случае — значение false.
     */
    friend bool operator >( const double &value1,
                            const NDouble &value2 ) noexcept;

    /**
     * @brief operator < - Оператор, указывающий, действительно ли заданное
     * значение числа типа double меньше значения числа типа NDouble.
     * @param value1 - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @param value2 - число двойной точности с плавающей запятой.
     * @return Значение true, если данного экземпляра меньше или равно заданному
     * значению в противном случае — значение false.
     */
    friend bool operator <( const double &value1,
                            const NDouble &value2 ) noexcept;

    /**
     * @brief operator == - Оператор проверяет равно ли числа типа double и
     * число типа NDouble.
     * Точность 6 знаков.
     * @param value1 - число двойной точности с плавающей запятой стандартного
     * типа double.
     * @param value2 - число двойной точности с плавающей запятой.
     * @return Значение true, если значения равны в противном случае значение
     * false.
     */
    friend bool operator ==( const double &value1,
                             const NDouble &value2 ) noexcept;

private:
    bool operator >=( const double &value ) const;
    bool operator >=( const NDouble &value ) const;
    bool operator <=( const double &value ) const;
    bool operator <=( const NDouble &value ) const;
    bool operator !=( const double &value ) const;
    bool operator !=( const NDouble &value ) const;
};

inline bool NDouble::operator ==( const double &value ) const
{
    return this->compare( value );
}

inline bool NDouble::operator ==( const NDouble &value ) const
{
    return this->compare( value );
}

inline NDouble NDouble::operator -() const noexcept
{
    return NDouble( -this->value_ );
}

inline bool NDouble::isInfinity( const NDouble &value ) noexcept
{
    return ( ( value.value_ == NDouble::nInfinity.value_ ) ||
             ( value.value_ == NDouble::pInfinity.value_ ) );
}

inline bool NDouble::isNaN( const NDouble &value ) noexcept
{
    return !( value.value_ == value.value_ );
}

inline bool NDouble::isNegativeInfinity( const NDouble &value ) noexcept
{
    return NDouble::nInfinity.compare( value );
}

inline bool NDouble::isPositiveInfinity( const NDouble &value ) noexcept
{
    return NDouble::pInfinity.compare( value );
}

inline NDouble::NDouble() noexcept
{
    this->value_ = 0.0;
}

inline NDouble::NDouble( const double &value ) noexcept
{
    this->value_ = value;
}

inline NDouble::NDouble( const NDouble &value ) noexcept
    : INFloatingPoint<NDouble,double>(value)
{

}

inline NDouble::NDouble( NDouble &&value ) noexcept
{
    this->value_ = value.value_;
}

inline NDouble NDouble::entier() const noexcept
{
    double _ent = 0.0;
    modf( this->value_, &_ent );
    return NDouble( _ent );
}

inline NDouble NDouble::fraction() const noexcept
{
    double _ent = 0.0;
    return NDouble( modf( this->value_, &_ent ) );
}

inline bool NDouble::compare( const double &value,
                              NInt32 number ) const noexcept
{
    if( !( ( this->value_ > value ) || ( this->value_ < value ) ) )
        return true;
    double _n = 1.0;
    for( NInt32 i; i < number; i++ )
        _n *= 10.0;
    double _p;
    if( this->value_ > value )
        _p = this->value_ / _n;
    else
        _p = value / _n;
    return !( NDouble( this->value_ - value ).abs() > fabs( _p ) );
}

inline bool NDouble::compare( const NDouble &value, NInt32 number ) const noexcept
{
    return this->compare( value.value_, number );
}

inline bool NDouble::unequal( const double &value, NInt32 number ) const noexcept
{
    return !this->compare( value, number );
}

inline bool NDouble::unequal( const NDouble &value, NInt32 number ) const noexcept
{
    return !this->compare( value, number );
}

inline bool NDouble::moreThan( const double &value, NInt32 number ) const noexcept
{
    return ( ( *this > value ) || this->compare( value, number ) );
}

inline bool NDouble::moreThan( const NDouble &value, NInt32 number ) const noexcept
{
    return this->moreThan( value.value_, number );
}

inline bool NDouble::feverThan( const double &value, NInt32 number ) const noexcept
{
    return ( ( *this < value ) || this->compare( value, number ) );
}

inline bool NDouble::feverThan( const NDouble &value, NInt32 number ) const noexcept
{
    return this->feverThan( value.value_, number );
}

inline NDouble NDouble::ceil()
{
    return NDouble( ::ceil( this->value_ ) );
}

inline NDouble &NDouble::operator =( const double &value ) noexcept
{
    this->value_ = value;
    return *this;
}

inline NDouble &NDouble::operator =( const NDouble &value ) noexcept
{
    INFloatingPoint<NDouble,double>::operator=( value );
    return *this;
}

inline NDouble &NDouble::operator =( NDouble &&value ) noexcept
{
    this->value_ = value.value_;
    return *this;
}

inline NDouble NDouble::operator +( const double &value ) const noexcept
{
    NDouble _v( this->value_ + value );
    if( NDouble::isInfinity( _v ) )
    {
        std::wcerr << "Error! Infinity number! value1 = " << this->value_
                   << " and value2 = " << value << std::endl;
        if( this->value_ > 0 )
            return NDouble::maxValue;
        else
            return NDouble::minValue;
    }
    return _v;
}

inline NDouble NDouble::operator +( const NDouble &value ) const noexcept
{
    return ( *this + value.value_ );
}

inline NDouble NDouble::operator -( const double &value ) const noexcept
{
    NDouble _v( this->value_ - value );
    if( NDouble::isInfinity( _v ) )
    {
        std::wcerr << "Error! Infinity number! value1 = " << this->value_
                   << " and value2 = " << value << std::endl;
        if( this->value_ > 0 )
            return NDouble::maxValue;
        else
            return NDouble::minValue;
    }
    return _v;
}

inline NDouble NDouble::operator -( const NDouble &value ) const noexcept
{
    return ( *this - value.value_ );
}

inline NDouble &NDouble::operator++() noexcept
{
    if( NDouble::maxValue == this->value_ )
        std::wcerr << "Error! Overflow! this->value_ = "
                   << this->value_ << std::endl;
    else
        ++this->value_;
    return *this;
}

inline NDouble NDouble::operator++(int) noexcept
{
    NDouble v = *this;
    if( v == NDouble::maxValue )
        std::wcerr << "Error! Overflow! this->value_ = "
                   << this->value_ << std::endl;
    else
        ++(*this);
    return v;
}

inline NDouble &NDouble::operator--() noexcept
{
    if( NDouble::minValue == this->value_ )
        std::wcerr << "Error! Overflow! this->value_ = "
                   << this->value_ << std::endl;
    else
        --this->value_;
    return *this;
}

inline NDouble NDouble::operator--(int) noexcept
{
    NDouble v = *this;
    if( v == NDouble::minValue )
        std::wcerr << "Error! Overflow! this->value_ = "
                   << this->value_ << std::endl;
    else
        --(*this);
    return v;
}

inline NDouble NDouble::operator *( const double &value ) const noexcept
{
    NDouble _v( this->value_ * value );
    if( NDouble::isInfinity( _v ) )
    {
        std::wcerr << "Error! Infinity number! value1 = " << this->value_
                   << " and value2 = " << value << std::endl;
        if( this->value_ > 0 )
            return NDouble::maxValue;
        else
            return NDouble::minValue;
    }
    return _v;
}

inline NDouble NDouble::operator *( const NDouble &value ) const noexcept
{
    return ( *this * value.value_ );
}

inline NDouble NDouble::operator /( const double &value ) const noexcept
{
    NDouble _v( this->value_ / value );
    if( NDouble::isNaN( _v ) )
    {
        std::wcerr << "Error! 0 divide! value1 = " << this->value_
                << " and value2 = " << value << std::endl;
        return NDouble( 0.0 );
    }
    if( NDouble::isInfinity( _v ) )
    {
        std::wcerr << "Error! Infinity number!value1 = " << this->value_
                   << " and value2 = " << value << std::endl;
        if( this->value_ > 0 )
            return NDouble::maxValue;
        else
            return NDouble::minValue;
    }
    return _v;
}

inline NDouble NDouble::operator /( const NDouble &value ) const noexcept
{
    return *this / value.value_;
}

inline NDouble NDouble::operator %( const double &value ) const noexcept
{
    NDouble _r( fmod( this->value_, value ) );
    if( NDouble() > this->value_ )
        return NDouble( fabs( value ) ) - NDouble( fabs( _r.toType() ) );
    return _r;
}

inline NDouble NDouble::operator %( const NDouble &value ) const noexcept
{
    return *this % value.value_;
}

inline NDouble &NDouble::operator +=( const double &value ) noexcept
{
    this->value_ = this->value_ + value;
    return *this;
}

inline NDouble &NDouble::operator +=( const NDouble &value ) noexcept
{
    *this += value.value_;
    return *this;
}

inline NDouble &NDouble::operator -=( const double &value ) noexcept
{
    this->value_ = this->value_ - value;
    return *this;
}

inline NDouble &NDouble::operator -=( const NDouble &value ) noexcept
{
    *this -= value.value_;
    return *this;
}

inline NDouble &NDouble::operator *=( const double &value ) noexcept
{
    this->value_ *= value;
    return *this;
}

inline NDouble &NDouble::operator *=( const NDouble &value ) noexcept
{
    *this *= value.value_;
    return *this;
}

inline NDouble &NDouble::operator /=( const double &value ) noexcept
{
    *this = *this / value;
    return *this;
}

inline NDouble &NDouble::operator /=( const NDouble &value ) noexcept
{
    *this = *this / value;
    return *this;
}

inline bool NDouble::operator >( const double &value ) const noexcept
{
    return ( this->value_ > value );
}

inline bool NDouble::operator >( const NDouble &value ) const noexcept
{
    return ( *this > value.value_ );
}

inline bool NDouble::operator <( const double &value ) const noexcept
{
    return ( this->value_ < value);
}

inline bool NDouble::operator <( const NDouble &value ) const noexcept
{
    return ( *this < value.value_ );
}

inline NDouble operator +(const double &value1, const NDouble &value2 ) noexcept
{
    return value2 + value1;
}

inline NDouble operator -( const double &value1,
                           const NDouble &value2 ) noexcept
{
    return NDouble( value1 ) - value2;
}

inline NDouble operator *( const double &value1,
                           const NDouble &value2 ) noexcept
{
    return value2 * value1;
}

inline NDouble operator /( const double &value1,
                           const NDouble &value2 ) noexcept
{
    return NDouble( value1 ) / value2;
}

inline NDouble operator %( const double &value1,
                           const NDouble &value2 ) noexcept
{
    return NDouble( value1 ) % value2;
}

inline bool operator >( const double &value1, const NDouble &value2 ) noexcept
{
    return ( value1 > value2.value_ );
}

inline bool operator <( const double &value1, const NDouble &value2 ) noexcept
{
    return ( value1 < value2.value_ );
}

inline bool operator ==( const double &value1, const NDouble &value2 ) noexcept
{
    return value2.compare( value1 );
}

#endif // NDOUBLE_H
