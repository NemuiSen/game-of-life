using System;
using SFML.Graphics;
using SFML.System;

namespace Game_of_life
{
	class Celulas : Drawable
	{
		bool[] state;
		VertexArray g_cels;
		Vector2u cambas;
		float size;
		bool play = false;


		public void Draw(RenderTarget target, RenderStates states)
		{
			updateGraph();
			target.Draw(g_cels, states);
		}


		private uint getIndex(uint x, uint y)
		{
			return x + y * cambas.X;
		}
		private Vector2u getIndexPos(uint index)
		{
			uint x = index % cambas.X;
			uint y = (index - x) / cambas.X;
			return new Vector2u(x, y);
		}
		private void updateGraph()
		{
			for (uint i = 0; i < cambas.X * cambas.Y * 4; i += 4)
			{
				Color color = state[i/4] == false ? Color.Black : Color.White;

				Vector2u tp = getIndexPos(i/4);
				g_cels[ i ] = new Vertex(new Vector2f( tp.X   *size,  tp.Y   *size), color);
				g_cels[i+1] = new Vertex(new Vector2f((tp.X+1)*size,  tp.Y   *size), color);
				g_cels[i+2] = new Vertex(new Vector2f((tp.X+1)*size, (tp.Y+1)*size), color);
				g_cels[i+3] = new Vertex(new Vector2f( tp.X   *size, (tp.Y+1)*size), color);
			}
		}
		public Celulas(uint with, uint height, float size)
		{
			this.size = size;

			cambas = new Vector2u(with, height);

			state = new bool[with * height];

			Clear();

			g_cels = new VertexArray(PrimitiveType.Quads, cambas.X * cambas.Y * 4);
			Click(11, 10);
			Click(10, 11);
			Click(10, 12);
			Click(11, 12);
			Click(12, 12);
			
			/* Para recordar, no hay que olvidar que las posiciones tambien son afectadas por el incremento a cuatro
			for (uint y = 0; y < cambas.Y * 4; y += 4)
			for (uint x = 0; x < cambas.X * 4; x += 4)
			{
				uint index = getIndex(x/4, y/4);
				Color color = state[index] == false ? Color.White : Color.Red;

				g_cels[ index ] = new Vertex(new Vector2f( x   *size,  y   *size), color);
				g_cels[index+1] = new Vertex(new Vector2f((x+1)*size,  y   *size), color);
				g_cels[index+2] = new Vertex(new Vector2f((x+1)*size, (y+1)*size), color);
				g_cels[index+3] = new Vertex(new Vector2f( x   *size, (y+1)*size), color);
			}
			*/

		}
		public void Display()
		{
			if (play)
			{
				bool[] copy = new bool[cambas.X * cambas.Y];
				Array.Copy(state, copy, cambas.X * cambas.Y);

				for (uint y = 0; y < cambas.Y; y++)
				for (uint x = 0; x < cambas.X; x++)
				{
					int count = 0;

					for (int c_x = -1; c_x < 2; c_x++)
					for (int c_y = -1; c_y < 2; c_y++)
					{
						int new_x = c_x + (int)x;
						int new_y = c_y + (int)y;

						if (new_x >= cambas.X) new_x = 0;
						if (new_x < 0) new_x = (int)cambas.X - 1;

						if (new_y >= cambas.Y) new_y = 0;
						if (new_y < 0) new_y = (int)cambas.Y - 1;

						bool temp_cel = state[getIndex(
							(uint)new_x,
							(uint)new_y 
						)];
						if (temp_cel) count++;
					}

					bool act_cel = state[getIndex(x, y)];

					if (act_cel) count--;

					if(act_cel && (count < 2 || count > 3))
						copy[getIndex(x, y)] = false;
					else if(!act_cel && count == 3)
						copy[getIndex(x, y)] = true;
				}

				Array.Copy(copy, state, cambas.X * cambas.Y);
			}
		}
		public void Clear () {
			for (int i = 0; i < state.Length; i++)
			{
				state[i] = false;
			}
		}
		public void tick () { play = !play; }
		public void Click(uint x, uint y)
		{
			state[getIndex(x, y)] = !state[getIndex(x, y)]; 
		}
	}
}
