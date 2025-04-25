# Red-Black Tree

## Overview
This project is a learning exercise to understand and implement Red-Black Trees, a type of self-balancing binary search tree. The primary focus is on implementing the following core functions:

- `rb_tree_node` - Creates a new node for the Red-Black Tree.
- `rb_tree_valid` - Checks if a given node satisfies the black property of the Red-Black Tree.
- `rb_tree_insert` - Inserts a new value into the tree while maintaining Red-Black Tree properties.

## Features
- Efficient insertion with automatic balancing.
- Verification of Red-Black properties.
- Structured node creation with proper color assignment.

## Red-Black Tree Properties
A Red-Black Tree maintains the following properties:
1. Each node is either red or black.
2. The root is always black.
3. Red nodes cannot have red children (no two consecutive red nodes).
4. Every path from a node to its descendant NULL pointers must contain the same number of black nodes.

## Learning Goals
- Understanding the role of rotations in balancing.
- Ensuring color flips maintain tree integrity.
- Applying tree traversal techniques for validation.

## Future Enhancements
- Implement delete operation.
- Improve visualization of the tree structure.
- Extend with additional balancing checks.
