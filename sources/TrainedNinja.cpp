//
// Created by or on 5/2/23.
//

#include "TrainedNinja.hpp"

#include <utility>

ariel::TrainedNinja::TrainedNinja(std::string name, ariel::Point location): Ninja(std::move(name),location,trainedLife,trainedSpeed) {}

