#ifndef NGRADEMINSECMSEC_H
#define NGRADEMINSECMSEC_H

#include <nangle.h>
#include <ntype.h>
#include "nbase.h"

class NGradeMinSecMsec
{
public:
    NGradeMinSecMsec();
    NGradeMinSecMsec( bool direction, nint grade, nint minute,
                       nint second, nint msecond );
    ~NGradeMinSecMsec();

    bool direction() const;
    nint grade() const;
    nint minute() const;
    nint second() const;
    nint msecond() const;

    void setDirection( bool direction );
    void setGrade( nint grade );
    void setMinute( nint minute );
    void setSecond( nint second );
    void setMsecond( nint msecond );

    static NGradeMinSecMsec convert( const NAngle &coordinate );

protected:
    bool direction_;
    nint grade_;
    nint minute_;
    nint second_;
    nint msecond_;
};

inline NGradeMinSecMsec::NGradeMinSecMsec()
 : direction_(false),grade_(0),minute_(0),second_(0),msecond_(0){}

inline NGradeMinSecMsec::NGradeMinSecMsec( bool direction, nint grade,
                                             nint minute, nint second,
                                             nint msecond )
{
    this->grade_ = 0;
    this->minute_ = 0;
    this->second_ = 0;
    this->msecond_ = 0;
    this->setDirection( direction );
    this->setGrade( grade );
    this->setMinute( minute );
    this->setSecond( second );
    this->setMsecond( msecond );
}

inline NGradeMinSecMsec::~NGradeMinSecMsec(){}

inline bool NGradeMinSecMsec::direction() const
{
    return this->direction_;
}

inline nint NGradeMinSecMsec::grade() const
{
    return this->grade_;
}

inline nint NGradeMinSecMsec::minute() const
{
    return this->minute_;
}

inline nint NGradeMinSecMsec::second() const
{
    return this->second_;
}

inline nint NGradeMinSecMsec::msecond() const
{
    return this->msecond_;
}

inline void NGradeMinSecMsec::setDirection( bool direction )
{
    this->direction_ = direction;
}

inline void NGradeMinSecMsec::setGrade( nint grade )
{
    if( grade.intervalStrict( 0, 180 ) )
        this->grade_ = grade;
    else
        std::cerr << "Warning MpLibs class NGradeMinSecMsec, "
                     "method setGrade()!!! grade < 0 || grade > 180"
                  << std::endl;
}

inline void NGradeMinSecMsec::setMinute( nint minute )
{
    if( minute.intervalStrict( 0, 59 ) )
        this->minute_ = minute;
    else
        std::cerr << "Warning MpLibs class NGradeMinSecMsec, method "
                     "setMinute()!!! minute < 0 || minute > 59"
                  << std::endl;
}

inline void NGradeMinSecMsec::setSecond( nint second )
{
    if( second.intervalStrict( 0, 59 ) )
        this->second_ = second;
    else
        std::cerr << "Warning MpLibs class NGradeMinSecMsec, method "
                     "setSecond()!!! second < 0 || second > 59"
                  << std::endl;
}

inline void NGradeMinSecMsec::setMsecond( nint msecond )
{
    if( msecond.intervalStrict( 0 , 999 ) )
        this->msecond_ = msecond;
    else
        std::cerr << "Warning MpLibs class NGradeMinSecMsec, method "
                     "setMsecond()!!! msecond < 0 || msecond > 999"
                  << std::endl;
}

#endif // NGRADEMINSECMSEC_H
