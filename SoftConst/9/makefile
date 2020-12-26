CC      = gcc
INCLUDES = -I/home/staff/nakaya/SoftConst/include -I.
LIBS    = -L/home/staff/nakaya/SoftConst/lib
LFLAGS  = -ldotman3
TARGET  = main
OBJS    = mychar.o 2darray.o show_field.o

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBS) $(LFLAGS)

test_2darray:test_2darray.o 2darray.o
	$(CC) -o $@ $^
test_show_field:test_show_field.o test_show_field.o 2darray.o
.c.o:
	$(CC) $(INCLUDES) -c $<

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)