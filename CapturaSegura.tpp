#include <limits>
#include <iostream>
using std::numeric_limits;

using std::cout;
using std::cin;

template <typename Tipo>
void CapturaSegura(Tipo &n, const char solicitud[])
{

    cout << solicitud;
    cin >> n;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        cout << solicitud;
        cin >> n;
    }
}