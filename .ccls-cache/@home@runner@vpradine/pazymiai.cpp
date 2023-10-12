#include "pazymiai.h"
#include <cstdlib>

std::vector<int> PazymiuGeneracija(int kiekis) {
    vector<int> pazymiai;
    for (int i = 0; i < kiekis; ++i) {
        pazymiai.push_back(rand() % 10 + 1); 
    }
    return pazymiai;
}