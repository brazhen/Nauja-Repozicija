#ifndef STUD_H
#define STUD_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Mylib.h"

using namespace std;

// STUDENTO KLASĖ
class Stud {
private:
    string vardas_;
    string pavarde_;
    vector<int> ND_;
    double egz_;

public:
    // Constructors
    Stud() : egz_(0) {}
    Stud(const string& vardas, const string& pavarde, const vector<int>& ND, double egz)
        : vardas_(vardas), pavarde_(pavarde), ND_(ND), egz_(egz) {}
    // Copy constructor
    Stud(const Stud& other)
        : vardas_(other.vardas_), pavarde_(other.pavarde_), ND_(other.ND_), egz_(other.egz_) {}
    // Destructor
    ~Stud() {}

    // Copy assignment operator
    Stud& operator=(const Stud& other) {
        if (this != &other) {
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
            ND_ = other.ND_;
            egz_ = other.egz_;
        }
        return *this;
    }

    // Accessors
    inline string vardas() const { return vardas_; }
    inline string pavarde() const { return pavarde_; }
    inline vector<int> ND() const { return ND_; }
    inline double egz() const { return egz_; }

    // Mutators
    void setVardas(const string& vardas) { vardas_ = vardas; }
    void setPavarde(const string& pavarde) { pavarde_ = pavarde; }
    void setND(const vector<int>& ND) { ND_ = ND; }
    void setEgz(double egz) { egz_ = egz; }
    inline vector<int>& ND() { return ND_; }

    // Calculation methods
    double galutinisVid() const;
    double galutinisMediana() const;

    // Overloaded I/O operators
    friend ostream& operator<<(ostream& os, const Stud& s) {
        os << s.vardas_ << " " << s.pavarde_ << " " << s.galutinisVid();
        return os;
    }

    friend istream& operator>>(istream& is, Stud& s) {
        is >> s.vardas_ >> s.pavarde_;
        int nd;
        s.ND_.clear();
        for (int i = 0; i < 10; i++) {
            is >> nd;
            s.ND_.push_back(nd);
        }
        is >> s.egz_;
        return is;
    }
};

// Function declarations remain the same but need to be adapted to work with the class
void generuotiStudentuFaila(int kiekis);

void rusiutiStudentus_Strategy1(const vector<Stud>& studentai);
void rusiutiStudentus_Strategy2(vector<Stud>& studentai);
void rusiutiStudentus_Strategy3(vector<Stud>& studentai);

void rusiutiStudentus_Strategy1(const list<Stud>& studentaiList);
void rusiutiStudentus_Strategy2(list<Stud>& studentaiList);
void rusiutiStudentus_Strategy3(list<Stud>& studentaiList);

void skaitytiIsFailoSuKlaiduTikrinimu(vector<Stud>& studentai, const string& failo_pav);
void skaitytiIsFailoSuKlaiduTikrinimu(list<Stud>& studentaiList, const string& failo_pav);

void isvestiRezultatus(const std::string& failoPav, const std::vector<Stud>& studentai);
void isvestiRezultatus(const std::string& failoPav, const std::list<Stud>& studentaiList);

void ivestiNamudarbus(Stud& studentas);

void spausdintiRezultatus(const vector<Stud>& studentai, char skaiciavimo_budas);
void spausdintiRezultatus(const list<Stud>& studentai, char skaiciavimo_budas);

#endif
