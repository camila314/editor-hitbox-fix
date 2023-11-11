#include <Geode/Geode.hpp>
#include <Geode/modify/GameObject.hpp>

using namespace geode::prelude;

class $modify(MyGameObj, GameObject) {
	void customSetup() {
		GameObject::customSetup();

		if (m_editor) {
			schedule(schedule_selector(MyGameObj::onUpdate));
		}
	}

	void onUpdate(float) {
		if (canRotateFree() && getObjectRadius() == 0) {
			m_oriented = true;
			updateOrientedBox();
		}
	}
};
