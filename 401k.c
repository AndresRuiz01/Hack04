/*
 * File: 401k.c
 * Authors: Teresa Gramer and Andres Ruiz
 * Date: 2019/02/08
 *
 * A code that returns the interest and balance for the
 * first few and last few month of a retirement plan
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(int argc, char **argv) {

  double balance = atof(argv[1]);
  double contribution = atof(argv[2]);
  double rateOfReturn = atof(argv[3]);
  double inflationRate = atof(argv[4]);
  int years = atoi(argv[5]);

  double adjustedRateReturn, interestGained, totalInterest;
  int months;
  int count = 1;

  adjustedRateReturn = (((1 + rateOfReturn) / (1 + inflationRate)) - 1) / 12;
  months = years * 12;


  if ((contribution * 12) > 18500) {
    printf("Illegal: monthly contributions exceed $18,500 annual limit.");
    return 0;
}
  printf("Month Interest Balance\n");

    while (count <= months) {
      interestGained = ((balance) * (adjustedRateReturn + 1)) - (balance);
      balance = balance + interestGained + contribution;
      printf("%d $ %0.2f $ %0.2f\n", count, interestGained, balance);
      totalInterest = totalInterest + interestGained;
      count++;
      balance = (int)(balance * 100 + 0.5);
      balance = balance / 100;
      totalInterest = (int)(totalInterest * 100 + 0.5);
      totalInterest = totalInterest / 100;
}

  printf("Total Interest Earned: $ %0.2f\n", totalInterest);
  printf("Total Nest Egg: $ %0.2f\n", balance);

  return 0;
}
