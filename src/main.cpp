#include <raylib.h>
#include <MenuMeta.h>
#include <SimpleStartScreenUI.h>

int main() {
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "OpenField");
  SetTargetFPS(60);

  MenuMeta menuData {};

  SimpleStartScreenUI simple {};
  menuData.add_menu("simple_start", &simple);

  menuData.switch_menu("simple_start");

  while (!WindowShouldClose()) {
      menuData.update();

      BeginDrawing();
      ClearBackground(RAYWHITE);

      menuData.draw2D();

      EndDrawing();
  }

  CloseWindow(); // Close window and OpenGL context

  return 0;
}
