#include <string>
#include "EnigmaMachineComponent.h"


#ifndef REFLECTOR_H_
#define REFLECTOR_H_

class Reflector : public EnigmaMachineComponent
{
    public:
    Reflector(char letterOrder[26]);
    char SwapCharacter(char in) override;
};

#endif