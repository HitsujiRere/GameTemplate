
# include "HitsujiGUI_Button.hpp"

void HitsujiGUI::Button::update()
{
	transition.update(rect.mouseOver());

	if (rect.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	if (rect.leftClicked())
	{
		eventClicked();
	}
}

void HitsujiGUI::Button::draw() const
{
	rect.draw(ColorF(1.0, transition.value())).drawFrame(2);

	FontAsset(U"Menu")(text).drawAt(rect.center(), ColorF(0.25));
}
