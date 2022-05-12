#include <iostream>
#include <string>
#include <fstream>
#include <limits>
using namespace std;

struct Course

{

	char Title[20]; 

	int Price; 

	int Time_For_Preparing;   

	
	

	void print()

	{
		
		
			cout << "Название блюда: " << Title << endl;

			cout << "Цена блюда: " << Price << endl;

			cout << "Время приготовления: " << Time_For_Preparing << endl;
	
			ofstream gg("res.txt",ofstream::app);
			gg << Title << ' ' << Price << ' ' << Time_For_Preparing << ' ' << endl;
			gg.close();
		


	}


};


void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int main()

{

	setlocale(LC_ALL, "rus");

	bool abc = true;
	
	int size = 0;

	while(abc)
	{ 

	cout << "Введите размер массива Course: " << endl;

	
		cin >> size;
		if (std::cin.fail()) 
		{
			
			std::cin.clear(); 
			ignoreLine();     
			std::cout << "Введите целочисленную длину массива!\n\n";

		}
		else
		{
			abc = false;
			 

			
		}
     }

	Course** A = new Course * [size];
	for (int i = 0; i < size; i++)

	{
		A[i] = new Course;
	}
	for (int i = 0; i < size; i++)

	{
		abc = true;
		

		cout << "Введите название блюда " << i + 1 << ":";

		cin >> A[i]->Title;




		


	
		abc = true;
		


		while (abc)
		{

			cout << "Введите цену блюда " << i + 1 << ":";


			cin >> A[i]->Price;
			if (std::cin.fail())
			{

				std::cin.clear();
				ignoreLine();
				std::cout << "Введите целочисленную цену блюда\n\n";

			}
			else
			{
				abc = false;
				


			}
		}


		abc = true;

		//

		while (abc)
		{

			cout << "Введите время приготовления " << i + 1 << ":";


			cin >> A[i]->Time_For_Preparing;
			if (std::cin.fail())
			{

				std::cin.clear();
				ignoreLine();
				std::cout << "Введите время приготовления в минутах\n\n";

			}
			else
			{
				abc = false;



			}
		}





	}

	Course* swap;

	for (int i = 0; i < size; i++)
	{

		for (int j = i + 1; j < size; j++)
		{



			if (A[i]->Time_For_Preparing > A[j]->Time_For_Preparing)

			{
				swap = A[i];

				A[i] = A[j];

				A[j] = swap;
			}




			if (A[i]->Price > A[j]->Price)
			{
				swap = A[i];

				A[i] = A[j];

				A[j] = swap;

			}




		};
	}

	for (int i = 0; i < size; i++)

	{


		A[i]->print();


	}




	return 0;

}
