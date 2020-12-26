CC 	= gcc
INCLUDES = -I/home/staff/nakaya/SoftConst/include -I.
LIBS	= -L/home/staff/nakaya/SoftConst/lib
LFLAGS	= -ldotman4
TARGET	= main
OBJS 	= mychar.o 2darray.o show_field.o makemap.o

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LIBS) $(LFLAGS)

.c.o:
	$(CC) $(INCLUDES) -c $<

test_show_field: test_show_field.o show_field.o /home/staff/nakaya/SoftConst/obj/2darray_alter.o
	$(CC) -o $@ $^

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)
