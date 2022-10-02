namespace _1103339_ex_3_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Point[] pt1 = new Point[6];
            Point[] pt2 = new Point[6];
            int Cx = this.ClientRectangle.Width / 2;
            int Cy = this.ClientRectangle.Height / 2;
            int D = (int)(Math.Min(this.ClientSize.Width/2, this.ClientSize.Height/2)) - 10;
            double Theta1 = -Math.PI / 2.0;
            double Theta2 = -Math.PI / 2.0;
            pt1[5].X = Cx + (int)(D * Math.Cos(Theta1));
            pt1[5].Y = Cy + (int)(D * Math.Sin(Theta1));
            pt2[5].X = Cx + (int)(D * Math.Cos(Theta2));
            pt2[5].Y = Cy + (int)(D * Math.Sin(Theta2));
            for (int i = 0; i < 5; i++)
            {
                pt1[i].X = Cx + (int)(D * Math.Cos(Theta1));
                pt1[i].Y = Cy + (int)(D * Math.Sin(Theta1));
                pt2[i].X = Cx + (int)(D * Math.Cos(Theta2));
                pt2[i].Y = Cy + (int)(D * Math.Sin(Theta2));
                Theta1 += Math.PI * 2 / 5;
                Theta2 += Math.PI * 4 / 5;
            }
            e.Graphics.DrawLines(Pens.Black, pt1);
            e.Graphics.DrawLines(Pens.Black, pt2);
        }

        private void Form1_Resize(object sender, EventArgs e)
        {
            Invalidate();
        }
    }
}