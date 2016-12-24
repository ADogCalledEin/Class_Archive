## Hashing

Convention: If you override `.equals` you should probably make an implementation in hash.

As such:
```
a.equals(b)

a.hashCode == b.hashCode
```

Example:
```
class Transaction {
  private final String who;
  private final Date when;
  private final Double amount;

  public int hashCode(){
    int hash = 17;
    hash = 31 * hash + who.hashCode();
    hash = 31 * hash + when.hashCode();
    hash = 31 * hash + amount.hashCode();
    return hash;
  }
}

```

If you have objects that have consistent, well-defined implementations, use them (they will have consistent methods).


We want the values of our hashes to be uniformly distributed in the range of possible values. Java's latest implementation of Integer, Long, and Double of hashCode() are interesting for the following reasons. Integer's hashCode function just returns the primitive value. Long and Double takes the high 32 bits and the low 32 bits and takes the XOR of the two and returns that 32 bit as the hashcode.

#### Hash w/ Separate Chaining

1. M array position
2. Choose M to be sufficiently large as to keep the lists short
3. Sequential search over unordered list

## Graph Algorithms
