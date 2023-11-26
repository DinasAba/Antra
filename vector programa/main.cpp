#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <chrono>
#include "studentas.h"

using namespace std;

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


            for (int i = 0; i < studentuSkaicius; ++i) {
                Studentas studentas;
                cout << "Iveskite studento varda: ";
                std::string vardas;
                cin >> vardas;
                studentas.setVardas(vardas);

                cout << "Iveskite studento pavarde: ";
                std::string pavarde;
                cin >> pavarde;
                studentas.setPavarde(pavarde);

                studentas.setEgzas(rand() % 10 + 1);

                studentas.setPazymiai(PazymiuGeneracija(rand() % 10 + 1));

                cout << "Objekto adresas: " << &studentas << endl;

                studentas.setGalutinisVidurkis(apskaiciuotiGalutiniBalaVidurkis(studentas.getPazymiai(), studentas.getEgzas()));
                studentas.setGalutinisMediana(skaiciuotiGalutiniBalaMediana(studentas.getPazymiai()));

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
                cout << setw(15) << studentas.getVardas() << setw(15) << studentas.getPavarde() << setw(15) << fixed
                     << setprecision(2);
                if (rezultatoRusis == 'M' || rezultatoRusis == 'm') {
                    cout << studentas.getGalutinisMediana() << endl;
                } else if (rezultatoRusis == 'V' || rezultatoRusis == 'v') {
                    cout << studentas.getGalutinisVidurkis() << endl;
                } else {
                    cout << studentas.getGalutinisMediana() << endl;
                }
            }


        } else if (duomenusaltinis == 'D' || duomenusaltinis == 'd') {
            cout << "Pasirinkite duomenu faila 1000,10000,100000,1000000,10000000:   " << setprecision(10);
            int FailoPasirinkimas;
            cin >> FailoPasirinkimas;

            string filename;
            if (FailoPasirinkimas == 1000) {
                filename = "C:\\Users\\User\\uzduotis\\1000.txt";
            } else if (FailoPasirinkimas == 10000) {
                filename = "C:\\Users\\User\\uzduotis\\10000.txt";
            } else if (FailoPasirinkimas == 100000) {
                filename = "C:\\Users\\User\\uzduotis\\100000.txt";
            } else if (FailoPasirinkimas == 1000000) {
                filename = "C:\\Users\\User\\uzduotis\\1000000.txt";
            } else if (FailoPasirinkimas == 10000000) {
                filename = "C:\\Users\\User\\uzduotis\\10000000.txt";
            } else {
                cerr << "Klaida, pasirinkite tinkama faila" << endl;
            }


            cout << "Pasirinkite strategija 1,2,3: " << setprecision(10);
            int strategija;
            cin >> strategija;

            switch (strategija) {
                case 1: {
                    vector<Studentas> vargsiukai;
                    vector<Studentas> kietiakai;


                    double totalCategorize = 0;
                    double totalWriteVargsiukai = 0;
                    double totalWriteKetiakai = 0;
                    double totalRead = 0;
                    double totalSort = 0;


                    for (int kartojimai = 1; kartojimai <= 5; ++kartojimai) {
                        kietiakai.clear();
                        vargsiukai.clear();

                        auto startRead = std::chrono::high_resolution_clock::now();

                        std::ifstream inputFile(filename);
                        if (!inputFile.is_open()) {
                            throw std::runtime_error("Klaida - failas nerastas.");
                        }
                        std::string line;

                        studentai.clear();

                        getline(inputFile, line);


                        while (getline(inputFile, line)) {
                            istringstream iss(line);
                            Studentas studentas;

                            std::string vardas, pavarde;
                            if (!(iss >> vardas >> pavarde)) {
                                cerr << "Klaida - neteisingas duomenų formatas: " << line << endl;
                                continue;
                            }

                            studentas.setVardas(vardas);
                            studentas.setPavarde(pavarde);

                            studentas.clearPazymiai();

                            int pazymys;
                            while (iss >> pazymys) {
                                studentas.addPazymys(pazymys);
                            }


                            if (studentas.getPazymiai().empty()) {
                                cerr << "Klaida - nėra pažymių duomenų: " << line << endl;
                                continue;
                            }

                            if (!studentas.getPazymiai().empty()) {
                                int egzas = studentas.getPazymiai().back();
                                studentas.getPazymiai().pop_back();
                                studentas.setEgzas(egzas);}


                            const auto& pazymiai = studentas.getPazymiai();

                            studentas.setGalutinisVidurkis(apskaiciuotiGalutiniBalaVidurkis(pazymiai, studentas.getEgzas()));


                            studentai.push_back(std::move(studentas));
                        }

                        inputFile.close();
                        auto endRead = chrono::high_resolution_clock::now();

                        if (studentai.empty()) {
                            throw runtime_error("Klaida - nėra studentų duomenų.");
                        }

                        auto startSort = chrono::high_resolution_clock::now();

                        sort(studentai.begin(), studentai.end(), RusiavimasPavarde);

                        auto endSort = chrono::high_resolution_clock::now();

                        chrono::duration<double> durationRead = endRead - startRead;
                        chrono::duration<double> durationSort = endSort - startSort;

                        totalRead += durationRead.count();
                        totalSort += durationSort.count();

                        auto startCategorize = chrono::high_resolution_clock::now();

                        for (const Studentas &studentas: studentai) {
                            if (studentas.getGalutinisVidurkis() < 5.0) {
                                vargsiukai.push_back(studentas);
                            } else {
                                kietiakai.push_back(studentas);
                            }
                        }
                        ofstream vargsiukaiFile("C:\\Users\\User\\Desktop\\pirma-0.3\\vargsiukai.txt");
                        ofstream kietiakiaiFile("C:\\Users\\User\\Desktop\\pirma-0.3\\kietiakiai.txt");
                        auto startWriteVargsiukai = chrono::high_resolution_clock::now();

                        for (const Studentas &studentas: vargsiukai) {
                            vargsiukaiFile << studentas.getVardas() << " " << studentas.getPavarde() << " "
                                           << studentas.getGalutinisVidurkis()
                                           << endl;
                        }

                        auto endWriteVargsiukai = chrono::high_resolution_clock::now();

                        auto startWriteKietiakiai = chrono::high_resolution_clock::now();

                        for (const Studentas &studentas: kietiakai) {
                            kietiakiaiFile << studentas.getVardas() << " " << studentas.getPavarde() << " "
                                           << studentas.getGalutinisVidurkis()
                                           << endl;
                        }

                        auto endWriteKietiakiai = chrono::high_resolution_clock::now();

                        auto endCategorize = chrono::high_resolution_clock::now();


                        chrono::duration<double> durationCategorize = endCategorize - startCategorize;
                        chrono::duration<double> durationWriteVargsiukai = endWriteVargsiukai - startWriteVargsiukai;
                        chrono::duration<double> durationWriteKietiakiai = endWriteKietiakiai - startWriteKietiakiai;


                        totalCategorize += durationCategorize.count();
                        totalWriteVargsiukai += durationWriteVargsiukai.count();
                        totalWriteKetiakai += durationWriteKietiakiai.count();

                        vargsiukaiFile.close();
                        kietiakiaiFile.close();
                    }


                    double avgCategorize = totalCategorize / 5;
                    double avgWriteVargsiukai = totalWriteVargsiukai / 5;
                    double avgWriteKietiakai = totalWriteKetiakai / 5;
                    double avgRead = totalRead / 5;
                    double avgSort = totalSort / 5;

                    cout << fixed << setprecision(6);
                    cout << "Failo is " << studentai.size() << " irasu nuskaitymo laikas: " << avgRead << " sekundziu"
                         << endl;
                    cout << "Irasu rusiavimo laikas: " << avgSort << " sekundziu" << endl;
                    cout << studentai.size() << " irasu dalijimo i dvigrupes laikas: " << avgCategorize
                         << " sekundziu" << endl;
                    cout << vargsiukai.size() << " irasu vargsiuku irasymo i faila laikas: "
                         << avgWriteVargsiukai
                         << " sekundziu" << endl;
                    cout << kietiakai.size() << " irasu keteku irasymo i faila laikas: "
                         << avgWriteKietiakai
                         << " sekundziu" << endl;

                    cout << studentai.size() << " irasu testo laikas "
                         << avgRead + avgSort + avgCategorize +
                            avgWriteVargsiukai + avgWriteKietiakai;
                    break;
                }


              /*  case 2: {
                    vector<Studentas> vargsiukai;
                    double totalCategorize = 0;
                    double totalWriteVargsiukai = 0;
                    double totalRead = 0;
                    double totalSort = 0;


                    for (int kartojimai = 1; kartojimai <= 5; ++kartojimai) {

                        auto startRead = chrono::high_resolution_clock::now();
                        inputFile.close();
                        inputFile.clear();

                        while (getline(inputFile, line)) {
                            istringstream iss(line);
                            Studentas studentas;

                            std::string pavarde, vardas;
                            if (!(iss >> pavarde >> vardas)) {
                                cerr << "Klaida - neteisingas duomenų formatas: " << line << endl;
                                continue;
                            }
                            studentas.setPavarde(pavarde);
                            studentas.setVardas(vardas);

                            studentas.getPazymiai().clear();
                            int pazymys;
                            while (iss >> pazymys) {
                                studentas.getPazymiai().push_back(pazymys);
                            }
                            if (studentas.getPazymiai().empty()) {
                                cerr << "Klaida - nėra pažymių duomenų: " << line << endl;
                                continue;
                            }

                            studentas.setEgzas(studentas.getPazymiai().back());
                            studentas.getPazymiai().pop_back();

                            studentas.setGalutinisVidurkis(apskaiciuotiGalutiniBalaVidurkis(studentas.getPazymiai(), studentas.getEgzas()));
                            studentas.setGalutinisMediana(skaiciuotiGalutiniBalaMediana(studentas.getPazymiai()));

                            studentai.push_back(studentas);
                        }


                        auto endRead = chrono::high_resolution_clock::now();

                        auto startSort = chrono::high_resolution_clock::now();

                        std::sort(studentai.begin(), studentai.end(), RusiavimasPavarde);

                        auto endSort = chrono::high_resolution_clock::now();

                        chrono::duration<double> durationRead = endRead - startRead;
                        chrono::duration<double> durationSort = endSort - startSort;

                        totalRead += durationRead.count();
                        totalSort += durationSort.count();

                        auto startCategorize = chrono::high_resolution_clock::now();

                        auto it = studentai.begin();
                        while (it != studentai.end()) {
                            if (it->getGalutinisVidurkis() < 5.0) {
                                vargsiukai.push_back(*it);
                                it = studentai.erase(it);
                            } else {
                                ++it;
                            }
                        }

                        ofstream vargsiukaiFile("C:\\Users\\User\\Desktop\\pirma-0.3\\vargsiukai.txt");

                        auto startWriteVargsiukai = chrono::high_resolution_clock::now();

                        for (const Studentas &studentas: vargsiukai) {
                            vargsiukaiFile << studentas.getVardas() << " " << studentas.getPavarde() << " "
                                           << studentas.getGalutinisVidurkis()
                                           << endl;
                        }

                        auto endWriteVargsiukai = chrono::high_resolution_clock::now();

                        auto endCategorize = chrono::high_resolution_clock::now();

                        chrono::duration<double> durationCategorize = endCategorize - startCategorize;
                        chrono::duration<double> durationWriteVargsiukai = endWriteVargsiukai - startWriteVargsiukai;

                        totalCategorize += durationCategorize.count();
                        totalWriteVargsiukai += durationWriteVargsiukai.count();
                        vargsiukaiFile.close();
                        studentai.clear();
                    }

                    inputFile.close();

                    double avgCategorize = totalCategorize / 5;
                    double avgWriteVargsiukai = totalWriteVargsiukai / 5;
                    double avgRead = totalRead / 5;
                    double avgSort = totalSort / 5;

                    cout << fixed << setprecision(10) << "Failo is " << pradinisStudentuSkaicius
                         << " irasu nuskaitymo laikas: " << avgRead << flush
                         << " sekundziu" << endl;
                    cout << "Irasu rusiavimo laikas: " << avgSort << " sekundziu" << endl;
                    cout << pradinisStudentuSkaicius << " irasu dalijimo i dvigrupes laikas: " << avgCategorize
                         << " sekundziu" << endl;
                    cout << vargsiukai.size() << " irasu vargsiuku irasymo i faila laikas: "
                         << avgWriteVargsiukai
                         << " sekundziu" << endl;
                    cout << pradinisStudentuSkaicius << " irasu testo laikas "
                         << avgRead + avgWriteVargsiukai + avgCategorize +
                            +avgSort << endl;

                    break;
                }

                case 3: {
                    vector<Studentas> vargsiukai;
                    vector<Studentas> kietiakai;
                    double totalCategorize = 0;
                    double totalWriteVargsiukai = 0;
                    double totalWriteKetiakai = 0;
                    double totalRead = 0;
                    double totalSort = 0;

                    for (int kartojimai = 1; kartojimai <= 5; ++kartojimai) {
                        vargsiukai.clear();
                        kietiakai.clear();
                        auto startRead = chrono::high_resolution_clock::now();
                        while (getline(inputFile, line)) {
                            istringstream iss(line);
                            Studentas studentas;

                            std::string pavarde, vardas;
                            if (!(iss >> pavarde >> vardas)) {
                                cerr << "Klaida - neteisingas duomenų formatas: " << line << endl;
                                continue;
                            }
                            studentas.setPavarde(pavarde);
                            studentas.setVardas(vardas);

                            studentas.getPazymiai().clear();
                            int pazymys;
                            while (iss >> pazymys) {
                                studentas.getPazymiai().push_back(pazymys);
                            }
                            if (studentas.getPazymiai().empty()) {
                                cerr << "Klaida - nėra pažymių duomenų: " << line << endl;
                                continue;
                            }

                            studentas.setEgzas(studentas.getPazymiai().back());
                            studentas.getPazymiai().pop_back();

                            studentas.setGalutinisVidurkis(apskaiciuotiGalutiniBalaVidurkis(studentas.getPazymiai(), studentas.getEgzas()));
                            studentas.setGalutinisMediana(skaiciuotiGalutiniBalaMediana(studentas.getPazymiai()));

                            studentai.push_back(studentas);
                        }

                        inputFile.close();
                        auto endRead = chrono::high_resolution_clock::now();

                        auto startSort = chrono::high_resolution_clock::now();

                        sort(studentai.begin(), studentai.end(), RusiavimasPavarde);

                        auto endSort = chrono::high_resolution_clock::now();

                        chrono::duration<double> durationRead = endRead - startRead;
                        chrono::duration<double> durationSort = endSort - startSort;

                        totalRead += durationRead.count();
                        totalSort += durationSort.count();
                        auto startCategorize = chrono::high_resolution_clock::now();

                        auto galutinis_balas = [](const Studentas &s) { return s.getGalutinisVidurkis() < 5.0; };

                        auto it = partition(studentai.begin(), studentai.end(), galutinis_balas);

                        auto endCategorize = chrono::high_resolution_clock::now();


                        partition_copy(studentai.begin(), studentai.end(), back_inserter(vargsiukai),
                                       back_inserter(kietiakai), galutinis_balas);


                        ofstream vargsiukaiFile("C:\\Users\\User\\Desktop\\pirma-0.3\\vargsiukai.txt");
                        ofstream kietiakiaiFile("C:\\Users\\User\\Desktop\\pirma-0.3\\kietiakiai.txt");
                        auto startWriteVargsiukai = chrono::high_resolution_clock::now();

                        for (const Studentas &studentas: vargsiukai) {
                            vargsiukaiFile << studentas.getVardas() << " " << studentas.getPavarde() << " "
                                           << studentas.getGalutinisVidurkis()
                                           << endl;
                        }

                        auto endWriteVargsiukai = chrono::high_resolution_clock::now();

                        auto startWriteKietiakiai = chrono::high_resolution_clock::now();

                        for (const Studentas &studentas: kietiakai) {
                            kietiakiaiFile << studentas.getVardas() << " " << studentas.getPavarde() << " "
                                           << studentas.getGalutinisVidurkis()
                                           << endl;
                        }

                        auto endWriteKietiakiai = chrono::high_resolution_clock::now();



                        chrono::duration<double> durationCategorize = endCategorize - startCategorize;
                        chrono::duration<double> durationWriteVargsiukai = endWriteVargsiukai - startWriteVargsiukai;
                        chrono::duration<double> durationWriteKietiakiai = endWriteKietiakiai - startWriteKietiakiai;


                        totalCategorize += durationCategorize.count();
                        totalWriteVargsiukai += durationWriteVargsiukai.count();
                        totalWriteKetiakai += durationWriteKietiakiai.count();

                        vargsiukaiFile.close();
                        kietiakiaiFile.close();
                    }


                    double avgCategorize = totalCategorize / 5;
                    double avgWriteVargsiukai = totalWriteVargsiukai / 5;
                    double avgWriteKietiakai = totalWriteKetiakai / 5;
                    double avgRead = totalRead / 5;
                    double avgSort = totalSort / 5;

                    cout << fixed << setprecision(6);
                    cout << "Failo is " << studentai.size() << " irasu nuskaitymo laikas: " << avgRead << " sekundziu"
                         << endl;
                    cout << "Irasu rusiavimo laikas: " << avgSort << " sekundziu" << endl;
                    cout << studentai.size() << " irasu dalijimo i dvigrupes laikas: " << avgCategorize
                         << " sekundziu" << endl;
                    cout << vargsiukai.size() << " irasu vargsiuku irasymo i faila laikas: "
                         << avgWriteVargsiukai
                         << " sekundziu" << endl;
                    cout << kietiakai.size() << " irasu keteku irasymo i faila laikas: "
                         << avgWriteKietiakai
                         << " sekundziu" << endl;

                    cout << studentai.size() << " irasu testo laikas "
                         << avgRead + avgSort + avgCategorize +
                            avgWriteVargsiukai + avgWriteKietiakai;
                    break;
                } */
            }
        }
    }

    catch (const exception &e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}







