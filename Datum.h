//
// Created by Lukas on 14.03.2022.
//

#ifndef DATUM_DATUM_H
#define DATUM_DATUM_H
#include <iostream>

class Datum {
public:
    Datum();
    Datum(const Datum&);
    Datum(int, int ,int);
    virtual ~Datum();
    int getDen() const;
    int getMesic() const;
    int getRok() const;
    bool setDatum(int, int, int);
    int denVTydnu() const;
    int pocetDniOdData();
    const int MAX_VALID_YR = 2050;
    const int MIN_VALID_YR = 1900;


private:
    int den;
    int mesic;
    int rok;
    void systemoveDatum();
    bool kontrolaData(int, int, int) const;
    bool prestupnyRok(int) const;

};



std::ostream & operator <<(std::ostream&, const Datum&);

#endif //DATUM_DATUM_H
