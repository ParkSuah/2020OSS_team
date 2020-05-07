CC = gcc
TARGET = student_score
OBJECTS = main.c score.o list.o

$(TARGET) : $(OBJECTS)
	$(CC) -o $@ $^

clean :
	rm *.o $(TARGET) 
