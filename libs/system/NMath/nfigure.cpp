#include "nfigure.h"

NFigure::NFigure(const NLineSection &lineSection )
{
    this->lineSection_ = nullptr;
    this->arc_ = nullptr;
    this->setLineSection( lineSection );
}

NFigure::NFigure( const NArc &arc )
{
    this->lineSection_ = nullptr;
    this->arc_ = nullptr;
    this->setArc( arc );
}

NFigure::NFigure( const NFigure &figure )
{
    this->lineSection_ = nullptr;
    this->arc_ = nullptr;
    if( figure.figureArc() )
        this->setArc( *figure.arc_ );
    else if( figure.figureLineSection() )
        this->setLineSection( *figure.lineSection_ );
}

NFigure::NFigure( NFigure &&figure )
{
    this->lineSection_ = nullptr;
    this->arc_ = nullptr;
    if( figure.figureArc() )
        this->setArc( std::move( *figure.arc_ ) );
    else if( figure.figureLineSection() )
        this->setLineSection( std::move( *figure.lineSection_ ) );
}

NFigure::~NFigure()
{
    this->deleteArc();
    this->deleteLineSection();
}

NPoint NFigure::pointStart() const
{
    if( this->figureArc() )
        return this->arc().start();
    else
        return this->lineSection().start();
}

NPoint NFigure::pointStop() const
{
    if( this->figureArc() )
        return this->arc().stop();
    else
        return this->lineSection().stop();
}

void NFigure::setLineSection( const NLineSection &lineSection )
{
    this->deleteArc();
    this->deleteLineSection();
    this->lineSection_ = new NLineSection( lineSection );
}

void NFigure::setLineSection( NLineSection &&lineSection )
{
    this->deleteArc();
    this->deleteLineSection();
    this->lineSection_ = std::move( &lineSection );
}

void NFigure::setArc( const NArc &arc )
{
    this->deleteArc();
    this->deleteLineSection();
    this->arc_ = new NArc( arc );
}

void NFigure::setArc( NArc &&arc )
{
    this->deleteArc();
    this->deleteLineSection();
    this->arc_ = std::move( &arc );
}

bool NFigure::figureArc() const
{
    return ( this->arc_ != nullptr );
}

bool NFigure::figureLineSection() const
{
    return ( this->lineSection_ != nullptr );
}

void NFigure::deleteLineSection()
{
    delete this->lineSection_;
    this->lineSection_ = nullptr;
}

void NFigure::deleteArc()
{
    delete this->arc_;
    this->arc_ = nullptr;
}

nreal NFigure::lehghtFigure( const QList<NFigure> &figure )
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

NFigure &NFigure::operator =( const NFigure &NFigure )
{
    if( NFigure.figureArc() )
        this->setArc( *NFigure.arc_ );
    else if( NFigure.figureLineSection() )
        this->setLineSection( *NFigure.lineSection_ );
    else
    {
        this->deleteArc();
        this->deleteLineSection();
    }
    return *this;
}

NFigure &NFigure::operator=( NFigure &&NFigure )
{
    if( NFigure.figureArc() )
        this->setArc( std::move( *NFigure.arc_ ) );
    else if( NFigure.figureLineSection() )
        this->setLineSection( std::move( *NFigure.lineSection_ ) );
    else
    {
        this->deleteArc();
        this->deleteLineSection();
    }
    return *this;
}
