//
// Created by or on 5/2/23.
//

#include "OldNinja.hpp"

#include <utility>


ariel::OldNinja::OldNinja(std::string name, ariel::Point location): Ninja(std::move(name),location,oldLife,oldSpeed) {}

