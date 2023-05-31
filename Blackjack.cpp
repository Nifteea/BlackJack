//fix aces for dealer
#include <iostream>
#include <Windows.h>
#include <cstring>
#include <cstdlib>
#include <ctime>

struct Card
{
    char m_cardName[6];
    char m_cardSuit[9];
    int m_cardValue;
};

//how to parse array 
void generateDeck(Card Deck[])
{
    for (int Suit = 0; Suit < 52; Suit += 13) 
    {

        for (int Card = 0; Card < 13; Card++) 
        {

            if (Card > 9) { Deck[Suit + Card].m_cardValue = 10; }
            else { Deck[Suit + Card].m_cardValue = Card + 1; }

            if (Suit == 0) { strcpy(Deck[Suit + Card].m_cardSuit, "Hearts"); }
            if (Suit == 13) { strcpy(Deck[Suit + Card].m_cardSuit, "Diamonds"); }
            if (Suit == 26) { strcpy(Deck[Suit + Card].m_cardSuit, "Clubs"); }
            if (Suit == 39) { strcpy(Deck[Suit + Card].m_cardSuit, "Spades"); }
            switch (Card)
            {
            case 0: {strcpy(Deck[Suit + Card].m_cardName, "Ace"); break; } 
            case 1: {strcpy(Deck[Suit + Card].m_cardName, "Two"); break; } 
            case 2: {strcpy(Deck[Suit + Card].m_cardName, "Three"); break; } 
            case 3: {strcpy(Deck[Suit + Card].m_cardName, "Four"); break; } 
            case 4: {strcpy(Deck[Suit + Card].m_cardName, "Five"); break; } 
            case 5: {strcpy(Deck[Suit + Card].m_cardName, "Six"); break; }
            case 6: {strcpy(Deck[Suit + Card].m_cardName, "Seven"); break; } 
            case 7: {strcpy(Deck[Suit + Card].m_cardName, "Eight"); break; } 
            case 8: {strcpy(Deck[Suit + Card].m_cardName, "Nine"); break; }
            case 9: {strcpy(Deck[Suit + Card].m_cardName, "Ten"); break; } 
            case 10: {strcpy(Deck[Suit + Card].m_cardName, "Jack"); break; 
            case 11: {strcpy(Deck[Suit + Card].m_cardName, "Queen"); break; } 
            case 12: {strcpy(Deck[Suit + Card].m_cardName, "King"); break; } 
            default: break;
            }
        }
    }
}

void shuffle(Card Deck[])
{
    
}

void shuffle(char cardArray[52][2])
{
    int x;
    int y;
    char tempSuit;
    char tempValue;
    for (int i = 0; i < 1000; i++) //make 1000 swaps
    {
        x = rand() % 52;
        y = rand() % 52;
        tempValue = cardArray[x][0]; //temporarily store contents of x in temporary variables
        tempSuit = cardArray[x][1];
        cardArray[x][0] = cardArray[y][0]; //replace contents of x with contents of y
        cardArray[x][1] = cardArray[y][1];
        cardArray[y][0] = tempValue; //replace contents of y with contents of temporary variables
        cardArray[y][1] = tempSuit;
    }

}

void getRandomCard(char cardArray[52][2], char chosenCard[2])
{
    int x = rand() % 52;
    if (cardArray[x][0] == 'x') //has this card already been picked
    {
        int getRandomCard();
    }
    else //if not already picked, choose a random card
    {
        chosenCard[0] = cardArray[x][0];
        chosenCard[1] = cardArray[x][1];
        cardArray[x][0] = 'x'; //remove card suit and type from cardArray
        cardArray[x][1] = 'x';
    }
}

void displayPlayerhand(char playerHand[11][2]) //output player's hand
{

    std::cout << playerHand[0][0];
    std::cout << playerHand[0][1];
    int x = 1;
    while (x < 11 && playerHand[x][0] != 'x')
    {
        std::cout << ", ";
        std::cout << playerHand[x][0];
        std::cout << playerHand[x][1];
        x++;
    }
    std::cout << std::endl;
}

void displayDealerhand(char dealerHand[11][2]) //output dealer's hand
{
    std::cout << dealerHand[0][0];
    std::cout << dealerHand[0][1];
    std::cout << ", ";
    std::cout << "hole card";
    int x = 2;
    while (x < 11 && dealerHand[x][0] != 'x') //outputs every card and stops when reaches an empty space
    {
        std::cout << ", ";
        std::cout << dealerHand[x][0];
        std::cout << dealerHand[x][1];
        x++;
    }
    std::cout << std::endl;
}

//int cardValue(char value, bool dealer) //returns the value of the card
//{
//    char temp;
//    switch (value)
//    {
//    case 'A':
//        if (dealer == true)
//        {
//            return 11;
//        }
//        else
//        {
//            while (1) //repeat until player enters a valid input
//            {
//                std::cout << "enter A if you would like your ace to have a value of 1 or enter B for 11: ";
//                std::cin >> temp;
//                if (temp == 'A')
//                {
//                    return 1;
//                }
//                else if (temp == 'B')
//                {
//                    return 11;
//                }
//            }
//        }
//    case 'T':
//        return 10;
//    case 'J':
//        return 10;
//    case 'Q':
//        return 10;
//    case 'K':
//        return 10;
//    default:
//        return value - 48;
//    }
//}

int sumHand(char hand[11][2], bool dealer) //adds the values of every card in a hand
{
    int x = 0;
    int sum = 0;
    while (x < 11 && hand[x][0] != 'x') //ends if all valid cards in hand checked
    {
        sum = sum + cardValue(hand[x][0], dealer);
        x++;
    }
    return sum;
}

void displayStats(char playerHand[11][2], char dealerHand[11][2], int moneyPot, int playerBet)
{
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "money pot: " << moneyPot << std::endl;
    std::cout << "player bet: " << playerBet << std::endl;
    std::cout << "player's hand: ";
    displayPlayerhand(playerHand);
    std::cout << "dealer's hand: ";
    displayDealerhand(dealerHand);
    std::cout << "player's card total: " << sumHand(playerHand, false) << std::endl;
    std::cout << "dealer's card total: " << sumHand(dealerHand, true) << std::endl;
}

int main(void)
{
    bool exitFlag = false;
    int menuChoice;
    char returnToMenu;
    int moneyPot = 100;
    int playerBet = 0;
    //char cardArray[52][2];
    Card Deck[52] = { 0 }; //***
    char chosenCard[2];
    char playerHand[11][2]; //11 cards is the worst case scenario: without busting is 11 total cards: four aces, four 2's and three 3's
    char dealerHand[11][2];
    int playerTotal = 0;
    int dealerTotal = 0;
    bool stand = false;
    char playerInput;
    bool valid;
    bool flag;
    int pointer;

    srand(time(0));

    while (exitFlag == false) //while player hasn't run out of money in money pot and still wants to play
    {
        Card Deck[52] = { 0 }; //***
        generateDeck(Deck);
        //generateDeck(cardArray);

        shuffle(cardArray);

        for (int i = 0; i < 11; i++) //sets every item in player and dealer's hands to x (empty)
        {
            playerHand[i][0] = 'x';
            playerHand[i][1] = 'x';
            dealerHand[i][0] = 'x';
            dealerHand[i][1] = 'x';
        }
        for (int i = 0; i < 2; i++) //2 random cards are delt to the player and dealer
        {
            getRandomCard(cardArray, chosenCard);
            playerHand[i][0] = chosenCard[0];
            playerHand[i][1] = chosenCard[1];
            getRandomCard(cardArray, chosenCard);
            dealerHand[i][0] = chosenCard[0];
            dealerHand[i][1] = chosenCard[1];
        }

        system("CLS"); //clear screen
        menuChoice = 0;
        std::cout << "Blackjack Menu\n1.Play\n2.Instructions\n3.Debug\n4.Exit\n";
        std::cin >> menuChoice;
        switch (menuChoice)
        {
        case 1: system("CLS"); //play
            std::cout << "Play Game Selected" << std::endl;
            displayStats(playerHand, dealerHand, moneyPot, playerBet);
            std::cout << "-------------------------------------" << std::endl;
            std::cout << "please place your bet: ";
            std::cin >> playerBet;
            moneyPot = moneyPot - playerBet;
            while (stand == false && playerTotal < 21) //while the player hasn't gone over 21 cards they can choose to hit or stay
            {
                valid = false;
                while (valid == false) //keep asking player if they want to hit or stay until a valid input is given
                {
                    displayStats(playerHand, dealerHand, moneyPot, playerBet);
                    std::cout << "-------------------------------------" << std::endl;
                    std::cout << "would you like to hit or stay?(h/s): " << std::endl;
                    std::cin >> playerInput;
                    switch (playerInput)
                    {
                    case 'h': //the player chooses to hit
                        flag = false;
                        pointer = 0;
                        while (pointer < 11 || flag == false) //inserting new card into the first empty position in playerHand
                        {
                            if (playerHand[pointer][0] == 'x' && flag == false) //if the position is empty
                            {
                                getRandomCard(cardArray, chosenCard);
                                playerHand[pointer][0] = chosenCard[0];
                                playerHand[pointer][1] = chosenCard[1];
                                flag = true;
                            }
                            else
                            {
                                pointer++;
                            }
                        }
                        valid = true;
                        break;
                    case 's': //the player chooses to stay
                        stand = true;
                        valid = true;
                        break;
                    default: //the player entered an invalid input
                        std::cout << "you entered an invalid input" << std::endl;
                        break;
                    }
                }
            }

            if (sumHand(playerHand, false) <= 21) //if player hasn't lost by exceeding 21
            {
                dealerTotal = sumHand(dealerHand, true); //dealer's turn starts, first calculates total of 2 cards
                while (sumHand(dealerHand, true) < 17)
                {
                    flag = false;
                    pointer = 0;
                    while (pointer < 11 || flag == false) //inserting new card into the first empty position in dealerHand
                    {
                        if (dealerHand[pointer][0] == 'x' && flag == false) //if the position is empty
                        {
                            getRandomCard(cardArray, chosenCard);
                            dealerHand[pointer][0] = chosenCard[0];
                            dealerHand[pointer][1] = chosenCard[1];
                            //temporary - just for testing
                            std::cout << "dealer's hand: ";
                            for (int i = 0; i < 11; i++)
                            {
                                std::cout << dealerHand[i][0];
                                std::cout << dealerHand[i][1];
                            }
                            std::cout << std::endl;
                            flag = true;
                            dealerTotal = sumHand(dealerHand, true);
                            std::cout << "dealer's total is " << dealerTotal << std::endl;
                        }
                        else
                        {
                            pointer++;
                        }
                    }
                }

                playerTotal = sumHand(playerHand, false);
                dealerTotal = sumHand(dealerHand, true);
                int count = 0;
                while (dealerTotal > 21 && count < 11) //if dealerTotal exceeds 21, dealerHand is checked through for any aces and assigns them the value 1
                {
                    if (dealerHand[count][0] == 'A') {
                        dealerTotal = dealerTotal - 10;
                    }
                }
                if (playerTotal == 21) //if player gets 21 points
                {
                    moneyPot = moneyPot + playerBet + playerBet * 2.5;
                    std::cout << "you got 21 points and won. Your bet is returned and you win an additional 2.5x your bet" << std::endl;
                }
                else if (dealerTotal > 21) //if the dealer got more than 21 points
                {
                    moneyPot = moneyPot + playerBet + playerBet * 2;
                    std::cout << "the dealer's hand went above 21 so you won. Your bet is returned and you win an additional 2x your bet" << std::endl;
                }
                else if (playerTotal > dealerTotal) //if player gets more points than the dealer
                {
                    moneyPot = moneyPot + playerBet + playerBet * 2;
                    std::cout << "you got " << playerTotal << " points and beat the dealer. Your bet is returned and you win an additional 2x your bet" << std::endl;
                }
                else if (playerTotal == dealerTotal) //if player gets the same number of points as the dealer
                {
                    moneyPot = moneyPot + playerBet;
                    std::cout << "you got the same number number of points as the dealer and drew. Your bet is returned" << std::endl;
                }
                else //if player gets less points than the dealer
                {
                    moneyPot = moneyPot;
                    std::cout << "you got " << playerTotal << " points and lost to the dealer. You win nothing and lose your bet" << std::endl;
                }
            }
            else
            {
                std::cout << "you exceeded 21 points and lost. You win nothing and lose your bet" << std::endl;
            }
            std::cout << "you have " << moneyPot << " coins in your money pot" << std::endl;


            if (moneyPot == 0) //if the player runs out of money in their moneyPot
            {
                std::cout << "your money pot is empty, the game ends" << std::endl;
                exitFlag = false; //game ends
            }
            else
            {
                char playerChoice;
                std::cout << "do you want to play again? y/n" << std::endl;
                std::cin >> playerChoice;
                if (playerChoice == 'n')
                {
                    std::cout << "you choose to end the game, you have " << moneyPot << " coins in your money pot" << std::endl;
                    exitFlag = false; //game ends
                }
            }
            std::cout << "Enter any value to return to the menu: " << std::endl;
            std::cin >> returnToMenu;
            break;

        case 2: system("CLS"); //instructions
            std::cout << "Instructions:\n------------------------------------------------------" << std::endl;
            std::cout << "The goal of blackjack is to have a hand that has a higher total card value than the dealer's but doesn't go over 21.\n";
            std::cout << "The player starts off with a money pot with 100 pounds\n";
            std::cout << "At the start of each game, the player can place a bet.\n";

            std::cout << "Cards 2 through 10 are worth their face value.\n";
            std::cout << "Jacks, Queensand Kings are worth 10 points each.\n";
            std::cout << "Aces are worth either 1 or 11 points (your menuChoice).\n" << std::endl;

            std::cout << " the start of the game, the playerand dealer both receive 2 cards each.\n";
            std::cout << "The player can see one of the dealer's cards.\n";
            std::cout << "The other(hole card) is shown once the player ends their turn.\n";
            std::cout << "After the cards are delt, the player can choose to stand (keep the cards they have) or hit (take more cards from the deck).\n";
            std::cout << "The player can choose to draw as many times as they want.\n" << std::endl;

            std::cout << "If the player goes over 21 (they go bust), then the player loses the gameand their bet.\n";
            std::cout << "Once the player chooses to stand, ending their turn, the dealer's hole card is revealed.\n";
            std::cout << "If the point total is less than 17 they must hit otherwise they must stand.\n";
            std::cout << "If the dealer goes bust or if the player has a higher point total than the dealer, the player winsand their bet is doubled.\n";
            std::cout << "If the player wins with a point value of 21 (a blackjack win), the player wins a bonus amount equal to half their origional bet.\n";
            std::cout << "If the playerand the dealer both have the same point total, the bet is returned.\n";
            std::cout << "Otherwise the dealer winsand the player looses their bet.\n" << std::endl;
            std::cout << "The game ends when the player runs out of money in the money pot or they choose to end the game.\n------------------------------------------------------" << std::endl;
            std::cout << "Enter any value to return to the menu: " << std::endl;
            std::cin >> returnToMenu;
            break;

        case 3: //debug
            std::cout << "dealer's hole card: " << playerHand[1][0] << playerHand[1][1] << std::endl; //outputs dealer's hole card
            std::cout << "Enter any value to return to the menu: " << std::endl;
            std::cin >> returnToMenu;
            break;

        case 4: //exit
            system("CLS");
            std::cout << "Exit Selected .. Good Bye!" << std::endl;
            exitFlag = true;
            break;

        default: system("CLS"); //invalid menu input
            std::cout << "Please enter a number from 1-4" << std::endl;
            std::cout << "Enter any value to return to the menu: " << std::endl;
            std::cin >> returnToMenu;
            break;
        }
    }
    return 0;
}
