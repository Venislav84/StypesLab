CXX = g++;
CXXFLAGS = -c;
OBJ = program.o swap.o
EXEC = program

all: $(EXEC)

$(EXEC): $(OBJ)
$(CXX) $^ -o $@
%.o: %.cpp
$(CXX) $(CXXFLAGS) $ < -o $@

clean:
rm -f $ (OBJ) $(EXEC)

run: $(EXEC)
./$(EXEC)