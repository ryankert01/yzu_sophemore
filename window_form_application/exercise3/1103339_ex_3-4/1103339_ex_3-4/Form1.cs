namespace _1103339_ex_3_4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Pen p1 = new Pen(Color.Blue, 5);
            e.Graphics.DrawEllipse(p1, 30, 30, 200, 200);
            p1.Color = Color.Black;
            e.Graphics.DrawEllipse(p1, 80, 80, 20,20);
            e.Graphics.DrawEllipse(p1, 150, 80, 20, 20);
            p1.Color = Color.Red;
            e.Graphics.DrawArc(p1, new Rectangle(80, 100, 100, 100), 0, 180);
        }
    }
}