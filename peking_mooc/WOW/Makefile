OBJS= Timer.o Util.o Global.o RewardOrder.o WarriorFactory.o WeaponFactory.o WeaponOrder.o Weapon.o Arrow.o Bomb.o\
Sword.o Warrior.o Dragon.o Lion.o Iceman.o Ninja.o Wolf.o Headquarter.o Redquarter.o Bluequarter.o\
City.o Game.o GameMain.o
CC=g++
DEBUG=-g 
INCLUDE=-I./include
SRC_FOLDER=./src
CFLAGS=$(INCLUDE) -c $(DEBUG)
LFLAGS=$(DEBUG)
VPATH=./src

all: WOW

WOW: $(OBJS) 	
	$(CC) $(LFLAGS) $(OBJS) -o $@ 
Timer.o: Timer.cpp
	$(CC) $(CFLAGS) $<
Util.o: Util.cpp
	$(CC) $(CFLAGS) $<
Global.o: Global.cpp
	$(CC) $(CFLAGS) $<
RewardOrder.o: RewardOrder.cpp
	$(CC) $(CFLAGS) $<
WarriorFactory.o: WarriorFactory.cpp
	$(CC) $(CFLAGS) $<
WeaponFactory.o: WeaponFactory.cpp
	$(CC) $(CFLAGS) $<
WeaponOrder.o: WeaponOrder.cpp
	$(CC) $(CFLAGS) $<
Weapon.o: Weapon.cpp
	$(CC) $(CFLAGS) $<
Arrow.o: Arrow.cpp
	$(CC) $(CFLAGS) $<
Bomb.o: Bomb.cpp
	$(CC) $(CFLAGS) $<
Sword.o: Sword.cpp
	$(CC) $(CFLAGS) $<
Warrior.o: Warrior.cpp
	$(CC) $(CFLAGS) $<
Dragon.o: Dragon.cpp
	$(CC) $(CFLAGS) $<
Lion.o: Lion.cpp
	$(CC) $(CFLAGS) $<
Iceman.o: Iceman.cpp
	$(CC) $(CFLAGS) $<
Ninja.o: Ninja.cpp
	$(CC) $(CFLAGS) $<
Wolf.o: Wolf.cpp
	$(CC) $(CFLAGS) $<
Headquarter.o: Headquarter.cpp
	$(CC) $(CFLAGS) $<
Redquarter.o: Redquarter.cpp
	$(CC) $(CFLAGS) $<
Bluequarter.o: Bluequarter.cpp
	$(CC) $(CFLAGS) $<
City.o: City.cpp
	$(CC) $(CFLAGS) $<
Game.o: Game.cpp
	$(CC) $(CFLAGS) $<
GameMain.o: GameMain.cpp
	$(CC) $(CFLAGS) $<
clean:
	rm *.o WOW
