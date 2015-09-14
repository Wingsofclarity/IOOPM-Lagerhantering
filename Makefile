main: main.o lager.o ware.o warehouse.o
	gcc -ggdb main.o lager.o ware.o warehouse.o -o main
# might be worth removing clean, not sure yet
	make clean
main.o: main.c lager.h warehouse.h
	gcc -c -ggdb -Wall -std=c11 main.c
lager.o: lager.c lager.h ware.h warehouse.h
	gcc -c -ggdb -Wall -std=c11 lager.c
ware.o: ware.c ware.h
	gcc -c -ggdb -Wall -std=c11 ware.c
warehouse.o: warehouse.c warehouse.h ware.h
	gcc -c -ggdb -Wall -std=c11 warehouse.c
clean:
	rm main.o
	rm lager.o
	rm ware.o
	rm warehouse.o

