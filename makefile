.PHONY = all clean all
CC = gcc
AR = ar
loop = basicClassification.o advancedClassificationLoop.o
recursive = basicClassification.o advancedClassificationRecursion.o
CFLAGS= -Wall -g
all: recursived loopd recursives loops mains maindloop maindrec
mains: main.o libclassrec.a
	$(CC) $(CFLAGS)  -o mains main.o libclassrec.a -lm
maindloop: main.o libclassloops.so 
	$(CC) $(CFLAGS)  -o maindloop main.o libclassloops.so  ./libclassloops.so -lm
maindrec: main.o libclassrec.so 
	$(CC) $(CFLAGS)  -o maindrec main.o libclassrec.so  ./libclassrec.so -lm
loops: $(loop)
	$(AR) -rcs libclassloops.a $(loop)
recursives: $(recursive)
	$(AR) -rcs libclassrec.a $(recursive)
loopd: $(loop)
	$(CC) -shared -o libclassloops.so $(loop) -lm
recursived: $(recursive)
	$(CC) -shared -o libclassrec.so $(recursive) -lm
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(CFLAGS) -c basicClassification.c -lm
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationLoop.c -lm
main.o: main.c NumClass.h
	$(CC) $(CFLAGS) -c main.c
 

clean:
	rm -f *.o *.a *.so maindloop maindrec mains