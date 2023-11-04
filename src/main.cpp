#include <raylib.h>
#include <UI.h>
#include <SimpleUIElement.h>

int main() {
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "OpenField");
  SetTargetFPS(60);

  UI ui {};

  // ---- ADD YOUR CLASSES HERE ----
  SimpleElement simple {};
  ui.add_element(&simple);

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
