#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Zmogus {

protected:
    std::string vardas;
    std::string pavarde;

public:
    Zmogus() = default;
    Zmogus(const std::string& v, const std::string& p) : vardas(v), pavarde(p) {}
    virtual ~Zmogus() = default;

    virtual const std::string& getVardas() const { return vardas; }
    virtual const std::string& getPavarde() const { return pavarde; }

    virtual void setVardas(const std::string& v) { vardas = v; }
    virtual void setPavarde(const std::string& p) { pavarde = p; }

    virtual void printInfo() const = 0;
};


class Studentas : public Zmogus {
private:
    std::vector<int> pazymiai;
    int egzas;
    double galutinis_vidurkis;
    double galutinis_mediana;


public:

    Studentas() : Zmogus(), egzas(0), galutinis_vidurkis(0.0), galutinis_mediana(0.0) {}
    Studentas(const std::string& v, const std::string& p, const std::vector<int>& paz, int e)
            : Zmogus(v, p), pazymiai(paz), egzas(e), galutinis_vidurkis(0.0), galutinis_mediana(0.0) {}

    const std::string& getVardas() const override { return Zmogus::vardas; }
    const std::string& getPavarde() const override { return Zmogus::pavarde; }
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
    void printInfo() const override {
        std::cout << "Vardas: " << getVardas() << ", Pavarde: " << getPavarde()
                  << ", Galutinis vidurkis: " << galutinis_vidurkis
                  << ", Galutinis mediana: " << galutinis_mediana << std::endl;
    }

    ~Studentas() {pazymiai.clear(); };

    Studentas(const Studentas& other) {
        vardas = other.vardas;
        pavarde = other.pavarde;
        pazymiai = other.pazymiai;
        egzas = other.egzas;
        galutinis_vidurkis = other.galutinis_vidurkis;
        galutinis_mediana = other.galutinis_mediana;
    }

    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            vardas = other.vardas;
            pavarde = other.pavarde;
            pazymiai = other.pazymiai;
            egzas = other.egzas;
            galutinis_vidurkis = other.galutinis_vidurkis;
            galutinis_mediana = other.galutinis_mediana;
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Studentas& studentas) {
        os << "Vardas: " << studentas.vardas << ", Pavarde: " << studentas.pavarde
           << ", Galutinis vidurkis: " << studentas.galutinis_vidurkis
           << ", Galutinis mediana: " << studentas.galutinis_mediana;

        return os;
    }

    friend std::istream& operator>>(std::istream& is, Studentas& studentas) {
        std::cout << "Iveskite studento varda: ";
        is >> studentas.vardas;
        std::cout << "Iveskite studento pavarde: ";
        is >> studentas.pavarde;
        std::cout << "Iveskite egzamino rezultata: ";
        is >> studentas.egzas;


        std::cout << "Iveskite pazymius (pabaiga zymima -1): ";
        int pazymys;
        while (is >> pazymys && pazymys != -1) {
            studentas.pazymiai.push_back(pazymys);
        }

        return is;
    }
};


double apskaiciuotiGalutiniBalaVidurkis(const std::vector<int>& pazymiai, int egzas);
bool RusiavimasPavarde(const Studentas& a, const Studentas& b);
std::vector<int> PazymiuGeneracija(int kiekis);
double skaiciuotiGalutiniBalaMediana(const std::vector<int>& pazymiai);
std::vector<int> nuskaitytiPazymius();



