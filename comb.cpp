#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;
using std::cout;
using std::cin;
using std::ofstream;
using std::ifstream; 


void printComb_i(int arrayComb[], int start, int len, int out[], int now, int max) {

	ofstream myfile;
	myfile.open("Arq.txt", ios::app);
	if (now >= max) {
		for (int i = 0; i<max; i++) {
			printf(" %d ", out[i]);
			myfile << out[i] << " ";
		}
		myfile << endl;
		printf("\n");
		return;
	}
	for (int i = start; i<len; i++) {
		out[now] = arrayComb[i];
		printComb_i(arrayComb, i + 1, len, out, now + 1, max);
	}
	myfile.close();
}


void printComb(int arrayComb[], int len, int r) {
	
	int out[15];
	memset(out, 0, sizeof(out));
	for (int i = 0; i <= len - r; i++) {
		out[0] = arrayComb[i];
		printComb_i(arrayComb, i + 1, len, out, 1, r);
	}
}

void fillArray(int arrayComb[]) {
	for (int i = 0; i < 60; i++) {
		arrayComb[i] = i + 1;
	}
}

int main()
{
	ofstream myfile;
	myfile.open("Arq.txt");
	myfile.close();
	time_t start, end;
	start = time(NULL);
	int arrayComb[60];
	int numberQtd=0;

	printf("Digite a quantidade de números jogados: \n");
	scanf("%d", &numberQtd);

	int n = sizeof(arrayComb) / sizeof(arrayComb[0]);
	fillArray(arrayComb);
	printComb(arrayComb, n, numberQtd);
	end = time(NULL);
	fprintf(stdout, "O tempo de execucao em segundos é %f\n", difftime(end, start));
	system("pause");
}