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
	std::cout << "feature colors=1\n";
	log.write("Sent: feature colors=1\n");

	std::cin >>  s; // now we should get accepted collors
	log.write("Received: ");
	log.write(s);
	std::cin >>  s;
	log.write(s);
	log.write("\n");

	// now we take the new game parameters
	
	log.write("Received: ");
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