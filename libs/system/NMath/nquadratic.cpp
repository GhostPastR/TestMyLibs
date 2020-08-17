#include "nquadratic.h"

NQuadratic::NQuadratic( const nreal &a )
{
    this->a1_ = a;
    this->a2_ = a;
    this->a3_ = a;
    this->discriminant();
}

NQuadratic::NQuadratic( const nreal &a1, const nreal &a2,
                          const nreal &a3 )
{
    if( a1.compare( nreal() ) )
    {
        std::cerr << "1-st factor is equal 0" << std::endl;
        this->a1_ = nreal( 1.0 );
    }
    else
        this->a1_ = a1;
    this->a2_ = a2;
    this->a3_ = a3;
    this->discriminant();
}

NQuadratic::NQuadratic( const NQuadratic &qudratic )
{
    this->a1_ = qudratic.a1_;
    this->a2_ = qudratic.a2_;
    this->a3_ = qudratic.a3_;
}

NQuadratic::NQuadratic( NQuadratic &&qudratic )
{
    this->a1_ = std::move( qudratic.a1_ );
    this->a2_ = std::move( qudratic.a2_ );
    this->a3_ = std::move( qudratic.a3_ );
}

NQuadratic::~NQuadratic()
{

}

inline void NQuadratic::setA1( const nreal &a1 )
{
    if( a1.compare( nreal() ) )
    {
        std::cerr << "1-st factor is equal 0" << std::endl;
        this->a1_ = nreal( 1.0 );
    }
    else
        this->a1_ = a1;
    this->discriminant();
}

inline void NQuadratic::setA2( const nreal &a2 )
{
    this->a2_ = a2;
    this->discriminant();
}

inline void NQuadratic::setA3( const nreal &a3 )
{
    this->a3_ = a3;
    this->discriminant();
}

void NQuadratic::discriminant()
{
    this->d_ = this->a2_ * this->a2_ - nreal( 4.0 ) * this->a1_ * this->a3_;
}

nreal NQuadratic::d()
{
    if( this->d_.isNaN() )
        this->discriminant();
    return this->d_;
}

QPair<nreal, nreal> NQuadratic::rRoot()
{
    this->discriminant();
    if( this->d_ < nreal() )
        return QPair<nreal, nreal>( nreal::nan, nreal::nan );
    else
    {
        QPair<nreal, nreal> _pair;
        _pair.first = ( -this->a2_ - sqrt( this->d_.toType() ) ) /
                                                 ( nreal( 2.0 ) * this->a1_ );
        _pair.first = ( -this->a2_ + sqrt( this->d_.toType() ) ) /
                                                 ( nreal( 2.0 ) * this->a1_ );
        return  _pair;
    }
}

NQuadratic &NQuadratic::operator=( const NQuadratic &qudratic )
{
    this->a1_ = qudratic.a1_;
    this->a2_ = qudratic.a2_;
    this->a3_ = qudratic.a3_;
    return *this;
}

NQuadratic &NQuadratic::operator=( NQuadratic &&qudratic )
{
    this->a1_ = std::move( qudratic.a1_ );
    this->a2_ = std::move( qudratic.a2_ );
    this->a3_ = std::move( qudratic.a3_ );
    return *this;
}
