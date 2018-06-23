OBJS=herdsrv herdcli

all: clean $(OBJS)

$(OBJS): %: %.cc
	gcc -o $@ $<

clean:
	-@rm $(OBJS)

.PHONY: all $(OBJS) clean

