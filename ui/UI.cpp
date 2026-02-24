#include "UI.h" //includes the UI header file

//draw button with hover and active highlight
bool DrawButton(Button &btn) {
    Vector2 mouse = GetMousePosition(); //gets the current mouse position
    bool hover = CheckCollisionPointRec(mouse, btn.rect); //check if mouse is over button

    //changes the color of the button based on its state, if its active or the mouse is hovering on it
    Color border = btn.active ? BLUE : (hover ? Fade(BLUE, 0.8f) : Fade(BLUE, 0.5f));
    Color bg     = btn.active ? Fade(BLUE, 0.25f) : (hover ? Fade(BLUE, 0.15f) : RAYWHITE);

    DrawRectangleRec(btn.rect, bg); //draw button background
    DrawRectangleLinesEx(btn.rect, 2, border); //draw button borders

    //calculates the width of the button text
    int textWidth = MeasureText(btn.text.c_str(), 18);

    //draws the text on the middle of the button
    DrawText(btn.text.c_str(), btn.rect.x + btn.rect.width/2 - textWidth/2,
             btn.rect.y + 10, 18, DARKBLUE);

    //return true if hovered and left click released
    return hover && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);
}

//drawing the header at top
void DrawHeader(const std::string &title) {
    DrawRectangle(0, 0, GetScreenWidth(), 60, WHITE); //draws a white header bar at top
    DrawText(title.c_str(), 20, 15, 28, DARKBLUE); //draw title text
}

//drawing the side bar at left
void DrawSidebar() {
    DrawRectangle(0, 60, 200, GetScreenHeight(), Fade(BLUE, 0.05f));
}