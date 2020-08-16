#ifndef IMPARC_H
#define IMPARC_H

#include <mpangle.h>

//!Список содержащий направление дуги
enum class MpDirect
{
    EN_D_NONE  = 0,  //!Направление не задано
    EN_D_LEFT  = -1, //!Направление против часовой стрелки от начало
    EN_D_RIGHT = 1,  //!Направление по часовой стрелки от начало
};

template<class P>
/**
 * @brief The IMpArc class - Класс интерфейс для новых классов описывающие
 * геометрический примитив дуга.
 */
class IMpArc
{
public:
    const MpAngle &angleStart() const noexcept;
    const MpAngle &angleStop() const noexcept;
    MpDirect direct() const noexcept;
    const nreal &radius() const noexcept;
    const P &center() const noexcept;

    void setAngleStart( const MpAngle &startAngle ) noexcept;
    void setAngleStop( const MpAngle &stopAngle ) noexcept;
    void setDirect( MpDirect direct ) noexcept;
    void setRadius( const nreal &radius ) noexcept;
    void setCenter( const P &center ) noexcept;

    //! \brief convert - статический метод меняет направление
    //! \param direct - значения направления
    //! \return - конвертированное направление
    static MpDirect convert( MpDirect direct ) noexcept;

protected:
    IMpArc();
    IMpArc( const nreal &radius, const MpAngle &courseStart,
            const MpAngle &courseStop, MpDirect direct );
    IMpArc( const IMpArc &iMpArc );
    IMpArc( IMpArc &&iMpArc );
    ~IMpArc();

    IMpArc &operator=( const IMpArc &iMpArc );
    IMpArc &operator=( IMpArc &&iMpArc );

    /**
     * @brief angleStart_ - Направления от центра к 1-й точки дуги.
     */
    MpAngle angleStart_;
    /**
     * @brief angleStop_ - Направления от центра ко 2-й точки дуги.
     */
    MpAngle angleStop_;
    /**
     * @brief direct_ - Направление дуги.
     */
    MpDirect direct_;
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
inline IMpArc<P>::IMpArc() : direct_(MpDirect::EN_D_RIGHT) {}

template<class P>
inline IMpArc<P>::IMpArc( const nreal &radius, const MpAngle &angleStart,
                          const MpAngle &angleStop, MpDirect direct )
    : angleStart_(angleStart), angleStop_(angleStop),
      direct_(direct), radius_(radius) {}

template<class P>
inline IMpArc<P>::IMpArc( const IMpArc &iMpArc )
{
    this->angleStart_ = iMpArc.angleStart_;
    this->angleStop_ = iMpArc.angleStop_;
    this->direct_ = iMpArc.direct_;
    this->radius_ = iMpArc.radius_;
    this->center_ = iMpArc.center_;
}

template<class P>
inline IMpArc<P>::IMpArc( IMpArc &&iMpArc )
{
    this->angleStart_ = std::move( iMpArc.angleStart_ );
    this->angleStop_ = std::move( iMpArc.angleStop_ );
    this->direct_ = std::move( iMpArc.direct_ );
    this->radius_ = std::move( iMpArc.radius_ );
    this->center_ = std::move( iMpArc.center_ );
}

template<class P>
inline IMpArc<P>::~IMpArc(){}

template<class P>
inline IMpArc<P> &IMpArc<P>::operator=( const IMpArc &iMpArc )
{
    this->angleStart_ = iMpArc.angleStart_;
    this->angleStop_ = iMpArc.angleStop_;
    this->direct_ = iMpArc.direct_;
    this->radius_ = iMpArc.radius_;
    this->center_ = iMpArc.center_;
    return *this;
}

template<class P>
inline IMpArc<P> &IMpArc<P>::operator=( IMpArc &&iMpArc )
{
    this->angleStart_ = std::move( iMpArc.angleStart_ );
    this->angleStop_ = std::move( iMpArc.angleStop_ );
    this->direct_ = std::move( iMpArc.direct_ );
    this->radius_ = std::move( iMpArc.radius_ );
    this->center_ = std::move( iMpArc.center_ );
    return *this;
}

template<class P>
inline const MpAngle &IMpArc<P>::angleStart() const noexcept
{
    return this->angleStart_;
}

template<class P>
inline const MpAngle &IMpArc<P>::angleStop() const noexcept
{
    return this->angleStop_;
}

template<class P>
inline MpDirect IMpArc<P>::direct() const noexcept
{
    return this->direct_;
}

template<class P>
inline const nreal &IMpArc<P>::radius() const noexcept
{
    return this->radius_;
}

template<class P>
inline const P &IMpArc<P>::center() const noexcept
{
    return this->center_;
}

template<class P>
inline void IMpArc<P>::setAngleStart( const MpAngle &angleStart ) noexcept
{
    this->angleStart_ = angleStart;
}

template<class P>
inline void IMpArc<P>::setAngleStop( const MpAngle &angleStop ) noexcept
{
    this->angleStop_ = angleStop;
}

template<class P>
inline void IMpArc<P>::setDirect( MpDirect direct ) noexcept
{
    if( ( direct == MpDirect::EN_D_NONE ) ||
            ( direct == MpDirect::EN_D_LEFT ) ||
            ( direct == MpDirect::EN_D_RIGHT )  )
        this->direct_ = direct;
    else
    {
        std::wcerr << "Error! Arc direct != NONE, LEFT, RIGHT!" << std::endl;
        this->direct_ = MpDirect::EN_D_RIGHT;
    }
}

template<class P>
inline void IMpArc<P>::setRadius( const nreal &radius ) noexcept
{
    this->radius_ = radius;
}

template<class P>
inline void IMpArc<P>::setCenter( const P &center ) noexcept
{
    this->center_ = center;
}

template<class P>
inline MpDirect IMpArc<P>::convert( MpDirect direct ) noexcept
{
    if( direct == MpDirect::EN_D_LEFT )
        return MpDirect::EN_D_RIGHT;
    if( direct == MpDirect::EN_D_RIGHT )
        return MpDirect::EN_D_LEFT;
    return direct;
}

#endif // IMPARC_H
