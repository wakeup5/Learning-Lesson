/* 04-02 ~ 04-05 휴일-주말 과제
 * RPG 겨투겜
 * 1. 케릭터 선택. 3개. 랜덤 가능. 히든 있으면 좋음.
 * 레벨 HP MP EXP STR DEX STAMINA AGI(회피) ATK DEF MATK MDEF 스킬 3개가 미리 표시되고 고를 수 있다.
 * 전사, 마법, 밸런스 등 케릭 컨셉이 있으면 좋다.
 * 
 * 2. 프롤로그.
 * 게임 컨셉에 맞는 시작 이야기가 있어야 한다. 데코레이션.. ㅋㅋ
 *
 * 3. 전투
 * (1) 공격력, (2) 스킬, (3) 아이템 메뉴가 있어야 한다.
 * 몹 5마리와 전투 후 보스 전투.
 * 보스 처치 후 엔딩 나오고 끝.
 *
 * 4. 게임은 턴제.
 */
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "animation.cpp"

#define length(arr) (sizeof(arr)/sizeof(*arr))

struct Skill
{
	char* name;
	int atkAttr;
	float magPower;
	int consumeMP;
	int cooltime;
	int cooltimeLeft;
};

struct Unit
{
	char* name;
	int level;
	int exp;
	int maxHp;
	int maxMp;
	int maxStamina;
	int str;
	int dex;
	float agi;
	int atk;
	int def;
	int matk;
	int mdef;
	int atkAttr;
	Skill skills[3];
	int hp;
	int mp;
	int stamina;
};

   
using namespace std;

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


int main()
{
	srand((unsigned int)time(NULL));
	
	//콘솔 크기, 글자크기 지정
	system("mode CON COLS=101 LINES=50");
	//오프닝
	for (int i = 0; i < length(opening); i++)
	{
		system("cls");
		cout << opening[i];
	}

	Sleep(1000);

	//케릭터, 몬스터 값 설정.
	Unit character[3] = {
		{ "배트청년", 1, 0.0, 1000, 150, 100, 50, 40, 20.0, 100, 50, 10, 10,	1, { { "머리가격!", 1, 2.5, 30, 2 },{ "발목타격!", 2, 1.5, 20, 2 }, { "죽어라 거지야!!", 1, 3.5, 50, 3 }}},
		{ "해머아저씨", 1, 0.0, 1200, 100, 100, 50, 40, 20.0, 150, 50, 10, 10, 1, { { "강하게 휘두르기!!", 1, 1.5, 20, 2 }, { "빠르게 휘두르기!!", 1, 2.0, 30, 3 }, { "혼신을 다해 휘두르기!!", 1, 3.5, 50, 5 } } },
		{ "책아가씨", 1, 0.0, 800, 500, 0, 50, 40, 20.0, 10, 20, 110, 50, 2, {{ "볼펜 투척!!", 2, 1.5, 20, 2 },{ "책 투척!!", 2, 2.0, 30, 3 },{ "입에서 불뿜기!!", 2, 3.5, 50, 5 }}}
	};

	Unit zombies[6] = {
		{ "좀비", 1, 0.0, 500, 200, 200, 30, 20, 10.0, 50, 20, 10, 10, 1, { { "할퀴기", 1, 2.5, 30 }, { "물기", 1, 1.5, 20 }, { "토하기", 1, 3.5, 50 } } },
		{ "좀비", 1, 0.0, 500, 200, 200, 30, 20, 10.0, 50, 20, 10, 10, 1,
			{
				{ "할퀴기", 1, 2.5, 30 },
				{ "물기", 1, 1.5, 20 },
				{ "토하기", 1, 3.5, 50 }
			}
		},
		{ "좀비", 1, 0.0, 500, 200, 200, 30, 20, 10.0, 50, 20, 10, 10, 1,
			{
				{ "할퀴기", 1, 2.5, 30 },
				{ "물기", 1, 1.5, 20 },
				{ "토하기", 1, 3.5, 50 }
			}
		},
		{ "좀비", 1, 0.0, 500, 200, 200, 30, 20, 10.0, 50, 20, 10, 10, 1,
			{
				{ "할퀴기", 1, 2.5, 30 },
				{ "물기", 1, 1.5, 20 },
				{ "토하기", 1, 3.5, 50 }
			}
		},
		{ "좀비", 1, 0.0, 500, 200, 200, 30, 20, 10.0, 50, 20, 10, 10, 1,
			{
				{ "할퀴기", 1, 2.5, 30 },
				{ "물기", 1, 1.5, 20 },
				{ "토하기", 1, 3.5, 50 }
			}
		},
		{ "좀비보스", 1, 0.0, 1500, 500, 500, 150, 150, 25.0, 150, 50, 30, 20, 1,
			{
				{ "팔 휘두르기", 1, 2.5, 30 },
				{ "덮치기", 1, 1.5, 20 },
				{ "바이러스 안개", 1, 3.5, 50 }
			}
		}
	};

	Unit player;
	
	//케릭터 선택

	int selectNum = 0;
	int selectinput;

	while (true)
	{
		system("cls");
		printf(characterPicture[selectNum]);

		Unit chara = character[selectNum];

		printf("%s 기본능력치\nHP\tMP\tStamina\tStr\tDex\tAgi\tAkt\tDef\tMDtk\tMDef\n", chara.name);
		printf("%d\t%d\t%d\t%d\t%d\t%.1f\t%d\t%d\t%d\t%d\n\n", chara.maxHp, chara.maxMp, chara.maxStamina, chara.str, chara.dex, chara.agi, chara.atk, chara.def, chara.matk, chara.mdef);

		printf("스킬명\t\t\t타입\t배율\t소모량\n");
		for (int i = 0; i < 3; i++)
		{
			printf("%23s\t", chara.skills[i].name);
			if (chara.skills[i].atkAttr == 1) printf("물리\t");
			else if (chara.skills[i].atkAttr == 2) printf("마법\t");
			printf("%.1f\t%d\n", chara.skills[i].magPower, chara.skills[i].consumeMP);
		}

		printf("\n케릭터 선택.\n");
		for (int i = 0; i < 3; i++)
		{
			if (selectNum == i) cout << " > ";
			else cout << "   ";
			cout << (i + 1) << ". " << character[i].name << endl;
		}
		
		selectinput = _getch();
		switch (selectinput)
		{
		case 72: //상 방향키
			selectNum--;
			if (selectNum < 0) selectNum = 2;
			continue;
		case 80: //하 방향키
			selectNum++;
			if (selectNum > 2) selectNum = 0;
			continue;
		case 13: //엔터키
			player = character[selectNum];
			break;
		default:
			continue;
		}

		break;
	}

	int battleInput;
	int battleSelectMode = 0;//0 = 최상위, 1 = 스킬, 2 = 아이템
	int battleNum = 0;
	int skillNum = 0;
	int itemNum = 0;

	int damage = 0;
	int minDamage = 0;
	int maxDamage = 0;
	int attackDamage = 0;
	float agility = 0;

	//잔몹 전투 시작
	for (int i = 0; i < 6; i++)
	{
		battleSelectMode = battleNum = skillNum = itemNum = damage = minDamage = maxDamage = attackDamage = 0;
		agility = 0.0;

		//피 마나 스태미너 최대치 초기화
		player.hp = player.maxHp;
		player.mp = player.maxMp;
		player.stamina = player.maxStamina;

		//좀비 피 초기화
		zombies[i].hp = zombies[i].maxHp;
		zombies[i].mp = zombies[i].maxMp;
		zombies[i].stamina = zombies[i].maxStamina;

		system("cls");
		cout << zombies[i].name << "가 나타났다!" << endl;
		Sleep(1000);
		while (true)
		{
			system("cls");
			printf("====================================================================================================\n");
			printf("player HP : %d\n", player.hp);
			printf("player MP : %d\n", player.mp);
			printf("player Stamina : %d\n" , player.stamina);
			printf("좀비의 체력 : %d\n", zombies[i].hp);

			//플레이어 턴
			if (battleSelectMode == 0)
			{
				cout << (battleNum == 0 ? " > " : "   ") << "공격" << endl;
				cout << (battleNum == 1 ? " > " : "   ") << "스킬 사용" << endl;
				cout << (battleNum == 2 ? " > " : "   ") << "아이템 사용" << endl;

				battleInput = _getch();
				switch (battleInput)
				{
				case 72: //상 방향키
					battleNum--;
					if (battleNum < 0) battleNum = 2;
					continue;
				case 80: //하 방향키
					battleNum++;
					if (battleNum > 2) battleNum = 0;
					continue;
				case 13: //엔터키
					if (battleNum == 0)
					{
						//물리 최종 공격력 공식 기본공격력+힘+(민첩/2) 최소공격력 90%, 최대 110%;
						//마법 최종 공격력 공식 기본마공격력+민첩
						damage = (player.atkAttr == 1) ? player.atk + player.str + (player.dex / 2) : player.matk + player.dex;
						minDamage = damage * (9 / 10);
						maxDamage = damage * (11 / 10);
						attackDamage = rand() % (maxDamage - minDamage - 1) + maxDamage;

						//회피 여부
						agility = (rand() % 1000) / 10;
						if (agility < zombies[i].agi)
						{
							printf("좀비를 공격하였으나 피했습니다!");
						}
						else
						{
							zombies[i].hp -= attackDamage;
							printf("좀비를 공격 하여 %d 만큼 데미지를 주었다!\n", attackDamage);
						}

						Sleep(1000);

						break;
					}
					else if (battleNum == 1)
					{
						battleSelectMode = 1;
						continue;
					}
					else if (battleNum == 2)
					{
						battleSelectMode = 2;
						continue;
					}
				default:
					continue;
				}
			}
			else if (battleSelectMode == 1)
			{
				cout << "스킬 사용" << endl;
				int j = 0;
				for (; j < length(player.skills); j++)
				{
					cout << (skillNum == j ? " > " : "   ") << player.skills[j].name << endl;
				}
				cout << (skillNum == j ? " > " : "   ") << "이전 메뉴로" << endl;
				
				battleInput = _getch();
				switch (battleInput)
				{
				case 72: //상 방향키
					skillNum--;
					if (skillNum < 0) skillNum = 3;
					continue;
				case 80: //하 방향키
					skillNum++;
					if (skillNum > 3) skillNum = 0;
					continue;
				case 13: //엔터키
					if (skillNum == length(player.skills))
					{
						battleSelectMode = 0;
						continue;
					}
					else
					{
						//스킬 공격력 공식 최종 공격력 * 스킬 배율
						damage = (player.skills[skillNum].atkAttr == 1) ? player.atk + player.str + (player.dex / 2) : player.matk + player.dex;
						minDamage = damage * (9 / 10);
						maxDamage = damage * (11 / 10);
						attackDamage = (rand() % (maxDamage - minDamage - 1) + maxDamage) * player.skills[skillNum].magPower;
						
						//쿨타임
						if (player.skills[skillNum].cooltimeLeft != 0)
						{
							printf("쿨타임 입니다.\n");
							continue;
						}
						//쿨타임 전체 -1;
						for (int k = 0; k < length(player.skills); k++)
						{
							if (player.skills[k].cooltimeLeft > 0) player.skills[k].cooltimeLeft--;
						}

						player.skills[skillNum].cooltimeLeft = player.skills[skillNum].cooltime;
						//mp 혹은 스테미너 소모
						if (player.skills[skillNum].atkAttr == 1)
						{
							if (player.stamina < player.skills[skillNum].consumeMP)
							{
								printf("스태미너가 부족합니다.\n");
								continue;
							}
							else
							{
								player.stamina -= player.skills[skillNum].consumeMP;
							}
						}
						else
						{
							if (player.mp < player.skills[skillNum].consumeMP)
							{
								printf("MP가 부족합니다.\n");
								continue;
							}
							else
							{
								player.mp -= player.skills[skillNum].consumeMP;
							}
						}
						
						//공격 실행
						printf("%s\n", player.skills[skillNum].name);
						agility = (rand() % 1000) / 10;
						if (agility < zombies[i].agi)
						{
							printf("좀비를 공격하였으나 피했습니다!\n");
						}
						else
						{
							zombies[i].hp -= attackDamage;
							printf("좀비를 공격 하여 %d 만큼 데미지를 주었다!\n", attackDamage);
						}
						Sleep(1000);

						break;
					}
				default:
					continue;
				}
			}
			else if (battleSelectMode == 2)
			{
				cout << (itemNum == 0 ? " > " : "   ") << "라면(HP - 200 회복)" << endl;
				cout << (itemNum == 1 ? " > " : "   ") << "코카콜라(MP - 150 회복)" << endl;
				cout << (itemNum == 2 ? " > " : "   ") << "쵸코바(stamina - 150 회복)" << endl;
				cout << (itemNum == 3 ? " > " : "   ") << "이전 메뉴로" << endl;

				battleInput = _getch();
				switch (battleInput)
				{
				case 72: //상 방향키
					itemNum--;
					if (itemNum < 0) itemNum = 3;
					continue;
				case 80: //하 방향키
					itemNum++;
					if (itemNum > 3) itemNum = 0;
					continue;
				case 13: //엔터키
					if (itemNum == 0)
					{
						player.hp += 200;
						if (player.hp > player.maxHp) player.hp = player.maxHp;
						break;
					}
					else if (itemNum == 1)
					{
						player.mp += 150;
						if (player.mp > player.maxMp) player.mp = player.maxMp;
						break;
					}
					else if (itemNum == 2)
					{
						player.stamina += 150;
						if (player.stamina > player.maxStamina) player.stamina = player.maxStamina;
						break;
					}
					else if (itemNum == 3)
					{
						battleSelectMode = 0;
						continue;
					}
				default:
					continue;
				}
			}
			
			if (zombies[i].hp <= 0)
			{
				printf("%s가 죽었습니다.\n", zombies[i].name);


				Sleep(1000);
				break;
			}

			//좀비 턴
			int zombieAI = rand() % 5;
			if (zombieAI < length(zombies[i].skills) &&
				((zombies[i].skills[zombieAI].atkAttr == 1 && zombies[i].stamina > zombies[i].skills[zombieAI].consumeMP) ||
				(zombies[i].skills[zombieAI].atkAttr == 2 && zombies[i].mp > zombies[i].skills[zombieAI].consumeMP)))
			{
				damage = (zombies[i].skills[zombieAI].atkAttr == 1) ? zombies[i].atk + zombies[i].str + (zombies[i].dex / 2) : zombies[i].matk + zombies[i].dex;
				minDamage = damage * (9 / 10);
				maxDamage = damage * (11 / 10);
				attackDamage = (rand() % (maxDamage - minDamage - 1) + maxDamage) * zombies[i].skills[skillNum].magPower;

				printf("%s 의 %s!\n", zombies[i].name, zombies[i].skills[zombieAI].name);
			}
			else
			{
				damage = (zombies[i].atkAttr == 1) ? zombies[i].atk + zombies[i].str + (zombies[i].dex / 2) : zombies[i].matk + zombies[i].dex;
				minDamage = damage * (9 / 10);
				maxDamage = damage * (11 / 10);
				attackDamage = (rand() % (maxDamage - minDamage - 1) + maxDamage);
				
				player.hp -= attackDamage;
				
				printf("좀비가 공격합니다!\n");
			}

			Sleep(1000);

			agility = (rand() % 1000) / 10;
			if (agility < zombies[i].agi)
			{
				printf("좀비의 공격을 피했습니다!\n");
			}
			else
			{
				player.hp -= attackDamage;
				printf("%d 만큼 데미지를 입었다!\n", attackDamage);
			}

			Sleep(1000);

			if (player.hp <= 0)
			{
				printf("플레이어가 죽었습니다..\n");
				Sleep(1000);
				exit(0);
			}

			battleSelectMode = 0;
		}
	}
	return 0;
}


