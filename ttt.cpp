#include <iostream>

using namespace std;

bool checkwin(short pos, short last)
{
	pos = ~pos;
	switch (last)
	{
	case 0:
		if ((pos & 272) == 0)
			return true;
		if ((pos & 72) == 0)
			return true;
		if ((pos & 6) == 0)
			return true;
		return false;
	case 1:
		if ((pos & 5) == 0)
			return true;
		if ((pos & 144) == 0)
			return true;
		return false;
	case 2:
		if ((pos & 3) == 0)
			return true;
		if ((pos & 288) == 0)
			return true;
		if ((pos & 80) == 0)
			return true;
		return false;
	case 3:
		if ((pos & 48) == 0)
			return true;
		if ((pos & 65) == 0)
			return true;
		return false;
	case 4:
		if ((pos & 40) == 0)
			return true;
		if ((pos & 130) == 0)
			return true;
		if ((pos & 257) == 0)
			return true;
		if ((pos & 68) == 0)
			return true;
		return false;
	case 5:
		if ((pos & 260) == 0)
			return true;
		if ((pos & 24) == 0)
			return true;
		return false;
	case 6:
		if ((pos & 384) == 0)
			return true;
		if ((pos & 9) == 0)
			return true;
		if ((pos & 20) == 0)
			return true;
		return false;
	case 7:
		if ((pos & 320) == 0)
			return true;
		if ((pos & 18) == 0)
			return true;
		return false;
	case 8:
		if ((pos & 192) == 0)
			return true;
		if ((pos & 17) == 0)
			return true;
		if ((pos & 36) == 0)
			return true;
		return false;
	}
}

void display(short pos1, short pos2)
{
	for (short j = 8; j > -1;){
		for (short u = 0; u < 9; ++u){
			short tev = (((j + 3) / 3) * 3 - 1 - u / 3), tpr = (u + j % 3 + u / 3) & 1;
			if ((pos1 & (1 << tev)) > 0){
				if(tpr == 0)
					cout << "\033[1;31m#\033[0m";
				else
					cout << " ";
				goto fend;
			}
			else if((pos2 & (1 << tev)) > 0){
				if(tpr)
					cout << "\033[1;33m#\033[0m";
				else
					cout << " ";
				goto fend;
			}
			if (j % 3 == 1 && u % 3 == 1) 
				cout << tev + 1;
			else
				cout << " ";
			fend:
			if (u % 3 == 2 && u < 8) 
				cout << "|";
		}
		cout << endl;
		--j;
		if (j % 3 == 2)
			cout << "---+---+---" << endl;
	}
}

int entry = 0;

short minimax(short depth, short alpha, short beta, short position1, short position2, bool player){
	entry++;
	short tpos = (position1 | position2), npos; 
	if (player)
	{
		npos = ~position2;
		bool iswin = false;
		short winblock;
		if ((tpos & 1) == 0) 
			if ((npos & 272) == 0 or (npos & 72) == 0 or (npos & 6) == 0){
				iswin = true;
				winblock = 1;
			}
		if ((tpos & 2) == 0)
			if ((npos & 5) == 0 or (npos & 144) == 0){
				iswin = true;
				winblock = 2;
			}
		if ((tpos & 4) == 0)
			if ((npos & 3) == 0 or (npos & 288) == 0 or (npos & 80) == 0){
				iswin = true;
				winblock = 4;
			}
		if ((tpos & 8) == 0)
			if ((npos & 48) == 0 or (npos & 65) == 0){
				if(iswin)
					return -depth;
				iswin = true;
				winblock = 8;
			}
		if ((tpos & 32) == 0)
			if ((npos & 260) == 0 or (npos & 24) == 0){
				if(iswin)
					return -depth;
				iswin = true;
				winblock = 32;
			}
		if ((tpos & 64) == 0)
			if ((npos & 384) == 0 or (npos & 9) == 0 or (npos & 20) == 0){
				if(iswin)
					return -depth;
				iswin = true;
				winblock = 64;
			}
		if ((tpos & 128) == 0)
			if ((npos & 320) == 0 or (npos & 18) == 0){
				if(iswin)
					return -depth;
				iswin = true;
				winblock = 128;
			}
		if ((tpos & 256) == 0)
			if ((npos & 192) == 0 or (npos & 17) == 0 or (npos & 36) == 0){
				if(iswin)
					return -depth;
				iswin = true;
				winblock = 256;
			}
		depth--;
		if(depth == 0)
			return 0;
		if(iswin)
			return minimax(depth, alpha, beta, position1 | winblock, position2, false);
		short maxscore = depth - 3;
		if(alpha > maxscore)
			return alpha;
		if ((tpos & 16) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1 | 16, position2, false);
			if(reschild > maxscore)
				return reschild;
			if(reschild > alpha){
				if(beta <= reschild)
					return reschild;
				alpha = reschild;
			}
		}
		if ((tpos & 256) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1 | 256, position2, false);
			if(reschild > maxscore)
				return reschild;
			if(reschild > alpha){
				if(beta <= reschild)
					return reschild;
				alpha = reschild;
			}
		}
		if ((tpos & 64) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1 | 64, position2, false);
			if(reschild > maxscore)
				return reschild;
			if(reschild > alpha){
				if(beta <= reschild)
					return reschild;
				alpha = reschild;
			}
		}
		if ((tpos & 4) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1 | 4, position2, false);
			if(reschild > maxscore)
				return reschild;
			if(reschild > alpha){
				if(beta <= reschild)
					return reschild;
				alpha = reschild;
			}
		}
		if ((tpos & 1) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1 | 1, position2, false);
			if(reschild > maxscore)
				return reschild;
		}
		return alpha;
	}
	else
	{
		npos = ~position1;
		bool iswin = false;
		short winblock;
		if ((tpos & 1) == 0) 
			if ((npos & 272) == 0 or (npos & 72) == 0 or (npos & 6) == 0){
				iswin = true;
				winblock = 1;
			}
		if ((tpos & 2) == 0)
			if ((npos & 5) == 0 or (npos & 144) == 0){
				iswin = true;
				winblock = 2;
			}
		if ((tpos & 4) == 0)
			if ((npos & 3) == 0 or (npos & 288) == 0 or (npos & 80) == 0){
				if(iswin)
					return depth;
				iswin = true;
				winblock = 4;
			}
		if ((tpos & 8) == 0)
			if ((npos & 48) == 0 or (npos & 65) == 0){
				if(iswin)
					return depth;
				iswin = true;
				winblock = 8;
			}
		if ((tpos & 32) == 0)
			if ((npos & 260) == 0 or (npos & 24) == 0){
				if(iswin)
					return depth;
				iswin = true;
				winblock = 32;
			}
		if ((tpos & 64) == 0)
			if ((npos & 384) == 0 or (npos & 9) == 0 or (npos & 20) == 0){
				if(iswin)
					return depth;
				iswin = true;
				winblock = 64;
			}
		if ((tpos & 128) == 0)
			if ((npos & 320) == 0 or (npos & 18) == 0){
				if(iswin)
					return depth;
				iswin = true;
				winblock = 128;
			}
		if ((tpos & 256) == 0)
			if ((npos & 192) == 0 or (npos & 17) == 0 or (npos & 36) == 0){
				if(iswin)
					return depth;
				iswin = true;
				winblock = 256;
			}
		depth--;
		if(iswin)
			return minimax(depth, alpha, beta, position1, position2 | winblock, true);
		short minscore = 3 - depth;
		if(beta < minscore)
			return beta;
		if ((tpos & 16) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1, position2 | 16, true);
			if(reschild < beta){
				if(reschild <= alpha)
					return reschild;
				beta = reschild;
			}
		}
		if ((tpos & 256) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1, position2 | 256, true);
			if(reschild < minscore)
				return reschild;
			if(reschild < beta){
				if(reschild <= alpha)
					return reschild;
				beta = reschild;
			}
		}
		if ((tpos & 64) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1, position2 | 64, true);
			if(reschild < minscore)
				return reschild;
			if(reschild < beta){
				if(reschild <= alpha)
					return reschild;
				beta = reschild;
			}
		}
		if ((tpos & 4) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1, position2 | 4, true);
			if(reschild < minscore)
				return reschild;
			if(reschild < beta){
				if(reschild <= alpha)
					return reschild;
				beta = reschild;
			}
		}
		if ((tpos & 1) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1, position2 | 1, true);
			if(reschild < minscore)
				return reschild;
		}
		if ((tpos & 128) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1, position2 | 128, true);
			if(reschild < minscore)
				return reschild;
			if(reschild < beta){
				if(reschild <= alpha)
					return reschild;
				beta = reschild;
			}
		}
		if ((tpos & 32) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1, position2 | 32, true);
			if(reschild < minscore)
				return reschild;
		}
		return beta;
	}
}

short minimaxmain(short depth, short alpha, short beta, short position1, short position2, bool player)
{
	short tpos = (position1 | position2), npos; 
	if (player)
	{
		npos = ~position1;
		if ((tpos & 1) == 0) 
			if ((npos & 272) == 0 or (npos & 72) == 0 or (npos & 6) == 0)
				return 0;
		if ((tpos & 4) == 0)
			if ((npos & 3) == 0 or (npos & 288) == 0 or (npos & 80) == 0)
				return 2;
		if ((tpos & 8) == 0)
			if ((npos & 48) == 0 or (npos & 65) == 0)
				return 3;
		if ((tpos & 32) == 0)
			if ((npos & 260) == 0 or (npos & 24) == 0)
				return 5;
		if ((tpos & 64) == 0)
			if ((npos & 384) == 0 or (npos & 9) == 0 or (npos & 20) == 0)
				return 6;
		if ((tpos & 128) == 0)
			if ((npos & 320) == 0 or (npos & 18) == 0)
				return 7;
		npos = ~position2;
		if ((tpos & 2) == 0)
			if ((npos & 5) == 0 or (npos & 144) == 0)
				return 1;
		if ((tpos & 4) == 0)
			if ((npos & 3) == 0 or (npos & 288) == 0 or (npos & 80) == 0)
				return 2;
		if ((tpos & 8) == 0)
			if ((npos & 48) == 0 or (npos & 65) == 0)
				return 3;
		if ((tpos & 32) == 0)
			if ((npos & 260) == 0 or (npos & 24) == 0)
				return 5;
		if ((tpos & 64) == 0)
			if ((npos & 384) == 0 or (npos & 9) == 0 or (npos & 20) == 0)
				return 6;
		short ret, maxscore = depth - 3;
		depth--;
		if ((tpos & 16) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1 | 16, position2, false);
			if(reschild > alpha){
				alpha = reschild;
				ret = 4;
			}	
		}
		if ((tpos & 256) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1 | 256, position2, false);
			if(reschild > alpha){
				alpha = reschild;
				ret = 8;
			}
		}
		if ((tpos & 64) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1 | 64, position2, false);
			if(reschild > maxscore)
				return 6;
			if(reschild > alpha){
				alpha = reschild;
				ret = 6;
			}
		}
		if ((tpos & 4) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1 | 4, position2, false);
			if(reschild > maxscore)
				return 2;
			if(reschild > alpha){
				alpha = reschild;
				ret = 2;
			}
		}
		if ((tpos & 1) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1 | 1, position2, false);
			if(reschild > alpha){
				alpha = reschild;
				ret = 0;
			}
		}
		if ((tpos & 128) == 0)
			if(minimax(depth, alpha, beta, position1 | 128, position2, false) > maxscore)
				return 7;
		if ((tpos & 32) == 0)
			if(minimax(depth, alpha, beta, position1 | 32, position2, false) > maxscore)
				return 5;
		if ((tpos & 8) == 0)
			if(minimax(depth, alpha, beta, position1 | 8, position2, false) > maxscore)
				return 3;
		if ((tpos & 2) == 0)
			if(minimax(depth, alpha, beta, position1 | 2, position2, false) > maxscore)
				return 1;
		return ret;
	}
	else
	{ 
		npos = ~position2;
		if ((tpos & 1) == 0) 
			if ((npos & 272) == 0 or (npos & 72) == 0 or (npos & 6) == 0)
				return 0;
		if ((tpos & 2) == 0)
			if ((npos & 5) == 0 or (npos & 144) == 0)
				return 1;
		if ((tpos & 4) == 0)
			if ((npos & 3) == 0 or (npos & 288) == 0 or (npos & 80) == 0)
				return 2;
		if ((tpos & 8) == 0)
			if ((npos & 48) == 0 or (npos & 65) == 0)
				return 3;
		if ((tpos & 32) == 0)
			if ((npos & 260) == 0 or (npos & 24) == 0)
				return 5;
		if ((tpos & 64) == 0)
			if ((npos & 384) == 0 or (npos & 9) == 0 or (npos & 20) == 0)
				return 6;
		if ((tpos & 128) == 0)
			if ((npos & 320) == 0 or (npos & 18) == 0)
				return 7;
		if ((tpos & 256) == 0)
			if ((npos & 192) == 0 or (npos & 17) == 0 or (npos & 36) == 0)
				return 8;
		npos = ~position1;
		if ((tpos & 1) == 0) 
			if ((npos & 272) == 0 or (npos & 72) == 0 or (npos & 6) == 0)
				return 0;
		if ((tpos & 2) == 0)
			if ((npos & 5) == 0 or (npos & 144) == 0)
				return 1;
		if ((tpos & 4) == 0)
			if ((npos & 3) == 0 or (npos & 288) == 0 or (npos & 80) == 0)
				return 2;
		if ((tpos & 8) == 0)
			if ((npos & 48) == 0 or (npos & 65) == 0)
				return 3;
		if ((tpos & 32) == 0)
			if ((npos & 260) == 0 or (npos & 24) == 0)
				return 5;
		if ((tpos & 64) == 0)
			if ((npos & 384) == 0 or (npos & 9) == 0 or (npos & 20) == 0)
				return 6;
		if ((tpos & 128) == 0)
			if ((npos & 320) == 0 or (npos & 18) == 0)
				return 7;
		if ((tpos & 256) == 0)
			if ((npos & 192) == 0 or (npos & 17) == 0 or (npos & 36) == 0)
				return 8;
		short ret = -1, minscore = 3 - depth;
		depth--;
		if ((tpos & 16) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1, position2 | 16, true);
			if(reschild < beta){
				beta = reschild;
				ret = 4;
			}
		}
		if ((tpos & 256) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1, position2 | 256, true);
			if(reschild < minscore)
				return 8;
			if(reschild < beta){
				beta = reschild;
				ret = 8;
			}
		}
		if ((tpos & 64) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1, position2 | 64, true);
			if(reschild < minscore)
				return 6;
			if(reschild < beta){
				beta = reschild;
				ret = 6;
			}
		}
		if ((tpos & 4) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1, position2 | 4, true);
			if(reschild < minscore)
				return 2;
			if(reschild < beta){
				beta = reschild;
				ret = 2;
			}
		}
		if ((tpos & 1) == 0)
			if(minimax(depth, alpha, beta, position1, position2 | 1, true) < minscore)
				return 0;
		if ((tpos & 128) == 0)
		{
			short reschild = minimax(depth, alpha, beta, position1, position2 | 128, true);
			if(reschild < minscore)
				return 7;
			if(reschild < beta){
				beta = reschild;
				ret = 7;
			}
		}
		if ((tpos & 32) == 0)
			if(minimax(depth, alpha, beta, position1, position2 | 32, true) < minscore)
				return 5;
		return ret;
	}
}

int main()
{
	// system("CLS");
	for (;;)
	{
		short pos1 = 0, pos2 = 0;
		if (rand() % 2)
		{
			cout << "Bot starts first" << endl;
			for (short itmain = 0;; itmain++)
			{
				entry = 0;
				short move1 = minimaxmain(9 - (itmain << 1), -100, 100, pos1, pos2, true);
				//244
				cout << entry << endl;
				pos1 += (1 << move1);
				if (checkwin(pos1, move1))
				{
					display(pos1, pos2);
					cout << "You lose..." << endl;
					break;
				}
				if (itmain == 4)
				{
					display(pos1, pos2);
					cout << "Draw" << endl;
					break;
				}
				display(pos1, pos2);
				short move2;
				cin >> move2;
				for (; move2 < 0 or move2 > 9 or ((pos1 | pos2) & (1 << (move2 - 1))) > 0;)
					cin >> move2;
				pos2 += (1 << (move2 - 1));
			}
		}
		else
		{
			cout << "You start first" << endl;
			for (short itmain = 0;; itmain++)
			{
				display(pos1, pos2);
				short move2;
				cin >> move2;
				for (; move2 < 0 or move2 > 9 or ((pos1 | pos2) & (1 << (move2 - 1))) > 0;)
					cin >> move2;
				pos1 += (1 << (move2 - 1));
				if (itmain == 4)
				{
					display(pos1, pos2);
					cout << "Draw" << endl;
					break;
				}
				entry = 0;
				short move1 = minimaxmain(8 - (itmain << 1), -100, 100, pos1, pos2, false);
				cout << entry << endl;
				pos2 += (1 << move1);
				if (checkwin(pos2, move1) == 1)
				{
					display(pos1, pos2);
					cout << "You lose..." << endl;
					break;
				}
			}
		}
	}
}
