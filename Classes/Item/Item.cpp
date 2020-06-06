#include "Item.h"

void Item::bindSprite(Sprite* pSprite)
{
    m_pSprite = pSprite;
    this->addChild(m_pSprite);
}

//为weapon添加交互函数后删掉本函数，把原函数改成纯虚函数
void Item::interact()
{
	return;
}

bool Item::voidOnContactPreSolve(PhysicsContact& contact)
{
	return false;
}
