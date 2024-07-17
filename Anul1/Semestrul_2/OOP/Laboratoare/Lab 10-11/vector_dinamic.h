#pragma once
#define INITIAL_CAPACITY 2
template <typename Tip>
class iterator_vector;

template <typename Tip>
class vectorul_meu
{
public:
	/*
	Constructor default
	Alocam loc pentru 5 elemente
	*/
	vectorul_meu();

	/*
	Constructor de copiere
	*/
	vectorul_meu(const vectorul_meu& ot); //rule of 3

	/*
	Eliberam memoria
	*/
	~vectorul_meu();//rule of 3

	/*
	Operator assgnment
	elibereaza ce era in obiectul curent (this)
	aloca spatiu pentru elemente
	copieaza elementele din ot in this
	*/
	vectorul_meu& operator=(const vectorul_meu& ot);//rule of 3


	/*
	Move constructor
	Apelat daca construim un nou vector dintr-un r-value (ex temporary, expresie de la return)
	Obiectul ot nu se mai foloseste astfel se poate refolosi interiorul lui
	*/
	vectorul_meu(vectorul_meu&& ot); //rule of 5 

	/*
	Move assignment
	Similar cu move constructor
	Folosit la assignment
	*/
	vectorul_meu& operator=(vectorul_meu&& ot); //rule of 5 

	void add(const Tip& el);

	Tip& get(int poz) const;

	void set(int poz, const Tip& el);

	int size() const noexcept;

	friend class iterator_vector<Tip>;
	//functii care creaza iteratori
	iterator_vector<Tip> begin();
	iterator_vector<Tip> end();


	void erase(iterator_vector<Tip> poz);

private:
	int lg;
	int cap;
	Tip* elems;

	void ensureCapacity();
};

template<typename Tip>
vectorul_meu<Tip>::vectorul_meu() :elems{ new Tip[INITIAL_CAPACITY] }, cap{ INITIAL_CAPACITY }, lg{ 0 } {}

template<typename Tip>
vectorul_meu<Tip>::vectorul_meu(const vectorul_meu<Tip>& ot) {
	elems = new Tip[ot.cap];
	for (int i = 0; i < ot.lg; i++) {
		elems[i] = ot.elems[i]; 
	}
	lg = ot.lg;
	cap = ot.cap;
}


template<typename Tip>
vectorul_meu<Tip>& vectorul_meu<Tip>::operator=(const vectorul_meu<Tip>& ot) {
	if (this == &ot) {
		return *this;//s-a facut l=l;
	}
	delete[] elems;
	elems = new Tip[ot.cap]; 
	//copiez elementele
	for (int i = 0; i < ot.lg; i++) {
		elems[i] = ot.elems[i];
	}
	lg = ot.lg;
	cap = ot.cap;
	return *this;
}

template<typename Tip>
vectorul_meu<Tip>::~vectorul_meu() {
	delete[] elems;
}


/*
Move constructor
Apelat daca construim un nou vector dintr-un r-value (ex temporary)
Obiectul ot nu se mai foloseste astfel se poate refolosi interiorul lui
*/
template<typename Tip>
vectorul_meu<Tip>::vectorul_meu(vectorul_meu&& ot) {
	// Copy the data pointer from other
	elems = ot.elems;
	lg = ot.lg;
	cap = ot.cap;

	// Release the data pointer from the source object so that  
	// the destructor does not free the memory multiple times.  
	ot.elems = nullptr;
	ot.lg = 0;
	ot.cap = 0;
}

/*
Move assignment
Similar cu move constructor
Folosit la assignment
Elibereaza ce continea obiectul curent (this)
"fura" interiorul lui ot
pregateste ot pentru distrugere
*/
template<typename Tip>
vectorul_meu<Tip>& vectorul_meu<Tip>::operator=(vectorul_meu<Tip>&& ot) {
	if (this == &ot) {
		return *this;
	}
	delete[] elems;
	// Copy the data pointer from other
	elems = ot.elems;
	lg = ot.lg;
	cap = ot.cap;

	// Release the data pointer from the source object so that  
	// the destructor does not free the memory multiple times.  
	ot.elems = nullptr;
	ot.lg = 0;
	ot.cap = 0;
	return *this;
}

template<typename Tip>
void vectorul_meu<Tip>::add(const Tip& el) {
	ensureCapacity();//daca e nevoie mai alocam memorie
	elems[lg++] = el;
}

template<typename Tip>
void vectorul_meu<Tip>::erase(iterator_vector<Tip> poz) {

	iterator_vector<Tip> it = this->begin();
	int indice, i = 0;
	for (it; it != this->end(); ++it)
	{
		if (it == poz)
		{
			indice = i;
			break;
		}
		else
			i++;
	}
	for (int i = indice; i < this->size() - 1; i++)
	{
		this->elems[i] = this->elems[i + 1];
	}
	this->lg--;
}

template<typename Tip>
Tip& vectorul_meu<Tip>::get(int poz) const {
	return elems[poz - 1];
}

template<typename Tip>
void vectorul_meu<Tip>::set(int poz, const Tip& el) {
	elems[poz] = el;
}

template<typename Tip>
int vectorul_meu<Tip>::size() const noexcept {
	return lg;
}

template<typename Tip>
void vectorul_meu<Tip>::ensureCapacity() {
	if (lg < cap) {
		return; //mai avem loc
	}
	cap *= 2;
	Tip* aux = new Tip[cap];
	for (int i = 0; i < lg; i++) {
		aux[i] = elems[i];
	}
	delete[] elems;
	elems = aux;
}

template<typename Tip>
iterator_vector<Tip> vectorul_meu<Tip>::begin()
{
	return iterator_vector<Tip>(*this);
}

template<typename Tip>
iterator_vector<Tip> vectorul_meu<Tip>::end()
{
	return iterator_vector<Tip>(*this, lg);
}

template<typename Tip>
class iterator_vector {
private:
	const vectorul_meu<Tip>& v;
	int poz = 0;
public:
	iterator_vector(const vectorul_meu<Tip>& v) noexcept;
	iterator_vector(const vectorul_meu<Tip>& v, int poz)noexcept;
	bool valid()const;
	Tip& element() const;
	void next();
	Tip& operator*();
	iterator_vector& operator++();
	bool operator==(const iterator_vector& ot)noexcept;
	bool operator!=(const iterator_vector& ot)noexcept;
};

template<typename Tip>
iterator_vector<Tip>::iterator_vector(const vectorul_meu<Tip>& v) noexcept :v{ v } {}

template<typename Tip>
iterator_vector<Tip>::iterator_vector(const vectorul_meu<Tip>& v, int poz)noexcept : v{ v }, poz{ poz } {}

template<typename Tip>
bool iterator_vector<Tip>::valid()const {
	return poz < v.lg;
}

template<typename Tip>
Tip& iterator_vector<Tip>::element() const {
	return v.elems[poz];
}

template<typename Tip>
void iterator_vector<Tip>::next() {
	poz++;
}

template<typename Tip>
Tip& iterator_vector<Tip>::operator*() {
	return element();
}

template<typename Tip>
iterator_vector<Tip>& iterator_vector<Tip>::operator++() {
	next();
	return *this;
}

template<typename Tip>
bool iterator_vector<Tip>::operator==(const iterator_vector<Tip>& ot) noexcept {
	return poz == ot.poz;
}

template<typename Tip>
bool iterator_vector<Tip>::operator!=(const iterator_vector<Tip>& ot)noexcept {
	return !(*this == ot);
}

