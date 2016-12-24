import java.util.Iterator;


/***
 * Made my Pim Trouerbach
 *
 */




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


	/**
	 * Rearranges an array of objects in uniformly random order
	 * (under the assumption that {@code Math.random()} generates independent
	 * and uniformly distributed numbers between 0 and 1).
	 * @param a the array to be shuffled
	 * @source http://algs4.cs.princeton.edu/11model/Knuth.java.html
	 */
	public static void knuthShuffle(Object[] a) {
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
	public static Iterator<PlayingCard> OrderedDeck() { //
        final PlayingCard[] deck = new PlayingCard[52];
        int counter = 0;
        int currentPos = 0;
        for(int i = 0; i < 4; i++){
            Suit s = Suit.values()[i];
            for(int j=0; j< 13; j++){
                Rank r = Rank.values()[j];
                PlayingCard card = new PlayingCard(r, s);
                deck[counter] = card;
                counter++;
            }
        }
        Iterator<PlayingCard> itr = new Iterator<PlayingCard>() {
            int currentPos = 0;
            @Override
            public boolean hasNext() {
                return (currentPos < deck.length);
            }

            @Override
            public PlayingCard next() {
                return deck[currentPos++];
            }

			@Override
			public void remove() {

			}
		};
        return itr;
	}


	/***
	 *
	 * @return an Iterator over a set of 52 PlayingCard objects
	 *  in a randomized order
	 */
	public static Iterator<PlayingCard> ShuffledDeck() {
        final PlayingCard[] deck = new PlayingCard[52];
        int counter = 0;
        int currentPos = 0;
        for(int i = 0; i < 4; i++){
            Suit s = Suit.values()[i];
            for(int j=0; j< 13; j++){
                Rank r = Rank.values()[j];
                PlayingCard card = new PlayingCard(r, s);
                deck[counter] = card;
                counter++;
            }
        }
        knuthShuffle(deck);
        Iterator<PlayingCard> itr = new Iterator<PlayingCard>() {
			int currentPos = 0;
            @Override
            public boolean hasNext(){ return (currentPos < deck.length); }


            @Override
            public PlayingCard next() { return deck[currentPos++]; }

			@Override
			public void remove() {

			}

		};
    return itr;
	}

	/***
	 * asssumptions for natural ordering:
	 *   Rank:  Two < Three < ..Ten < Jack < Queen < King < Ace
	 *   Suit: Clubs < Diamonds < Hearts < Spades
	 */
	@Override
	public int compareTo(PlayingCard o) {
		if (this.rank().compareTo(o.rank()) < 0) {
			return -1;
		} else if (this.rank().compareTo(o.rank()) > 0) {
			return 1;
		} else {
			if (this.suit().compareTo(o.suit()) < 0) {
				return -1;
			} else if (this.suit().compareTo(o.suit()) > 0) {
				return 1;
			} else {
				return 0;
			}
		}
	}

}
