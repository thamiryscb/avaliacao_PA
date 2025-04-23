#include <iostream>

using namespace std;

int main()
{
    char x[4];
    int y[4];
    float z[4];
    double t[4];

    for(int i=0; i<4; i++){
        printf("%p ", &x[i]);
    }
    printf("\n");

    for(int i=0; i<4; i++){
        printf("%p ", &y[i]);
    }
    printf("\n");

    for(int i=0; i<4; i++){
        printf("%p ", &z[i]);
    }
    printf("\n");
    for(int i=0; i<4; i++){
        printf("%p ", &t[i]);
    }
    return 0;
}
