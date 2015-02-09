Type "make", "make parselist" or "make all" to compile.

Takes input from stdin and separates tokens using whitespace and newlines.
One limitation is that the scanner will only accept max sized tokens of 1024 characters (this can be easily changed if needed)

Basic input works but there are some bugs with more advanced input (mainly using multiple ITEM or STMT)

- Patrick Bryan