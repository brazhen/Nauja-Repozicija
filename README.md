# Projektas: Studentų Rezultatų Analizė

## Aprašymas

Šis projektas skirtas studentų pasiekimų analizei. Programa leidžia įvesti studentų duomenis, generuoti atsitiktinius duomenis, skaityti duomenis iš failo, atlikti skaičiavimus pagal vidurkį ar medianą ir išvesti rezultatus į failus.

## Įdiegimo instrukcija

Norint sėkmingai paleisti šią programą, reikalinga CMake įrankio versija 3.14 ar naujesnė. Taip pat reikalingas C++ kompiliatorius, palaikantis C++17 standartą.

### Programos paruošimas

1. Atsisiųskite projekto kodą iš GitHub ar kitos saugyklos.
2. Įsitikinkite, kad jūsų sistemoje įdiegtas CMake ir tinkamas C++ kompiliatorius.
3. Į programos aplanką atsisiųskite gtest

### Programos kompiliavimas

Atidarykite terminalą ir vykdykite šias komandas:

```bash
cd kelias_iki_projekto
mkdir build
cd build
cmake ..
make
```
Šios komandos sukurs build katalogą, kuriame bus generuojami visi kompiliavimo failai, ir iškompiliuos programą.

## Naudojimosi instrukcija

Programa gali būti naudojama keliais būdais, priklausomai nuo to, kaip norite įvesti duomenis:

1. Rankinis duomenų įvedimas: paleidus programą, pasirinkite duomenų įvedimo būdą ir įveskite reikiamus duomenis.
2. Duomenų generavimas: programa gali sugeneruoti duomenų failą su nurodytu studentų skaičiumi.
3. Duomenų skaitymas iš failo: duomenys gali būti nuskaitomi iš iš anksto paruošto tekstinio failo.

## Rezultatų išvedimas

Gauti rezultatai išvedami į failus, kurių pavadinimai nurodomi programos vykdymo metu. Rezultatai taip pat gali būti rodomi konsolėje.

## Gauti testavimo rezultatai

Programa sėkmingai atlieka studentų duomenų analizę. Priklausomai nuo pasirinkto skaičiavimo būdo (vidurkis ar mediana),
rezultatai gali šiek tiek skirtis. Programa efektyviai tvarko didelius duomenų kiekius, o jos veikimo laikas priklauso nuo
apdorojamų duomenų kiekio.
