#include "mppolarcoordinat.h"

MpPolarCoordinat::MpPolarCoordinat( const MpPolarCoordinat &polarCoordinat )
{
    this->range_ = polarCoordinat.range_;
    this->omnibearing_ = polarCoordinat.omnibearing_;
}

MpPolarCoordinat::MpPolarCoordinat( MpPolarCoordinat &&polarCoordinat )
{
    this->range_ = std::move( polarCoordinat.range_ );
    this->omnibearing_ = std::move( polarCoordinat.omnibearing_ );
}

MpPolarCoordinat::~MpPolarCoordinat()
{

}

void MpPolarCoordinat::setPoint( const MpPoint &point , const MpPoint &start )
{
    this->range_ = point.distance( start );
    this->omnibearing_ = point.angleFromPoint( start );
}

MpPoint MpPolarCoordinat::point( const MpPoint &start ) const
{
    return MpPoint( this->range_ * this->omnibearing_.sin() + start.x(),
                    this->range_ * this->omnibearing_.cos() + start.y() );
}

MpPolarCoordinat &MpPolarCoordinat::operator=
                                      ( const MpPolarCoordinat &polarCoordinat )
{
    this->range_ = polarCoordinat.range_;
    this->omnibearing_ = polarCoordinat.omnibearing_;
    return *this;
}

MpPolarCoordinat &MpPolarCoordinat::operator=
                                           ( MpPolarCoordinat &&polarCoordinat )
{
    this->range_ = std::move( polarCoordinat.range_ );
    this->omnibearing_ = std::move( polarCoordinat.omnibearing_ );
    return *this;
}
