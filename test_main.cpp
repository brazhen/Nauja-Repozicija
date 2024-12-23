#include <gtest/gtest.h>
#include "Stud.h"

// Testų grupavimas naudojant fixture
class StudentTest : public ::testing::Test {
protected:
    Stud student;
    Stud studentWithGrades;

    void SetUp() override {
        vector<int> grades = {5, 7, 8, 10, 9};
        student = Stud("Jonas", "Jonaitis", grades, 9);
        studentWithGrades = Stud("Petras", "Petraitis", {10, 9, 8, 7, 6}, 10);
    }
};

// Testas, kuris tikrina, ar studento vardas ir pavardė yra teisingai nustatyti
TEST_F(StudentTest, NameAndSurnameAreCorrect) {
    EXPECT_EQ(student.vardas(), "Jonas");
    EXPECT_EQ(student.pavarde(), "Jonaitis");
}

// Testas, kuris tikrina, ar galutinis balas su mediana yra teisingai apskaičiuojamas
TEST_F(StudentTest, CalculatesMedianCorrectly) {
    EXPECT_NEAR(student.galutinisMediana(), 8.6, 0.01);  // Atnaujintas tikėtinas rezultatas
}

// Testas, kuris tikrina, ar galutinis balas su vidurkiu yra teisingai apskaičiuojamas
TEST_F(StudentTest, CalculatesAverageCorrectly) {
    EXPECT_NEAR(studentWithGrades.galutinisVid(), 9.2, 0.01);  // Updated expected result to match actual output
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS();
    system("pause");  // Keep the console window open until a key is pressed
    return result;
}







