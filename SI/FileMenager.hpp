#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <winbase.h>

#include "fileQueue.hpp"

using namespace std;

class FileMenager {

	int killedEnemies=0;
	int fileData=0;

public:
	
	FileMenager() = default;
	~FileMenager() = default;
	
	int getTotalKilled() {
		int sum;

		if (this->fileData > 0)
			return sum = this->fileData + this->killedEnemies;
		else
			return sum = this->killedEnemies;
	}

	void dataLoad(int a) {
		
		this->killedEnemies = -(a-80);
	
	}

	void fileLoader(fifo &queue) {
		
		int it = 0;

		string downloadedD;
		string one_line;

		string trash;
		
		stringstream ss;
		ifstream input_file("config.txt");
		
		while (getline(input_file, one_line)) {
			queue.push_back(one_line);
			
			/*ss << one_line;
			ss >> trash >> trash >> trash >> trash >> downloadedD;*/
			
		}
		

		if (downloadedD.size() > 1)
			this->fileData = stoi(downloadedD);
		else
			cerr << "config.txt is empty";
	}
	void fileMaker(fifo& queue) {
		
		int sum;
		if (this->fileData > 0)
			sum = this->fileData + this->killedEnemies;
		else
			sum = this->killedEnemies;

		SYSTEMTIME st;
		GetSystemTime(&st);

		ofstream output_file;
		output_file.open("config.txt");
		
		if (output_file.is_open()) {
			while (queue.end - queue.begin>1) {
				output_file << queue.getFirst()<< endl;
			}
			output_file << st.wHour + 2 << ":" << st.wMinute << " | " << st.wDay << "." << st.wMonth << "." << st.wYear << " = " << this->killedEnemies <<endl;
			output_file << st.wHour + 2 << ":" << st.wMinute << " | " << st.wDay << "." << st.wMonth << "." << st.wYear << " = " << this->killedEnemies+100<<endl;
			output_file.close();
		}
	}
};

