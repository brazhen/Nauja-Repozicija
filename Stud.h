#ifndef STUD_H
#define STUD_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Mylib.h"

using namespace std;

// ABSTRAKTI BAZINĖ KLASĖ ŽMOGUS
class Zmogus {
protected:
    string vardas_;
    string pavarde_;

public:
    Zmogus(const string& vardas, const string& pavarde) : vardas_(vardas), pavarde_(pavarde) {}
    virtual ~Zmogus() = 0; // Pure virtual destructor makes this class abstract

    virtual string vardas() const { return vardas_; }
    virtual string pavarde() const { return pavarde_; }
};

inline Zmogus::~Zmogus() {} // Definition of pure virtual destructor

// IŠVESTINĖ KLASĖ STUDENTAS
class Stud : public Zmogus {
private:
    vector<int> ND_;
    double egz_;

public:
    Stud() : Zmogus("", ""), egz_(0.0) {} // Default constructor
    Stud(const string& vardas, const string& pavarde, const vector<int>& ND, double egz)
        : Zmogus(vardas, pavarde), ND_(ND), egz_(egz) {}
    Stud(const Stud& other)
        : Zmogus(other.vardas_, other.pavarde_), ND_(other.ND_), egz_(other.egz_) {}
    ~Stud() {}

    Stud& operator=(const Stud& other) {
        if (this != &other) {
            vardas_ = other.vardas_;
            pavarde_ = other.pavarde_;
            ND_ = other.ND_;
            egz_ = other.egz_;
        }
        return *this;
    }

    void setVardas(const string& vardas) { vardas_ = vardas; }
    void setPavarde(const string& pavarde) { pavarde_ = pavarde; }

    inline vector<int> ND() const { return ND_; }
    inline double egz() const { return egz_; }
    void setND(const vector<int>& ND) { ND_ = ND; }
    void setEgz(double egz) { egz_ = egz; }
    inline vector<int>& ND() { return ND_; }

    double galutinisVid() const;
    double galutinisMediana() const;
};

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
