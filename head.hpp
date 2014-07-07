void print_table(int on_table[], CARD* card)
{	
	wcout<<"   ";
	for(int i=0; i<25; ++i) wcout<<"_";
	wcout<<endl;
	
	for(int i=0; i<10; ++i)
	{
		if(i == 0) 
		wcout<<"  |        Player 2         |"<<endl;
		else if(i == 4) 
		wcout<<"  | Player 1       Player 3 |"<<endl;
		else if(i == 8) 
		wcout<<"  |            ME           |"<<endl;
		else if(on_table[1] > 0 && ( i == 5 || i == 1) ) //玩家1先出牌。。
		{
			if( i == 5 ) //第五行。。
			{	
				int card_id1 = on_table[1];
				int card_id3 = on_table[3];
				wcout<<"  |   ";
				card[card_id1].Prt();
				wcout<<"           ";
				card[card_id3].Prt();
				wcout<<"   |"<<endl;
			}
			else // 第一行。。
			{
				int card_id = on_table[2];
				wcout<<"  |          ";
				card[card_id].Prt();
				wcout<<"           |"<<endl;
			}
		}
		else if(on_table[2] > 0 && (i == 5 || i ==1) ) //玩家2先出牌。。
		{
			if ( i == 5)
			{
				int card_id3 = on_table[3];
				wcout<<"  |                  ";
				card[card_id3].Prt();
				wcout<<"   |"<<endl;
			}
			else
			{
				int card_id = on_table[2];
				wcout<<"  |          ";
				card[card_id].Prt();
				wcout<<"           |"<<endl;
			}	
		}
		else if(on_table[3] > 0 && i ==5 ) //玩家3先出牌。。
		{
				int card_id3 = on_table[3];
				wcout<<"  |                  ";
				card[card_id3].Prt();
				wcout<<"   |"<<endl;
		}
		else if(on_table[0] > 0 && i ==9 ) //玩家3先出牌。。
		{
				int card_id3 = on_table[0];
				wcout<<"  |           ";
				card[card_id3].Prt();
				wcout<<"          |"<<endl;
		}
		else 
		wcout<<"  |                         |"<<endl;
	}
		
	wcout<<"  |";
	for(int i=0; i<25; ++i) wcout<<"_";
	wcout<<"|"<<endl;
}

int four_max(int first, int on_table[], CARD* card)
{
	int p[4] = {0, 0, 0, 0};
	p[first] = card[ on_table[first] ].Wgt();

	for( int k=0; k<4; ++k )
	{
		if( k!=first)
		{
			if( card[ on_table[first] ].Clr() == card[ on_table[k] ].Clr() )// check if belongs to same colour.. 
			p[k] = card[ on_table[k] ].Wgt();
			else 					
			p[k] = 0;
		}
	}

	wcout<<p[0]<<" ";
	wcout<<p[1]<<" ";
	wcout<<p[2]<<" ";
	wcout<<p[3]<<" ";
	wcout<<endl;

	int re;// return the player id..
	if 		(p[0] > p[1] && p[0] > p[2] && p[0] > p[3]) re = 0;
	else if (p[1] > p[0] && p[1] > p[2] && p[1] > p[3]) re = 1;
	else if (p[2] > p[0] && p[2] > p[1] && p[2] > p[3]) re = 2;
	else 												re = 3;
	//else if (p[3] > p[0] && p[3] > p[1] && p[3] > p[2]) re = 3;
	
	return re;
}

int Allmark(int on_table[], CARD* card)
{
	return 0;
}

int Play(int first, PLAYER &P0, PLAYER &P1, PLAYER &P2, PLAYER &P3, CARD *card)
{
	wcout<<first<<endl;
	int on_table[4]={0,0,0,0};

	if(first == 0)
	{	
		wcout<<"i am "<<first<<endl;
		print_table(on_table, card);
		P0.playme(on_table, card);
		P1.play  (on_table, card);
		P2.play  (on_table, card);
		P3.play  (on_table, card);
		wcout<<"Result of this round:"<<endl;
		wcout<<on_table[0]<<" "<<on_table[1]<<" "<<on_table[2]<<" "<<on_table[3]<<endl;
		print_table(on_table, card);
	}
	
	if(first == 1)
	{	
		P1.play  (on_table, card);
		P2.play  (on_table, card);
		P3.play  (on_table, card);
		
		wcout<<"i am "<<first<<endl;
		wcout<<on_table[0]<<" "<<on_table[1]<<" "<<on_table[2]<<" "<<on_table[3]<<endl;
		print_table(on_table, card);
		P0.playme(on_table, card);
		
		wcout<<"Result of this round:"<<endl;
		print_table(on_table, card);
	}
	
	if(first == 2)
	{	
		P2.play  (on_table, card);
		P3.play  (on_table, card);
		
		wcout<<"i am "<<first<<endl;
		wcout<<on_table[0]<<" "<<on_table[1]<<" "<<on_table[2]<<" "<<on_table[3]<<endl;
		print_table(on_table, card);
		P0.playme(on_table, card);
		P1.play  (on_table, card);
		
		wcout<<"Result of this round:"<<endl;
		print_table(on_table, card);
	}
	
	if(first == 3)
	{	
		P3.play  (on_table, card);
		
		wcout<<"i am "<<first<<endl;
		wcout<<on_table[0]<<" "<<on_table[1]<<" "<<on_table[2]<<" "<<on_table[3]<<endl;
		print_table(on_table, card);
		P0.playme(on_table, card);
		P1.play  (on_table, card);
		P2.play  (on_table, card);
		
		wcout<<"Result of this round:"<<endl;
		print_table(on_table, card);
	}
	
	int next = four_max(first, on_table, card);
	if ( next == 0)      P0.getall( on_table); // 拿到桌上所有牌。。并且给自己加分。。
	else if( next == 1 ) P1.getall( on_table);
	else if( next == 2 ) P2.getall( on_table);
	else 				 P3.getall( on_table);
	
	wcout<< next <<endl;	
	return next;
}

void Sellall(bool pig, bool sheep, bool heart, bool trans, PLAYER P0, CARD *card)
{
	srand48(time(NULL));
	bool havepig = 0; // 0 is do not have pig..
	for(int i=0; i<13; ++i)
	{
		if ( P0.hand[i] == 12 )
		{
			wcout<<"Pig in your hand, do you want to sell Pig? (y/n)"<<endl;
			while(1)
			{
				wchar_t check;
				wcin>>check;
				if( check != 'y' && check != 'n' )
				{
					wcout<<"Please input 'y' or 'n'!"<<endl;
				}
				else
				{
					card[12].Double();
					pig = 1;
					havepig = 1;
					break;
				}
			}
		}
	}
	if( havepig ==0 && drand48()> 0.6 ) pig = 1; 

	bool haveheart = 0; // 0 is do not have heart..
	for(int i=0; i<13; ++i)
	{
		if ( P0.hand[i] == 14 )
		{
			wcout<<"Pig in your hand, do you want to sell Heart? (y/n)"<<endl;
			while(1)
			{
				wchar_t check;
				wcin>>check;
				if( check != 'y' && check != 'n' )
				{
					wcout<<"Please input 'y' or 'n'!"<<endl;
				}
				else
				{
					card[14].Double();
					heart = 1;
					haveheart = 1;
					break;
				}
			}
		}
	}
	if( haveheart ==0 && drand48()> 0.6 ) heart = 1; 
	
	bool havesheep = 0; // 0 is do not have sheep..
	for(int i=0; i<13; ++i)
	{
		if ( P0.hand[i] == 50 )
		{
			wcout<<"Pig in your hand, do you want to sell Sheep? (y/n)"<<endl;
			while(1)
			{
				wchar_t check;
				wcin>>check;
				if( check != 'y' && check != 'n' )
				{
					wcout<<"Please input 'y' or 'n'!"<<endl;
				}
				else
				{
					card[50].Double();
					sheep = 1;
					havesheep = 1;
					break;
				}
			}
		}
	}
	if( havesheep ==0 && drand48()> 0.6 ) sheep = 1; 

	bool havetrans = 0; // 0 is do not have trans..
	for(int i=0; i<13; ++i)
	{
		if ( P0.hand[i] == 36 )
		{
			wcout<<"Pig in your hand, do you want to sell Transformer? (y/n)"<<endl;
			while(1)
			{
				wchar_t check;
				wcin>>check;
				if( check != 'y' && check != 'n' )
				{
					wcout<<"Please input 'y' or 'n'!"<<endl;
				}
				else
				{
					card[36].Double();
					trans = 1;
					havetrans = 1;
					break;
				}
			}
		}
	}
	if( havetrans ==0 && drand48()> 0.6 ) trans = 1; 
}
