compiler = g++

assignment1 : main.o 
	$(compiler) main.o  -Llibrary -lShape -o assignment1

main.o: main.cpp
	$(compiler) -c main.cpp  -Ilibrary  -o main.o

clean:
	rm *.o