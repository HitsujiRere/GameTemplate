
# pragma once
# include "HitsujiGUI.hpp"

class HitsujiGUI::Button
{
public:

	Rect rect;

	Transition transition = Transition(0.4s, 0.2s);

	std::function<void()> eventClicked;

	String text;

	Button(Rect _rect, std::function<void()> _eventClicked, String _text = U"")
		: rect(_rect)
		, eventClicked(_eventClicked)
		, text(_text) {}

	void update();

	void draw() const;
};
