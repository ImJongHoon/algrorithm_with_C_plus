#include <iostream>

using namespace std;

int main(int argc, char** argv){

    char before[101];
    char after[101];

    int p = 0;

    cin.getline(before, 101, '\n');

    for(int i =0; before[i] != '\0'; i++){
        if(before[i] != ' '){
            if(before[i]>=65 && before[i]<=90){
                after[p] = before[i] + 32;
                p++;
            }
            else if(before[i]>=97 && before[i]<=122){
                after[p] = before[i];
                p++;
            }
        }
    }

    after[p] = '\0';

    cout << after;
    
    return 0;
}