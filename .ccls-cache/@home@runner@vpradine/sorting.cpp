

#include <string>
#include <vector>
#include "sorting.h" 
#include "studentas.h"

bool RusiavimasPavarde(const Studentas& a, const Studentas& b) {
    if (a.pavarde.length() != b.pavarde.length()) {
        return a.pavarde.length() < b.pavarde.length();
    }
    return a.pavarde < b.pavarde;
}