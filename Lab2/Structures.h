#pragma once
#include "Util.h"

/// <summary>
/// ��������� ����� �������, ����� ������������ ���� ����� ��������
/// � ����������� ���� �������� ������������
/// </summary>

struct LivingEntityStruct {
	char* name = 0;
	double* healthPoints = 0;
	double movementSpeed;
};

/// <summary>
/// ��������� ��������, ����������: ���� ������ ��������, �������� �����, 
/// ���������� �����, ���������� � ����������� ������ � ���� �������������� �����.
/// </summary>

struct MonsterEntityStruct {
	LivingEntityStruct entity;
	double baseDamage;
	double elementDamage;
	Element weakness;
	Element damageType;
};

/// <summary>
/// ��������� �����, ����������: ���� ������� ������, ��������� ������
/// � ���� ��������� ������
/// </summary>


struct ArmorStruct {
	double baseDefence;
	double elementDefence;
	Element defenceType;
};

/// <summary>
/// ��������� ������, ����������: ���� �������� �����, ���������� �����
/// � ���� ���������� �����
/// </summary>

struct WeaponStruct {
	Element damageType;
	double baseDamage;
	double elementDamage;
};

/// <summary>
/// ��������� ������, ���������� ����: ����� ��������, ����� � ������
/// </summary>

struct PlayerEntityStruct {
	LivingEntityStruct entity;
	ArmorStruct equippedArmor;
	WeaponStruct equippedWeapon;
};

/// <summary>
/// ������� �������� ����� ����� ��������
/// </summary>

static LivingEntityStruct livingEntityCreateInstance(char* name, double healthPoints, double movementSpeed);

/// <summary>
/// ������� ����� ����� ����� ��������
/// </summary>

static LivingEntityStruct livingEntityInput(EntityType type);

/// <summary>
/// ������� ������ ����� ����� ��������
/// </summary>

static void livingEntityOutput(LivingEntityStruct livingEntity);

/// <summary>
/// ������� ��������� ����� ����� ���������
/// </summary>

static void livingEntityHurt(LivingEntityStruct livingEntity, double damage);

/// <summary>
/// ������� �������� ��������, ���� �� ���
/// </summary>

static int isDead(LivingEntityStruct livingEntity);

/// <summary>
/// ������� �������� ������ �������
/// </summary>

static MonsterEntityStruct monsterEntityCreateInstance(char* name, double healthPoints, double movementSpeed, double baseDamage, double elementDamage, Element damageType, Element weakness);

/// <summary>
/// ������� ����� ����� �������
/// </summary>

static MonsterEntityStruct monsterEntityInput();

/// <summary>
/// ������� ��������� ����� ��������
/// </summary>

static void monsterEntityHurt(MonsterEntityStruct monster, double baseDamage, double elementDamage, Element damageType);

/// <summary>
/// ������� ����� �������� ������
/// </summary>

static void monsterEntityAttack(MonsterEntityStruct monster, PlayerEntityStruct player);

/// <summary>
/// ������� ������ ����� �������
/// </summary>

static void monsterEntityOutput(MonsterEntityStruct monsterEntity);

/// <summary>
/// ������� �������� ����� �����
/// </summary>

static ArmorStruct armorCreateInstance(double baseDefence, double elementDefence, Element defenceType);

/// <summary>
/// ������� ����� ����� �����
/// </summary>

static ArmorStruct armorInput();

/// <summary>
/// ������� ������ ����� �����
/// </summary>

static void armorOutput(ArmorStruct armor);

/// <summary>
/// ������� �������� ������ ������
/// </summary>

static WeaponStruct weaponCreateInstance(double baseDamage, double elementDamage, Element damageType);

/// <summary>
/// ������� ����� ����� ������
/// </summary>

static WeaponStruct weaponInput();

/// <summary>
/// ������� ������ ����� ������
/// </summary>

static void weaponOutput(WeaponStruct weapon);

/// <summary>
/// ������� �������� ������ ������
/// </summary>

static PlayerEntityStruct playerEntityCreateInstance(char* name, double healthPoints, double movementSpeed, WeaponStruct equippedWeapon, ArmorStruct equippedArmor);

/// <summary>
/// ������� ����� ����� ������
/// </summary>

static PlayerEntityStruct playerEntityInput();

/// <summary>
/// ������� ������ ����� ������
/// </summary>

static void playerEntityOutput(PlayerEntityStruct entity);

/// <summary>
/// ������� ��������� ����� �������
/// </summary>

static void playerEntityHurt(PlayerEntityStruct player, double damage);

/// <summary>
/// ������� ����� ������� �������
/// </summary>

static void playerEntityAttack(PlayerEntityStruct player, MonsterEntityStruct monster);