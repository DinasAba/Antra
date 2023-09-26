#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Studentas {
  string vardas;
  string pavarde; 
  vector<int> pazymiai;
  int egzas;
  double galutinis;
};

vector<int> nuskaitytiPazymius() {
  vector<int> pazymiai;
  int pazymys; 

  cout << "Įveskite namų darbų rezultatus (pabaiga zymima -1):";
  while(cin >> pazymys && pazymys != -1) {
    pazymiai.push_back(pazymys);
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
  int studentuSkaicius;
  cout << "Iveskite studentu skaiciu:";
  cin >> studentuSkaicius;

  vector<Studentas> studentai;

  for(int i = 0; i < studentuSkaicius; ++i) {
    Studentas studentas;
    cout << "Iveskite studento varda: ";
    cin >> studentas.vardas;
    cout << "Iveskite studento pavarde: ";
    cin >> studentas.pavarde;
    cout << "Iveskite egzamino rezultata: ";
    cin >> studentas.egzas;
    studentas.pazymiai = nuskaitytiPazymius();
    cout << "Pasirinkite skaiciavimo metoda (Vidurkis - V, Mediana - M): ";
    char skaiciavimoMetodas;
    cin >> skaiciavimoMetodas;
    if (skaiciavimoMetodas == 'V' || skaiciavimoMetodas == 'v') {
      studentas.galutinis = 0.4 * apskaiciuotiGalutiniBalaVidurkis(studentas.pazymiai, studentas.egzas) + 0.6 * studentas.egzas;
    } else if (skaiciavimoMetodas == 'M' || skaiciavimoMetodas == 'v') {
      studentas.galutinis = 0.4 * skaiciuotiGalutiniBalaMediana(studentas.pazymiai) + 0.6 * studentas.egzas;
    } else {
      cout << "Neteisingai parinktas skaiciavimo metodas. Taikomas vidurkis skaiciavimas" << endl;
      studentas.galutinis = 0.4 * apskaiciuotiGalutiniBalaVidurkis(studentas.pazymiai, studentas.egzas) + 0.6 * studentas.egzas;
    }
    studentai.push_back(studentas);
  }

  cout << "Pavarde\tVardas\tGalutinis(Vid)\tGalutinis(Med)" << endl;
  cout << "---------------------------------------------" << endl;
  for (const Studentas& studentas : studentai) {
    cout << studentas.pavarde << "\t" << studentas.vardas << "\t" << fixed << setprecision(2) << studentas.galutinis << endl;         
  }
  return 0;
}