#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <chrono>
#include "studentas.h"
#include <list>

using namespace std;

int main() {
    srand(time(0));

    try {
        cout << "Pasirinkite duomenis (Is dokumento - D, Is ivedimo - I): ";
        char duomenusaltinis;
        cin >> duomenusaltinis;
        list<Studentas> studentai;

        if (duomenusaltinis == 'I' || duomenusaltinis == 'i') {
            int studentuSkaicius;
            cout << "Iveskite studentu skaiciu:";
            cin >> studentuSkaicius;

            if (studentuSkaicius <= 0) {
                throw invalid_argument("Klaida - neteisingas studentu skaicius.");
            }


            for (int i = 0; i < studentuSkaicius; ++i) {
                Studentas studentas;
                cout << "Iveskite studento varda: ";
                cin >> studentas.vardas;
                cout << "Iveskite studento pavarde: ";
                cin >> studentas.pavarde;
                studentas.egzas = rand() % 10 + 1;

                studentas.pazymiai = PazymiuGeneracija(rand() % 10 + 1);

                cout << "Objekto adresas: " << &studentas << endl;

                studentas.galutinis_vidurkis = apskaiciuotiGalutiniBalaVidurkis(studentas.pazymiai, studentas.egzas);
                studentas.galutinis_mediana = skaiciuotiGalutiniBalaMediana(studentas.pazymiai);

                studentai.push_back(studentas);
            }


            char rezultatoRusis;
            cout << "Pasirinkite, kaip norite matyti rezultatus (M - mediana, V - vidurkis): ";
            cin >> rezultatoRusis;

            cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis";

            if (rezultatoRusis == 'M' || rezultatoRusis == 'm') {
                cout << "(Med.)" << endl;
            } else if (rezultatoRusis == 'V' || rezultatoRusis == 'v') {
                cout << "(Vid.)" << endl;
            } else {
                cout << "(Med.)" << endl;
            }

            cout << "--------------------------------------------------------------" << endl;


            for (const Studentas &studentas: studentai) {
                cout << setw(15) << studentas.vardas << setw(15) << studentas.pavarde << setw(15) << fixed
                     << setprecision(2);
                if (rezultatoRusis == 'M' || rezultatoRusis == 'm') {
                    cout << studentas.galutinis_mediana << endl;
                } else if (rezultatoRusis == 'V' || rezultatoRusis == 'v') {
                    cout << studentas.galutinis_vidurkis << endl;
                } else {
                    cout << studentas.galutinis_mediana << endl;
                }
            }


        } else if (duomenusaltinis == 'D' || duomenusaltinis == 'd') {
            ifstream inputFile("C:\\Users\\User\\uzduotis\\10000000.txt");
            if (!inputFile) {
                throw runtime_error("Klaida - failas nerastas.");
            }


            string line;
            getline(inputFile, line);

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

                studentas.galutinis_vidurkis = apskaiciuotiGalutiniBalaVidurkis(studentas.pazymiai,
                                                                                studentas.egzas);
                studentas.galutinis_mediana = skaiciuotiGalutiniBalaMediana(studentas.pazymiai);

                studentai.push_back(studentas);
            }

            inputFile.close();
            auto endRead = chrono::high_resolution_clock::now();

            if (studentai.empty()) {
                throw runtime_error("Klaida - nėra studentų duomenų.");
            }

            auto startSort = chrono::high_resolution_clock::now();

            studentai.sort(RusiavimasPavarde);

            auto endSort = chrono::high_resolution_clock::now();


            list<Studentas> vargsiukai;
            list<Studentas> kietiakiai;

            auto startCategorize = chrono::high_resolution_clock::now();

            auto it = studentai.begin();
            while (it != studentai.end()) {
                if (it->galutinis_vidurkis < 5.0) {
                    vargsiukai.push_back(*it);
                    it = studentai.erase(it);
                } else {
                    ++it;
                }
            }


            ofstream vargsiukaiFile("C:\\Users\\User\\Desktop\\pirma-0.3\\vargsiukai.txt");
            //ofstream kietiakiaiFile("C:\\Users\\User\\Desktop\\pirma-0.3\\kietiakiai.txt");
            auto startWriteVargsiukai = chrono::high_resolution_clock::now();

            for (const Studentas &studentas: vargsiukai) {
                vargsiukaiFile << studentas.vardas << " " << studentas.pavarde << " "
                               << studentas.galutinis_vidurkis
                               << endl;
            }

            auto endWriteVargsiukai = chrono::high_resolution_clock::now();

            /*auto startWriteKietiakiai = chrono::high_resolution_clock::now();

            for (const Studentas &studentas: kietiakiai) {
                kietiakiaiFile << studentas.vardas << " " << studentas.pavarde << " "
                               << studentas.galutinis_vidurkis
                               << endl;
            }

            auto endWriteKietiakiai = chrono::high_resolution_clock::now(); */

            vargsiukaiFile.close();
            //kietiakiaiFile.close();

            auto endCategorize = chrono::high_resolution_clock::now();

            chrono::duration<double> durationRead = endRead - startRead;
            chrono::duration<double> durationSort = endSort - startSort;
            chrono::duration<double> durationCategorize = endCategorize - startCategorize;
            chrono::duration<double> durationWriteVargsiukai = endWriteVargsiukai - startWriteVargsiukai;
            //chrono::duration<double> durationWriteKietiakiai = endWriteKietiakiai - startWriteKietiakiai;


            cout << "Failo is " << studentai.size() << " irasu nuskaitymo laikas: " << durationRead.count()
                 << " sekundziu" << endl;
            cout << "Irasu rusiavimo laikas: " << durationSort.count() << " sekundziu" << endl;
            cout << studentai.size() << " irasu dalijimo i dvigrupes laikas: " << durationCategorize.count()
                 << " sekundziu" << endl;
            cout << vargsiukai.size() << " irasu vargsiuku irasymo i faila laikas: "
                 << durationWriteVargsiukai.count()
                 << " sekundziu" << endl;
            //cout << kietiakiai.size() << " irasu keteku irasymo i faila laikas: " << durationWriteKietiakiai.count()
            //     << " sekundziu" << endl;

            cout << studentai.size() << " irasu testo laikas "
                 << durationRead.count() + durationCategorize.count() + durationWriteVargsiukai.count() +
                    /*durationWriteKietiakiai.count()*/ + durationSort.count();
        }
    }
    catch (const exception &e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}



