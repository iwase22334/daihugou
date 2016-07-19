//----------------------------------------------------------
// Class Daihugo Card 
// author : Iwase Hajime
//----------------------------------------------------------
#ifndef D_CARD_H
#define D_CARD_H
#include"card.h"
//----------------------------------------------------------
// Class Card
//----------------------------------------------------------
class DCard : public Card{
public:
	static const int STRONGEST_NUM;
public:
	DCard(const Mark &, const int &);
	DCard(const DCard &);
	virtual bool operator<(const Card &);
};
#endif