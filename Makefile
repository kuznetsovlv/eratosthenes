obj = main.o mem.o strToNum.o simple.o
headers = mem.h strToNum.h simple.h

.PHONY: all
all: eratosthenes

eratosthenes: $(obj)
	gcc -o eratosthenes $(obj) -lm

main.o: $(headers)
mem.o: mem.h
strToNum.o: strToNum.h
simple.o: simple.h

.PHONY: clean
clean:
	-rm -f eratosthenes *.o 2>/dev/null
