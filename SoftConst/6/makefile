CC      = gcc
INCLUDES = -I/home/h31j/h31j059/SoftConst/6/include -I.
LIBS    = -L/home/h31j/h31j059/SoftConst/6/lib
LFLAGS  = -ldotman1
TARGET  = main
OBJS    = mychar.o

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBS) $(LFLAGS)

.c.o:
	$(CC) $(INCLUDES) -c $<

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)