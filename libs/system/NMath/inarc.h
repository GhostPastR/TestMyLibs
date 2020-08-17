#ifndef INARC_H
#define INARC_H

#include <nangle.h>

//!Список содержащий направление дуги
enum class NDirect
{
    EN_D_NONE  = 0,  //!Направление не задано
    EN_D_LEFT  = -1, //!Направление против часовой стрелки от начало
    EN_D_RIGHT = 1,  //!Направление по часовой стрелки от начало
};

template<class P>
/**
 * @brief The INArc class - Класс интерфейс для новых классов описывающие
 * геометрический примитив дуга.
 */
class INArc
{
public:
    const NAngle &angleStart() const noexcept;
    const NAngle &angleStop() const noexcept;
    NDirect direct() const noexcept;
    const nreal &radius() const noexcept;
    const P &center() const noexcept;

    void setAngleStart( const NAngle &startAngle ) noexcept;
    void setAngleStop( const NAngle &stopAngle ) noexcept;
    void setDirect( NDirect direct ) noexcept;
    void setRadius( const nreal &radius ) noexcept;
    void setCenter( const P &center ) noexcept;

    //! \brief convert - статический метод меняет направление
    //! \param direct - значения направления
    //! \return - конвертированное направление
    static NDirect convert( NDirect direct ) noexcept;

protected:
    INArc();
    INArc( const nreal &radius, const NAngle &courseStart,
            const NAngle &courseStop, NDirect direct );
    INArc( const INArc &INArc );
    INArc( INArc &&INArc );
    ~INArc();

    INArc &operator=( const INArc &INArc );
    INArc &operator=( INArc &&INArc );

    /**
     * @brief angleStart_ - Направления от центра к 1-й точки дуги.
     */
    NAngle angleStart_;
    /**
     * @brief angleStop_ - Направления от центра ко 2-й точки дуги.
     */
    NAngle angleStop_;
    /**
     * @brief direct_ - Направление дуги.
     */
    NDirect direct_;
    /**
     * @brief radius_ - Радиус дуги.
     */
    nreal radius_;
    /**
     * @brief center_ - Координаты центра дуги
     */
    P center_;
};

template<class P>
inline INArc<P>::INArc() : direct_(NDirect::EN_D_RIGHT) {}

template<class P>
inline INArc<P>::INArc( const nreal &radius, const NAngle &angleStart,
                          const NAngle &angleStop, NDirect direct )
    : angleStart_(angleStart), angleStop_(angleStop),
      direct_(direct), radius_(radius) {}

template<class P>
inline INArc<P>::INArc( const INArc &INArc )
{
    this->angleStart_ = INArc.angleStart_;
    this->angleStop_ = INArc.angleStop_;
    this->direct_ = INArc.direct_;
    this->radius_ = INArc.radius_;
    this->center_ = INArc.center_;
}

template<class P>
inline INArc<P>::INArc( INArc &&INArc )
{
    this->angleStart_ = std::move( INArc.angleStart_ );
    this->angleStop_ = std::move( INArc.angleStop_ );
    this->direct_ = std::move( INArc.direct_ );
    this->radius_ = std::move( INArc.radius_ );
    this->center_ = std::move( INArc.center_ );
}

template<class P>
inline INArc<P>::~INArc(){}

template<class P>
inline INArc<P> &INArc<P>::operator=( const INArc &INArc )
{
    this->angleStart_ = INArc.angleStart_;
    this->angleStop_ = INArc.angleStop_;
    this->direct_ = INArc.direct_;
    this->radius_ = INArc.radius_;
    this->center_ = INArc.center_;
    return *this;
}

template<class P>
inline INArc<P> &INArc<P>::operator=( INArc &&INArc )
{
    this->angleStart_ = std::move( INArc.angleStart_ );
    this->angleStop_ = std::move( INArc.angleStop_ );
    this->direct_ = std::move( INArc.direct_ );
    this->radius_ = std::move( INArc.radius_ );
    this->center_ = std::move( INArc.center_ );
    return *this;
}

template<class P>
inline const NAngle &INArc<P>::angleStart() const noexcept
{
    return this->angleStart_;
}

template<class P>
inline const NAngle &INArc<P>::angleStop() const noexcept
{
    return this->angleStop_;
}

template<class P>
inline NDirect INArc<P>::direct() const noexcept
{
    return this->direct_;
}

template<class P>
inline const nreal &INArc<P>::radius() const noexcept
{
    return this->radius_;
}

template<class P>
inline const P &INArc<P>::center() const noexcept
{
    return this->center_;
}

template<class P>
inline void INArc<P>::setAngleStart( const NAngle &angleStart ) noexcept
{
    this->angleStart_ = angleStart;
}

template<class P>
inline void INArc<P>::setAngleStop( const NAngle &angleStop ) noexcept
{
    this->angleStop_ = angleStop;
}

template<class P>
inline void INArc<P>::setDirect( NDirect direct ) noexcept
{
    if( ( direct == NDirect::EN_D_NONE ) ||
            ( direct == NDirect::EN_D_LEFT ) ||
            ( direct == NDirect::EN_D_RIGHT )  )
        this->direct_ = direct;
    else
    {
        std::wcerr << "Error! Arc direct != NONE, LEFT, RIGHT!" << std::endl;
        this->direct_ = NDirect::EN_D_RIGHT;
    }
}

template<class P>
inline void INArc<P>::setRadius( const nreal &radius ) noexcept
{
    this->radius_ = radius;
}

template<class P>
inline void INArc<P>::setCenter( const P &center ) noexcept
{
    this->center_ = center;
}

template<class P>
inline NDirect INArc<P>::convert( NDirect direct ) noexcept
{
    if( direct == NDirect::EN_D_LEFT )
        return NDirect::EN_D_RIGHT;
    if( direct == NDirect::EN_D_RIGHT )
        return NDirect::EN_D_LEFT;
    return direct;
}

#endif // INARC_H
