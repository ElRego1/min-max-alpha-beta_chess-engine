
build:
	g++ -std=c++11 -Wall -Wextra -O0 -g -o main main.cpp

test_engine:
	xboard -fcp "./main" -fd "`pwd`" -debug

clean:
	rm main