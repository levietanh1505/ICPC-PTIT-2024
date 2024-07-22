#include<iostream>
#include<string.h>
#include<cctype>

using namespace std;

int main(){
    long long sum = 0;
    char input[10000];
    while(fgets(input, sizeof(input), stdin) != NULL){
        char *token = strtok(input, " ");
        while(token != NULL){
            if(strlen(token) < 19 && atoll(token) > 2147483647) sum += atoll(token);
            token = strtok(NULL, " ");
        }
    }
    cout << sum;
    return 0;
}