#/usr/bin/make -f
## Makefile
## Copyright (c) 2025 Your Name


# Project variables

EXEC := example


# Useful builtin makefile options, uncomment to use

# SHELL := /bin/sh

# AS := as
# CC := cc
# CXX := g++
# CPP := $(CC) -E

# ASFLAGS := 
CFLAGS := -g -Og -Wall -Werror
# CXXFLAGS := 
# CPPFLAGS := 
# LDFLAGS := 
# LDLIBS := 


.PHONY: all
all: $(EXEC)

.PHONY: run
run: $(EXEC)
	./$(EXEC)


# minimal rule to get your project started
$(EXEC): $(EXEC).c


.PHONY: clean
clean:
	rm $(EXEC)
