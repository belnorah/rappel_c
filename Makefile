all: t3c

t3c:
	gcc -g src/t3c.c -o t3c -lcrypto -Wall -Wextra

clean:
	rm -f t3c