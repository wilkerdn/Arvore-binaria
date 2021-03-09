#include "arv-binaria.h"

int main(){
	int x=0,opcao=0,opcao2=0,cont=0,opc=1;

	while(opc==1){
	printf("\nDigite um numero que sera a raiz de sua arvore: ");
	scanf("%d",&x);
	Arvore *tree = cria_arvore(x);
		opcao = 0;
		while(opcao==0){
		printf("\nInserir numero = 1\nEfetuar busca = 2\nRemover numero = 3\nVerificar altura = 4\nImprimir numeros = 5\nDeletar arvore = 6\nOpcao = ");
		scanf("%d",&opcao2);

		if(opcao2==1){
		printf("\nDigite um numero para ser inserido na arvore: ");
		scanf("%d",&x);
		insere_no(tree->raiz, x);
		opcao=0;

		}else if(opcao2==2){
		printf("\nDigite um numero para ser pesquisado na arvore: ");
		scanf("%d",&x);
		pesquisa_no(tree->raiz, x);
		opcao=0;
	
		}else if(opcao2==3){
		printf("\nDigite um numero para ser deletado da arvore: ");
		scanf("%d",&x);
		if(altura(tree->raiz)==0){
		remove_no(tree->raiz, x);
		printf("\nVoce removeu o unico elemento da arvore\n");
		opcao=1;
		}else{
		remove_no(tree->raiz, x);
		opcao=0;
		}

		}else if(opcao2==4){
		cont = altura(tree->raiz);
		printf("\nAltura = %d\n",cont);
		opcao=0;
		
		}else if(opcao2==5){
		printf("\nImprimir in-ordem = 1, pre-ordem = 2 ou pos-ordem = 3\n");
		scanf("%d",&opcao2);
			if(opcao2==1){
			exibir_emordem(tree->raiz);
			}else if(opcao2==2){
			exibir_preordem(tree->raiz);
			}else{
			exibir_posordem(tree->raiz);
			}
		printf("\n");
		opcao=0;
		
		}else if(opcao2==6){
		deletar_arv(tree->raiz);
		free(tree);
		break;
		}
}
	printf("\nPara comecar outra arvore = 1\nPara encerrar o programa = 2\nOpcao = ");
	scanf("%d",&opc);
}	
	return 0;
}
