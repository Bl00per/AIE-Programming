#include "EntityEditorApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

#include <imgui.h>
#include <Windows.h>
#include <iostream>


EntityEditorApp::EntityEditorApp() {

}

EntityEditorApp::~EntityEditorApp() {

}

bool EntityEditorApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);
	
	setBackgroundColour(1, 1, 1);

	for (int i = 0; i < ENTITY_COUNT; i++)
	{
		m_entities[i].x = 100 + i * 50;
		m_entities[i].y = 100 + i * 50;
		m_entities[i].size = 20;
	}

	// Stores how many elements are in the array
	sizeHandle = CreateFileMapping(
		INVALID_HANDLE_VALUE, // a handle to an existing virtual file, or invalid
		nullptr, // optional security attributes
		PAGE_READWRITE, // read/wrte access control
		0, sizeof(int), // size of the memory block,
		L"EntryCount");

	fileHandle = CreateFileMapping(
		INVALID_HANDLE_VALUE, // a handle to an existing virtual file, or invalid
		nullptr, // optional security attributes
		PAGE_READWRITE, // read/wrte access control
		0, sizeof(Entity) * ENTITY_COUNT, // size of the memory block,
		L"EditorSharedMemory");

	return true;
}

void EntityEditorApp::shutdown() {
	CloseHandle(fileHandle);
	CloseHandle(sizeHandle);
	delete m_font;
	delete m_2dRenderer;
}

void EntityEditorApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	// select an entity to edit
	static int selection = 0;
	ImGui::SliderInt("entry #", &selection, 0, ENTITY_COUNT - 1);
	ImGui::Separator();
	ImGui::BeginGroup();

	// display editable stats within a GUI
	ImGui::InputFloat("x", &m_entities[selection].x);
	ImGui::InputFloat("y", &m_entities[selection].y);
	ImGui::SliderAngle("rotation", &m_entities[selection].rotation);
	ImGui::SliderFloat("speed", &m_entities[selection].speed, 0, 1000);
	ImGui::ColorEdit3("colour", &m_entities[selection].r);
	ImGui::SliderFloat("size", &m_entities[selection].size, 0, 1000);
	ImGui::EndGroup();

	// move entities
	for (auto& entity : m_entities) {
		float s = sinf(entity.rotation) * entity.speed;
		float c = cosf(entity.rotation) * entity.speed;
		entity.x -= s * deltaTime;
		entity.y += c * deltaTime;

		// wrap position around the screen
		entity.x = fmod(entity.x, (float)getWindowWidth());
		if (entity.x < 0)
			entity.x += getWindowWidth();
		entity.y = fmod(entity.y, (float)getWindowHeight());
		if (entity.y < 0)
			entity.y += getWindowHeight();
	}

	int* sizeData = (int*)MapViewOfFile(sizeHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(int));
	*sizeData = ENTITY_COUNT;
	UnmapViewOfFile(sizeData);

	Entity* data = (Entity*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Entity) * ENTITY_COUNT);
	memcpy(data, m_entities, sizeof(Entity) * ENTITY_COUNT);
	UnmapViewOfFile(data);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void EntityEditorApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw entities
	for (auto& entity : m_entities) {
		m_2dRenderer->setRenderColour(entity.r, entity.g, entity.b);
		m_2dRenderer->drawBox(entity.x, entity.y, entity.size, entity.size, entity.rotation);
	}
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}