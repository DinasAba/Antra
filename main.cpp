#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include "studentas.h"
#include <chrono>


using namespace std;


int main() {
    try {
        vector<Studentas> studentai;
        ifstream inputFile("C:\\Users\\User\\0.2uzd\\1000.txt");

        if (!inputFile) {
            throw runtime_error("Klaida - failas nerastas.");
        }

        string line;

        auto startRead = chrono::high_resolution_clock::now();

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

            studentai.push_back(studentas);
        }

        inputFile.close();

        if (studentai.empty()) {
            throw runtime_error("Klaida - nėra studentų duomenų.");
        }

        sort(studentai.begin(), studentai.end(), RusiavimasPavarde);

        auto endRead = chrono::high_resolution_clock::now();



        vector<Studentas> vargsiukai;
        vector<Studentas> kietiakiai;

        auto startCategorize = chrono::high_resolution_clock::now();

        for (const Studentas& studentas : studentai) {
            if (studentas.galutinis_vidurkis < 5.0) {
                vargsiukai.push_back(studentas);
            } else {
                kietiakiai.push_back(studentas);
            }
        }


        ofstream vargsiukaiFile("C:\\Users\\User\\0.2uzd\\vargsiukai.txt");
        ofstream kietiakiaiFile("C:\\Users\\User\\0.2uzd\\kietiakiai.txt");
        auto startWriteVargsiukai = chrono::high_resolution_clock::now();

        for (const Studentas& studentas : vargsiukai) {
            vargsiukaiFile << studentas.vardas << " " << studentas.pavarde << " " << studentas.galutinis_vidurkis << endl;
        }

        auto endWriteVargsiukai = chrono::high_resolution_clock::now();

        auto startWriteKietiakiai = chrono::high_resolution_clock::now();

        for (const Studentas& studentas : kietiakiai) {
            kietiakiaiFile << studentas.vardas << " " << studentas.pavarde << " " << studentas.galutinis_vidurkis << endl;
        }

        auto endWriteKietiakiai = chrono::high_resolution_clock::now();

        vargsiukaiFile.close();
        kietiakiaiFile.close();

        auto endCategorize = chrono::high_resolution_clock::now();



        chrono::duration<double> durationRead = endRead - startRead;
        chrono::duration<double> durationCategorize = endCategorize - startCategorize;
        chrono::duration<double> durationWriteVargsiukai = endWriteVargsiukai - startWriteVargsiukai;
        chrono::duration<double> durationWriteKietiakiai = endWriteKietiakiai - startWriteKietiakiai;

        cout << "Failo is " << studentai.size() << " irasu nuskaitymo laikas: " << durationRead.count() << " sekundziu" << endl;
        cout << studentai.size() << " irasu dalijimo i dvigrupes laikas: " << durationCategorize.count() << " sekundziu" << endl;
        cout << vargsiukai.size() << " irasu vargsiuku irasymo i faila laikas: " << durationWriteVargsiukai.count() << " sekundziu" << endl;
        cout << kietiakiai.size() << " irasu keteku irasymo i faila laikas: " << durationWriteKietiakiai.count() << " sekundziu" << endl;

        cout << studentai.size() << " irasu testo laikas " << durationRead.count() + durationCategorize.count() + durationWriteVargsiukai.count() + durationWriteKietiakiai.count();

    } catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}



