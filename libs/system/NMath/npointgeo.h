#ifndef NPOINTGEO_H
#define NPOINTGEO_H

#include <QString>
#include "npolarcoordinat.h"
#include "ngrademinsecmsec.h"

/**
 * @brief The NPointGeo class - Класс содержащий поля и методы для работы с
 * геометрической объектом точка(топографические координаты).
 */
class NPointGeo
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

    NPointGeo();
    NPointGeo( const NAngle &latitude, const NAngle &longitude,
                const nreal &altitude = nreal() );
    NPointGeo( const NPointGeo &pointGeo );
    NPointGeo( NPointGeo &&pointGeo );
    virtual ~NPointGeo();

    void setLatitude( const NAngle &latitude );
    void setLongitude( const NAngle &longitude );
    void setAltitude( const nreal &altitude );

    const NAngle &latitude() const;
    const NAngle &longitude() const;
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
    nreal distance( const NPointGeo &stop ) const;

    /**
     * @brief angle - метод возвращает азимут на точку.
     * @param stop - точка до который рассчитывается азимут.
     * @return - азимут.
     */
    NAngle angle( const NPointGeo &stop ) const;

    /**
     * @brief midplane - метод возвращает среднию точку между точками.
     * @param point - точка относительно которой будет определена средняя точка.
     * @return - координаты cредней точки.
     */
    NPointGeo midplane( const NPointGeo &point ) const;

    /**
     * @brief getGradeMinSecMsec - метод преобрузует координаты в формат
     * градусы, минуты, секунлы и миллисекунды.
     * @param coord - тип координаты(широта, долгота).
     * @return - координата в формате градусы, минуты, секунлы и миллисекунды.
     */
    NGradeMinSecMsec getGradeMinSecMsec( Coordinate coord ) const;

    /**
     * @brief setGradeMinSecMsec - метод задает координаты точки в формате
     * градусы, минуты, секунлы и миллисекунды.
     * @param latitude - широта.
     * @param longitude - долгота.
     */
    void setGradeMinSecMsec( const NGradeMinSecMsec &latitude,
                             const NGradeMinSecMsec &longitude );

    /**
     * @brief getNextGeoCoordinat - метод возвращает координаты точки по пеленгу
     * и дальности относительно текущей точки.
     * @param range - дальность до точки.
     * @param omnibearing - пеленг на точку.
     * @return - новые координаты точки.
     */
    NPointGeo getNextGeoCoordinat( const nreal &range,
                                    const NAngle &omnibearing ) const;

    /**
     * @brief getPolarToTc - метод возвращает полярные координаты до точки
     * 'pointGeo'.
     * @param pointGeo - точка до которой определяются полярные координаты.
     * @return - полярные координаты.
     */
    NPolarCoordinat getPolarToTc( const NPointGeo &pointGeo ) const;

    /**
     * @brief getPolarFromTc - метод возвращает полярные координаты от точки
     * 'pointGeo'.
     * @param pointGeo - точка от которой определяются полярные координаты.
     * @return - полярные координаты.
     */
    NPolarCoordinat getPolarFromTc( const NPointGeo &pointGeo ) const;

    /**
     * @brief getPolarToTc - статический метод возвращает полярные координаты от
     * точки 'start' до точки 'stop'.
     * @param start - точка от которой считаются координаты.
     * @param stop - точка до которой считаются координаты.
     * @return - полярные координаты.
     */
    static NPolarCoordinat getPolarToTc( const NPointGeo &start,
                                          const NPointGeo &stop );

    NPointGeo &operator=( const NPointGeo &pointGeo );
    NPointGeo &operator=( NPointGeo &&pointGeo );
    bool operator ==( const NPointGeo &pointGeo ) const;

protected:
    NAngle latitude_;   //!Широта
    NAngle longitude_;  //!Долгота
    nreal altitude_;   //!Высота

    static const nreal stSemiminorAxis;    //!Малая полуось
    static const nreal stSemimajorAxis;    //!Большая полуось

    static nreal eccentricity2_1();
    static nreal eccentricity2_2();

    static void commonSurveyComp( const nreal &range,
                                  const NAngle &omnibearing,
                                  const NPointGeo &start , NPointGeo &stop );
    static void geographicInverse( const NPointGeo &start,
                                   const NPointGeo &stop,
                                   NPolarCoordinat &polar );
};

inline NPointGeo::NPointGeo( )
    : latitude_( nreal() ), longitude_( nreal() ), altitude_( nreal() )
{

}

inline const NAngle &NPointGeo::latitude() const
{
    return this->latitude_;
}

inline const NAngle &NPointGeo::longitude() const
{
    return this->longitude_;
}

inline const nreal &NPointGeo::altitude() const
{
    return this->altitude_;
}

#endif // NPOINTGEO_H
