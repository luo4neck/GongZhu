#include"stdlib.h"
#include"iostream"
#include"clocale"
#include"card.h"
//#include"player.h"

using namespace std;

void print_table(int on_table[], CARD *card);
int Play(int first, PLAYER P0, PLAYER P1, PLAYER P2, PLAYER P3, CARD *card);

int main()
{
	// Initializing..
	setlocale(LC_ALL, "");
	CARD *card = new CARD[53]; // 0-52, 0 will never be used..
	for(int i=1; i<53; ++i)
	{
		card[i].Init(i);
		card[i].Prt();
		if(i%13 == 0) wcout<<endl;	
	}
	
	PLAYER P0(0), P1(1), P2(2), P3(3);
	// Game start.. every one selling..
	
	//while(0)// game loop..
	{
		//洗牌。。
		int *shuffle = Shuffle();

		//发牌。。
		int first_guy = 0;
		for( int i=0; i<52; ++i)
		{
			//wcout<<shuffle[i]<<endl;
			if( i < 13)		  P0.hand[i] = shuffle[i] + 1;
			else if ( i < 26) P1.hand[i-13] = shuffle[i] + 1;
			else if ( i < 39) P2.hand[i-26] = shuffle[i] + 1;
			else 			  P3.hand[i-39] = shuffle[i] + 1;
		
			if (shuffle[i] == 27) first_guy =  (i-i%13)/13;
		}
		
		wcout<<first_guy<<endl;
		qsort(P0.hand, 13, sizeof(int), compare);
		qsort(P1.hand, 13, sizeof(int), compare);
		qsort(P2.hand, 13, sizeof(int), compare);
		qsort(P3.hand, 13, sizeof(int), compare);
		for(int i=0; i<13; ++i) card[P0.hand[i]].Prt(); wcout<<endl;
		for(int i=0; i<13; ++i) card[P1.hand[i]].Prt(); wcout<<endl;
		for(int i=0; i<13; ++i) card[P2.hand[i]].Prt(); wcout<<endl;
		for(int i=0; i<13; ++i) card[P3.hand[i]].Prt(); wcout<<endl;
		
		// play..
		for(int round_i=0; round_i<3; ++round_i)
		{
			first_guy = Play(first_guy, P0, P1, P2, P3, card);
		}
	}
	
	delete[] card;
	wcout<<"fine at last"<<endl;
	
    return 0;
}

void print_table(int on_table[], CARD* card)
{	
	wcout<<"   ";
	for(int i=0; i<25; ++i) wcout<<"_";
	wcout<<endl;
	
	for(int i=0; i<10; ++i)
	{
		if(i == 0) 
		wcout<<"  |        Player 2         |"<<endl;
		else if(i == 4) 
		wcout<<"  | Player 1       Player 3 |"<<endl;
		else if(i == 8) 
		wcout<<"  |            ME           |"<<endl;
		else if(on_table[2] > 0 && i ==1 ) //玩家2出过牌。。
		{
			int card_id = on_table[2];
			wcout<<"  |          ";
			card[card_id].Prt();
			wcout<<"           |"<<endl;
		}
		else if(on_table[2] > 0 && i ==1 ) //玩家1出过牌。。
		{
			int card_id = on_table[2];
			wcout<<"  |          ";
			card[card_id].Prt();
			wcout<<"           |"<<endl;
		}
		else if(on_table[2] > 0 && i ==1 ) //玩家3出过牌。。
		{
			int card_id = on_table[2];
			wcout<<"  |          ";
			card[card_id].Prt();
			wcout<<"           |"<<endl;
		}
		else 
		wcout<<"  |                         |"<<endl;
	}
		
	wcout<<"  |";
	for(int i=0; i<25; ++i) wcout<<"_";
	wcout<<"|"<<endl;
}

int Play(int first, PLAYER P0, PLAYER P1, PLAYER P2, PLAYER P3, CARD *card)
{
	int on_table[4]={0,0,0,0};

	if(first == 0)
	{	
		print_table(on_table, card);
		P0.play(on_table);
		P1.play(on_table);
		P2.play(on_table);
		P3.play(on_table);
	}
	
	if(first == 1)
	{	
		P1.play(on_table);
		P2.play(on_table);
		P3.play(on_table);
		
		print_table(on_table, card);
		P0.play(on_table);
	}
	
	if(first == 2)
	{	
		P2.play(on_table);
		P3.play(on_table);
		
		print_table(on_table, card);
		P0.play(on_table);
		P1.play(on_table);
	}
	
	if(first == 3)
	{	
		P3.play(on_table);
		
		print_table(on_table, card);
		P0.play(on_table);
		P1.play(on_table);
		P2.play(on_table);
	}
	
	int next = 1;
	//int next = 4Cmp(on_table);
	return next;
}









