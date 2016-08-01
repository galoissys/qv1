#makefile

PROGRAM = main.exe
OBJS = main.o qv.o rnd.o qlrn.o
CC = gcc

$(PROGRAM): $(OBJS)
	$(CC) -o $(PROGRAM) $(OBJS)

main.o: main.c
	$(CC) -c $<

qv.o: qv.c
	$(CC) -c $<

rnd.o: rnd.c
	$(CC) -c $<

qlrn.o: qlrn.c
	$(CC) -c $<

clean:
	rm -f $(PROGRAM) $(OBJS)

