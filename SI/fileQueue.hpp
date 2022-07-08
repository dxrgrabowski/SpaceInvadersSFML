#pragma once
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class fifo {
private:
	bool oneElement; 

	struct oneline {
		string element;
		oneline* nastepny = nullptr;
	};
	oneline* b = nullptr;
	oneline* e = nullptr;
	oneline* el = nullptr;
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

	friend ostream& operator<<(ostream& output, fifo& queue) {
		queue.el = queue.b;
		queue.b = queue.b->nastepny;
		++queue.begin;
		output << queue.b->element << endl;
		return output;
	};

	unsigned int size() { return end - begin; }

	void push_back(string x)
	{
		if (oneElement)
		{
			e = new oneline;   
			e->element = x; 
			b = new oneline; 		
			b->nastepny = e; 
			oneElement = 0;
		}
		else
		{
			el = new oneline;   
			el->element = x;	
			e->nastepny = el;	
			e = el;				
		}
		end++;
	}

	unsigned int begin, end;

};