#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 1,section=1,x1=0,x2=n,y1=0,y2=n;
    int mat[n][n];
    /*
    1  2  3  4
    12 13 14 5
    11 16 15 6
    10 9  8  7 
    */
    while (count<=n*n){
        switch(section){
            case 1:
                for (int i = y1 ; i < y2 ; i++){
                    mat[x1][i]=count;
                    count++;
                }
                x1++;
                section = 2;
                break;
            case 2:
                for (int i = x1 ; i < x2 ; i++){
                    mat[i][y2-1]=count;
                    count++;
                }
                y2--;
                section = 3;
                break;
            case 3:
                for (int i = y2-1 ; i >= y1 ; i--){
                    mat[x2-1][i]=count;
                    count++;
                }
                x2--;
                section = 4;
                break;
            case 4:
                for (int i = x2-1 ; i >= x1 ; i--){
                    mat[i][y1]=count;
                    count++;
                }
                y1++;
                section = 1;
                break;
        }
    }

    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            printf("%d,\t",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}