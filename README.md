# C - Stacks, Queues - LIFO, FIFO
## Monty 0.98 Interpreter

The objective of this project was to build a Monty 0.98 scripting language interpreter to handle various commands to manipulate stacks and queues.

## Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```
       
## Opcode Commands

The commands coded into the interpretor are as follows:

* push [Usage: push #] - pushes # onto the stack. # is an integer value

* pall - prints the stack contents starting from the top

* pint - prints the first element on the top of the stack

* pop - deletes the top element of the stack

* swap - swaps the first two elements of the stack

* add - adds the first two elements of the stack

* nop - does not do anything to the stack



## Author:
- Juan Granada <1958@holbertonschool.com>

2020 - All programs written by Juan Granada ([@juangraram](https://twitter.com/JuanGraRam)) at [Holberton School](https://www.holbertonschool.com/)