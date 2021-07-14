# Push_Swap

Ce dépôt contiens ma solution au projet `Push_swap` de 42 (Paris).

This Repositorie contains my solution to the project `Push_swap` of 42 (Paris).

[![jaeskim's 42 stats](https://badge42.herokuapp.com/api/stats/cmaginot?cursus=42cursus&privacyName=true)](https://github.com/JaeSeoKim/badge42)

[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/cmaginot/push_swap)](https://github.com/JaeSeoKim/badge42)

## Exemple of Uses

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

## Avancement / Advancement

- [x] parsing atguments (from n int or one string)
- [x] error management (is not a int, same number twice, over int max or under int min)
- [x] checking if already sorted
- [x] tools (push, swap, rotate, reverse rotate)
- [x] sorting algo (under five and radix_sort)
- [ ] better algo for big 100 number (less than 700 operation) (current = 1084 - 3/5)
- [ ] better algo for big 500 number (less than 5500 operation) (current = 6784 - 4/5)
- [ ] bonus (checker)
- [x] leaks
- [x] norm

## Tester :

- [ ] push_swap_tester(https://github.com/lmalki-h/push_swap_tester) by lmalki-h(https://github.com/lmalki-h)
- [ ] push_swap_tester(https://github.com/LeoFu9487/push_swap_tester.git) by LeoFu9487(https://github.com/LeoFu9487)

## Visualizer :

push_swap_visualizer(https://github.com/o-reo/push_swap_visualizer.git)
