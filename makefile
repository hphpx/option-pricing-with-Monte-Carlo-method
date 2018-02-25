CXX=g++
target=test

$(target):main.o monte.o
	$(CXX) main.o monte.o -o $(target)
main.o: main.cpp
	$(CXX) main.cpp -c
monte.o: monte.cpp
	$(CXX) monte.cpp -c
clean:
	rm $(target) *.o
