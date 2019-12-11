#pragma once

#include "matrix.h"
#include "Vector2.h"
#include "Vector"

struct Transform2D
{
	Vector2 position;
	Vector2 scale;
	Vector2 rotation;

	//Initial position
	Vector2 initPos;
	//Initial scale
	Vector2 initScale;
	//Initial rotation
	Vector2 initRotation;
};