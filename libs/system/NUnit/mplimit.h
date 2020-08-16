#ifndef MPLIMIT_H
#define MPLIMIT_H

#include <iostream>

template<class T>
class MpLimit
{
public:
    MpLimit( const T &min, const T &max ) noexcept;
    MpLimit( const MpLimit &mpLimit );
    MpLimit( MpLimit &&mpLimit );

    const T &min() const noexcept;
    void setMin( const T &min ) noexcept;

    const T &max() const noexcept;
    void setMax( const T &max ) noexcept;

    static bool checkValue( const T &min, const T &max,
                            const T &value ) noexcept;

    MpLimit &operator=( const MpLimit &mpLimit );
    MpLimit &operator=( MpLimit &&mpLimit );

private:
    T min_;
    T max_;
};

template<class T>
inline MpLimit<T>::MpLimit( const T &min, const T &max ) noexcept
{
    this->min_ = min;
    this->max_ = max;
}

template<class T>
inline MpLimit<T>::MpLimit( const MpLimit &mpLimit )
{
    this->min_ = mpLimit.min_;
    this->max_ = mpLimit.max_;
}

template<class T>
inline MpLimit<T>::MpLimit( MpLimit &&mpLimit )
{
    this->min_ = std::move( mpLimit.min_ );
    this->max_ = std::move( mpLimit.max_ );
}

template<class T>
inline const T &MpLimit<T>::min() const noexcept
{
    return this->min_;
}

template<class T>
inline void MpLimit<T>::setMin( const T &min ) noexcept
{
    min_ = min;
}

template<class T>
inline const T &MpLimit<T>::max() const noexcept
{
    return this->max_;
}

template<class T>
inline void MpLimit<T>::setMax( const T &max ) noexcept
{
    max_ = max;
}

template<class T>
inline bool MpLimit<T>::checkValue( const T &min, const T &max,
                                    const T &value ) noexcept
{
    if( ( min <= value ) && ( value <= max ) )
        return true;
    std::wcerr << "Error! Out-of-range value!" << std::endl;
    return false;
}

template<class T>
inline MpLimit<T> &MpLimit<T>::operator=( const MpLimit &mpLimit )
{
    this->min_ = mpLimit.min_;
    this->max_ = mpLimit.max_;
    return *this;
}

template<class T>
inline MpLimit<T> &MpLimit<T>::operator=( MpLimit &&mpLimit )
{
    this->min_ = std::move( mpLimit.min_ );
    this->max_ = std::move( mpLimit.max_ );
    return *this;
}

#endif // MPLIMIT_H

