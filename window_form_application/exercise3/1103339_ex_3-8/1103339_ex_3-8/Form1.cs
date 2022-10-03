namespace _1103339_ex_3_8
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            int x, y, r, g, b;
            Random rd = new Random();
            Brush b1;
            Graphics g1 = this.CreateGraphics();
            g1.Clear(Color.White);
            for(int i = 0; i < 10; i++)
            {
                x = 10 + rd.Next(260);
                y = 10 + rd.Next(260);
                r = rd.Next(256);
                g = rd.Next(256);
                b = rd.Next(256);
                b1 = new SolidBrush(Color.FromArgb(r,g,b));
                g1.FillEllipse(b1, x-5, y-5, 10, 10);
            }
        }
    }
}