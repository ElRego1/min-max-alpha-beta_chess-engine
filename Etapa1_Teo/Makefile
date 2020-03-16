CC=g++ -std=c++11 
CFLAGS=-Wall -Wextra
CFLAGS_OPTIM=-funit-at-a-time
CFLAGS_TEMP=-Og

OUT_NAME=main

build:
	$(CC) $(CFLAGS) $(CFLAGS_OPTIM) $(CFLAGS_TEMP) -o $(OUT_NAME) main.cpp

test_engine:
	xboard -fcp "./$(OUT_NAME)" -fd "`pwd`" -debug

clean:
	rm main