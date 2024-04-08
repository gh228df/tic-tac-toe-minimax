#include <iostream>
#include <vector>

using namespace std;

bool checkwin(short pos){
    if((pos & 7) == 7)
        return true;
    if((pos & 56) == 56)
        return true;
    if((pos & 448) == 448)
        return true;
    if((pos & 73) == 73)
        return true;
    if((pos & 146) == 146)
        return true;
    if((pos & 292) == 292)
        return true;
    if((pos & 273) == 273)
        return true;
    if((pos & 84) == 84)
        return true;
    return false;
}

int minimax(int depth, int alpha, int beta, short position1, short position2, bool player){
    if(depth == 0)
        return 0;
    int res;
    if(player){
        res = -100;
        if((position1 & 1) == 0 and (position2 & 1) == 0){
            if(checkwin(position1 + 1) == 1)
                return depth;
        }
        if((position1 & 2) == 0 and (position2 & 2) == 0){
            if(checkwin(position1 + 2) == 1)
                return depth;
        }
        if((position1 & 4) == 0 and (position2 & 4) == 0){
            if(checkwin(position1 + 4) == 1)
                return depth;
        }
        if((position1 & 8) == 0 and (position2 & 8) == 0){
            if(checkwin(position1 + 8) == 1)
                return depth;
        }
        if((position1 & 16) == 0 and (position2 & 16) == 0){
            if(checkwin(position1 + 16) == 1)
                return depth;
        }
        if((position1 & 32) == 0 and (position2 & 32) == 0){
            if(checkwin(position1 + 32) == 1)
                return depth;
        }
        if((position1 & 64) == 0 and (position2 & 64) == 0){
            if(checkwin(position1 + 64) == 1)
                return depth;
        }
        if((position1 & 128) == 0 and (position2 & 128) == 0){
            if(checkwin(position1 + 128) == 1)
                return depth;
        }
        if((position1 & 256) == 0 and (position2 & 256) == 0){
            if(checkwin(position1 + 256) == 1)
                return depth;
        }
        if((position1 & 1) == 0 and (position2 & 1) == 0){
            int reschild = minimax(depth - 1, alpha, beta, position1 + 1, position2, false);
            if(reschild > res)
                res = reschild;
            if(reschild > alpha)
                alpha = reschild;
            if(beta <= alpha)
                return res;
        }
        if((position1 & 2) == 0 and (position2 & 2) == 0){
            int reschild = minimax(depth - 1, alpha, beta, position1 + 2, position2, false);
            if(reschild > res)
                res = reschild;
            if(reschild > alpha)
                alpha = reschild;
            if(beta <= alpha)
                return res;
        }
        if((position1 & 4) == 0 and (position2 & 4) == 0){
            int reschild = minimax(depth - 1, alpha, beta, position1 + 4, position2, false);
            if(reschild > res)
                res = reschild;
            if(reschild > alpha)
                alpha = reschild;
            if(beta <= alpha)
                return res;
        }
        if((position1 & 8) == 0 and (position2 & 8) == 0){
            int reschild = minimax(depth - 1, alpha, beta, position1 + 8, position2, false);
            if(reschild > res)
                res = reschild;
            if(reschild > alpha)
                alpha = reschild;
            if(beta <= alpha)
                return res;
        }
        if((position1 & 16) == 0 and (position2 & 16) == 0){
            int reschild = minimax(depth - 1, alpha, beta, position1 + 16, position2, false);
            if(reschild > res)
                res = reschild;
            if(reschild > alpha)
                alpha = reschild;
            if(beta <= alpha)
                return res;
        }
        if((position1 & 32) == 0 and (position2 & 32) == 0){
            int reschild = minimax(depth - 1, alpha, beta, position1 + 32, position2, false);
            if(reschild > res)
                res = reschild;
            if(reschild > alpha)
                alpha = reschild;
            if(beta <= alpha)
                return res;
        }
        if((position1 & 64) == 0 and (position2 & 64) == 0){
            int reschild = minimax(depth - 1, alpha, beta, position1 + 64, position2, false);
            if(reschild > res)
                res = reschild;
            if(reschild > alpha)
                alpha = reschild;
            if(beta <= alpha)
                return res;
        }
        if((position1 & 128) == 0 and (position2 & 128) == 0){
            int reschild = minimax(depth - 1, alpha, beta, position1 + 128, position2, false);
            if(reschild > res)
                res = reschild;
            if(reschild > alpha)
                alpha = reschild;
            if(beta <= alpha)
                return res;
        }
        if((position1 & 256) == 0 and (position2 & 256) == 0){
            int reschild = minimax(depth - 1, alpha, beta, position1 + 256, position2, false);
            if(reschild > res)
                res = reschild;
            if(reschild > alpha)
                alpha = reschild;
            if(beta <= alpha)
                return res;
        }
        return res;
    }
    else
    {
        res = 100;
        if((position1 & 1) == 0 and (position2 & 1) == 0){
            if(checkwin(position2 + 1) == 1)
                return -depth;
        }
        if((position1 & 2) == 0 and (position2 & 2) == 0){
            if(checkwin(position2 + 2) == 1)
                return -depth;
        }
        if((position1 & 4) == 0 and (position2 & 4) == 0){
            if(checkwin(position2 + 4) == 1)
                return -depth;
        }
        if((position1 & 8) == 0 and (position2 & 8) == 0){
            if(checkwin(position2 + 8) == 1)
                return -depth;
        }
        if((position1 & 16) == 0 and (position2 & 16) == 0){
            if(checkwin(position2 + 16) == 1)
                return -depth;
        }
        if((position1 & 32) == 0 and (position2 & 32) == 0){
            if(checkwin(position2 + 32) == 1)
                return -depth;
        }
        if((position1 & 64) == 0 and (position2 & 64) == 0){
            if(checkwin(position2 + 64) == 1)
                return -depth;
        }
        if((position1 & 128) == 0 and (position2 & 128) == 0){
            if(checkwin(position2 + 128) == 1)
                return -depth;
        }
        if((position1 & 256) == 0 and (position2 & 256) == 0){
            if(checkwin(position2 + 256) == 1)
                return -depth;
        }
        if((position1 & 1) == 0 and (position2 & 1) == 0){
            int reschild = minimax(depth - 1, alpha, beta, position1, position2 + 1, true);
            if(reschild < res)
                res = reschild;
            if(reschild < beta)
                beta = reschild;
            if(beta <= alpha)
                return res;
        }
        if((position1 & 2) == 0 and (position2 & 2) == 0){
            int reschild = minimax(depth - 1, alpha, beta, position1, position2 + 2, true);
            if(reschild < res)
                res = reschild;
            if(reschild < beta)
                beta = reschild;
            if(beta <= alpha)
                return res;
        }
        if((position1 & 4) == 0 and (position2 & 4) == 0){
            int reschild = minimax(depth - 1, alpha, beta, position1, position2 + 4, true);
            if(reschild < res)
                res = reschild;
            if(reschild < beta)
                beta = reschild;
            if(beta <= alpha)
                return res;
        }
        if((position1 & 8) == 0 and (position2 & 8) == 0){
            int reschild = minimax(depth - 1, alpha, beta, position1, position2 + 8, true);
            if(reschild < res)
                res = reschild;
            if(reschild < beta)
                beta = reschild;
            if(beta <= alpha)
                return res;
        }
        if((position1 & 16) == 0 and (position2 & 16) == 0){
            int reschild = minimax(depth - 1, alpha, beta, position1, position2 + 16, true);
            if(reschild < res)
                res = reschild;
            if(reschild < beta)
                beta = reschild;
            if(beta <= alpha)
                return res;
        }
        if((position1 & 32) == 0 and (position2 & 32) == 0){
            int reschild = minimax(depth - 1, alpha, beta, position1, position2 + 32, true);
            if(reschild < res)
                res = reschild;
            if(reschild < beta)
                beta = reschild;
            if(beta <= alpha)
                return res;
        }
        if((position1 & 64) == 0 and (position2 & 64) == 0){
            int reschild = minimax(depth - 1, alpha, beta, position1, position2 + 64, true);
            if(reschild < res)
                res = reschild;
            if(reschild < beta)
                beta = reschild;
            if(beta <= alpha)
                return res;
        }
        if((position1 & 128) == 0 and (position2 & 128) == 0){
            int reschild = minimax(depth - 1, alpha, beta, position1, position2 + 128, true);
            if(reschild < res)
                res = reschild;
            if(reschild < beta)
                beta = reschild;
            if(beta <= alpha)
                return res;
        }
        if((position1 & 256) == 0 and (position2 & 256) == 0){
            int reschild = minimax(depth - 1, alpha, beta, position1, position2 + 256, true);
            if(reschild < res)
                res = reschild;
            if(reschild < beta)
                beta = reschild;
            if(beta <= alpha)
                return res;
        }
        return res;
    }
}

void printpos(short pos1, short pos2){
    if((pos1 & 256) == 256)
        cout << "X";
    else if((pos2 & 256) == 256)
        cout << "O";
    else 
        cout << ".";
    if((pos1 & 128) == 128)
        cout << "X";
    else if((pos2 & 128) == 128)
        cout << "O";
    else 
        cout << ".";
    if((pos1 & 64) == 64)
        cout << "X";
    else if((pos2 & 64) == 64)
        cout << "O";
    else 
        cout << ".";
    cout << endl;
    if((pos1 & 32) == 32)
        cout << "X";
    else if((pos2 & 32) == 32)
        cout << "O";
    else 
        cout << ".";
    if((pos1 & 16) == 16)
        cout << "X";
    else if((pos2 & 16) == 16)
        cout << "O";
    else 
        cout << ".";
    if((pos1 & 8) == 8)
        cout << "X";
    else if((pos2 & 8) == 8)
        cout << "O";
    else 
        cout << ".";
    cout << endl;
    if((pos1 & 4) == 4)
        cout << "X";
    else if((pos2 & 4) == 4)
        cout << "O";
    else 
        cout << ".";
    if((pos1 & 2) == 2)
        cout << "X";
    else if((pos2 & 2) == 2)
        cout << "O";
    else 
        cout << ".";
    if((pos1 & 1) == 1)
        cout << "X";
    else if((pos2 & 1) == 1)
        cout << "O";
    else 
        cout << ".";
    cout << endl;
}

vector<int> minimaxmain(int depth, int alpha, int beta, short position1, short position2, bool player){
    vector<int> eval = {0,0,0,0,0,0,0,0,0};
    if(player){
        if((position1 & 1) == 0 and (position2 & 1) == 0){
            if(checkwin(position1 + 1) == 1){
                eval[0] = depth;
                return eval;
            }
        }
        if((position1 & 2) == 0 and (position2 & 2) == 0){
            if(checkwin(position1 + 2) == 1){
                eval[1] = depth;
                return eval;
            }
        }
        if((position1 & 4) == 0 and (position2 & 4) == 0){
            if(checkwin(position1 + 4) == 1){
                eval[2] = depth;
                return eval;
            }
        }
        if((position1 & 8) == 0 and (position2 & 8) == 0){
            if(checkwin(position1 + 8) == 1){
                eval[3] = depth;
                return eval;
            }
        }
        if((position1 & 16) == 0 and (position2 & 16) == 0){
            if(checkwin(position1 + 16) == 1){
                eval[4] = depth;
                return eval;
            }
        }
        if((position1 & 32) == 0 and (position2 & 32) == 0){
            if(checkwin(position1 + 32) == 1){
                eval[5] = depth;
                return eval;
            }
        }
        if((position1 & 64) == 0 and (position2 & 64) == 0){
            if(checkwin(position1 + 64) == 1){
                eval[6] = depth;
                return eval;
            }
        }
        if((position1 & 128) == 0 and (position2 & 128) == 0){
            if(checkwin(position1 + 128) == 1){
                eval[7] = depth;
                return eval;
            }
        }
        if((position1 & 256) == 0 and (position2 & 256) == 0){
            if(checkwin(position1 + 256) == 1){
                eval[8] = depth;
                return eval;
            }
        }
        for(int i = 0; i < 9; i++)
            if((position1 & (1 << i)) == 0 and (position2 & (1 << i)) == 0)
                eval[i] = minimax(depth - 1, -100, 100, position1 + (1 << i), position2, false);
        return eval;
    }
    else
    {
        if((position1 & 1) == 0 and (position2 & 1) == 0){
            if(checkwin(position2 + 1) == 1){
                eval[0] = -depth;
                return eval;
            }
        }
        if((position1 & 2) == 0 and (position2 & 2) == 0){
            if(checkwin(position2 + 2) == 1){
                eval[1] = -depth;
                return eval;
            }
        }
        if((position1 & 4) == 0 and (position2 & 4) == 0){
            if(checkwin(position2 + 4) == 1){
                eval[2] = -depth;
                return eval;
            }
        }
        if((position1 & 8) == 0 and (position2 & 8) == 0){
            if(checkwin(position2 + 8) == 1){
                eval[3] = -depth;
                return eval;
            }
        }
        if((position1 & 16) == 0 and (position2 & 16) == 0){
            if(checkwin(position2 + 16) == 1){
                eval[4] = -depth;
                return eval;
            }
        }
        if((position1 & 32) == 0 and (position2 & 32) == 0){
            if(checkwin(position2 + 32) == 1){
                eval[5] = -depth;
                return eval;
            }
        }
        if((position1 & 64) == 0 and (position2 & 64) == 0){
            if(checkwin(position2 + 64) == 1){
                eval[6] = -depth;
                return eval;
            }
        }
        if((position1 & 128) == 0 and (position2 & 128) == 0){
            if(checkwin(position2 + 128) == 1){
                eval[7] = -depth;
                return eval;
            }
        }
        if((position1 & 256) == 0 and (position2 & 256) == 0){
            if(checkwin(position2 + 256) == 1){
                eval[8] = -depth;
                return eval;
            }
        }
        for(int i = 0; i < 9; i++)
            if((position1 & (1 << i)) == 0 and (position2 & (1 << i)) == 0)
                eval[i] = minimax(depth - 1, -100, 100, position1, position2 + (1 << i), true);
        return eval;
    }
}

int main()
{
    for(;;){
        short pos1 = 0, pos2 = 0;
        bool pl = rand() % 2;
        if(pl == 0){
            cout << "Bot starts first" << endl;
            for(int itmain = 0;; itmain++){
                vector<int> eval = minimaxmain(9 - (itmain << 1), -100, 100, pos1, pos2, true);
                for(int i = 8; i > -1; i--){
                    cout << eval[i] << " ";
                    if(i % 3 == 0)
                         cout << endl;
                }
                cout << endl;
                int max = -100, move1;
                for(int i = 0; i < 9; i++)
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
                if(itmain == 4){
                    printpos(pos1, pos2);
                    cout << "Draw" << endl;
                    break;
                }
                printpos(pos1, pos2);
                int move2;
                cin >> move2;
                for(; move2 < 0 or move2 > 9 or (pos1 & (1 << (move2 - 1))) > 0 or (pos2 & (1 << (move2 - 1))) > 0;)
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
