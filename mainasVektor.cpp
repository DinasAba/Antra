#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <chrono>


using namespace std;

struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> pazymiai;
    int egzas;
    double galutinis_vidurkis;
};



double apskaiciuotiGalutiniBalaVidurkis(const vector<int>& pazymiai, int egzas) {
    double vidurkis = 0.0;
    for (int pazymis : pazymiai) {
        vidurkis += pazymis;
    }
    vidurkis /= (pazymiai.size() > 0 ? pazymiai.size() : 1);
    return 0.4 * vidurkis + 0.6 * egzas;
}

bool RusiavimasPavarde(const Studentas& a, const Studentas& b) {
    if (a.pavarde.length() != b.pavarde.length()) {
        return a.pavarde.length() < b.pavarde.length();
    }
    return a.pavarde < b.pavarde;
}

    int main() {
        srand(time(0));

        try {
            cout << "Pasirinkite duomenis (Is dokumento - D, Is ivedimo - I): ";
            char duomenusaltinis;
            cin >> duomenusaltinis;
            vector<Studentas> studentai;

            if (duomenusaltinis == 'I' || duomenusaltinis == 'i') {
                int studentuSkaicius;
                cout << "Iveskite studentu skaiciu:";
                cin >> studentuSkaicius;

                if (studentuSkaicius <= 0) {
                    throw invalid_argument("Klaida - neteisingas studentu skaicius.");
                }

                vector<Studentas> studentai;

                for (int i = 0; i < studentuSkaicius; ++i) {
                    Studentas studentas;
                    cout << "Iveskite studento varda: ";
                    cin >> studentas.vardas;
                    cout << "Iveskite studento pavarde: ";
                    cin >> studentas.pavarde;
                    studentas.egzas = rand() % 10 + 1;


                    cout << "Objekto adresas: " << &studentas << endl;

                    studentas.galutinis_vidurkis = apskaiciuotiGalutiniBalaVidurkis(studentas.pazymiai,
                                                                                    studentas.egzas);


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

                    } else if (rezultatoRusis == 'V' || rezultatoRusis == 'v') {
                        cout << studentas.galutinis_vidurkis << endl;
                    } else {

                    }
                }
            } else if (duomenusaltinis == 'D' || duomenusaltinis == 'd') {
                ifstream inputFile("C:\\Users\\User\\uzduotis\\1000.txt");
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

                    studentai.push_back(studentas);
                }

                inputFile.close();
                auto endRead = chrono::high_resolution_clock::now();

                if (studentai.empty()) {
                    throw runtime_error("Klaida - nėra studentų duomenų.");
                }

                auto startSort = chrono::high_resolution_clock::now();

                sort(studentai.begin(), studentai.end(), RusiavimasPavarde);

                auto endSort = chrono::high_resolution_clock::now();

                vector<Studentas> vargsiukai;
                vector<Studentas> kietiakiai;

                auto startCategorize = chrono::high_resolution_clock::now();

                for (const Studentas &studentas: studentai) {
                    if (studentas.galutinis_vidurkis < 5.0) {
                        vargsiukai.push_back(studentas);
                    } else {
                        kietiakiai.push_back(studentas);
                    }
                }

                ofstream vargsiukaiFile("C:\\Users\\User\\Desktop\\pirma-0.3\\vargsiukai.txt");
                ofstream kietiakiaiFile("C:\\Users\\User\\Desktop\\pirma-0.3\\kietiakiai.txt");
                auto startWriteVargsiukai = chrono::high_resolution_clock::now();

                for (const Studentas &studentas: vargsiukai) {
                    vargsiukaiFile << studentas.vardas << " " << studentas.pavarde << " "
                                   << studentas.galutinis_vidurkis
                                   << endl;
                }

                auto endWriteVargsiukai = chrono::high_resolution_clock::now();

                auto startWriteKietiakiai = chrono::high_resolution_clock::now();

                for (const Studentas &studentas: kietiakiai) {
                    kietiakiaiFile << studentas.vardas << " " << studentas.pavarde << " "
                                   << studentas.galutinis_vidurkis
                                   << endl;
                }

                auto endWriteKietiakiai = chrono::high_resolution_clock::now();

                vargsiukaiFile.close();
                kietiakiaiFile.close();

                auto endCategorize = chrono::high_resolution_clock::now();

                chrono::duration<double> durationRead = endRead - startRead;
                chrono::duration<double> durationSort = endSort - startSort;
                chrono::duration<double> durationCategorize = endCategorize - startCategorize;
                chrono::duration<double> durationWriteVargsiukai = endWriteVargsiukai - startWriteVargsiukai;
                chrono::duration<double> durationWriteKietiakiai = endWriteKietiakiai - startWriteKietiakiai;

                cout << "Failo is " << studentai.size() << " irasu nuskaitymo laikas: " << durationRead.count()
                     << " sekundziu" << endl;
                cout << "Irasu rusiavimo laikas: " << durationSort.count() << " sekundziu" << endl;
                cout << studentai.size() << " irasu dalijimo i dvigrupes laikas: " << durationCategorize.count()
                     << " sekundziu" << endl;
                cout << vargsiukai.size() << " irasu vargsiuku irasymo i faila laikas: "
                     << durationWriteVargsiukai.count()
                     << " sekundziu" << endl;
                cout << kietiakiai.size() << " irasu keteku irasymo i faila laikas: " << durationWriteKietiakiai.count()
                     << " sekundziu" << endl;

                cout << studentai.size() << " irasu testo laikas "
                     << durationRead.count() + durationCategorize.count() + durationWriteVargsiukai.count() +
                        durationWriteKietiakiai.count() + durationSort.count();
            }
        } catch (const exception &e) {
            cerr << e.what() << endl;
            return 1;
        }

        return 0;
    }





