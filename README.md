# Push_swap

This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

## Project

You need to write 2 programs in C:
- <em>checker</em> which takes integer arguments and reads instructions on the standard output. Once read, <em>checker</em> executes them and displays "OK" if the integers are sorted. Otherwise, it will displays "KO".
- <em>push_swap</em> which calculates and displays on the standard output the smallest combination of instructions to sort the integer arguments.

You can use the following instuctions:
- swap a (sa), swap the first 2 elements at the top of <em>stack a</em>, if there aren't 2 elements do nothing.
- swap b (sb), swap the first 2 elements at the top of <em>stack b</em>, if there aren't 2 elements do nothing.
- ss, swap a and swap b at the same time.

- push a (pa), take the the first element at the top of <em>b</em> and put it at the top of <em>a</em>, do nothing if <em>b</em> is empty.
- push b (pb), take the the first element at the top of <em>a</em> and put it at the top of <em>b</em>, do nothing if <em>a</em> is empty.

- rotate a (ra), shift up all elements of <em>stack a</em> by 1, the first becomes the last one.
- rotate b (rb), shift up all elements of <em>stack b</em> by 1, the first becomes the last one.
- rr, rotate a and rotate b at the same time.

- reverse rotate a (rra), shift down all elements of <em>stack a</em> by 1, the last becomes the first one.
- reverse rotate b (rrb), shift down all elements of <em>stack b</em> by 1, the last becomes the first one.
- rrr, reverse rotate a and reverse rotate b at the same time.

## Checker

<em>Checker</em> will get as an argument the <em>stack a</em> formatted as a list of integers. The first argument should be at the top of the stack.
<br/>If no argument is given, <em>checker</em> stops and displays nothing.

<em>Checker</em> will wait and read the instructions on the standard input, each instruction will be followed by a newline.
<br/>Once all instruction have been read, <em>checker</em> will execute them on the stack received as an argument.

If after executing those instructions, <em>stack a</em> is sorted and <em>b</em> is empty, then <em>checker</em> displays "OK" followed by a newline on the standard output.
<br/>Else <em>checker</em> displays "KO" follwed by a newline on the standard output.

In case of an error, <em>checker</em> displays "Error" followed by a newline on the standard error.

Example
```bash
$ ./checker 0 3 2 4
pb
sa
pa
OK
```

## Push_swap

<em>Push_swap</em> will receive as an argument the <em>stack a</em> formatted as a list of integers. The first argument should be at the top of the stack.

<em>Push_swap</em> must display the smallest list of instruction possible to sort <em>stack a</em>, in a way that the smallest number is at the top.
<br/>The instructions must be seperated by a newline.

In case of error, <em>push_swap</em> displats "Error" followed by a newline on the standard error.

Example
```bash
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```

## Allowed functions

write
<br/>read
<br/>malloc
<br/>free
<br/>exit

## Usage

With <em>checker</em> we can check if the given instructions by <em>push_swap</em>, are actually sorting the stack properly.
```bash
$ ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
       6
$ ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
OK
```

If <em>checker</em> displays "KO", it means that <em>push_swap</em> came with a list of instructions that don't sort the list.
