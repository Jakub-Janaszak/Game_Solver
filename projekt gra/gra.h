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
    /** Funkcja wy�wietla plansze w konsoli i w pliku zapis.txt
    @param plansza plansza, kt�r� funkcja ma wy�wietli�
    @param max_wielkosc_kolumny maksymalna wysko��, kt�r� mo�e przybra� kolumna w planszy*/
    void wypisanie_planszy(std::vector<std::vector<char>> plansza, int max_wielkosc_kolumny);
    /** Funkcja przek�ada element z jednej kolumny na drug�
    @param plansza plansza, kt�r� funkcja ma wy�wietli�
    @param kolumna_odejmij kolumna, z kt�rej funkcja zabiera element
    @param kolumna_odejmij kolumna, do kt�rej funkcja dodaje element*/
    void przelozenie_elementu(std::vector<std::vector<char>>& plansza, int kolumna_odejmij, int kolumna_dodaj);
    /** Funkcja sprawdza, czy plansza jest ju� u�o�ona 
    @param plansza plansza, kt�r� funkcja ma wy�wietli�
    @param max_wielkosc_kolumny maksymalna wysko��, kt�r� mo�e przybra� kolumna w planszy*/
    bool sprawdzenie_czy_ulozone(std::vector<std::vector<char>>& plansza, int max_wielkosc_kolumny);
    /** Funkcja sprawdza, z kt�rej kolumny zabra� element, �eby do�o�y� do pustej komuny i to wykonuje
    @param plansza plansza, kt�r� funkcja ma wy�wietli�
    @param max_wielkosc_kolumny maksymalna wysko��, kt�r� mo�e przybra� kolumna w planszy
    @return funkcja zwraca true, je�li plansza jest u�o�ona*/
    void pusta_kolumna(std::vector<std::vector<char>>& plansza, int max_wielkosc_kolumny);
    /** Funkcja rozpoczynaj�ca uk�adanie planszy*/
    void rozpoczecie_gry();
};
