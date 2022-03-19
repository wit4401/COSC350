# Project #2: Compressing and Uncompressing Files
## Objective
In this project you are going to implement a compression program and an uncompression
program to build a useful compression utility. These are separate programs, but they share many
functions, which should be built as shared library. The program that reads a regular file and
produces a compressed file is called the compression or huffing program. The program that does
the reverse, producing a regular file from a compressed file is called the uncompression or
unhuffing program.
## Requirements
* The huffing program should be able to perform the following operations:
  * Read the characters in a text file and count the frequency of each character and store the character and its frequency in a data structure.
  * Use Huffman coding algorithm to create a binary tree for Huffman coding. Your binary tree for Huffman coding should provide the following functionalities:
    * Traverse the tree and record every root-to-leaf path. The edges taken for each root-to-leaf path determine the coding of the character stored in the leaf node.
    *  Perform a pre-order traversal to write the tree, and read it back. This is needed if the tree is stored in the header of a compressed file.
    *  Perform a post-order traversal to delete all tree nodes when the tree is no longer needed.
  * Read the text file and produce a compressed file of the original text file. You also need to include the coding tree information at the beginning of the output file.
* The unhuffing program should be able to perform the following operations:
  * Read the compressed text and the binary Huffman coding in the binary tree from the compressed file.
  * Reconstruct the binary Huffman coding tree from the information read from the file.
  * Use Huffman coding binary tree to create the original text file from the compressed original file.
## Overall Performance
