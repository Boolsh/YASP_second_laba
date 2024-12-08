//Создать класс Angle для работы с углами на плоскости, задаваемыми величиной
//в градусах и минутах.Обязательно должны быть реализованы : перевод в радианы,
//приведение к диапазону 0 - 360, увеличение и уменьшение угла на заданную
//величину, получение синуса, сравнение углов, сложение углов, умножение угла
//на вещественное число.
// Пекшин Степан 9 группа


#include "Angle.h"
#include <fstream>
template<typename T>
T read_and_check();

void input_change(bool x, Angle& angle);
int angle_choice();
int main_menu();
int input_menu();
int output_menu();
int check_file(std::ifstream& file);
void input_angle(Angle& angle);

int main()
{
	setlocale(LC_ALL, "RU");

	int choice;
	int option_choice;
	Angle angle1;
	Angle angle2;


	do {
		choice = main_menu();
		switch (choice)
		{
		case 0://напечататть угол
		{
			int out_choice = output_menu();
			if (out_choice == 1)
			{
				std::string file_name;
				std::cout << "Введите имя файла ";
				file_name = read_and_check<std::string>();
				std::ofstream file(file_name);
				if (angle_choice() == 1)
					angle1.print("", file);
				else
					angle2.print("", file);
			}
			else
			{
				if (angle_choice() == 1)
					angle1.print("", std::cout);
				else
					angle2.print("", std::cout);
			}
			break;
		}
		case 1:
		{
			input_angle(angle1);
			break;
		}
		case 2:
		{
			input_angle(angle2);
			break;
		}
		case 3: //to radiance
		{
			angle_choice() == 1 ? std::cout << angle1.to_radians() << std::endl : std::cout << angle2.to_radians()
				<< std::endl;
			break;

		}
		case 4: //to 360
		{
			if (angle_choice() == 1)
			{
				angle1.to_360();
				angle1.print("Приведенный угол ", std::cout);
			}
			else
			{
				angle2.to_360();
				angle2.print("Приведенный угол ", std::cout);
			}
			break;
		}
		case 5: //up
		{
			if (angle_choice() == 1)
			{

				input_change(1, angle1);
				angle1.print("Угол после апа ", std::cout);
			}
			else
			{
				input_change(1, angle2);
				angle2.print("Угол после апа ", std::cout);
			}
		}
		break;
		case 6: //down
		{
			if (angle_choice() == 1)
			{

				input_change(0, angle1);
				angle1.print("Угол после дауна ", std::cout);
			}
			else
			{
				input_change(0, angle2);
				angle2.print("Угол после дауна ", std::cout);
			}
			break;
		}
		case 7: //sin
		{
			angle_choice() == 1 ? std::cout << angle1.get_sin() << std::endl : std::cout << angle2.get_sin() << std::endl;

			break;
		}
		break;
		case 8: //sravnenie
		{
			if (angle1 > angle2) std::cout << "Угол А > Угол В\n";
			else if (angle1 < angle2) std::cout << "Угол А < Угол В";
			else std::cout << "Угол А == Угол В";
			break;
		}
		case 9: //*float
		{
			std::cout << "на какое число умножить->";
			double a;
			a = read_and_check<double>();
			if (angle_choice() == 1)
			{
				angle1* a;
				angle1.print("угол после умножения", std::cout);

			}
			else
			{
				angle2* a;
				angle2.print("угол после умножения", std::cout);
			}
			break;
		}
		case 10: //сложить два угла
		{
			angle1 + angle2;
			angle1.print("Угол 1 после сложения", std::cout);
			break;
		}
		case 11: //вычесть два угла
		{
			angle1 - angle2;
			angle1.print("Угол 1 после вычитания", std::cout);
			break;
		}
		}


	} while (choice != 12);




}


template<typename T>
T read_and_check() {
	T data;

	while (true) {
		std::cin >> data;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cout << "Ошибка ввода!\n";
		}
		else {
			return data;
		}
	}
}

void input_change(bool x, Angle& angle)
{
	float adding_degrees, adding_minutes;
	std::cout << "Введите значения градусов и минут, на которые необходимо изменить угол\nГрадусы-> ";
	adding_degrees = read_and_check<float>();
	std::cout << "Минуты-> ";
	adding_minutes = read_and_check<float>();
	std::cout << std::endl;
	if (x) angle.angle_up(adding_degrees, adding_minutes);
	else angle.angle_down(adding_degrees, adding_minutes);

}

int angle_choice()
{
	std::cout << "Выберите угол\n";
	int choice;
	do {
		std::cout << "1.Угол А\n2.Угол В\n";
		choice = read_and_check<int>();
		if (!(choice == 1 || choice == 2)) std::cout << "Введите 1 или 2\n";
	} while (!(choice == 1 || choice == 2));
	return choice;

}

int input_menu()
{
	std::cout << "\n\nВыбор формата ввода\n";
	std::cout << "1. Заполнить из файла\n";
	std::cout << "2. Заполнить с клавиатуры\n";
	int choice;
	do {
		std::cout << "Введите цифру:";
		choice = read_and_check<int>();
	} while (!(choice >= 0 && choice <= 2));
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	return choice;
}

int output_menu()
{
	std::cout << "Куда вывести\n";
	std::cout << "1. Вывод в файл\n";
	std::cout << "2. Вывод в консоль\n";
	int choice;
	do {
		std::cout << "Введите цифр:";
		choice = read_and_check<int>();
	} while (!(choice >= 0 && choice <= 2));
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	return choice;
}

int check_file(std::ifstream& file)
{
	int res = 1;
	if (!file)
	{
		res = -1;
	}
	else
		if (file.peek() == EOF)
			res = 0;
	return res;
}

void input_angle(Angle& angle)
{
	int option_choice = input_menu();
	if (option_choice == 1)
	{
		std::string file_name;
		std::cout << "\nВведите имя файла: ";
		file_name = read_and_check<std::string>();
		std::ifstream file(file_name);
		switch (check_file(file))
		{
		case -1:
			std::cout << "Некорректное имя фала\n";
			break;
		case 0:
			std::cout << "Пустой файл\n";
			break;
		default:
			angle.fill(file);
			std::cout << "\nДанные получены\n";
		}
	}
	else
	{
		angle.fill(std::cin);
	}
}


//Создать класс Angle для работы с углами на плоскости, задаваемыми величиной
//в градусах и минутах.Обязательно должны быть реализованы : перевод в радианы,
//приведение к диапазону 0 - 360, увеличение и уменьшение угла на заданную
//величину, получение синуса, сравнение углов, сложение углов, умножение угла
//на вещественное число.
int main_menu()
{
	std::cout << "\nМеню\n";
	std::cout << "0. Напечатать угол\n";
	std::cout << "1. Заполнить угол А\n";
	std::cout << "2. Заполнить угол В\n";
	std::cout << "3. Показать значение в радианах\n";
	std::cout << "4. Привести к дипазону 0-360\n";
	std::cout << "5. Увеличить угол\n";
	std::cout << "6. Уменьшить угол\n";
	std::cout << "7. Получить синус\n";
	std::cout << "8. Сравнить углы\n";
	std::cout << "9. Умножить на вещественное число\n";
	std::cout << "10. Сложить углы\n";
	std::cout << "11. Вычесть углы\n";
	std::cout << "12. Выход\n";
	int choice;
	do {
		std::cout << "\nВведите пункт меню: ";
		choice = read_and_check<int>();
	} while (!(choice >= 0 && choice <= 12));
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	return choice;




}

