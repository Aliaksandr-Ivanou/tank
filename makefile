all:
	cc ruch.c json_interpr.c main.c -lcurl ../cJSON/cJSON.o
	./a.out

test: all
	./a.out 