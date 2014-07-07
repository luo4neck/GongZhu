#include"iostream"
#include"iomanip"

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
	
	void Double()	{ credit = credit * 2; }
	
	const int Id()  { return id; }
	
	const int Wgt() { return weight; }
	
	const int Crt() { return credit; }
	
	const int Clr() 
	{ 
		if( Id() <= 13)			return 1; // spade..
		else if ( Id() <= 26 )  return 2; // heart..
		else if ( Id() <= 39 )  return 3; // club..
		else 					return 4; // diamond..
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
	bool trans;
	int score;
	int score_sum;
	const int id;
	public:
	int hand[13];

	PLAYER(int I): id(I)
	{
		trans = 0;
		score = 0;
		score_sum = 0;
	}
	
	~PLAYER() {};
	
	void playme(int on_table[], CARD *card)
	{
	/*
		for(int i=0; i<13; ++i)
		{
			wcout<<hand[i]<<" ";
		}
		wcout<<endl; */
    	wcout<<"In my hand: ";
     	for(int i=0; i<13; ++i)
		{
	        if ( hand[i] == 0 ) wcout<<"   ";
			else card[ hand[i] ].Prt();
		}
		wcout<<endl<<"Card Number: ";
	
		for(int i=0; i<13; ++i)
		{
			if ( hand[i] != 0 )	wcout<<setw(2)<<i<<"  "; 
			else                wcout<<"   ";
		}
		wcout<<endl;
		
		int dom_clr; //dominent colour..
		if ( on_table[1] > 0 ) 		dom_clr = card[ on_table[1] ].Clr();
		else if ( on_table[2] > 0 ) dom_clr = card[ on_table[2] ].Clr();
		else if ( on_table[3] > 0 ) dom_clr = card[ on_table[3] ].Clr();
		else 								dom_clr = 0;

		while(1)
		{
			wcout<<"Please select a card to send out"<<endl;
			int re;
			wcin>>re;
		
			if ( wcin.fail() || re<0 || re>12 || hand[re]==0 )
			// 选一张牌出处去。。检测是否合法。。 
			{
				wcout<<"Wrong input!"<<endl;
			}
				else 
			{
				bool have = 0;
				for( int i=0; i<13; ++i)
				// 如果手里的牌中有dom-clr的花色。。 
				{
					if( hand[i]!=0 && card[hand[i]].Clr() == dom_clr ) 
					have = 1;
				}
				
				//wcout<<dom_clr<<" "<<have<<" "<<card[hand[re]].Clr()<<endl;

				if (dom_clr!=0 && have && card[hand[re]].Clr() != dom_clr ) 
				// 我有这个花色并且出处来的不是这个花色。。
				{
					wcout<<"Wrong input!"<<endl;
				}
				else
				{
					on_table[0] = card[hand[re]].Id();
					hand[re] = 0;
					break;
				}
			}
		}
		
//		wcout<<hand[0]<<endl;
	}
	
	void play(int on_table[], CARD* card)
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

		int out; //要出去的牌在自己手里的编号。。
		if ( count == 0 && inhand == 13 ) //桌上没牌并且是第一轮。。先出草花2。。 
		{
			for( int i=0; i<13; ++i)
			{
				if (card[hand[i]].Id() == 28)	out = i;
			}
		}
		else// 不是第一轮。。 
		{
			if( count == 0 ) //桌上没牌。。
			{
				bool have = 0;
				for( int i=0; i<13; ++i) //先拱猪。。
				{
					if ( hand[i]!=0 && card[ hand[i] ].Clr() == 1 && card[ hand[i] ].Wgt() <= 11)
					{
						out = i;
						have = 1; //有合适的黑桃比国内且出了。。
					}
				}
				if ( have == 0 ) // 没有合适的黑桃。。选一张小牌出。。
				{
					int weight = 15;
					for( int j=0; j<13; ++j)
					{
						if( hand[j]!=0 && card[ hand[j] ].Wgt() < weight )
						out = j, weight = card[ hand[j] ].Wgt();
					}
				}
			}
			else //桌上有牌。。需要先判断花色。。
			{
				int dom_clr;
				for( int i=1; i<=3; ++i)
				{
					int t = (Id() + i)%4;
					if ( on_table[t] != 0 )
					{
						dom_clr = card[ on_table[t] ].Clr();
						break;
					}
				}
				
				bool have = 0;
				for( int i=0; i<13; ++i) //自己有桌上的花色。。出牌。。
				{
					if( hand[i] != 0 && card[hand[i]].Clr() == dom_clr )
					{	
						out = i;
						have = 1;
					}
				}
				
				if (have == 0) // 自己没有桌上的花色。。瞎选。。
				{
					int weight = 15;
					for( int j=0; j<13; ++j)
					{
						if( hand[j]!=0 && card[ hand[j] ].Wgt() < weight )
						out = j, weight = card[ hand[j] ].Wgt();
					}
				}
			}
		}
		
		on_table[ Id() ] = hand[out];// give a card from hand onto the table..
		hand[out] = 0; // this position is empty now.. set to 0..
	}

	void getall(int on_table[], CARD *card)
	{
		int count = 0;
		for(int i=0; i<4; ++i)
		{
			if ( on_table[i] == 36 )
			Getrans();
			else 
			count = count + card[ on_table[i]].Crt();
		}
		score = score + count;
		wcout<<"Player "<<Id()<<" is the largest!\n";
		wcout<<"Player "<<Id()<<" got "<<count<<"!\n";
	}
	
	void Getrans()
	{
		trans = 1; // 1 is get the trans..
	}

	const int Trans()
	{
		if (trans == 0)	return 1;
		else 			return 2;
	}

	const int Id() { return id; }

	const int Score()
	{
		//本局分数。。
		return score;
	}
	
	void SetScore() { score = 0; }
	const int ScoreSum()
	{
		//输出已经加上的新分数。。
		score_sum = score_sum + score * Trans();
		return score_sum;
	}
};

int compare(const void *a, const void *b) // used to quick sorting..
{
	int *pa = (int*)a;
	int *pb = (int*)b;
	return (*pa) - (*pb);
}
