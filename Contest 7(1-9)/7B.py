# Có N quả bóng khác nhau và N chiếc hộp giống nhau (không phân biệt thứ tự các hộp). 
# Một chiếc hộp có thể có nhiều quả bóng, nhưng cũng có thể không có quả bóng nào. 
# Hãy đếm số cách xếp N quả bóng vào N chiếc hộp?

from math import comb

def init():
    C = [[0] * 51 for _ in range(51)]       # C[i][j] = jCi
    res = [0] * 51
    
    for i in range(51):
        C[i][0] = 1
        C[i][i] = 1
        for j in range(1, i):
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j]
    
    res[0] = 1
    for i in range(1, 51):
        res[i] = sum(C[i - 1][j] * res[j] for j in range(i))
    
    return res

def main():
    res = init()
    t = int(input())
    for _ in range(t):
        n = int(input())
        print(res[n])

if __name__ == "__main__":
    main()
