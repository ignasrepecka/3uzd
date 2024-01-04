#ifndef LISTCALCULATESTATISTICS_H_INCLUDED
#define LISTCALCULATESTATISTICS_H_INCLUDED

#include <list>
#include <string>
#include <istream>

class Studentasl {
    private:
    std::string vardas;
    std::string pavarde;
    std::list<int> balai;
    double vidurkis;
    double mediana;
    int egz;

public:
    // Constructor
    Studentasl() : vidurkis(0), mediana(0), egz(0) {}

    ~Studentasl() {}

    // Getters
    inline std::string getVardas() const { return vardas; }
    inline std::string getPavarde() const { return pavarde; }
    std::list<int> getBalai() const { return balai; }
    double getVidurkis() const { return vidurkis; }
    double getMediana() const { return mediana; }
    int getEgz() const { return egz; }

    // Other member functions
    void listCalculateStatistics();

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

#endif // LISTCALCULATESTATISTICS_H_INCLUDED
