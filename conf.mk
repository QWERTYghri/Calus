#
# conf.mk
#
# Configuration file for makefile
#

# Compile Flags
CC	 := gcc
CFLAGS	 := -std=c99 -Wpedantic -Wall -Wextra -pipe
CPPFLAGS := -D_POSIX_C_SOURCE=200809L

# Libraries
LIB 	 := -lncurses

# Optimization Flags
#OFLAG	 := -Os
OFLAG 	 := -g -O0

# Output name
CALUS	 := "./calus"