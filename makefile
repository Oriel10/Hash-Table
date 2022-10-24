CC = g++
# OBJS = main.o
EXEC = hashtable_output
DEBUG_FLAG = -DNDBUG
COMP_FLAG = -std=c++11 -Wall -Werror -pedantic-errors 

# $(EXEC): $(OBJS)
# 	$(CC) $(DEBUG_FLAG) $(OBJS) -o $@ -L. -lmap
# electionTestsExample.o: tests/electionTestsExample.c election.h test_utilities.h mtm_map/map.h
# 	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) tests/electionTestsExample.c
# election.o: election.c election.h area.h mtm_map/map.h
# 	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.c
# area.o: area.h area.c mtm_map/map.h
# 	$(CC) -c $(DEBUG_FLAG) $(COMP_FLAG) $*.c

# clean:
# 	rm -f $(OBJS) $(EXEC)

$(EXEC): clean
	$(CC) $(COMP_FLAG) -o $@ *.cpp

clean:
	rm -f $(EXEC)

