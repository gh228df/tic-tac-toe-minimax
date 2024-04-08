#include <iostream>
#include <vector>

using namespace std;

bool checkwin(int pos){
    if((pos & 15) == 15)
        return true;
    if((pos & 30) == 30)
        return true;
    if((pos & 480) == 480)
        return true;
    if((pos & 960) == 960)
        return true;
    if((pos & 15360) == 15360)
        return true;
    if((pos & 30720) == 30720)
        return true;
    if((pos & 491520) == 491520)
        return true;
    if((pos & 983040) == 983040)
        return true;
    if((pos & 15728640) == 15728640)
        return true;
    if((pos & 31457280) == 31457280)
        return true;
    if((pos & 33825) == 33825)
        return true;
    if((pos & 67650) == 67650)
        return true;
    if((pos & 135300) == 135300)
        return true;
    if((pos & 270600) == 270600)
        return true;
    if((pos & 541200) == 541200)
        return true;
    if((pos & 1082400) == 1082400)
        return true;
    if((pos & 2164800) == 2164800)
        return true;
    if((pos & 4329600) == 4329600)
        return true;
    if((pos & 8659200) == 8659200)
        return true;
    if((pos & 17318400) == 17318400)
        return true;
    if((pos & 266305) == 266305)
        return true;
    if((pos & 17043520) == 17043520)
        return true;
    if((pos & 4369) == 4369)
        return true;
    if((pos & 1118464) == 1118464)
        return true;
    if((pos & 34952) == 34952)
        return true;
    if((pos & 532610) == 532610)
        return true;
    if((pos & 2236928) == 2236928)
        return true;
    if((pos & 8521760) == 8521760)
        return true;
    return false;
}

int minimax(int depth, int alpha, int beta, int position1, int position2, bool player){
    if(depth == 0)
        return 0;
    int res;
    if(player){
        res = -100;
        for(int i = 0; i < 25; i++)
            if((position1 & (1 << i)) == 0 and (position2 & (1 << i)) == 0){
                if(checkwin(position1 + (1 << i)) == 1)
                    return depth;
            }
        for(int i = 0; i < 25; i++)
            if((position1 & (1 << i)) == 0 and (position2 & (1 << i)) == 0){
                if((position1 & (1 << i)) == 0 and (position2 & (1 << i)) == 0){
                    int reschild = minimax(depth - 1, alpha, beta, position1 + (i << 1), position2, false);
                    if(reschild > res)
                        res = reschild;
                    if(reschild > alpha)
                        alpha = reschild;
                    if(beta <= alpha)
                        return res;
                }
            }
        return res;
    }
    else
    {
        res = 100;
        for(int i = 0; i < 25; i++)
            if((position1 & (1 << i)) == 0 and (position2 & (1 << i)) == 0){
                if(checkwin(position2 + (1 << i)) == 1)
                    return -depth;
            }
        for(int i = 0; i < 25; i++)
            if((position1 & (1 << i)) == 0 and (position2 & (1 << i)) == 0){
                if((position1 & (1 << i)) == 0 and (position2 & (1 << i)) == 0){
                    int reschild = minimax(depth - 1, alpha, beta, position1, position2 + (1 << i), true);
                    if(reschild < res)
                        res = reschild;
                    if(reschild < beta)
                        beta = reschild;
                    if(beta <= alpha)
                        return res;
                }
            }
        return res;
    }
}

void printpos(int pos1, int pos2){
    for(int i = 25; i > -1; i--){
        if((pos1 & (1 << i)) == (1 << i))
            cout << "X";
        else if((pos2 & (1 << i)) == (1 << i))
            cout << "O";
        else 
            cout << ".";
        if(i % 5 == 0)
            cout << endl;
    }
}

vector<int> minimaxmain(int depth, int alpha, int beta, int position1, int position2, bool player){
    vector<int> eval = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    if(player){
        for(int i = 0; i < 25; i++)
            if((position1 & (1 << i)) == 0 and (position2 & (1 << i)) == 0){
                if(checkwin(position1 + (1 << i)) == 1){
                    eval[i] = depth;
                    return eval;
                }
            }
        for(int i = 0; i < 25; i++)
            if((position1 & (1 << i)) == 0 and (position2 & (1 << i)) == 0)
                eval[i] = minimax(depth - 1, -100, 100, position1 + (1 << i), position2, false);
        return eval;
    }
    else
    {
        for(int i = 0; i < 25; i++)
            if((position1 & (1 << i)) == 0 and (position2 & (1 << i)) == 0){
                if(checkwin(position2 + (1 << i)) == 1){
                    eval[i] = -depth;
                    return eval;
                }
            }
        for(int i = 0; i < 25; i++)
            if((position1 & (1 << i)) == 0 and (position2 & (1 << i)) == 0)
                eval[i] = minimax(depth - 1, -100, 100, position1, position2 + (1 << i), true);
        return eval;
    }
}

int main()
{
    for(;;){
        int pos1 = 0, pos2 = 0;
        bool pl = 0;
        if(pl == 0){
            cout << "Bot starts first" << endl;
            for(int itmain = 0;; itmain++){
                vector<int> eval = minimaxmain(25 - (itmain << 1), -100, 100, pos1, pos2, true);
                for(int i = 24; i > -1; i--){
                    cout << eval[i] << " ";
                    if(i % 4 == 0)
                         cout << endl;
                }
                cout << endl;
                int max = -100, move1;
                for(int i = 0; i < 25; i++)
                    if(eval[i] > max and (pos1 & (1 << i)) == 0 and (pos2 & (1 << i)) == 0){
                        max = eval[i];
                        move1 = i;
                    }
                pos1 += (1 << move1);
                if(checkwin(pos1) == 1){
                    printpos(pos1, pos2);
                    cout << "You lose..." << endl;
                    break;
                }
                if(itmain == 24){
                    printpos(pos1, pos2);
                    cout << "Draw" << endl;
                    break;
                }
                printpos(pos1, pos2);
                int move2;
                cin >> move2;
                for(; move2 < 0 or move2 > 25 or (pos1 & (1 << (move2 - 1))) > 0 or (pos2 & (1 << (move2 - 1))) > 0;)
                    cin >> move2;
                pos2 += (1 << (move2 - 1));
                if(checkwin(pos2) == 1){
                    printpos(pos1, pos2);
                    cout << "You lose..." << endl;
                    break;
                }
            }
        }
        else
        {
            cout << "You start first" << endl;
            for(int itmain = 0;; itmain++){
                printpos(pos1, pos2);
                int move2;
                cin >> move2;
                for(; move2 < 0 or move2 > 9 or (pos1 & (1 << (move2 - 1))) > 0 or (pos2 & (1 << (move2 - 1))) > 0;)
                    cin >> move2;
                pos1 += (1 << (move2 - 1));
                if(checkwin(pos1) == 1){
                    printpos(pos1, pos2);
                    cout << "You lose..." << endl;
                    break;
                }
                if(itmain == 4){
                    printpos(pos1, pos2);
                    cout << "Draw" << endl;
                    break;
                }
                vector<int> eval = minimaxmain(8 - (itmain << 1), -100, 100, pos1, pos2, false);
                for(int i = 8; i > -1; i--){
                    cout << eval[i] << " ";
                    if(i % 3 == 0)
                         cout << endl;
                }
                cout << endl;
                int min = 100, move1;
                for(int i = 0; i < 9; i++)
                    if(eval[i] < min and (pos1 & (1 << i)) == 0 and (pos2 & (1 << i)) == 0){
                        min = eval[i];
                        move1 = i;
                    }
                pos2 += (1 << move1);
                if(checkwin(pos2) == 1){
                    printpos(pos1, pos2);
                    cout << "You lose..." << endl;
                    break;
                }
            }
        }
    }
}
