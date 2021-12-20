# c_pattern_matching
C implementation of two pattern matching algorithms - finite state machine and Knuth-Morris-Pratt

Compilation: ```make```. Usage: for both programs you need to run ```./dfa [<input_file>]``` or ```./kmp [<input_file>]``` for finite state and Knuth-Morris-Pratt algorithm respectively. If you specify an input file, the source text will be read from it, but you need to enter the pattern in the command line. You can also run without an input file, entering the pattern in one line and then the source text in the next line, however with a file you can pass a multiline input, while in the command line the \n character will be considered as the end of input. Both programs support UTF-8 input. Functions handling UTF-8 characters are based on the ```read()``` function from glibc. Programs print (to stdout) position of pattern's first letter for each occurence of pattern in the source text. Character numeration in the text starts with 0.

In ```data``` directory there is a sample input file in UTF-8 (Greek). For a pattern ```αβα``` the result is ```10 12 22 26```.
