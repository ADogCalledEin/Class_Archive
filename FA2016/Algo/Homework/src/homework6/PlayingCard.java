package homework6;
//NAME:Griffin Siadak
//Rishi Javia and Pim trouerbach helped me a ton on this assignment
import java.util.Iterator;

public class PlayingCard implements Comparable<PlayingCard> {
	
	public enum  Rank { Two, Three, Four, Five, Six,
		Seven, Eight, Nine, Ten, Jack, Queen, King, Ace }
	
	public enum Suit { Clubs, Diamonds, Hearts, Spades }

	private Rank _r;
	private Suit _s;
	
	public PlayingCard(Rank r, Suit s) {
		this._r=r;
		this._s=s;
	}
	
	public Rank rank() {
		return this._r;
	}
	
	public Suit suit() {
		return this._s;
	}

	public static void knuthShuffle(Object[] a) { // Shuffling from algs4
		int n = a.length;
		for (int i = 0; i < n; i++) {
			int r = i + (int) (Math.random() * (n - i));
			Object swap = a[r];
			a[r] = a[i];
			a[i] = swap;
		}
	}
	/***
	 * 
	 * @return an Iterator over a set of 52 PlayingCard objects in
	 * their natural order
	 */
	public static Iterator<PlayingCard> OrderedDeck() { //builds a deck that takes the first suit, adds the ranks, then moves to the next suit
		final PlayingCard[] deck = new PlayingCard[52];
		int counter = 0;
		for(int i = 0; i < 4; i++){
			Suit s = Suit.values()[i];
			for(int k=0; k< 13; k++){
				Rank r = Rank.values()[k];
				PlayingCard card = new PlayingCard(r, s);
				deck[counter] = card;
				counter++;
			}
		}
		Iterator<PlayingCard> iter = new Iterator<PlayingCard>() {
			int position = 0;
			@Override
			public boolean hasNext() {
				return (position < deck.length);
			}

			@Override
			public PlayingCard next() {
				return deck[position++];
			}

			@Override
			public void remove() {

			}
		};
		return iter;

	}
	
	/***
	 * 
	 * @return an Iterator over a set of 52 PlayingCard objects
	 *  in a randomized order
	 */
	public static Iterator<PlayingCard> ShuffledDeck() { //basically does the same thing but calls a shuffle function.
		final PlayingCard[] deck = new PlayingCard[52];  //Please do tell in assignment comments if I could have called OrderedDeck() somehow from here. I tried but nothing would pass the tests we wrote.
		int counter = 0;
		int position = 0;
		for(int i = 0; i < 4; i++){
			Suit s = Suit.values()[i];
			for(int k=0; k< 13; k++){
				Rank r = Rank.values()[k];
				PlayingCard card = new PlayingCard(r, s);
				deck[counter] = card;
				counter++;
			}
		}
		knuthShuffle(deck);
		Iterator<PlayingCard> iter = new Iterator<PlayingCard>() {
			int position = 0;
			@Override
			public boolean hasNext(){ return (position < deck.length); }

			@Override
			public PlayingCard next() { return deck[position++]; }

			@Override
			public void remove() {

			}

		};
		return iter;

	}
	
	/***
	 * asssumptions for natural ordering:
	 *   Rank:  Two < Three < ..Ten < Jack < Queen < King < Ace
	 *   Suit: Clubs < Diamonds < Hearts < Spades
	 */
	@Override
	public int compareTo(PlayingCard o) {
		if (this.rank().compareTo(o.rank()) > 0) {
			return 1;
		}
		else if(this.rank().compareTo(o.rank()) < 0) {
			return -1;
		}
		else{
			if (this.suit().compareTo(o.suit()) > 0) return 1;
			else if (this.suit().compareTo(o.suit()) < 0) return -1;
			else{
				return 0;
			}
		}
	}

}
