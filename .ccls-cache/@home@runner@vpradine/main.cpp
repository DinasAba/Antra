#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "studentas.h"
#include "pazymiai.h"

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(0)));

    cout << "Pasirinkite duomenis (Iš dokumento - D, Iš įvedimo - I): ";
    char duomenusaltinis;
    cin >> duomenusaltinis;
    vector<Studentas> studentai;

    if (duomenusaltinis == 'I' || duomenusaltinis == 'i') {
        int studentuSkaicius;
        cout << "Iveskite studentu skaiciu:";
        cin >> studentuSkaicius;

        for (int i = 0; i < studentuSkaicius; ++i) {
            Studentas studentas;
            cout << "Iveskite studento varda: ";
            cin >> studentas.vardas;
            cout << "Iveskite studento pavarde: ";
            cin >> studentas.pavarde;
            studentas.egzas = rand() % 10 + 1;
            studentas.pazymiai = PazymiuGeneracija(rand() % 10 + 1);
            cout << "Pasirinkite skaiciavimo metoda (Vidurkis - V, Mediana - M): ";
            char skaiciavimoMetodas;
            cin >> skaiciavimoMetodas;
            if (skaiciavimoMetodas == 'V' || skaiciavimoMetodas == 'v') {
                studentas.galutinis = 0.4 * apskaiciuotiGalutiniBalaVidurkis(studentas.pazymiai, studentas.egzas) + 0.6 * studentas.egzas;
            } else if (skaiciavimoMetodas == 'M' || skaiciavimoMetodas == 'm') {
                studentas.galutinis = 0.4 * skaiciuotiGalutiniBalaMediana(studentas.pazymiai) + 0.6 * studentas.egzas;
            } else {
                cout << "Neteisingai parinktas skaiciavimo metodas. Taikomas vidurkis skaiciavimas" << endl;
                studentas.galutinis = 0.4 * apskaiciuotiGalutiniBalaVidurkis(studentas.pazymiai, studentas.egzas) + 0.6 * studentas.egzas;
            }
            studentai.push_back(studentas);
        }
    } else if (duomenusaltinis == 'D' || duomenusaltinis == 'd') {
        ifstream inputFile("kursiokai.txt");
        if (!inputFile.is_open()) {
            cerr << "Klaida - failas 'kursiokai.txt' nerastas." << endl;
            return 1;
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

            cout << "Pasirinkite skaiciavimo metoda (Vidurkis - V, Mediana - M): ";
            char skaiciavimoMetodas;
            cin >> skaiciavimoMetodas;
            if (skaiciavimoMetodas == 'V' || skaiciavimoMetodas == 'v') {
                studentas.galutinis = 0.4 * apskaiciuotiGalutiniBalaVidurkis(studentas.pazymiai, studentas.egzas) + 0.6 * studentas.egzas;
            } else if (skaiciavimoMetodas == 'M' || skaiciavimoMetodas == 'm') {
                studentas.galutinis = 0.4 * skaiciuotiGalutiniBalaMediana(studentas.pazymiai) + 0.6 * studentas.egzas;
            } else {
                cout << "Neteisingai parinktas skaiciavimo metodas. Taikomas vidurkis skaiciavimas" << endl;
                studentas.galutinis = 0.4 * apskaiciuotiGalutiniBalaVidurkis(studentas.pazymiai, studentas.egzas) + 0.6 * studentas.egzas;
            }
            studentai.push_back(studentas);
        }

        inputFile.close();
    } else {
        cerr << "Klaida - neteisingai parinktas duomenu saltinis." << endl;
        return 1;
    }

    cout << "Pavarde\tVardas\tGalutinis(Vid)\tGalutinis(Med)" << endl;
    cout << "---------------------------------------------" << endl;
    for (const Studentas& studentas : studentai) {
        cout << studentas.pavarde << "\t" << studentas.vardas << "\t" << fixed << setprecision(2) << studentas.galutinis << endl;
    }
    return 0;
}
