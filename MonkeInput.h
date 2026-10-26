#pragma once

namespace ZeroGUI
{
	namespace Input
	{
		inline bool mouseDown[5]{};
		inline bool mouseDownAlready[256]{};
		inline bool keysDown[256]{};
		inline bool keysDownAlready[256]{};

		inline void SetMouseButtonState(int button, bool isDown)
		{
			if (button >= 0 && button < 5)
				mouseDown[button] = isDown;
		}

		inline void SetKeyState(int key, bool isDown)
		{
			if (key >= 0 && key < 256)
				keysDown[key] = isDown;
		}

		inline bool IsAnyMouseDown()
		{
			for (bool isDown : mouseDown)
			{
				if (isDown)
					return true;
			}
			return false;
		}

		inline bool IsMouseClicked(int button, int element_id, bool repeat)
		{
			if (button < 0 || button >= 5 || element_id < 0 || element_id >= 256)
				return false;

			if (mouseDown[button])
			{
				if (!mouseDownAlready[element_id])
				{
					mouseDownAlready[element_id] = true;
					return true;
				}
				return repeat;
			}

			mouseDownAlready[element_id] = false;
			return false;
		}

		inline bool IsKeyPressed(int key, bool repeat)
		{
			if (key < 0 || key >= 256)
				return false;

			if (keysDown[key])
			{
				if (!keysDownAlready[key])
				{
					keysDownAlready[key] = true;
					return true;
				}
				return repeat;
			}

			keysDownAlready[key] = false;
			return false;
		}
	}
}
