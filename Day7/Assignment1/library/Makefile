compiler=g++

libShape : shape.o 
	$(compiler) --shared -fPIC  shape.o -o libShape.so


shape.o: shape.cpp shape.h
	$(compiler) -c shape.cpp -o shape.o

clean:
	rm *.o
