CC=g++
CFLAGS=-Wall -Wno-unused-parameter -Wextra -O2 -pedantic -std=c++14 -I$(IDIR)
ODIR=../obj
IDIR=../include
BIN=jt

_DEPS=solver.h
DEPS=$(addprefix $(IDIR)/,$(_DEPS))

_OBJS=main.o solver.o
OBJS=$(addprefix $(ODIR)/,$(_OBJS))

$(BIN): $(OBJS) $(IDIR)/types.h
	$(CC) -o $@ $(OBJS) $(CFLAGS)

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BIN)