//
// Camden did this 11/3/2023
//


void Cell::draw2D() {
    // do some drawing depending on the cells state
}


/// <summary>
/// 
/// </summary>
/// <param name="button"></param>
/// <returns></returns>
int Cell::mouse_click(MoueClickButton button) {
    if (isClicked) {
        // return saying that nothing happened
    }
    else if (button == UIElement::MoueClickButton::MOUSE_CLICK_LEFT) {
        // clear if not mine
    }
    else if (button == UIElement::MoueClickButton::MOUSE_CLICK_RIGHT && !isClicked) {
        // flag space
    }
}