#include"stdlib.h"
#include"iostream"
#include"clocale"
#include"card.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	CARD *card = new CARD[53]; // 0-52, 0 will never be used..
	for(int i=1; i<53; ++i)
	{
		card[i].Init(i);
		card[i].Prt();
		if(i%13 == 0) cout<<endl;	
	}

	
	cout<<"fine at last"<<endl;
    return 0;
}
