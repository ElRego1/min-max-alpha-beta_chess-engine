#ifndef COMMUNICATIONS_H
#define COMMUNICATIONS_H

#define DEBUG 1

#include <bits/stdc++.h>


// object for logging the communications
class Log {
	std::ofstream out;
public:
	Log() {
#if DEBUG
		out = std::ofstream("log.txt");
#endif
	}

	~Log() {
#if DEBUG
		out.close();
#endif
	}

	[[gnu::always_inline]] inline
	void write(std::string msg) {
#if DEBUG
		out << msg;
		out.flush();
#endif
	}
};

int protocol_begin(Log &log);

#endif
