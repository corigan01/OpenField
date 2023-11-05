//
// Created by Owner on 11/4/2023.
//

#ifndef OPENFIELD_RENDER3DUIELEMENT_H
#define OPENFIELD_RENDER3DUIELEMENT_H


#include "UIElement.h"

class Render3DUIElement : public UIElement  {
public:
    Render3DUIElement();
    ~Render3DUIElement() = default;

    void draw2D();
};


#endif //OPENFIELD_RENDER3DUIELEMENT_H
