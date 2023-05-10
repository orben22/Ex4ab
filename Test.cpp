#include "doctest.h"
#include "sources/Ninja.hpp"
#include "sources/Character.hpp"
#include "sources/Point.hpp"
#include "sources/Cowboy.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/OldNinja.hpp"

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
TEST_CASE("Test-Cowboy vs Ninja"){
    ariel::Point p1(1, 0);
    ariel::Point p2(0.99,0);
    ariel::Point p3;
    auto *c1 = new ariel::Cowboy("Bob", p1);
    auto *c2 = new ariel::Cowboy("Alice", p2);
    auto *youngNinja = new ariel::YoungNinja("or", p3);
    c1->shoot(youngNinja);
    CHECK_EQ(youngNinja->getLife(),90);
    CHECK_EQ(c1->getNumOfBullets(),5);
    youngNinja->slash(c1);
    youngNinja->slash(c2);
    CHECK_EQ(c1->getLife(),110);
    CHECK_EQ(c2->getLife(),97);
    for (int i=1;i<=5;i++) c1->shoot(youngNinja);
    CHECK_FALSE(c1->hasBullets());
    c1->reload();
    CHECK_EQ(c1->getNumOfBullets(),6);














}