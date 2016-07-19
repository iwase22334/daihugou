//----------------------------------------------------------
// Class DCard 
// author : Iwase Hajime
//----------------------------------------------------------
//----------------------------------------------------------
// include
//----------------------------------------------------------
#include <iostream>
#include <list>
#include <array>

#include "DataStructures/card.h"
#include "DataStructures/DCard.h"
#include "DataStructures/hand.h"
#include "DataStructures/CardTable.h"

//----------------------------------------------------------
// Main entry point of this program
//----------------------------------------------------------
int main(){
	Hand hand;
	CTablei itable(1);
	CTablei itable2(1);
	CTablei itable3(0);
	list<Card::Mark> mark_list{
		Card::E_Spade,
		Card::E_Dia,
		Card::E_Heart,
		Card::E_Club
	};

	for(int i = 1; i < Card::MAX_NUM + 1; ++ i){
		list<Card::Mark>::iterator it = mark_list.begin();
		while(it != mark_list.end()){
			hand.push_back(DCard((*it), i));
			++ it;
		}
	}
	hand.push_back(DCard(Card::E_Joker, 1));
	hand.push_back(DCard(Card::E_Joker, 2));

	cout << hand << endl;

	hand.sort();

	cout << hand << endl;

	cout << itable << endl;
	for(int i = 1; i < Card::MAX_NUM + 1; ++ i){
		list<Card::Mark>::iterator it = mark_list.begin();
		while(it != mark_list.end()){
			itable = itable - DCard((*it), i);
			cout << itable << endl;
			++ it;
		}
	}
	return 0;
}