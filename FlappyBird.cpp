#include <iostream>
#include <string>

#include "olcConsoleGameEngineSDL.h"

class OneLoneCoder_FlappyBird : public olcConsoleGameEngine {
public:
  OneLoneCoder_FlappyBird() {
    m_sAppName = L"FlappyBird;
  }
private:
  float fBirdPosition = 0.0f;
  float fBirdVelocity = 0.0f;
  float fBirdAcceleration = 0.0f;

  float fGravity = 100.0f;

protected:
  // Called by olcConsoleGameEngine
  virtual bool OnUserCreate() {
    return true;
  }

  // Called by olcConsoleGameEngine
  virtual bool OnUserUpdate(float fElaspedTime) {
    if (m_keys[VK_SPACE].bPressed) {
      fBirdAcceleration = 0.0f;
      fBirdVelocity = -fGravity / 4.0f;
    }
    else {
      fBirdAcceleration += fGravity * fElapsedTime;
    }
    if (fBirdAcceleration >= fGravity) {
      fBirdAcceleration = fGravity;
    }

    fBirdVelocity += fBirdAcceleration * fElaspedTime;
    fBirdPosition += fBirdVelocity * fElapsedTime;

    Fill(0, 0, ScreenWidth(), ScreenHeight(), L' ');

    int nBirdx = (int)(ScreenWidth() / 3.0f)

    // Draw Bird
    if (fBirdVelocity > 0) {
      DrawString(nBirdX, fBirdPosition + 0, L"\\\\\\");
      DrawString(nBirdX, fBirdPosition + 1, L"<\\\\\\=Q");
    }
    else {
      DrawString(nBirdX, fBirdPosition + 0, L"<///=Q");
      DrawString(nBirdX, fBirdPosition + 1, L"///");
    }

    return true;
  }
}

int main() {
  // Use olcConsoleGameEngine dervied app
  game.ConstructConsole(80, 48, 16, 16);
  game.Start();

  return 0;
}
