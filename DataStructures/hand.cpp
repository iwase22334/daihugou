//----------------------------------------------------------
// Class Hand
// author : Iwase Hajime
//----------------------------------------------------------
//----------------------------------------------------------
// include
//----------------------------------------------------------
#include "hand.h"

//----------------------------------------------------------
// Constructor
//----------------------------------------------------------
Hand::Hand(const list<DCard> & cl) : card_list(cl) {};
Hand::Hand(const Hand & h) : card_list(h.card_list) {};

//----------------------------------------------------------
// list handler
//----------------------------------------------------------
void Hand::push_front(const DCard & c) { card_list.push_front(c); };
void Hand::push_back(const DCard & c) { card_list.push_back(c); };
DCard & Hand::front() { return card_list.front(); };
DCard & Hand::back() { return card_list.front(); };

//----------------------------------------------------------
//  Getter
//----------------------------------------------------------
int Hand::size() const { return card_list.size(); };

list<DCard>& Hand::get_card_list(){ return card_list; };
list< list<DCard*> >& Hand::get_two_list(){ return two_list; };
list< list<DCard*> >& Hand::get_three_list(){ return three_list; };
list< list<DCard*> >& Hand::get_four_list(){ return four_list; };
list< list<DCard*> >& Hand::get_stairs_list(){ return stairs_list; };

//----------------------------------------------------------
//  Other functions
//----------------------------------------------------------
void Hand::sort(){
	card_list.sort();
	{// Search same mark cards
		list<DCard*> card_buf;
		list<DCard>::iterator it = card_list.begin();
		while(it != card_list.end()){
			if(card_buf.size() == 0){
				card_buf.push_back(&(*it));
			}
			else if((card_buf.back()->get_num()) == (*it).get_num()){
				card_buf.push_back(&(*it));
				switch(card_buf.size()){
					case 2:
						two_list.push_back(card_buf);
						break;
					case 3:
						three_list.push_back(card_buf);
						break;
					case 4:
						four_list.push_back(card_buf);
						break;
					default:
						break;
				}
			}
			else{
				card_buf.clear();
				card_buf.push_back(&(*it));
			}
			++ it;
		}
	}
	{// Search stairs
		/*list<DCard*> card_buf;
		list<DCard>::iterator it = card_list.begin();
		while(it != card_list.end()){
			list<DCard>::iterator it_search = it;
			++ it_search;
			for(int stair_num = 1;;++ i){
				while((*it_search).get_mark() == (*it).get_mark() || it_search == card_list.end()){
					++ it_search;
				}
				if(it_search == card_list.end() || (*it_search).get_num() != (i + (*it).get_num())){
					break;
				}
				else if(){

				}
			}
			++ it;
		}*/
	}
	
};

ostream& operator<<(ostream& str, Hand& h){
	list<DCard>::iterator it = h.card_list.begin();
	while(it != h.card_list.end()){
		cout << (*it);
		++ it;
	}
	cout << endl;
	return str;
};