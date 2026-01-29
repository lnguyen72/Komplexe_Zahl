#pragma once
#include "KomplexeZahl.hpp"

/**
 * Vektor zum Speichern von N Komplexen Zahlen 
 * @var N Anzahl an Komplexen Zahlen in einem Vektor
 * @var head Pointer, der Speicher reserviert 
*/
class KomplexND
{ 
    private:
        KomplexeZahl *head;
        int N;

    public: 
        KomplexND(int);
        KomplexND();
        ~KomplexND();
        void einladen();
        void ausgeben();
        int getSize();
        KomplexeZahl& at(int);
        KomplexND add(KomplexND&);
        KomplexND skal(KomplexeZahl&);
};