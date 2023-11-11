#include "studentas.h"
#include <algorithm>


using namespace std;

double apskaiciuotiGalutiniBalaVidurkis(const std::list<int>& pazymiai, int egzas) {
    double vidurkis = 0.0;
    for (int pazymis : pazymiai) {
        vidurkis += pazymis;
    }
    if (!pazymiai.empty()) {
        vidurkis /= pazymiai.size();
    }
    return 0.4 * vidurkis + 0.6 * egzas;
}

double skaiciuotiGalutiniBalaMediana(const list<int>& pazymiai) {
    list<int> pazymiukopija = pazymiai;
    pazymiukopija.sort();
    int dydis = pazymiukopija.size();

    if (dydis % 2 == 0) {
        auto it1 = std::next(pazymiukopija.begin(), dydis / 2 - 1);
        auto it2 = std::next(pazymiukopija.begin(), dydis / 2);
        int viduris1 = *it1;
        int viduris2 = *it2;
        return (viduris1 + viduris2) / 2.0;
    } else {
        auto it = std::next(pazymiukopija.begin(), dydis / 2);
        return *it;
    }
}


bool RusiavimasPavarde(const Studentas& a, const Studentas& b) {
    if (a.pavarde.length() != b.pavarde.length()) {
        return a.pavarde.length() < b.pavarde.length();
    }
    return a.pavarde < b.pavarde;
}

std::list<int> PazymiuGeneracija(int kiekis) {
    std::list<int> pazymiai;
    for (int i = 0; i < kiekis; ++i) {
        pazymiai.push_back(rand() % 10 + 1);
    }
    return pazymiai;
}

