CC      = gcc
INCLUDES = -I/home/h31j/h31j059/SoftConst/7/include -I.
LIBS    = -L/home/h31j/h31j059/SoftConst/7/lib
LFLAGS  = -ldotman2
TARGET  = main
OBJS    = mychar.o 2darray.o

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBS) $(LFLAGS)

test_2darray:test_2darray.o 2darray.o
	$(CC) -o $@ $^
.c.o:
	$(CC) $(INCLUDES) -c $<

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)