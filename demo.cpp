#include "CalculateStatistics.h"
#include <iostream>
#include <vector>

void demo() {
    Studentas s1;
    std::cout << "Iveskite 1studento varda pavarde 3 balus ir egzamina:" << std::endl;
    std::cin >> s1;

    std::cout << "1studento parametrai" << s1 << std::endl;

    Studentas s2 = s1;
    std::cout << "2studento parametrai (kopijuoti nuo s1): " << s2 << std::endl;

    Studentas s3;
    s3 = s1;
    std::cout << "3studento parametrai (priskirti nuo s1): " << s3 << std::endl;
}
