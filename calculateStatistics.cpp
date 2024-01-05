#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include "calculateStatistics.h"

using namespace std;

void Studentas::calculateStatistics() {
    double suma = 0;
    for(int j : this->getBalai()) {
        suma += j;
    }
    suma += this->getEgz(); // Include the exam grade in the sum

    std::vector<int> balaiCopy = this->getBalai();
    balaiCopy.push_back(this->getEgz()); // Include the exam grade in the grades vector
    sort(balaiCopy.begin(), balaiCopy.end());
    if ((balaiCopy.size()) % 2 == 0)
        this->mediana = (balaiCopy[balaiCopy.size()/2 - 1] + balaiCopy[balaiCopy.size()/2]) / 2.0;
    else
        this->mediana = balaiCopy[balaiCopy.size()/2];

    this->vidurkis = suma/balaiCopy.size();
}


std::ostream& operator<<(std::ostream& os, const Studentas& s) {
    os << s.getVardas() << " " << s.getPavarde() << " " << s.getVidurkis();
    return os;
}
