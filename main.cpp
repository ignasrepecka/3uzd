#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <limits>
#include <fstream>
#include "studentai.h"
#include "failas.h"
#include "calculateStatistics.h"
#include "generateFile.h"
#include "listfailas.h"
#include "listCalculateStatistics.h"
#include "demo.h"
#include "ivesti.h"

using namespace std;

int main() {
    srand(time(0));

    int a;
    cout << "Ka pasirinksite?: 1 - Vidurkis, 2 - Mediana, 3 - Generuoti failus, 4 - Ivesti: ";
    cin >> a;

    vector<Studentas> studentai;
    list<Studentasl> studentail;


    try {
        if (a == 3) {
            int fileNum;
            cout << "Kiek failu norite generuoti?: ";
            cin >> fileNum;

            for (int i = 1; i <= fileNum; ++i) {
                int n;
                cout << "Kiek studentu bus " << i << "-ajame faile?: ";
                cin >> n;
                generateFile(n, i);
            }
        } else if (a==1 || a==2) {
            int fileNum;
            cout << "Kiek failu norite skaityti?: ";
            cin >> fileNum;
            cout << "--------------------------------------------------------------------------";
            cout << endl;
            for (int i = 1; i <= fileNum; ++i) {
                int b;
                cout << "koki konteineri naudoti?: 1 - Vector, 2 - List: ";
                cin >> b;
                int n;
                cout << "Kiek studentu yra " << i << "-ajame faile?: ";
                cin >> n;
                string filename = "C:\\Users\\Administrator\\Desktop\\cc++++\\v1.2\\studentai" + to_string(n) + ".txt";
                if (b==1) {
                    isFailo(studentai, a, filename);
                } else {
                    listIsFailo(studentail, a, filename);
                }

            }
        } else if (a==4){
            ivestiStudentus(a);
        }
    } catch (const exception& e) {
        cerr << "Klaida: " << e.what() << endl;
    }

    return 0;
}
