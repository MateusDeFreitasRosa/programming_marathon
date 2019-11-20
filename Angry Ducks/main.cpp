#include <bits/stdc++.h>
#define PI 3.14159
#define GV 9.80665

using namespace std;

int main()
{
    double alturaI;
    int p1,p2;
    int n;
    double angulo, velocidade,angulo_rad;
    double Vox,Voy,alcance,H;

    while (cin >> alturaI >> p1 >> p2 >> n)
    {
        cout << fixed;
        cout.precision(5);

        for (int i=0; i<n; i++)
        {
            cin >> angulo >> velocidade;
            angulo_rad = (double) (PI*angulo) / 180;

            Vox = velocidade * cos(angulo_rad);
            Voy = velocidade * sin(angulo_rad);
            H = (double) ((Voy*Voy) / (2*GV)) + alturaI;

            alcance = (double) (((Voy / GV) + sqrt((2 * H) / GV)) * Vox);

            if (alcance > p1 && alcance < p2) {
                cout << alcance << " -> DUCK" << endl;
            }
            else {
                cout << alcance << " -> NUCK" << endl;
            }
        }
    }
    return 0;
}
