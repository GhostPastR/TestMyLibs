#include "mptime.h"
#include <mpdistance.h>
#include <mpspeed.h>
#include <iostream>

MpTime MpTime::time( const MpDistance &distance, const MpSpeed &speed ) noexcept
{
    return MpTime( ( distance.m() / speed.ms() ).toUInt32() );
}

MpTime &MpTime::setTime(const MpDistance &distance, const MpSpeed &speed) noexcept
{
    *this = MpTime::time( distance, speed );
    return *this;
}

QString MpTime::toString(const QString &format ) noexcept
{
    if( format.isEmpty() )
       {
           std::cerr<<"Error format! Format is Empty!";
           return QString();
       };
       QString symbol = "dhms";
       if ( symbol.indexOf( format.at(0) ) == -1 )
       {
           std::cerr<<"Error format! Spacer in first!";
           return QString();
       };
       if ( symbol.indexOf( format.at( format.count() - 1 ) ) == -1 )
       {
           std::cerr<<"Error format! Spacer in last place!";
           return QString();
       };
       int flag = 0b0000;
       int count = 0;
       auto _check = [&flag, &count]( int f ){
           if( ( flag == 0b0000 ) || ( flag == f ) )
               count++;
           else
               return false;
           flag = f;
           return true;
       };

       QString res = "";
       auto _str = [&res, &count]( nulong value, QString s ) {
           if( count > 1 )
               res.append( QString( "%1" ).arg( value, 2, 10, QLatin1Char('0') ) );
           else
               res.append( QString( "%1" ).arg( value, 1, 10 ) );
           res.append( s );
       };

       for( int i = 0, c = format.count(); i < c; i++ )
       {
           if( format[i] == 'd' ) {
               if( !_check( 0b1000 ) ) {
                   std::cerr<<"Error format! Undefined symbol d!" << std::endl;
                   return QString();
               }
           }
           else if( format[i] == 'h' ) {
               if( !_check( 0b0100 ) ) {
                   std::cerr<<"Error format! Undefined symbol h!" << std::endl;
                   return QString();
               }
           }
           else if( format[i] == 'm' ) {
               if( !_check( 0b0010 ) ) {
                   std::cerr<<"Error format! Undefined symbol m!" << std::endl;
                   return QString();
               }
           }
           else if( format[i] == 's' ) {
               if( !_check( 0b0001 ) ) {
                   std::cerr<<"Error format! Undefined symbol s!" << std::endl;
                   return QString();
               }
           }
           if( ( symbol.indexOf( format.at(i) ) == -1 ) || ( i == c - 1 ) ){
               if (flag == 0b0000)
               {
                   std::cerr<<"Error format! Double spacer!" << std::endl;
                   return QString();
               }
               QString _char;
               if( i != c - 1 )
                   _char = format[i];
               if( count > 2 )
                   std::cerr<<"Error format! So mush sumbol!" << std::endl;
               if( flag == 0b1000 )
                   _str( this->day(), format[i] );
               else if( flag == 0b0100 )
                   _str( this->hour() % nulong( 24 ), _char );
               else if( flag == 0b0010 )
                   _str( this->min() % nulong( 60 ), _char );
               else if( flag == 0b0001 )
                   _str( this->sec() % nulong( 60 ), _char );
               flag = 0b0000;
               count = 0;
           }
       }
       return res;
}
