#include <stdio.h>
// fakultät rechner

// funktion für nutzer eingabe von n
int input();
// funktion zum rechnen
int faculty(int n);

int main()
{
 int n;
 // nutzer eingabe als n speichern
 n = input();
 // pass by value 
 int res = faculty(n); 
 // ausgabe
 printf("%d! = %d", n, res); 

 return 0; 
}

int input() {
 int n;
 scanf("%d",&n); 
 return n;
}

int faculty(int n) {
// basis = 0! ist 1 
if (n == 0) {
 return 1;
}
// n (mal) n-1 bis 1  
else {
 return n * faculty(n-1); 
}

}


