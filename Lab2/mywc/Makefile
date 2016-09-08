#################################################################
# Makefile for the mywc project
#
# This file will compile all the files in mywc project and
# build an executable. We build a dependency graph of all files
# to wite the Makefile for mywc
#
# Authors: Srikanth Kanuri (srkanuri)
# Date Created: 09/02/2016
# Last Modified by: Srikanth Kanuri
# Date Last Modified: 09/08/2016
# Assignment: Lab2
# Part of: mywc
##################################################################

CC = gcc
CFLAGS = -g
LDFLAGS = 

mywc: mywc.o
	$(CC) $(LDFLAGS) -o mywc mywc.o
mywc.o: mywc.c
	$(CC) $(CFLAGS) -c mywc.c
clean:
	rm mywc.o mywc
