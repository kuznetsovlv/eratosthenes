obj = main.o mem.o
headers = mem.h

.PHONY: all
all: eratosthenes

eratosthenes: $(obj)
	gcc -o eratosthenes $(obj)

main.o: $(headers)
mem.o: mem.h

.PHONY: clean
clean:
	-rm -f eratosthenes *.o 2>/dev/null
