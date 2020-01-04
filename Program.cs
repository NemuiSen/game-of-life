using System;
using SFML.Window;
using SFML.Graphics;
using SFML.System;

namespace Game_of_life
{
	class Program
    {
		static Celulas gol;
		static C_Cursor cursor;
		static uint size = 16;
        static void Main(string[] args)
        {
			Vector2f celdas = new Vector2f(20, 30);

			uint w = 1000 / size;
			uint h = 700 / size;

			cursor = new C_Cursor(size, 5f);
			gol = new Celulas(w, h, size);

			VideoMode vm = new VideoMode(w*size, h*size);
            RenderWindow window = new RenderWindow(vm, "Game of Life");
			window.SetMouseCursorVisible(false);
			window.Closed += OnClose;
			window.KeyPressed += OnKeyPressed;
			window.MouseMoved += OnMouseMoved;
			window.MouseButtonPressed += OnMouseButtonPressed;

			Clock clock = new Clock();

			while (window.IsOpen)
			{
				window.DispatchEvents();

				if (clock.ElapsedTime.AsSeconds() > 0.6 / 10)
				{
					gol.Display();
					clock.Restart();
				}

				window.Clear();

				window.Draw(gol);
				window.Draw(cursor);

				window.Display();
			}
        }
		static void OnClose(object sender, EventArgs e)
		{
			Window window = (Window)sender;
			window.Close();
		}
		static void OnKeyPressed(object sender, KeyEventArgs e)
		{
			Window wnd = (Window)sender;
			if (e.Code == Keyboard.Key.Space)
			{
				gol.tick();
				
				if (cursor.color == Color.Red)
				{
					cursor.color = Color.Yellow;
				}
				else if (cursor.color == Color.Yellow)
				{
					cursor.color = Color.Red;
				}
			}
			if (e.Code == Keyboard.Key.C)
			{
				gol.Clear();
			}
			if (e.Code == Keyboard.Key.Escape)
			{
				wnd.Close();
			}
		}
		static void OnMouseMoved(object sender, MouseMoveEventArgs e)
		{
			cursor.setPos(e.X, e.Y);
		}
		static void OnMouseButtonPressed(object sender, MouseButtonEventArgs e)
		{
			if (e.Button == Mouse.Button.Left)
			{
				uint x = (uint)(e.X / size);
				uint y = (uint)(e.Y / size);
				gol.Click(x, y);
			}
		}
    }
}
