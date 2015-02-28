EXENAME = exif_parser
OBJS = exif_parser.o main.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp exif_parser.h 
	$(CXX) $(CXXFLAGS) main.cpp

exif_parser.o : exif_parser.cpp exif_parser.h
	$(CXX) $(CXXFLAGS) exif_parser.cpp

clean :
	-rm -f *.o $(EXENAME)
