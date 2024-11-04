#pragma once

/// <summary>
/// ѕеречисление типов стихийного урона: нестихийный, огонь, маги€ и молни€
/// </summary>

enum Element {
	none, fire, magic, lighting
};

/// <summary>
/// ѕеречисление типов существ: живые существа, монстр и игрок
/// </summary>

enum EntityType {
	living, monster, player
};

/// <summary>
/// —троковые определни€ перечислени€ element
/// </summary>

static const char* elementNames[] = {
	"none", "fire", "magic", "lighting"
};

/// <summary>
/// —троковые определни€ перечислени€ entity
/// </summary>

static const char* entityTypes[] = {
	"living", "monster", "player"
};