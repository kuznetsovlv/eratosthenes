obj = main.o mem.o strToNum.o
headers = mem.h strToNum.h

.PHONY: all
all: eratosthenes

eratosthenes: $(obj)
	gcc -o eratosthenes $(obj)

main.o: $(headers)
mem.o: mem.h
strToNum.o: strToNum.h

.PHONY: clean
clean:
	-rm -f eratosthenes *.o 2>/dev/null
