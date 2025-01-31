# Calcule de complexité en nombre de mouvement.

## adaptation des differents algorithmes de tri au contraintes de l'exercice.

## Stacks

* stack_1
    char    stack_1.name
    int *   stack_1.arr[n]
    int     stack_1.len

* stack_2
    stack_2.name
    stack_2.arr[n]
    stack_2.len


## Mouvement:

* rotate                -->                     coût:   1;

* reverse rotate        <--                     coût:   1;

* rrr               <-- stacke_1                coût:   1;
                    <-- stacke_2

* rr                --> stacke_1                coût:   1;
                    --> stacke_2

* swap      stack.arr[0] <-> stack.arr[1]       coût:   1;

* Push      stack_x.arr[0] ^  stack_y.arr[0]    coût:   1;            



int arr = 9 19 223 8 409 22211 29 887 87 1


# buble sort exemple: