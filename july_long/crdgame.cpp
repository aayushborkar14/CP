#include <iostream>

using namespace std;

long long int powerOfCard(int k) {
    long long int sum{ };
    while (k != 0) {
        sum += k%10;
        k /= 10;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t{ };
    cin >> t;
    int n{ };
    while (t--) {
        cin >> n;
        int chef{ }, morty{ };
        long long int a{ }, b{ };
        long long int chefTemp{ }, mortyTemp{ };
        while (n--) {
            cin >> a >> b;
            chefTemp = powerOfCard(a);
            mortyTemp = powerOfCard(b);
            if (chefTemp > mortyTemp) {
                chef++;
            } else if (chefTemp < mortyTemp) {
                morty++;
            } else {
                chef++;
                morty++;
            }            
        }
        if (chef > morty) {
            cout << 0 << " " << chef << "\n";
        } else if (morty > chef) {
            cout << 1 << " " << morty << "\n";
        } else if (morty == chef) {
            cout << 2 << " " << chef << "\n";
        }        
    }
}
