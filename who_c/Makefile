whoPro : who1.o utmplib.o
	gcc -o whoPro who1.o utmplib.o
	rm utmplib.o who1.o
who1.o : who1.c
	gcc -c who1.c
utmplib.o : utmplib.c
	gcc -c utmplib.c
clean:
	rm whoPro
