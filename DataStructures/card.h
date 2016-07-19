//----------------------------------------------------------
// Class Card 
// author : Iwase Hajime
//----------------------------------------------------------
#ifndef CARD_H
#define CARD_H

//----------------------------------------------------------
// include
//----------------------------------------------------------
#include <iostream>
using namespace std;
//----------------------------------------------------------
// Class Card
//----------------------------------------------------------
class Card{
public:
	static const int MAX_NUM;
	
	typedef enum E_Mark{
		E_Spade = 4,
		E_Dia = 3,
		E_Heart = 2,
		E_Club = 1,
		E_Null = 0,
		E_Joker = 5
	} Mark;

protected:
	Mark mark;
	int num;

public:
	Card();
	Card(const Mark &, const int &);
	Card(const Card &);

	void operator=(const Card &);
	bool operator==(const Card &);
	virtual bool operator<(const Card &);

	Mark get_mark() const;
	int get_num() const;

	void set_mark(const Mark &);
	void set_num(const int &);

	friend ostream& operator<<( ostream& str, Card& c){
		char m;
		switch(c.mark){
			case E_Spade:
				m = 'S';
				break;
			case E_Dia:
				m = 'D';
				break;
			case E_Heart:
				m = 'H';
				break;
			case E_Club:
				m = 'C';
				break;
			case E_Joker:
				m = 'J';
				break;
			default:
				m = '-';
				break;
		}
		cout << "["  << m << c.num << "]";
		return str;
	};	
};
#endif