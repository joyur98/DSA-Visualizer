#include "UI.h"

// Draw button with hover + active highlight
bool DrawButton(Button &btn) {
    Vector2 mouse = GetMousePosition();
    bool hover = CheckCollisionPointRec(mouse, btn.rect);

    Color border = btn.active ? BLUE : (hover ? Fade(BLUE, 0.8f) : Fade(BLUE, 0.5f));
    Color bg     = btn.active ? Fade(BLUE, 0.25f) : (hover ? Fade(BLUE, 0.15f) : RAYWHITE);

    DrawRectangleRec(btn.rect, bg);
    DrawRectangleLinesEx(btn.rect, 2, border);

    int textWidth = MeasureText(btn.text.c_str(), 18);
    DrawText(btn.text.c_str(), btn.rect.x + btn.rect.width/2 - textWidth/2,
             btn.rect.y + 10, 18, DARKBLUE);

    return hover && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);
}

void DrawHeader(const std::string &title) {
    DrawRectangle(0, 0, GetScreenWidth(), 60, WHITE);
    DrawText(title.c_str(), 20, 15, 28, DARKBLUE);
}

void DrawSidebar() {
    DrawRectangle(0, 60, 200, GetScreenHeight(), Fade(BLUE, 0.05f));
}