//----------------------------------------------------------
// Class Card  Table
// author : Iwase Hajime
//----------------------------------------------------------
#ifndef CARD_TABLE_H
#define CARD_TABLE_H
//----------------------------------------------------------
// Class Card Table
//----------------------------------------------------------
//----------------------------------------------------------
// Costructor
//----------------------------------------------------------
template<int M, int N, typename Tp>
CardTable<M, N, Tp>::CardTable() : 
	size_x(M), 
	size_y(N){
	for(int i = 0; i < M * N; ++ i){
		table[i] = 0;
	}
};
template<int M, int N, typename Tp>
CardTable<M, N, Tp>::CardTable(Tp init_value) : 
	size_x(M), 
	size_y(N){
	for(int i = 0; i < M * N; ++ i){
		table[i] = init_value;
	}
};
template<int M, int N, typename Tp>
CardTable<M, N, Tp>::CardTable(const CardTable<M , N, Tp> & ct) : 
	size_x(M), 
	size_y(N){
	for(int i = 0; i < M * N; ++ i){
		table[i] = ct.table[i];
	}
};

//----------------------------------------------------------
// Getter
//----------------------------------------------------------
template<int M, int N, typename Tp>
int CardTable<M, N, Tp>::get_size_x() const{ return size_x; };

template<int M, int N, typename Tp>
int CardTable<M, N, Tp>::get_size_y() const{ return size_y; };
//----------------------------------------------------------
// Accessor
//----------------------------------------------------------
template<int M, int N, typename Tp>
Tp& CardTable<M, N, Tp>::operator[](const int x) {
	return table[x];
};
template<int M, int N, typename Tp>
Tp& CardTable<M, N, Tp>::operator[](const Card & c) {
	return table[get_index(c)];
};

//----------------------------------------------------------
// Operator -
//----------------------------------------------------------
template<int M, int N, typename Tp>
CardTable<M, N, Tp> CardTable<M, N, Tp>::operator-(const Card & c){
	CardTable<M, N, Tp> res(*this);
	-- res[get_index(c)];
	return res;
};
template<int M, int N, typename Tp>
CardTable<M, N, Tp> CardTable<M, N, Tp>::operator-(const CardTable<M , N, Tp> & ct ){
	CardTable<M, N, Tp> res(*this);
	for(int i = 0; i < M * N; ++ i){
		res[i] = res[i] - ct.table[i];
	}
	return res;

};

//----------------------------------------------------------
// Operator +
//----------------------------------------------------------
template<int M, int N, typename Tp>
CardTable<M, N, Tp> CardTable<M, N, Tp>::operator+(const Card & c){
	CardTable<M, N, Tp> res(*this);
	++ res[get_index(c)];
	return res;
};
template<int M, int N, typename Tp>
CardTable<M, N, Tp> CardTable<M, N, Tp>::operator+(const CardTable<M , N, Tp> & ct){
	CardTable<M, N, Tp> res(*this);
	for(int i = 0; i < M * N; ++ i){
		res[i] = res[i] + ct.table[i];
	}
	return res;
};
//----------------------------------------------------------
// Operator 
//----------------------------------------------------------
template<int M, int N, typename Tp>
void CardTable<M, N, Tp>::operator=(const CardTable<M, N, Tp> & ct){
	for(int i = 0; i < M * N; ++ i){
		table[i] = ct.table[i];
	}
};
template<int M, int N, typename Tp>
void CardTable<M, N, Tp>::operator-=(const Card & c){
	table[get_index(c.get_mark(), c.get_num())] = 0;
};
template<int M, int N, typename Tp>
void CardTable<M, N, Tp>::operator-=(const CardTable<M , N, Tp> & ct){
	for(int i = 0; i < M * N; ++ i){
		if(ct.table[i] == 1 && table[i] == 1){
			table[i] = 0;
		}
	}
};
template<int M, int N, typename Tp>
void CardTable<M, N, Tp>::operator+=(const Card & c){
	table[get_index(c.get_mark(), c.get_num())] = 1;
};
template<int M, int N, typename Tp>
void CardTable<M, N, Tp>::operator+=(const CardTable<M , N, Tp> & ct){
	for(int i = 0; i < M * N; ++ i){
		if(ct.table[i] == 1 && table[i] == 0){
			table[i] = 1;
		}
	}
};
//----------------------------------------------------------
// Index getter
//----------------------------------------------------------
template<int M, int N, typename Tp>
int CardTable<M, N, Tp>::get_index(const Card & c) const{
	return get_index(c.get_mark(), c.get_num());
}
template<int M, int N, typename Tp>
int CardTable<M, N, Tp>::get_index(const Card::Mark m, const int n) const{
	int row;
	switch(m){
		case Card::E_Spade:
			row = 0;
			break;
		case Card::E_Dia:
			row = 1;
			break;
		case Card::E_Heart:
			row = 2;
			break;
		case Card::E_Club:
			row = 3;
			break;
		case Card::E_Joker:
			row = 4;
			break;
		default:
			break;
	}
	return M * row + (n - 1);
};

#endif