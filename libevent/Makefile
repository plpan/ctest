OBJS=simcli simsrv midcli midsrv comcli comsrv

all: clean $(OBJS)

$(OBJS): %: %.cc
	gcc -levent -I/usr/local/Cellar/libevent/2.1.8/include/event2 -o $@ $<

clean:
	-@rm $(OBJS)

.PHONY: all $(OBJS) clean
