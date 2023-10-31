#include <iostream>
#include <fstream>
#include <vector>

class Gra
{
public:
    /**zmienne
    */
    std::vector<std::vector<char>> plansza;
    std::vector<char> kolumny;
    std::string znak;
    int wielkosc_kolumny = 0;
    int max_wielkosc_kolumny = 0;
    std::fstream plik;
    std::ofstream zapis;
    int ostatnia_kolumna_odejmij=0;
    int ostatnia_kolumna_dodaj=0;
    /** Funkcja wyœwietla plansze w konsoli i w pliku zapis.txt
    @param plansza plansza, któr¹ funkcja ma wyœwietliæ
    @param max_wielkosc_kolumny maksymalna wyskoœæ, któr¹ mo¿e przybraæ kolumna w planszy*/
    void wypisanie_planszy(std::vector<std::vector<char>> plansza, int max_wielkosc_kolumny);
    /** Funkcja przek³ada element z jednej kolumny na drug¹
    @param plansza plansza, któr¹ funkcja ma wyœwietliæ
    @param kolumna_odejmij kolumna, z której funkcja zabiera element
    @param kolumna_odejmij kolumna, do której funkcja dodaje element*/
    void przelozenie_elementu(std::vector<std::vector<char>>& plansza, int kolumna_odejmij, int kolumna_dodaj);
    /** Funkcja sprawdza, czy plansza jest ju¿ u³o¿ona 
    @param plansza plansza, któr¹ funkcja ma wyœwietliæ
    @param max_wielkosc_kolumny maksymalna wyskoœæ, któr¹ mo¿e przybraæ kolumna w planszy*/
    bool sprawdzenie_czy_ulozone(std::vector<std::vector<char>>& plansza, int max_wielkosc_kolumny);
    /** Funkcja sprawdza, z której kolumny zabraæ element, ¿eby do³o¿yæ do pustej komuny i to wykonuje
    @param plansza plansza, któr¹ funkcja ma wyœwietliæ
    @param max_wielkosc_kolumny maksymalna wyskoœæ, któr¹ mo¿e przybraæ kolumna w planszy
    @return funkcja zwraca true, jeœli plansza jest u³o¿ona*/
    void pusta_kolumna(std::vector<std::vector<char>>& plansza, int max_wielkosc_kolumny);
    /** Funkcja rozpoczynaj¹ca uk³adanie planszy*/
    void rozpoczecie_gry();
};
