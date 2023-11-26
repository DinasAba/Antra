#include "studentas.h"
#include <algorithm>
#include <vector>
#include <string>


using namespace std;


bool RusiavimasPavarde(const Studentas& a, const Studentas& b) {
    if (a.getPavarde().length() != b.getPavarde().length()) {
        return a.getPavarde().length() < b.getPavarde().length();
    }
    return a.getPavarde() < b.getPavarde();
}

double skaiciuotiGalutiniBalaMediana(const vector<int>& pazymiai) {
    vector<int> pazymiukopija = pazymiai;
    sort(pazymiukopija.begin(), pazymiukopija.end());
    int dydis = pazymiukopija.size();

    if (dydis % 2 == 0) {
        auto it1 = next(pazymiukopija.begin(), dydis / 2 - 1);
        auto it2 = next(pazymiukopija.begin(), dydis / 2);
        int viduris1 = *it1;
        int viduris2 = *it2;
        return (viduris1 + viduris2) / 2.0;
    } else {
        auto it = next(pazymiukopija.begin(), dydis / 2);
        return *it;
    }
}

double apskaiciuotiGalutiniBalaVidurkis(const vector<int>& pazymiai, int egzas) {
    double vidurkis = 0.0;

    if (!pazymiai.empty()) {
        for (size_t i = 0; i < pazymiai.size() - 1; ++i) {
            vidurkis += pazymiai[i];
        }

        vidurkis /= (pazymiai.size() - 1);
    }

    return 0.4 * vidurkis + 0.6 * egzas;
}

vector<int> PazymiuGeneracija(int kiekis) {
    vector<int> pazymiai;
    for (int i = 0; i < kiekis; ++i) {
        pazymiai.push_back(rand() % 10 + 1);
    }
    return pazymiai;
}
