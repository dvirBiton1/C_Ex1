.PHONY = all clean all
CC = gcc
AR = ar
loopFails = basicClassification.o advancedClassificationLoop.o
recFails = basicClassification.o advancedClassificationRecursion.o
CFLAGS= -Wall -g
all: libclassloops.a libclassrec.a libclassrec.so libclassloops.so mains maindloop maindrec
mains: main.o libclassrec.a
	$(CC) $(CFLAGS)  -o mains main.o libclassrec.a -lm
maindloop: main.o libclassloops.so 
	$(CC) $(CFLAGS)  -o maindloop main.o libclassloops.so -lm
maindrec: main.o libclassrec.so 
	$(CC) $(CFLAGS)  -o maindrec main.o libclassrec.so -lm
libclassloops.a: $(loopFails)
	$(AR) -rcs libclassloops.a $(loopFails)
libclassrec.a: $(recFails)
	$(AR) -rcs libclassrec.a $(recFails)
libclassloops.so: $(loopFails)
	$(CC) -shared -o libclassloops.so $(loopFails) -lm
libclassrec.so: $(recFails)
	$(CC) -shared -o libclassrec.so $(recFails) -lm
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(CFLAGS) -c basicClassification.c -lm
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationLoop.c -lm
main.o: main.c NumClass.h
	$(CC) $(CFLAGS) -c main.c
 

clean:
	rm -f *.o *.a *.so maindloop maindrec mains