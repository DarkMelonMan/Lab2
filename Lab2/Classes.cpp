#define _CRT_SECURE_NO_WARNINGS
#include "Classes.h"
#include "Structures.cpp"

void LivingEntity::hurt(double damage) {
	healthPoints -= damage;
	if (healthPoints <= 0) {
		healthPoints = 0;
		cout << endl << name << " entity is dead";
	}
}
void LivingEntity::inputLivingEntityFields() {
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
	inputLivingEntityFields();
}

void LivingEntity::Print() {
	cout << endl << endl << name << " entity:";
	cout << endl << "Health points: " << healthPoints;
	cout << endl << "Movement speed: " << movementSpeed;
}

double LivingEntity::GetHealthPoints()
{
	return this->healthPoints;
}

void Armor::inputArmorFields()
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

double Armor::GetActualDamage(double baseDamage, double elementDamage, Element damageType) {
	double damage = baseDamage * (1 - this->baseDefence / 100);
	if (this->defenceType == damageType && damageType != none)
		damage += elementDamage * (1 - this->elementDefence / 100);
	else if (damageType != none) damage += elementDamage;
	return damage;
};

Armor::Armor()
{
	inputArmorFields();
}

Armor::Armor(double baseDefence, double elementDefence, Element defenceType)
{
	this->baseDefence = baseDefence;
	this->defenceType = defenceType;
	if (this->defenceType != none)
		this->elementDefence = elementDefence;
	else this->elementDefence = 0;
}

void Armor::Print()
{
	cout << endl << "Player armor:";
	cout << endl << "Base defence: " << this->baseDefence << "%";
	cout << endl << "Elemental type of defence: " << elementNames[(int)defenceType];
	cout << endl << "Elemental defence: " << this->elementDefence << "%";
}

Weapon::Weapon(double baseDamage, double elementDamage, Element damageType) {
	this->baseDamage = baseDamage;
	this->damageType = damageType;
	if (this->damageType != none)
		this->elementDamage = elementDamage;
	else this->elementDamage = 0;
}

void Weapon::inputWeaponFields() {
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
	inputWeaponFields();
}

double Weapon::GetDamage(Element weakness)
{
	double damage = baseDamage;
	if (weakness == damageType && weakness != none)
		damage += elementDamage;
	else if (weakness != none)
		damage += elementDamage * 0.5;
	return damage;
}

void Weapon::Print()
{
	cout << endl << "Player weapon:";
	cout << endl << "Base damage: " << this->baseDamage;
	cout << endl << "Elemental type of damage: " << elementNames[(int)damageType];
	cout << endl << "Elemental damage: " << this->elementDamage;
}

void MonsterEntity::inputMonsterEntityFields() {
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
	inputMonsterEntityFields();
}

 MonsterEntity::MonsterEntity(string name, double healthPoints, double movementSpeed, double baseDamage, double elementDamage, Element weakness, Element damageType): LivingEntity(name, healthPoints, movementSpeed) {
	this->baseDamage = baseDamage;
	if (damageType != none)
		this->elementDamage = elementDamage;
	else this->elementDamage = 0;
	this->weakness = weakness;
	this->damageType = damageType;
}

PlayerEntity::PlayerEntity() {
	 inputPlayerEntityFields();
}

void PlayerEntity::inputPlayerEntityFields() {
	weapon = new Weapon();
	armor = new Armor();
	cout << endl << name << " player entity created!";
}

PlayerEntity::PlayerEntity(string name, double healthPoints, double movementSpeed, Armor* armor, Weapon* weapon): LivingEntity(name, healthPoints, movementSpeed) {
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

void MonsterEntity::Hurt(double damage) {
	LivingEntity::hurt(damage);
}

void PlayerEntity::Hurt(double baseDamage, double elementDamage, Element damageType) {
	LivingEntity::hurt(this->GetArmor()->GetActualDamage(baseDamage, elementDamage, damageType));
}

void PlayerEntity::AttackMonster(MonsterEntity* monster)
{
	monster->Hurt(GetWeapon()->GetDamage(monster->GetMonsterWeakness()));
}

void PlayerEntity::Print()
{
	LivingEntity::Print();
	GetArmor()->Print();
	GetWeapon()->Print();
}

void MonsterEntity::AttackPlayer(PlayerEntity* player) {
	player->Hurt(this->baseDamage, this->elementDamage, this->damageType);
}

void MonsterEntity::Print(){
	LivingEntity::Print();
	cout << endl << "Base damage: " << baseDamage;
	cout << endl << "Elemental type of damage: " << damageType;
	cout << endl << "Elemental weakness type: " << weakness;
	if (damageType != none)
		cout << endl << "Elemental damage: " << elementDamage;
}

Element MonsterEntity::GetMonsterWeakness()
{
	return this->weakness;
}

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
				cout << endl << "Current player health points = " << *player1.entity.healthPoints
				<< " , but it must be 1,3. Test was unsuccessful";
			monsterEntityAttack(monster2, player2);
			if (*player2.entity.healthPoints + 0.00001 > 3.5 && *player2.entity.healthPoints - 0.00001 < 3.5)
				cout << endl << "Test 2 was successful";
			else
				cout << endl << "Current player health points = " << *player2.entity.healthPoints
				<< " , but it must be 3,5. Test was unsuccessful";
			break;
		case 2:
			playerEntityAttack(player1, monster1);
			// Урон = 20 - 10 - 10 * 0.5 = 5
			if (*monster1.entity.healthPoints + 0.00001 > 5 && *monster1.entity.healthPoints - 0.00001 < 5)
				cout << endl << "Test 1 was successful";
			else
				cout << endl << "Current monster health points = " << *monster1.entity.healthPoints
				<< " , but it must be 5. Test was unsuccessful";
			// Урон = 20 - 10 - 10 = 0
			playerEntityAttack(player2, monster2);
			if (*monster2.entity.healthPoints + 0.00001 > 0 && *monster2.entity.healthPoints - 0.00001 < 0)
				cout << endl << "Test 2 was successful";
			else
				cout << endl << "Current monster health points = " << *monster2.entity.healthPoints
				<< " , but it must be 0. Test was unsuccessful";
			break;
		default:
			break;
		}
		free(name1); free(name2); free(name3); free(name4);
	} while (choice != 3);
}

void DamageTest::ChooseClass()
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
		if (choice == 3)
			exit(0);
		MonsterEntity* monster1 = new MonsterEntity("Blob", 20, 1.5, 15, 8, magic, fire);
		MonsterEntity* monster2 = new MonsterEntity("Ben", 20, 1.5, 15, 8, magic, lighting);
		PlayerEntity* player1 = new PlayerEntity("Henry", 20, 1, new Armor(10, 35, fire), new Weapon (10, 10, fire));
		PlayerEntity* player2 = new PlayerEntity("Harry", 25, 1, new Armor(10, 35, magic), new Weapon(10, 10, magic));
		switch (choice) {
		case 1:
			cout << "Damage system test: monster attacks player:" << endl;
			monster1->AttackPlayer(player1);
			if (player1->GetHealthPoints() + 0.00001 > 1.3 && player1->GetHealthPoints() - 0.00001 < 1.3)
				cout << endl << "Test 1 was successful";
			else
				cout << endl << "Current player health points = " << player1->GetHealthPoints() 
				<< " , but it must be 1,3. Test was unsuccessful";
			monster2->AttackPlayer(player2);
			if (player2->GetHealthPoints() + 0.00001 > 3.5 && player2->GetHealthPoints() - 0.00001 < 3.5)
				cout << endl << "Test 2 was successful";
			else
				cout << endl << "Current player health points = " << player2->GetHealthPoints()
				<< " , but it must be 3,5. Test was unsuccessful";
			break;
		case 2:
			cout << "Damage system test: player attacks monster:" << endl;
			player1->AttackMonster(monster1);
			// Урон = 20 - 10 - 10 * 0.5 = 5
			if (monster1->GetHealthPoints() + 0.00001 > 5 && monster1->GetHealthPoints() - 0.00001 < 5)
				cout << endl << "Test 1 was successful";
			else
				cout << endl << "Current monster health points = " << monster1->GetHealthPoints()
				<< " , but it must be 5. Test was unsuccessful";
			// Урон = 20 - 10 - 10 = 0
			player2->AttackMonster(monster2);
			if (monster2->GetHealthPoints() + 0.00001 > 0 && monster2->GetHealthPoints() - 0.00001 < 0)
				cout << endl << "Test 2 was successful";
			else
				cout << endl << "Current monster health points = " << monster2->GetHealthPoints()
				<< " , but it must be 0. Test was unsuccessful";
			break;
		default:
			break;
		}
		
	} while (choice != 3);
}
void DamageTest::ChooseTestType(){
	int testChoice;
	do {
		cout << endl << "Choose test type:" << endl << "1)Structures" << endl <<
			"2)Classes" << endl << "3)Exit" << endl;
		do {
			cin >> testChoice;
			if (testChoice < 1 || testChoice > 3)
				cout << "Wrong choice. Try again: " << endl;
		} while (testChoice < 1 || testChoice > 3);
		if (testChoice == 3)
			exit(0);
		switch (testChoice) {
		case 1:
			DamageTest::ChooseStruct();
			break;
		case 2:
			DamageTest::ChooseClass();
			break;
		default:
			exit(0);
		}
	} while (testChoice != 3);

}