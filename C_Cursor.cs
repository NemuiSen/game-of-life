using SFML.Graphics;
using SFML.System;

namespace Game_of_life
{
	class C_Cursor : Drawable
	{
		RectangleShape c_c;

		public Color color
		{
			get => c_c.OutlineColor;
			set => c_c.OutlineColor = value;
		}

		public void Draw(RenderTarget target, RenderStates states)
		{
			target.Draw(c_c, states);
		}


		public C_Cursor(float size, float grosor)
		{
			c_c = new RectangleShape(new Vector2f(size, size));
			c_c.OutlineThickness = grosor;
			c_c.FillColor = Color.Transparent;
			c_c.OutlineColor = Color.Red;
		}
		public void setPos(int x, int y)
		{
			int new_x = x/(int)c_c.Size.X;
			int new_y = y/(int)c_c.Size.X;
			c_c.Position = new Vector2f(new_x*c_c.Size.X, new_y*c_c.Size.X);
		}
	}
}
