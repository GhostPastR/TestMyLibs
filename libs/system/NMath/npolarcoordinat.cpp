#include "npolarcoordinat.h"

NPolarCoordinat::NPolarCoordinat( const NPolarCoordinat &polarCoordinat )
{
    this->range_ = polarCoordinat.range_;
    this->omnibearing_ = polarCoordinat.omnibearing_;
}

NPolarCoordinat::NPolarCoordinat( NPolarCoordinat &&polarCoordinat )
{
    this->range_ = std::move( polarCoordinat.range_ );
    this->omnibearing_ = std::move( polarCoordinat.omnibearing_ );
}

NPolarCoordinat::~NPolarCoordinat()
{

}

void NPolarCoordinat::setPoint( const NPoint &point , const NPoint &start )
{
    this->range_ = point.distance( start );
    this->omnibearing_ = point.angleFromPoint( start );
}

NPoint NPolarCoordinat::point( const NPoint &start ) const
{
    return NPoint( this->range_ * this->omnibearing_.sin() + start.x(),
                    this->range_ * this->omnibearing_.cos() + start.y() );
}

NPolarCoordinat &NPolarCoordinat::operator=
                                      ( const NPolarCoordinat &polarCoordinat )
{
    this->range_ = polarCoordinat.range_;
    this->omnibearing_ = polarCoordinat.omnibearing_;
    return *this;
}

NPolarCoordinat &NPolarCoordinat::operator=
                                           ( NPolarCoordinat &&polarCoordinat )
{
    this->range_ = std::move( polarCoordinat.range_ );
    this->omnibearing_ = std::move( polarCoordinat.omnibearing_ );
    return *this;
}
