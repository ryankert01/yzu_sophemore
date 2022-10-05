using System.Drawing.Drawing2D;

namespace _1103339_ex_4_5
{
    public partial class Form1 : Form
    {
        Color bgcolor = Color.White;
        int lineWidth = 1;
        Color linecolor = Color.Black;
        bool lineSolid = true;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.BackColor = bgcolor;
            toolStripComboBox1.SelectedIndex = 0;
            toolStripComboBox2.SelectedIndex = 0;
            toolStripComboBox3.SelectedIndex = 0;
            白ToolStripMenuItem.Checked = true;
            灰ToolStripMenuItem.Checked = false;
            銀ToolStripMenuItem.Checked = false;
        }

        private void 白ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            bgcolor = Color.White;
            this.BackColor = bgcolor;
            白ToolStripMenuItem.Checked = true;
            灰ToolStripMenuItem.Checked = false;
            銀ToolStripMenuItem.Checked = false;
            Invalidate();
        }

        private void 灰ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            bgcolor = Color.Gray;
            this.BackColor = bgcolor;
            白ToolStripMenuItem.Checked = false;
            灰ToolStripMenuItem.Checked = true;
            銀ToolStripMenuItem.Checked = false;
            Invalidate();
        }

        private void 銀ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            bgcolor = Color.Silver;
            this.BackColor = bgcolor;
            白ToolStripMenuItem.Checked = false;
            灰ToolStripMenuItem.Checked = false;
            銀ToolStripMenuItem.Checked = true;
            Invalidate();
        }

        private void toolStripComboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            lineWidth = toolStripComboBox1.SelectedIndex + 1;
            Invalidate();
        }

        private void toolStripComboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (toolStripComboBox2.SelectedIndex)
            {
                case 0:
                    linecolor = Color.Red;
                    break;
                case 1:
                    linecolor = Color.Green;
                    break;
                case 2:
                    linecolor = Color.Blue;
                    break;
            }
            Invalidate();

        }

        private void toolStripComboBox3_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (toolStripComboBox3.SelectedIndex)
            {
                case 0:
                    lineSolid = true;
                    break;
                case 1:
                    lineSolid = false;
                    break;
            }
            Invalidate();

        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Pen p1 = new Pen(linecolor, lineWidth);
            if (lineSolid)
                p1.DashStyle = DashStyle.Solid;
            else
                p1.DashStyle = DashStyle.Dash;
            Graphics g1 = e.Graphics;
            g1.DrawEllipse(p1, 40, 40, 100, 100);
        }
    }
}