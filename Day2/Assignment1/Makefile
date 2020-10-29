compiler=g++
assignment1: main.o inputs.o
	$(compiler) -o assignment1 main.o inputs.o

main.o : main.cpp
	$(compiler) -c main.cpp -o main.o

inputs.o: inputs.cpp
	$(compiler) -c inputs.cpp -o inputs.o

clean:
	rm *.o
	rm assignment1
	ls

run: main.o inputs.o
	./assignment1