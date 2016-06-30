.SUFFIXES:.cpp .o

#CC=gcc
CC=g++
SRCS=examples/test.cpp \
			tinyxml/tinystr.cpp \
			tinyxml/tinyxml.cpp \
			tinyxml/tinyxmlerror.cpp \
			tinyxml/tinyxmlparser.cpp \
			utils/Buffer.cpp \
			utils/XTimeUtil.cpp \
			utils/ChineseData.cpp \
			filemanager/FileManager.cpp \
			net/BaseNetDelegate.cpp

OBJS=$(SRCS:.cpp=.o)
#EXEC=$(SRCS:.c=)
EXEC=hello

start: $(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
	@echo "-------------ok-------------"
	
.cpp.o:
	$(CC) -g -o $@ -c $<
	
clean:
	rm -f $(OBJS) $(EXEC)
	@echo "clean ok"
