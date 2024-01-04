#include <iostream>
#include <list>
#include <string>
#include <limits>
#include <iomanip>
#include <stdexcept>
#include "listCalculateStatistics.h"

using namespace std;

void Studentasl::listCalculateStatistics() {
    double suma = 0;
    for(int j : this->getBalai()) {
        suma += j;
    }

    std::list<int> balaiCopy = this->getBalai();
    balaiCopy.sort();
    auto it = balaiCopy.begin();
    std::advance(it, std::distance(balaiCopy.begin(), balaiCopy.end())/2);
    if ((balaiCopy.size()) % 2 == 0) {
        int val1 = *it;
        --it;
        int val2 = *it;
        this->mediana = (val1 + val2) / 2.0;
    } else {
        this->mediana = *it;
    }

    this->vidurkis = suma/balaiCopy.size();
}
