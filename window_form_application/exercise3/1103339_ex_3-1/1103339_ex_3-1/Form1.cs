using System.Drawing.Drawing2D;

namespace _1103339_ex_3_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Size = new Size(300, 450);
        }
        
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Pen pen1 = new Pen(Color.Black, 3);
            pen1.DashStyle = DashStyle.Dash;
            e.Graphics.DrawLine(pen1, 10, 10, 200, 10);
            pen1.DashStyle = DashStyle.DashDot;
            e.Graphics.DrawLine(pen1, 10, 40, 200, 40);
            pen1.DashStyle= DashStyle.DashDotDot;
            e.Graphics.DrawLine(pen1, 10, 70, 200, 70);
            pen1.DashStyle = DashStyle.DashDotDot;
            e.Graphics.DrawLine(pen1, 10, 100, 200, 100);
            pen1.DashStyle = DashStyle.Solid;
            e.Graphics.DrawLine(pen1, 10, 130, 200, 130);

            pen1.Width = 10;
            int x = 10, y = 130;
            y += 30;
            pen1.StartCap = pen1.EndCap = LineCap.Flat;
            e.Graphics.DrawLine(pen1, x, y, x + 200, y);

            y += 30;
            pen1.StartCap = pen1.EndCap = LineCap.Square;
            e.Graphics.DrawLine(pen1, x, y, x + 200, y);

            y += 30;
            pen1.StartCap = pen1.EndCap = LineCap.Round;
            e.Graphics.DrawLine(pen1, x, y, x + 200, y);

            y += 30;
            pen1.StartCap = pen1.EndCap = LineCap.Triangle;
            e.Graphics.DrawLine(pen1, x, y, x + 200, y);

            y += 30;
            pen1.StartCap = pen1.EndCap = LineCap.SquareAnchor;
            e.Graphics.DrawLine(pen1, x, y, x + 200, y);

            y += 30;
            pen1.StartCap = pen1.EndCap = LineCap.RoundAnchor;
            e.Graphics.DrawLine(pen1, x, y, x + 200, y);

            y += 30;
            pen1.StartCap = pen1.EndCap = LineCap.DiamondAnchor;
            e.Graphics.DrawLine(pen1, x, y, x + 200, y);

            y += 30;
            pen1.StartCap = pen1.EndCap = LineCap.ArrowAnchor;
            e.Graphics.DrawLine(pen1, x, y, x + 200, y);
        }
    }
}