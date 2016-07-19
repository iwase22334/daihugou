//----------------------------------------------------------
// Class DCard 
// author : Iwase Hajime
//----------------------------------------------------------
//----------------------------------------------------------
// include
//----------------------------------------------------------
#include "DCard.h"

const int DCard::STRONGEST_NUM(2);

DCard::DCard(const Mark & m, const int & n) : Card(m, n){};
DCard::DCard(const DCard & d) : Card(d){};
//----------------------------------------------------------
// Operator
//----------------------------------------------------------
bool DCard::operator<(const Card & c){
	bool rval = false;
	// Same Card
	if( *this == c ){
		rval = false;
	}

	// Joker is strongest card
	else if(mark == E_Joker){
		rval = false;
	}
	else if(c.get_mark() == E_Joker){
		rval = true;
	}

	// Same number
	else if(num == c.get_num()){
		rval = mark < c.get_mark();
	}

	// Number check
	else{
		rval = (((num + (Card::MAX_NUM - STRONGEST_NUM))) % (Card::MAX_NUM + 1)) < (((c.get_num() + (Card::MAX_NUM - STRONGEST_NUM ))) % (Card::MAX_NUM + 1));
	}
	return rval;
};