CXX = g++
CXXFLAGS = -std=c++2b

all: main

.outputFolder:
	mkdir -p out

main: .outputFolder
	$(CXX) $(CXXFLAGS) main.cpp -Wall -Wextra -Werror -o out/main
	./out/main

