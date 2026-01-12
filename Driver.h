#include<string>

#include "EnigmaMachine.h"

#ifndef DRIVER_H_
#define DRIVER_H_



class Driver
{
    public:
    Driver(EnigmaMachine *enigmaMachine);

    private:
    void RunMachine();

    EnigmaMachine *enigmaMachine;

};



#endif