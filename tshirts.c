#include <stdio.h>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    //Additional test cases
    assert(size(-2) == 'S');
    assert(size(37,56) == 'S');
    assert(size(40,58) == 'M');
    assert(size(43,61) == 'L');
    assert(size(243,261) == 'L');
    
    printf("All is well (maybe!)\n");
    return 0;
}
