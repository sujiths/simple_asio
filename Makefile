all: 
	$(MAKE) -C tests

clean: 
	$(MAKE) -C tests clean
    
.PHONY: all clean
