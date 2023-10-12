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
    srand(time(0));

    for (int n = 1000; n <= 10000000; n *= 10) {
        string filename = "C:\\Users\\User\\Perepisyvaju\\" + to_string(n) + ".txt";

        auto start = chrono::high_resolution_clock::now();

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


        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
        cout << "Failo " << filename << " kūrimo trukmė: " << duration.count() << " milisekundės" << endl;
    }

    return 0;
}




