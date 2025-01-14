#pragma once
#include "Component.h"
class Texture2D;
class Color;

class SpriteComponent :
	public Component
{
public:
	/// <param name="texture">Sets the sprites image to be this texture</param>
	/// <param name="name">The name of the component instance</param>
	SpriteComponent(Texture2D* texture);

	/// <param name="path">The path of the texture to load</param>
	/// <param name="name"></param>
	SpriteComponent(const char* path);

	~SpriteComponent() override;

	int getHeight() { return m_height; }
	int getWidth() { return m_width; }
	void setColor(Color color);
	void draw() override;

	void setPath(const char* path);

private:
	Texture2D* m_texture;
	Color* m_color;
	int m_width;
	int m_height;
};

