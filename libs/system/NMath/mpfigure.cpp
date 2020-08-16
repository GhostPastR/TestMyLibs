#include "mpfigure.h"

MpFigure::MpFigure(const MpLineSection &lineSection )
{
    this->lineSection_ = nullptr;
    this->arc_ = nullptr;
    this->setLineSection( lineSection );
}

MpFigure::MpFigure( const MpArc &arc )
{
    this->lineSection_ = nullptr;
    this->arc_ = nullptr;
    this->setArc( arc );
}

MpFigure::MpFigure( const MpFigure &figure )
{
    this->lineSection_ = nullptr;
    this->arc_ = nullptr;
    if( figure.figureArc() )
        this->setArc( *figure.arc_ );
    else if( figure.figureLineSection() )
        this->setLineSection( *figure.lineSection_ );
}

MpFigure::MpFigure( MpFigure &&figure )
{
    this->lineSection_ = nullptr;
    this->arc_ = nullptr;
    if( figure.figureArc() )
        this->setArc( std::move( *figure.arc_ ) );
    else if( figure.figureLineSection() )
        this->setLineSection( std::move( *figure.lineSection_ ) );
}

MpFigure::~MpFigure()
{
    this->deleteArc();
    this->deleteLineSection();
}

MpPoint MpFigure::pointStart() const
{
    if( this->figureArc() )
        return this->arc().start();
    else
        return this->lineSection().start();
}

MpPoint MpFigure::pointStop() const
{
    if( this->figureArc() )
        return this->arc().stop();
    else
        return this->lineSection().stop();
}

void MpFigure::setLineSection( const MpLineSection &lineSection )
{
    this->deleteArc();
    this->deleteLineSection();
    this->lineSection_ = new MpLineSection( lineSection );
}

void MpFigure::setLineSection( MpLineSection &&lineSection )
{
    this->deleteArc();
    this->deleteLineSection();
    this->lineSection_ = std::move( &lineSection );
}

void MpFigure::setArc( const MpArc &arc )
{
    this->deleteArc();
    this->deleteLineSection();
    this->arc_ = new MpArc( arc );
}

void MpFigure::setArc( MpArc &&arc )
{
    this->deleteArc();
    this->deleteLineSection();
    this->arc_ = std::move( &arc );
}

bool MpFigure::figureArc() const
{
    return ( this->arc_ != nullptr );
}

bool MpFigure::figureLineSection() const
{
    return ( this->lineSection_ != nullptr );
}

void MpFigure::deleteLineSection()
{
    delete this->lineSection_;
    this->lineSection_ = nullptr;
}

void MpFigure::deleteArc()
{
    delete this->arc_;
    this->arc_ = nullptr;
}

nreal MpFigure::lehghtFigure( const QList<MpFigure> &figure )
{
    nreal _len;
    for( auto f : figure )
    {
        if( f.figureArc() )
            _len += f.arc().lengthArc();
        if( f.figureLineSection() )
            _len += f.lineSection().length();
    }
    return _len;
}

MpFigure &MpFigure::operator =( const MpFigure &mpFigure )
{
    if( mpFigure.figureArc() )
        this->setArc( *mpFigure.arc_ );
    else if( mpFigure.figureLineSection() )
        this->setLineSection( *mpFigure.lineSection_ );
    else
    {
        this->deleteArc();
        this->deleteLineSection();
    }
    return *this;
}

MpFigure &MpFigure::operator=( MpFigure &&mpFigure )
{
    if( mpFigure.figureArc() )
        this->setArc( std::move( *mpFigure.arc_ ) );
    else if( mpFigure.figureLineSection() )
        this->setLineSection( std::move( *mpFigure.lineSection_ ) );
    else
    {
        this->deleteArc();
        this->deleteLineSection();
    }
    return *this;
}
