#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/Point.hpp"
#include "sources/Cowboy.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/OldNinja.hpp"
#include "sources/Team.hpp"


TEST_CASE("Test- Point Class") {
    ariel::Point p1(3, 4);
    ariel::Point p2;
    CHECK_EQ(p1.getX(), 3);
    CHECK_EQ(p1.getY(), 4);
    CHECK_EQ(p2.getX(), 0);
    CHECK_EQ(p2.getY(), 0);
    CHECK_EQ(p2.distance(p1), 5);
}
//need to check move func
TEST_CASE("Test-Ninja Class") {
    ariel::Point p1(3, 4);
    ariel::Point p2;
    ariel::Point p3(2, 6);
    auto *youngNinja = new ariel::YoungNinja("or", p1);
    auto *oldNinja = new ariel::OldNinja("shay", p2);
    auto *trainedNinja = new ariel::TrainedNinja("ilan", p3);
    CHECK_EQ(youngNinja->distance(oldNinja), 5);
    CHECK_EQ(oldNinja->distance(youngNinja), 5);
    CHECK_EQ(youngNinja->distance(youngNinja), 0);
    CHECK_EQ(trainedNinja->getName(), "ilan");
    CHECK_EQ(youngNinja->getLife(), 100);
    CHECK_EQ(trainedNinja->getLife(), 120);
    CHECK_EQ(oldNinja->getLife(), 150);
    CHECK_EQ(youngNinja->getSpeed(), 14);
    CHECK_EQ(trainedNinja->getSpeed(), 12);
    CHECK_EQ(oldNinja->getSpeed(), 8);
    CHECK_EQ(youngNinja->getLocation(), p1);
    CHECK_EQ(trainedNinja->getLocation(), p2);
    CHECK_EQ(oldNinja->getLocation(), p3);
    CHECK(youngNinja->isAlive());
}

TEST_CASE("Test-Cowboy Class") {
    ariel::Point p1(2, 5);
    auto *c1 = new ariel::Cowboy("Bob", p1);
    CHECK(c1->hasboolets());
    CHECK_NOTHROW(c1->reload());
    CHECK_EQ(c1->getLocation(), p1);
    CHECK_EQ(c1->getLife(), 110);
    CHECK(c1->isAlive());
    CHECK_EQ(c1->getName(), "Bob");
}

TEST_CASE("Test-Cowboy vs Ninja") {
    ariel::Point p1(1, 0);
    ariel::Point p2(0.99, 0);
    ariel::Point p3;
    ariel::Point p4(18, 0);
    auto *c1 = new ariel::Cowboy("Bob", p1);
    auto *c2 = new ariel::Cowboy("Alice", p2);
    auto *youngNinja = new ariel::YoungNinja("or", p3);
    auto *trainedNinja = new ariel::TrainedNinja("chen", p4);
    c1->shoot(youngNinja);
    CHECK_EQ(youngNinja->getLife(), 90);
    CHECK_EQ(c1->getNumOfBullets(), 5);
    youngNinja->slash(c1);
    youngNinja->slash(c2);
    youngNinja->slash(trainedNinja);
    CHECK_EQ(c1->getLife(), 110);
    CHECK_EQ(c2->getLife(), 97);
    CHECK_EQ(trainedNinja->getLife(), 120);
    youngNinja->move(c1);
    youngNinja->slash(c1);
    CHECK_EQ(c1->getLife(), 97);
    youngNinja->move(trainedNinja);
    youngNinja->slash(trainedNinja);
    CHECK_EQ(trainedNinja->getLife(), 120);
    youngNinja->move(trainedNinja);
    CHECK_EQ(trainedNinja->getLife(), 107);
    for (int i = 1; i <= 5; i++) c1->shoot(youngNinja);
    CHECK_FALSE(c1->hasboolets());
    CHECK_NOTHROW(c1->shoot(c2));
    CHECK_EQ(c2->getLife(), 97);
    c1->reload();
    CHECK_EQ(c1->getNumOfBullets(), 6);
    for (int i = 1; i <= 4; i++) c1->shoot(youngNinja);
    CHECK_EQ(youngNinja->getLife(), 0);
    youngNinja->slash(c2);
    CHECK_EQ(c2->getLife(), 97);
    CHECK_FALSE(youngNinja->isAlive());
    ariel::Point p5(0.1, 0);
    auto *oldNinja = new ariel::OldNinja("Tim", p5);
    for (int i = 1; i <= 8; i++) oldNinja->slash(c2);
    c2->shoot(oldNinja);
    CHECK_EQ(oldNinja->getLife(), 150);
    CHECK_FALSE(c2->hasboolets());
    CHECK_FALSE(c2->isAlive());
    CHECK_THROWS(c2->reload());
}

TEST_CASE("Test-Team Class") {
    ariel::Point p1(1, 0);
    ariel::Point p2(0.5, 0);
    ariel::Point p3(9, 8);
    ariel::Point p4(10, 2);
    ariel::Point p5(5, 3);
    ariel::Point p6(6, 0);
    ariel::Point p7(1, 8);
    ariel::Point p8(1, 9);
    ariel::Point p9(1.5, 1.5);
    ariel::Point p10(0, 1);
    auto *leader = new ariel::Cowboy("Tim", p1);
    auto *c2 = new ariel::Cowboy("Tom", p2);
    auto *c3 = new ariel::YoungNinja("Tommy", p3);
    auto *c4 = new ariel::OldNinja("Timmy", p4);
    auto *c5 = new ariel::TrainedNinja("Or", p5);
    auto *c6 = new ariel::TrainedNinja("Dor", p6);
    auto *c7 = new ariel::Cowboy("Mor", p7);
    auto *c8 = new ariel::Cowboy("Shay", p8);
    auto *c9 = new ariel::Cowboy("May", p9);
    auto *c10 = new ariel::YoungNinja("Ori", p10);
    auto *c11 = new ariel::Cowboy("Test", p1);
    auto t1 = new ariel::Team(leader);
    CHECK_THROWS(t1->add(leader));
    t1->add(c2);
    t1->add(c3);
    t1->add(c4);
    t1->add(c5);
    t1->add(c6);
    t1->add(c7);
    t1->add(c8);
    t1->add(c9);
    t1->add(c10);
    CHECK_THROWS(t1->add(c11));
    CHECK_EQ(t1->stillAlive(), 10);
    for (int i = 0; i < 11; i++) {
        if (!c11->hasboolets()) c11->reload();
        c11->shoot(c2);
    }
    CHECK_EQ(t1->stillAlive(), 9);
    for (int i = 0; i < 11; i++) {
        if (!c11->hasboolets()) c11->reload();
        c11->shoot(leader);
    }
    CHECK_EQ(t1->stillAlive(), 8);
    CHECK_NE(t1->getLeader(), leader);
    auto t2 = new ariel::Team(c11);
    CHECK_THROWS(t2->add(c3));
    auto *c22 = new ariel::Cowboy("Tom2", p2);
    auto *c33 = new ariel::YoungNinja("Tommy2", p3);
    auto *c44 = new ariel::OldNinja("Timmy2", p4);
    auto *c55 = new ariel::TrainedNinja("Or2", p5);
    auto *c66 = new ariel::TrainedNinja("Dor2", p6);
    auto *c77 = new ariel::Cowboy("Mor2", p7);
    auto *c88 = new ariel::Cowboy("Shay2", p8);
    auto *c99 = new ariel::Cowboy("May2", p9);
    auto *c1010 = new ariel::YoungNinja("Ori2", p10);
    t2->add(c22);
    t2->add(c33);
    t2->add(c44);
    t2->add(c55);
    t2->add(c66);
    t2->add(c77);
    t2->add(c88);
    t2->add(c99);
    t2->add(c1010);
    while (t1->stillAlive() > 0 && t2->stillAlive() > 0) {
        t1->attack(t2);
        t2->attack(t1);
    }
    CHECK(((t1->stillAlive() == 0) || (t2->stillAlive() == 0)));
    if (t1->stillAlive() == 0) {
        CHECK_THROWS(t1->attack(t2));
    } else if (t2->stillAlive() == 0) {
        CHECK_THROWS(t2->attack(t1));
    }
}
