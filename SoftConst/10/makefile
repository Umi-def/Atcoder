CC      = gcc
INCLUDES = -I/home/staff/nakaya/SoftConst/include -I.
LIBS    = -L/home/staff/nakaya/SoftConst/lib
LFLAGS  = -ldotman4
TARGET  = main
OBJS    = mychar.o 2darray.o show_field.o makemap.o

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBS) $(LFLAGS)

test_2darray:test_2darray.o 2darray.o
	$(CC) -o $@ $^
.c.o:
	$(CC) $(INCLUDES) -c $<

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)