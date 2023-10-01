#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <algorithm>
#include "studentas.h"
#include "pazymiai.h"

using namespace std;

bool RusiavimasPavarde(const Studentas& a, const Studentas& b) {
    if (a.pavarde.length() != b.pavarde.length()) {
        return a.pavarde.length() < b.pavarde.length();
    }
    return a.pavarde < b.pavarde;
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    try {
        cout << "Pasirinkite duomenis (Iš dokumento - D, Iš įvedimo - I): ";
        char duomenusaltinis;
        cin >> duomenusaltinis;
        vector<Studentas> studentai;

        if (duomenusaltinis == 'I' || duomenusaltinis == 'i') {
            int studentuSkaicius;
            cout << "Iveskite studentu skaiciu:";
            cin >> studentuSkaicius;

            if (studentuSkaicius <= 0) {
                throw invalid_argument("Klaida - neteisingas studentų skaičius.");
            }

            for (int i = 0; i < studentuSkaicius; ++i) {
                Studentas studentas;
                cout << "Iveskite studento varda: ";
                cin >> studentas.vardas;
                cout << "Iveskite studento pavarde: ";
                cin >> studentas.pavarde;
                studentas.egzas = rand() % 10 + 1;
                studentas.pazymiai = PazymiuGeneracija(rand() % 10 + 1);

                studentas.galutinis_vidurkis = apskaiciuotiGalutiniBalaVidurkis(studentas.pazymiai, studentas.egzas);
                studentas.galutinis_mediana = skaiciuotiGalutiniBalaMediana(studentas.pazymiai);

                studentai.push_back(studentas);
            }
        } else if (duomenusaltinis == 'D' || duomenusaltinis == 'd') {
            ifstream inputFile("2.txt");
            if (!inputFile) {
                throw runtime_error("Klaida - failas '2.txt' nerastas.");
            }

            string line;

            while (getline(inputFile, line)) {
                istringstream iss(line);
                Studentas studentas;
                if (!(iss >> studentas.pavarde >> studentas.vardas)) {
                    cerr << "Klaida - neteisingas duomenu formatas: " << line << endl;
                    continue;
                }
                studentas.pazymiai.clear();
                int pazymys;
                while (iss >> pazymys) {
                    studentas.pazymiai.push_back(pazymys);
                }
                if (studentas.pazymiai.empty()) {
                    cerr << "Klaida - nera pazymiu duomenu: " << line << endl;
                    continue;
                }
                studentas.egzas = studentas.pazymiai.back();
                studentas.pazymiai.pop_back();

                studentas.galutinis_vidurkis = apskaiciuotiGalutiniBalaVidurkis(studentas.pazymiai, studentas.egzas);
                studentas.galutinis_mediana = skaiciuotiGalutiniBalaMediana(studentas.pazymiai);

                studentai.push_back(studentas);
            }

            inputFile.close();
        } else {
            throw invalid_argument("Klaida - neteisingai parinktas duomenu saltinis.");
        }

        if (studentai.empty()) {
            throw runtime_error("Klaida - nėra studentų duomenų.");
        }

        sort(studentai.begin(), studentai.end(), RusiavimasPavarde);

        cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis(Vid.)" << setw(15)
             << "Galutinis(Med.)" << endl;
        cout << "--------------------------------------------------------------" << endl;
        for (const Studentas& studentas : studentai) {
            cout << setw(15) << studentas.vardas << setw(15) << studentas.pavarde << setw(15) << fixed
                 << setprecision(2) << studentas.galutinis_vidurkis << setw(15) << studentas.galutinis_mediana << endl;
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}