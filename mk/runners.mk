run:=./
valgrind-memory:=valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt # leave trailing space
