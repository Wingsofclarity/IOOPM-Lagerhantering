main: main.o lager.o ware.o warehouse.o undo.o
	gcc -ggdb main.o lager.o ware.o warehouse.o undo.o -o main
# might be worth removing clean, not sure yet
	make clean
main.o: main.c lager.h warehouse.h undo.h
	gcc -c -ggdb -Wall -std=c11 main.c
lager.o: lager.c lager.h
	gcc -c -ggdb -Wall -std=c11 lager.c
ware.o: ware.c ware.h
	gcc -c -ggdb -Wall -std=c11 ware.c
warehouse.o: warehouse.c warehouse.h
	gcc -c -ggdb -Wall -std=c11 warehouse.c
undo.o: undo.h undo.c
	gcc -c -ggdb -Wall -std=c11 undo.c
clean:
	rm main.o
	rm lager.o
	rm ware.o
	rm warehouse.o

