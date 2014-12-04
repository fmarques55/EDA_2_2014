TNo *visitaArvore(TNo *ra, TNo *r, int v)
,.,bj{
	//Endereco recebido eh onde o novo no deve ser alocado
	if(r==NULL)
	{
		r=malloc(sizeof(struct TNo));
		r->valor=v;
		r->esq=NULL;
		r->dir=NULL;

		//A insercao eh na raiz
		if(ra==NULL)
		{
			return r; //A raiz sera preenchida como o novo no criado
		}
		//A insercao nao eh na raiz
		else
		{
			//Se o valor for menor que o do no atual, alocar na esquerda
			if(v < ra->valor)
			{
				ra->esq=r;
			}
			//Se o valor for maior que o do no atual, alocar na direita
			else
			{
				ra->dir=r;
			}
			return r;

		}

	}
	//Ir para esquerda ou direita encontrar o endereco onde inserir na ABP
	else
	{
		if(v< r->valor)
		{
			visitaArvore(ra,r->esq,v);
		}
		else
		{
			visitaArvore(ra,r->dir,v);
		}
	}
	
}

void inserir(TNo *raiz, int valor)
{
	if(raiz==NULL)
	{
		raiz = visitaArvore(raiz,raiz,valor);
	}
	else
	{
		visitaArvore(raiz,raiz,valor);
	}
}