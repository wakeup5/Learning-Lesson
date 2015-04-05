/* 04-02 ~ 04-05 ����-�ָ� ����
 * RPG ������
 * 1. �ɸ��� ����. 3��. ���� ����. ���� ������ ����.
 * ���� HP MP EXP STR DEX STAMINA AGI(ȸ��) ATK DEF MATK MDEF ��ų 3���� �̸� ǥ�õǰ� �� �� �ִ�.
 * ����, ����, �뷱�� �� �ɸ� ������ ������ ����.
 * 
 * 2. ���ѷα�.
 * ���� ������ �´� ���� �̾߱Ⱑ �־�� �Ѵ�. ���ڷ��̼�.. ����
 *
 * 3. ����
 * (1) ���ݷ�, (2) ��ų, (3) ������ �޴��� �־�� �Ѵ�.
 * �� 5������ ���� �� ���� ����.
 * ���� óġ �� ���� ������ ��.
 *
 * 4. ������ ����.
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
	
	//�ܼ� ũ��, ����ũ�� ����
	system("mode CON COLS=101 LINES=50");
	//������
	for (int i = 0; i < length(opening); i++)
	{
		system("cls");
		cout << opening[i];
	}

	Sleep(1000);

	//�ɸ���, ���� �� ����.
	Unit character[3] = {
		{ "��Ʈû��", 1, 0.0, 1000, 150, 100, 50, 40, 20.0, 100, 50, 10, 10,	1, { { "�Ӹ�����!", 1, 2.5, 30, 2 },{ "�߸�Ÿ��!", 2, 1.5, 20, 2 }, { "�׾�� ������!!", 1, 3.5, 50, 3 }}},
		{ "�ظӾ�����", 1, 0.0, 1200, 100, 100, 50, 40, 20.0, 150, 50, 10, 10, 1, { { "���ϰ� �ֵθ���!!", 1, 1.5, 20, 2 }, { "������ �ֵθ���!!", 1, 2.0, 30, 3 }, { "ȥ���� ���� �ֵθ���!!", 1, 3.5, 50, 5 } } },
		{ "å�ư���", 1, 0.0, 800, 500, 0, 50, 40, 20.0, 10, 20, 110, 50, 2, {{ "���� ��ô!!", 2, 1.5, 20, 2 },{ "å ��ô!!", 2, 2.0, 30, 3 },{ "�Կ��� �һձ�!!", 2, 3.5, 50, 5 }}}
	};

	Unit zombies[6] = {
		{ "����", 1, 0.0, 500, 200, 200, 30, 20, 10.0, 50, 20, 10, 10, 1, { { "������", 1, 2.5, 30 }, { "����", 1, 1.5, 20 }, { "���ϱ�", 1, 3.5, 50 } } },
		{ "����", 1, 0.0, 500, 200, 200, 30, 20, 10.0, 50, 20, 10, 10, 1,
			{
				{ "������", 1, 2.5, 30 },
				{ "����", 1, 1.5, 20 },
				{ "���ϱ�", 1, 3.5, 50 }
			}
		},
		{ "����", 1, 0.0, 500, 200, 200, 30, 20, 10.0, 50, 20, 10, 10, 1,
			{
				{ "������", 1, 2.5, 30 },
				{ "����", 1, 1.5, 20 },
				{ "���ϱ�", 1, 3.5, 50 }
			}
		},
		{ "����", 1, 0.0, 500, 200, 200, 30, 20, 10.0, 50, 20, 10, 10, 1,
			{
				{ "������", 1, 2.5, 30 },
				{ "����", 1, 1.5, 20 },
				{ "���ϱ�", 1, 3.5, 50 }
			}
		},
		{ "����", 1, 0.0, 500, 200, 200, 30, 20, 10.0, 50, 20, 10, 10, 1,
			{
				{ "������", 1, 2.5, 30 },
				{ "����", 1, 1.5, 20 },
				{ "���ϱ�", 1, 3.5, 50 }
			}
		},
		{ "���񺸽�", 1, 0.0, 1500, 500, 500, 150, 150, 25.0, 150, 50, 30, 20, 1,
			{
				{ "�� �ֵθ���", 1, 2.5, 30 },
				{ "��ġ��", 1, 1.5, 20 },
				{ "���̷��� �Ȱ�", 1, 3.5, 50 }
			}
		}
	};

	Unit player;
	
	//�ɸ��� ����

	int selectNum = 0;
	int selectinput;

	while (true)
	{
		system("cls");
		printf(characterPicture[selectNum]);

		Unit chara = character[selectNum];

		printf("%s �⺻�ɷ�ġ\nHP\tMP\tStamina\tStr\tDex\tAgi\tAkt\tDef\tMDtk\tMDef\n", chara.name);
		printf("%d\t%d\t%d\t%d\t%d\t%.1f\t%d\t%d\t%d\t%d\n\n", chara.maxHp, chara.maxMp, chara.maxStamina, chara.str, chara.dex, chara.agi, chara.atk, chara.def, chara.matk, chara.mdef);

		printf("��ų��\t\t\tŸ��\t����\t�Ҹ�\n");
		for (int i = 0; i < 3; i++)
		{
			printf("%23s\t", chara.skills[i].name);
			if (chara.skills[i].atkAttr == 1) printf("����\t");
			else if (chara.skills[i].atkAttr == 2) printf("����\t");
			printf("%.1f\t%d\n", chara.skills[i].magPower, chara.skills[i].consumeMP);
		}

		printf("\n�ɸ��� ����.\n");
		for (int i = 0; i < 3; i++)
		{
			if (selectNum == i) cout << " > ";
			else cout << "   ";
			cout << (i + 1) << ". " << character[i].name << endl;
		}
		
		selectinput = _getch();
		switch (selectinput)
		{
		case 72: //�� ����Ű
			selectNum--;
			if (selectNum < 0) selectNum = 2;
			continue;
		case 80: //�� ����Ű
			selectNum++;
			if (selectNum > 2) selectNum = 0;
			continue;
		case 13: //����Ű
			player = character[selectNum];
			break;
		default:
			continue;
		}

		break;
	}

	int battleInput;
	int battleSelectMode = 0;//0 = �ֻ���, 1 = ��ų, 2 = ������
	int battleNum = 0;
	int skillNum = 0;
	int itemNum = 0;

	int damage = 0;
	int minDamage = 0;
	int maxDamage = 0;
	int attackDamage = 0;
	float agility = 0;

	//�ܸ� ���� ����
	for (int i = 0; i < 6; i++)
	{
		battleSelectMode = battleNum = skillNum = itemNum = damage = minDamage = maxDamage = attackDamage = 0;
		agility = 0.0;

		//�� ���� ���¹̳� �ִ�ġ �ʱ�ȭ
		player.hp = player.maxHp;
		player.mp = player.maxMp;
		player.stamina = player.maxStamina;

		//���� �� �ʱ�ȭ
		zombies[i].hp = zombies[i].maxHp;
		zombies[i].mp = zombies[i].maxMp;
		zombies[i].stamina = zombies[i].maxStamina;

		system("cls");
		cout << zombies[i].name << "�� ��Ÿ����!" << endl;
		Sleep(1000);
		while (true)
		{
			system("cls");
			printf("====================================================================================================\n");
			printf("player HP : %d\n", player.hp);
			printf("player MP : %d\n", player.mp);
			printf("player Stamina : %d\n" , player.stamina);
			printf("������ ü�� : %d\n", zombies[i].hp);

			//�÷��̾� ��
			if (battleSelectMode == 0)
			{
				cout << (battleNum == 0 ? " > " : "   ") << "����" << endl;
				cout << (battleNum == 1 ? " > " : "   ") << "��ų ���" << endl;
				cout << (battleNum == 2 ? " > " : "   ") << "������ ���" << endl;

				battleInput = _getch();
				switch (battleInput)
				{
				case 72: //�� ����Ű
					battleNum--;
					if (battleNum < 0) battleNum = 2;
					continue;
				case 80: //�� ����Ű
					battleNum++;
					if (battleNum > 2) battleNum = 0;
					continue;
				case 13: //����Ű
					if (battleNum == 0)
					{
						//���� ���� ���ݷ� ���� �⺻���ݷ�+��+(��ø/2) �ּҰ��ݷ� 90%, �ִ� 110%;
						//���� ���� ���ݷ� ���� �⺻�����ݷ�+��ø
						damage = (player.atkAttr == 1) ? player.atk + player.str + (player.dex / 2) : player.matk + player.dex;
						minDamage = damage * (9 / 10);
						maxDamage = damage * (11 / 10);
						attackDamage = rand() % (maxDamage - minDamage - 1) + maxDamage;

						//ȸ�� ����
						agility = (rand() % 1000) / 10;
						if (agility < zombies[i].agi)
						{
							printf("���� �����Ͽ����� ���߽��ϴ�!");
						}
						else
						{
							zombies[i].hp -= attackDamage;
							printf("���� ���� �Ͽ� %d ��ŭ �������� �־���!\n", attackDamage);
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
				cout << "��ų ���" << endl;
				int j = 0;
				for (; j < length(player.skills); j++)
				{
					cout << (skillNum == j ? " > " : "   ") << player.skills[j].name << endl;
				}
				cout << (skillNum == j ? " > " : "   ") << "���� �޴���" << endl;
				
				battleInput = _getch();
				switch (battleInput)
				{
				case 72: //�� ����Ű
					skillNum--;
					if (skillNum < 0) skillNum = 3;
					continue;
				case 80: //�� ����Ű
					skillNum++;
					if (skillNum > 3) skillNum = 0;
					continue;
				case 13: //����Ű
					if (skillNum == length(player.skills))
					{
						battleSelectMode = 0;
						continue;
					}
					else
					{
						//��ų ���ݷ� ���� ���� ���ݷ� * ��ų ����
						damage = (player.skills[skillNum].atkAttr == 1) ? player.atk + player.str + (player.dex / 2) : player.matk + player.dex;
						minDamage = damage * (9 / 10);
						maxDamage = damage * (11 / 10);
						attackDamage = (rand() % (maxDamage - minDamage - 1) + maxDamage) * player.skills[skillNum].magPower;
						
						//��Ÿ��
						if (player.skills[skillNum].cooltimeLeft != 0)
						{
							printf("��Ÿ�� �Դϴ�.\n");
							continue;
						}
						//��Ÿ�� ��ü -1;
						for (int k = 0; k < length(player.skills); k++)
						{
							if (player.skills[k].cooltimeLeft > 0) player.skills[k].cooltimeLeft--;
						}

						player.skills[skillNum].cooltimeLeft = player.skills[skillNum].cooltime;
						//mp Ȥ�� ���׹̳� �Ҹ�
						if (player.skills[skillNum].atkAttr == 1)
						{
							if (player.stamina < player.skills[skillNum].consumeMP)
							{
								printf("���¹̳ʰ� �����մϴ�.\n");
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
								printf("MP�� �����մϴ�.\n");
								continue;
							}
							else
							{
								player.mp -= player.skills[skillNum].consumeMP;
							}
						}
						
						//���� ����
						printf("%s\n", player.skills[skillNum].name);
						agility = (rand() % 1000) / 10;
						if (agility < zombies[i].agi)
						{
							printf("���� �����Ͽ����� ���߽��ϴ�!\n");
						}
						else
						{
							zombies[i].hp -= attackDamage;
							printf("���� ���� �Ͽ� %d ��ŭ �������� �־���!\n", attackDamage);
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
				cout << (itemNum == 0 ? " > " : "   ") << "���(HP - 200 ȸ��)" << endl;
				cout << (itemNum == 1 ? " > " : "   ") << "��ī�ݶ�(MP - 150 ȸ��)" << endl;
				cout << (itemNum == 2 ? " > " : "   ") << "���ڹ�(stamina - 150 ȸ��)" << endl;
				cout << (itemNum == 3 ? " > " : "   ") << "���� �޴���" << endl;

				battleInput = _getch();
				switch (battleInput)
				{
				case 72: //�� ����Ű
					itemNum--;
					if (itemNum < 0) itemNum = 3;
					continue;
				case 80: //�� ����Ű
					itemNum++;
					if (itemNum > 3) itemNum = 0;
					continue;
				case 13: //����Ű
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
				printf("%s�� �׾����ϴ�.\n", zombies[i].name);


				Sleep(1000);
				break;
			}

			//���� ��
			int zombieAI = rand() % 5;
			if (zombieAI < length(zombies[i].skills) &&
				((zombies[i].skills[zombieAI].atkAttr == 1 && zombies[i].stamina > zombies[i].skills[zombieAI].consumeMP) ||
				(zombies[i].skills[zombieAI].atkAttr == 2 && zombies[i].mp > zombies[i].skills[zombieAI].consumeMP)))
			{
				damage = (zombies[i].skills[zombieAI].atkAttr == 1) ? zombies[i].atk + zombies[i].str + (zombies[i].dex / 2) : zombies[i].matk + zombies[i].dex;
				minDamage = damage * (9 / 10);
				maxDamage = damage * (11 / 10);
				attackDamage = (rand() % (maxDamage - minDamage - 1) + maxDamage) * zombies[i].skills[skillNum].magPower;

				printf("%s �� %s!\n", zombies[i].name, zombies[i].skills[zombieAI].name);
			}
			else
			{
				damage = (zombies[i].atkAttr == 1) ? zombies[i].atk + zombies[i].str + (zombies[i].dex / 2) : zombies[i].matk + zombies[i].dex;
				minDamage = damage * (9 / 10);
				maxDamage = damage * (11 / 10);
				attackDamage = (rand() % (maxDamage - minDamage - 1) + maxDamage);
				
				player.hp -= attackDamage;
				
				printf("���� �����մϴ�!\n");
			}

			Sleep(1000);

			agility = (rand() % 1000) / 10;
			if (agility < zombies[i].agi)
			{
				printf("������ ������ ���߽��ϴ�!\n");
			}
			else
			{
				player.hp -= attackDamage;
				printf("%d ��ŭ �������� �Ծ���!\n", attackDamage);
			}

			Sleep(1000);

			if (player.hp <= 0)
			{
				printf("�÷��̾ �׾����ϴ�..\n");
				Sleep(1000);
				exit(0);
			}

			battleSelectMode = 0;
		}
	}
	return 0;
}


