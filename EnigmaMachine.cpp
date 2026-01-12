#include "EnigmaMachine.h"

#include <iostream>


EnigmaMachine::EnigmaMachine()
{
}

EnigmaMachine::~EnigmaMachine()
{
}

void EnigmaMachine::Configure(const EnigmaConstants::Rotor *rotorPosition1,const EnigmaConstants::Rotor *rotorPosition2,const EnigmaConstants::Rotor *rotorPosition3, int initialRotorSetting1, int initialRotorSetting2, int initialRotorSetting3)
{
    this->rotorPosition1 = rotorPosition1;
    this->rotorPosition2 = rotorPosition2;
    this->rotorPosition3 = rotorPosition3;

    this->rotorSetting1 = initialRotorSetting1;
    this->rotorSetting2 = initialRotorSetting2;
    this->rotorSetting3 = initialRotorSetting3;

}

std::string EnigmaMachine::Encrypt(std::string plainText)
{
    std::string cipherText = "";


    for (size_t i = 0; i < plainText.length(); i++)
    {
        char character = plainText[i];
        int pos;
            
        Rotation();
        
        pos = TranslateCharacter(&character, EnigmaConstants::alphabetLetterOrder, rotorSetting1, 0);
        character = rotorPosition1->letterOrder[pos];

        pos = TranslateCharacter(&character, EnigmaConstants::alphabetLetterOrder, rotorSetting2, rotorSetting1);
        character = rotorPosition2->letterOrder[pos];

        pos = TranslateCharacter(&character, EnigmaConstants::alphabetLetterOrder, rotorSetting3, rotorSetting2);
        character = rotorPosition3->letterOrder[pos];

        pos = TranslateCharacter(&character, EnigmaConstants::alphabetLetterOrder, 0, rotorSetting3);
        character = EnigmaConstants::alphabetLetterOrder[pos];

        pos = TranslateCharacter(&character, EnigmaConstants::reflectorLetterOrder, rotorSetting3, 0);
        character = EnigmaConstants::alphabetLetterOrder[pos];

        pos = TranslateCharacter(&character, rotorPosition3->letterOrder, rotorSetting2, rotorSetting3);
        character = EnigmaConstants::alphabetLetterOrder[pos];

        pos = TranslateCharacter(&character, rotorPosition2->letterOrder, rotorSetting1, rotorSetting2);
        character = EnigmaConstants::alphabetLetterOrder[pos];

        pos = TranslateCharacter(&character, rotorPosition1->letterOrder, 0, rotorSetting1);
        character = EnigmaConstants::alphabetLetterOrder[pos];

        cipherText += character;
    }
    
    std::cout << rotorSetting1 << "\n";
    std::cout << rotorSetting2 << "\n";
    std::cout << rotorSetting3 << "\n";
    return cipherText;
}

void EnigmaMachine::fixPosition(int &pos)
{
    if (pos >= 26)
    {
        pos -= 26;
    }
    if (pos < 0)
    {
        pos += 26;
    }
}

void EnigmaMachine::Rotation()
{
    rotorSetting1 += 1;

    if (Cascade(rotorPosition1, &rotorSetting1))
    {
        rotorSetting2 += 1;
        if (Cascade(rotorPosition2, &rotorSetting2)) {
            rotorSetting3 += 1;
        }
    }
}

bool EnigmaMachine::Cascade(const EnigmaConstants::Rotor* rotor, int* rotorSetting)
{
    bool cascade = false;

    if (*rotorSetting >= 26)
    {
        *rotorSetting -= 26;
    }
    if (*rotorSetting == rotor->notchPosition)
    {
        cascade = true;
    }

    return cascade;
}

int EnigmaMachine::TranslateCharacter(char* character, const std::string rotorLetterOrder, int rotorSettingIn, int rotorSettingOut)
{
    int position = 0;

        position = FindCharacterPosition(rotorLetterOrder, *character);
        position = position + rotorSettingIn - rotorSettingOut;
        fixPosition(position);
    return position;
    
}


int EnigmaMachine::FindCharacterPosition(std::string string, char character1)
{
    char character2;
    for (int i = 0; i < string.length(); i++)
    {
        character2 = string[i];
        if (character2 == character1)
        {
            return i;
        }
    }
    // Flag an error
    return 0;
}