//
// Created by or on 5/2/23.
//

#ifndef UNTITLED3_YOUNGNINJA_H
#define UNTITLED3_YOUNGNINJA_H
#include "Ninja.hpp"

namespace ariel {
    int const youngSpeed=14;
    int const youngLife=100;
    class YoungNinja:public Ninja{
    public:
        int getType() const override;

        YoungNinja(std::string name,Point location);
    };
}

#endif //UNTITLED3_YOUNGNINJA_H
