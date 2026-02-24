#pragma once //makes it so that this header file is only included once

#include "raylib.h" //raylib header file for graphic functions
#include "raymath.h" //header file for raylib math functions

//structure for handling smooth animations
struct AnimatedPos{
    Vector2 current; //current position at the screen
    Vector2 target; //target position, where the object should move to
    float speed; //pixels per frame, how fast the object should move

    //updating the current position to target position
    void Update(){
        //calculate the distance to move
        Vector2 delta = { target.x - current.x, target.y - current.y };
        
        //if the distance is small enough then move to the target
        if (Vector2Length(delta) < speed){
            current = target;
        }

        else{
            //otherwise move one step to target
            Vector2 dir = Vector2Normalize(delta); //gets unit vector pointing from current to target
            current.x += dir.x * speed; //moves current x one step close
            current.y += dir.y * speed; //moves current y one step closer
        }
    }
};