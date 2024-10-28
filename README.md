Given 𝑛 pairs of parentheses and 𝑚 pairs of square brackets, write a function to count all combinations
of well-formed sequences.
In the well-formed sequence, each square brackets pair cannot be enclosed within parenthesis pair.
Also, both two sides of a parentheses pair should be simultaneously enclosed or not enclosed in a
square bracket pair. For example, "[()]" and "()[]" are well-formed sequences, while "([])" and "[(])" are
not well-formed sequences.
Input: two integers n and m, representing the number of parenthesis pairs and bracket pairs, where n
< 16 and m < 16.
Output: the number of all combinations of well-formed sequences.
