#include "Item.h"

void Item::bindSprite(Sprite* pSprite)
{
    m_pSprite = pSprite;
    this->addChild(m_pSprite);
}

//Ϊweapon��ӽ���������ɾ������������ԭ�����ĳɴ��麯��
void Item::interact()
{
	return;
}

bool Item::voidOnContactPreSolve(PhysicsContact& contact)
{
	return false;
}
