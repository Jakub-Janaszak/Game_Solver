#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "gra.h"


void Gra::wypisanie_planszy(std::vector<std::vector<char>> plansza, int max_wielkosc_kolumny)
{

    for (int i = 0; i < plansza.size(); i++)
    {
        std::cout << "<" << i + 1 << "> ";
        zapis << "<" << i + 1 << "> ";
        for (int j = 0; j < max_wielkosc_kolumny; j++)
        {
            std::cout << (j < plansza[i].size() ? plansza[i][j] : '.');
            zapis << (j < plansza[i].size() ? plansza[i][j] : '.');
        }
        std::cout << std::endl;
        zapis << std::endl;
    }
}

void Gra::przelozenie_elementu(std::vector<std::vector<char>>& plansza, int kolumna_odejmij, int kolumna_dodaj)
{
    if (ostatnia_kolumna_dodaj == kolumna_odejmij && ostatnia_kolumna_odejmij == kolumna_dodaj)
    {
        system("cls");
        std::cout << "Brak mozliwosci rozwiazania.";
        zapis.close();
        zapis.open("rozwi¹zanie.txt");
        zapis << "Brak mo¿liwoœci rozwi¹zania.";
        zapis.close();
        exit(0);
    }
    plansza[kolumna_dodaj].push_back(plansza[kolumna_odejmij].back());
    plansza[kolumna_odejmij].pop_back();

    std::cout << std::endl << "<" << kolumna_odejmij + 1 << "> ---> <" << kolumna_dodaj + 1 << "> " << std::endl;
    zapis << std::endl << "<" << kolumna_odejmij + 1 << "> ---> <" << kolumna_dodaj + 1 << "> " << std::endl;

    ostatnia_kolumna_dodaj = kolumna_dodaj;
    ostatnia_kolumna_odejmij = kolumna_odejmij;
}

bool Gra::sprawdzenie_czy_ulozone(std::vector<std::vector<char>>& plansza, int max_wielkosc_kolumny)
{
    char pomocnicza;
    for (int i = 0; i < plansza.size(); i++)
    {
        if (plansza[i].empty())
            continue;
        if (plansza[i].size() == max_wielkosc_kolumny)
        {
            for (int j = 0; j < plansza[i].size(); j++)
            {
                if (j == 0)
                    pomocnicza = plansza[i][j];
                else
                {
                    if (plansza[i][j] != pomocnicza)
                        return false;
                }
            }
        }
        else
            return false;
    }
    return true;
}

void Gra::pusta_kolumna(std::vector<std::vector<char>>& plansza, int max_wielkosc_kolumny)
{
    int id_pustej_kolumny = 0;
    int najczestsza_litera = 0;
    int max_ilosc_wystapien = 0;
    int id_kolumny_z_najczestrza_litera = 0;
    bool czy_cala_kolumna_taka_sama;

    int ilosc_wys_liter_na_szczycie[26]; // 0=A, 1=B, 2=C...
    for (int i = 0; i < 26; i++)
        ilosc_wys_liter_na_szczycie[i] = 0;

    for (int i = 0; i < plansza.size(); i++)
    {
        if (plansza[i].empty())
            id_pustej_kolumny = i;
        else
        {
            czy_cala_kolumna_taka_sama = true; //sprawdzenie czy cala kolumna nie jest z tych samych el
            for (int j = 0; j < plansza[i].size() - 1; j++)
            {
                 if (plansza[i].back() != plansza[i][j])
                 czy_cala_kolumna_taka_sama = false;
            }
            if (czy_cala_kolumna_taka_sama == false)
            {
                ilosc_wys_liter_na_szczycie[int(plansza[i].back()) - 65] += 2;
                if (plansza[i].back() == plansza[i][max_wielkosc_kolumny - 2])
                ilosc_wys_liter_na_szczycie[int(plansza[i].back()) - 65]++;
            }
        }
    }

    for (int i = 0; i < 26; i++) //Sprawdzenie ktorej litery jest najwiecej
    {
        if (ilosc_wys_liter_na_szczycie[i] >= max_ilosc_wystapien)
        {
            najczestsza_litera = i;
            max_ilosc_wystapien = ilosc_wys_liter_na_szczycie[i];
        }
    }

    for (int i = 0; i < plansza.size(); i++) //Sprawdzenie w ktorej kolumnie jest najczesciej wystepujaca litera
    {
        if (!plansza[i].empty() && plansza[i].back() == (char)(65 + najczestsza_litera))
        {
            id_kolumny_z_najczestrza_litera = i;
            if (plansza[i][plansza[i].size() - 2] == (char)(65 + najczestsza_litera))
                break;
        }
    }

    przelozenie_elementu(plansza, id_kolumny_z_najczestrza_litera, id_pustej_kolumny);
    wypisanie_planszy(plansza, max_wielkosc_kolumny);

}


void Gra::rozpoczecie_gry()
{

    //plik
    plik.open("plik.txt");
    zapis.open("rozwi¹zanie.txt");
    if (plik.good() == false)
    {
        std::cout << "brak pliku wejsciowego 'plik.txt'";
        zapis << "brak pliku wejsciowego 'plik.txt'";
        return;
    }
        
    //wgrywanie z pliku
    while (plik >> znak)
    {
        if (int(znak[0]) >= 48 && int(znak[0]) <= 57)
        {
            if (!(int(znak[0]) == 49 && znak.size() == 1))
            {
                wielkosc_kolumny = 0;
                plansza.push_back(kolumny);
                kolumny.clear();
            }
        }
        else
        {
            if (int(znak[0]) != 46)
                kolumny.push_back(znak[0]);
            wielkosc_kolumny++;
            if (wielkosc_kolumny > max_wielkosc_kolumny)
                max_wielkosc_kolumny = wielkosc_kolumny;
        }

    }
    plansza.push_back(kolumny);
    plik.close();

    wypisanie_planszy(plansza, max_wielkosc_kolumny);
    pusta_kolumna(plansza, max_wielkosc_kolumny);


    bool czy_wszystkie_w_kolumnie_takie_same_i = true;
    bool czy_wszystkie_w_kolumnie_takie_same_j = true;
    while (sprawdzenie_czy_ulozone(plansza, max_wielkosc_kolumny) == false)
    {
        for (int i = 0; i < plansza.size() - 1; i++)
        {
            for (int j = i + 1; j < plansza.size(); j++)
            {
                if (sprawdzenie_czy_ulozone(plansza, max_wielkosc_kolumny) == true)
                {
                    zapis.close();
                    return;
                }

                for (int k = 0; k < plansza.size(); k++)
                {
                    if(plansza[k].empty()==true)
                        pusta_kolumna(plansza, max_wielkosc_kolumny);
                }

                czy_wszystkie_w_kolumnie_takie_same_i = true;
                czy_wszystkie_w_kolumnie_takie_same_j = true;

                if ((plansza[i].back() == plansza[j].back()) && (plansza[i].size() < max_wielkosc_kolumny || plansza[j].size() < max_wielkosc_kolumny))
                {
                    for (int k = 0; k < plansza[i].size(); k++)
                    {
                        if (plansza[i][k] != plansza[i].back())
                            czy_wszystkie_w_kolumnie_takie_same_i = false;
                    }
                    for (int k = 0; k < plansza[j].size(); k++)
                    {
                        if (plansza[j][k] != plansza[i].back())
                            czy_wszystkie_w_kolumnie_takie_same_j = false;
                    }

                    if (czy_wszystkie_w_kolumnie_takie_same_i == true && czy_wszystkie_w_kolumnie_takie_same_j == true)
                    {
                        if (plansza[i].size() > plansza[j].size())
                            przelozenie_elementu(plansza, j, i);
                        else
                            przelozenie_elementu(plansza, i, j);
                        wypisanie_planszy(plansza, max_wielkosc_kolumny);
                    }
                    else if (czy_wszystkie_w_kolumnie_takie_same_i == true)
                    {
                        przelozenie_elementu(plansza, j, i);
                        wypisanie_planszy(plansza, max_wielkosc_kolumny);
                    }
                    else if (czy_wszystkie_w_kolumnie_takie_same_j == true)
                    {
                        przelozenie_elementu(plansza, i, j);
                        wypisanie_planszy(plansza, max_wielkosc_kolumny);
                    }
                    else
                    {
                        if (plansza[i].size() > plansza[j].size())
                        {
                            przelozenie_elementu(plansza, i, j);
                            wypisanie_planszy(plansza, max_wielkosc_kolumny);
                        }
                        else
                        {
                            przelozenie_elementu(plansza, j, i);
                            wypisanie_planszy(plansza, max_wielkosc_kolumny);
                        }
                    }
                }
            }
        }
    }
    zapis.close();
    return;
}