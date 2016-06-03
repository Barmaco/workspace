.SUFFIXES:.cpp .o

#CC=gcc
CC=g++
SRCS=test.cpp \
			utils/Buffer.cpp \
			utils/XTimeUtil.cpp \
			utils/ChineseData.cpp \
			filemanager/FileManager.cpp

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