#include <string>

#ifndef ENIGMAMACHINECOMPONENT_H_
#define ENIGMAMACHINECOMPONENT_H_


class EnigmaMachineComponent
{
    public:
    EnigmaMachineComponent() = delete;
    EnigmaMachineComponent(char letterOrder[26]);
    virtual char SwapCharacter(char in) = 0;

    protected:
    char letterOrder[26];
    const char ALPHABET[26] = {'A','B','C','D','E',
                               'F','G','H','I','J',
                               'K','L','M','N','O',
                               'P','Q','R','S','T',
                               'U','V','W','X','Y',
                               'Z'};
};

#endif