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
	for (uint8_t j = 8;;){
		for (uint8_t u = 0; u < 9; ++u){
			uint8_t tev = (((j + 3) / 3) * 3 - 1 - u / 3), tpr = (u + j % 3 + u / 3) & 1;
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
		if(j == 0)
			return;
		--j;
		if (j % 3 == 2)
			cout << "---+---+---" << endl;
	}
}

short minimaxmain(short position1, short position2, bool player)
{
	short tpos = (position1 | position2), npos; 
	if ((tpos & 16) == 0)
		return 4;
	if (player)
	{
		npos = ~position1;
		if ((tpos & 1) == 0 and npos == -273) {
			return 0;
		}
		if ((tpos & 4) == 0 and (npos == -81 or npos == -337)){
			return 2;
		}
		if ((tpos & 32) == 0 and (npos == -277 or npos == -281)){
			return 5;
		}
		if ((tpos & 128) == 0 and (npos == -337 or npos == -275)){
			return 7;
		}
		if ((tpos & 8) == 0 and (npos == -113 or npos == -307)){
			return 3;
		}
		npos = ~position2;
		if ((tpos & 2) == 0)
			if ((npos & 5) == 0 or (npos & 144) == 0){
				return 1;
			}
		if ((tpos & 4) == 0)
			if ((npos & 3) == 0 or (npos & 288) == 0 or (npos & 80) == 0){
				return 2;
			}
		if ((tpos & 8) == 0)
			if ((npos & 48) == 0 or (npos & 65) == 0){
				return 3;
			}
		if ((tpos & 32) == 0)
			if ((npos & 260) == 0 or (npos & 24) == 0){
				return 5;
			}
		if ((tpos & 256) == 0){
			return 8;
		}
		if ((tpos & 4) == 0 and tpos == 401){
			return 2;
		}
		if ((tpos & 64) == 0 and tpos != 407){
			return 6;
		}
		if ((tpos & 128) == 0){
			return 7;
		}
		if ((tpos & 32) == 0){
			return 5;
		}
		return 0;
	}
	else
	{ 
		npos = ~position2;
		if ((tpos & 1) == 0 and (npos == -273 or npos == -337)) 
			return 0;
		if ((tpos & 64) == 0)
			if ((npos & 384) == 0 or (npos & 9) == 0 or (npos & 20) == 0){
				return 6;
			}
		if ((tpos & 4) == 0)
			if ((npos & 3) == 0 or (npos & 288) == 0 or (npos & 80) == 0){
				return 2;
			}
		if ((tpos & 2) == 0)
			if ((npos & 5) == 0 or (npos & 144) == 0){
				return 1;
			}
		if ((tpos & 32) == 0)
			if ((npos & 260) == 0 or (npos & 24) == 0){
				return 5;
			}
		if ((tpos & 128) == 0)
			if ((npos & 320) == 0 or (npos & 18) == 0){
				return 7;
			}
		if ((tpos & 8) == 0)
			if ((npos & 48) == 0 or (npos & 65) == 0){
				return 3;
			}
		npos = ~position1;
		if ((tpos & 4) == 0)
			if ((npos & 3) == 0 or (npos & 288) == 0 or (npos & 80) == 0){
				return 2;
			}
		if ((tpos & 64) == 0)
			if ((npos & 384) == 0 or (npos & 9) == 0 or (npos & 20) == 0){
				return 6;
			}
		if ((tpos & 8) == 0)
			if ((npos & 48) == 0 or (npos & 65) == 0){
				return 3;
			}
		if ((tpos & 2) == 0)
			if ((npos & 5) == 0 or (npos & 144) == 0){
				return 1;
			}
		if ((tpos & 1) == 0) 
			if ((npos & 272) == 0 or (npos & 72) == 0 or (npos & 6) == 0){
				return 0;
			}
		if ((tpos & 128) == 0)
			if ((npos & 320) == 0 or (npos & 18) == 0){
				return 7;
			}
		if ((tpos & 32) == 0)
			if ((npos & 260) == 0 or (npos & 24) == 0){
				return 5;
			}
		if (npos == -258 or npos == -269 or npos == -69 or npos == -98){
			return 7;
		}
		if (npos == -13 or npos == -265){
			return 6;
		}
		if (npos == -67){
			return 2;
		}
		if(npos == -11){
			return 0;
		}
		if (npos == -134 or npos == -323){
			return 5;
		}
		if ((tpos & 256) == 0){
			return 8;
		}
		if ((tpos & 4) == 0){
			return 2;
		}
		if ((tpos & 64) == 0){
			return 6;
		}
		if ((tpos & 128) == 0){
			return 7;
		}
		if ((tpos & 32) == 0){
			return 5;
		}
		return 0;
	}
}

int main()
{
	for (;;)
	{
		short pos1 = 0, pos2 = 0;
		if (true)
		{
			cout << "Bot starts first" << endl;
			for (uint8_t itmain = 0;; itmain++)
			{
				short move = minimaxmain(pos1, pos2, true);
				pos1 |= (1 << move);
				if (checkwin(pos1, move))
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
				cin >> move;
				for (;;){
					move--;
					if(move < 9 and ((pos1 | pos2) & (1 << move)) == 0)
						break;
					cin >> move;
				}
				pos2 += (1 << move);
			}
		}
		else
		{
			cout << "You start first" << endl;
			for (short itmain = 0;; itmain++)
			{
				display(pos1, pos2);
				short move;
				cin >> move;
				for (;;){
					move--;
					if(move < 9 and ((pos1 | pos2) & (1 << move)) == 0)
						break;
					cin >> move;
				}
				pos1 += (1 << move);
				if (itmain == 4)
				{
					display(pos1, pos2);
					cout << "Draw" << endl;
					break;
				}
				move = minimaxmain(pos1, pos2, false);
				pos2 += (1 << move);
				if (checkwin(pos2, move))
				{
					display(pos1, pos2);
					cout << "You lose..." << endl;
					break;
				}
			}
		}
	}
}
