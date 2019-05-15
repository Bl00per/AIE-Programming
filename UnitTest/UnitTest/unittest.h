#pragma once


// YOUR INCLUDES HERE
#include "matrix_3x3.h"
#include "matrix_4x4.h"
#include "vector_2.h"
#include "vector_3.h"
#include "vector_4.h"


// TYPEDEFS IF NEEDED
typedef vector_2 Vector2;
typedef vector_3 Vector3;
typedef vector_4 Vector4;
typedef matrix_3x3 Matrix3;
typedef matrix_4x4 Matrix4;

// IF YOU GAVE YOUR CLASSES STREAM OPERATORS YOU CAN UNCOMMENT THIS
//#define NO_DEFAULT_STREAM_OPERATOR

// tests the following:

// Vector2: dot(V2), V2 + V2, V2 - V2, V2 x float, float x V2, magnitude(), normalise(), [], (float*)
// Vector3: dot(V3), cross(V3), V3 + V3, V3 - V3, V3 x float, float x V3, magnitude(), normalise(), [], (float*)
// Vector4: dot(V4), cross(V4), V4 + V4, V4 - V4, V4 x float, float x V4, magnitude(), normalise(), [], (float*)
// Matrix2: setRotate(float), M2 x V2, [], (float*)
// Matrix3: setRotateX(float), setRotateY(float), setRotateZ(float), M3 x V3, [], (float*)
// Matrix4: setRotateX(float), setRotateY(float), setRotateZ(float), M4 x V4, [], (float*)

// returns true if all tests successful
bool runUnitTests();