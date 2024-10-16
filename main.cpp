#include "Mylib.h"
#include "Stud.h"
#include <chrono>

int main() {
    srand(static_cast<unsigned int>(time(0)));

    char testi;
    do {
        vector<Stud> studentai;
        char pasirinkimas;

        do {
            cout << "Ar norite ivest studentu duomenis rankiniu budu, nuskaityt is failo ar sugeneruoti faila? (r/f/g): ";
            cin >> pasirinkimas;
            if (pasirinkimas != 'r' && pasirinkimas != 'R' && pasirinkimas != 'f' && pasirinkimas != 'F' && pasirinkimas != 'g' && pasirinkimas != 'G') {
                cout << "Neteisingas pasirinkimas. Prasom pasirinkti 'r', 'f' arba 'g'." << endl;
            }
        } while (pasirinkimas != 'r' && pasirinkimas != 'R' && pasirinkimas != 'f' && pasirinkimas != 'F' && pasirinkimas != 'g' && pasirinkimas != 'G');

        if (pasirinkimas == 'g' || pasirinkimas == 'G') {
            // Generate the file and measure performance
            int studentu_skaicius;
            cout << "Pasirinkite studentu skaiciu: 1000, 10000, 100000, 1000000, 10000000: ";
            cin >> studentu_skaicius;

            auto start = chrono::high_resolution_clock::now();
            generuotiStudentuFaila(studentu_skaicius);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> diff = end - start;
            cout << "Failo generavimas uztruko: " << diff.count() << " s" << endl;

            // Read from the generated file
            string failo_pav = "studentai.txt";
            start = chrono::high_resolution_clock::now();
            skaitytiIsFailoSuKlaiduTikrinimu(studentai, failo_pav);
            end = chrono::high_resolution_clock::now();
            diff = end - start;
            cout << "Duomenu nuskaitymas uztruko: " << diff.count() << " s" << endl;

            // Sort students into categories
            start = chrono::high_resolution_clock::now();
            rusiutiStudentus(studentai);
            end = chrono::high_resolution_clock::now();
            diff = end - start;
            cout << "Studentu rusiuoti i kategorijas uztruko: " << diff.count() << " s" << endl;
        } else if (pasirinkimas == 'f' || pasirinkimas == 'F') {
            string failo_pav;
            cout << "Iveskite failo pavadinima: ";
            cin >> failo_pav;

            skaitytiIsFailoSuKlaiduTikrinimu(studentai, failo_pav);  // Skaitome iš failo su klaidų tikrinimu
        } else {
            int studentu_skaicius;
            cout << "Kiek studentu norite ivesti? ";
            cin >> studentu_skaicius;

            while (cin.fail()) { // Patikrinimas dėl neteisingo įvedimo
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Netinkama ivestis. Prasome ivesti skaiciu: ";
                cin >> studentu_skaicius;
            }

            cin.ignore();  // Išvalome '\n' po skaičiaus įvedimo
            studentai.resize(studentu_skaicius);

            // Pasirinkimas, ar ND ir egzamino rezultatus norite ivesti rankiniu budu, ar generuoti
            char generuoti;
            do {
                cout << "Ar norit, kad namu darbu ir egzamino rezultatai butu sugeneruoti? (y/n): ";
                cin >> generuoti;

                if (generuoti != 'y' && generuoti != 'Y' && generuoti != 'n' && generuoti != 'N') {
                    cout << "Neteisingas pasirinkimas. Prašome pasirinkti 'y' arba 'n'." << endl;
                }
            } while (generuoti != 'y' && generuoti != 'Y' && generuoti != 'n' && generuoti != 'N');

            if (generuoti == 'y' || generuoti == 'Y') {
                for (int i = 0; i < studentu_skaicius; ++i) {
                    cout << "Iveskite studento Nr. " << i + 1 << " varda: ";
                    cin >> studentai[i].vardas;
                    cout << "Iveskite studento Nr. " << i + 1 << " pavarde: ";
                    cin >> studentai[i].pavarde;

                    // Generuojame ND ir egzaminų rezultatus
                    for (int j = 0; j < 15; ++j) {
                        studentai[i].ND.push_back(rand() % 10 + 1);  // Generuojame pažymius (1-10)
                    }
                    studentai[i].egz = rand() % 10 + 1;  // Generuojame egzamino pažymį (1-10)
                }
            } else {
                for (int i = 0; i < studentu_skaicius; ++i) {
                    cout << "Iveskite studento Nr. " << i + 1 << " varda: ";
                    cin >> studentai[i].vardas;
                    cout << "Iveskite studento Nr. " << i + 1 << " pavarde: ";
                    cin >> studentai[i].pavarde;

                    cin.ignore();  // Čia išvalome buferį prieš naudojant getline
                    ivestiNamudarbus(studentai[i]);

                    cout << "Iveskite egzamino rezultata (skaicius nuo 1 iki 10): ";
                    while (true) {
                        cin >> studentai[i].egz;
                        if (cin.fail() || studentai[i].egz < 1 || studentai[i].egz > 10) {
                            cin.clear(); // Išvalome klaidos vėliavėlę
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Išvalome likusią įvestį
                            cout << "Neteisinga ivestis. Iveskite skaiciu tarp 1 ir 10: ";
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        // Pasirinkimas, kaip skaičiuoti galutinį balą
        char skaiciavimo_budas;
        do {
            cout << "Ar norite skaiciuoti galutini bala su vidurkiu ar mediana? (v/m): ";
            cin >> skaiciavimo_budas;

            if (skaiciavimo_budas != 'v' && skaiciavimo_budas != 'V' && skaiciavimo_budas != 'm' && skaiciavimo_budas != 'M') {
                cout << "Neteisingas pasirinkimas. Prašome pasirinkti 'v' arba 'm'." << endl;
            }
        } while (skaiciavimo_budas != 'v' && skaiciavimo_budas != 'V' && skaiciavimo_budas != 'm' && skaiciavimo_budas != 'M');

        // Spausdiname rezultatus
        spausdintiRezultatus(studentai, skaiciavimo_budas);

        cout << "Ar norite dar karta vykdyti programa? (y/n): ";
        cin >> testi;
    } while (testi == 'y' || testi == 'Y');

    return 0;
}

