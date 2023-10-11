#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
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
      srand(time(0));

    for (int n = 1000; n <= 10000000; n *= 10) {
        string filename = to_string(n) + ".txt";
        ofstream outputFile(filename);

        for (int i = 1; i <= n; ++i) {
            outputFile << "Pavarde" << i << " Vardas" << i;

            int pazymiuKiekis = rand() % 10 + 1; 

            for (int j = 0; j < pazymiuKiekis; ++j) {
                int pazymys = rand() % 10 + 1;
                outputFile << " " << pazymys;
            }

            outputFile << endl;
        }

        outputFile.close();
    }

    return 0;

    try {
        vector<Studentas> studentai;
        ifstream inputFile("2.txt"); 

        if (!inputFile) {
            throw runtime_error("Klaida - failas nerastas.");
        }

        string line;

        while (getline(inputFile, line)) {
            istringstream iss(line);
            Studentas studentas;
            if (!(iss >> studentas.pavarde >> studentas.vardas)) {
                cerr << "Klaida - neteisingas duomenų formatas: " << line << endl;
                continue;
            }
            studentas.pazymiai.clear();
            int pazymys;
            while (iss >> pazymys) {
                studentas.pazymiai.push_back(pazymys);
            }
            if (studentas.pazymiai.empty()) {
                cerr << "Klaida - nėra pažymių duomenų: " << line << endl;
                continue;
            }
            studentas.egzas = studentas.pazymiai.back();
            studentas.pazymiai.pop_back();

            studentas.galutinis_vidurkis = apskaiciuotiGalutiniBalaVidurkis(studentas.pazymiai, studentas.egzas);
            studentas.galutinis_mediana = skaiciuotiGalutiniBalaMediana(studentas.pazymiai);

            studentai.push_back(studentas);
        }

        inputFile.close();

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


