#include "communications.h"

int protocol_begin(Log &log) {
	std::string s;
	std::cin >>  s; // should be "xboard"
	log.write("Received: ");
	log.write(s);
	log.write(" ");

	std::cin >>  s; // should be "protover"
	log.write(s);

	std::cin >>  s; // should be "x" denoting the number of protover
	log.write(" ");
	log.write(s);
	log.write("\n");

	//TO_DO
	// now we can send the features
	std::cout << "feature color=1\n";
	log.write("Sent: feature color=1\n");

	// now we take the new game parameters
	std::cin >>  s;
	log.write("Received: ");
	log.write(" ");
	log.write(s);

	std::cin >>  s;
	log.write(" ");
	log.write(s);

	std::cin >>  s;
	log.write(" ");
	log.write(s);

	std::cin >>  s;
	log.write(" ");
	log.write(s);

	std::cin >>  s;
	log.write(" ");
	log.write(s);

	std::cin >>  s;
	log.write(" ");
	log.write(s);

	return 1;
}