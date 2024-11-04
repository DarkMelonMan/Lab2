#pragma once
#include <iostream>
#include "Util.h"
using namespace std;

/// <summary>
/// ����� ����� �������, �������� ��� ������� �������� � �������
/// </summary>
class LivingEntity {
protected:
	string name;
	double healthPoints;
	double movementSpeed;

	/// <summary>
	/// �������� ����
	/// </summary>
	/// <param name="damage">���������� ������� ����</param>
	void hurt(double damage);
	
	/// <summary>
	/// ���� ���� �����
	/// </summary>
	void inputLivingEntityFields();

public:
	
	LivingEntity(string name, double healthPoints, double movementSpeed);
	LivingEntity();
	~LivingEntity() {};

	/// <summary>
	/// ����� �� ����� ���� �����
	/// </summary>
	void Print();

	/// <summary>
	/// �������� ���������� ����� ��������
	/// </summary>
	/// <returns>���������� ����� ��������</returns>
	double GetHealthPoints();
};

/// <summary>
/// ����� ����� ������
/// </summary>
class Armor {
private:
	double baseDefence;
	double elementDefence;
	Element defenceType;
	/// <summary>
	/// ���� ���� �����
	/// </summary>
	void inputArmorFields();
public:
	/// <summary>
	/// �������� ���������� ����� � ������ ����������� �����
	/// </summary>
	/// <returns>���������� ����� � ������ �����</returns>
	double GetActualDamage(double baseDamage, double elementDamage, Element damageType);
	
	Armor();
	Armor(double baseDefence, double elementDefence, Element defenceType);
	
	/// <summary>
	/// ����� �� ����� ���� �����
	/// </summary>
	void Print();
};

/// <summary>
/// ����� ������ ������
/// </summary>
class Weapon {
private:
	Element damageType;
	double baseDamage;
	double elementDamage;
	
	/// <summary>
	/// ���� ���� �����
	/// </summary>
	void inputWeaponFields();
public:
	Weapon(double baseDamage, double elementDamage, Element damageType);
	Weapon();

	/// <summary>
	/// �������� ����� ���������� �����
	/// </summary>
	/// <returns>����� ���������� �����</returns>
	double GetDamage(Element weakness);
	
	/// <summary>
	/// ����� ���� �����
	/// </summary>
	void Print();
};

/// <summary>
/// ����� ������� - �������� ����������
/// </summary>
class MonsterEntity;

/// <summary>
/// ����� ������
/// </summary>
class PlayerEntity : public LivingEntity {
private:
	Armor* armor;
	Weapon* weapon;

	/// <summary>
	/// ���� ���� �����
	/// </summary>
	void inputPlayerEntityFields();
public:
	PlayerEntity(string name, double healthPoints, double movementSpeed, Armor* armor, Weapon* weapon);
	PlayerEntity();

	/// <summary>
	/// �������� ������ ����� ������
	/// </summary>
	/// <returns>������ ����� ������</returns>
	Armor* GetArmor();
	
	/// <summary>
	/// �������� ������ ������ ������
	/// </summary>
	/// <returns>������ ������ ������</returns>
	Weapon* GetWeapon();

	/// <summary>
	/// �������� ����
	/// </summary>
	/// <param name="baseDamage">������� ����</param>
	/// <param name="elementDamage">��������� ����</param>
	/// <param name="damageType">��� ���������� �����</param>
	void Hurt(double baseDamage, double elementDamage, Element damageType);
	
	/// <summary>
	/// ��������� �������
	/// </summary>
	/// <param name="monster">��������� �� ������ �������</param>
	void AttackMonster(MonsterEntity* monster);
	
	/// <summary>
	/// ����� �� ����� ���� �����
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
	/// ���� ���� �����
	/// </summary>
	void inputMonsterEntityFields();
public:
	MonsterEntity(string name, double healthPoints, double movementSpeed, double baseDamage, double elementDamage, Element weakness, Element damageType);
	MonsterEntity();

	/// <summary>
	/// �������� ����
	/// </summary>
	/// <param name="damage">����� ���������� �����</param>
	void Hurt(double damage);
	
	/// <summary>
	/// ��������� ������
	/// </summary>
	/// <param name="player">��������� �� ������ ������</param>
	void AttackPlayer(PlayerEntity* player);
	
	/// <summary>
	/// ����� ���� ����� �� �����
	/// </summary>
	void Print();

	/// <summary>
	/// �������� ��������� �������� �������
	/// </summary>
	/// <returns>��������� �������� �������</returns>
	Element GetMonsterWeakness();
};

/// <summary>
/// ����� ��� �������� ������� �����
/// </summary>
static class DamageTest {
public:
	/// <summary>
	/// ����� ��������� ��� ������������ ������� �����
	/// </summary>
	static void ChooseStruct();
	
	/// <summary>
	/// ����� ������ ��� ������������ ������� �����
	/// </summary>
	static void ChooseClass();

	/// <summary>
	/// ����� �������� ������������ ������� �����: ������������ �������� ��� �������
	/// </summary>
	static void ChooseTestType();
};
