#include "KomplexND.hpp"

/**
 * Konstruktor
 * @param n Anzahl von Komplexen Zahlen in dem Vektor
*/
KomplexND::KomplexND(int n)
{
    head = new KomplexeZahl[n];
    N = n;
}

/**
 * default Konstruktor
*/
KomplexND::KomplexND()
{
    head = nullptr;
    N = 0;
}

/**
 * Größe de Vektors
 * @returns N Größe des Vektors
*/
int KomplexND::getSize()
{
    return N;
}

/**
 * Methode für Rückgabe einer Komplexen Zahl
 * @param index Stelle einer Komplexen Zahl im Vektor
 * @returns Komplexe Zahl an der Stelle index
*/
KomplexeZahl& KomplexND::at(int index)
{
    return head[index];
}

/**
 * Destruktor
 * löscht nach Ausführung des Programms den Vektor
*/
KomplexND::~KomplexND()
{
    delete[]head;
}

/**
 * Methode, um Komplexe Zahlen über das Terminal in einen Vektor einzuladen
*/
void KomplexND::einladen() 
{
    for (int i = 0; i < N; i++) 
    {
        std::cout << "Gib die komplexe Zahl " << i + 1<< " ein: ";
        std::cin >> at(i);
    }
}

/**
 * Methode, um den Vektor mit Komplexen Zahlen auszugeben
*/
void KomplexND::ausgeben()
{
    std::cout << " { ";
    for (int i = 0; i < N; i++) 
    {
        std::cout << at(i) << " ";
    }
    std::cout << "}" << std::endl;
}

/**
 * Methode, um zwei Vektoren miteinander zu addieren
 * @param vek2 Vektor, der dazuaddiert wird
 * @returns result Vektor mit Summe der zwei Vektoren
*/
KomplexND KomplexND::add(KomplexND& vek2) 
{
    KomplexND result(N);
    for (int i = 0; i < N; i++) 
    {
        result.at(i) = this->at(i) + vek2.at(i);
    }
    return result;
}

/**
 * Methode, um Vektor mit einer Komplexen Zahl zu multiplizieren
 * @param zahl Komplexe Zahl, mit dem der Vektor multipliziert wird
 * @returns result Vektor nach Multiplikation
*/
KomplexND KomplexND::skal(KomplexeZahl& zahl)
{
    KomplexND result(N);
    for (int i = 0; i < N; i++) 
    {
        result.at(i) = at(i) * zahl;
    }
    return result;
}