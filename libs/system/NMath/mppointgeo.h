#ifndef MPPOINTGEO_H
#define MPPOINTGEO_H

#include <QString>
#include "mppolarcoordinat.h"
#include "mpgrademinsecmsec.h"

/**
 * @brief The MpPointGeo class - Класс содержащий поля и методы для работы с
 * геометрической объектом точка(топографические координаты).
 */
class MpPointGeo
{
public:
    /**
     * @brief The Coordinate enum - Список содержащий перечесления
     * топографических координат.
     */
    enum Coordinate
    {
        LATITUDE = 0x1,     //!Широта
        LONGITUDE = 0x2     //!Долгота
    };

    MpPointGeo();
    MpPointGeo( const MpAngle &latitude, const MpAngle &longitude,
                const nreal &altitude = nreal() );
    MpPointGeo( const MpPointGeo &pointGeo );
    MpPointGeo( MpPointGeo &&pointGeo );
    virtual ~MpPointGeo();

    void setLatitude( const MpAngle &latitude );
    void setLongitude( const MpAngle &longitude );
    void setAltitude( const nreal &altitude );

    const MpAngle &latitude() const;
    const MpAngle &longitude() const;
    const nreal &altitude() const;

    //! \brief latitudeString - метод переводит значения широты в строку
    //! \return - строка формата "00°00'000W"

    /**
     * @brief latitudeString - метод переводит значения широты в строку.
     * @param sec - флаг показывающий что нужно отображать отдельно секунды
     * (true - отображать отдельно секунды, false - отображать дробные минуты).
     * @return строка отображения широты.
     */
    QString latitudeString( bool sec = true ) const;
    /**
     * @brief longitudeString - метод переводит значения долготу в строку.
     * @param sec - флаг показывающий что нужно отображать отдельно секунды
     * (true - отображать отдельно секунды, false - отображать дробные минуты).
     * @return строка отображения широты.
     */
    QString longitudeString( bool sec = true ) const;

    /**
     * @brief distance - метод возвращает расстояние между точками.
     * @param stop - точка до который рассчитывается расстояние.
     * @return - расстояние до точки.
     */
    nreal distance( const MpPointGeo &stop ) const;

    /**
     * @brief angle - метод возвращает азимут на точку.
     * @param stop - точка до который рассчитывается азимут.
     * @return - азимут.
     */
    MpAngle angle( const MpPointGeo &stop ) const;

    /**
     * @brief midplane - метод возвращает среднию точку между точками.
     * @param point - точка относительно которой будет определена средняя точка.
     * @return - координаты cредней точки.
     */
    MpPointGeo midplane( const MpPointGeo &point ) const;

    /**
     * @brief getGradeMinSecMsec - метод преобрузует координаты в формат
     * градусы, минуты, секунлы и миллисекунды.
     * @param coord - тип координаты(широта, долгота).
     * @return - координата в формате градусы, минуты, секунлы и миллисекунды.
     */
    MpGradeMinSecMsec getGradeMinSecMsec( Coordinate coord ) const;

    /**
     * @brief setGradeMinSecMsec - метод задает координаты точки в формате
     * градусы, минуты, секунлы и миллисекунды.
     * @param latitude - широта.
     * @param longitude - долгота.
     */
    void setGradeMinSecMsec( const MpGradeMinSecMsec &latitude,
                             const MpGradeMinSecMsec &longitude );

    /**
     * @brief getNextGeoCoordinat - метод возвращает координаты точки по пеленгу
     * и дальности относительно текущей точки.
     * @param range - дальность до точки.
     * @param omnibearing - пеленг на точку.
     * @return - новые координаты точки.
     */
    MpPointGeo getNextGeoCoordinat( const nreal &range,
                                    const MpAngle &omnibearing ) const;

    /**
     * @brief getPolarToTc - метод возвращает полярные координаты до точки
     * 'pointGeo'.
     * @param pointGeo - точка до которой определяются полярные координаты.
     * @return - полярные координаты.
     */
    MpPolarCoordinat getPolarToTc( const MpPointGeo &pointGeo ) const;

    /**
     * @brief getPolarFromTc - метод возвращает полярные координаты от точки
     * 'pointGeo'.
     * @param pointGeo - точка от которой определяются полярные координаты.
     * @return - полярные координаты.
     */
    MpPolarCoordinat getPolarFromTc( const MpPointGeo &pointGeo ) const;

    /**
     * @brief getPolarToTc - статический метод возвращает полярные координаты от
     * точки 'start' до точки 'stop'.
     * @param start - точка от которой считаются координаты.
     * @param stop - точка до которой считаются координаты.
     * @return - полярные координаты.
     */
    static MpPolarCoordinat getPolarToTc( const MpPointGeo &start,
                                          const MpPointGeo &stop );

    MpPointGeo &operator=( const MpPointGeo &pointGeo );
    MpPointGeo &operator=( MpPointGeo &&pointGeo );
    bool operator ==( const MpPointGeo &pointGeo ) const;

protected:
    MpAngle latitude_;   //!Широта
    MpAngle longitude_;  //!Долгота
    nreal altitude_;   //!Высота

    static const nreal stSemiminorAxis;    //!Малая полуось
    static const nreal stSemimajorAxis;    //!Большая полуось

    static nreal eccentricity2_1();
    static nreal eccentricity2_2();

    static void commonSurveyComp( const nreal &range,
                                  const MpAngle &omnibearing,
                                  const MpPointGeo &start , MpPointGeo &stop );
    static void geographicInverse( const MpPointGeo &start,
                                   const MpPointGeo &stop,
                                   MpPolarCoordinat &polar );
};

inline MpPointGeo::MpPointGeo( )
    : latitude_( nreal() ), longitude_( nreal() ), altitude_( nreal() )
{

}

inline const MpAngle &MpPointGeo::latitude() const
{
    return this->latitude_;
}

inline const MpAngle &MpPointGeo::longitude() const
{
    return this->longitude_;
}

inline const nreal &MpPointGeo::altitude() const
{
    return this->altitude_;
}

#endif // MPPOINTGEO_H
