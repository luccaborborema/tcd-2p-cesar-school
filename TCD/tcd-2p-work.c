#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void insertion(int size, int vet [size]) {
	 int i, j, x;
	 for (i = 1; i < size; i++){
		  x = vet[i];
		  j = i - 1;
		  while( j >= 0 && vet[j] > x){
			  vet[j+1] = vet[j];
			  j = j-1;
		  }
		  vet[j+1] = x;
	}
}

void selection(int size, int vet [size]) {
    int i, j, min, aux;
    for (i = 0; i < (size-1); i++) {
        min = i;
        for (j = (i+1); j < size; j++) {
            if(vet[j] < vet[min])
            min = j;
        }
        if (i != min) {
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
        }
    }
}

void bubble(int size, int vet [size]) {
    int i, j, aux;
    for (i = size - 1; i > 0; i--){
        for (j = 0; j < i; j++){
            if(vet[j] > vet[j+1]){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}

void heapify (int size, int vet[size], int i)
{
	int maior;
	int aux;
	int l = 2*(i);
	int r = (2*i)+1;

	if ((l <= size) && (vet[l-1] > vet[i-1])) {
		maior = l;
	} else {
		maior = i;
	}
	if ((r <= size) && (vet[r-1] > vet[maior-1])) {
		maior = r;
	}
	if (maior != i) {
		aux = vet[i-1];
		vet[i-1] = vet [maior-1];
		vet[maior-1] = aux;
		heapify (size, vet, maior);
	}
}


void build_heap (int size, int vet[size])
{
	int i;
	for (i = (size/2); i >= 1; i--) {
		heapify(size, vet, i);
	}
}
void heap_sort (int size, int vet[])
{
	int i;
	int aux;
	int tam = size;

	build_heap (size, vet);
	for (i = size; i >= 1; i--) {
		aux = vet[i-1];
		vet[i-1] = vet [0];
		vet[0] = aux;
		tam --;
		heapify(tam, vet, 1);
	}
}

void intercala(int a[], int b[], int ini1, int ini2, int end)
{
	int i = ini1;
	int j = ini2;
	int k = ini1;

	while ((i < ini2) && (j < (end + 1))) {
		if (a[i] <= a[j]) {
			b[k] = a[i];
			i++;
			k++;
		} else {
			b[k] = a[j];
			j ++;
			k++;
		}
	}
	while (i < ini2) {
		b[k] = a[i];
		k++;
		i++;
	}
	while (j < (end + 1)) {
		b[k] = a[j];
		k++;
		j++;
	}
	for (i = ini1; i < (end+1); i++) {
		a[i] = b[i];
	}
}

void merge_sort(int a[], int b[], int ini, int end)
{
	if (ini == end) {
		return;
	}
	merge_sort(a, b, ini,((ini + end) / 2));
	merge_sort(a, b, (((ini + end) / 2) + 1), end);
	intercala(a, b, ini, (((ini + end) / 2) + 1), end);

}

int particiona(int vet[], int left, int right)
{
	int i = left;
	int j = right;
	int aux;
	int pivo = vet[left];
	while (i < j) {
		while (vet[i] <= pivo) {
			i++;
		}
		while (vet[j] > pivo) {
			j--;
		}
		if (i < j) {
			aux = vet[j];
			vet[j] = vet[i];
			vet[i] = aux;
		}
	}
	aux = vet[j];
	vet[j] = vet[left];
	vet[left] = aux;
	return j;
}

void quick_sort(int vet[], int left, int right)
{
	int split;
	if (left < right) {
		split = particiona(vet, left, right);
		quick_sort(vet, left, (split - 1));
		quick_sort(vet, (split + 1), right);
	}
}

int main(void)
{
	int choice, size;
	int cont = 0;
	char *nome;
	FILE *ptr;

	printf("Digite 1 para insertion\n");
	printf("Digite 2 para selection\n");
	printf("Digite 3 para bubble\n");
	printf("Digite 4 para heap\n");
	printf("Digite 5 para merge\n");
	printf("Digite 6 para quick\n");
	scanf("%d", &choice);
	printf("------------------------------------\n");
	printf("Digite 1 para o arquivo de 1000 numeros\n");
	printf("Digite 2 para o arquivo de 5000 numeros\n");
	printf("Digite 3 para o arquivo de 10000 numeros\n");
	printf("Digite 4 para o arquivo de 20000 numeros\n");
	printf("Digite 5 para o arquivo de 50000 numeros\n");
	printf("Digite 6 para o arquivo de 75000 numeros\n");
	printf("Digite 7 para o arquivo de 100000 numeros\n");

	scanf("%d", &size);
	if (size == 1) {
		ptr = fopen("1000.txt","r");
		size = 1000;
	} else if (size == 2) {
		ptr = fopen("5000.txt","r");
		size = 5000;
	} else if (size == 3) {
		ptr = fopen("10000.txt","r");
		size = 10000;
	} else if (size == 4) {
		ptr = fopen("20000.txt","r");
		size = 20000;
	} else if (size == 5) {
		ptr = fopen("50000.txt","r");
		size = 50000;
	} else if (size == 6) {
		ptr = fopen("75000.txt","r");
		size = 75000;
	} else if (size == 7) {
		ptr = fopen("100000.txt","r");
		size = 100000;
	}

	int vet[size];

	while (!feof(ptr)){
		fscanf(ptr,"%d", &vet[cont]);
		cont +=1;
	}

	clock_t start, end;

	if (choice == 1){
		start = clock();
		insertion(size, vet);
		end = clock();
    } else if (choice == 2){
		start = clock();
		selection(size, vet);
		end = clock();
    } else if (choice == 3){
		start = clock();
		bubble(size, vet);
		end = clock();
    } else if (choice == 4){
		start = clock();
		heap_sort(size, vet);
		end = clock();
    } else if (choice == 5){
        int b [size];
        start = clock();
		merge_sort(vet, b, 0, (size - 1));
		end = clock
		double tempo = (end - start) * 1000/ 	CLOCKS_PER_SEC;
		cont = 0;
		while (cont < size) {
			printf("%d ", b[cont]);
			cont += 1;
		}
		printf("\ntempo gasto : %g ms.\n", tempo);
		return 0;
    } else if (choice == 6){
		start = clock();
		quick_sort(vet, 0, (size - 1));
		end = clock();
    }

	double tempo = (end - start) * 1000/ 	CLOCKS_PER_SEC;

	cont = 0;

	while (cont < size) {
		printf("%d ", vet[cont]);
		cont += 1;
	}
	
	printf("\ntempo gasto : %g ms.\n", tempo);
	return 0;
}
