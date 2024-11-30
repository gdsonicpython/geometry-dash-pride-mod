#include <Geode/modify/MenuLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

		auto ogLogo = this->getChildByID("main-title");
		if (!ogLogo) return true;

        auto logo = static_cast<CCSprite*>(ogLogo);
		auto pos = logo->getPosition();
		logo->removeMeAndCleanup();

		auto btn = CCMenuItemSpriteExtra::create(logo, this, menu_selector(MyMenuLayer::openGeometryPrideSettings));
		btn->m_scaleMultiplier = 1.075f;
		auto menu = CCMenu::create();
		menu->addChild(btn);
		btn->setPosition(pos);
		menu->setPosition({0, 0});
		this->addChild(menu);

		const int pride = Mod::get()->getSettingValue<int64_t>("pride");
		if (pride >= 0 && pride <= 9) logo->initWithSpriteFrameName(fmt::format("{}.png"_spr, pride).c_str());

        return true;    
	}

	void openGeometryPrideSettings(CCObject* sender) {
		openSettingsPopup(Mod::get());
	}
};
