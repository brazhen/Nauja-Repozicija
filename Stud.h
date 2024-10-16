#ifndef STUD_H
#define STUD_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Stud {
    string vardas;
    string pavarde;
    vector<int> ND; // Namų darbų rezultatai
    int egz; // Egzamino rezultatas
};

void generuotiStudentuFaila(int kiekis);
void rusiutiStudentus(const vector<Stud>& studentai);
void skaitytiIsFailoSuKlaiduTikrinimu(vector<Stud>& studentai, const string& failo_pav);
void ivestiNamudarbus(Stud& studentas);
double galutinisVidurkis(const Stud& studentas);
double galutinisMediana(const Stud& studentas);
void spausdintiRezultatus(const vector<Stud>& studentai, char skaiciavimo_budas);
double median(const vector<int>& nd);

#endif
