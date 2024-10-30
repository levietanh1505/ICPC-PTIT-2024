#include <iostream>
#include <cmath>

using namespace std;

const long double epsilon = 1e-9;

int main() {
    long double centerX, centerY, radius;
    cin >> centerX >> centerY >> radius;
    long long count = 0,
              minX = centerX - radius, maxX = centerX + radius;

    for (long long x = minX; x <= maxX; ++x) {
        long double distX = fabs(x - centerX);
        if (distX - radius <= epsilon) {
        
            long double distY = sqrt(radius * radius - distX * distX);
            long long minY = centerY - distY, maxY = centerY + distY;
            
            while (minY <= centerY + distY && 
                    !((x - centerX) * (x - centerX) + (minY - centerY) * (minY - centerY) - radius * radius <= epsilon)) 
                ++minY;
            while (maxY >= centerY - distY && 
                    !((x - centerX) * (x - centerX) + (maxY - centerY) * (maxY - centerY) - radius * radius <= epsilon)) 
                --maxY;
                
            count += (maxY - minY + 1);
        }
    }
    cout << count << endl;
    return 0;
}