compiler=g++
runtest: test.o
	./test.o

test.o : test.cpp serviceRecord.cpp
	$(compiler) test.cpp serviceRecord.cpp -o test.o

clean:
	rm *.o