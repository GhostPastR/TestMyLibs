#include "mpgrademinsecmsec.h"
#include <qdebug.h>

MpGradeMinSecMsec MpGradeMinSecMsec::convert( const MpAngle &coordinate )
{
    MpAngle _coordinate = coordinate;
    MpGradeMinSecMsec _gradeMinSecMsec;
    _gradeMinSecMsec.setDirection( _coordinate.d() < 0.0 );
    _coordinate = _coordinate.r().abs();
    _gradeMinSecMsec.setGrade( _coordinate.d().entier().toConvert<nint>() );
    nreal _minute = _coordinate.d().fraction() * 60.0;
    _gradeMinSecMsec.setMinute( _minute.entier().toConvert<nint>() );
    nreal _second = _minute.fraction() * 60.0;
    _gradeMinSecMsec.setSecond( _second.entier().toConvert<nint>() );
    _gradeMinSecMsec.setMsecond( ( _second.fraction() * 1000.0 )
                                 .entier().toConvert<nint>() );
    return _gradeMinSecMsec;
}
