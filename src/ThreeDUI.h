//
// Created by Owner on 11/5/2023.
//

#include <UI.h>
#include "Render3DUIElement.h"

class ThreeDUI : public UI {
private:
    Render3DUIElement element = Render3DUIElement();
public:
    ThreeDUI();
    ~ThreeDUI() = default;
    const char* finished_event_control() override;
};

