#include <gtest/gtest.h>
#include <studentas.h>


TEST(StudentasTest, CalculateMedianGrade) {
    std::vector<int> pazymiai = {5, 6, 7, 8, 9};
    double expectedMedian = 7.0;
    double result = skaiciuotiGalutiniBalaMediana(pazymiai);
    EXPECT_DOUBLE_EQ(result, expectedMedian);
}


TEST(StudentasTest, CalculateAverageGrade) {
    std::vector<int> pazymiai = {5, 6, 7, 8, 9};
    int egzas = 8;
    double expectedAverage = 7.2;
    double result = apskaiciuotiGalutiniBalaVidurkis(pazymiai, egzas);
    EXPECT_DOUBLE_EQ(result, expectedAverage);
}


TEST(StudentasTest, SortByLastName) {
    Studentas s1("Jonas", "Jonaitis", {5, 6, 7}, 8);
    Studentas s2("Antanas", "Antanaitis", {8, 9, 7}, 9);
    Studentas s3("Petras", "Petraitis", {6, 6, 6}, 7);

    std::vector<Studentas> students = {s1, s2, s3};
    std::sort(students.begin(), students.end(), RusiavimasPavarde);


    EXPECT_EQ(students[0].getPavarde(), "Antanaitis");
    EXPECT_EQ(students[1].getPavarde(), "Jonaitis");
    EXPECT_EQ(students[2].getPavarde(), "Petraitis");
}


TEST(StudentasTest, CopyConstructorAndAssignmentOperator) {
    Studentas s1("Jonas", "Jonaitis", {5, 6, 7}, 8);
    Studentas s2 = s1;
    Studentas s3;
    s3 = s2;


    EXPECT_EQ(s1.getVardas(), s2.getVardas());
    EXPECT_EQ(s1.getPavarde(), s2.getPavarde());
    EXPECT_EQ(s1.getPazymiai(), s2.getPazymiai());
    EXPECT_EQ(s1.getEgzas(), s2.getEgzas());
    EXPECT_EQ(s2.getVardas(), s3.getVardas());
    EXPECT_EQ(s2.getPavarde(), s3.getPavarde());
    EXPECT_EQ(s2.getPazymiai(), s3.getPazymiai());
    EXPECT_EQ(s2.getEgzas(), s3.getEgzas());
}


TEST(StudentasTest, InputAndOutput) {
    Studentas s1("Jonas", "Jonaitis", {5, 6, 7}, 8);
    std::stringstream ss;
    ss << s1;
    Studentas s2;
    ss >> s2;


    EXPECT_EQ(s2.getVardas(), "Jonas");
    EXPECT_EQ(s2.getPavarde(), "Jonaitis");
    EXPECT_EQ(s2.getEgzas(), 8);
    EXPECT_EQ(s2.getPazymiai(), std::vector<int>({5, 6, 7}));
}