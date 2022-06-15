#pragma once

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class fifo {
public:
	fifo() {
		this->begin = 0;
		this->end = 0; 
		this->oneElement = 1;
	}
	~fifo()
	{
		while (end - begin > 0) {
			el = b;
			b = b->nastepny;
			delete el;
			++begin;
		}
		if (!oneElement)
			delete b;
	}
	
	unsigned int size() { return end - begin; }//liczba elementów w kolejce
	
	void push_back(string x)//dodanie elementu na end kolejki
	{
		if (oneElement)//jesli pierwszy element wrzucamy do kolejki
		{
			e = new oneline;    //utworzenie elementu ostatniego
			e->element = x; //przypisanie do niego wartosci
			b = new oneline; 		//utworzenei elemntu pierwszego
			b->nastepny = e;  //element pierwszy wskazuje na ostatni	
			oneElement = 0;
		}
		else
		{
			el = new oneline;    //utworzenie nowego elementu kolejki
			el->element = x;	//przypisanie do niego wartosci
			e->nastepny = el;	//ostatni dotychczas element wskazuje na utworzony
			e = el;				//element utworzony staje siê ostatnim
		}
		end++;
	}
	
	string getFirst()
	{
		
		//if(end - begin>1){}
			el = b;
			b = b->nastepny; //przejscie na nastêpny element kolejki
			++begin;
			return b->element;
	}

	
	unsigned int begin, end; // index
	
private:
	bool oneElement; // czy w kolejce cos ju¿ siê pojawi³o
	
	struct oneline {
		string element;
		oneline* nastepny;
	};
	oneline* b, * e, * el; //begin, end, element
};