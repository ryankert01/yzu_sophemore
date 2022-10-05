namespace _1103339_ex_4_4
{
    public partial class Form1 : Form
    {
        Color c = Color.Red;
        public Form1()
        {
            InitializeComponent();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void redToolStripMenuItem_Click(object sender, EventArgs e)
        {
            c = Color.Red;
            redToolStripMenuItem.Checked = true;
            greenToolStripMenuItem.Checked = false;
            blueToolStripMenuItem.Checked = false;
        }

        private void greenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            c = Color.Green;
            redToolStripMenuItem.Checked = false;
            greenToolStripMenuItem.Checked = true;
            blueToolStripMenuItem.Checked = false;
        }

        private void blueToolStripMenuItem_Click(object sender, EventArgs e)
        {
            c = Color.Red;
            redToolStripMenuItem.Checked = false;
            greenToolStripMenuItem.Checked = false;
            blueToolStripMenuItem.Checked = true;
        }

        private void circleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Graphics g1 = this.CreateGraphics();
            g1.DrawEllipse(new Pen(c), 20, 40, 100, 100);
        }

        private void squareToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Graphics g1 = this.CreateGraphics();
            g1.DrawRectangle(new Pen(c), 140, 40, 100, 100);
        }

        private void clearToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Graphics g1 = this.CreateGraphics();
            g1.Clear(this.BackColor);
        }
    }
}