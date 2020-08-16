#include "mpapproximation.h"

//QList<double> MpApproximation::approxData( const double &dStart, const double &dStop, const double &lenght, const double &interval )
//{
//    QList<double> _list;
//    double _dlen = 0;
//    if( lenght > 0 )
//    {
//        _dlen = ( dStop - dStart ) / lenght;
//    }
//    else
//    {
//        _dlen = 1.0;
//    }
//    double _len = 0.0;
//    while( _len < lenght )
//    {
//        _list.append( dStart + _dlen * _len );
//        _len += interval;
//    }
//    _list.append( dStop );
//    return _list;
//}

//QList<double> MpApproximation::approxData( const double &dStart, const double &dStop, const double &lenght, const double &interval, double &del )
//{
//    QList<double> _list;
//    double _dlen = 0;
//    if( lenght > 0 )
//    {
//        _dlen = ( dStop - dStart ) / lenght;
//    }
//    else
//    {
//        _dlen = 1.0;
//    }
//    double _len = interval - del;
//    while( _len < lenght )
//    {
//        _list.append( dStart + _dlen * _len );
//        _len += interval;
//    }
//    return _list;
//}

//QList<MpPoint> MpApproximation::approxIntervalLine( const MpLineSection &line, double &del )
//{
//    QList<MpPoint> _list;
//    double _lenStage = line.length();
//    double _len = 0;
//    if( del > 0 )
//    {
//        _len = this->interval_ - del;
//    }
//    if( _len > _lenStage )
//    {
//        del = _lenStage + _lenStage;
//        return QList<MpPoint>();
//    }
//    double _angle = line.angle();
//    while( _len < _lenStage )
//    {
//        _list.append( MpPoint::getCoordinate( _angle, _len, line.start() ) );
//        _len += this->interval_;
//    }
//    del = _lenStage - ( _len - this->interval_ );
//    return _list;
//}

//QList<MpPoint> MpApproximation::approxIntervalArc( const MpArc &arc, double &del )
//{
//    QList<MpPoint> _list;
//    double _lenStage = arc.lengthArc();
//    double _len = 0;
//    if( del > 0 )
//    {
//        _len = this->interval_ - del;
//    }
//    if( _len > _lenStage )
//    {
//        del = _lenStage + _lenStage;
//        return QList<MpPoint>();
//    }
//    _lenStage = _lenStage / arc.radius();
//    double _delStart = _len / arc.radius();
//    double _delAngle = this->interval_ / arc.radius();
//    double _angleStart = arc.angleStart();

//    if( arc.direct() == MpArc::LEFT )
//    {
//        while( _delStart < _lenStage )
//        {
//            _list.append( MpPoint::getCoordinate( _angleStart - _delStart, arc.radius(), arc.center() ) );
//            _delStart += _delAngle;
//        }
//    }
//    else
//    {
//        while( _delStart < _lenStage )
//        {
//            _list.append( MpPoint::getCoordinate( _angleStart + _delStart, arc.radius(), arc.center() ) );
//            _delStart += _delAngle;
//        }
//    }
//    del = arc.lengthArc() - ( _delStart - _delAngle ) * arc.radius();
//    return _list;
//}


class MpApproximationPrivat
{
public:
    typedef std::shared_ptr<MpLineSection> SMpLineSection;
    typedef std::shared_ptr<MpArc> SMpArc;
    typedef std::shared_ptr<MpFigure> SMpFigure;
    typedef QList<MpFigure> LMpFigure;

    MpApproximationPrivat( const MpLineSection &lineSection );
    MpApproximationPrivat( const MpArc &arc );
    MpApproximationPrivat( const MpFigure &figure );
    MpApproximationPrivat( const QList<MpFigure> &lfigure );

    void setLineSection( const MpLineSection &lineSection );
    void setArc( const MpArc &arc );
    void setFigure( const MpFigure &figure );
    void setLFigure( const QList<MpFigure> &lfigure );

    bool isLineSection() const;
    bool isArc() const;
    bool isFigure() const;
    bool isLFigure() const;

    const MpLineSection &lineSection() const;
    const MpArc &arc() const;
    const MpFigure &figure() const;
    const QList<MpFigure> &lfigure() const;

private:
    SMpLineSection lineSection_;
    SMpArc arc_;
    SMpFigure figure_;
    LMpFigure listFigure_;
};

MpApproximationPrivat::MpApproximationPrivat( const MpLineSection &lineSection )
{
    this->setLineSection( lineSection );
}

MpApproximationPrivat::MpApproximationPrivat( const MpArc &arc )
{
    this->setArc( arc );
}

MpApproximationPrivat::MpApproximationPrivat( const MpFigure &figure )
{
    this->setFigure( figure );
}

MpApproximationPrivat::MpApproximationPrivat( const QList<MpFigure> &lfigure )
{
    this->setLFigure( lfigure );
}

void MpApproximationPrivat::setLineSection( const MpLineSection &lineSection )
{
    this->arc_.reset();
    this->figure_.reset();
    this->listFigure_.clear();
    this->lineSection_.reset( new MpLineSection( lineSection ) );
}

void MpApproximationPrivat::setArc( const MpArc &arc )
{
    this->lineSection_.reset();
    this->figure_.reset();
    this->listFigure_.clear();
    this->arc_.reset( new MpArc( arc ) );
}

void MpApproximationPrivat::setFigure( const MpFigure &figure )
{
    this->lineSection_.reset();
    this->arc_.reset();
    this->listFigure_.clear();
    this->figure_.reset( new MpFigure( figure ) );
}

void MpApproximationPrivat::setLFigure( const QList<MpFigure> &lfigure )
{
    this->lineSection_.reset();
    this->arc_.reset();
    this->figure_.reset();
    this->listFigure_ = lfigure;
}

bool MpApproximationPrivat::isLineSection() const
{
    return ( this->lineSection_.get() != nullptr );
}

bool MpApproximationPrivat::isArc() const
{
    return ( this->arc_.get() != nullptr );
}

bool MpApproximationPrivat::isFigure() const
{
    return ( this->figure_.get() != nullptr );
}

bool MpApproximationPrivat::isLFigure() const
{
    return !this->listFigure_.isEmpty();
}

const MpLineSection &MpApproximationPrivat::lineSection() const
{
    return *this->lineSection_.get();
}

const MpArc &MpApproximationPrivat::arc() const
{
    return *this->arc_.get();
}

const MpFigure &MpApproximationPrivat::figure() const
{
    return *this->figure_.get();
}

const QList<MpFigure> &MpApproximationPrivat::lfigure() const
{
    return this->listFigure_;
}





MpApproximation::MpApproximation( const MpLineSection &lineSection,
                                  const nreal &interval )
{
    this->setInterval( interval );
    this->ptr_.reset( new MpApproximationPrivat( lineSection ) );
}

MpApproximation::MpApproximation( const MpArc &arc, const nreal &interval )
{
    this->setInterval( interval );
    this->ptr_.reset( new MpApproximationPrivat( arc ) );
}

MpApproximation::MpApproximation( const MpFigure &figure,
                                  const nreal &interval )
{
    this->setInterval( interval );
    this->ptr_.reset( new MpApproximationPrivat( figure ) );
}

MpApproximation::MpApproximation( const QList<MpFigure> &listFigure,
                                  const nreal &interval )
{
    this->setInterval( interval );
    this->ptr_.reset( new MpApproximationPrivat( listFigure ) );
}

QList<MpPoint> MpApproximation::approximation( bool equidistant ) const
{
    if( this->ptr_->isLineSection() )
        return this->approximation( this->ptr_->lineSection(), equidistant );
    if( this->ptr_->isArc() )
        return this->approximation( this->ptr_->arc(), equidistant );
    if( this->ptr_->isFigure() )
        return this->approximation( this->ptr_->figure(), equidistant );
    if( this->ptr_->isLFigure() )
        return this->approximation( this->ptr_->lfigure(), equidistant );
    return QList<MpPoint>();
}

QList<MpPoint> MpApproximation::approximation( const MpLineSection &line,
                                               bool equidistant ) const
{
    QList<MpPoint> _listPoint;
    nreal _length = line.length();
    nreal _interval = this->interval_;
    if( equidistant )
        _interval = this->equidistantIterval( _length );
    nreal _len;
    MpAngle _angle = line.angle();
    if( !_interval.compare( nreal() ) )
        this->calcPointLineSection( line, _listPoint, _len, _length, _interval );
    _listPoint.append( line.stop() );
    return _listPoint;
}

QList<MpPoint> MpApproximation::approximation( const MpArc &arc,
                                               bool equidistant ) const
{
    QList<MpPoint> _listPoint;
    nreal _length = arc.lengthArc();
    nreal _interval = this->interval_;
    if( equidistant )
        _interval = this->equidistantIterval( _length );
    nreal _lenStage = _length / arc.radius();
    MpAngle _delStart;
    MpAngle _delAngle( _interval / arc.radius() );
    MpAngle _angleStart = arc.angleStart();
    if( !_interval.compare( nreal() ) )
        this->calcPointArc( arc, _listPoint, _delStart, _lenStage,
                                                       _delAngle, _angleStart );
    _listPoint.append( MpPoint::newPoint( arc.angleStop(), arc.radius(),
                                          arc.center() ) );

    return _listPoint;
}

QList<MpPoint> MpApproximation::approximation( const MpFigure &figure,
                                               bool equidistant ) const
{
    if( figure.figureArc() )
        return this->approximation( figure.arc(), equidistant );
    if( figure.figureLineSection() )
        return this->approximation( figure.lineSection(), equidistant );
    return QList<MpPoint>();
}

QList<MpPoint> MpApproximation::approximation( const QList<MpFigure> &lFigure,
                                               bool equidistant ) const
{
    if( lFigure.isEmpty() )
        return QList<MpPoint>();
    QList<MpPoint> _listPoint;
    nreal _length = MpFigure::lehghtFigure( lFigure );
    nreal _interval = this->interval_;
    if( equidistant )
        _interval = this->equidistantIterval( _length );
    if( !_interval.compare( nreal() ) )
        return _listPoint;
    nreal _ds;
    for( auto i : lFigure )
    {
        if( i.figureArc() )
        {
            nreal _lenStage = i.arc().lengthArc();
            nreal _len;
            if( _ds > nreal() )
                _len = _interval - _ds;
            if( _len > _lenStage )
            {
                _ds = _lenStage + _lenStage;
                continue;
            }
            _lenStage = _lenStage / i.arc().radius();
            MpAngle _delStart( _len / i.arc().radius() );
            MpAngle _delAngle( _interval / i.arc().radius() );
            MpAngle _angleStart = i.arc().angleStart();
            this->calcPointArc( i.arc(), _listPoint, _delStart, _lenStage,
                                _delAngle, _angleStart );
            _ds = i.arc().lengthArc() - ( _delStart - _delAngle ).r()
                    * i.arc().radius();
        }
        else if( i.figureLineSection() )
        {
            nreal _lenStage = i.lineSection().length();
            nreal _len;
            if( _ds > nreal() )
                _len = _interval - _ds;
            if( _len > _lenStage )
            {
                _ds = _lenStage + _lenStage;
                continue;
            }
            this->calcPointLineSection( i.lineSection(), _listPoint, _len,
                                        _lenStage, _interval );
            _ds = _lenStage - ( _len - _interval );
        }
    }
    return _listPoint;
}

nreal MpApproximation::equidistantIterval( const nreal &length ) const
{
    nreal _c = ( length / this->interval_ ).entier();
    if( _c.compare( nreal() ) )
        return nreal();
    return length / _c;
}

void MpApproximation::calcPointLineSection( const MpLineSection &lineSection,
                                            QList<MpPoint> &listPoint,
                                            nreal &lenIterator,
                                            const nreal &lenStage,
                                            const nreal &interval ) const
{
    while( lenIterator < lenStage )
    {
        listPoint.append( std::move( MpPoint::newPoint( lineSection.angle(),
                                         lenIterator, lineSection.start() ) ) );
        lenIterator += interval;
    }
}

void MpApproximation::calcPointArc( const MpArc &arc,
                                    QList<MpPoint> &listPoint,
                                    MpAngle &lenIterator,
                                    const nreal &lenStage,
                                    const MpAngle &interval,
                                    const MpAngle &angleStart ) const
{
    auto _while = [&]( const nreal &sign )
    {
        while( lenIterator < lenStage )
        {
            listPoint.append( std::move( MpPoint::newPoint(
                                          angleStart + lenIterator * sign,
                                          arc.radius(), arc.center() ) ) );
            lenIterator += interval;
        }
    };
    if( arc.direct() == MpDirect::EN_D_LEFT )
        _while( nreal( -1.0 ) );
    else
        _while( nreal( 1.0 ) );
}


