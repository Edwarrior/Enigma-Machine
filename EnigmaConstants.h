#include<string>

#ifndef ENIGMACONSTANTS_H_
#define ENIGMACONSTANTS_H_

namespace EnigmaConstants
{
    struct Rotor
    {
        std::string letterOrder;
        int notchPosition;

    };

    const std::string alphabetLetterOrder = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string reflectorLetterOrder = "YRUHQSLDPXNGOKMIEBFZCWVJAT";

    const Rotor rotorI = {"EKMFLGDQVZNTOWYHXUSPAIBRCJ", 17};
    const Rotor rotorII = {"AJDKSIRUXBLHWTMCQGZNPYFVOE", 5};
    const Rotor rotorIII = {"BDFHJLCPRTXVZNYEIWGAKMUSQO", 22};
    const Rotor rotorIV = {"ESOVPZJAYQUIRHXLNFTGKDCMWB", 10};
    const Rotor rotorV = {"VZBRGITYUPSDNHLXAWMJQOFECK", 0};
}
#endif