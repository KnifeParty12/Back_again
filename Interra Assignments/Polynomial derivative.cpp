#include "bits/stdc++.h"
#define MOD (1e9 + 7);
using ll = int64_t;
using ull = uint64_t;
#define ll long long
using namespace std;

// Function to differentiate the
// given term
string diffTerm(string pTerm)
{
    // Get the coefficient
    string coeffStr = "", S = "";
    int i;

    // Loop to get the coefficient
    for (i = 0; pTerm[i] != 'x'; i++)
        coeffStr.push_back(pTerm[i]);

    int coeff
        = atoi(coeffStr.c_str());

    // Loop to get the power of each term
    string powStr = "";
    for (i = i + 2; i != pTerm.size(); i++)
        powStr.push_back(pTerm[i]);

    int power = atoi(powStr.c_str());
    string a, b;
    // Converting the value
    // to the string
    ostringstream str1, str2;

    // For ax^n, we find (n)*a*x^(n-1)
    coeff = coeff * power;
    str1 << coeff;
    a = str1.str();
    power--;
    str2 << power;
    b = str2.str();
    S += a + "x^" + b;

    return S;
}

// Function to differentiate the
// given polynomial
string diffstr(string& poly)
{

    // We use istringstream to get
    // the input in tokens
    istringstream is(poly);

    string pTerm, S = "";

    // For every token, compute the
    // differentiation
    while (is >> pTerm) {

        // If the token is equal to
        // '+', '-' then
        // continue with the string
        if (pTerm == "+") {
            S += " + ";
            continue;
        }

        if (pTerm == "-") {
            S += " - ";
            continue;
        }

        // Otherwise find the differentiation
        // of that particular term
        else
            S += diffTerm(pTerm);
    }
    return S;
}

// Driver code
int main()
{
    string str = "5x^4 + 6x^2 + 5x^2";
    int der = 2;
    while(der--){
        cout<<diffstr(str)<<endl;
    }
   return 0;
}
