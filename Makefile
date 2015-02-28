EXENAME = exif_parser
OBJS = exif_parser.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

exif_parser.o : exif_parser.cpp exif_parser.h
	$(CXX) $(CXXFLAGS) exif_parser.cpp

clean :
	-rm -f *.o $(EXENAME)
