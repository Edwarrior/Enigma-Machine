#include<string>
#include"EnigmaConstants.h"

#ifndef ENIGMAOPERATION_H_
#define ENIGMAOPERATION_H_


class EnigmaMachine
{

  public:
    EnigmaMachine();

    ~EnigmaMachine();

    void Configure(const EnigmaConstants::Rotor* rotorPosition1, const EnigmaConstants::Rotor* rotorPosition2, const EnigmaConstants::Rotor* rotorPosition3, int initialRotorSetting1, int initialRotorSetting2, int initialRotorSetting3);

    std::string Encrypt(std::string plainText);


  private:

    void Rotation();
    bool Cascade(const EnigmaConstants::Rotor* rotor, int* rotorSetting);
    int TranslateCharacter(char* character, const std::string rotorLetterOrder, int rotorSettingIn, int rotorSettingOut);
    void fixPosition(int &pos);
    int FindCharacterPosition(std::string string, char character1);

    const EnigmaConstants::Rotor* rotorPosition1;
    const EnigmaConstants::Rotor* rotorPosition2;
    const EnigmaConstants::Rotor* rotorPosition3;
    
    int rotorSetting1;
    int rotorSetting2;
    int rotorSetting3;

};




#endif
