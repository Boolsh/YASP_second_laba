//Создать класс Angle для работы с углами на плоскости, задаваемыми величиной
//в градусах и минутах.Обязательно должны быть реализованы : перевод в радианы,
//приведение к диапазону 0 - 360, увеличение и уменьшение угла на заданную
//величину, получение синуса, сравнение углов, сложение углов, умножение угла
//на вещественное число.
// Пекшин Степан 9 группа


#include "Angle.h"


int main()
{
    setlocale(LC_ALL, "RU");

    Angle angle1(180);
    Angle angle2(180, 1);
    angle1.print("угол1");
    angle2.print("угол1");
    std::cout << "Sin = " << angle1.get_sin() << "\n";
    std::cout << "Sin = " << angle2.get_sin() << "\n";
    //angle1.to_360();
    //angle1.print("угол1 приведенный");
    //angle1.angle_up(15,63);
    //angle1.print("угол1 после апа");
    //angle1.angle_down(15,64);
    //angle1.print("угол1 после дауна");

    std::cout << "угол1 в радианах " << angle1.to_radians() << std::endl;
    std::cout << "угол2 в радианах " << angle2.to_radians() << std::endl;

    if (angle1 > angle2) std::cout << "angle1 > angle2\n";
    else if (angle1 < angle2) std::cout << "angle1 < angle2";
    else std::cout << "angle1 == angle2";
  




}

