// Copyright 2024 Jessica Vu

#include <iostream>
#include <fstream>  // Has to put it here to explicitly use for ifstream
#include <string>
#include "Universe.hpp"
#include "CelestialBody.hpp"

using NB::Universe;
using NB::CelestialBody;

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testNumOfParticles) {
    Universe uni;
    std::ifstream fin;
    fin.open("nbody/8star-rotation.txt");
    fin >> uni;
    std::ofstream fout;
    fout.open("output.txt");
    fout << uni;
    std::ifstream fin1;
    fin1.open("output.txt");
    std::string filename;
    int temp;
    fin1 >> temp;
    BOOST_REQUIRE_EQUAL(temp, 8);
}

BOOST_AUTO_TEST_CASE(testRadius) {
    Universe uni;
    std::ifstream fin;
    fin.open("nbody/planets.txt");
    fin >> uni;
    std::ofstream fout;
    fout.open("output.txt");
    fout << uni;
    std::ifstream fin1;
    fin1.open("output.txt");
    std::string filename;
    int temp;
    double temp1;
    fin1 >> temp >> temp1;
    BOOST_REQUIRE_EQUAL(temp1, 2.50e+11);
}

BOOST_AUTO_TEST_CASE(testBinaryUni) {
    Universe uni;
    std::ifstream fin;
    fin.open("nbody/binary.txt");
    fin >> uni;
    std::ofstream fout;
    fout.open("output.txt");
    fout << uni;
    std::ifstream fin1;
    fin1.open("output.txt");
    std::string filename;
    int temp;
    double temp1;
    fin1 >> temp >> temp1 >> temp1 >> temp1 >> temp1 >> temp1 >> temp1 >> filename;
    BOOST_REQUIRE_EQUAL(filename, "sun.gif");
}

BOOST_AUTO_TEST_CASE(testUni100) {
    Universe uni;
    std::ifstream fin;
    fin.open("nbody/uniform100.txt");
    fin >> uni;
    std::ofstream fout;
    fout.open("output.txt");
    fout << uni;
    std::ifstream fin1;
    fin1.open("output.txt");
    std::string filename;
    int temp;
    double temp1, temp2, temp3, temp4, temp5, temp6;
    fin1 >> temp >> temp1 >> temp2 >> temp3 >> temp4 >> temp5 >> temp6 >> filename;
    BOOST_REQUIRE_EQUAL(filename, "pluto.gif");
    BOOST_REQUIRE_EQUAL(temp, 100);
    BOOST_REQUIRE_EQUAL(temp1, 6.0E9);
    BOOST_REQUIRE_EQUAL(temp2, 5.000000e+09);
    BOOST_REQUIRE_EQUAL(temp3, 0.000000e+00);
    BOOST_REQUIRE_EQUAL(temp4, 0.000000e+00);
    BOOST_REQUIRE_EQUAL(temp5, -2.00440e+02);
    BOOST_REQUIRE_EQUAL(temp6, 4.00e+22);
}

BOOST_AUTO_TEST_CASE(testStepMethod) {
    Universe uni;
    std::ifstream fin;
    fin.open("nbody/planets.txt");
    fin >> uni;
    uni.step(25000);
    std::ofstream fout;
    fout.open("output.txt");
    fout << uni;
    std::ifstream fin1;
    fin1.open("output.txt");
    std::string filename;
    int temp;
    double temp1, temp2, temp3, temp4, temp5, temp6;
    fin1 >> temp >> temp1 >> temp2 >> temp3 >> temp4 >> temp5 >> temp6 >> filename;
    BOOST_REQUIRE_EQUAL(filename, "earth.gif");
    BOOST_REQUIRE_EQUAL(temp, 5);
    BOOST_REQUIRE_CLOSE(temp1, 2.50e+11, 1.0);
    BOOST_REQUIRE_CLOSE(temp2, 1.4960e+11, 10.0);
    BOOST_REQUIRE_CLOSE(temp3, 7.4500e+08, 1.0);
}

BOOST_AUTO_TEST_CASE(testMultipleStep) {
    Universe uni;
    std::ifstream fin;
    fin.open("nbody/planets.txt");
    fin >> uni;
    uni.step(25000);
    uni.step(25000);
    uni.step(25000);
    std::ofstream fout;
    fout.open("output.txt");
    fout << uni;
    std::ifstream fin1;
    fin1.open("output.txt");
    std::string filename;
    int temp;
    double temp1, temp2, temp3, temp4, temp5, temp6;
    fin1 >> temp >> temp1 >> temp2 >> temp3 >> temp4 >> temp5 >> temp6 >> filename;
    BOOST_REQUIRE_CLOSE(temp4, -4.4460e+02, 10.0);
}
