namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        int startAngle = -10;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            int Cx = this.ClientSize.Width / 2;
            int Cy = this.ClientSize.Height / 2;
            int D = (int)(Math.Min(this.ClientSize.Width, this.ClientSize.Height) / 2) - 10;
            for(int i = 0; i < 18; i++)
            {
                if(i % 2 == 0)
                {
                    e.Graphics.DrawPie(Pens.Black, Cx - D, Cy - D, 2 * D, 2 * D, startAngle + i * 20, 20);
                }
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            startAngle += 1;
            Invalidate();
        }
    }
}