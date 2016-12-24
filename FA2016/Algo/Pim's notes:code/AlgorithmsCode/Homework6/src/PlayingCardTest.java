import java.util.Iterator;

import static org.junit.Assert.*;

/**
 * Created by Pim Trouerbach on 10/5/16.
 */
public class PlayingCardTest {
    @org.junit.Test
    public void orderedDeck() throws Exception {
        Iterator<PlayingCard> cardIterator = PlayingCard.OrderedDeck();
        for(int i = 0; i < 52; i++){
            PlayingCard card = cardIterator.next();
            System.out.println(card.rank()+ " of " + card.suit());
        }
    }

    @org.junit.Test
    public void shuffledDeck() throws Exception {
        Iterator<PlayingCard> cardIterator = PlayingCard.ShuffledDeck();
        for(int i = 0; i < 52; i++){
            PlayingCard card = cardIterator.next();
            System.out.println(card.rank()+ " of " + card.suit());
        }
    }

    @org.junit.Test
    public void compareTo() throws Exception {
        PlayingCard card = new PlayingCard(PlayingCard.Rank.Two, PlayingCard.Suit.Diamonds);
        PlayingCard card1 = new PlayingCard(PlayingCard.Rank.Eight, PlayingCard.Suit.Diamonds);
        PlayingCard card2 = new PlayingCard(PlayingCard.Rank.Eight, PlayingCard.Suit.Diamonds);
        PlayingCard card3 = new PlayingCard(PlayingCard.Rank.Eight, PlayingCard.Suit.Diamonds);
        PlayingCard card4 = new PlayingCard(PlayingCard.Rank.Eight, PlayingCard.Suit.Hearts);
        PlayingCard card5 = new PlayingCard(PlayingCard.Rank.Eight, PlayingCard.Suit.Spades);
        PlayingCard card6 = new PlayingCard(PlayingCard.Rank.Ace, PlayingCard.Suit.Clubs);
        PlayingCard card7 = new PlayingCard(PlayingCard.Rank.Two, PlayingCard.Suit.Hearts);
        PlayingCard card8 = new PlayingCard(PlayingCard.Rank.Eight, PlayingCard.Suit.Hearts);


        int result = card.compareTo(card1);
        System.out.println(result);
        assertEquals(result, -1);
        result = card2.compareTo(card3);
        System.out.println(result);
        assertEquals(result, 0);
        result = card4.compareTo(card3);
        System.out.println(result);
        assertEquals(result, 1);
        result = card5.compareTo(card4);
        System.out.println(result);
        assertEquals(result, 1);
        result = card7.compareTo(card8);
        System.out.println(result);
        assertEquals(result, -1);
        result = card8.compareTo(card7);
        System.out.println(result);
        assertEquals(result, 1);
        result = card6.compareTo(card);
        System.out.println(result);
        assertEquals(result, 1);



    }

}