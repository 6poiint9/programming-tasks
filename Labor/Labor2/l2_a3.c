#include <stdio.h>

// Calculate BMI 
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
  printf("Der BMI liegt bei: %.2f!\n", bmi);

  return 0;
}
