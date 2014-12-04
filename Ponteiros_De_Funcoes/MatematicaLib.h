//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
#include <float.h>

//Séries:

void GeraSerieAleatoria(float *pSerie, int pqtde)
{
  int pp;
  float pmaior = FLT_MIN;
  srand(time(NULL));
  for(pp=0;pp<pqtde;pp++)
  {
    pSerie[pp] = rand();
    if(pSerie[pp] > pmaior)
      pmaior = pSerie[pp];
  }
  for(pp=0;pp<pqtde;pp++)
    pSerie[pp] /= pmaior;
}
// Funções matemáticas sobre vetores
float Soma(float *pnumeros, int pqtde)
{
  int pind;
  float presultado = 0;
  for(pind=0;pind<pqtde;pind++)
    presultado += pnumeros[pind];
  return presultado;
}

float Media(float *pnumeros, int pqtde)
{
  int pind;
  float presultado = 0;
  for(pind=0;pind<pqtde;pind++)
    presultado += pnumeros[pind];
  return presultado/pqtde;
}

float DesvioPadrao(float *pnumeros, int pqtde)
{
  int pind;
  float pdif, pmedia = 0, presultado=0;
  for(pind=0;pind<pqtde;pind++)
    pmedia += pnumeros[pind];
  pmedia /= pqtde;
  for(pind=0;pind<pqtde;pind++)
  {
    pdif = (pnumeros[pind]-pmedia);
    presultado += pdif*pdif;
  }
  return presultado/(float)(pqtde*pqtde);
}

float SomaPotencias(float *pnumeros, int pqtde)
{
  int pind;
  float presultado = 0;
  for(pind=0;pind<pqtde;pind++)
    presultado += powf(pnumeros[pind],pind);
  return presultado;
}

float SomaQuadrados(float *pnumeros, int pqtde)
{
  int pind;
  float presultado = 0;
  for(pind=0;pind<pqtde;pind++)
    presultado += pnumeros[pind]*pnumeros[pind];
  return presultado;
}
