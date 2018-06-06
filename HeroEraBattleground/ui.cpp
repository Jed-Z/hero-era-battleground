#include "ui.h"
#include <string>
#include <Windows.h>
/* Print a split line */
void split_line() {
	cout << " " << string(100 ,'=') << endl;
}

/* Print introduction */
void print_introduction() {
	system("cls");	// Clear screen.
	cout << string(10, '\n');
	cout << string(40, ' ') << "WELCOME TO [ HERO ERA BATTLEGROUND ] !" << endl << endl;
	cout << string(40, ' ') << "PRESS [ SPACE ] TO PLAY." << endl;
	cout << string(40, ' ') << "PRESS [ H ] FOR GAMING HELP." << endl;
	cout << string(40, ' ') << "PRESS [ ESC ] TO EXIT." << endl;

	//cout << string(40, ' ') << "PRESS [ I ] FOR INFORMATION." << endl;
	cout << string(5, '\n');
}

/* Print gaming help */
void print_help(int lang) {
	system("cls");	// Clear screen.
	cout << string(7, '\n');
	cout << string(45, ' ') << "NEW ERA BATTLEGROUND " << endl << endl;
	if (lang == 0) {
		cout << "\tIn this game you will play a hero. You will participate in multiple games if you can keep alive.\n\
	In each game, you will encounter an enemy hero, and you will conduct multiple rounds of fighting.\n\n\
	At the beginning, both heroes have 100 HP. In each round, you and the enemy can each perform one\n\
	operation. These operations include \"attack\", \"recover\", \"buy equipment\", \"sell equipment\", etc.\n\n\
	In this battle, if you defeat the enemy, then the game ends.You can choose to start a new game\n\
	again and accumulate points.Of course you can also exit the game.However, if your hero dies, the\n\
	game ends immediately and you will see your final score.\n" << endl;
		cout << "\tEnjoy it!\n" << endl;
	}
	else {
		cout << "\t  在这个游戏中，你将要扮演一名英雄。你将会参加多场游戏，如果你能一直保持存活的话。每局游戏中，你都会\n\
	遇到一个敌人英雄，你们将进行多回合的战斗。一开始，双方英雄都各自拥有100点生命值。每一回合中，你和敌\n\
	人可以各进行一次操作。这些操作包括“攻击”“恢复”“购买装备”“卖出装备”等。\n\n\
	  在这场战斗中，如果你战胜了敌人，那么该局游戏结束。你可以选择重新开始新的一局游戏，积分累计。当然你\n\
	也可以退出游戏。然而，如果你的英雄死亡了，那么游戏立即结束，你将看到你的最终得分。\n" << endl;
		cout << "\t  尽情享受吧！\n" << endl;
	}
	cout << "\tPRESS [ ANY KEY ] TO GO BACK." << endl;
	cout << string(5, '\n');
}

/* Print goodbye */
void print_bye() {
	for (int i = 3; i > 0; i--) {
		system("cls");	// Clear screen.
		cout << string(7, '\n');
		cout << string(50, ' ') << "NEW ERA BATTLEGROUND " << endl << endl;
		cout << "\tGood bye, my hero. Hope you have had fun in this game. Looking forward to your return.\n" << endl;
		cout << "\tWindow will close in ";
		cout << i << " seconds." << endl;
		Sleep(1000);	// Terminates in 3 seconds.
	}
	exit(0);
}