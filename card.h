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
	
	~CARD() {}
	
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

	const void Prt()
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
	
	const int Clr() 
	{ 
		if( Id() <= 13)			return 0; // spade..
		else if ( Id() <= 26 )  return 1; // heart..
		else if ( Id() <= 39 )  return 2; // club..
		else 					return 3; // diamond..
	}
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
	const int id;
	public:
	int hand[13];

	PLAYER(int I): id(I)
	{
		sheep = 0;
		pig = 0;
		bian = 0;
		score = 0;
		score_sum = 0;
	}
	
	~PLAYER() {};

	void play(int on_table[])
	{
		int count = 0; //数数桌上有几张牌了。。
		for( int i=0; i<4; ++i)
		{
			if ( on_table[i] != 0 ) count++;
		}
			
		int inhand = 0;
		for( int i=0; i<13; ++i)
		{
			if( hand[i] != 0) inhand++;// 数数手里还有多少张牌。。
		}

		if ( count == 0 ) // 没牌。。先出。。 
		{

			if ( inhand == 13) // 手里有13张牌。。第一把。。应该出草花2。。
			{
				
			}
			else
			{
			
			}
		}
		else 
		{
		
		}
		
		int out = 13 - inhand; 

		on_table[ Id() ] = hand[out];// give a card from hand onto the table..
		hand[out] = 0; // this position is empty now.. set to 0..
	}
	
	const int Id() { return id; }
	
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
