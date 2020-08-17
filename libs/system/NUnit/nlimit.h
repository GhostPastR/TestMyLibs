#ifndef NLIMIT_H
#define NLIMIT_H

#include <iostream>

template<class T>
class NLimit
{
public:
    NLimit( const T &min, const T &max ) noexcept;
    NLimit( const NLimit &NLimit );
    NLimit( NLimit &&NLimit );

    const T &min() const noexcept;
    void setMin( const T &min ) noexcept;

    const T &max() const noexcept;
    void setMax( const T &max ) noexcept;

    static bool checkValue( const T &min, const T &max,
                            const T &value ) noexcept;

    NLimit &operator=( const NLimit &NLimit );
    NLimit &operator=( NLimit &&NLimit );

private:
    T min_;
    T max_;
};

template<class T>
inline NLimit<T>::NLimit( const T &min, const T &max ) noexcept
{
    this->min_ = min;
    this->max_ = max;
}

template<class T>
inline NLimit<T>::NLimit( const NLimit &NLimit )
{
    this->min_ = NLimit.min_;
    this->max_ = NLimit.max_;
}

template<class T>
inline NLimit<T>::NLimit( NLimit &&NLimit )
{
    this->min_ = std::move( NLimit.min_ );
    this->max_ = std::move( NLimit.max_ );
}

template<class T>
inline const T &NLimit<T>::min() const noexcept
{
    return this->min_;
}

template<class T>
inline void NLimit<T>::setMin( const T &min ) noexcept
{
    min_ = min;
}

template<class T>
inline const T &NLimit<T>::max() const noexcept
{
    return this->max_;
}

template<class T>
inline void NLimit<T>::setMax( const T &max ) noexcept
{
    max_ = max;
}

template<class T>
inline bool NLimit<T>::checkValue( const T &min, const T &max,
                                    const T &value ) noexcept
{
    if( ( min <= value ) && ( value <= max ) )
        return true;
    std::wcerr << "Error! Out-of-range value!" << std::endl;
    return false;
}

template<class T>
inline NLimit<T> &NLimit<T>::operator=( const NLimit &NLimit )
{
    this->min_ = NLimit.min_;
    this->max_ = NLimit.max_;
    return *this;
}

template<class T>
inline NLimit<T> &NLimit<T>::operator=( NLimit &&NLimit )
{
    this->min_ = std::move( NLimit.min_ );
    this->max_ = std::move( NLimit.max_ );
    return *this;
}

#endif // NLIMIT_H

