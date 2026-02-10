CC = g++ -g
CFLAGS = -std=c++1z

all: observerPattern

observerPattern: Subject.o SerialManager.o Effect.o Delay.o AudioManager.o main.o
	$(CC) -o $@ $(CFLAGS) Subject.o SerialManager.o Effect.o Delay.o AudioManager.o main.o

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f observerPattern
