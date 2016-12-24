# Reading Notes

## Chapter 2.1

Our primary concern when it comes to algorithms, is to rearrange arrays of items where each item contains a key. The idea behind rearranging the keys is to do to is a manner so that the keys are naturally ordered.

We put our sort code in a sort() method within a single class along with private helper functions `less()` and `exch()`. `less()` checks whether a number is less than the one it is being compared to and `exch()` will swap two values in an array.

The comparable interface makes implementing `less()` very straightforward

**Certification**

Does sort implementation always pit the array in order, no matter what the initial order? As a conservative practice, we include the statement `assert isSorted(a);` in our test client to certify that array entries are in order after the sort. It is reasonable to include this statement in every sort implementation, even though we normally test our code and develop mathematical arguments that our algorithms are correct.

**Extra Memory** The amount of extra memory used by a sorting algorithm is often as important a factor as running time. The sorting algorithms divide into two basic types: those that sort in place and use no extra memory except perhaps for a small function-call stack to a constant number of instance variables, an those that need enough extra memory to hold another copy of the array to be sorted.

**Types of Data**

Our sort code is effective for ant item type that implements the `Comparable` interface. Adhering to Java's convention in this way is convenient because many of the types of data that you might want to sort implement `Comparable`. For example, Java's numeric wrapper types such as Integer and Double implement Comparable, as do String and even more complex variable types such as FILE and URL. Listed below is an example of the `compareTo` method.

```
public int compareTo(Date that){
	if(this.year > that.year) return +1;
	if(this.year < that.year) return -1;
	if(this.month > that.month) return +1;
	if(this.month < that.month) return -1;
	if(this.day > that.day) return +1;
	if(this.day < that.day) return -1;
}
```

Java's convention is that the call `v.compareTo(w)` returns a integer that is negative, zero, or positive when v < w, v = w, or v > w, respectively. By convention, code `v.compareTo(w)` throws an exception if v and w are incompatible types or either is null. Furthermore `compareTo()` must implement a total order. it must be
	1. Reflexive (for all v, v = v)
	2. Antisymmetric (for all v and w, if v < w then w > v and if v=w then w=v)
	3. Transitive (for all v, w, and x, if v <= w and w <= x then v <= x)
These rules are intuitive and standard in mathematics.

## **Selection Sort**

one of the simplest sorting algorithms is as follows, find the smallest element in the array and exchange it for the first value in the array. Then find the next smallest element and exchange it for the second value in the array. Continue this until the entire array is sorted. This method of sorting is called selection sort and is one of the most trivial sorting algorithms out there. Below is an example of selection sort

```
public class Selection{
	public static void sort(Comparable[] a){ // sort a into increasing order
		int N = a.length;
		for(int i = 0; i < N; i++){ // Exchange a[i] with smallest entry in a[i+1...N).
			int min = i; // index of a minimal entry
			for(int j = i+1; j < N; j++){
				if(Less(a[j], a[min])) min = j;
			exch(a, i, min);
			}
		}
	}
}
```
The work of moving the items around falls outside the inner loop: each exchange puts an item into its final position so the number of exchanges in N. Thus, the running time is dominated by the number of compares.

**Proposition A**
Selection sort uses N<sup>2</sup>/2 compares and N exchanges to sort an array of length N.

You can prove this with by examining the trace table and noticing that the table in N by N in which unshaded letters correspond to compares.

```
i   min   0   1   2   3   4   5   6   7   8   9   10
          S   O   R   T   E   X   A   M   P   L   E
0   6			S   O   R   T   E   X   A   M   P   L   E
1   4     A   O   R   T   E   X   S   M   P   L   E
2   10    A   E   R   T   O   X   S   M   P   L   E
3   9     A   E   E   T   O   X   S   M   P   L   R
4   7     A   E   E   L   O   X   S   M   P   T   R
5   7     A   E   E   L   M   X   S   O   P   T   R
6   8     A   E   E   L   M   O   S   X   P   T   R
7   10    A   E   E   L   M   O   P   X   S   T   R
8   8     A   E   E   L   M   O   P   R   S   T   X
9   9     A   E   E   L   M   O   P   R   S   T   X
10  10    A   E   E   L   M   O   P   R   S   T   X
```

In summary selection sort is a simple sorting method that is easy to understand and to implement and is characterized by the following two signature properties.

**Running time is insensitive to input**
The process of finding the smallest item on one pass through the array does not give much information about where the smallest item might be on the next pass .This property can be disadvantageous in some situations. For example, the person using the sort client might be surprised to realize that it takes about as long to run selection sort for an array that is already in sorted order or for an array with all keys equal to as it does for a randomly ordered array.

**Data movement is minimal**

Each of the N exchanges changes the value of two array entries, so selection sort uses N exchanges. the number of exchanges is a linear function of the array size. None of the other sorting algorithms that we consider have this property. (most involve linearithmic or quadratic growth)

## **Insertion Sort**

 The algorithm that people often use to sort bridge hands is to consider the cards one at a time, inserting each into its proper place among those already considered. In a computer implementation we need to make space to insert the current item into the vacated position. This method is called insertion sort. Code for this can be seen below.

 ```
public class Insertion{
	public static void sort(comparable[] a){
		int N = a.length;
		for (int i = 0; i < N; i++){
			for(int j = i; j > 0 && less(a[j], a[j-1]); j--){
				exch(a, j, j-1);
			}
		}
	}
}
 ```
For each i from 1 to N-1, exchange a[i] with the entries that are larger in a[0] through a[i-1]. As the index i travels from left to right, the entries to its left are in sorted order in the array, so the array is fully sorted when i reaches the end right.

Unlike selection sort, the running tie of insertion sort depends on the initial order of the items in the input. For example, if the array is large and its entries are already in order ( or nearly in order), then insertion sort is much, much faster that if entries are randomly ordered or in reverse order.

**Proposition B**
Insertion sort uses ~N<sup>2</sup>/4 compares and ~N<sup>2</sup>/4 exchanges to sort a randomly ordered array of length N with distinct keys, on the average. The worst case is ~N<sup>2</sup>/2 compares and ~N<sup>2</sup>/2 exchanges and the best case is N-1 compares and 0 exchanges.

```
i   j   0   1   2   3   4   5   6   7   8   9   10
        S   O   R   T   E   X   A   M   P   L   E
1   0   O   S   R   T   E   X   A   M   P   L   E
2   1   O   R   S   T   E   X   A   M   P   L   E
3   3   O   R   S   T   E   X   A   M   P   L   E
4   0   E   O   R   S   T   X   A   M   P   L   E
5   5   E   O   R   S   T   X   A   M   P   L   E
6   0   A   E   O   R   S   T   X   M   P   L   E
7   2   A   E   M   O   R   S   T   X   P   L   E
8   4   A   E   M   O   P   R   S   T   X   L   E
9   2   A   E   L   M   O   P   R   S   T   X   E
10  2   A   E   E   L   M   O   P   R   S   T   X
        A   E   E   L   M   O   P   R   S   T   X
```

**Proof B:**
 the number of compares and exchanges is easy to visualize in the N by N diagram that we use to illustrate the sort. We count entries below the diagonal -- all of them, in the worst case, and none of them, in the best case. For randomly ordered arrays, we expect each item to go about halfway back on the average, so we count one-half entries below the diagonal. The number of compares is the number of exchanges plus an additional term equal to N minus the number of times the item is inserted is the smallest so far. In the worst case (array is reverse order), this term is negligible in relation to the total; in the best case it is equal to N-1.

Insertion sort works we;; for certain types of nonrandom arrays that often arise in practice, even if they are huge. For example, if you already have a sorted array that you implement insertion sort on, the sort will immediately determine that each element is in its correct place and the total running time is linear. The same is true for an array who's keys are all equal.

## **Shell Sort**

To exhibit the value of knowing properties of elementary sorts, we next consider a fast algorithm based on insertion sort. Insertion sort is slow for large unordered arrays because the only exchange it does involves adjacent entries, so items can move through the array only one place at a time. For example if the time with the smallest key happens to be at the end of the array N-1 exchanges are needed to get that one item where it belongs, shellsort is a simple extension of insertion sort that gains speed by allowing exchanges of array entries that are far apart, to produce partially sorted arrays that can be efficiently sorted, eventually by insertion sort.

The idea is to rearrange the array to give it the property that taking every Hth entry yields a sorted subsequence. Such an array is said to be h-sorted. Put another way, an h-sorted array is h independent sorted subsequences, interleaved together. By h-sorting for some large value of h, we can move items in the array long distances and thus make is easier to h-sort for smaller values of h. Using such a procedure for any sequence of values of h that end in 1 will produce a sorted array: that is shellsort. An example of shellsort can be found below.

```
public class Shell{
	public static void sort(Comparable[] a){
		int N = a.length;
		int h = 1;
		while(h < N/3) h = 3*h + 1;
		while(h >= 1){
			for(int i = h; i < N; h++){
				for(int j = i; j >= h && less(a[j], a[j-h]); j -= h){
					exch(a, j, j-h);
				}
			}
			h = h/3;
		}
	}
}
```

The general convention for using shell sort is using an h sequence of decreasing values 1/2*(3<sup>k</sup>-1), starting at the smallest increment greater than or equal to N/3 and decreasing to 1. we refer to such a sequence as an increment sequence. The example above computes its increment sequence; another alternative is to store an increment sequence in the array.

One way to implement shell sort would be, for each h, to use insertion sort independently on each of the h subsequences. Because the subsequences are independent, we can use an even simpler approach: when h-sorting the array, we insert each item among the previous items in its h-subsequence by exchanging it with those that have larger keys (moving them each one position to the right of the sequence). We accomplish this by implementing insertion- sort code, but modified to decrement by h instead of 1 when moving through the array. This observation reduces the shell sort implementation to an insertion sort like pass through the array for each increment.

Shell sort gains efficiency by making a tradeoff between size and partial order in the subsequences. At the beginning, the subsequences are short; later in the sort the subsequences are partially sorted. In both cases, insertion sort is the method of choice. The extend to which the subsequences are partially sorted is a variable factor that depends strongly on the increment sequence.

As you can learn from comparing insertion sort and selection sort, shell sort is muc faster that insertion sort and selection sort, and its speed advantages increases with the array size. Shell sort makes it possible to address sorting problems that could not be addressed with the more elementary algorithms.

## **Chapter 2.2 Merge Sort**

The algorithms described in this chapter are based on combining two ordered arrays to make one larger ordered array. This operation immediately leads to a simple recursive sort method known as **merge sort**; to sort an array, divide it into two halves, sort the two halves (recursively) and then merge the results. One of the major benefits of merge sort is that it guarantees to sort any array of N elements in time proportional to Nlog(N).

**Abstract in place merge.**

The straightforward approach to implementing merging is to design a method that merges two disjoint ordered arrays of comparable objects into a third array. This strategy is easy to implement: create an output array of the requisite size and then choose successively the smallest remaining item from the two input arrays to e the next item added to the output array.

However when we merge sort a large array, we are doing a huge number of merges, so the cost of creating a new array to gold the output every time that we do a merge is problematic. This is where in place merge comes in to play. The idea behind this is that we sort the first half then sort the next half and merge the two halves. Solutions to this tend to be quite complex especially by comparison to alternatives that use extra space. Below is source code for an implementation of this.

```
private static void merge(Comparable[] a, int lo, int mid, int hi){
	int i = lo, j = mid+1;

	for(int k = lo; k<= hi; k++){
		aux[k] = a[k];
	}
	for (int k = 0; k <= hi; k++){
		if (i > mid) 									 a[k] = aux[j++];
		else if (j > hi) 							 a[k] = aux[i++];
		else if (less(aux[j], aux[i])) a[k] = aux[j++];
		else  												 a[k] = aux[i++];			
	}
}
```

## **Top Down MergeSort**

This algorithm of Top Down merge sort is one of the best examples of a divide and conquer paradigm for efficient algorithm design.

To understand merge sort, it is worthwhile to consider carefully the dynamics of the method calls. The idea behind this is recursively call the sort method to sort smaller and smaller subsets of the array then once the two are successfully sorted for their respective halves, there is one major sort that will sort the two halves together. The benefit of this is that when you call merge the more computationally difficult two halves, then those halves are already sorted so the process becomes a lot easier for a computer to handle. Top-down merge sort uses between ~1/2Nlog(N) and Nlog(N) compares to sort any array of length N.

We can improve most recursive algorithms by handling small cases differently, because the recursion guarantees that the method will be used often for small cases, so improvements in handling them lead to improvements in the whole algorithm. In the case of sorting, we know that insertion sort or selection sort is simple and therefore likely to be faster than merge sort for tiny subarrays. Another improvemnet we coudl make is to add a test to call the skip to `merge()` if a[mid] is less than or equal to a[mid+1. With this change we still do the recursive calls but the running time for sorted arrays in linear.

# **Chapter 2.1 Quick sort**

One of the must popular sorting algorithms out there is known as quick sort. Quick sort is popular among the community because it is not difficult to implement, works well for a variety of different kinds of input data, and is substantially faster than any other sorting method in typical applications. The quick sort algorithm's desirable features are that it is in-place and that it requires time proportional to N*log(N) on the average to sort an array of length N. None of those algorithms that we have covered so far share these two properties. Also quick sort has a shorter inner loop than most other sorting algorithms, which means that it is faster in practice and theory.

One of the few downsides of quick sort is that it is fragile in the sense that some care is involved in the implementation to be sure to avoid bad performance. Numerous mistakes in taking care of how to handle quick sort can quickly lead to it being quadratic.

Quick sort is a divide and conquer method for sorting. It works by partitioning an array into sub-arrays, then sorting the subarrays independently. Quick sort is complementary to merge sort, expect for quick sort we arrange it so that when we partition the two halves and put them back together the entire array is sorted. Below is example code for quick sort.

```
public class Quick{
	public static void sort(comparable[] a){
		StdRandom.shuffle(a);
		sort(a, 0, a.length -1);
	}

	private static void sort(Comparable[] a, int lo, int hi){
		if (hi <= lo) return;
		int j = partition(a, lo, hi);
		sort(a, lo, j-1);
		sort(a, j+1, hi);
	}
}
```

In the first instance we do the two recursive calls before working on the whole array; in the second instance, we do the two recursive calls after working on the whole array. For quicksort the position of the partition depends on the contents of the array.

The crux of the method is the partitioning process, which rearranges the array to make the following three conditions hold:
	1. The entry a[j] is in its final place in the array, for some j
	2. No entry in a[lo] through a[j-1] is greater than a[j]
	3. no entry in a[j+1] through a[hi] is less than a[j]
We achieve a complete sort by partitioning, the recursively applying this method. Because the partitioning process always fixes one item into its position, it is relatively easy to produce a proof by induction.

## **Partitioning in place**
If we use an extra array, partitioning is easy to implement, but not so much easier that it is worth the extra cost of copying the partitioned version back into the original.

## **Staying in bounds**
If the smallest item or the largest item in the array is the partitioning item, we have to take care that the pointers do not run off the left or right ends of the array. Our Partition() implementation has explicit tests to guard against this circumstance. the test (j == lo) is redundant, since the partitioning item is at a[lo] and not less that itself.

## **Preserving randomness**
The random shuffle puts the array in a random order. Since it treats all items i the subarrays uniformly. This fact is crucial to the predictability of the algorithm's running time. An alternate way to preserve randomness is to choose a random item for partitioning within partition.

# Helpful hints for the midterm

Well, in Java an int is a primitive while an Integer is an Object. Meaning, if you made a new Integer:

`Integer i = new Integer(6);`
You could call some method on i:

`String s = i.toString();//sets s the string representation of i`
Whereas with an int:

`int i = 6;`
You cannot call any methods on it, because it is simply a primitive. So:

`String s = i.toString();//will not work!!!`

---
markdown-pdf AlgorithmNotes.md

---

## **Various Big-O Notations**

| Algorithm      | Time Complexity |                 |                | Space Complexity |
|----------------|-----------------|-----------------|----------------|------------------|
|                | Best            | Average         | Worst          | Worst            |
| Quicksort      | Ω(n log(n))     | Θ(n log(n))     | O(n^2)         | O(log(n))        |
| Mergesort      | Ω(n log(n))     | Θ(n log(n))     | O(n log(n))    | O(n)             |
| Timsort        | Ω(n)            | Θ(n log(n))     | O(n log(n))    | O(n)             |
| Heapsort       | Ω(n log(n))     | Θ(n log(n))     | O(n log(n))    | O(1)             |
| Bubble Sort    | Ω(n)            | Θ(n^2)          | O(n^2)         | O(1)             |
| Insertion Sort | Ω(n)            | Θ(n^2)          | O(n^2)         | O(1)             |
| Selection Sort | Ω(n^2)          | Θ(n^2)          | O(n^2)         | O(1)             |
| Tree Sort      | Ω(n log(n))     | Θ(n log(n))     | O(n^2)         | O(n)             |
| Shell Sort     | Ω(n log(n))     | Θ(n(log(n))^2)  | O(n(log(n))^2) | O(1)             |
| Bucket Sort    | Ω(n+k)          | Θ(n+k)          | O(n^2)         | O(n)             |
| Radix Sort     | Ω(nk)           | Θ(nk)           | O(nk)          | O(n+k)           |
| Counting Sort  | Ω(n+k)          | Θ(n+k)          | O(n+k)         | O(k)             |
| Cubesort       | Ω(n)            | Θ(n log(n))     | O(n log(n))    | O(n)             |


---

## **Static Method**

Static methods are called `functions` in many programming languages. The modifier static distinguishes these methods from instance methods which must be called on a object so a.sort();
---

## **Abstract Data Types**

To specify the behavior of an abstract data type, we use an API, which is a list of constructors and instance methods, with an informal description of the effect of each, as in the API for counter

```
public class counter

				Counter(String id) // create a counter named id
void 		increment() 			 // increment the counter by one
int 		tally() 					 // number of increments since creation
String	toString()				 // string representation
```

### **Inhereted methods**

All objects in java must inherit a toString() method. If we use the general toString that it inherits we would get a string with the memory representation so generally the user would override the method and implement their own. Other examples of methods that are generally overided are equals(), compareTo(), hashCode().

### **Objects**

Naturally, you can declare that a variables heads is to be associated with data of type Counter with the code `Counter heads;`. An object is an entitty that can take on a data-type value. Objects are characterized by three essential properties: state, identity, behavior. The state of an object is a value from a data type. The identity od an object distinguishes one object from another. It is useful to think of an objects identity as a place where it is stored in memory. The behavior of an object is the effect of data-type operations.

### **Creating Objects**

Each data-type value is stored in an object. To create an individual object, we invoke a constructor by using the keyword new, followed by the class name, followed by () (or a list or args). A constructor has no return type because it always returns a reference to an object of its data type. Each time that a client uses new(), the system
	1. Allocates memory space for the object
	2. invokes the constructor to initialize its value
	3. REturns a reference to the object

In client code we typically create objects in an initializing declaration that associates a variable with an object, as we often do with variables of primitive types. Unlike primitive types, variables are associated with references to objects, not the data-type values themselves.

---

## **Equality of Objects**

IF we test objects with (a == b) where a and b are reference variables of the same type we are testing whether they have the same identity: whether the references are equal. An example of using the .equals instance method, if x and y are string values, then x.equals(y) is true if and only if x and y have the same length and are identical in each character position. Java's convention is that equals() must be an equivalence relation. It must be
	1. Refelxive, x.equals(y) is true
	2. Symmetric, x.equals(y) is true and y.equals(x) is true
	3. Transitive, if x.equals(y) and y.equals(z) are true then x.equals(z) is true

```
public boolean equals(Object x){
	if (this == x) return true;
	if (x == null) return false;
	if (this.getClass() != this.getClass()) return false;
	Date that = (Date) x;
	if (this.day != that.day) return false;
	if (this.month != that.month) return false;
	if (this.year != this.year) return false;
	return true;
}
```

---

## **Immutability**

An immutable data type such as date has a property that the value of an object never changes once constructed. By contrast a mutable data type such as a Counter or accumulator manipulates object values that are intended to change. Java supports this feature with the final modifier. When you declare a variable to be final, you are promising to assign it a value only once.

---

## **Generics**

Java Generic methods and generic classes enable programmers to specify, with a single method declaration, a set of related methods, or with a single class declaration, a set of related types, respectively.

Generics also provide compile-time type safety that allows programmers to catch invalid types at compile time.You can write a single generic method declaration that can be called with arguments of different types. Based on the types of the arguments passed to the generic method, the compiler handles each method call appropriately. Following are the rules to define Generic Methods −

	1. All generic method declarations have a type parameter section delimited by angle brackets (< and >) that precedes the method's return type 	( < E > in the next example).

	2. Each type parameter section contains one or more type parameters separated by commas. A type parameter, also known as a type variable, is an identifier that specifies a generic type name.

	3. The type parameters can be used to declare the return type and act as placeholders for the types of the arguments passed to the generic method, which are known as actual type arguments.

	4. A generic method's body is declared like that of any other method. Note that type parameters can represent only reference types, not primitive types (like int, double and char).

```
public class GenericMethodTest {
   // generic method printArray
   public static < E > void printArray( E[] inputArray ) {
      // Display array elements
      for(E element : inputArray) {
         System.out.printf("%s ", element);
      }
      System.out.println();
   }

   public static void main(String args[]) {
      // Create arrays of Integer, Double and Character
      Integer[] intArray = { 1, 2, 3, 4, 5 };
      Double[] doubleArray = { 1.1, 2.2, 3.3, 4.4 };
      Character[] charArray = { 'H', 'E', 'L', 'L', 'O' };

      System.out.println("Array integerArray contains:");
      printArray(intArray);   // pass an Integer array

      System.out.println("\nArray doubleArray contains:");
      printArray(doubleArray);   // pass a Double array

      System.out.println("\nArray characterArray contains:");
      printArray(charArray);   // pass a Character array
   }
}
```

---

## **Type Erasure**

Type erasure applies to the use of generics. There's definitely metadata in the class file to say whether or not a method/type is generic, and what the constraints are etc. But when generics are used, they're converted into compile-time checks and execution-time casts. So this code:

List<String> list = new ArrayList<String>();
list.add("Hi");
String x = list.get(0);
is compiled into

List list = new ArrayList();
list.add("Hi");
String x = (String) list.get(0);

---

## **Intefaces**

### Comparable Intefaces

```
		public class Animal implements Comparable<Animal>{
    public String name;
    public int year_discovered;
    public String population;

    public Animal(String name, int year_discovered, String population){
        this.name = name;
        this.year_discovered = year_discovered;
        this.population = population;
    }

    public String toString(){
     String s = "Animal name: "+ name+"\nYear Discovered: "+year_discovered+"\nPopulation: "+population;
     return s;
    }

    @Override
    public int compareTo( final Animal o) {
        return Integer.compare(this.year_discovered, o.year_discovered);
    }
}
```

### Iterator Interfaces

```
private class ListIterator implements Iterator<V> {
    private Node next;
    private boolean alreadyDeleted = false;

    ListIterator(Node node){
        this.next = node;
    }

    @Override
    public boolean hasNext() {
        // because next is the current element. We need to iterate over all the elements
        // from the collection.
        return next != null;
    }

    @Override
    public V next() {
        if (next == null) {
           throw new NoSuchElementException();
        }

        Node current = next;

        this.next = current.getNext();
        this.alreadyDeleted = false; // it's better to try to elimate this state variable. You can try to do in another way, if yours removeElement returns something

        return current;
    }

    @Override
    public void remove() {
        if (alreadyDeleted || next == null) {
           throw new IllegalStateException();
        }
        removeElement(next.getReprKey());
        this.alreadyRemoved = true;
    }

}
```

### Iteratable Interfaces

```
public class MyCollection<E> implements Iterable<E>{

    public Iterator<E> iterator() {
        return new MyIterator<E>();
    }
}
```

---

## **Bags, Queues, stacks**

Generics. An essential characteristic of collection ADTs is that we should be able to use them for any type of data. A specific Java mechanism known as generics enables this capability. The notation <Item> after the class name in each of our APIs defines the name Item as a type parameter, a symbolic placeholder for some concrete type to be used by the client. You can read Stack<Item> as "stack of items."

Autoboxing. Type parameters have to be instantiated as reference types, so Java automatically converts between a primitive type and its corresponding wrapper type in assignments, method arguments, and arithmetic/logic expressions. This conversion enables us to use generics with primitive types, as in the following code:

```
Stack<Integer> stack = new Stack<Integer>();
stack.push(17);        // auto-boxing (int -> Integer)
int i = stack.pop();   // auto-unboxing (Integer -> int)
```

Bags. A bag is a collection where removing items is not supported—its purpose is to provide clients with the ability to collect items and then to iterate through the collected items. Stats.java is a bag client that reads a sequence of real numbers from standard input and prints out their mean and standard deviation.

```
public class Bag<Item> implements Iterable<Item>
		 		Bag()							    // create an empty Bag
void 		add(Item item)				// add an item
boolean isEmpty()							// Is the bag empty?
int 		size() 								// number of items in the bag

public class Queue<Item> implements Iterable<Item>
				Queue()								// create an empty Queue
void 		enqueue(Item item)		// add an item
Item		dequeue()             // remove the least recently added item
boolean isEmpty() 						// is the queue emtpy?
int 		size() 								// number of items in the queue

public class Stack<Item> implements Iterable<Item>
				Stack()								// create  a empty Stack
void 		push(Item item) 			// add an item
Item		pop()									// remoce the most recently added item
boolean isEmpty()							// is the stack empty?
int 		size() 								// number o items in the stack
```

---
