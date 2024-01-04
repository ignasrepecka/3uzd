#ifndef CALCULATESTATISTICS_H_INCLUDED
#define CALCULATESTATISTICS_H_INCLUDED

#include <vector>
#include <string>
#include <istream>
#include <ostream>
#include <iostream>
class Studentas {
    private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> balai;
    double vidurkis;
    double mediana;
    int egz;

public:
    // Constructor
    Studentas() : vidurkis(0), mediana(0), egz(0) {}

    // Rule of Three
    // 1. Destructor
    ~Studentas() {
        std::cout << "Destructor called for " << vardas << std::endl;
    }

    // 2. Copy constructor
    Studentas(const Studentas& other)
        : vardas(other.vardas), pavarde(other.pavarde), balai(other.balai),
          vidurkis(other.vidurkis), mediana(other.mediana), egz(other.egz) {}

    // 3. Copy assignment operator
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            vardas = other.vardas;
            pavarde = other.pavarde;
            balai = other.balai;
            vidurkis = other.vidurkis;
            mediana = other.mediana;
            egz = other.egz;
        }
        return *this;
    }

    // Getters
    inline std::string getVardas() const { return vardas; }
    inline std::string getPavarde() const { return pavarde; }
    std::vector<int> getBalai() const { return balai; }
    double getVidurkis() const { return vidurkis; }
    double getMediana() const { return mediana; }
    int getEgz() const { return egz; }

    // Other member functions
    void calculateStatistics();

    // New method
    std::istream& readStudent(std::istream& is) {
        is >> this->vardas >> this->pavarde;
        for(int i = 0; i < 3; i++) {
            int j;
            is >> j;
            this->balai.push_back(j);
        }
        is >> this->egz;
        return is;
    }

    // Input/output operators
    friend std::istream& operator>>(std::istream& is, Studentas& s) {
        return s.readStudent(is);
    }

    friend std::ostream& operator<<(std::ostream& os, const Studentas& s) {
        os << s.getVardas() << " " << s.getPavarde() << " Grades: ";
        for (int grade : s.getBalai()) {
            os << grade << " ";
        }
        os << "Exam: " << s.getEgz();
        return os;
    }
};

#endif // CALCULATESTATISTICS_H_INCLUDED
