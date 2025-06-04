
CC = gcc #nasz komplator
CFLAGS = -Wall -g  #lepsze error code'y 
OBJECTS = main.o print_args.o find_max.o find_min.o #pliki z funkcjami 
TARGET = tres
all: $(TARGET)
$(TARGET):$(OBJECTS) #tres zostanie ponownie skompliowany jesli zmieni sie ktorys z plikow objektowych
	$(CC) $OBJECTS -o $(TARGET)  
main.o: main.c funkcje.h  #main zostanie ponownie skompilowany jesli zmieni sie ktorys z tych 2 plikow
	$(CC) $(CFLAGS) -c main.c 
print_args.o: print_args.c funkcje.h #i tak dalej
	$(CC) $(CFLAGS) -c print_args.c
find_max.o: find_max.c funkcje.h
	$(CC) $(CFLAGS) -c find_max.c
find_min.o: find_min.c funkcje.h
	$(CC) $(CFLAGS) -c find_min.c
clean:
	rm -f $(OBJECTS) $(TARGET)