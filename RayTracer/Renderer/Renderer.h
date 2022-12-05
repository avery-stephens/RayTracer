#pragma once
#include "Canvas.h"
#include <SDL.h>
#include "../Math/Ray.h"
#include "../Objects/Object.h"

class Renderer
{
public:
	Renderer() = default;
	bool Initialize(); 
	void Shutdown(); 
	bool CreateWindow(int width, int height);

	void CopyCanvas(const Canvas& canvas);
	void Present();

	void Render(Canvas& canvas, Object* object);

	friend class Canvas;

private:
	SDL_Window* m_window{ nullptr };
	SDL_Renderer* m_renderer{ nullptr };
	color3 GetBackgroundFromRay(const Ray& ray);
};