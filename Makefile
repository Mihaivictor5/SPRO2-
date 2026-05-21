.PHONY: all pi tests clean

all: pi

pi:
	$(MAKE) -C pi_controller

tests:
	$(MAKE) -C tests run

clean:
	$(MAKE) -C pi_controller clean
	$(MAKE) -C tests clean
