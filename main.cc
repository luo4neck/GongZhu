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
		if(i%13 == 0) cout<<endl;	
	}
	
	PLAYER P1, P2, P3, P4;
	// Game start.. every one selling..
	
	while(0)// game loop..
	{
		//洗牌。。

		//发牌。。

		for(int round_i=0; round_i<13; ++round_i)
		{
			
		}
	}
	
	delete[] card;
	cout<<"fine at last"<<endl;
	
    return 0;
}
