CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		helloredis.o

LIBS =

TARGET =	helloredis

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
