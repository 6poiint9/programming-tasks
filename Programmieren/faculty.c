/*
 fakultät n mithilfe recurion berehchnen

 Funktionen:
 input() 
 faculty() 
 */
#include <stdio.h> 

// Funtion prototypen
int input(); 
int faculty(int n);

int main()
{
  int n = input(); 
  
  int result = faculty(n); 
  
  printf("%d",result); 

  return 0; 
}

int input() {
 int n; 
 scanf("%d", &n); 
 return n; 
}

int faculty(int n) {
  // Basisfall 0! = 1
 if (n == 0) {
  return 1; 
 }
 else {
  return faculty(n - 1) * n; 
 }



}
















