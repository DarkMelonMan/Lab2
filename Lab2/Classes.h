#pragma once
#include <iostream>
#include "Util.h"
#include <string>
using namespace std;

/// <summary>
/// Класс живых существ, надкласс для классов монстров и игроков
/// </summary>
class LivingEntity {
protected:
	string name;
	double healthPoints;
	double movementSpeed;
	
	/// <summary>
	/// Ввод всех полей
	/// </summary>
	void inputLivingEntityFields();

public:
	LivingEntity(string name, double healthPoints, double movementSpeed);
	LivingEntity();
	~LivingEntity() {};

	/// <summary>
	/// Вывод на экран всех полей
	/// </summary>
	void Print();

	/// <summary>
	/// Получить количество очков здоровья
	/// </summary>
	/// <returns>Количество очков здоровья</returns>
	double* GetHealthPoints();

	/// <summary>
	/// Получить урон
	/// </summary>
	/// <param name="damage">Получаемый игроком урон</param>
	void Hurt(double damage);
};

/// <summary>
/// Класс брони игрока
/// </summary>
class Armor {
private:
	double baseDefence;
	double elementDefence;
	Element defenceType;
	/// <summary>
	/// Ввод всех полей
	/// </summary>
	void inputArmorFields();
public:

	/// <summary>
	/// Получить значение базовой защиты
	/// </summary>
	/// <returns>Значение базовой защиты брони</returns>
	double GetBaseDefence();

	/// <summary>
	/// Получить значение стихийной защиты
	/// </summary>
	/// <returns>Значение стихийной защиты брони</returns>
	double GetElementDefence();

	/// <summary>
	/// Получить тип стихийной защиты
	/// </summary>
	/// <returns>Тип стихийной защиты брони</returns>
	Element GetDefenceType();

	Armor();
	Armor(double baseDefence, double elementDefence, Element defenceType);
	
	Armor operator+(Armor& armor);

	Armor operator++();

	Armor operator++(int);



	/// <summary>
	/// Вывод на экран всех полей
	/// </summary>
	void Print();
};

/// <summary>
/// Класс оружия игрока
/// </summary>
class Weapon {
private:
	Element damageType;
	double baseDamage;
	double elementDamage;
	
	/// <summary>
	/// Ввод всех полей
	/// </summary>
	void inputWeaponFields();
public:
	Weapon(double baseDamage, double elementDamage, Element damageType);
	Weapon();

	/// <summary>
	/// Получить базовое количество урона
	/// </summary>
	/// <returns>Базовое количество урона</returns>
	double GetBaseDamage();

	/// <summary>
	/// Получить количество стихийного урона
	/// </summary>
	/// <returns>Количество стихийного урона</returns>
	double GetElementDamage();

	/// <summary>
	/// Получить тип стихийного урона
	/// </summary>
	/// <returns>Тип стихийного урона</returns>
	double GetDamageType();
	
	/// <summary>
	/// Вывод всех полей
	/// </summary>
	void Print();
};

/// <summary>
/// Класс монстра - игрового противника
/// </summary>
class MonsterEntity;

/// <summary>
/// Класс игрока
/// </summary>
class PlayerEntity : public LivingEntity {
private:
	Armor* armor;
	Weapon* weapon;

	/// <summary>
	/// Ввод всех полей
	/// </summary>
	void inputPlayerEntityFields();
public:
	PlayerEntity(string name, double healthPoints, double movementSpeed, Armor* armor, Weapon* weapon);
	PlayerEntity();

	/// <summary>
	/// Получить объект брони игрока
	/// </summary>
	/// <returns>Объект брони игрока</returns>
	Armor* GetArmor();
	
	/// <summary>
	/// Получить объект оружия игрока
	/// </summary>
	/// <returns>Объект оружия игрока</returns>
	Weapon* GetWeapon();
	
	/// <summary>
	/// Атаковать монстра
	/// </summary>
	/// <param name="monster">Указатель на объект монстра</param>
	friend void AttackMonster(PlayerEntity&, MonsterEntity&);
	
	/// <summary>
	/// Вывод на экран всех полей
	/// </summary>
	void Print();
};

class MonsterEntity : public LivingEntity {
private:
	double baseDamage;
	double elementDamage;
	Element weakness;
	Element damageType;
	
	/// <summary>
	/// Ввод всех полей
	/// </summary>
	void inputMonsterEntityFields();
public:
	MonsterEntity(string name, double healthPoints, double movementSpeed, double baseDamage, double elementDamage, Element weakness, Element damageType);
	MonsterEntity();
	
	/// <summary>
	/// Атаковать игрока
	/// </summary>
	/// <param name="player">Указатель на объект игрока</param>
	friend void AttackPlayer(MonsterEntity&, PlayerEntity&);
	
	/// <summary>
	/// Вывод всех полей на экран
	/// </summary>
	void Print();

	/// <summary>
	/// Получить стихийную слабость монстра
	/// </summary>
	/// <returns>Стихийная слабость монстра</returns>
	Element GetMonsterWeakness();
};

class TestError : public runtime_error {
public:
	TestError(double currentValue, double expectedValue, const char* currentValueName) : runtime_error("Current " + *currentValueName + to_string(currentValue) + ", but it must be " + to_string(expectedValue)) {
	};
};

/// <summary>
/// Класс для проверки системы урона
/// </summary>
static class DamageTest {
public:
	/// <summary>
	/// Выбор структуры для тестирования системы урона
	/// </summary>
	static void ChooseStruct();
	
	/// <summary>
	/// Выбор класса для тестирования системы урона
	/// </summary>
	static void ChooseClass();
	
	/// <summary>
	/// Поле, обозначающее вариант тестирования: тестирование структур или тестирование классов 
	/// </summary>
	static int testChoice;
};
