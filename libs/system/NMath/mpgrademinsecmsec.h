#ifndef MPGRADEMINSECMSEC_H
#define MPGRADEMINSECMSEC_H

#include <mpangle.h>
#include <ntype.h>
#include "mpbase.h"

class MpGradeMinSecMsec
{
public:
    MpGradeMinSecMsec();
    MpGradeMinSecMsec( bool direction, nint grade, nint minute,
                       nint second, nint msecond );
    ~MpGradeMinSecMsec();

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

    static MpGradeMinSecMsec convert( const MpAngle &coordinate );

protected:
    bool direction_;
    nint grade_;
    nint minute_;
    nint second_;
    nint msecond_;
};

inline MpGradeMinSecMsec::MpGradeMinSecMsec()
 : direction_(false),grade_(0),minute_(0),second_(0),msecond_(0){}

inline MpGradeMinSecMsec::MpGradeMinSecMsec( bool direction, nint grade,
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

inline MpGradeMinSecMsec::~MpGradeMinSecMsec(){}

inline bool MpGradeMinSecMsec::direction() const
{
    return this->direction_;
}

inline nint MpGradeMinSecMsec::grade() const
{
    return this->grade_;
}

inline nint MpGradeMinSecMsec::minute() const
{
    return this->minute_;
}

inline nint MpGradeMinSecMsec::second() const
{
    return this->second_;
}

inline nint MpGradeMinSecMsec::msecond() const
{
    return this->msecond_;
}

inline void MpGradeMinSecMsec::setDirection( bool direction )
{
    this->direction_ = direction;
}

inline void MpGradeMinSecMsec::setGrade( nint grade )
{
    if( grade.intervalStrict( 0, 180 ) )
        this->grade_ = grade;
    else
        std::cerr << "Warning MpLibs class MpGradeMinSecMsec, "
                     "method setGrade()!!! grade < 0 || grade > 180"
                  << std::endl;
}

inline void MpGradeMinSecMsec::setMinute( nint minute )
{
    if( minute.intervalStrict( 0, 59 ) )
        this->minute_ = minute;
    else
        std::cerr << "Warning MpLibs class MpGradeMinSecMsec, method "
                     "setMinute()!!! minute < 0 || minute > 59"
                  << std::endl;
}

inline void MpGradeMinSecMsec::setSecond( nint second )
{
    if( second.intervalStrict( 0, 59 ) )
        this->second_ = second;
    else
        std::cerr << "Warning MpLibs class MpGradeMinSecMsec, method "
                     "setSecond()!!! second < 0 || second > 59"
                  << std::endl;
}

inline void MpGradeMinSecMsec::setMsecond( nint msecond )
{
    if( msecond.intervalStrict( 0 , 999 ) )
        this->msecond_ = msecond;
    else
        std::cerr << "Warning MpLibs class MpGradeMinSecMsec, method "
                     "setMsecond()!!! msecond < 0 || msecond > 999"
                  << std::endl;
}

#endif // MPGRADEMINSECMSEC_H
