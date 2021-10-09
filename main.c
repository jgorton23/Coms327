#include "ca.h"

int main(){
    CAPTR p = create1DCA(12,0);
    init1DCA(p,-1);
    display1DCA(p);
    set1DCACell(p,11,0);
    display1DCA(p);
}