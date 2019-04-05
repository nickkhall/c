#include "../headers/Game.hpp"

bool Game::GetIsGameOver() {
  return IsGameOver;
}

bool Game::SetIsGameOver() {
  IsGameOver = true;
  return IsGameOver;
}

// Render top corners and ceiling of intro
void Game::RenderIntroCeiling() {
  int MapWidth = MapInstance->GetMapWidth();

  for (int i = 0; i <= MapWidth; i++) {
    if (i == 0) {
      Intro += "\u250C";
    } else if (i == MapWidth) {
      Intro += "\u2510";
    } else {
      Intro += "\u2500";
    }
  }

  Intro += "\n";
  return;
}

// Render walls and text of intro
void Game::RenderIntroText() {
  int MapHeight = MapInstance->GetMapHeight();
  int MapWidth = MapInstance->GetMapWidth();

  for (int walls = 0; walls <= MapHeight / 100; walls ++) {
    for (int w = 0; w <= MapWidth; w++) {
      if (w == 0 || w == MapWidth - 24) {
        Intro += "\u2502";
      } else if (w == MapWidth / 3) {
        Intro += "Welcome to the Snake Game";
      } else {
        Intro += " ";
      }
    }

    Intro += "\n";
  }

  return;
}

// Render the floor of the intro
void Game::RenderIntroFloor() {
  int MapWidth = MapInstance->GetMapWidth();

  for (int floor = 0; floor <= MapWidth; floor++) {
    if (floor == 0) {
      Intro += "\u2514";
    } else if (floor == MapWidth) {
      Intro += "\u2518";
    } else {
      Intro += "\u2500";
    }
  }
  return;
}

void Game::SetIntro() {
  RenderIntroCeiling();
  RenderIntroText();
  RenderIntroFloor();
  return;
}

std::string Game::PrintIntro() {
  return Intro;
}

std::string Game::GetKeyPressed() {
  return KeyPressed;
}

void Game::SetKeyPressed() {
  KeyPlayerPressed = getch();

  if (KeyPlayerPressed > -1) {
    switch (KeyPlayerPressed) {
      case UpKey:
        NewSnake.MoveUp();
        break;
      case DownKey:
        NewSnake.MoveDown();
        break;
      case LeftKey:
        NewSnake.MoveLeft();
        break;
      case RightKey:
        NewSnake.MoveRight();
        break;
      case EscapeKey:
        SetIsGameOver();
        break;

      default:
        // refresh();
        break;
    }
  } else {
    // refresh();
  }

  return;
}

void Game::ReRenderMap() {
  IncrementGameCounter();

  getmaxyx(stdscr, row, col);
  refresh();

  MapInstance->GenerateMap(row, col);

  if(GetGameCounter() == 100) {
    ResetGameCounter();
    NewSnake.Move();
  }

  return;
}

int Game::GetGameCounter() {
  return GameCounter;
}

void Game::IncrementGameCounter() {
  GameCounter = GameCounter + 1;
  return;
}

void Game::ResetGameCounter() {
  GameCounter = 0;
  return;
}

void Game::MoveSnake() {
  NewSnake.MoveLeft();
  return;
}

std::string Game::GetGameOverText() {
  return GameOverText;
};
