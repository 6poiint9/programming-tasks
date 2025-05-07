# Copyright (c) 2025 Hochschule Esslingen
# author: Rainer Keller, Dennis Grewe
# description: Makefile for the syscall counter module

# usage: make --help

obj-m = mod_syscall_counter.o

KVERSION = $(shell uname -r)

modules all: syscall_names.h
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(KVERSION)/build M=$(PWD) clean
	rm -f syscall_names.h

syscall_names.h:
	bash gen_syscall_names.sh /lib/modules/$(KVERSION)/build

# Help message
help:
	@echo "Makefile for syscall_counter kernel module"
	@echo ""
	@echo "Targets:"
	@echo "  all           - Build all modules (default)"
	@echo "  mod_syscall_counter - Build only the complete solution"
	@echo "  clean         - Remove all generated files"
	@echo ""
	@echo "Architecture is detected automatically"
