#include <string>
#include "EnigmaMachineComponent.h"
#include <list>


#ifndef ROTOR_H_
#define ROTOR_H_

class Rotor : public EnigmaMachineComponent
{
    public:
    Rotor(char letterOrder[26], std::list<int32_t> rotationNotchPositions, int32_t ringSetting, int32_t rotationPosition);
    void SetBeforeReflector(bool newBeforeReflector);
    char SwapCharacter(char in) override;
    void Rotate();
    bool GetRotateNeighbour();

    private:
    bool beforeReflector;
    std::list<int32_t> rotationNotchPositions = {}; // Location of notch(es) causing neighbour rotor to rotate.
    int32_t ringSetting;        // 1-26 | Offset of letter mapping, 1 is standard and 2 means that A will map to what B originally mapped to. This is a very similar operation to the rotation position of the rotor.
    int32_t rotationPosition;   // 1-26
    bool rotateNeighbour;


};

#endif