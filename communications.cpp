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

	//TODO
	std::vector<std::string> features = {"feature sigint=0", " colors=1", " done=1"};
	for (int i = 0; i < features.size(); ++i) {
		std::cout << features[i] << " ";
		log.write("Sent: ");
		log.write(features[i]);
	}
	std::cout << "\n";

	for (int i = 0; i < features.size(); ++i) {
		std::cin >>  s;
		log.write("Received: ");
		log.write(s);
		log.write(" ");
		std::cin >>  s;
		log.write(s);
		log.write("\n");
	}
	// now we can send the features
	// std::cout << "feature sigint=0 color=1\n";
	// log.write("Sent: feature sigint=0\n");

	// std::cin >>  s; // now we should get accepted collors
	// log.write("Received: ");
	// log.write(s);
	// log.write(" ");
	// std::cin >>  s;
	// log.write(s);
	// log.write("\n");

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
	// finished the init

	log.write("\n\t*****\n");
	return 1;
}