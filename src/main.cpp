#include <Geode/Geode.hpp>
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>

class $modify(MyMenuLayer, MenuLayer) {
	struct Fields{
		int m_wokeness;
	};
    bool init() {

        if (!MenuLayer::init()) {
            return false;
        }

        m_fields->m_wokeness = Mod::get()->getSettingValue<int64_t>("pride");

        auto logo = static_cast<CCSprite*>(this->getChildByID("main-title"));
		auto pos = logo->getPosition();
		logo->removeMeAndCleanup();

		auto btn = CCMenuItemSpriteExtra::create(logo, this, menu_selector(MyMenuLayer::openSettings));
		btn->m_scaleMultiplier = 1.075f;
		auto menu = CCMenu::create();
		menu->addChild(btn);
		btn->setPosition(pos);
		menu->setPosition({0, 0});
		this->addChild(menu);

        switch (m_fields->m_wokeness) {
			case 0:
				logo->initWithSpriteFrameName("0.png"_spr);
				break;
			case 1:
				logo->initWithSpriteFrameName("1.png"_spr);
				break;
			case 2:
				logo->initWithSpriteFrameName("2.png"_spr);
				break;
			case 3:
				logo->initWithSpriteFrameName("3.png"_spr);
				break;
			case 4:
				logo->initWithSpriteFrameName("4.png"_spr);
				break;
			case 5:
				logo->initWithSpriteFrameName("5.png"_spr);
				break;
			case 6:
				logo->initWithSpriteFrameName("6.png"_spr);
				break;
			case 7:
				logo->initWithSpriteFrameName("7.png"_spr);
				break;
			case 8:
				logo->initWithSpriteFrameName("8.png"_spr);
				break;
			case 9:
				logo->initWithSpriteFrameName("9.png"_spr);
				break;
		};
        return true;    
	}

	void openSettings(CCObject* sender) {
		openSettingsPopup(Mod::get());
	}
};
