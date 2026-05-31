#include <string>
#include "EnigmaMachineComponent.h"


#ifndef PLUGBOARD_H_
#define PLUGBOARD_H_

class PlugBoard : public EnigmaMachineComponent
{
    public:
    PlugBoard(char letterOrder[26]);
    char SwapCharacter(char in) override;
};

#endif