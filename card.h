#include"iostream"

using namespace std;

const wchar_t spade[]  = L"\u2660";
//const wchar_t heart[]  = L"\u2665";
const wchar_t heart[]  = L"\u2661";
const wchar_t club[]   = L"\u2663";
//const wchar_t diamond[]= L"\u2666";
const wchar_t diamond[]= L"\u2662";

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
		int I = Id()%13;
		if(I != 10) wcout<<" ";
		
		if (Id() <= 13) 	 wcout<<spade  <<L"";
		else if (Id() <= 26) wcout<<heart  <<L"";
		else if (Id() <= 39) wcout<<club   <<L"";
		else 				 wcout<<diamond<<L"";
		
		if (I == 1)		  wcout<<"A";
		else if (I == 11) wcout<<"J";
		else if (I == 12) wcout<<"Q";
		else if (I == 0 ) wcout<<"K";
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

	for(int i=0; i<900; ++i) // shuffle for 500 times..
	{
		int a = lrand48()%52, tmp, b = lrand48()%52;
		tmp	  = sh[a];
		sh[a] = sh[b];
		sh[b] = tmp;
	}
	return sh;
}

// player class start here.. 
class PLAYER
{
	private:
	bool sheep; //羊。。
	bool pig; //猪。。
	bool bian; //变压器。。
	int score;
	int score_sum;
	public:
	int hand[13];

	PLAYER()
	{
		sheep = 0;
		pig = 0;
		bian = 0;
		score = 0;
		score_sum = 0;
	}
	
	void play(int on_table[])
	{
	
	}

	const int Score()
	{
		//本局分数。。
		return score;
	}
	
	const int ScoreSum()
	{
		//输出已经加上的新分数。。
		return score_sum;
	}
};

int compare(const void *a, const void *b) // used to quick sorting..
{
	int *pa = (int*)a;
	int *pb = (int*)b;
	return (*pa) - (*pb);
}
