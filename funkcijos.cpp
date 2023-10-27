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
        return vidurkis;

}
bool RusiavimasPavarde(const Studentas& a, const Studentas& b) {
        if (a.pavarde.length() != b.pavarde.length()) {
            return a.pavarde.length() < b.pavarde.length();
        }
        return a.pavarde < b.pavarde;

}