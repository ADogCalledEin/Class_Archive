## Red and Black Trees

Basically like taking a 2-3 Tree and applying constraints on it to make it act like a Binary Search Tree.

Example of how to introduce color into the tree:
```
Node {
  K
  V
  boolean isRed;
}
```

When we have a 3 node, we want to convert it so that the min value of the 3 node is red.

If one path to a leaf node has three black links and another has two, you've violated the red black property.

#### Three Key Properties that Define Red-Black Trees
1. All red links hang left
-  No node has two red links connected
- Perfect black link balance (every path from a root to a link node has the same number of black links, red links don't matter as long as the second property is followed)

#### Operations for Red-Black Trees

###### _Left Rotation_
Situation: A right leaning link had become red

Assumption: Operation has received as input a node w/ a right leaning link as red.

Right rotation is normally in combination with Color Flipping

###### _Color Flipping_
Assumption: Assume a black node with two RED child nodes

1. Make the children black
2. Flip the node to red

Liek dis:
```
Node {
  Node left;
  Node right;
  boolean isRed;
}

flip(Node me){
  me.isRed = true;
  me.left.isRed = false;
  me.right.isRed = false;
}

```
Color flipping is analogous to splitting and promoting in 2-3 Trees

**Insertions**

- In 2-3 trees, we grow the height of tree from the root up.
- Insertions ALWAYS create RED links. This is where we color flip. But the root cannot be red. So that is also flipped.
- If links added are red and on the right, a rotation needs to happen.

Base case: Same as binary search tree, but new links are created as red.

1. If right child is red, and left is black we do a left rotation.
2. If both the left child and the left child of the left child are red, rotate right, then color flip where necessary.
3. If both children are red: Color flip.

*(Various insertion examples are in notebook)*

- We will always color flip when inserting into a 3 node (because that creates a 4 node, which we then split and promote from).

**Other Shit about Red-Black Trees**

- The height (upper bound) is always equal to 2(log(N)) where N is the number of Nodes of a 2-3 Tree.
- Average case performance in real life is around 2(log(N)) - C where c < 1.
