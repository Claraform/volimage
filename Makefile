CC=g++
CCFLAGS=-std=c++11
LIBS=-lm -lX

default: VolImage.o main.o
	$(CC) VolImage.o main.o $(CCFLAGS) -o volimage
        
VolImage.o: VolImage.cpp VolImage.h
	$(CC) $(CCFLAGS) VolImage.cpp -c
        
main.o: main.cpp
	$(CC) $(CCFLAGS) main.cpp -c
        
clean:
	rm -f *.o
	rm -f volimage
                           
