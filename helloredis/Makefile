.SUFFIXES:.c .o

CC=gcc
SRCS=03fork.c

OBJS=$(SRCS:.c=.o)
#EXEC=$(SRCS:.c=)
EXEC=hello

start: $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
	@echo "-------------ok-------------"
	
.c.o:
	$(CC) -o $@ -c $<
	
clean:
	rm -f $(OBJS)
	@echo "clean ok"