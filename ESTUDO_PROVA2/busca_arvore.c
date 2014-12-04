TNo *busca_arvore(TNo *no, int v)
{
	if(no!=NULL)
	{
		if(v==no->valor)
		{
			return no;
		}
		else
		{
			if(v< no->valor)
			{
				return busca_arvore(no->esq, v);
			}
			else
			{
				return busca_arvore(no->dir, v);
			}
		}
	}
	else
	{
		return NULL;
	}
}