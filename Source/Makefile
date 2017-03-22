default:
	gcc -c -o QueueLib.o QueueLib.c -Wall
	ar rcs QueueLib.a QueueLib.o
	gcc -o Main Main.c QueueLib.a -Wall
	mv Main ..

clean:
	rm ../Main
	rm QueueLib.a QueueLib.o
