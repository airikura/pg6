CC= g++
FILES = CardTest.cpp Card.cpp 
OPTIONS = -std=c++11 -pedantic -Wall -Wextra -O
GCOV = -fprofile-arcs -ftest-coverage
OUTPUT = pg6
pg4: $(FILES)
	$(CC) $(OPTIONS) -o $(OUTPUT) $(FILES)

gcov: $(FILES)
	$(CC) $(OPTIONS) -o $(OUTPUT) $(FILES) $(GCOV)

clean: 
	rm *.gcov *.gcda *.gcno *~
