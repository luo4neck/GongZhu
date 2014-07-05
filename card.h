#include"iostream"

using namespace std;

const wchar_t spade[]  = L"\u2660";
const wchar_t heart[]  = L"\u2665";
//const wchar_t heart[]  = L"\u2661";
const wchar_t club[]   = L"\u2663";
const wchar_t diamond[]= L"\u2666";
//const wchar_t diamond[]= L"\u2662";

class CARD
{
	private:
	int id;
	int weight;
	int credit;
	
	public:
	CARD() {}
	
	void Init(const int ID)
	{
		id = ID;
		
		int wgt = ID;
		wgt = wgt%13;
		if (wgt == 1)	   weight = 14;
		else if (wgt == 0) weight = 13;
		else			   weight = wgt;
		
		if (ID == 12)			credit = -100; //pig.. 
		else if (ID == 14)		credit = -50; // heart A
		else if (ID>17&&ID<24)  credit = -10; // heart 5,6,7,8,9,10
		else if ( ID == 24 )	credit = -20; // heart J..
		else if ( ID == 25 )	credit = -30; // heart Q..
		else if ( ID == 26 )	credit = -40; // heart k..
		else if ( ID == 50 )	credit = 100; // sheep.. 
		else					credit = 0; 
	}

	void Prt()
	{
		if (Id() <= 13) 	 wcout<<spade  <<L"";
		else if (Id() <= 26) wcout<<heart  <<L"";
		else if (Id() <= 39) wcout<<club   <<L"";
		else 				 wcout<<diamond<<L"";
		
		int I = Id()%13;
		
		if (I == 1)		  wcout<<"A";
		else if (I == 11) wcout<<"J";
		else if (I == 12) wcout<<"Q";
		else if (I == 0 ) wcout<<"K";
		else if (I < 10)  wcout<<I;
		else			  wcout<<I;
		
		wcout<<" ";
		//wcout<<"-"<<Id()<<" ";
	}

	const int Id()  { return id; }
	
	const int Wgt() { return weight; }
	
	const int Crt() { return credit; }
};

int *Shuffle()
{
	srand48(time(NULL));
	int *sh = new int[52];
	for(int i=0; i<52; ++i) sh[i] = i;

	for(int i=0; i<500; ++i) // shuffle for 500 times..
	{
		int a = lrand48()%52;
		int b = lrand48()%52;
		int tmp;
		tmp	  = sh[a];
		sh[a] = sh[b];
		sh[b] = tmp;
	}
	return sh;
}
