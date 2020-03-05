CXX = g++
CXXFLAGS = -Wall

proj2: Alchemist.o Game.o lil_alchemy.cpp
        $(CXX) $(CXXFLAGS) Alchemist.o Game.o lil_alchemy.cpp -o lil_alchemy

Game.o: Alchemist.o Game.cpp Game.h
        $(CXX) $(CXXFLAGS) -c Game.cpp

Alchemist.o: Alchemist.h Alchemist.cpp Element.h
        $(CXX) $(CXXFLAGS) -c Alchemist.cpp

clean:
        rm *.o*
        rm *~

run:
        ./lil_alchemy
