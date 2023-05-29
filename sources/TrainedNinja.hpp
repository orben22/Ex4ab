//
// Created by or on 5/2/23.
//

#ifndef UNTITLED3_TRAINEDNINJA_H
#define UNTITLED3_TRAINEDNINJA_H
#include "Ninja.hpp"
namespace ariel {
    int const trainedSpeed=12;
    int const trainedLife=120;
    class TrainedNinja:public Ninja{
    public:
        int getType() const override;

        TrainedNinja(std::string name,Point location);
    };
}

#endif //UNTITLED3_TRAINEDNINJA_H
