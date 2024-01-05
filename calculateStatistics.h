#ifndef CALCULATESTATISTICS_H_INCLUDED
#define CALCULATESTATISTICS_H_INCLUDED

#include <vector>
#include <string>
#include <istream>
#include <ostream>
#include <iostream>

class Zmogus {
    protected:
    std::string vardas;
    std::string pavarde;

public:
    // Constructor
    Zmogus() {}

    // Virtual Destructor
    virtual ~Zmogus() {}

    // Pure virtual function
    virtual void calculateStatistics() = 0;

    // Getters
    inline std::string getVardas() const { return vardas; }
    inline std::string getPavarde() const { return pavarde; }
};

class Studentas : public Zmogus {
    private:
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
        : Zmogus(other), balai(other.balai),
          vidurkis(other.vidurkis), mediana(other.mediana), egz(other.egz) {}

    // 3. Copy assignment operator
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            Zmogus::operator=(other);
            balai = other.balai;
            vidurkis = other.vidurkis;
            mediana = other.mediana;
            egz = other.egz;
        }
        return *this;
    }

    // Getters
    std::vector<int> getBalai() const { return balai; }
    double getVidurkis() const { return vidurkis; }
    double getMediana() const { return mediana; }
    int getEgz() const { return egz; }

    // Other member functions
    void calculateStatistics();

    // New method
    std::istream& readStudent(std::istream& is) {
        is >> this->vardas >> this->pavarde;
        for(int i = 0; i < 2; i++) {
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

    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
};

#endif // CALCULATESTATISTICS_H_INCLUDED
