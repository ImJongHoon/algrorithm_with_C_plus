#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, char** argv){
    int sumResult = 0;
    int Hcount = 0;
    int Ccount = 0;
    bool Ccalc = false;

    string strArr;
    getline(cin, strArr);

    for(int i = (strArr.length() - 1); i>=0; i--){
        if(strArr[i] == 'H' && sumResult == 0){
            Ccalc = true;
            sumResult = sumResult + 1;

            if(strArr[i-1] == 'C'){
                sumResult = sumResult + 4;
                printf("%d", sumResult);
                break;
            }
        } else if (strArr[i] == 'H'){
            Ccalc = true;

            if(strArr[i-1] == 'C'){
                sumResult = sumResult + 4;
                printf("%d", sumResult);
                break;
            }
        } 
        else if(strArr[i] == 'C'){
            printf("%d", sumResult);
            break;
        }
        else{
            if(Ccalc == true){
            sumResult = sumResult + (12 * pow(10, Ccount) * (int)(strArr[i] - '0'));
            Ccount++;
            } else {
                sumResult = sumResult + (1 * pow(10, Hcount) * (int)(strArr[i] - '0'));
                Hcount++;
            }
        }
    }
    
    return 0;
}