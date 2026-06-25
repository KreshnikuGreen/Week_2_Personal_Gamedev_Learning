#include "soldier.h"

int occupation_for_rank(int rank){
    if(rank == 1){
        return 1;
    } else if(rank == 2){
        return random_int(2, 5);
    } else {
        return 6;
    }
}
