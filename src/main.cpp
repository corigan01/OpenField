#include <raylib.h>
#include <UI.h>
#include <SimpleUIElement.h>

int main(void) {
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "OpenField");
  SetTargetFPS(60);

  UI ui {};

  SetTargetFPS(60); // Set our game to run at 60 frames-per-second

  // ----- END ADD YOUR CLASSES HERE ----

  ui.init_all();

  while (!WindowShouldClose())
  {
      ui.updateUI();

      BeginDrawing();
      ClearBackground(RAYWHITE);

      ui.draw2D_all();

      EndDrawing();
  }

  CloseWindow(); // Close window and OpenGL context

  return 0;
}
