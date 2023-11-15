#include <Geode/Geode.hpp>
#include <Geode/modify/GameObject.hpp>
#include <UIBuilder.hpp>

using namespace geode::prelude;

class $(GameObject) {
	void customSetup() {
		GameObject::customSetup();

		if (m_editor) {
			Build(this).schedule([=](float) {
				if (this->canRotateFree() && this->getObjectRadius() == 0) {
					m_oriented = true;
					this->updateOrientedBox();
				}
			});
		}
	}
};
