
#pragma once

#include <string>
#include <vector>
#include <list>

struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::list<int> pazymiai;
    int egzas;
    double galutinis_vidurkis;
    double galutinis_mediana;
};

double apskaiciuotiGalutiniBalaVidurkis(const std::list<int>& pazymiai, int egzas);
bool RusiavimasPavarde(const Studentas& a, const Studentas& b);
std::list<int> PazymiuGeneracija(int kiekis);
double skaiciuotiGalutiniBalaMediana(const std::list<int>& pazymiai);

