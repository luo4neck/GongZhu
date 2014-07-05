#include"stdlib.h"
#include"iostream"
#include"clocale"
#include"card.h"
#include"player.h"

using namespace std;

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
	
	PLAYER P0, P1, P2, P3;
	// Game start.. every one selling..
	
	//while(0)// game loop..
	{
		//洗牌。。
		int *shuffle = Shuffle();

		//发牌。。
		for( int i=0; i<52; ++i)
		{
			wcout<<shuffle[i]<<endl;
			if( i < 13)		  P0.hand[i] = shuffle[i] + 1;
			else if ( i < 26) P1.hand[i-13] = shuffle[i] + 1;
			else if ( i < 39) P2.hand[i-26] = shuffle[i] + 1;
			else 			  P3.hand[i-39] = shuffle[i] + 1;
		}
		
		for(int i=0; i<13; ++i) card[P0.hand[i]].Prt(); wcout<<endl;
		for(int i=0; i<13; ++i) card[P1.hand[i]].Prt(); wcout<<endl;
		for(int i=0; i<13; ++i) card[P2.hand[i]].Prt(); wcout<<endl;
		for(int i=0; i<13; ++i) card[P3.hand[i]].Prt(); wcout<<endl;

		for(int round_i=0; round_i<13; ++round_i)
		{
			
		}
	
		// play..
	}
	
	delete[] card;
	wcout<<"fine at last"<<endl;
	
    return 0;
}
