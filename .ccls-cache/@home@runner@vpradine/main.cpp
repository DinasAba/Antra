#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

struct Studentas {
  string vardas;
  string pavarde; 
  vector<int> pazymiai;
  int egzas;
  double galutinis;
};

vector<int> PazymiuGeneracija(int kiekis) {
  vector<int> pazymiai;
  for (int i=0; i < kiekis; ++i) {
    pazymiai.push_back(rand() % 10 + 1);
  }
  return pazymiai;
}

double apskaiciuotiGalutiniBalaVidurkis(const vector <int>& pazymiai, int egzas) {
  double vidurkis = 0.0;
  for (int pazymis : pazymiai) {
    vidurkis += pazymis;
  }
  if (!pazymiai.empty()) {
    vidurkis /= pazymiai.size();
  }
  return vidurkis;
}

double skaiciuotiGalutiniBalaMediana(const vector <int>& pazymiai) {
  vector<int> pazymiukopija = pazymiai;
  sort(pazymiukopija.begin(), pazymiukopija.end());
  int dydis = pazymiukopija.size();
  if (dydis % 2 == 0) {
    int viduris1 = pazymiukopija[dydis / 2 -1];
    int viduris2 = pazymiukopija[dydis / 2];
    return (viduris1 + viduris2 / 2);
  }
  else {
    return pazymiukopija[dydis / 2];
  }
}

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

      for(int i = 0; i < studentuSkaicius; ++i) {
      Studentas studentas;
      cout << "Iveskite studento varda: ";
      cin >> studentas.vardas;
      cout << "Iveskite studento pavarde: ";
      cin >> studentas.pavarde;
      studentas.egzas = rand() % 10 + 1;
      studentas.pazymiai = PazymiuGeneracija(rand() %10 + 1);
      cout << "Pasirinkite skaiciavimo metoda (Vidurkis - V, Mediana - M): ";
      char skaiciavimoMetodas;
      cin >> skaiciavimoMetodas;
      if (skaiciavimoMetodas == 'V' || skaiciavimoMetodas == 'v') {
        studentas.galutinis = 0.4 * apskaiciuotiGalutiniBalaVidurkis(studentas.pazymiai, studentas.egzas) + 0.6 * studentas.egzas;
      } 
      else if (skaiciavimoMetodas == 'M' || skaiciavimoMetodas == 'm') {
        studentas.galutinis = 0.4 * skaiciuotiGalutiniBalaMediana(studentas.pazymiai) + 0.6 * studentas.egzas;
      } 
      else {
        cout << "Neteisingai parinktas skaiciavimo metodas. Taikomas vidurkis skaiciavimas" << endl;
        studentas.galutinis = 0.4 * apskaiciuotiGalutiniBalaVidurkis(studentas.pazymiai, studentas.egzas) + 0.6 * studentas.egzas;
      }
      studentai.push_back(studentas);
      }
    }
      
    else if (duomenusaltinis == 'D' || duomenusaltinis == 'd') {
      ifstream inputFile("kursiokai.txt");
      if (!inputFile.is_open()) {
      cerr << "Klaid - neatidaromas failas" << endl;
      return 1;
      }
  
      string line;
      
      while (getline(inputFile, line)) {
        istringstream iss(line);
        Studentas studentas;
        iss >> studentas.pavarde >> studentas.vardas;
        studentas.pazymiai.clear();
        int pazymys;
        while (iss >> pazymys) {
            studentas.pazymiai.push_back(pazymys);
        }
        studentas.egzas = studentas.pazymiai.back();
        studentas.pazymiai.pop_back();
        studentai.push_back(studentas);
      }
    
      inputFile.close();
      
    }
  

  cout << "Pavarde\tVardas\tGalutinis(Vid)\tGalutinis(Med)" << endl;
  cout << "---------------------------------------------" << endl;
  for (const Studentas& studentas : studentai) {
    cout << studentas.pavarde << "\t" << studentas.vardas << "\t" << fixed << setprecision(2) << studentas.galutinis << endl;         
  }
  return 0;
}