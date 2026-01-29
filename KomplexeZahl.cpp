#include "KomplexeZahl.hpp"
#include <cmath>

/** 
 * Konstruktor
 * @param r entspricht Realteil der Komplexen Zahl
 * @param i entspricht Imaginärtel der Komplexen Zahl
*/
KomplexeZahl::KomplexeZahl(double r, double i)
{
    real = r;
    imag = i;
}

/** default Konstruktor
*/
KomplexeZahl::KomplexeZahl()
{
    real = 0.0;
    imag = 0.0;
}

/** 
 * überladen des Operators +
 * @param c1, c2 sind Komplexe Zahlen, die miteinander addiert werden
 * @returns das Ergebnis, also die Summe der Zahlen
*/
KomplexeZahl operator+(KomplexeZahl& c1, KomplexeZahl& c2)
{
    KomplexeZahl ergebnis;
    ergebnis.real = c1.real + c2.real;
    ergebnis.imag = c1.imag + c2.imag;
    return ergebnis;
}

/** 
 * überladen des Operators * für zwei komplexe Zahlen
 * @param c1, c2 sind Komplexe Zahlen, die miteinander multipliziert werden 
 * @returns das Ergebnis, also das Produkt der Zahlen
*/
KomplexeZahl operator*(KomplexeZahl& c1, KomplexeZahl& c2)
{
    KomplexeZahl ergebnis;
    ergebnis.real = c1.real * c2.real - c1.imag * c2.imag;
    ergebnis.imag = c1.real * c2.imag + c2.real * c1.imag;
    return ergebnis; 
}

/** 
 * überladen des Operators * Multiplikation mit Skalar
 * @param d Skalar, mit dem @param c1 Komplexe Zahl multipliziert wird
 * @returns das Ergebnis der Multiplikation
*/
KomplexeZahl operator*(double d, KomplexeZahl& c1)
{
    KomplexeZahl ergebnis;
    ergebnis.real = d * c1.real;
    ergebnis.imag = d * c1.imag;
    return ergebnis;
}

/** 
 * Berechnung einer komplexen Zahl über ihre Polarkoordinaten
 * @param winkel Winkel der komplexen Zahl in Bogenmaß
 * @param betrag Betrag der komplexen Zahl
*/
KomplexeZahl KomplexeZahl::polar(double winkel, double betrag)
{
    double realT = betrag * cos(winkel);
    double imagT = betrag * sin(winkel);
    return KomplexeZahl(realT, imagT);
}

/** 
 * Eingabeoperator überladen, sodass Komplexe Zahlen in gewünschter Form eingeladen werden können
 * @param Zahl Komplexe Zahl, die eingeladen wird
 * @returns in Eingabestrom
*/
std::istream& operator>>(std::istream& in, KomplexeZahl& Zahl)
{
    char dummy;
    in >> dummy; 
    in >> Zahl.real;
    in >> Zahl.imag; 
    in >> dummy;
    return in;
}

/** 
 * Ausgabeoperator überladen
 * @param Zahl Komplexe Zahl, die ausgegeben wird
 * @returns out Ausgabestrom
*/
std::ostream& operator<<(std::ostream& out, KomplexeZahl& Zahl)
{
    out << "[ " << Zahl.real << " " << Zahl.imag << " ]";
    return out;
}

/** 
 * Methode, um Werte aus dem Terminal einzulesen
 * @param a, b Komplexe Zahlen
 * @param c Skalar
*/
void KomplexeZahl::KomZahlEinlesen(KomplexeZahl& a, KomplexeZahl& b, double& c)
{
    std::cout << "Gib eine Komplexe Zahl ein: ";
    std::cin >> a;
    std::cout << "Gib eine weitere Komplexe Zahl ein: ";
    std::cin >> b;
    std::cout << "Gib ein Skalar ein: ";
    std::cin >> c;
} 
/** 
 * Methode, die komplexe Zahlen miteinander addiert und multipliziert und mit einem Skalar multipliziert und ausgibt
 * @param a, b Komplexe Zahlen
 * @param c Skalar
*/
void KomplexeZahl::KomZahlAusgabe(KomplexeZahl& a, KomplexeZahl& b, double& c)
{
    KomplexeZahl sum = a + b;
    KomplexeZahl mul = a * b;
    KomplexeZahl skal1 = c * a;
    KomplexeZahl skal2 = c * b;
    std::cout << "Addition: " << sum << std::endl;
    std::cout << "Multiplikation: " << mul << std::endl;
    std::cout << "Multiplikation der Komplexen Zahl " << a << " mit Skalar: " << skal1 << std::endl;
    std::cout << "Multiplikation der komplexen Zahl " << b << " mit Skalar: " << skal2 << std::endl;
}

/** 
 * Methode, die Winkelund Betrag einer Komplexen Zahl einlädt
 * @param betrag Betrag einer Komplexen Zahl
 * @param winkel Winkel einer Komplexen Zahl in Bogenmaß
*/
void KomplexeZahl::PolEinlesen(double& betrag, double& winkel)
{
    std::cout << "Gib den Betrag einer Komplexen Zahl ein: ";
    std::cin >> betrag;
    std::cout << "Gib den Winkel einer Komplexen Zahl ein: ";
    std::cin >> winkel;
}

/**
 * Methode, die eine Komplexe Zahl über ihre Polarkoordinate bestimmt und ausgibt
 * @param betrag Betrag einer Komplexen Zahl
 * @param winkel Winkel einer Komplexen Zahl in Bogenmaß
*/
void KomplexeZahl::PolAusgabe(double& betrag, double& winkel)
{
    KomplexeZahl kZ, pol = kZ.polar(winkel, betrag);
    std::cout << "Komplexe Zahl durch Berechnung mit Polarkoordinaten: " << pol << std::endl;
}