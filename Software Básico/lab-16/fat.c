int fat (int n) {

  if (n > 0)

     return fat(n-1) * n;

  return 1;  

}
