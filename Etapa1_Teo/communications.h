#ifndef COMMUNICATIONS_H
#define COMMUNICATIONS_H

#define DEBUG 1

#include <bits/stdc++.h>

class Log {

	std::ofstream out;

public:
	Log() {
		out = std::ofstream("log.txt");
	}

	~Log() {
		out.close();
	}

	void inline write(std::string msg)  __attribute__((always_inline)) {
#if DEBUG	
		out << msg;
		out.flush();
#endif	
	}
};

#endif