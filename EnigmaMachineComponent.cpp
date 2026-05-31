#include "EnigmaMachineComponent.h"
#include <cstring>
#include <iostream>

EnigmaMachineComponent::EnigmaMachineComponent(char letterOrder[26])
{
    std::memcpy(this->letterOrder, letterOrder, sizeof(letterOrder));

}