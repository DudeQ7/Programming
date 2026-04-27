CC=gcc 
CFLAGS= -Wall 
TARGET1 = zad1_nadaj
TARGET2 = zad1_odbierz
SOURCE1 = zad1_nadaj.c
SOURCE2 = zad1_odbierz.c 
all:$(TARGET1) $(TARGET2)
$(TARGET1): $(SOURCE1)
	$(CC) $(CFLAGS) $(SOURCE1) -o $(TARGET1)
$(TARGET2): $(SOURCE2)
	$(CC) $(CFLAGS) $(SOURCE2) -o $(TARGET2)
clean:
	rm -f $(TARGET1) $(TARGET2)