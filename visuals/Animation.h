#pragma once
#include "raylib.h"
#include "raymath.h"

struct AnimatedPos {
    Vector2 current;
    Vector2 target;
    float speed; // pixels per frame

    void Update() {
        Vector2 delta = { target.x - current.x, target.y - current.y };
        if (Vector2Length(delta) < speed) {
            current = target;
        } else {
            Vector2 dir = Vector2Normalize(delta);
            current.x += dir.x * speed;
            current.y += dir.y * speed;
        }
    }
};