#include "Stud.h"
#include "Mylib.h"
#include <random>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <list>
#include <vector>

using namespace std;

//FAILO GENERAVIMAS
void generuotiStudentuFaila(int kiekis) {
    ofstream outFile("studentai.txt");
    outFile << "Vardas Pavarde ";
    for (int i = 1; i <= 10; ++i) outFile << "ND" << i << " ";
    outFile << "EgzaminoBalas\n";

    for (int i = 1; i <= kiekis; ++i) {
        outFile << "Vardas" << i << " Pavarde" << i << " ";
        vector<int> nd;
        for (int j = 0; j < 10; ++j) {
            nd.push_back(rand() % 10 + 1);
            outFile << nd.back() << " ";
        }
        double egz = rand() % 10 + 1;
        outFile << egz << "\n";
        Stud student("Vardas" + to_string(i), "Pavarde" + to_string(i), nd, egz);
    }

    outFile.close();
}

// STUDENTŲ RŪŠIAVIMO STRATEGIJOS (VECTOR)
void rusiutiStudentus_Strategy1(const vector<Stud>& studentai) {
    vector<Stud> tinginukai;
    vector<Stud> moksliukai;

    for (const auto& stud : studentai) {
        if (stud.galutinisVid() < 5.0) {
            tinginukai.push_back(stud);
        } else {
            moksliukai.push_back(stud);
        }
    }

    isvestiRezultatus("tinginukai.txt", tinginukai);
    isvestiRezultatus("moksliukai.txt", moksliukai);
}

void rusiutiStudentus_Strategy2(vector<Stud>& studentai) {
    vector<Stud> tinginukai;

    auto it = std::remove_if(studentai.begin(), studentai.end(), [&](Stud& stud) {
        if (stud.galutinisVid() < 5.0) {
            tinginukai.push_back(stud);
            return true;
        }
        return false;
    });

    studentai.erase(it, studentai.end());

    isvestiRezultatus("tinginukai.txt", tinginukai);
    isvestiRezultatus("moksliukai.txt", studentai);
}

void rusiutiStudentus_Strategy3(vector<Stud>& studentai) {
    auto it = std::partition(studentai.begin(), studentai.end(), [](const Stud& stud) {
        return stud.galutinisVid() < 5.0;
    });

    vector<Stud> tinginukai(studentai.begin(), it);
    vector<Stud> moksliukai(it, studentai.end());

    isvestiRezultatus("tinginukai.txt", tinginukai);
    isvestiRezultatus("moksliukai.txt", moksliukai);
}

// STUDENTŲ RŪŠIAVIMO STRATEGIJOS (LIST)
void rusiutiStudentus_Strategy1(const list<Stud>& studentaiList) {
    list<Stud> tinginukai;
    list<Stud> moksliukai;

    for (const auto& stud : studentaiList) {
        if (stud.galutinisVid() < 5.0) {
            tinginukai.push_back(stud);
        } else {
            moksliukai.push_back(stud);
        }
    }

    isvestiRezultatus("tinginukai.txt", tinginukai);
    isvestiRezultatus("moksliukai.txt", moksliukai);
}

void rusiutiStudentus_Strategy2(list<Stud>& studentaiList) {
    list<Stud> tinginukai;

    for (auto it = studentaiList.begin(); it != studentaiList.end(); ) {
        if (it->galutinisVid() < 5.0) {
            tinginukai.push_back(*it);
            it = studentaiList.erase(it);
        } else {
            ++it;
        }
    }

    isvestiRezultatus("tinginukai.txt", tinginukai);
    isvestiRezultatus("moksliukai.txt", studentaiList);
}

void rusiutiStudentus_Strategy3(list<Stud>& studentaiList) {
    list<Stud> tinginukai;
    list<Stud> moksliukai;

    std::partition_copy(studentaiList.begin(), studentaiList.end(),
                        std::back_inserter(tinginukai), std::back_inserter(moksliukai),
                        [](const Stud& stud) { return stud.galutinisVid() < 5.0; });

    isvestiRezultatus("tinginukai.txt", tinginukai);
    isvestiRezultatus("moksliukai.txt", moksliukai);
}

// SKAITYMAS IŠ FAILO
void skaitytiIsFailoSuKlaiduTikrinimu(vector<Stud>& studentai, const string& failo_pav) {
    ifstream inFile(failo_pav);
    if (!inFile) {
        cerr << "Klaida atidarant faila: " << failo_pav << endl;
        return;
    }

    studentai.clear();

    string line;
    getline(inFile, line);
    while (getline(inFile, line)) {
        Stud student;
        istringstream iss(line);
        string vardas, pavarde;
        vector<int> ND;
        double egz;
        iss >> vardas >> pavarde;

        for (int i = 0; i < 10; ++i) {
            int nd;
            iss >> nd;
            ND.push_back(nd);
        }

        iss >> egz;
        student.setVardas(vardas);
        student.setPavarde(pavarde);
        student.setND(ND);
        student.setEgz(egz);

        studentai.push_back(student);
    }

    inFile.close();
}

void skaitytiIsFailoSuKlaiduTikrinimu(list<Stud>& studentaiList, const string& failo_pav) {
    ifstream inFile(failo_pav);
    if (!inFile) {
        cerr << "Klaida atidarant faila: " << failo_pav << endl;
        return;
    }

    studentaiList.clear();

    string line;
    getline(inFile, line);
    while (getline(inFile, line)) {
        Stud student;
        istringstream iss(line);
        string vardas, pavarde;
        vector<int> ND;
        double egz;
        iss >> vardas >> pavarde;

        for (int i = 0; i < 10; ++i) {
            int nd;
            iss >> nd;
            ND.push_back(nd);
        }

        iss >> egz;
        student.setVardas(vardas);
        student.setPavarde(pavarde);
        student.setND(ND);
        student.setEgz(egz);

        studentaiList.push_back(student);
    }

    inFile.close();
}

// REZULTATŲ IŠVEDIMAS
void isvestiRezultatus(const string& failoPav, const vector<Stud>& studentai) {
    ofstream outFile(failoPav);
    for (const auto& stud : studentai) {
        outFile << stud.vardas() << " " << stud.pavarde() << " " << stud.galutinisVid() << "\n";
    }
}

void isvestiRezultatus(const string& failoPav, const list<Stud>& studentaiList) {
    ofstream outFile(failoPav);
    for (const auto& stud : studentaiList) {
        outFile << stud.vardas() << " " << stud.pavarde() << " " << stud.galutinisVid() << "\n";
    }
}

void ivestiNamudarbus(Stud& studentas) {
    string input;
    cout << "Pradekite vesti namu darbu rezultatus (ivedus du kartus Enter, ivestis bus baigta):" << endl;

    while (true) {
        cout << "ND: ";
        getline(cin, input);

        // Jei paspaustas tuščias Enter du kartus, nutraukiame įvestį
        if (input.empty()) {
            cout << "Ivedimas baigtas." << endl;
            break;
        }

        try {
            int nd = stoi(input); // Konvertuojame į skaičių
            if (nd < 1 || nd > 10) {
                cout << "Pazymys turi buti tarp 1 ir 10. Bandykite dar karta." << endl;
            } else {
                studentas.ND().push_back(nd); // Pridedame pažymį, jei jis tinkamas
            }
        } catch (const invalid_argument&) {
            cout << "Neteisingas formatas. Iveskite skaiciu nuo 1 iki 10." << endl;
        }
    }
}


double Stud::galutinisVid() const {
    if (ND_.empty()) return 0.0;
    double suma = accumulate(ND_.begin(), ND_.end(), 0.0);
    double vidurkis = suma / ND_.size();
    return 0.4 * vidurkis + 0.6 * egz_;
}

double Stud::galutinisMediana() const {
    if (ND_.empty()) return 0.0;
    vector<int> temp = ND_;
    sort(temp.begin(), temp.end());
    size_t size = temp.size();
    double mediana;
    if (size % 2 == 0) {
        mediana = (temp[size / 2 - 1] + temp[size / 2]) / 2.0;
    } else {
        mediana = temp[size / 2];
    }
    return 0.4 * mediana + 0.6 * egz_;
}


// REZULTATŲ SPAUSDINIMAS
void spausdintiRezultatus(const vector<Stud>& studentai, char skaiciavimo_budas) {
    cout << setw(20) << "Pavarde"
              << setw(20) << "Vardas"
              << setw(20);

    if (skaiciavimo_budas == 'v' || skaiciavimo_budas == 'V') {
        cout << "Galutinis (Vid.)";
    } else {
        cout << "Galutinis (Med.)";
    }

    cout << endl;
    cout << "---------------------------------------------------------------" << endl;

    for (const Stud& s : studentai) {
        double galutinis;
        if (skaiciavimo_budas == 'v' || skaiciavimo_budas == 'V') {
            galutinis = s.galutinisVid();  // Naudojame vidurkį
        } else {
            galutinis = s.galutinisMediana();  // Naudojame medianą
        }

        cout << setw(20) << s.pavarde()
                  << setw(20) << s.vardas()
                  << setw(20) << fixed << setprecision(2) << galutinis
                  << endl;
    }
}
