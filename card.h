#include"iostream"

using namespace std;

const wchar_t spade[]  = L"\u2660";
const wchar_t heart[]  = L"\u2665";
const wchar_t club[]   = L"\u2663";
const wchar_t diamond[]= L"\u2666";

class CARD
{
	private:
	int id;
	int weight;
	int credit;
	
	public:
	CARD()
	{
		
	}
	
	void Init(const int ID)
	{
		id = ID;
		
		int wgt = ID;
		wgt = wgt%13;
		if (wgt == 1)	   weight = 14;
		else if (wgt == 0) weight = 13;
		else			   weight = wgt;
	}

	void Prt()
	{
		if (Id() <= 13) 	 wcout<<spade  <<L"";
		else if (Id() <= 26) wcout<<heart  <<L"";
		else if (Id() <= 39) wcout<<club   <<L"";
		else 				 wcout<<diamond<<L"";
		
		int I = Id()%13;
		
		if (I == 1)		  cout<<"A";
		else if (I == 11) cout<<"J";
		else if (I == 12) cout<<"Q";
		else if (I == 0 ) cout<<"K";
		else if (I < 10)  cout<<I;
		else			  cout<<I;
		
		cout<<" ";
	}

	const int Id()
	{
		return id;
	}
	
	const int Wgt()
	{
		return weight;
	}
};
