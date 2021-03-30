IDIR =./
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj

LIBS= -lm -lgtest -lgtest_main -lpthread

_DEPS = romano.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = romano.o testaromano.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testar: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

verificar: testar
	valgrind --leak-check=full ./testar
	@echo "*** CPP CHECK ***"
	cppcheck --enable=warning romano.cpp

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *.gch *.out 