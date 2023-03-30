# Miscellaneous Contents

## 1) Bracket Balancing 
Here, we are trying to implement a code to test brackets indentation
This code not only inform the user that there is an error in the usage of brackets, but also point to the exact place in the code with the problematic bracket. 
First priority is to find the first unmatched closing bracket which either doesn’t have an opening bracket before it,
like ] in ](), or closes the wrong opening bracket, like } in ()[}. If there are no such mistakes, then
it should find the first unmatched opening bracket without the corresponding closing bracket after it,
like ( in {}([]. If there are no mistakes, text editor should inform the user that the usage of brackets
is correct.
Apart from the brackets, code can contain big and small latin letters, digits and punctuation marks.
