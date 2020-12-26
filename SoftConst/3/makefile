CC      = gcc
INCLUDES = -I/home/h31j/h31j059/SoftConst/3/include -I.
LIBS    = -L/home/h31j/h31j059/SoftConst/3/lib
LFLAGS  = -lppm_data
TARGET  = rotate hflip vflip
OBJS    = rotate.o hflip.o vflip.o

.PHONY: all
all: $(TARGET)

rotate: rotate.o
	$(CC) -o $@ $^ $(LIBS) $(LFLAGS)

hflip: hflip.o
	$(CC) -o $@ $^ $(LIBS) $(LFLAGS)
vflip: vflip.o
	$(CC) -o $@ $^ $(LIBS) $(LFLAGS)


.c.o:
	$(CC) $(INCLUDES) -c $<

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)