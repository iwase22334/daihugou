//----------------------------------------------------------
// Class Hand
// author : Iwase Hajime
//----------------------------------------------------------
#ifndef HAND_H
#define HAND_H
//----------------------------------------------------------
// include
//----------------------------------------------------------
#include <list>
#include "DCard.h"
//----------------------------------------------------------
// Class Hand
//----------------------------------------------------------
using namespace std;

class Hand{
private:
	list<DCard> card_list;
	list< list<DCard*> > two_list;
	list< list<DCard*> > three_list;
	list< list<DCard*> > four_list;
	list< list<DCard*> > stairs_list;

public:
	Hand(){};
	Hand(const list<DCard> &);
	Hand(const Hand &);

	int size() const;

	void push_front(const DCard &);
	void push_back(const DCard &);
	DCard & front();
	DCard & back();

	list<DCard>& get_card_list();
	list< list<DCard*> >& get_two_list();
	list< list<DCard*> >& get_three_list();
	list< list<DCard*> >& get_four_list();
	list< list<DCard*> >& get_stairs_list();

	void sort();

	friend ostream& operator<<(ostream&, Hand&);
};

#endif