#define _CRT_SECURE_NO_WARNINGS
#include "Classes.h"
#include "Structures.cpp"

void Entity::Hurt(double damage) {
	healthPoints -= damage;
	if (healthPoints <= 0) {
		healthPoints = 0;
		cout << endl << name << " entity is dead";
	}
}
LivingEntity& LivingEntity::operator=(const LivingEntity& entity)
{
	if (&entity != this) {
		name = entity.name;
		healthPoints = entity.healthPoints;
		movementSpeed = entity.movementSpeed;
	}
	return *this;
}
void LivingEntity::inputFields() {
	cout << endl << "Enter a name for a new entity: ";
	do {
		cin >> name;
		if (name.empty())
			cout << endl << "Invalid name. Try again: ";
	} while (name.empty());
	cout << endl << "Enter health points of " << name << " entity: ";
	do {
		cin >> healthPoints;
		if (healthPoints <= 0)
			cout << endl << "Invalid health points. Try again: ";
	} while (healthPoints <= 0);
	cout << endl << "Enter movement speed of " << name << " entity: ";
	do {
		cin >> movementSpeed;
		if (movementSpeed <= 0)
			cout << endl << "Invalid movement speed. Try again: ";
	} while (movementSpeed <= 0);
}

LivingEntity::LivingEntity(string name, double healthPoints, double movementSpeed) {
	this->name = name;
	this->healthPoints = healthPoints;
	this->movementSpeed = movementSpeed;
}

LivingEntity::LivingEntity() {
	healthPoints = 0;
	movementSpeed = 0;
	name = "";
}

double* Entity::GetHealthPoints()
{
	return &healthPoints;
}

void Armor::inputFields()
{
	int defenceType;
	cout << endl << "Enter base defence of a new armor (in %): ";
	do {
		cin >> baseDefence;
		if (baseDefence <= 0)
			cout << endl << "Invalid base defence. Try again: ";
	} while (baseDefence <= 0);
	cout << endl << "Enter elemental type of defence of a new armor (0 - none, 1 - fire, 2 - magic, 3 - lighting): ";
	do {
		cin >> defenceType;
		if (defenceType < 0 || defenceType > 3)
			cout << endl << "Invalid type of defence. Try again: ";
	} while (defenceType < 0 || defenceType > 3);
	this->defenceType = (Element)defenceType;
	if (this->defenceType != none) {
		cout << endl << "Enter elemental defence of a new armor (in %): ";
		do {
			cin >> elementDefence;
			if (elementDefence <= 0)
				cout << endl << "Invalid elemental defence. Try again: ";
		} while (elementDefence <= 0);
	}
	else elementDefence = 0;
	cout << endl << "New armor created!";
}

double Armor::GetBaseDefence()
{
	return baseDefence;
}
;

double Armor::GetElementDefence()
{
	return elementDefence;
}

Element Armor::GetDefenceType()
{
	return defenceType;
}

Armor::Armor()
{
	inputFields();
}

Armor::Armor(double baseDefence, double elementDefence, Element defenceType)
{
	this->baseDefence = baseDefence;
	this->defenceType = defenceType;
	if (this->defenceType != none)
		this->elementDefence = elementDefence;
	else this->elementDefence = 0;
}

Armor Armor::operator+(Armor& armor)
{
	double resultBaseDefence, resultElementDefence;
	Element resultDefenceType = none;
	if (baseDefence + armor.baseDefence < 100)
		resultBaseDefence = baseDefence + armor.baseDefence;
	else
		resultBaseDefence = 99;
	if (defenceType == armor.defenceType) {
		resultElementDefence = elementDefence + armor.elementDefence;
		resultDefenceType = defenceType;
	}
	else if (elementDefence > armor.elementDefence) {
		resultElementDefence = elementDefence;
		resultDefenceType = defenceType;
	}
	else {
		resultElementDefence = armor.elementDefence;
		resultDefenceType = armor.defenceType;
	}
	return Armor(resultBaseDefence, resultElementDefence, resultDefenceType);
}

Armor Armor::operator ++ ()
{
	if (baseDefence + 1 < 100)
		baseDefence++;
	if (elementDefence + 1 < 100)
		elementDefence++;
	return *this;
}

Armor Armor::operator ++ (int)
{
	Armor oldArmor = Armor(baseDefence, elementDefence, defenceType);
	if (baseDefence + 1 < 100)
		baseDefence++;
	if (elementDefence + 1 < 100)
		elementDefence++;
	return oldArmor;
}

Weapon::Weapon(double baseDamage, double elementDamage, Element damageType) {
	this->baseDamage = baseDamage;
	this->damageType = damageType;
	if (this->damageType != none)
		this->elementDamage = elementDamage;
	else this->elementDamage = 0;
}

void Weapon::inputFields() {
	int damageType;
	cout << endl << "Enter base damage of a new weapon: ";
	do {
		cin >> baseDamage;
		if (baseDamage <= 0)
			cout << endl << "Invalid base damage. Try again: ";
	} while (baseDamage <= 0);
	cout << endl << "Enter elemental type of damage of a new weapon (0 - none, 1 - fire, 2 - magic, 3 - lighting): ";
	do {
		cin >> damageType;
		if (damageType < 0 || damageType > 3)
			cout << endl << "Invalid type of damage. Try again: ";
	} while (damageType < 0 || damageType > 3);
	this->damageType = (Element)damageType;
	if (this->damageType != none) {
		cout << endl << "Enter elemental damage of a new weapon: ";
		do {
			cin >> elementDamage;
			if (elementDamage <= 0)
				cout << endl << "Invalid elemental damage. Try again: ";
		} while (elementDamage <= 0);
	}
	else elementDamage = 0;
	cout << endl << "New weapon created!";
}

Weapon::Weapon() {
	inputFields();
}

double Weapon::GetBaseDamage()
{
	return baseDamage;
}

double Weapon::GetElementDamage()
{
	return elementDamage;
}

double Weapon::GetDamageType()
{
	return damageType;
}

void MonsterEntity::inputFields() {
	LivingEntity::inputFields();
	int weakness;
	int damageType;
	cout << endl << "Enter base damage of " << name << " monster entity: ";
	do {
		cin >> baseDamage;
		if (baseDamage <= 0)
			cout << endl << "Invalid base damage. Try again: ";
	} while (baseDamage <= 0);
	cout << endl << "Enter elemental weakness of " << name << " monster entity (0 - none, 1 - fire, 2 - magic, 3 - lighting): ";
	do {
		cin >> weakness;
		if (weakness < 0 || weakness > 3)
			cout << endl << "Invalid weakness type. Try again: ";
	} while (weakness < 0 || weakness > 3);
	this->weakness = (Element)weakness;
	cout << endl << "Enter elemental type of damage of " << name << " monster entity (0 - none, 1 - fire, 2 - magic, 3 - lighting): ";
	do {
		cin >> damageType;
		if (damageType < 0 || damageType > 3)
			cout << endl << "Invalid type of damage. Try again: ";
	} while (damageType < 0 || damageType > 3);
	this->damageType = (Element)damageType;
	if (this->damageType != none) {
		cout << endl << "Enter elemental damage of " << name << " monster entity: ";
		do {
			cin >> elementDamage;
			if (elementDamage <= 0)
				cout << endl << "Invalid elemental damage. Try again: ";
		} while (elementDamage <= 0);
	}
	else elementDamage = 0;
	cout << endl << name << " monster entity created!";
}

MonsterEntity::MonsterEntity() {
	inputFields();
}

MonsterEntity::MonsterEntity(string name, double healthPoints, double movementSpeed, 
	double baseDamage, double elementDamage, Element weakness, Element damageType) : LivingEntity(name, healthPoints, movementSpeed) {
	this->baseDamage = baseDamage;
	if (damageType != none)
		this->elementDamage = elementDamage;
	else this->elementDamage = 0;
	this->weakness = weakness;
	this->damageType = damageType;
}

PlayerEntity::PlayerEntity() {
	inputFields();
}

void PlayerEntity::inputFields() {
	LivingEntity::inputFields();
	weapon = new Weapon();
	armor = new Armor();
	cout << endl << name << " player entity created!";
}

PlayerEntity::PlayerEntity(string name, double healthPoints, double movementSpeed, Armor* armor, Weapon* weapon) : LivingEntity(name, healthPoints, movementSpeed) {
	this->armor = armor;
	this->weapon = weapon;
}

Armor* PlayerEntity::GetArmor() {
	return this->armor;
}

Weapon* PlayerEntity::GetWeapon()
{
	return this->weapon;
}

ostream& operator<<(ostream& os, const LivingEntity& livingEntity)
{
	os << endl << endl << livingEntity.name << " entity:";
	os << endl << "Health points: " << livingEntity.healthPoints;
	os << endl << "Movement speed: " << livingEntity.movementSpeed;
	return os;
}

ostream& operator<<(ostream& os, const Weapon& weapon)
{
	os << endl << "Player weapon:";
	os << endl << "Base damage: " << weapon.baseDamage;
	os << endl << "Elemental type of damage: " << elementNames[(int)weapon.damageType];
	os << endl << "Elemental damage: " << weapon.elementDamage;
	return os;
}

void AttackMonster(PlayerEntity& player, MonsterEntity& monster)
{
	double damage = player.weapon->GetBaseDamage();
	if (monster.GetMonsterWeakness() == player.weapon->GetDamageType() && monster.GetMonsterWeakness() != none)
		damage += player.weapon->GetElementDamage();
	else if (monster.GetMonsterWeakness() != none)
		damage += player.weapon->GetElementDamage() * 0.5;
	monster.Hurt(damage);
}

ostream& operator<<(ostream& os, const Armor& armor)
{
	os << endl << "Player armor:";
	os << endl << "Base defence: " << armor.baseDefence << "%";
	os << endl << "Elemental type of defence: " << elementNames[(int)armor.defenceType];
	cout << endl << "Elemental defence: " << armor.elementDefence << "%";
	return os;
}

void AttackPlayer(MonsterEntity& monster, PlayerEntity& player)
{
	double damage = monster.baseDamage * (1 - player.GetArmor()->GetBaseDefence() / 100);
	if (player.GetArmor()->GetDefenceType() == monster.damageType && monster.damageType != none)
		damage += monster.elementDamage * (1 - player.GetArmor()->GetElementDefence() / 100);
	else if (monster.damageType != none) damage += monster.elementDamage;
	player.Hurt(damage);
}

PlayerEntity& PlayerEntity::operator=(const PlayerEntity& entity) {
	if (this != &entity) {
		LivingEntity::operator=(entity);
		weapon = entity.weapon;
		armor = entity.armor;
	}
	return *this;
}

Element MonsterEntity::GetMonsterWeakness()
{
	return weakness;
}


ostream& operator<<(ostream& os, const MonsterEntity& monster)
{
	os << static_cast<const LivingEntity&>(monster) << endl;
	os << endl << "Base damage: " << monster.baseDamage;
	cout << endl << "Elemental type of damage: " << monster.damageType;
	cout << endl << "Elemental weakness type: " << monster.weakness;
	if (monster.damageType != none)
		cout << endl << "Elemental damage: " << monster.elementDamage;
	return os;
}

ostream& operator<<(ostream& os, const PlayerEntity& player)
{
	os << static_cast<const LivingEntity&>(player) << endl;
	os << static_cast<const Weapon&>(*player.weapon) << endl;
	os << static_cast<const Armor&>(*player.armor) << endl;
	return os;
}

int DamageTest::testChoice = 0;

void DamageTest::ChooseStruct()
{
	int choice;
	do {
		cout << endl << "Choose class type:" << endl << "1)MonsterEntity" << endl <<
			"2)PlayerEntity" << endl << "3)Exit" << endl;
		do {
			cin >> choice;
			if (choice < 1 || choice > 3)
				cout << "Wrong choice. Try again: " << endl;
		} while (choice < 1 || choice > 3);
		char* name1 = (char*)calloc(5, sizeof(char)); strcpy(name1, "Blob");
		char* name2 = (char*)calloc(4, sizeof(char)); strcpy(name2, "Ben");
		char* name3 = (char*)calloc(6, sizeof(char)); strcpy(name3, "Henry");
		char* name4 = (char*)calloc(6, sizeof(char)); strcpy(name4, "Harry");
		MonsterEntityStruct monster1 = monsterEntityCreateInstance(name1, 20, 1.5, 15, 8, fire, magic);
		MonsterEntityStruct monster2 = monsterEntityCreateInstance(name2, 20, 1.5, 15, 8, lighting, magic);
		PlayerEntityStruct player1 = playerEntityCreateInstance(name3, 20, 1, weaponCreateInstance(10, 10, fire), armorCreateInstance(10, 35, fire));
		PlayerEntityStruct player2 = playerEntityCreateInstance(name4, 25, 1, weaponCreateInstance(10, 10, magic), armorCreateInstance(10, 35, magic));
		switch (choice) {
		case 1:
			cout << "Damage system test: monster attacks player:" << endl;
			monsterEntityAttack(monster1, player1);
			if (*player1.entity.healthPoints + 0.00001 > 1.3 && *player1.entity.healthPoints - 0.00001 < 1.3)
				cout << endl << "Test 1 was successful";
			else
				throw TestError(*player1.entity.healthPoints, 1.3, "player health points");
			monsterEntityAttack(monster2, player2);
			if (*player2.entity.healthPoints + 0.00001 > 3.5 && *player2.entity.healthPoints - 0.00001 < 3.5)
				cout << endl << "Test 2 was successful";
			else
				throw TestError(*player2.entity.healthPoints, 3.5, "player health points");
			break;
		case 2:
			playerEntityAttack(player1, monster1);
			// Урон = 20 - 10 - 10 * 0.5 = 5
			if (*monster1.entity.healthPoints + 0.00001 > 5 && *monster1.entity.healthPoints - 0.00001 < 5)
				cout << endl << "Test 1 was successful";
			else
				throw TestError(*monster1.entity.healthPoints, 5, "monster health points");
			// Урон = 20 - 10 - 10 = 0
			playerEntityAttack(player2, monster2);
			if (*monster2.entity.healthPoints + 0.00001 > 0 && *monster2.entity.healthPoints - 0.00001 < 0)
				cout << endl << "Test 2 was successful";
			else
				throw TestError(*monster2.entity.healthPoints, 0, "monster health points");
			break;
		default:
			break;
		}
		free(name1); free(name2); free(name3); free(name4);
	} while (choice != 3);
}

template<typename TEntity>
size_t EntitiesManager<TEntity>::size = 0;

template<typename TEntity>
size_t EntitiesManager<TEntity>::capacity = 10;

template<typename TEntity>
EntitiesManager<TEntity>::EntitiesManager(){
	entities = new TEntity[capacity];
}

template<typename TEntity>
EntitiesManager<TEntity>::~EntitiesManager() {
	delete[] entities;
}

template<typename TEntity>
void EntitiesManager<TEntity>::resize(size_t n) {
	capacity += n;
	TEntity* newEntities = new TEntity[capacity];
	for (size_t i = 0; i < size; i++)
		newEntities[i] = entities[i];
	delete[] entities;
	entities = newEntities;
}

template<typename TEntity>
void EntitiesManager<TEntity>::addEntity(TEntity entity) {
	if (size == capacity) resize(1);
	entities[size++] = entity;
}

template<typename TEntity>
void EntitiesManager<TEntity>::removeEntity(size_t index) {
	if (index < size) {
		for (int i = index; i < size - 1; i++) {
			entities[i] = entities[i + 1];
		}
		size--;
	}
	else throw out_of_range("Index out of range");
}

template<typename TEntity>
TEntity EntitiesManager<TEntity>::getEntity(size_t index) {
	if (index < size)
		return entities[index];
	throw out_of_range("Index out of range");
}

template<typename TEntity>
size_t EntitiesManager<TEntity>::getSize() {
	return size;
}

void DamageTest::ChooseClass()
{
	int choice;
	do {
		cout << endl << "Choose class type:" << endl << "1)MonsterEntity" << endl <<
			"2)PlayerEntity" << endl << "3)Armor" << endl << "4)2d and 1d array" << endl << "5)EntitiesManager" << endl << "6)Exit" << endl;
		do {
			cin >> choice;
			if (choice < 1 || choice > 6)
				cout << "Wrong choice. Try again: " << endl;
		} while (choice < 1 || choice > 6);
		MonsterEntity* monster1 = new MonsterEntity("Blob", 20, 1.5, 15, 8, magic, fire);
		MonsterEntity* monster2 = new MonsterEntity("Ben", 20, 1.5, 15, 8, magic, lighting);
		PlayerEntity* player1 = new PlayerEntity("Henry", 20, 1, new Armor(10, 35, fire), new Weapon(10, 10, fire));
		PlayerEntity* player2 = new PlayerEntity("Harry", 25, 1, new Armor(10, 35, magic), new Weapon(10, 10, magic));
		Armor armor1 = Armor(10, 35, fire);
		Armor armor2 = Armor(95, 20, magic);
		Armor resArmor = Armor(0, 0, none);
		Armor resArmor2 = Armor(0, 0, none);
		EntitiesManager<LivingEntity>* manager = new EntitiesManager<LivingEntity>();
		LivingEntity objectsArray[4] = { LivingEntity("Blob", 10, 1.5), LivingEntity("Eddie", 35, 1), 
			LivingEntity("Henry", 12, 2), LivingEntity("Ben", 43, 1) };
		LivingEntity objectsMatrix[2][2] = { LivingEntity("Blob", 10, 1.5), LivingEntity("Eddie", 35, 1), 
			LivingEntity("Henry", 12, 2), LivingEntity("Ben", 43, 1) };
		PlayerEntity henry = PlayerEntity("Henry", 20, 1, new Armor(10, 35, fire), new Weapon(10, 10, fire));
		LivingEntity blob = LivingEntity("Blob", 10, 1.5);
		blob = henry;
		switch (choice) {
		case 1:
			cout << "Damage system test: monster attacks player:" << endl;
			AttackPlayer(*monster1, *player1);
			if (*player1->GetHealthPoints() + 0.00001 > 1.3 && *player1->GetHealthPoints() - 0.00001 < 1.3)
				cout << endl << "Test 1 was successful";
			else
				throw TestError(*player1->GetHealthPoints(), 1.3, "player health points");
			AttackPlayer(*monster2, *player2);
			if (*player2->GetHealthPoints() + 0.00001 > 3.5 && *player2->GetHealthPoints() - 0.00001 < 3.5)
				cout << endl << "Test 2 was successful";
			else
				throw TestError(*player2->GetHealthPoints(), 3.5, "player health points");
			break;
		case 2:
			cout << "Damage system test: player attacks monster:" << endl;
			AttackMonster(*player1, *monster1);
			// Урон = 20 - 10 - 10 * 0.5 = 5
			if (*monster1->GetHealthPoints() + 0.00001 > 5 && *monster1->GetHealthPoints() - 0.00001 < 5)
				cout << endl << "Test 1 was successful";
			else
				throw TestError(*monster1->GetHealthPoints(), 5, "monster health points");
			// Урон = 20 - 10 - 10 = 0
			AttackMonster(*player2, *monster2);
			if (*monster2->GetHealthPoints() + 0.00001 > 0 && *monster2->GetHealthPoints() - 0.00001 < 0)
				cout << endl << "Test 2 was successful";
			else
				throw TestError(*monster2->GetHealthPoints(), 0, "monster health points");
			break;
		case 3:
			resArmor = armor1 + armor2;
			if (resArmor.GetBaseDefence() + 0.00001 > 99 && resArmor.GetBaseDefence() - 0.00001 < 99 &&
				resArmor.GetElementDefence() + 0.00001 > 35 && resArmor.GetElementDefence() - 0.00001 < 35 && resArmor.GetDefenceType() == fire)
				cout << endl << "Test 1 was successful";
			else {
				throw TestError(resArmor.GetBaseDefence(), 99, "result armor base defence");
				throw TestError(resArmor.GetElementDefence(), 35, "result armor element defence");
				throw TestError(resArmor.GetDefenceType(), fire, "result armor defence type");
			}
			++armor1;
			if (armor1.GetBaseDefence() + 0.00001 > 11 && armor1.GetBaseDefence() - 0.00001 < 11)
				cout << endl << "Test 2 was successful";
			else {
				throw TestError(armor1.GetBaseDefence(), 11, "result armor base defence");
			}
			resArmor2 = armor1++;
			if (resArmor2.GetBaseDefence() + 0.00001 > 11 && resArmor2.GetBaseDefence() - 0.00001 < 11)
				cout << endl << "Test 3 was successful";
			else {
				throw TestError(resArmor2.GetBaseDefence(), 11, "result armor base defence");
			}
			break;
		case 4:
			cout << endl << endl << "Matrix: " << endl;
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					cout << objectsMatrix[i][j];
			cout << endl << endl << "Array: " << endl;
			for (int i = 0; i < 4; i++)
				cout << objectsArray[i];
			break;
		case 5:
			manager->addEntity(*monster1);
			manager->addEntity(*monster2);
			manager->addEntity(*player1);
			manager->addEntity(*player2);
			cout << endl << "Entities manager contains (before removing):" << endl << endl;
			for (int i = 0; i < 4; i++) {
				cout << manager->getEntity(i) << endl;
			}
			manager->removeEntity(2);
			cout << endl << "Entities manager contains (after removing):" << endl << endl;
			for (int i = 0; i < 3; i++) {
				cout << (i + 1) + ") ";
				cout << manager->getEntity(i) << endl;
			}
			break;
		default:
			break;
		}
	} while (choice != 6);
}
