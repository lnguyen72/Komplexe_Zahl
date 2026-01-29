#include "KomplexeZahl.hpp"
#include "KomplexND.hpp"

void menueAusgeben();
void menueAbfragen();
void auswahl(int);

int main()
{
    menueAbfragen();
}

/**
 * stellt Menueoptionen dar
*/
void menueAusgeben() 
{
    std::cout   << "[1] mit Komplexen Zahlen rechnen\n"
                << "[2] über Polarkoordinate Komplexe Zahl bestimmen\n"
                << "[3] Vektor über Klasse KomplexND\n";
}

/**
 * ruft zunächst Funktion menueAusgeben() auf
 * Funktion, die fragt, welche Aktion ausgeführt werden soll, falls Option nicht im Menue ist, wird weitergefragt
 * ruft Funktion auswahl(int) auf und uebergibt ihr die ausgewaehlte Option
*/
void menueAbfragen() 
{
    menueAusgeben();
    int choice;
    std::cout << "Bitte wählen Sie eine Option: ";
    do
    {
        std::cin >> choice;
        if(choice < 1 || choice > 3)
            std::cout << "Ungültige Auswahl! Bitte zwsischen den Menüpunkten 1, 2 und 3 wählen: ";
    }while(choice < 1 || choice > 3);{
        std::cout << "\n";
        auswahl(choice);
    }

}

/**
 * Funktion, die unterschiedliche Handlungsoptionen aufruft
 * @param choice wird uebergeben, damit eins der drei cases aufgerufen und ausgefuehrt wird
*/
void auswahl( int choice ) 
{
    KomplexeZahl werte, c1, c2;
    double s, betrag, winkel;

    switch( choice ) 
    {
        case 1: 
            werte.KomZahlEinlesen(c1, c2, s);
            std::cout <<"\n";
            werte.KomZahlAusgabe(c1, c2, s);
        break; 

        case 2:
            werte.PolEinlesen(betrag, winkel);
            std::cout << "\n";
            werte.PolAusgabe(betrag, winkel);
        break;

        case 3:
        int n;
        KomplexeZahl c3;
        std::cout << "Wie viele Komplexe Zahlen soll der Vektor enthalten? ";
        do
        {
            std::cin >> n;
                if(n < 1)
                    std::cout << "Zahl muss größer als null sein!" <<std::endl;
        }while(n < 1);{
        KomplexND vec1(n), vec2(n);
        std::cout << "Vektor 1" << std::endl;
        vec1.einladen();
        std::cout << "Vektor 2" << std::endl;
        vec2.einladen();
        std::cout << "Mit welcher Komplexen Zahl sollen die Vektoren skalisiert werden? ";
        std::cin >> c3;
        KomplexND sum = vec1.add(vec2);
        KomplexND sk = vec1.skal(c3), sk2 = vec2.skal(c3);
        std::cout << "\nVektor 1:";
        vec1.ausgeben();
        std::cout << "Vektor 2:";
        vec2.ausgeben();
        std::cout << "\n";
        std::cout   << "Addition\n"
                    << "Vektor:";
        sum.ausgeben();
        std::cout << "\n";
        std::cout   << "Multiplikation\n" 
                    << "Vektor 1:";
        sk.ausgeben();
        std::cout << "Vektor 2:";
        sk2.ausgeben();
        }
    }
}
