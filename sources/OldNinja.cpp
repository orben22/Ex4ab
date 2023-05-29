//
// Created by or on 5/2/23.
//

#include "OldNinja.hpp"

#include <utility>


ariel::OldNinja::OldNinja(std::string name, ariel::Point location): Ninja(std::move(name),std::move(location),oldLife,oldSpeed) {}

int ariel::OldNinja::getType() const {
    return 3;
}

