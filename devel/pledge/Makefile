include ../../config.mk
include ../../rules.mk

CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic
CFLAGS += -fdiagnostics-color=always
INCDIR = ./src
INCDIR += -I$(CCTOOLS_HOME)/dttools/src

# some posix functions werent added to standard c until c23, so we have
# to specify
# POSIX_C_SOURCE is saying that we want to enable functionality from 2008 posix
# CFLAGS += -std=c11 -D_POSIX_C_SOURCE=200809L
# Alternatively, this enables extensions and all functionality
CFLAGS += -I$(INCDIR)

RELFLGS = -O3

BUILDDIR = ./build

# LDFLAGS += $(CCTOOLS_HOME)/dttools/src/libdttools.a

# COMMON_SRCS = src/pl_list.c src/util.c
COMMON_SRCS = src/util.c src/list_util.c
COMMON_SRCS += $(CCTOOLS_HOME)/dttools/src/list.c

ENFORCER = $(BUILDDIR)/libenforcer.so
ENF_LDFLAGS += $(LDFLAGS) -ldl -shared
ENF_CFLAGS += $(CFLAGS) -fPIC
ENF_SRCS = src/enforcer.c
ENF_OBJ = $(BUILDDIR)/enforcer.o

ENFORCER_H = src/libenforcer.h

PLEDGE = $(BUILDDIR)/pledge
PL_LDFLAGS += $(LDFLAGS)
PL_CFLAGS += $(CFLAGS)
PL_SRCS = src/pledge.c
PL_OBJ = $(BUILDDIR)/pledge.o

CFLAGS += -std=gnu11



all: $(PLEDGE)

$(PLEDGE): $(ENFORCER_H) $(PL_OBJ)
	$(CC) $(CCTOOLS_INTERNAL_CCFLAGS) $(PL_CFLAGS) $(PL_LDFLAGS) $(PL_OBJ) $(COMMON_SRCS) -o $(PLEDGE)

$(ENFORCER_H): $(ENFORCER)
	xxd -i -n minienforcer $(BUILDDIR)/libenforcer.so > src/libenforcer.h

$(ENFORCER): $(ENF_OBJ)
	$(CC) $(CCTOOLS_INTERNAL_CCFLAGS) $(ENF_CFLAGS) $(ENF_LDFLAGS) $(ENF_OBJ) $(COMMON_SRCS) -o $(ENFORCER)

$(PL_OBJ) : $(PL_SRCS) | $(BUILDDIR)
	$(CC) $(CCTOOLS_INTERNAL_CCFLAGS) $(PL_CFLAGS) -c $< -o $@

# # Order only build dir
$(ENF_OBJ) : $(ENF_SRCS) | $(BUILDDIR)
	$(CC) $(CCTOOLS_INTERNAL_CCFLAGS) $(ENF_CFLAGS) -c $< -o $@

$(BUILDDIR):
	mkdir $@

.PHONY : clean all
clean:
	rm -rf $(BUILDDIR)
	rm src/libenforcer.h
