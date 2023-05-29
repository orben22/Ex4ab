//
// Created by or on 5/2/23.
//

#ifndef UNTITLED3_OLDNINJA_H
#define UNTITLED3_OLDNINJA_H
#include "Ninja.hpp"
namespace ariel {
    int const oldSpeed=8;
    int const oldLife=150;
    class OldNinja:public Ninja{
    public:
        OldNinja(std::string name,Point location);

        int getType() const override;
    };
}

#endif //UNTITLED3_OLDNINJA_H
