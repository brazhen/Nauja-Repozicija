#include "Mylib.h"
#include "Stud.h"
#include <random>

void generuotiStudentuFaila(int kiekis) {
    ofstream outFile("studentai.txt");
    outFile << "Vardas Pavarde ";
    for (int i = 1; i <= 10; ++i) outFile << "ND" << i << " ";
    outFile << "EgzaminoBalas\n";

    for (int i = 1; i <= kiekis; ++i) {
        outFile << "Vardas" << i << " Pavarde" << i << " ";
        for (int j = 0; j < 10; ++j) outFile << rand() % 10 + 1 << " ";
        outFile << rand() % 10 + 1 << "\n";
    }

    outFile.close();
}

void rusiutiStudentus(const vector<Stud>& studentai) {
    ofstream tinginukai("tinginukai.txt");
    ofstream moksliukai("moksliukai.txt");

    for (const Stud& s : studentai) {
        double galutinis = galutinisVidurkis(s);  // Calculate final grade based on average
        if (galutinis < 5.0) tinginukai << s.vardas << " " << s.pavarde << " " << galutinis << endl;
        else moksliukai << s.vardas << " " << s.pavarde << " " << galutinis << endl;
    }

    tinginukai.close();
    moksliukai.close();
}

void skaitytiIsFailoSuKlaiduTikrinimu(vector<Stud>& studentai, const string& failo_pav) {
    ifstream inFile(failo_pav);
    if (!inFile) {
        cerr << "Klaida atidarant faila: " << failo_pav << endl;
        return;
    }

    studentai.clear();  // Clear the existing vector

    string line;
    getline(inFile, line); // Skip header line
    while (getline(inFile, line)) {
        Stud student;
        istringstream iss(line);
        iss >> student.vardas >> student.pavarde;

        // Read ND
        for (int i = 0; i < 10; ++i) {
            int nd;
            iss >> nd;
            student.ND.push_back(nd);
        }

        // Read exam score
        iss >> student.egz;

        // Add the student to the vector
        studentai.push_back(student);
    }

    inFile.close();
}

void ivestiNamudarbus(Stud &studentas) {
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
            double nd = stod(input); // Konvertuojame į skaičių
            if (nd < 1 || nd > 10) {
                cout << "Pazymys turi buti tarp 1 ir 10. Bandykite dar karta." << endl;
            } else {
                studentas.ND.push_back(nd); // Pridedame pažymį, jei jis tinkamas
            }
        } catch (const invalid_argument&) {
            cout << "Neteisingas formatas. Iveskite skaiciu nuo 1 iki 10." << endl;
        }
    }
}

double galutinisVidurkis(const Stud& studentas) {
    double suma = 0.0;
    for (int nd : studentas.ND) suma += nd;
    return suma / studentas.ND.size() * 0.4 + studentas.egz * 0.6; // Weighted average
}
double galutinisMediana(const Stud& studentas) {
    double med = median(studentas.ND);
    return med * 0.4 + studentas.egz * 0.6;
}

// Funkcija spausdinti studentų rezultatus
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
            galutinis = galutinisVidurkis(s);  // Naudojame vidurkį
        } else {
            galutinis = galutinisMediana(s);  // Naudojame medianą
        }

        cout << setw(20) << s.pavarde
                  << setw(20) << s.vardas
                  << setw(20) << fixed << setprecision(2) << galutinis
                  << endl;
    }
}

double median(const vector<int>& nd) {
    vector<int> copy = nd; // Copy to sort
    sort(copy.begin(), copy.end());
    size_t size = copy.size();
    if (size % 2 == 0)
        return (copy[size / 2 - 1] + copy[size / 2]) / 2.0;
    else
        return copy[size / 2];
}

