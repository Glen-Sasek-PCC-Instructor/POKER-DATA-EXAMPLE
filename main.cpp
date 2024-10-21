// Terminal compile and run command
// g++ -Wall -Werror -o main main.cpp && ./main && rm main

#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

class Card {
public:
    static const char SUIT_CHAR[];
    static const char RANK_CHAR[];
    int suit;
    int rank;

    void print() {
        cout << RANK_CHAR[rank] << SUIT_CHAR[suit];
    }
};

const char Card::RANK_CHAR[] = "xA12345678910JQK";
const char Card::SUIT_CHAR[] = "xHSDC";


class Hand {
public:
    static const int CARDS_PER_HAND = 5;
    Card cards[CARDS_PER_HAND];
    int value = 0;

    Hand(istream &in) {
        for(int i = 0 ; i < Hand::CARDS_PER_HAND; i++) {
            in >> cards[i].suit;
            in.get();
            in >> cards[i].rank;
            in.get();
        }
        in >> value;
    }

    void print() {
        for(int i = 0 ; i < Hand::CARDS_PER_HAND; i++) {
            cards[i].print();
            cout << ' ';
        }
        cout << endl;
    }
};

const char FILENAME[] = "poker-hand-testing.csv";

int main() {
    fstream fin(FILENAME);

    // Ignore header row
    fin.ignore(numeric_limits<streamsize>::max(), '\n');

    while(fin && fin.peek() != fin.eof()) {
        Hand hand(fin);
        hand.print();
        fin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}