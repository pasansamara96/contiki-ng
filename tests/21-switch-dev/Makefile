CONTIKI_PROJECT = 21-switch-dev

all: $(CONTIKI_PROJECT)

TARGET = zoul
BOARD = firefly
MAKE_MAC = MAKE_MAC_CSMA
MAKE_ROUTING = MAKE_ROUTING_RPL_LITE
MAKE_NET = MAKE_NET_NULLNET

MODULES += os/services/deployment

CONTIKI = ../..

include $(CONTIKI)/Makefile.include
