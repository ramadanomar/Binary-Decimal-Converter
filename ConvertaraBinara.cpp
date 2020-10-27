#include <iostream>

using namespace std;

void DecimalToBinar(int nr) // Functie Decimal to binar
{
	int numarBinar[1000]; // Vectorul cu numarul binar

	int i = 0; // Contour

	while (nr) // Convertirea Numarului
	{
		numarBinar[i] = nr % 2; // 0 sau 1 in functie de divizibilitatea numarului
		nr = nr / 2; // Impartim numarul
		i++; // Creste ordinea numarului
	}

	cout << "Varianta Binara a numarului este: ";

	for (int j = i - 1; j >= 0; j--) // j = i-1 deoarece iese din for cu i ul incrementat. j-- pentru ca trb sa afisam vectorul in ordine descrescatoare
	{
		cout << numarBinar[j];
	}

	cout << endl;
}

int BinaryToDecimal(int nr)
{
	int numarDecimal = 0, base = 1;

	while (nr)
	{
		int ultCifra = nr % 10; // Ultima cifra
		nr = nr / 10; // eliminam ultima cifra din numar
		numarDecimal = numarDecimal + ultCifra * base; // Adaugam valoare cifrei catre numar
		base = base * 2; // Inmultim pozitia cu 2

	}

	return numarDecimal;
}

int esteBinar(int nr) // Verificam daca numarul este binar
{
	int ultCifra;
	while (nr > 0)
	{
		ultCifra = nr % 10;
		nr = nr / 10;
		if (ultCifra >= 2)
			return 0;
	}
	return 1;
}

int main()
{
	int numar; cin >> numar;

	while (numar >= 0)
	{
		if (esteBinar(numar) == 1)
			cout << "Numarul in forma decimala este: " << BinaryToDecimal(numar) << endl;
		else
			DecimalToBinar(numar);
		
		cin >> numar;
	}

}