#include <iostream>
#include <string>

#include "olcConsoleGameEngine.h"

class OneLoneCoder_FlappyBird : public olcConsoleGameEngine {
public:
  OneLoneCoder_FlappyBird() {
    m_sAppName = L"FlappyBird;
  }
private:

protected:
  // Called by olcConsoleGameEngine
  virtual bool OnUserCreat() {
    return true;
  }

  // Called by olcConsoleGameEngine
  virtual bool OnUserUpdate(float fElaspedTime) {
    return true;
  }
}

int main() {
  // Use olcConsoleGameEngine dervied app
  game.ConstructConsole(80, 48, 16, 16);
  game.Start();

  return 0;
}
