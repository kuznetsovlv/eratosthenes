obj = main.o mem.o strToNum.o prime.o
headers = mem.h strToNum.h prime.h

.PHONY: all
all: eratosthenes

eratosthenes: $(obj)
	gcc -o eratosthenes $(obj) -lm

main.o: $(headers)
mem.o: mem.h
strToNum.o: strToNum.h
prime.o: prime.h

.PHONY: clean
clean:
	-rm -f eratosthenes *.o 2>/dev/null
