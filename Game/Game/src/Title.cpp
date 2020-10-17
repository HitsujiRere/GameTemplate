
# include "Title.hpp"

Title::Title(const InitData& init)
	: IScene(init)
{
	m_buttons << HitsujiGUI::Button(
		Rect(Arg::center = Scene::Center().movedBy(0, 0), { 300, 60 }), 
		[&]() { changeScene(State::Game); },
		U"はじめる"
	);

	m_buttons << HitsujiGUI::Button(
		Rect(Arg::center = Scene::Center().movedBy(0, 100), { 300, 60 }), 
		[&]() { System::Exit(); },
		U"おわる"
	);
}

void Title::update()
{
	m_buttons.each([](HitsujiGUI::Button& button) { button.update(); });
}

void Title::draw() const
{
	const String titleText = U"ブロックくずし";
	const Vec2 center(Scene::Center().x, 120);
	FontAsset(U"Title")(titleText).drawAt(center.movedBy(4, 6), ColorF(0.0, 0.5));
	FontAsset(U"Title")(titleText).drawAt(center);

	m_buttons.each([](const HitsujiGUI::Button& button) { button.draw(); });

	Rect(0, 500, Scene::Width(), Scene::Height() - 500)
		.draw(Arg::top = ColorF(0.0, 0.0), Arg::bottom = ColorF(0.0, 0.5));

	const int32 highScore = getData().highScore;
	FontAsset(U"Score")(U"High score: {}"_fmt(highScore)).drawAt(Vec2(620, 550));
}
