#include"stdlib.h"
#include"iostream"
#include"clocale"
#include"card.hpp"
#include"head.hpp"

using namespace std;

void print_table(int on_table[], CARD *card);
int Play(int first, PLAYER &P0, PLAYER &P1, PLAYER &P2, PLAYER &P3, CARD *card);
int four_max(int first, int on_table[], CARD* card);
int Allmark(int on_table[], CARD* card);
void Sellall(bool trans, PLAYER P0, CARD *card);

int main()
{
	// Initializing..
	setlocale(LC_ALL, "");
	CARD *card = new CARD[53]; // 0-52, 0 will never be used..
	for(int i=1; i<53; ++i)
	{
		card[i].Init(i);
	}
	
	PLAYER P0(0), P1(1), P2(2), P3(3);
	// Game start.. every one selling..
	
	while(1)// game loop..
	{
		//洗牌。。
		int *shuffle = Shuffle();

		//发牌。。
		int first_guy = 0;
		for( int i=0; i<52; ++i)
		{
			if( i < 13)		  P0.hand[i] = shuffle[i] + 1;
			else if ( i < 26) P1.hand[i-13] = shuffle[i] + 1;
			else if ( i < 39) P2.hand[i-26] = shuffle[i] + 1;
			else 			  P3.hand[i-39] = shuffle[i] + 1;
		
			if (shuffle[i] == 27) first_guy =  (i-i%13)/13;
		}
		
		qsort(P0.hand, 13, sizeof(int), compare);
		qsort(P1.hand, 13, sizeof(int), compare);
		qsort(P2.hand, 13, sizeof(int), compare);
		qsort(P3.hand, 13, sizeof(int), compare);
		
		wcout<<"Cards in my hand:"<<endl;
		for(int i=0; i<13; ++i) card[P0.hand[i]].Prt(); wcout<<endl;
		/*
		for(int i=0; i<13; ++i) card[P1.hand[i]].Prt(); wcout<<endl;
		for(int i=0; i<13; ++i) card[P2.hand[i]].Prt(); wcout<<endl;
		for(int i=0; i<13; ++i) card[P3.hand[i]].Prt(); wcout<<endl;
		*/
		// play..
		
		//sell or not, 0 is not sold, 1 is sold..
		bool trans=0;
		Sellall(trans, P0, card);
		
		P0.SetScore();
		P1.SetScore();
		P2.SetScore();
		P3.SetScore();

		for(int round_i=0; round_i<13; ++round_i)
		{
			wcout<<endl<<"+ + + + + + + + + + + + + + + + ";
			wcout<<"+ + + + + + + + + + + + + + + + + "<<endl;
			wcout<<"This is round "<<round_i + 1<<endl;
			
			first_guy = Play(first_guy, P0, P1, P2, P3, card);
			wcout<<"Round "<<round_i + 1<<" finished!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		}
		wcout<<"Player 0 get "<<P0.Score()<<" in this game. Totally credit: "<<P0.ScoreSum()<<endl<<endl;
		wcout<<"Player 1 get "<<P1.Score()<<" in this game. Totally credit: "<<P1.ScoreSum()<<endl<<endl;
		wcout<<"Player 2 get "<<P2.Score()<<" in this game. Totally credit: "<<P2.ScoreSum()<<endl<<endl;
		wcout<<"Player 3 get "<<P3.Score()<<" in this game. Totally credit: "<<P3.ScoreSum()<<endl<<endl;
		
		wcout<<"Have a new game? (y/n)? ";
		wchar_t check;
		wcin>>check;
		if(check == 'n') break;
		else 			wcout<<"\n\n\n\nNew game start!\n";
	}
	
	delete[] card;
	wcout<<endl<<"Thank you for play the game!"<<endl;
	
    return 0;
}
