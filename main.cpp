#include <iostream>
#include <chrono>
#include <time.h>
#include<fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

void bubble_sort(int tab[], int size_tab)
{

	for (int i = 0; i<size_tab; i++)
	{
		for (int j = 0; j<size_tab - i - 1; j++)
		{
			if (tab[j]>tab[j + 1])
			{
				swap(tab[j], tab[j + 1]);
			}
		}
	}

}

void counting_sort(int *tab, int n)
{
	int max = 0;
	for (int i = 0; i<n; i++)
	{
		if (tab[i]>max)
		{
			max = tab[i];
		}

	}
	int *counting = new int[max + 1];
	
	for (int i = 0; i<max+1; i++)
	{
		counting[i] = 0;

	}
	for (int i = 0; i<n; i++)
	{
		counting[tab[i]]++;

	}

	for (int i = 1; i<max+1; i++)
	{
		counting[i] = counting[i] + counting[i-1];

	}
	int *help_array = new int[n];
	for (int i = 0; i<n; i++)
	{
		help_array[i] = 0;


	}

	for (int i = n-1; i >= 0; i--)
	{
		counting[tab[i]] -= 1;
		help_array[counting[tab[i]]] = tab[i];


	}

	for (int i = 0; i<n; i++)
	{
		tab[i] = help_array[i];
	}

}
void Shell_sort(int *tab, int size_tab)
{
	int h = 1;
	while (h <= size_tab)
	{
		h = 3 * h + 1;
	}
	h = h / 9;
	if (h == 0)
	{
		h = 1;
	}
	int i, element;
	while (h)
	{
		for (int j = size_tab - h - 1; j >= 0; j--)
		{
			element = tab[j];
			i = j + h;
			while ((i<size_tab) && (element>tab[i]))
			{
				tab[i - h] = tab[i];
				i += h;
			}
			tab[i - h] = element;
		}
		h = h / 3;

	}

}

void Heapify(int *tab, int n, int i) 
{
int naj = i;
int l = 2 * i + 1;
int r = 2 * i + 2;

if (l < n && tab[l] > tab[naj])
naj = l;

if (r < n && tab[r] > tab[naj])
naj = r;

if (naj != i)
	{
	int pom = tab[naj];
	tab[naj] = tab[i];
	tab[i] = pom;
	Heapify(tab, n, naj);
	}
}
void HeapSort(int *tab, int n) 
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(tab, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		int pom = tab[0];
		tab[0] = tab[i];
		tab[i] = pom;
		Heapify(tab, i, 0);
	}
}

void losowe_bubble()
{
	ofstream wynik;
	wynik.open("Bubble.txt");
	srand(time(NULL));
	int N = 15000;
	wynik << "Bubble: " << endl;
	for (int j = 0; j < 15; j++)
	{
		int *tab = new int[N + 1];
		for (int i = 0; i < N; i++)
		{
			tab[i] = rand() % 1000000;
		}
		auto begin = std::chrono::high_resolution_clock::now();
		bubble_sort(tab, N);
		auto end = std::chrono::high_resolution_clock::now();
		wynik << N << " " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n";
		delete[] tab;
		N = N + 5000;
	}
}

void losowe_heap()
{
	ofstream wynik;
	wynik.open("Heap.txt");
	srand(time(NULL));
	int N = 1000000;
	wynik << "Heap: " << endl;
	for (int j = 0; j<15; j++)
	{
		int *tab = new int[N+1];
		for (int i = 0; i<N; i++)
		{
			tab[i] = rand() % 1000000;
		}
		auto begin = std::chrono::high_resolution_clock::now();
		HeapSort(tab, N);
		auto end = std::chrono::high_resolution_clock::now();
		wynik << N << " " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n";
		delete[] tab;
		N = N + 500000;
	}
}
void losowe_counting()
{
	ofstream wynik;
	wynik.open("Counting.txt");
	srand(time(NULL));
	int N = 1000000;
	wynik << "Counting: " << endl;
	for (int j = 0; j<15; j++)
	{
		int *tab = new int[N + 1];
		for (int i = 0; i<N; i++)
		{
			tab[i] = rand() % 1000;
		}
		auto begin = std::chrono::high_resolution_clock::now();
		counting_sort(tab, N);
		auto end = std::chrono::high_resolution_clock::now();
		wynik << N << " " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n";
		delete[] tab;
		N = N + 500000;
	}
}
void losowe_shell()
{
	ofstream wynik;
	wynik.open("Shell.txt");
	srand(time(NULL));
	int N = 1000000;
	wynik << "Shell: " << endl;
	for (int j = 0; j<15; j++)
	{
		int *tab = new int[N + 1];
		for (int i = 0; i<N; i++)
		{
			tab[i] = rand() % 1000000;
		}
		auto begin = std::chrono::high_resolution_clock::now();
		Shell_sort(tab, N);
		auto end = std::chrono::high_resolution_clock::now();
		wynik << N << " " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n";
		delete[] tab;
		N = N + 500000;
	}
}
int main()
{
	losowe_counting();
	losowe_shell();
	losowe_heap();
	system("Pause");
	return 0;
}