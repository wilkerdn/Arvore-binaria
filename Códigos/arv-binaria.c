#include "arv-binaria.h"

No* cria_no(int num){
	No *tree;
	tree = (No*) malloc(sizeof(No));

	tree->esq = NULL;
	tree->dir = NULL;
	tree->num =  num;

	return tree;
}

Arvore* cria_arvore(int num){
	Arvore *tree;
	tree = (Arvore*) malloc(sizeof(Arvore));
	tree->raiz = cria_no(num);

	return tree;
}

void insere_no(No *tree, int num){
	if(num < tree->num){
		if(tree->esq){
			insere_no(tree->esq, num);
		}else{
			No *novo = cria_no(num);
			tree->esq = novo;
		}
	}else{
		if(tree->dir){
			insere_no(tree->dir, num);
		}else{
			No *novo = cria_no(num);
			tree->dir = novo;
		}
	}
}

void pesquisa_no(No *tree, int num){
	if(tree == NULL){
		printf("Numero %d nao esta presente na arvore\n",num);
	}else if(num < tree->num){
		pesquisa_no(tree->esq, num);
	}else if(num > tree->num){
		pesquisa_no(tree->dir, num);
	}else{
		printf("O numero %d esta presente na arvore\n", num);
	}
}

No* acha_menor(No *tree){
	if(tree->esq == NULL){
		return tree;
	}
	return acha_menor(tree->esq);
}

int acha_maior(int a, int b){
	if(a>b){
		return a;
	}else
		return b;
}

No *remove_no(No *tree, int num){
	No *aux;
	if(tree==NULL){
		printf("Numero ausente\n");
	}else if(num < tree->num){
		tree->esq = remove_no(tree->esq, num);
	}else if(num > tree->num){
		tree->dir = remove_no(tree->dir, num);
	}else if(tree->esq == NULL && tree->dir == NULL){
		aux = tree;
		free(tree);
		return NULL;
	}else if(tree->esq == NULL){
		aux = tree->dir;
		free(tree);
		return aux;
	}else if(tree->dir == NULL){
		aux = tree->esq;
		free(tree);
		return aux;
	}else{
		No *menor = acha_menor(tree->dir);
		tree->num = menor->num;
		tree->dir = remove_no(tree->dir, menor->num);
	}
	return tree;
}

int altura(No *tree){
	if((tree==NULL)||(tree->esq==NULL&&tree->dir==NULL)){
	return 0;
	}else{
	return 1 + acha_maior(altura(tree->esq), altura(tree->dir));
	}
}

void exibir_emordem(No *tree){
	if(tree!=NULL){
	exibir_emordem(tree->esq);
	printf("%d ",tree->num);
	exibir_emordem(tree->dir);
	}
}

void exibir_preordem(No *tree){
	if(tree!=NULL){
	printf("%d ",tree->num);
	exibir_preordem(tree->esq);
	exibir_preordem(tree->dir);
	}
}

void exibir_posordem(No *tree){
	if(tree!=NULL){
	exibir_posordem(tree->esq);
	exibir_posordem(tree->dir);
	printf("%d ",tree->num);
	}
}

void deletar_arv(No *tree){
	No *esquerda;
	No *direita;
	while(tree->esq!=NULL){
	esquerda = tree->esq;
	remove_no(tree, esquerda->num);
	}
	while(tree->dir!=NULL){
	direita = tree->dir;
	remove_no(tree, direita->num);
	}
	free(tree);
}
