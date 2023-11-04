#include <raylib.h>
#include <MenuMeta.h>
#include <SimpleStartScreenUI.h>

int main() {
  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "OpenField");
  SetTargetFPS(60);

  MenuMeta menuData {};

  // Cell Drawing Class
  //   - Explored and unexplored cells
  //   - Number of nearby mines  (overlay)
  //   - Flag (overlay)
  // UI Elements Classes
  //   - Draw UI Class
  //     - Draw game board (passed the game board object, loops
  //       to draw each cell with it's correct texture given properties
  //     - Draw buttons (quit game, undo, new game)
  // Sound Trigger Class
  //   - Safe explore sfx
  //   - Danger explore sfx (if explored cell has =< 1 bombs near)
  //   - Flag place sfx
  //   - Bomb explode/game end sfx (will play multiple different
  //     sounds, one on first bomb explode and one for each bomb on
  //     the board, decreasing volume based on distance from first bomb
  //     with random minor pitch shifts

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
