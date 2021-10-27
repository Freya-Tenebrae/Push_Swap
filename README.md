# Push_Swap

This Repositorie contains my solution to the project `Push_swap` of 42 (Paris).

[![jaeskim's 42 stats](https://badge42.herokuapp.com/api/stats/cmaginot?cursus=42cursus&privacyName=true)](https://github.com/JaeSeoKim/badge42)

[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/cmaginot/push_swap)](https://github.com/JaeSeoKim/badge42)

## Using push_swap

### Cloning

```shell
git clone --recurse-submodules https://github.com/Freya-Tenebrae/Push_Swap.git
```

### Compilation

for push_swap :
```shell
make push_swap
```
or
```shell
make
```
for checker :
```shell
make bonus
```

for both :
```shell
make push_swap_and_checker
```

### Exemple of uses

#### push_swap

```shell
./push_swap 1 2 3 4 five 6 8 7
Error
```
```shell
./push_swap 1 2 3 4 5 6 8 8
Error
```
```shell
./push_swap 2 3 1 5 4  
ra
ra
pb
ra
ra
pb
rra
sa
pa
pa
```

#### checker

> don't forget to uses ctrl + d to stop input;

```shell
./checker 1 2 3 4 five 6 8 7
Error
```
```shell
./checker 1 2 3 4 5 6 8 8
Error
```
```shell
./checker 2 3 1 5 4  
   ra
Error
```
```shell
./checker 2 3 1 5 4  
rrra
Error
```
```shell
./checker 2 3 1 5 4  
KO
```
```shell
./checker 2 3 1 5 4  
ra
pb
sa
rrr
KO
```
```shell
./checker 2 3 1 5 4  
ra
ra
pb
ra
ra
pb
rra
sa
pa
pa
OK
```
```shell
ARG="1 5 2 4 3";./push_swap $ARG|./checker $ARG
OK
```
## Tester :

- [x] push_swap_tester(https://github.com/lmalki-h/push_swap_tester) by lmalki-h(https://github.com/lmalki-h)
- [x] push_swap_tester(https://github.com/LeoFu9487/push_swap_tester.git) by LeoFu9487(https://github.com/LeoFu9487)

## Visualizer :

push_swap_visualizer(https://github.com/o-reo/push_swap_visualizer.git)
