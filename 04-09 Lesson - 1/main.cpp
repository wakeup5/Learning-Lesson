#include "Player.h"
#include <iostream>

void main()
{
	Player* player = new Player;
	
	player->setHp(1000);
	player->setMp(300);
	player->setStr(100);
	player->setDex(50);
	player->setAgi(20);
	player->setAtk(100);
	player->setDef(50);

	printf("플레이어 능력치 Hp : %d, Mp : %d, Str : %d, Dex : %d, Agi : %d, Atk : %d, Def : %d\n", 
		player->getHp(), player->getMp(), player->getStr(), player->getDex(), player->getAgi(), player->getAtk(), player->getDef());

	delete player;

	Player* players = new Player[10];

	players[0].setHp(100);
	printf("%d", players[0].getHp()); 

	delete[] players;
}