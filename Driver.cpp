#include "Driver.h"

#include <iostream>


Driver::Driver(EnigmaMachine *enigmaMachine)
{
    this->enigmaMachine = enigmaMachine;
    
    RunMachine();
}

void Driver::RunMachine()
{
    std::string userInput = "";


    enigmaMachine->Configure(&EnigmaConstants::rotorIII, &EnigmaConstants::rotorII, &EnigmaConstants::rotorI, 0, 0, 0);
    while(true)
    {

    
    std::cout << "Enter some text (all caps)\n";

    std::cin >> userInput;

    std::cout << enigmaMachine->Encrypt(userInput) << "\n";


    }
}
