#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;

class LaivuMusis
{
private:
	const static int ilgis = 10;
	const static int plotis = 10;
	int coOrd;
	int visoLaivu;
	int matrica[ilgis][plotis];
public:
	LaivuMusis()
	{ 
		coOrd = 0;
		visoLaivu = 10;
	}

	void Nunulinimas()
	{
		for (int y = 0; y < ilgis; y++)
		{
			for (int x = 0; x < plotis; x++)
			{
				matrica[y][x] = 0;
			}
		}
	}


	void Tinklelis()
	{
		cout << "   0 1 2 3 4 5 6 7 8 9" << endl;
		cout << "-----------------------" << endl;
		for (int x = 0; x < ilgis; x++)
		{
			cout << coOrd << "| ";
			coOrd++;
			for (int y = 0; y < ilgis; y++)
			{
				cout << matrica[x][y] << " ";
			}
			cout << endl;
		}
	}

	int LaivuSkaicius() 
	{
		int c = 0;
		for (int x = 0; x < ilgis; x++)
		{
			for (int y = 0; y < plotis; y++)
			{
				if (matrica[x][y] == 1)
				{
					c++;
				}
			}
		}
		return c;
	}

	void SumetamLaivus()
	{
		int laivai = 0;
		while (laivai < visoLaivu)
		{
			int xPos = rand() % 10; 
			int yPos = rand() % 10; 

			if (matrica[xPos][yPos] != 1)
			{
				laivai++;
				matrica[xPos][yPos] = 1;
			}

		}

	}
	bool Puolimas(int _x, int _y)
	{
		if (matrica[_x][_y] == 1)
		{
			matrica[_x][_y] = 2;
			return true;
		}
		return false; 
	}
	~LaivuMusis() {};
};

class Lenteles 
{
private:
	const static int ilgis = 10;
	const static int plotis = 10;
	char forma[ilgis][plotis];
public:
	
	void DaromLentele() 
	{
		for (int x = 0; x < ilgis; x++)
		{
			for (int y = 0; y < plotis; y++)
			{
				forma[x][y] = '-'; 
			}
		}
	}

	void LentelesAtnaujinimas(bool i, int x, int y) 
	{
		int xPos = x; 
		int yPos = y;

		if (i == true) 
		{
			forma[xPos][yPos] = 'Y'; 
		}
		else
		{
			forma[xPos][yPos] = 'N';
		}
	}

	void LentelesSpausdinimas() 
	{
		int amt = 0; 

		cout << "  0 1 2 3 4 5 6 7 8 9" << endl;
		for (int x = 0; x < ilgis; x++) {
			cout << amt << " "; 
			amt++; 
			for (int y = 0; y < plotis; y++) {
				cout << forma[x][y] << " "; 
			}
			cout << endl;
		}
	}
	~Lenteles() {};
};
void Taisykles();
int main() 
{
	int pasirinkimas;
	char kartojam;
	cout << "Sveiki atvyke i zaidima Laivu musis" << endl;
	cout << endl;
	cout << "1. Zaisti pries kompiuteri" << endl;
	cout << "2. Zaisti kartu su draugu" << endl;
	cout << "3. Kaip zaisti?" << endl;
	cout << endl;
	cout << "pasirinkite ka norite veikti: ";
	cin >> pasirinkimas;
	if (pasirinkimas > 3 || pasirinkimas < 0) {
		cout << "iveskite skaiciu is meniu: ";
		cin >> pasirinkimas;
	}

	if (pasirinkimas == 1) {

		do
		{
			system("CLS");
			srand((unsigned)time(NULL));
			LaivuMusis zaidejas;
			LaivuMusis cpu;

			Lenteles zaidejoLenta;
			Lenteles cpuLenta;

			zaidejas.Nunulinimas();
			zaidejas.SumetamLaivus();

			cpu.Nunulinimas();
			cpu.SumetamLaivus();

			zaidejoLenta.DaromLentele();
			cpuLenta.DaromLentele();

			cout << "Jusu lenta: " << endl;
			zaidejoLenta.LentelesSpausdinimas();
			cout << "CPU lenta" << endl;
			cpuLenta.LentelesSpausdinimas();

			int position1, position2;
			char ff;
			int rastaLaivu = 0;
			int LikoRast = 10;

			int cpuRado = 0;
			int cpuLiko = 10;

			bool Pataike;
			bool CpuPataike;

			while (rastaLaivu < 10 || cpuRado < 10)
			{
				int cpuX = rand() % 10;
				int cpuY = rand() % 10;

				if (cpu.Puolimas(cpuX, cpuY))
				{
					CpuPataike = true;
					cpuRado++;
					cpuLiko--;
					cout << "CPU rado Jusu laiva kurio koordinates buvo: " << cpuX << " " << cpuY <<  endl;
				}
				else
				{
					CpuPataike = false;
					cout << "CPU nepataike" << endl;
				}

				position1 = 11;
				position2 = 11;

				while (position1 > 9 || position2 > 9)
				{
					if (cpuRado == 10 || rastaLaivu == 10)
					{
						break;
					}
					cout << "Spekite kur yra CPU laivas: ";

					cin >> position1 >> position2;
					while (cin.fail())
					{
						cin.clear();
						cin.ignore();
						cout << "Tokiu koordinaciu nera, bandykite dar karta: "; cin >> position1 >> position2;
					}
				}

				if (zaidejas.Puolimas(position1, position2))
				{
					Pataike = true;
					rastaLaivu++;
					LikoRast--;
					cout << "Jus radote: " << rastaLaivu << " jums liko rasti: " << LikoRast <<  endl;
				}
				else
				{
					Pataike = false;
					cout << "Sioje vietoje nera laivo" << endl;
				}

				cout << "Liko: " << zaidejas.LaivuSkaicius() << " laivai" << endl;
				cout << "ar norite pasiduoti (y/n)?: "; cin >> ff;

				system("CLS");

				zaidejoLenta.LentelesAtnaujinimas(Pataike, position1, position2);
				cpuLenta.LentelesAtnaujinimas(CpuPataike, cpuX, cpuY);

				cout << "Jusu lentele: " << endl;
				zaidejoLenta.LentelesSpausdinimas();
				cout << "CPU lentele" << endl;
				cpuLenta.LentelesSpausdinimas();

				if (ff == 'y')
				{
					break;
				}
				else if (rastaLaivu == 10 || cpuRado == 10)
				{
					break;
				}

			}
			cout << "Pabaiga!" << endl;
			cout << "Zaidejo lentele: " << endl;
			cout << "2 reiskia, kad laivas yra numustas" << endl;
			zaidejas.Tinklelis();
			cout << "----------------------------------------------------" << endl;
			cout << "CPU lentele" << endl;
			cpu.Tinklelis();

			cout << "Ar kartojam? (r/e)"; cin >> kartojam;
		} while (kartojam == 'r' || kartojam == 'R');
	}

	if (pasirinkimas == 2)
	{
		do
		{
			system("CLS");
			LaivuMusis zaidejas1;
			LaivuMusis zaidejas2;

			Lenteles zaidejas1lenta;
			Lenteles zaidejas2lenta;

			zaidejas1.Nunulinimas();
			zaidejas1.SumetamLaivus();

			zaidejas2.Nunulinimas();
			zaidejas2.SumetamLaivus();

			zaidejas1lenta.DaromLentele();
			zaidejas2lenta.DaromLentele();

			cout << "1 zaidejo lentele: " << endl;
			cout << endl;
			zaidejas1lenta.LentelesSpausdinimas();
			cout << endl;
			cout << "2 zaidejo lentele: " << endl;
			zaidejas2lenta.LentelesSpausdinimas();
			cout << endl;

			int position1, position2;
			int position3, position4;
			int z1rado = 0;
			int z1liko = 10;

			int z2rado = 0;
			int z2liko = 10;

			bool z1pataike;
			bool z2pataike;

			cout << "Pirmo zaidejo ataka: ";

			// zaidejo 1 ataka

			position1 = 11;
			position2 = 11;

			while (position1 > 9 || position2 > 9)
			{
				{
					if (z2rado == 10 || z1rado == 10)
					{
						break;
					}

					cin >> position1 >> position2;
					while (cin.fail()) {
						cin.clear();
						cin.ignore();
						cout << "netinkamos koordinates, bandykite dar karta: "; cin >> position1 >> position2;
					}
				}
				if (zaidejas1.Puolimas(position1, position2)) {
					z1pataike = true;
					z1rado++;
					z1liko--;
					cout << "jums liko " << z1rado << " liko " << z1liko << endl;
				}
				else
				{
					z1pataike = false;
					cout << "toje vietoje nera laivo" << endl;
				}
				cout << "Liko: " << zaidejas1.LaivuSkaicius() << " laivu" << endl;
					//}
					// zaidejo 1 ataka

					// zaidejo 2 ataka
				position3 = 11;
				position4 = 11;

					while (position3 > 9 || position4 > 9) 
					{
						if (z2rado == 10 || z1rado == 10)
						{
							break;
						}
						cout << "Antro zaidejo ataka: ";

						cin >> position3 >> position4;
						while (cin.fail()) {
							cin.clear();
							cin.ignore();
							cout << "netinkamos koordinates, bandykite dar karta: ";
							cin >> position3 >> position4;
						}
					}
					if (zaidejas2.Puolimas(position3, position4)) {
						z2pataike = true;
						z2rado++;
						z2liko--;
						cout << "jums liko " << z2rado << " liko " << z2liko << endl;
					}
					else
					{
						z2pataike = false;
						cout << "toje vietoje nera laivo" << endl;
					}
					cout << "Liko: " << zaidejas2.LaivuSkaicius() << " left" << endl;
					system("CLS");

					zaidejas1lenta.LentelesAtnaujinimas(z1pataike, position1, position2);
					zaidejas2lenta.LentelesAtnaujinimas(z2pataike, position3, position4);

					cout << "Jusu lentele: " << endl;
					zaidejas1lenta.LentelesSpausdinimas();
					cout << "CPU lentele" << endl;
					zaidejas2lenta.LentelesSpausdinimas();
					char ff{};

					if (ff == 'y')
					{
						break;
					}
					else if (z1rado == 10 || z2rado == 10)
					{
						break;
					}
			}
			cout << "Pabaiga!" << endl;
			cout << "Zaidejo 1 lentele: " << endl;
			cout << "2 reiskia, kad laivas yra numustas" << endl;
			zaidejas1.Tinklelis();
			cout << "----------------------------------------------------" << endl;
			cout << "Zaidejo 2 lentele: " << endl;
			zaidejas2.Tinklelis();

			cout << "Ar norite kartoti? (r/e)"; cin >> kartojam;
		} while (kartojam == 'r' || kartojam == 'R');
	}
		// zaidejo 2 ataka
	if (pasirinkimas == 3) {
		Taisykles();
	}

	system("pause");
}

	void Taisykles()
{
	cout << endl;
	cout << "Kaip zaisti su kompiuteriu" << endl;
	cout << endl;
	cout << "Pasirinkus zaisit su kompiuteriu Jums ir kompiuteriui bus atsitiktinai sudelioti laiveliai kurie uzima viena vieta" << endl;
	cout << "Jums su savo klavietura reikes ivesti langelio koordinates atskirtas tarpu, i kuria vieta norite sauti" << endl;
	cout << "Skaiciau negali buti maziau negu 0 ir daugiau negu 9" << endl;
	cout << endl;
	cout << "Zaidiant su draugu reikia susitarti kuris bus zaidejas numeris 1 ir kuris bus zaidejas numeris 2" << endl;
	cout << "Lentele atsinaujins abiems zaidejam ivykdzius savo atakas" << endl;
	main();
}