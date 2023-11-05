//
// Created by Owner on 11/4/2023.
//

#include "Render3DUIElement.h"

Render3DUIElement::Render3DUIElement() {
    Camera camera = {0};
    camera.position = (Vector3) {5.0f, 2.0f, 5.0f};    // Camera position
    camera.target = (Vector3) {0.0f, 2.0f, 0.0f};      // Camera looking at point
    camera.up = (Vector3) {0.0f, 1.0f, 0.0f};          // Camera up vector
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type
}


void draw2D() {
    // draw 3D lol
}