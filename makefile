CXX = g++
CXXFLAGS = -std=c++2b

all: main

test: .outputFolder
	out/main $(arg1) $(arg2)

.outputFolder:
	mkdir -p out

main: .outputFolder
	$(CXX) $(CXXFLAGS) main.cpp -Wall -Wextra -Werror -o out/main
	./out/main

clean:
	find . -type f -name '*.h.gch' -delete -o -name '*.o' -delete

