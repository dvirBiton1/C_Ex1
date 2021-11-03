.PHONY = all clean
CC = gcc
AR = ar
loop =  advancedClassificationLoop.o basicClassification.o
recursive = advancedClassificationRecursion.o basicClassification.o
CFLAGS= -Wall -g
loops: libclassloops.a
looped: libclassloops.so
recursives:libclassrec.a
recursived:libclassrec.so

all: libclassloops.a libclassloops.so libclassrec.a libclassrec.so mains maindrec maindloop 

mains: main.o libclassrec.a
	$(CC) $(CFLAGS)  -o mains main.o libclassrec.a -lm
maindloop: main.o libclassloops.so 
	$(CC) $(CFLAGS)  -o maindloop main.o ./libclassloops.so -lm
maindrec: main.o libclassrec.so 
	$(CC) $(CFLAGS)  -o maindrec main.o ./libclassrec.so -lm
libclassloops.a: $(loop)
	$(AR) -rcs libclassloops.a $(loop)
libclassloops.so: $(loop)
	$(CC) -shared -o libclassloops.so $(loop) -lm
libclassrec.a: $(recursive)
	$(AR) -rcs libclassrec.a $(recursive)
libclassrec.so: $(recursive)
	$(CC) -shared -o libclassrec.so $(recursive) -lm
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(CFLAGS) -c basicClassification.c -lm
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationLoop.c -lm
main.o: main.c NumClass.h
	$(CC) $(CFLAGS) -c main.c
 

clean:
	rm -f *.o *.a *.so maindloop maindrec mains