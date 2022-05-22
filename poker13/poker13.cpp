
#include <iostream>
#include <string>
#include <ctime>
using namespace std;


enum Suit_n { Heart = 3, Diamonds, Clubs, Spades };
enum Rank { Two = 2, Three, Four, Fife, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

struct Card {
    char Suit;
    int Rank;
};


struct Player {
    string name;
    int score = 5000;
    Card* array;
};

struct Enemy {
    string name;
    int score = 5000;
    Card* array;
};


void deck_init(Card*& deck) {
    int size = _msize(deck) / sizeof(deck[0]);
    for (int i = 0, k = 2; i < 13; i++) {
        deck[i].Suit = Heart;
        deck[i].Rank = k++;
    }
    for (int i = 13, k = 2; i < 26; i++) {
        deck[i].Suit = Diamonds;
        deck[i].Rank = k++;
    }
    for (int i = 26, k = 2; i < 39; i++) {
        deck[i].Suit = Clubs;
        deck[i].Rank = k++;
    }
    for (int i = 39, k = 2; i < 52; i++) {
        deck[i].Suit = Spades;
        deck[i].Rank = k++;
    }
}


void showCards(Card*& deck) {
    int size = _msize(deck) / sizeof(deck[0]);
    for (int i = 0; i < size; i++) {

        //switch (i) {
        //case 9: //hearts
        //    cout << "J" << " " << deck[i].Suit << endl;
        //    break;
        //case 10:
        //    cout << "Q" << " " << deck[i].Suit << endl;
        //    break;
        //case 11:
        //    cout << "K" << " " << deck[i].Suit << endl;
        //    break;
        //case 12:
        //    cout << "A" << " " << deck[i].Suit << endl;
        //    break;
        //case 22: //diamonds
        //    cout << "J" << " " << deck[i].Suit << endl;
        //    break;
        //case 23:
        //    cout << "Q" << " " << deck[i].Suit << endl;
        //    break;
        //case 24:
        //    cout << "K" << " " << deck[i].Suit << endl;
        //    break;
        //case 25:
        //    cout << "A" << " " << deck[i].Suit << endl;
        //    break;
        //case 35: //spades
        //    cout << "J" << " " << deck[i].Suit << endl;
        //    break;
        //case 36:
        //    cout << "Q" << " " << deck[i].Suit << endl;
        //    break;
        //case 37:
        //    cout << "K" << " " << deck[i].Suit << endl;
        //    break;
        //case 38:
        //    cout << "A" << " " << deck[i].Suit << endl;
        //    break;
        //case 48: //clubs
        //    cout << "J" << " " << deck[i].Suit << endl;
        //    break;
        //case 49:
        //    cout << "Q" << " " << deck[i].Suit << endl;
        //    break;
        //case 50:
        //    cout << "K" << " " << deck[i].Suit << endl;
        //    break;
        //case 51:
        //    cout << "A" << " " << deck[i].Suit << endl;
        //    break;
        //default:
        //    cout << deck[i].Rank << " " << deck[i].Suit << endl;
        //    break;
        //}

        if (deck[i].Rank == 11) cout << i + 1 << " [J]" << " of " << deck[i].Suit << endl;
        else if (deck[i].Rank == 12) cout << i + 1 << " [Q]" << " of " << deck[i].Suit << endl;
        else if (deck[i].Rank == 13) cout << i + 1 << " [K]" << " of " << deck[i].Suit << endl;
        else if (deck[i].Rank == 14) cout << i + 1 << " [A]" << " of " << deck[i].Suit << endl;
        else cout << i + 1 << " [" << deck[i].Rank << "]" << " of " << deck[i].Suit << endl;



    }
}

void shuffleDeck(Card*& deck) { //тасовать колоду
    int size = _msize(deck) / sizeof(deck[0]);
    for (int i = 0; i < size; i++) {
        swap(deck[i], deck[rand() % size]);
    }
}



void takeCard(Card*& deck, Card*& hand1, Card*& hand2) { //раздача карт двум игрокам
    int size1 = _msize(hand1) / sizeof(hand1[0]);
    int size2 = _msize(hand2) / sizeof(hand2[0]);
    int counter = 0;
    for (int i = 0, k = 0; i < size1; i++) {
        hand1[i].Rank = deck[i].Rank;
        hand1[i].Suit = deck[i].Suit;
    }
    for (int i = 0, k = 0; i < size2; i++) {
        hand2[i].Rank = deck[i + size1].Rank;
        hand2[i].Suit = deck[i + size1].Suit;
    }

}


void delFromDeck(Card*& deck) { //удаление разданных карт. есть ли необходимость?
    int size = _msize(deck) / sizeof(deck[0]);
    int size2 = size - 7;
    Card* buf = new Card[size2];
    for (int i = 7, k = 0; i < size; i++) {
        buf[k++] = deck[i];
    }
    delete[]deck;
    deck = buf;
}

void showHand(Card*& hand1, Card*& hand2) { //разделить на две функции?
    int size1 = _msize(hand1) / sizeof(hand1[0]);
    int size2 = _msize(hand2) / sizeof(hand2[0]);
    cout << endl;
    cout << "|||||||my_hand|||||||: " << endl;
    for (int i = 0; i < size1; i++) {
        if (hand1[i].Rank == 11) cout << i + 1 << ": [J]" << " of " << hand1[i].Suit << endl;
        else if (hand1[i].Rank == 12) cout << i + 1 << ": [Q]" << " of " << hand1[i].Suit << endl;
        else if (hand1[i].Rank == 13) cout << i + 1 << ": [K]" << " of " << hand1[i].Suit << endl;
        else if (hand1[i].Rank == 14) cout << i + 1 << ": [A]" << " of " << hand1[i].Suit << endl;
        else cout << i + 1 << ": [" << hand1[i].Rank << "] of " << hand1[i].Suit << endl;

    }

    cout << endl;

    cout << "|||||||enemy_hand|||||||: " << endl;
    for (int i = 0; i < size2; i++) {
        if (hand2[i].Rank == 11) cout << i + 1 << ": [J]" << " of " << hand2[i].Suit << endl;
        else if (hand2[i].Rank == 12) cout << i + 1 << ": [Q]" << " of " << hand2[i].Suit << endl;
        else if (hand2[i].Rank == 13) cout << i + 1 << ": [K]" << " of " << hand2[i].Suit << endl;
        else if (hand2[i].Rank == 14) cout << i + 1 << ": [A]" << " of " << hand2[i].Suit << endl;
        else cout << i + 1 << ": [" << hand2[i].Rank << "] of " << hand2[i].Suit << endl;

    }
}


void initTable(Card*& deck, Card*& table) { //выкладываем на стол карты из колоды после того как раздали двум игрокам по две карты
    int size1 = _msize(deck) / sizeof(deck[0]);
    int size2 = _msize(table) / sizeof(table[0]);

    for (int i = 0, k = 4; i < size1; i++) { //сделать более универсальной
        table[i] = deck[k++];
    }

}


void startGame(Card*& deck) {
    deck_init(deck);
    shuffleDeck(deck);

}

void unitHT(Card*& hand, Card*& table, Card*& comb) { //объединение руки и стола в один массив для удобства дальнейшего сравнения карт
    int size1 = _msize(hand) / sizeof(hand[0]);
    int size2 = _msize(table) / sizeof(table[0]);
    int size3 = _msize(comb) / sizeof(comb[0]);
    for (int i = 0; i < size1; i++) {
        comb[i] = hand[i];
    }

    for (int i = 0, k = size1; i < size2; i++, k++) {
        comb[k] = table[i];
    }




    //int size3 = size1 + size2;
    //int counter_Ace = 0;
    //int counter_King = 0;
    //int counter_Queen = 0;
    //int counter_Jack = 0;
    //int counter_ten = 0;
    //int counter_nine = 0;
    //int counter_eight = 0;          //счётчики для подсчёта совпадающих рангов карт
    //int counter_seven = 0;
    //int counter_six = 0;
    //int counter_five = 0;
    //int counter_four = 0;
    //int counter_three = 0;
    //int counter_two = 0;

    //for (int i = 0; i < size1; i++) {
    //    if (hand[i].Rank == 14) counter_Ace++;
    //    else if (hand[i].Rank == 13) counter_King++;
    //    else if (hand[i].Rank == 12) counter_Queen++;
    //    else if (hand[i].Rank == 11) counter_Jack++;
    //    else if (hand[i].Rank == 10) counter_ten++;
    //    else if (hand[i].Rank == 9) counter_nine++;
    //    else if (hand[i].Rank == 8) counter_eight++;
    //    else if (hand[i].Rank == 7) counter_seven++;
    //    else if (hand[i].Rank == 6) counter_six++;
    //    else if (hand[i].Rank == 5) counter_five++;
    //    else if (hand[i].Rank == 4) counter_four++;
    //    else if (hand[i].Rank == 3) counter_three++;
    //    else if (hand[i].Rank == 2) counter_two++;
    //}

    //for (int i = 0; i < size2; i++) {
    //    if (table[i].Rank == 14) counter_Ace++;
    //    else if (table[i].Rank == 13) counter_King++;
    //    else if (table[i].Rank == 12) counter_Queen++;
    //    else if (table[i].Rank == 11) counter_Jack++;
    //    else if (table[i].Rank == 10) counter_ten++;
    //    else if (table[i].Rank == 9) counter_nine++;
    //    else if (table[i].Rank == 8) counter_eight++;   //можно ли сделать короче?
    //    else if (table[i].Rank == 7) counter_seven++;
    //    else if (table[i].Rank == 6) counter_six++;
    //    else if (table[i].Rank == 5) counter_five++;
    //    else if (table[i].Rank == 4) counter_four++;
    //    else if (table[i].Rank == 3) counter_three++;
    //    else if (table[i].Rank == 2) counter_two++;
    //}

    //cout << "  two: " << counter_two << "  three: " << counter_three << "  four: " << counter_four << "  five:" << counter_five << endl;
    //cout << "  six: " << counter_six << "  seven: " << counter_seven << "  eight: " << counter_eight << "  nine: " << counter_nine << endl;
    //cout << "  ten: " << counter_ten << "  jack: " << counter_Jack << "  queen: " << counter_Queen << "  king: " << counter_King << "  ace: " << counter_Ace << endl;

    //int array[13] = { counter_two, counter_three, counter_four, counter_five, counter_six, counter_seven, counter_eight, counter_nine, counter_ten, counter_Jack, counter_Queen, counter_King, counter_Ace  };
    //for (int i = 0; i < 13; i++) {
    //    if (array[i] == 2) cout << i + 2 << " Pair";
    //    else if (array[i] == 3) cout << i + 2 << " Set trips";
    //    else if (array[i] == 4)  cout << i + 2 << " Kare";
    //}

    //for (int i = 0; i < 5; i++) {
    //    for (int j = 0; j < 5; j++) {
    //        if(hand[i].Rank)
    //    }
    //}


}

void showComb(Card*& comb) {
    int size = _msize(comb) / sizeof(comb[0]);
    cout << "Combin" << endl;
    for (int i = 0; i < size; i++) {
        if (comb[i].Rank == 11) cout << i + 1 << ": [J]" << " of " << comb[i].Suit << endl;
        else if (comb[i].Rank == 12) cout << i + 1 << ": [Q]" << " of " << comb[i].Suit << endl;
        else if (comb[i].Rank == 13) cout << i + 1 << ": [K]" << " of " << comb[i].Suit << endl;
        else if (comb[i].Rank == 14) cout << i + 1 << ": [A]" << " of " << comb[i].Suit << endl;
        else cout << i + 1 << ": [" << comb[i].Rank << "] of " << comb[i].Suit << endl;

    }
}


void combinations(Card*& comb) {
    int size = _msize(comb) / sizeof(comb[0]);
    int counterR = 0;
    int counterS = 0;
    Card greatCard;
    bool flag = false;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (comb[i].Rank == comb[j].Rank) counterR++;
            if (comb[i].Suit == comb[j].Suit) counterS++;
        }
    }

    //cout << counterR << endl;
    if (counterR == 1) cout << " Pair" << endl;
    else if (counterR == 2) cout << " Double pair" << endl;
    else if (counterR == 3) cout << " Tripple" << endl;
    else if (counterR == 1 && counterR == 3) cout << " Full House";
    else if (counterR == 6) cout << " Kare" << endl;
    else if (counterS == 10) cout << " Street Flash" << endl;
    else cout << "No combination" << endl;

    int counter2 = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - (i + 1); j++) {
            bool flag = true;
            if (comb[j].Rank < comb[j + 1].Rank) {
                flag = false;
                counter2++;
            }
        }
        if (flag)break;
    }
    //cout << counterS << endl;
}



void playerTurn(Player &player1, Player &player2) {
    int bank = 500;
    int choise;
    cout << "Input your choise. 1 to up, 2 to equal, 3 to fold: " << endl;
    cin >> choise;
    switch (choise) {
    case 1:
        player1.score += 50;
        cout << player1.name << " | " << player1.score << endl;
        cout << player2.name << " | " << player2.score << endl;
        break;
    case 2:
        player1.score = player2.score;
        cout << player1.name << " | " << player1.score << endl;
        cout << player2.name << " | " << player2.score << endl;
        break;
    case 3:
        player1.score = 0;
        cout << player1.name << " | " << player1.score << endl;
        cout << player2.name << " | " << player2.score << endl;
        break;
    }
}


void enemyTurn(Player &player1, Player &player2) {
    int randCount = 0;
    for (int i = 0; i < 2; i++) {
        randCount = 1 + i - rand() % 2;
    }
    if (randCount == 0) player1.score += 50;
    if (randCount == 1) player1.score = player2.score;
    if (randCount == 2) player1.score = 0;
}

int main() {
    srand(time(NULL));
    Card* deck = new Card[52];
    Card* test_hand = new Card[2]{};
    Card* test_table = new Card[3]{ 3,5,6 };

    test_hand[0].Rank = 5;
    test_hand[0].Suit = 4;

    test_hand[1].Rank = 4;
    test_hand[1].Suit = 5;


    test_table[0].Rank = 5;
    test_table[0].Suit = 3;

    test_table[1].Rank = 5;
    test_table[1].Suit = 3;

    test_table[2].Rank = 5;
    test_table[2].Suit = 3;





    Card* my_hand = new Card[2];
    Card* enemy_hand = new Card[2];
    Card* table = new Card[3];
    Card* comb = new Card[5];
    deck_init(deck);
    shuffleDeck(deck);
    showCards(deck);
    takeCard(deck, my_hand, enemy_hand);
    initTable(deck, table);

    Player player1;
    player1.name = "Bebe";
    Player player2;
    player2.name = "Bubu";

    
    showHand(my_hand, enemy_hand);
    cout << endl << "-TABLE-" << endl;
    showCards(table);
    cout << endl << endl;
    /*unitHT(my_hand, table, comb);*/
    unitHT(my_hand, table, comb);
    showComb(comb);
    cout << endl;
    cout << "My combinations:   " << endl;
    combinations(comb);
    cout << endl << endl;
    /*unitHT(enemy_hand, table, comb);
    showComb(comb);*/
    cout << endl;
    cout << "Enemy combinations:   " << endl;
    combinations(comb);
    cout << endl;
    while (1) {
        playerTurn(player1, player2);
        enemyTurn(player2, player1);

        if (player2.score == 0) {
            cout << player1.name << " win!";
            break;
        }
        if (player1.score == 0) {
            cout << player2.name << " win!";
            break;
        }
    }

}

