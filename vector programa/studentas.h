#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Studentas {
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> pazymiai;
    int egzas;
    double galutinis_vidurkis;
    double galutinis_mediana;

public:

    Studentas() : egzas(0), galutinis_vidurkis(0.0), galutinis_mediana(0.0) {}


    Studentas(const std::string& v, const std::string& p, const std::vector<int>& paz, int e)
            : vardas(v), pavarde(p), pazymiai(paz), egzas(e), galutinis_vidurkis(0.0), galutinis_mediana(0.0) {}


    const std::string getVardas() const { return vardas; }
    const std::string getPavarde() const { return pavarde; }
    std::vector<int> getPazymiai() const { return pazymiai; }
    int getEgzas() const { return egzas; }
    double getGalutinisVidurkis() const { return galutinis_vidurkis; }
    double getGalutinisMediana() const { return galutinis_mediana; }

    void addPazymys(int paz) { pazymiai.push_back(paz); }
    void clearPazymiai() { pazymiai.clear(); }
    void setVardas(const std::string& v) { vardas = v; }
    void setPavarde(const std::string& p) { pavarde = p; }
    void setPazymiai(const std::vector<int>& paz) { pazymiai = paz; }
    void setEgzas(int e) { egzas = e; }
    void setGalutinisVidurkis(double vidurkis) { galutinis_vidurkis = vidurkis; }
    void setGalutinisMediana(double mediana) { galutinis_mediana = mediana; }

    ~Studentas() {pazymiai.clear(); };
};


double apskaiciuotiGalutiniBalaVidurkis(const std::vector<int>& pazymiai, int egzas);
bool RusiavimasPavarde(const Studentas& a, const Studentas& b);
std::vector<int> PazymiuGeneracija(int kiekis);
double skaiciuotiGalutiniBalaMediana(const std::vector<int>& pazymiai);
std::vector<int> nuskaitytiPazymius();



