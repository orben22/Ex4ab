#include "doctest.h"
#include "sources/Ninja.hpp"
#include "sources/Character.hpp"
#include "sources/Point.hpp"
#include "sources/Cowboy.hpp"

TEST_CASE("") {
    CHECK_THROWS(Fraction(1, 0));//the denominator can't be zero
    Fraction f1(0,9);
    Fraction f2(0,1);
    CHECK(((f1==f2)&&(f1==0)&&(f2==0)));//if the numerator is zero, so the value of the fraction is zero
    f1++;
    CHECK((f1==1));//no matter what is the denominator
}