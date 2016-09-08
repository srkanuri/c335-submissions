#################################################################
# Makefile for the poly project
# 
# This file will compile all the files in poly project and 
# build an executable. We build a dependency graph of all files
# to wite the Makefile for poly
#
# Authors: Srikanth Kanuri (srkanuri)
#          Samuel Eleftheri (selefthe)
# Date Created: 09/02/2016
# Last Modified by: Srikanth Kanuri
# Date Last Modified: 09/08/2016
# Assignment: Lab2
# Part of: poly
##################################################################
CC = gcc
CFLAGS = -g
LDFLAGS =
poly: poly.o dump.o
	$(CC) $(LDFLAGS) -o poly poly.o dump.o
poly.o: poly.c
	$(CC) $(CFLAGS) -c poly.c
dump.o: dump.c
	$(CC) $(CFLAGS) -c dump.c
clean:
	rm poly.o dump.o poly
