#pragma once
#include <iostream>
#include "Util.h"
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
	/// Получить урон
	/// </summary>
	/// <param name="damage">Получаемый игроком урон</param>
	void hurt(double damage);
	
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
	double GetHealthPoints();
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
	/// Получить количество урона с учётом показателей брони
	/// </summary>
	/// <returns>Количество урона с учётом брони</returns>
	double GetActualDamage(double baseDamage, double elementDamage, Element damageType);
	
	Armor();
	Armor(double baseDefence, double elementDefence, Element defenceType);
	
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
	/// Получить общее количество урона
	/// </summary>
	/// <returns>Общее количество урона</returns>
	double GetDamage(Element weakness);
	
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
	/// Получить урон
	/// </summary>
	/// <param name="baseDamage">Базовый урон</param>
	/// <param name="elementDamage">Стихийный урон</param>
	/// <param name="damageType">Тип стихийного урона</param>
	void Hurt(double baseDamage, double elementDamage, Element damageType);
	
	/// <summary>
	/// Атаковать монстра
	/// </summary>
	/// <param name="monster">Указатель на объект монстра</param>
	void AttackMonster(MonsterEntity* monster);
	
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
	/// Получить урон
	/// </summary>
	/// <param name="damage">Общее количество урона</param>
	void Hurt(double damage);
	
	/// <summary>
	/// Атаковать игрока
	/// </summary>
	/// <param name="player">Указатель на объект игрока</param>
	void AttackPlayer(PlayerEntity* player);
	
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
	/// Выбор варианта тестирования системы урона: тестирование структур или классов
	/// </summary>
	static void ChooseTestType();
};
