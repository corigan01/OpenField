//
// Created by Owner on 11/4/2023.
//

#ifndef OPENFIELD_RENDER3DUIELEMENT_H
#define OPENFIELD_RENDER3DUIELEMENT_H


#include "UIElement.h"
#include "MineFieldLogic.h"

class Render3DUIElement : public UIElement  {

private:
    const int screenWidth = 800;
    const int screenHeight = 450;

    VrDeviceInfo device;
    VrStereoConfig config;
    Shader distortion;
    RenderTexture2D target;
    Rectangle sourceRec;
    Rectangle destRec;
    Camera camera;
    Vector3 cubePosition;
    Vector3 cubeSize;

    //store because this doesn't change
    MineFieldLogic::CellPos board_size;


public:
    Render3DUIElement();
    ~Render3DUIElement() = default;

    void draw2D() override;
    void mouse_click(Vector2 pos, MouseEventType button) override;
};


#endif //OPENFIELD_RENDER3DUIELEMENT_H
