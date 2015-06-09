#include <stdio.h>

#include "callee.h"

void displayProduct(product p)
{
  printf("Department: %hd Stock: %d EAN:%lu price: %f\n", p.departmentCode,
	 p.stockLevel, p.EAN, p.price);
}
