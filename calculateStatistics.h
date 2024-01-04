#ifndef CALCULATESTATISTICS_H_INCLUDED
#define CALCULATESTATISTICS_H_INCLUDED

#include <vector>
#include <string>
#include <istream>

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

    ~Studentas() {}

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
};

#endif // CALCULATESTATISTICS_H_INCLUDED
