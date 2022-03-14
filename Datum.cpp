#include "Datum.h"
#include <iostream>
#include "time.h"

using std::cout;
using std::endl;


Datum::Datum(){
    systemoveDatum();
}

Datum::Datum(int d, int m, int r){
    if(!setDatum(d,m,r)){
        cout<<"Spatne datum"<<endl;
        systemoveDatum();
    }
}

Datum::~Datum() {
}

bool Datum::setDatum(int d, int m, int r) {
    if (kontrolaData(d,m,r)){
        this->den = d;
        this->mesic = m;
        this->rok = r;
        return true;
    }
    return false;
}

int Datum::getRok() const {
    return this->rok;
}

int Datum::getMesic() const {
    return this->mesic;
}

int Datum::getDen() const {
    return this->den;
}

void Datum::systemoveDatum(){
    time_t t =time(0);
    struct tm* tm = localtime(&t);
    setDatum(tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    return;
}


bool Datum::prestupnyRok(int year) const {
    if (((year % 4 == 0) && (year % 100 !=0)) || year % 400 ==0){
        return true;
    }else {
        return false;
    }
}

bool Datum::kontrolaData(int d, int m, int r) const {
    if(r > MAX_VALID_YR || r < MIN_VALID_YR){
        return false;
    }else if (m<1 || m>12){
        return false;
    }else if (d<1 || d>31){
        return false;
    }
    if (m == 2){
        if (prestupnyRok(r)){
            return (d<= 29);
        }else{
            return (d<= 28);
        }
    }
    if (m == 4 || m == 6 || m == 9 || m == 11){
        return (d <= 30);
    }
    return true;
}

int Datum::denVTydnu() const{
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    timeinfo->tm_year = this->rok - 1900;
    timeinfo->tm_mon = this->mesic - 1;
    timeinfo->tm_mday = this->den;
    mktime ( timeinfo );
    return timeinfo->tm_wday;
}

int Datum::pocetDniOdData() {
    int d = this->den;
    int m = this->mesic;
    int r = this->rok;
    int pomoc = (r - 1900) * 365;
    for (int i = 0; i <= (r - 1900); i++){
        if (prestupnyRok(1900 + i)){
            pomoc++;
        }
    }
    for (int i = 1; i < m; i++) {
        if (i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12) {
            pomoc += 31;
        } else if (i == 4 or i == 6 or i == 9 or i == 11) {
            pomoc += 30;
        } else if (i == 2){
            pomoc += 28;
        }
    }
    return pomoc+d;
}


std::ostream & operator<< (std::ostream & os, const Datum & d){
    os << (d.getDen()<10 ? "0" : "") << d.getDen() << "."<< (d.getMesic()<10 ? "0" : "") << d.getMesic() << "."<< d.getRok() ;
    return os;
}
