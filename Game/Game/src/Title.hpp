
# pragma once
# include "Common.hpp"

// タイトルシーン
class Title : public MyApp::Scene
{
private:

	Array<HitsujiGUI::Button> m_buttons;

public:

	Title(const InitData& init);

	void update() override;

	void draw() const override;
};
