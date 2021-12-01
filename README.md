# Monty
WeatherBoyGPR, Gino P.R
This is a repository which holds the source files for a monty byte code processor

Compilation is as follows:
$ gcc -Wall -Werror -Wextra -pedantic -std=c90 *.c -o monty

The structure of this program may be summarized as follows:
The main function obtains lines from input.
Then these lines are fed to the M_core, or monty core
These lines have the first two non-whitespace stretch of characters cut out from them.
The first token will be matched against a list of valid opcodes.
If a match is found, the second token will be fed into the function reponsible for the opcode.
The opcode will then be performed by the function, allocating and deallocating memory as needed.

Commands may be commented out with the hash symbol '#' at the front of the line

A list of commands is as follows:
push -
takes an integer argument and will push the value onto the top of the stack, or back of queue

stack -
will set mode to stack which operates on LIFO, default mode

queue -
will set mode to queue which operates on FIFO, non-default mode

pop -
will remove node from top of stack/front of queue

pall -
will print every node within stack/queue

pint -
will print the integer at the top of stack / front of queue

pchar -
will print the integer at the top of stack / front of queue as an ASCII character

pstr -
will print the first sequence of valid char integers starting from the front / top of queue / stack

swqp -
will swap the top two / front two values in the stack / queue

rotr -
will rotate stack / queue to top / front

rotl -
will rotate stack / queue to bottom / back

add -
will add the top two / front two values in the stack /queue
stores the result in the second to top/front, removing the top/front node

sub -
will sub the top two / front two values in the stack /queue
stores the result in the second to top/front, removing the top/front node

div -
will div the top two / front two values in the stack /queue
stores the result in the second to top/front, removing the top/front node

mod -
will mod the top two / front two values in the stack /queue
stores the result in the second to top/front, removing the top/front node
