//
// Created by or on 5/2/23.
//

#include "YoungNinja.hpp"

#include <utility>

ariel::YoungNinja::YoungNinja(std::string name, ariel::Point location): Ninja(std::move(name),std::move(location),youngLife,youngSpeed) {}

int ariel::YoungNinja::getType() const {
    return 1;
}
