
#pragma once

#include <string>
#include <vector>

struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> pazymiai;
    int egzas;
    double galutinis_vidurkis;
};

double apskaiciuotiGalutiniBalaVidurkis(const std::vector<int>& pazymiai, int egzas);
bool RusiavimasPavarde(const Studentas& a, const Studentas& b);


