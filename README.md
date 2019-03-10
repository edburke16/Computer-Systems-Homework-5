HW05 - Shell Commands Tokens
Shell commands come in several forms:

Commands without arguments:

  $ pwd
Commands with arguments:

  $ sort tests/sample.txt
Operators with single commands:

  $ sort < foo.txt
Operators joining multiple commands

  $ grep derp foo.txt | wc -l
Seven operators:

Redirect input: sort < foo.txt
Redirect output: sort foo.txt > output.txt
Pipe: sort foo.txt | uniq
Background: sleep 10 &
And: true && echo one
Or: true || echo one
Semicolon: echo one; echo two
In this assignment, you will write a program that reads single line shell commands, splits them into a sequence of tokens, reverses the sequence, and prints out one token per line.

Note: You must store the sequence of of tokens in a data structure in memory and then reverse it (either in place or to a new sequence) before printing it.

There are three kinds of tokens:

Command names.
Command arguments.
Shell operators.
Spaces that appear in a command are not tokens, although they may separate tokens.

Example interaction:

bash$ ./tokens
tokens$ echo one; echo two
two
echo
;
one
echo
tokens$ sort foo.txt | uniq
uniq
|
foo.txt
sort
tokens$ ^D
bash$
(Note: In the above interaction "^D" means the user has pressed Ctrl+D to send the End-of-File event to the terminal.)

Note: The C starter code from the previous assignment can be used in this assignment.
