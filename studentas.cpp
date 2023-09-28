#include "studentas.h"
#include <algorithm>

double apskaiciuotiGalutiniBalaVidurkis(const vector<int>& pazymiai, int egzas) {
    double vidurkis = 0.0;
    for (int pazymis : pazymiai) {
        vidurkis += pazymis;
    }
    if (!pazymiai.empty()) {
        vidurkis /= pazymiai.size();
    }
    return vidurkis;
}

double skaiciuotiGalutiniBalaMediana(const vector<int>& pazymiai) {
    vector<int> pazymiukopija = pazymiai;
    sort(pazymiukopija.begin(), pazymiukopija.end());
    int dydis = pazymiukopija.size();
    if (dydis % 2 == 0) {
        int viduris1 = pazymiukopija[dydis / 2 - 1];
        int viduris2 = pazymiukopija[dydis / 2.0];
        return (viduris1 + viduris2) / 2.0;
    } else {
        return pazymiukopija[dydis / 2.0];
    }
}