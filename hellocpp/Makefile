.SUFFIXES:.cpp .o

CC=gcc
SRCS=helloredis.cpp

OBJS=$(SRCS:.cpp=.o)
#EXEC=$(SRCS:.c=)
EXEC=hello

start: $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
	@echo "-------------ok-------------"
	
.cpp.o:
	$(CC) -o $@ -c $<
	
clean:
	rm -f $(OBJS) $(EXEC)
	@echo "clean ok"