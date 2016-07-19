//----------------------------------------------------------
// Class Card 
// author : Iwase Hajime
//----------------------------------------------------------
//----------------------------------------------------------
// include
//----------------------------------------------------------
#include "card.h"
//----------------------------------------------------------
// Constant parameter
//----------------------------------------------------------
const int Card::MAX_NUM(13);
//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Card::Card() : mark(E_Null), num (0) {};
Card::Card(const Mark & m, const int & n) : mark(m), num(n) {};
Card::Card(const Card & c) : mark(c.mark), num(c.num) {};

//----------------------------------------------------------
// Operator
//----------------------------------------------------------
void Card::operator=(const Card & c){
	mark = c.mark;
	num = c.num;
};
bool Card::operator==(const Card & c){
	return (mark == c.mark) && (num == c.num);
};
bool Card::operator<(const Card & c){
	bool rval = false;
	// Same Card
	if( *this == c ){
		rval = false;
	}

	// Joker is strongest card
	else if(mark == E_Joker){
		rval = false;
	}
	else if(c.mark == E_Joker){
		rval = true;
	}

	// Same number
	else if(num == c.num){
		rval = mark < c.mark;
	}

	// Number check
	else{
		rval = num < c.num;
	}
	return rval;
};


//----------------------------------------------------------
// Getter
//----------------------------------------------------------
Card::Mark Card::get_mark() const { return mark; };
int Card::get_num() const { return num; };

//----------------------------------------------------------
// Setter
//----------------------------------------------------------
void Card::set_mark(const Mark & m) { mark = m; };
void Card::set_num(const int & n) { num = n; };
