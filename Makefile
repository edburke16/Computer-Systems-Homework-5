
tokens:
	gcc -o tokens tokens.c

clean:
	rm -rf tmp tokens *.o

.PHONY: all clean

