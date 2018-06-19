OBJS:=pthread

all: clean pthread

pthread: pthread_test.c
	gcc -o $@ $<

clean:
	rm -rf $(OBJS)

.PHONY: clean
