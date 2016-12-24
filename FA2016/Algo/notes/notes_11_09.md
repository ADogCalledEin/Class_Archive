#### More Red-Black Trees to start off

- These trees are always 2log(N) performance.
- RB and Binary Trees are very easily queried, and an example of a well implemented symbol table.

## Hashing Algorithms

- The goal of a hashing algorithm is to map some key to some position in the array.

**For Reference when talking about Hashing**
- N: # of keys
- M: # of Slots
- array: M = length of array

#### Key Ideas
1. hash function f(key) = array position (where 0 <= m < M)
2. Collision resolution (key collision is when two keys hash to the same position in array)
3. Performance goals/constraints

Garbage Hashing function example
```
public int hashCode(){
  return 17;
}

```
- Above runs in constant time all the time, but has a 100% key collision rate.

#### Hashing Positive Integers

##### *Modular Hashing*
- Assume array of size M
- Assume M to be prime
- f(key) = key%M

- 32 Bit systems have a word size of 4
- Word Size: # of bits used to represent data
- 1 byte = 8 bits (bit is a single binary digit)
- w = wordsize in bits
- V = [V<sub>w-1</sub>, V<sub>w-2</sub>, ... ,V<sub>1</sub>, V<sub>0</sub>]

**Two's Complement Signed Integers**

Bto2C(v) = V<sub>w-1</sub> x 2<sup>w-1</sup> + (sum from 0 to w-2 of 2<sup>i</sup> * V<sup>i</sup>)
