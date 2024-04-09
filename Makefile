all: compile

compile:
	echo "Compilando..."
	gcc --std=c99 -o bin/api2 src/main.c

run:
	bin/api2

