//----------------------------------------------------------
// Class CardTable
// author : Iwase Hajime
//----------------------------------------------------------
//----------------------------------------------------------
// include
//----------------------------------------------------------
#include <iostream>
//----------------------------------------------------------
// Card Table
//----------------------------------------------------------
template<int M = 13, int N = 5, typename Tp = int>
class CardTable{
private:
	Tp table[M * N];
	int size_x;
	int size_y;

public:
	CardTable<M , N, Tp>();
	CardTable<M , N, Tp>(const Tp);
	CardTable<M , N, Tp>(const CardTable<M, N, Tp> &);

	int get_size_x() const;
	int get_size_y() const;

	Tp& operator[](const int);
	Tp& operator[](const Card &);

	CardTable<M, N, Tp> operator-(const Card &);
	CardTable<M, N, Tp> operator-(const CardTable<M, N, Tp> &);

	CardTable<M, N, Tp> operator+(const Card &);
	CardTable<M, N, Tp> operator+(const CardTable<M, N, Tp> &);

	void operator=(const CardTable<M, N, Tp> &);

	void operator-=(const Card &);
	void operator-=(const CardTable<M, N, Tp> &);

	void operator+=(const Card &);
	void operator+=(const CardTable<M, N, Tp> &);

	friend ostream& operator<<(ostream& str, CardTable<M, N, Tp>& ct){
		for(int i = 0; i < ct.size_y; ++ i){
			for(int j = 0; j < ct.size_x; ++ j){
				cout << ct.table[j + i * (ct.size_x)] << " ";
			}
			cout << endl;
		}
		return str;
	};
private:
	int get_index(const Card &) const;
	int get_index(const Card::Mark, const int) const;

};

//----------------------------------------------------------
// Include Implementation 
//----------------------------------------------------------
#include "CardTable.cpp" 

//----------------------------------------------------------
// Instanciation
//----------------------------------------------------------
template class CardTable<13, 5, int>;
template class CardTable<13, 5, double>;

//----------------------------------------------------------
// New name
//----------------------------------------------------------
typedef CardTable<13, 5, int> CTablei;
typedef CardTable<13, 5, double> CTabled;
 