package notes;

public class Cat extends Animal {

	private int _meows;
	
	public Cat(String nm) {
		super(nm);
	}
	
	public void meow() { _meows++; }
	
	public int meows() { return _meows; }

	@Override
	public boolean equals(Object obj) {
		if (this == obj) return true;
		if (obj == null) return false;
		if (obj instanceof Cat) {
			Cat that = (Cat)obj;
			return (this._meows == that._meows && super.equals(that));
		}
		return false;
	}
	
	
	
	
}
