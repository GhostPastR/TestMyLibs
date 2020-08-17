#include "napproximation.h"

//QList<double> NApproximation::approxData( const double &dStart, const double &dStop, const double &lenght, const double &interval )
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

//QList<double> NApproximation::approxData( const double &dStart, const double &dStop, const double &lenght, const double &interval, double &del )
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

//QList<NPoint> NApproximation::approxIntervalLine( const NLineSection &line, double &del )
//{
//    QList<NPoint> _list;
//    double _lenStage = line.length();
//    double _len = 0;
//    if( del > 0 )
//    {
//        _len = this->interval_ - del;
//    }
//    if( _len > _lenStage )
//    {
//        del = _lenStage + _lenStage;
//        return QList<NPoint>();
//    }
//    double _angle = line.angle();
//    while( _len < _lenStage )
//    {
//        _list.append( NPoint::getCoordinate( _angle, _len, line.start() ) );
//        _len += this->interval_;
//    }
//    del = _lenStage - ( _len - this->interval_ );
//    return _list;
//}

//QList<NPoint> NApproximation::approxIntervalArc( const NArc &arc, double &del )
//{
//    QList<NPoint> _list;
//    double _lenStage = arc.lengthArc();
//    double _len = 0;
//    if( del > 0 )
//    {
//        _len = this->interval_ - del;
//    }
//    if( _len > _lenStage )
//    {
//        del = _lenStage + _lenStage;
//        return QList<NPoint>();
//    }
//    _lenStage = _lenStage / arc.radius();
//    double _delStart = _len / arc.radius();
//    double _delAngle = this->interval_ / arc.radius();
//    double _angleStart = arc.angleStart();

//    if( arc.direct() == NArc::LEFT )
//    {
//        while( _delStart < _lenStage )
//        {
//            _list.append( NPoint::getCoordinate( _angleStart - _delStart, arc.radius(), arc.center() ) );
//            _delStart += _delAngle;
//        }
//    }
//    else
//    {
//        while( _delStart < _lenStage )
//        {
//            _list.append( NPoint::getCoordinate( _angleStart + _delStart, arc.radius(), arc.center() ) );
//            _delStart += _delAngle;
//        }
//    }
//    del = arc.lengthArc() - ( _delStart - _delAngle ) * arc.radius();
//    return _list;
//}


class NApproximationPrivat
{
public:
    typedef std::shared_ptr<NLineSection> SNLineSection;
    typedef std::shared_ptr<NArc> SNArc;
    typedef std::shared_ptr<NFigure> SNFigure;
    typedef QList<NFigure> LNFigure;

    NApproximationPrivat( const NLineSection &lineSection );
    NApproximationPrivat( const NArc &arc );
    NApproximationPrivat( const NFigure &figure );
    NApproximationPrivat( const QList<NFigure> &lfigure );

    void setLineSection( const NLineSection &lineSection );
    void setArc( const NArc &arc );
    void setFigure( const NFigure &figure );
    void setLFigure( const QList<NFigure> &lfigure );

    bool isLineSection() const;
    bool isArc() const;
    bool isFigure() const;
    bool isLFigure() const;

    const NLineSection &lineSection() const;
    const NArc &arc() const;
    const NFigure &figure() const;
    const QList<NFigure> &lfigure() const;

private:
    SNLineSection lineSection_;
    SNArc arc_;
    SNFigure figure_;
    LNFigure listFigure_;
};

NApproximationPrivat::NApproximationPrivat( const NLineSection &lineSection )
{
    this->setLineSection( lineSection );
}

NApproximationPrivat::NApproximationPrivat( const NArc &arc )
{
    this->setArc( arc );
}

NApproximationPrivat::NApproximationPrivat( const NFigure &figure )
{
    this->setFigure( figure );
}

NApproximationPrivat::NApproximationPrivat( const QList<NFigure> &lfigure )
{
    this->setLFigure( lfigure );
}

void NApproximationPrivat::setLineSection( const NLineSection &lineSection )
{
    this->arc_.reset();
    this->figure_.reset();
    this->listFigure_.clear();
    this->lineSection_.reset( new NLineSection( lineSection ) );
}

void NApproximationPrivat::setArc( const NArc &arc )
{
    this->lineSection_.reset();
    this->figure_.reset();
    this->listFigure_.clear();
    this->arc_.reset( new NArc( arc ) );
}

void NApproximationPrivat::setFigure( const NFigure &figure )
{
    this->lineSection_.reset();
    this->arc_.reset();
    this->listFigure_.clear();
    this->figure_.reset( new NFigure( figure ) );
}

void NApproximationPrivat::setLFigure( const QList<NFigure> &lfigure )
{
    this->lineSection_.reset();
    this->arc_.reset();
    this->figure_.reset();
    this->listFigure_ = lfigure;
}

bool NApproximationPrivat::isLineSection() const
{
    return ( this->lineSection_.get() != nullptr );
}

bool NApproximationPrivat::isArc() const
{
    return ( this->arc_.get() != nullptr );
}

bool NApproximationPrivat::isFigure() const
{
    return ( this->figure_.get() != nullptr );
}

bool NApproximationPrivat::isLFigure() const
{
    return !this->listFigure_.isEmpty();
}

const NLineSection &NApproximationPrivat::lineSection() const
{
    return *this->lineSection_.get();
}

const NArc &NApproximationPrivat::arc() const
{
    return *this->arc_.get();
}

const NFigure &NApproximationPrivat::figure() const
{
    return *this->figure_.get();
}

const QList<NFigure> &NApproximationPrivat::lfigure() const
{
    return this->listFigure_;
}





NApproximation::NApproximation( const NLineSection &lineSection,
                                  const nreal &interval )
{
    this->setInterval( interval );
    this->ptr_.reset( new NApproximationPrivat( lineSection ) );
}

NApproximation::NApproximation( const NArc &arc, const nreal &interval )
{
    this->setInterval( interval );
    this->ptr_.reset( new NApproximationPrivat( arc ) );
}

NApproximation::NApproximation( const NFigure &figure,
                                  const nreal &interval )
{
    this->setInterval( interval );
    this->ptr_.reset( new NApproximationPrivat( figure ) );
}

NApproximation::NApproximation( const QList<NFigure> &listFigure,
                                  const nreal &interval )
{
    this->setInterval( interval );
    this->ptr_.reset( new NApproximationPrivat( listFigure ) );
}

QList<NPoint> NApproximation::approximation( bool equidistant ) const
{
    if( this->ptr_->isLineSection() )
        return this->approximation( this->ptr_->lineSection(), equidistant );
    if( this->ptr_->isArc() )
        return this->approximation( this->ptr_->arc(), equidistant );
    if( this->ptr_->isFigure() )
        return this->approximation( this->ptr_->figure(), equidistant );
    if( this->ptr_->isLFigure() )
        return this->approximation( this->ptr_->lfigure(), equidistant );
    return QList<NPoint>();
}

QList<NPoint> NApproximation::approximation( const NLineSection &line,
                                               bool equidistant ) const
{
    QList<NPoint> _listPoint;
    nreal _length = line.length();
    nreal _interval = this->interval_;
    if( equidistant )
        _interval = this->equidistantIterval( _length );
    nreal _len;
    NAngle _angle = line.angle();
    if( !_interval.compare( nreal() ) )
        this->calcPointLineSection( line, _listPoint, _len, _length, _interval );
    _listPoint.append( line.stop() );
    return _listPoint;
}

QList<NPoint> NApproximation::approximation( const NArc &arc,
                                               bool equidistant ) const
{
    QList<NPoint> _listPoint;
    nreal _length = arc.lengthArc();
    nreal _interval = this->interval_;
    if( equidistant )
        _interval = this->equidistantIterval( _length );
    nreal _lenStage = _length / arc.radius();
    NAngle _delStart;
    NAngle _delAngle( _interval / arc.radius() );
    NAngle _angleStart = arc.angleStart();
    if( !_interval.compare( nreal() ) )
        this->calcPointArc( arc, _listPoint, _delStart, _lenStage,
                                                       _delAngle, _angleStart );
    _listPoint.append( NPoint::newPoint( arc.angleStop(), arc.radius(),
                                          arc.center() ) );

    return _listPoint;
}

QList<NPoint> NApproximation::approximation( const NFigure &figure,
                                               bool equidistant ) const
{
    if( figure.figureArc() )
        return this->approximation( figure.arc(), equidistant );
    if( figure.figureLineSection() )
        return this->approximation( figure.lineSection(), equidistant );
    return QList<NPoint>();
}

QList<NPoint> NApproximation::approximation( const QList<NFigure> &lFigure,
                                               bool equidistant ) const
{
    if( lFigure.isEmpty() )
        return QList<NPoint>();
    QList<NPoint> _listPoint;
    nreal _length = NFigure::lehghtFigure( lFigure );
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
            NAngle _delStart( _len / i.arc().radius() );
            NAngle _delAngle( _interval / i.arc().radius() );
            NAngle _angleStart = i.arc().angleStart();
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

nreal NApproximation::equidistantIterval( const nreal &length ) const
{
    nreal _c = ( length / this->interval_ ).entier();
    if( _c.compare( nreal() ) )
        return nreal();
    return length / _c;
}

void NApproximation::calcPointLineSection( const NLineSection &lineSection,
                                            QList<NPoint> &listPoint,
                                            nreal &lenIterator,
                                            const nreal &lenStage,
                                            const nreal &interval ) const
{
    while( lenIterator < lenStage )
    {
        listPoint.append( std::move( NPoint::newPoint( lineSection.angle(),
                                         lenIterator, lineSection.start() ) ) );
        lenIterator += interval;
    }
}

void NApproximation::calcPointArc( const NArc &arc,
                                    QList<NPoint> &listPoint,
                                    NAngle &lenIterator,
                                    const nreal &lenStage,
                                    const NAngle &interval,
                                    const NAngle &angleStart ) const
{
    auto _while = [&]( const nreal &sign )
    {
        while( lenIterator < lenStage )
        {
            listPoint.append( std::move( NPoint::newPoint(
                                          angleStart + lenIterator * sign,
                                          arc.radius(), arc.center() ) ) );
            lenIterator += interval;
        }
    };
    if( arc.direct() == NDirect::EN_D_LEFT )
        _while( nreal( -1.0 ) );
    else
        _while( nreal( 1.0 ) );
}


