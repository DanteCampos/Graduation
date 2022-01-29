int filtro(unsigned char x, short lim) {
  int r;
  unsigned short a = (unsigned short)x;
  unsigned short b = (unsigned short)lim;

  if (a < b)
    r = 0;
  else
    r = (int)lim;
  return r;
}
