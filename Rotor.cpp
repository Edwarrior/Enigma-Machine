#include "Rotor.h"
#include <iostream>
#include <algorithm>


Rotor::Rotor(char letterOrder[26], std::list<int32_t> rotationNotchPositions, int32_t ringSetting, int32_t rotationPosition) : EnigmaMachineComponent(letterOrder)
{
    this->rotationNotchPositions = rotationNotchPositions;
    this->ringSetting = ringSetting;
    this->rotationPosition = rotationPosition;
    beforeReflector = false;


}

char Rotor::SwapCharacter(char in)
{
    char out = 'A';

    



    return out;
}

void Rotor::Rotate()
{
    rotationPosition++;

    if (rotationPosition == 27)
    {
        rotationPosition = 1;
    }

    if (std::find(rotationNotchPositions.begin(), rotationNotchPositions.end(), rotationPosition) != rotationNotchPositions.end())
    {
        rotateNeighbour = true;
    }
    else
    {
        rotateNeighbour = false;
    }
}

void Rotor::SetBeforeReflector(bool newBeforeReflector)
{
    beforeReflector = newBeforeReflector;
}

bool Rotor::GetRotateNeighbour()
{
    return rotateNeighbour;
}