# 0x19.C - Stacks, Queues - LIFO, FIFO

## Monty 0.98 Interpreter

The objective of this project was to build a Monty 0.98 scripting language interpreter to handle various commands to manipulate stacks and queues.

## Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 14.04 LTS
- All your files should end with a new line
- You allowed to use a maximum of one global variable
- No more than 5 functions per file
- You are allowed to use the C standard library
- A `README.md` file, at the root of the folder of the project, is mandatory
- The prototypes of all your functions should be included in your header file called monty.h
- All your header files should be include guarded

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

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
```

## Opcode Commands

The commands coded into the interpretor are as follows:

- push [Usage: push #] - pushes # onto the stack. # is an integer value

- pall - prints the stack contents starting from the top

- pint - prints the first element on the top of the stack

- pop - deletes the top element of the stack

- swap - swaps the first two elements of the stack

- add - adds the first two elements of the stack

- nop - does not do anything to the stack
