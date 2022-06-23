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

	int killedEnemies = 0;
	int fileData = 0;

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

		this->killedEnemies = -(a - 80);

	}

	void fileLoader(fifo& queue) {

		int it = 0;

		bool sessionsFlag=0;
		string downloadedD;
		string sessionLine, recordLine;

		string trash;

		stringstream ss;
		ifstream input_file("sessions.txt");
		ifstream input_record_file("record.txt");

		while (getline(input_file, sessionLine)) {
			queue.push_back(sessionLine);
			sessionsFlag = 1;
		}

		while (getline(input_record_file, recordLine)) {

			ss << recordLine;
			ss >> downloadedD;

		}

		if (downloadedD.size() > 1)
			this->fileData = stoi(downloadedD);
		else
			cerr << "Failed to load record.txt";
		if (!sessionsFlag)
			cerr << "Failed to load sessions.txt";
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
		output_file.open("sessions.txt");

		if (output_file.is_open()) {
			while (queue.end - queue.begin > 0) {
				output_file << queue;
			}

			output_file << st.wHour + 2 << ":" << st.wMinute << " | " << st.wDay << "."
				<< st.wMonth << "." << st.wYear << " = " << this->killedEnemies << endl;

			output_file.close();
		}

		ofstream record_file;
		record_file.open("record.txt");

		if (record_file.is_open()) {


			record_file << sum << endl;

			record_file.close();
		}
	}
};

