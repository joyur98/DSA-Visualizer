#pragma once //makes it so that it only includes this header file once

#include "raylib.h" //includes raylib for graphic functions
#include <string> // string header file for string functions

//structure for a button
struct Button {
    Rectangle rect; //rectangle shaped button
    std::string text; //text to display on the button
    bool active = false;  //highlights the active button
};

bool DrawButton(Button &btn); //function to draw button

void DrawHeader(const std::string &title); //function to draw the title

void DrawSidebar(); //function to draw the side bar which contains the buttons