#include "ntriangle.h"

NTriangle::NTriangle( const NPoint &vertex1, const NPoint &vertex2,
                        const NPoint &vertex3 )
{
    this->vertex1_ = vertex1;
    this->vertex2_ = vertex2;
    this->vertex3_ = vertex3;
    if( !this->checkExistence() )
        std::cerr << "The triangle with the given tops does not exist!"
                  << std::endl;
}

NTriangle::NTriangle( const NTriangle &triangle )
{
    this->vertex1_ = triangle.vertex1_;
    this->vertex2_ = triangle.vertex2_;
    this->vertex3_ = triangle.vertex3_;
}

NTriangle::NTriangle( NTriangle &&triangle )
{
    this->vertex1_ = std::move( triangle.vertex1_ );
    this->vertex2_ = std::move( triangle.vertex2_ );
    this->vertex3_ = std::move( triangle.vertex3_ );
}

NTriangle::~NTriangle()
{

}

NAngle NTriangle::angle( NVertex vertex ) const
{
    if( vertex == NVertex::VERTEX_1 )
        return this->angle( this->vertex1_, this->vertex2_, this->vertex3_ );
    if( vertex == NVertex::VERTEX_2 )
        return this->angle( this->vertex2_, this->vertex3_, this->vertex1_ );
    else
        return this->angle( this->vertex3_, this->vertex1_, this->vertex2_ );
}

NTriangle &NTriangle::operator=( const NTriangle &triangle )
{
    this->vertex1_ = triangle.vertex1_;
    this->vertex2_ = triangle.vertex2_;
    this->vertex3_ = triangle.vertex3_;
    return *this;
}

NTriangle &NTriangle::operator=( NTriangle &&triangle )
{
    this->vertex1_ = std::move( triangle.vertex1_ );
    this->vertex2_ = std::move( triangle.vertex2_ );
    this->vertex3_ = std::move( triangle.vertex3_ );
    return *this;
}

bool NTriangle::checkExistence() const
{
    nreal _l1 = this->vertex1_.distance( this->vertex2_ );
    nreal _l2 = this->vertex2_.distance( this->vertex3_ );
    nreal _l3 = this->vertex3_.distance( this->vertex1_ );
    return !( _l1.moreThan( _l2 + _l3 ) || _l2.moreThan( _l1 + _l3 )
              || _l3.moreThan( _l1 + _l2 ) );
}

NAngle NTriangle::angle( const NPoint &vertex1, const NPoint &vertex2,
                           const NPoint &vertex3 ) const
{
    nreal _lvertex3 = vertex1.distance( vertex2 );
    nreal _lvertex1 = vertex2.distance( vertex3 );
    nreal _lvertex2 = vertex3.distance( vertex1 );
    auto _d = -( _lvertex1 * _lvertex1 - _lvertex3 * _lvertex3
                 - _lvertex2 * _lvertex2 );
    return NAngle().acos( _d / ( nreal(2.0) * _lvertex2 * _lvertex3) );
}
