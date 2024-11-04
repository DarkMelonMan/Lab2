#pragma once

/// <summary>
/// ������������ ����� ���������� �����: �����������, �����, ����� � ������
/// </summary>

enum Element {
	none, fire, magic, lighting
};

/// <summary>
/// ������������ ����� �������: ����� ��������, ������ � �����
/// </summary>

enum EntityType {
	living, monster, player
};

/// <summary>
/// ��������� ���������� ������������ element
/// </summary>

static const char* elementNames[] = {
	"none", "fire", "magic", "lighting"
};

/// <summary>
/// ��������� ���������� ������������ entity
/// </summary>

static const char* entityTypes[] = {
	"living", "monster", "player"
};