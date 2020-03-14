
build:
	g++ -std=c++11 -Wall -Wextra -funit-at-a-time -O0 -g matrix_transformation.cpp main.cpp

test_engine:
	xboard -fcp "./main" -fd "`pwd`" -debug

clean:
	rm main