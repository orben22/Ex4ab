#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/Point.hpp"
#include "sources/Cowboy.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/OldNinja.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"

TEST_CASE("Test- Point Class") {
    ariel::Point p1(3, 4);
    ariel::Point p2;
    CHECK_EQ(p1.getX(), 3);
    CHECK_EQ(p1.getY(), 4);
    CHECK_EQ(p2.getX(), 0);
    CHECK_EQ(p2.getY(), 0);
    CHECK_EQ(p2.distance(p1), 5);
    CHECK(p1.stillAlive());
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
    CHECK(c1->hasBullets());
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
    auto *c1 = new ariel::Cowboy("Bob", p1);
    auto *c2 = new ariel::Cowboy("Alice", p2);
    auto *youngNinja = new ariel::YoungNinja("or", p3);
    c1->shoot(youngNinja);
    CHECK_EQ(youngNinja->getLife(), 90);
    CHECK_EQ(c1->getNumOfBullets(), 5);
    youngNinja->slash(c1);
    youngNinja->slash(c2);
    CHECK_EQ(c1->getLife(), 110);
    CHECK_EQ(c2->getLife(), 97);
    for (int i = 1; i <= 5; i++) c1->shoot(youngNinja);
    CHECK_FALSE(c1->hasBullets());
    c1->reload();
    CHECK_EQ(c1->getNumOfBullets(), 6);
    for (int i = 1; i <= 4; i++) c1->shoot(youngNinja);
    CHECK_EQ(youngNinja->getLife(), 0);
    youngNinja->slash(c2);
    CHECK_EQ(c2->getLife(), 97);
    CHECK_FALSE(youngNinja->isAlive());
    ariel::Point p4(0.1, 0);
    auto *oldNinja = new ariel::OldNinja("Tim", p4);
    for (int i = 1; i <= 8; i++) oldNinja->slash(c2);
    c2->shoot(oldNinja);
    CHECK_EQ(oldNinja->getLife(), 150);
    CHECK_FALSE(c2->hasBullets());
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
    for (int i = 0; i <= 11; i++) {
        if (!c11->hasBullets()) c11->reload();
        c11->shoot(c2);
    }
    CHECK_EQ(t1->stillAlive(), 9);
}
