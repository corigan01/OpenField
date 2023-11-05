#include <raylib.h>
#include <MenuMeta.h>
#include <TitleScreenUI.h>
#include <GameScreenUI.h>
#include <WinLoseScreenUI.h>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_MSAA_4X_HINT);

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

    TitleScreenUI titleScreen {};
    menuData.add_menu("title", &titleScreen);

    GameScreenUI play {};
    menuData.add_menu("play", &play);

    WinLoseScreenUI win { true };
    menuData.add_menu("won", &win);

    WinLoseScreenUI lose { false };
    menuData.add_menu("lost", &lose);

    menuData.switch_menu("title");

    while (!WindowShouldClose()) {
      menuData.update();


      BeginDrawing();
      ClearBackground(RAYWHITE);
      menuData.draw2D();

      DrawFPS(10, 10);
      EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}
