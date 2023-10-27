
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
};

double apskaiciuotiGalutiniBalaVidurkis(const std::list<int>& pazymiai, int egzas);
bool RusiavimasPavarde(const Studentas& a, const Studentas& b);


