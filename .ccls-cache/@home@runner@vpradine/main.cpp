#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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

double apskaiciuotiGalutiniBala(const vector <int>& pazymiai, int egzas) {
  double vidurkis = 0.0;
  for (int pazymis : pazymiai) {
    vidurkis += pazymis;
  }
  if (!pazymiai.empty()) {
    vidurkis /= pazymiai.size();
  }
  double galutinis = 0.4 * vidurkis + 0.6 * egzas;
  return galutinis;

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
    studentas.galutinis = apskaiciuotiGalutiniBala(studentas.pazymiai, studentas.egzas);
    studentai.push_back(studentas);
  }

  cout << "Pavarde\tVardas\tGalutinis(Vid)" << endl;
  cout << "---------------------------------------------" << endl;
  for (const Studentas& studentas : studentai) {
    cout << studentas.pavarde << "\t" << studentas.vardas << "\t" << fixed << setprecision(2) << studentas.galutinis << endl;         
  }
  return 0;
}