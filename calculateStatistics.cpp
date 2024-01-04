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

    std::vector<int> balaiCopy = this->getBalai();
    sort(balaiCopy.begin(), balaiCopy.end());
    if ((balaiCopy.size()) % 2 == 0)
        this->mediana = (balaiCopy[balaiCopy.size()/2 - 1] + balaiCopy[balaiCopy.size()/2]) / 2.0;
    else
        this->mediana = balaiCopy[balaiCopy.size()/2];

    this->vidurkis = suma/balaiCopy.size();
}
