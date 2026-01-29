#pragma once
#include <iostream>

/**
 * erstellen von Komplexen Zahlen, bestehend aus Realteil @var real und Imaginaerteil @var imag
*/
class KomplexeZahl
{
    private: 
        double real;
        double imag;

    public: 
        KomplexeZahl(double, double);
        KomplexeZahl();
        friend KomplexeZahl operator+(KomplexeZahl&, KomplexeZahl&);
        friend KomplexeZahl operator*(KomplexeZahl&, KomplexeZahl&);
        friend KomplexeZahl operator*(double, KomplexeZahl&);
        friend std::istream& operator>>(std::istream& , KomplexeZahl&);
        friend std::ostream& operator<<(std::ostream& , KomplexeZahl&);
        KomplexeZahl polar(double, double);
        void KomZahlEinlesen(KomplexeZahl&, KomplexeZahl&, double&);
        void KomZahlAusgabe(KomplexeZahl&, KomplexeZahl&, double&);
        void PolEinlesen(double&, double&);
        void PolAusgabe(double&, double&);
        friend class KomplexND;
};