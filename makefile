
all: main.out

main.out: main.o array.o belote.o  playing-cards.o random.o rapidMemoryGame.o reliableMemoryGame.o terminalControl.o
	gcc -o main.out $^

%.o: %.c
	gcc -Wno-incompatible-pointer-types -c -o $@ $<
