compiler=g++
run: main.o
	./main.o

main.o : main.cpp
	$(compiler) main.cpp -o main.o

clean:
	rm *.o