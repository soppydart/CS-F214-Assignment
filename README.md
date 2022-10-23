# CS-F214-Assignment
This was made for an assignment to to check the proof of natural deduction in Propositional Logic.

## Requirements 
* GCC
* GNU Make

## Instructions to run
* Download and extract the repo to `<some-directory>`
* Run (for the first time) with :
```console
make
```
* For subsequent runs, use :
```console
./exec
```
### If running without GNU Make
Run the following in `<some-directory>`:
```console
gcc -c main.c -o main.o
gcc -c Task1/infixToPrefix.c -o infixToPrefix.o
gcc -c Miscellaneous/draw.c -o draw.o
gcc -c Task2/parser.c -o parser.o
gcc -c Task3/prefin.c -o prefin.o
gcc -c Task4/height.c -o height.o
gcc -c Task5/judge.c -o judge.o
gcc -c Miscellaneous/freee.c -o freee.o
gcc -o exec main.o infixToPrefix.o draw.o parser.o prefin.o height.o judge.o freee.o -lm
./exec
```

## Documentation and Profiling
Refer to [Documentation](https://github.com/soppydart/CS-F214-Assignment/tree/main/Documentation) .

## Examples
![Making and running the code](https://drive.google.com/uc?export=view&id=1Ig7aoH6XK57R9XFdXjKxYH3Vm8q_28Kq)
![Some more running](https://drive.google.com/uc?export=view&id=1IMIDkouT61ltYLRxEQpLwGerRCfd4jvU)
![And more running](https://drive.google.com/uc?export=view&id=1rCBqtazFwka0saDpg__SiWm8i7_UlH3G)
