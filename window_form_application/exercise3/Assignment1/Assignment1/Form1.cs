using Microsoft.Win32.SafeHandles;

namespace Assignment1
{
    public partial class Form1 : Form
    {
        Random rd = new Random();
        const int sz = 50;
        Color[] cr = new Color[9];
        Rectangle[] rec = new Rectangle[9];
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            
            for(int i = 0; i < 9; i++)
            {
                Brush br = new SolidBrush(cr[i]);
                int x = i / 3, y = i % 3;
                e.Graphics.FillRectangle(br, rec[i]);
                e.Graphics.DrawRectangle(Pens.Black, rec[i]);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            for(int i = 0; i < 9; i++)
            {
                cr[i] = genColor();
                int x = i / 3, y = i % 3;
                rec[i] = new Rectangle(x * sz, y * sz, sz, sz);
            }
            Invalidate();
        }

        private Color genColor()
        {
            int r, g, b;
            r = rd.Next(256);
            g = rd.Next(256);
            b = rd.Next(256);
            return Color.FromArgb(r, g, b);
        }

        private void Form1_Click(object sender, EventArgs e)
        {
            
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            for (int i = 0; i < 9; i++)
            {
                if (rec[i].Contains(e.Location))
                {
                    cr[i] = genColor();
                    Invalidate();
                }
            }
        }
    }
}