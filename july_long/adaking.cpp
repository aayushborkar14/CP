#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void printBoard(char board[8][8]) {
    for (int i=0; i < 8; i++) {
        for (int j=0; j < 8; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ };
    cin >> t;
    int k{ };
    vector<pair<int, int>> priorityList;
    priorityList.push_back(make_pair(2, 2));
    priorityList.push_back(make_pair(2, 3));
    priorityList.push_back(make_pair(2, 4));
    priorityList.push_back(make_pair(3, 2));
    priorityList.push_back(make_pair(3, 4));
    priorityList.push_back(make_pair(4, 2));
    priorityList.push_back(make_pair(4, 3));
    priorityList.push_back(make_pair(4, 4));

    priorityList.push_back(make_pair(1, 1));
    priorityList.push_back(make_pair(1, 2));
    priorityList.push_back(make_pair(1, 3));
    priorityList.push_back(make_pair(1, 4));
    priorityList.push_back(make_pair(1, 5));
    priorityList.push_back(make_pair(2, 1));
    priorityList.push_back(make_pair(2, 5));
    priorityList.push_back(make_pair(3, 1));
    priorityList.push_back(make_pair(3, 5));
    priorityList.push_back(make_pair(4, 1));
    priorityList.push_back(make_pair(4, 5));
    priorityList.push_back(make_pair(5, 1));
    priorityList.push_back(make_pair(5, 2));
    priorityList.push_back(make_pair(5, 3));
    priorityList.push_back(make_pair(5, 4));
    priorityList.push_back(make_pair(5, 5));

    priorityList.push_back(make_pair(0, 0));
    priorityList.push_back(make_pair(0, 1));
    priorityList.push_back(make_pair(0, 2));
    priorityList.push_back(make_pair(0, 3));
    priorityList.push_back(make_pair(0, 4));
    priorityList.push_back(make_pair(0, 5));
    priorityList.push_back(make_pair(0, 6));
    priorityList.push_back(make_pair(1, 0));
    priorityList.push_back(make_pair(1, 6));
    priorityList.push_back(make_pair(2, 0));
    priorityList.push_back(make_pair(2, 6));
    priorityList.push_back(make_pair(3, 0));
    priorityList.push_back(make_pair(3, 6));
    priorityList.push_back(make_pair(4, 0));
    priorityList.push_back(make_pair(4, 6));
    priorityList.push_back(make_pair(5, 0));
    priorityList.push_back(make_pair(5, 6));
    priorityList.push_back(make_pair(6, 0));
    priorityList.push_back(make_pair(6, 1));
    priorityList.push_back(make_pair(6, 2));
    priorityList.push_back(make_pair(6, 3));
    priorityList.push_back(make_pair(6, 4));
    priorityList.push_back(make_pair(6, 5));
    priorityList.push_back(make_pair(6, 6));
    
    priorityList.push_back(make_pair(7, 0));
    priorityList.push_back(make_pair(7, 1));
    priorityList.push_back(make_pair(7, 2));
    priorityList.push_back(make_pair(7, 3));
    priorityList.push_back(make_pair(7, 4));
    priorityList.push_back(make_pair(7, 5));
    priorityList.push_back(make_pair(7, 6));
    priorityList.push_back(make_pair(7, 7));
    priorityList.push_back(make_pair(0, 7));
    priorityList.push_back(make_pair(1, 7));
    priorityList.push_back(make_pair(2, 7));
    priorityList.push_back(make_pair(3, 7));
    priorityList.push_back(make_pair(4, 7));
    priorityList.push_back(make_pair(5, 7));
    priorityList.push_back(make_pair(6, 7));
    while (t--) {
        cin >> k;
        char board[8][8];
        for (int i=0; i < 8; i++) {
            for (int j=0; j < 8; j++) {
                board[i][j] = 'X';
            }
        }
        board[3][3] = 'O';

        int numOfFreed = 1;
        while (numOfFreed < k) {
            board[priorityList.at(numOfFreed-1).first][priorityList.at(numOfFreed-1).second] = '.';
            numOfFreed++;
        }
        printBoard(board);
    }
}
