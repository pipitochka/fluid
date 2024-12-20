//
// Created by Артем Акулов on 20.12.2024.
//
#include "generate.cpp"

#include <stdio.h>
#include <iostream>

int main(int argc, char* argv[]) {
    for (int i {}; i < argc; ++i)
    {
        std::cout << argv[i] << std::endl;
    }

    FluidFactory ff = Generate();


}