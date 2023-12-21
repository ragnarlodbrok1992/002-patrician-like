#include <iostream>
#include <string>

#include "raylib.h"

static int RESOLUTION_FACTOR = 120;
static int SCREEN_WIDTH = 16 * RESOLUTION_FACTOR;
static int SCREEN_HEIGHT = 9 * RESOLUTION_FACTOR;
static const char* ENGINE_TITLE_BAR = "Patrician Clone - alpha version.";
static int TARGET_FPS = 60;
static bool FULLSCREEN = true;

int main(int argc, char* argv[]) {
  // Avoiding unused parameter warnings
  (void) argc;
  (void) argv;

  // Starting code
  std::cout << "[INFO] Resolution - width: " << SCREEN_WIDTH << " height: " << SCREEN_HEIGHT << std::endl;
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, ENGINE_TITLE_BAR);

  SetTargetFPS(TARGET_FPS);

  while (!WindowShouldClose()) {
    BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawText("Patrician Clone", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
  }

  CloseWindow();

  // All went well - exiting
  std::cout << "Program exited successfully." << std::endl;
  return 0;
}

