#include <iostream>
#include <stdlib.h>     // rand
#include <time.h>       // time

using namespace std;

enum Suit {NONE, CLUBS, HEARTS, DIAMONDS, SPADES};

class Card
{
public:
    int value;
    Suit suit;
};

class CardHand
{
private:
    int HandSize;

public:
    int GetHandSize() const;
    bool AddCard(Card new_card);
};

bool DealCards(CardHand hands[], int num_hands)
{
    // check if there are enough cards (only 52 cards available)
    int cards_needed = 0;
    for (int hand_index = 0; hand_index < num_hands; hand_index++)
    {
        cards_needed = cards_needed + hands[hand_index].GetHandSize();
    }
    if (cards_needed > 52)
        return false;

    const int NUM_CARDS = 52;
    Card deck[NUM_CARDS];
    int current_value = 1;
    Suit current_suit = CLUBS;

    // create the deck of cards
    for (int card_index = 0; card_index < NUM_CARDS; card_index++)
    {
        deck[card_index].value = current_value;
        deck[card_index].suit = current_suit;

        current_value++;
        if (current_value > 13)
        {
            switch (current_suit)
            {
                case CLUBS: current_suit = HEARTS;
                    break;
                case HEARTS: current_suit = DIAMONDS;
                    break;
                case DIAMONDS: current_suit = SPADES;
                    break;
                default: break;
            }
            current_value = 1;
        }
    }

    // seed the random number generator
    srand(time(NULL));

    // randomly pull cards from the deck and assign them to each hand
    for (int hand_index = 0; hand_index < num_hands; hand_index++)
    {
        for (int card_index = 0; card_index < hands[hand_index].GetHandSize(); card_index++)
        {
            Card assign_card;
            assign_card.value = 0;
            assign_card.suit = NONE;

            while (assign_card.value == 0)
            {
                int try_card = rand() % 52;

                if (deck[try_card].value > 0)
                {
                    assign_card.value = deck[try_card].value;
                    assign_card.suit = deck[try_card].suit;
                    deck[try_card].value = 0;
                    deck[try_card].suit = NONE;
                }
            }

            hands[hand_index].AddCard(assign_card);
        }
    }

    return true;
}

int main()
{
    return 0;
}

CardHand::CardHand(){
    HandSize=5;
}

int CardHand::GetHandSize() const
{
    return 0;
}

bool CardHand::AddCard(Card new_card)
{
    return true;
}
