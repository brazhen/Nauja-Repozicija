#include "Mylib.h"
#include "Stud.h"
#include <chrono>

using namespace std;
using StudentList = list<Stud>;
using StudentVector = vector<Stud>;

int main() {
    StudentList studentaiList;
    StudentVector studentaiVector;
    srand(static_cast<unsigned int>(time(0)));

    char testi;
    do {
        StudentVector studentai;
        char pasirinkimas;

        // IVEDIMO BUDO PASIRINKIMAS:
        do {
            cout << "Ar norite ivest studentu duomenis rankiniu budu, nuskaityt is failo ar sugeneruoti faila? (r/f/g): ";
            cin >> pasirinkimas;
            if (pasirinkimas != 'r' && pasirinkimas != 'R' && pasirinkimas != 'f' && pasirinkimas != 'F' && pasirinkimas != 'g' && pasirinkimas != 'G') {
                cout << "Neteisingas pasirinkimas. Prasom pasirinkti 'r', 'f' arba 'g'." << endl;
            }
        } while (pasirinkimas != 'r' && pasirinkimas != 'R' && pasirinkimas != 'f' && pasirinkimas != 'F' && pasirinkimas != 'g' && pasirinkimas != 'G');

        // JEI PASIRENKAMAS FAILO GENERAVIMAS:
        if (pasirinkimas == 'g' or pasirinkimas == 'G') {
            char konteinerio_pasirinkimas;
            do {
                // KONTEINERIO PASIRINKIMAS
                cout << "Kuri konteineri norite naudoti? (v - vector, l - list): ";
                cin >> konteinerio_pasirinkimas;
                if (konteinerio_pasirinkimas != 'v' && konteinerio_pasirinkimas != 'V' && konteinerio_pasirinkimas != 'l' && konteinerio_pasirinkimas != 'L') {
                    cout << "Neteisingas pasirinkimas. Prašome pasirinkti 'v' arba 'l'." << endl;
                }
            } while (konteinerio_pasirinkimas != 'v' && konteinerio_pasirinkimas != 'V' && konteinerio_pasirinkimas != 'l' && konteinerio_pasirinkimas != 'L');

            // GENERUOJAMO FAILO STUDENTU KIEKIO PASIRINKIMAS
            int studentu_skaicius;
            cout << "Pasirinkite studentu skaiciu: 1000, 10000, 100000, 1000000, 10000000: ";
            cin >> studentu_skaicius;

            // FAILO GENERAVIMAS IR JO SPARTOS ANALIZE
            auto start = chrono::high_resolution_clock::now();
            generuotiStudentuFaila(studentu_skaicius);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> diff = end - start;
            cout << "Failo generavimas uztruko: " << diff.count() << " s" << endl;
            string failo_pav = "studentai.txt";

            // FAILO NUSKAITYMAS
            start = chrono::high_resolution_clock::now();
            if (konteinerio_pasirinkimas == 'v' || konteinerio_pasirinkimas == 'V') {
                skaitytiIsFailoSuKlaiduTikrinimu(studentai, failo_pav);
            } else {
                skaitytiIsFailoSuKlaiduTikrinimu(studentaiList, failo_pav);
            }
            end = chrono::high_resolution_clock::now();
            cout << "Failo nuskaitymas uztruko: " << chrono::duration<double>(end - start).count() << " s" << endl;

            // RUSIAVIMAS
            char strategija;
            cout << "Pasirinkite rusiavimo strategija (1 - dvieju konteineriu, 2 - vieno konteinerio arba 3 - optimizuota): ";
            cin >> strategija;

            if (konteinerio_pasirinkimas == 'v' || konteinerio_pasirinkimas == 'V') {
                switch (strategija) {
                    case '1':
                        start = chrono::high_resolution_clock::now();
                        rusiutiStudentus_Strategy1(studentai);
                        end = chrono::high_resolution_clock::now();
                        cout << "Rusiavimas uztruko: " << chrono::duration<double>(end - start).count() << " s" << endl;
                        break;
                    case '2':
                        start = chrono::high_resolution_clock::now();
                        rusiutiStudentus_Strategy2(studentai);
                        end = chrono::high_resolution_clock::now();
                        cout << "Rusiavimas uztruko: " << chrono::duration<double>(end - start).count() << " s" << endl;
                        break;
                    case '3':
                        start = chrono::high_resolution_clock::now();
                        rusiutiStudentus_Strategy3(studentai);
                        end = chrono::high_resolution_clock::now();
                        cout << "Rusiavimas uztruko: " << chrono::duration<double>(end - start).count() << " s" << endl;
                        break;
                    default:
                        cout << "Netinkama strategija" << endl;
                        break;
                }
            } else {
                switch (strategija) {
                    case '1':
                        start = chrono::high_resolution_clock::now();
                        rusiutiStudentus_Strategy1(studentaiList);
                        end = chrono::high_resolution_clock::now();
                        cout << "Rusiavimas uztruko: " << chrono::duration<double>(end - start).count() << " s" << endl;
                        break;
                    case '2':
                        start = chrono::high_resolution_clock::now();
                        rusiutiStudentus_Strategy2(studentaiList);
                        end = chrono::high_resolution_clock::now();
                        cout << "Rusiavimas uztruko: " << chrono::duration<double>(end - start).count() << " s" << endl;
                        break;
                    case '3':
                        start = chrono::high_resolution_clock::now();
                        rusiutiStudentus_Strategy3(studentaiList);
                        end = chrono::high_resolution_clock::now();
                        cout << "Rusiavimas uztruko: " << chrono::duration<double>(end - start).count() << " s" << endl;
                        break;
                    default:
                        cout << "Netinkama strategija" << endl;
                        break;
                }
            }

            // REZULTATU ISVEDIMAS I FAILUS IR SPARTOS ANALIZE (VECTOR IR LIST)
            start = chrono::high_resolution_clock::now();
            if (konteinerio_pasirinkimas == 'v' || konteinerio_pasirinkimas == 'V') {
                vector<Stud> moksliukai;
                vector<Stud> tinginukai;
                for (const auto& stud : studentai) {
                    if (stud.galutinisVid() < 5.0) {
                        tinginukai.push_back(stud);
                    } else {
                        moksliukai.push_back(stud);
                    }
                }
                isvestiRezultatus("tinginukai.txt", tinginukai);
                isvestiRezultatus("moksliukai.txt", moksliukai);

            } else {

                vector<Stud> moksliukai;
                vector<Stud> tinginukai;
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

            end = chrono::high_resolution_clock::now();
            cout << "Rezultatu isvedimas i failus uztruko: " << chrono::duration<double>(end - start).count() << " s" << endl;

            // JEI PASIRENKAMAS JAU EGZISTUOJANCIO FAILO NUSKAITYMAS
        } else if (pasirinkimas == 'f' || pasirinkimas == 'F') {
            string failo_pav;
            cout << "Iveskite failo pavadinima: ";
            cin >> failo_pav;

            // FAILO NUSKAITYMAS
            skaitytiIsFailoSuKlaiduTikrinimu(studentai, failo_pav);

            // JEI PASIRENKAMAS RANKINIS DUOMENU IVEDIMAS
        } else {
            int studentu_skaicius;
            cout << "Kiek studentu norite ivesti? ";
            cin >> studentu_skaicius;

            // IVEDIMO PATIKRINIMAS
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Netinkama ivestis. Prasome ivesti skaiciu: ";
                cin >> studentu_skaicius;
            }
            cin.ignore();
            studentai.resize(studentu_skaicius);

            // PASIRINKIMAS AR PAZYMIUS GENERUOTI
            char generuoti;
            do {
                cout << "Ar norit, kad namu darbu ir egzamino rezultatai butu sugeneruoti? (y/n): ";
                cin >> generuoti;

                // IVEDIMO PATIKRINIMAS
                if (generuoti != 'y' && generuoti != 'Y' && generuoti != 'n' && generuoti != 'N') {
                    cout << "Neteisingas pasirinkimas. Prašome pasirinkti 'y' arba 'n'." << endl;
                }
            } while (generuoti != 'y' && generuoti != 'Y' && generuoti != 'n' && generuoti != 'N');

            // JEI PASIRENKAMA GENERUOT
            if (generuoti == 'y' || generuoti == 'Y') {
                for (int i = 0; i < studentu_skaicius; ++i) {
                    cout << "Iveskite studento Nr. " << i + 1 << " varda: ";
                    string vardas;
                    cin >> vardas;
                    cout << "Iveskite studento Nr. " << i + 1 << " pavarde: ";
                    string pavarde;
                    cin >> pavarde;

                    // GENERAVIMO FUNKCIJA
                    vector<int> nd;
                    for (int j = 0; j < 15; ++j) {
                        nd.push_back(rand() % 10 + 1);
                    }
                    double egz = rand() % 10 + 1;
                    studentai[i].setVardas(vardas);
                    studentai[i].setPavarde(pavarde);
                    studentai[i].setND(nd);
                    studentai[i].setEgz(egz);
                }

                // JEI NENORIMA PAZYMIU GENERUOTI
            } else {
                for (int i = 0; i < studentu_skaicius; ++i) {
                    cout << "Iveskite studento Nr. " << i + 1 << " varda: ";
                    string vardas;
                    cin >> vardas;
                    cout << "Iveskite studento Nr. " << i + 1 << " pavarde: ";
                    string pavarde;
                    cin >> pavarde;
                    cin.ignore();
                    Stud student;
                    student.setVardas(vardas);
                    student.setPavarde(pavarde);
                    ivestiNamudarbus(student);

                    // EGZAMINO REZULTATO IVEDIMAS
                    cout << "Iveskite egzamino rezultata (skaicius nuo 1 iki 10): ";
                    while (true) {
                        double egz;
                        cin >> egz;
                        if (cin.fail() || egz < 1 || egz > 10) {
                            cin.clear(); // Išvalome klaidos vėliavėlę
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Neteisinga ivestis. Iveskite skaiciu tarp 1 ir 10: ";
                        } else {
                            student.setEgz(egz);
                            break;
                        }
                    }
                    studentai[i] = student;
                }
            }
        }

        // SKAICIAVIMO BUDO PASIRINKIMAS

        // GENERUOJAMAS FAILAS VISADA SU VIDURKIU
        char skaiciavimo_budas;
        bool generuojameFaila = false;
        if (pasirinkimas == 'g' || pasirinkimas == 'G') {
            generuojameFaila = true;
            skaiciavimo_budas = 'v';

            // FAILU NUSKAITYMUI IR RANKINIAM IVEDIMUI
        } else {
            do {
                cout << "Ar norite skaiciuoti galutini bala su vidurkiu ar mediana? (v/m): ";
                cin >> skaiciavimo_budas;

                if (skaiciavimo_budas != 'v' && skaiciavimo_budas != 'V' && skaiciavimo_budas != 'm' && skaiciavimo_budas != 'M') {
                    cout << "Neteisingas pasirinkimas. Prašome pasirinkti 'v' arba 'm'." << endl;
                }
            } while (skaiciavimo_budas != 'v' && skaiciavimo_budas != 'V' && skaiciavimo_budas != 'm' && skaiciavimo_budas != 'M');
        }


        // SPAUSDINAM REZULTATUS
        if (!generuojameFaila) {
            spausdintiRezultatus(studentai, skaiciavimo_budas);
            cout << "Rezultatu lenteles saugojimo atmintyje adresas: " << &studentai << &skaiciavimo_budas << endl;
        }

        // KLAUSIAM AR KARTOT PROGRAMA
        cout << "Ar norite dar karta vykdyti programa? (y/n): ";
        cin >> testi;
    } while (testi == 'y' || testi == 'Y');

    return 0;
}
