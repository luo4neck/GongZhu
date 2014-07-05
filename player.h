using namespace std;

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
