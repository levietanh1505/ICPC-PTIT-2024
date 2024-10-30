/*
    Giả thuyết Goldbach do nhà toán học người Đức Christian Goldbach (1690-1764) nêu ra vào năm 1742 trong 
    một lá thư gửi tới Leonhard Euler, là một trong những bài toán lâu đời và nổi tiếng còn chưa giải được 
    trong lý thuyết số nói riêng và toán học nói chung. Giả thuyết phỏng đoán rằng: 
    
    Mọi số tự nhiên chẵn lớn hơn 2 có thể biểu diễn bằng tổng của hai số nguyên tố. 
    
    Trong bài toán này bạn được cho một số tự nhiên chẵn ru0d6Jg+wC82P9+ATOHhBcdAM71AAAAAElFTkSuQmCC,
     bạn hãy đếm số lượng cặp số nguyên tố DG6LHObmtdcAAAAASUVORK5CYII= mà LwzlQQQxcSAAAAAElFTkSuQmCC.
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n;  cin >> n;
    
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i <= sqrt(n); i++){
        if(isPrime[i]){
            for(int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    int res = 0;
    for(int i = 2; i <= n / 2; i++){
        if(isPrime[i] && isPrime[n - i]) res++;
    }

    cout << res;
    return 0;
}