#include <stdio.h>

// Calculate BMI with feedback  
int main() 
{
  float weight, height;
  float bmi;
  scanf("%f %f", &weight, &height);
  // calculation from grams to Kg 
  float kg = weight / 1000.0;
  // Calculation from cm to m 
  float m = height /100.0; 
  // calculation of BMI
  bmi = kg / (m * m);
  // decleration of bmi-rating
  if (bmi <= 18.4 ) 
  {
    printf("Untergewicht %.1f\n", bmi); 
  }
  // could be written as 18.5 <= bmi <= 24.9
  if (bmi > 18.4 && bmi < 24.8) 
  {
    printf("Normalgewicht %.1f\n", bmi);
  }
  if (bmi >= 24.8)  
  {
    printf("Uebergewicht %.1f\n", bmi);   
  }

  return 0;
} 
