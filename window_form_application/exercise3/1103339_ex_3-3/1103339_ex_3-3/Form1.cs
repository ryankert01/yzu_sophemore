namespace _1103339_ex_3_3
{
    public partial class Form1 : Form
    {

        Rectangle rect;
        int D = 1; // increase speed
        public Form1()
        {
            InitializeComponent();
            int x = this.ClientSize.Width / 2;
            int y = this.ClientSize.Height / 2;
            rect = new Rectangle(x - 50, y - 50, 100, 100);
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.DrawRectangle(Pens.Black, rect);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (rect.Bottom >= this.ClientSize.Height || rect.Top <= 0 || rect.Right >= this.ClientSize.Width || rect.Left <= 0)
                D = -1;
            else if (rect.Height < 10) 
                D = 1;
            rect.Inflate(D, D);
            Invalidate();
        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            int x = this.ClientSize.Width / 2;
            int y = this.ClientSize.Height / 2;
            rect = new Rectangle(x - 50, y - 50, 100, 100);
        }
    }
}