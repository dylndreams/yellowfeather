CC = gcc
SRCS = src/main.c src/audio.c
LDFLAGS = -Llibs/z8lua -llua -lSDL2 -lm -lc -g -Iinclude
CFLAGS = -std=c99 -Oz -s -g

msg ?= $(shell bash -c 'read -p "COMMITMSG:" msg; echo $$msg')

all: run

run: build
	@./build.out

build: $(SRCS)
	@$(CC) $(SRCS) $(LDFLAGS) $(CFLAGS) -o build.out

commit:
	@git pull
	@git add .
	@git commit -m $(msg)
	@git push -u origin main

clean:
	rm -f build.out $(OBJS)

