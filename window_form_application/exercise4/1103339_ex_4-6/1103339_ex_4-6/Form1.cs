namespace _1103339_ex_4_6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.BackColor = Color.White;
            白ToolStripMenuItem.Checked = true;
            黑ToolStripMenuItem.Checked = false;
        }

        private void 白ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.White;
            白ToolStripMenuItem.Checked = true;
            灰ToolStripMenuItem.Checked = false;
            銀ToolStripMenuItem.Checked = false;
        }

        private void 灰ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.Gray;
            白ToolStripMenuItem.Checked = false;
            灰ToolStripMenuItem.Checked = true;
            銀ToolStripMenuItem.Checked = false;
        }

        private void 銀ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.Silver;
            白ToolStripMenuItem.Checked = false;
            灰ToolStripMenuItem.Checked = false;
            銀ToolStripMenuItem.Checked = true;
        }

        private void 黑ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            textBox1.ForeColor = Color.Black;
            黑ToolStripMenuItem.Checked = true;
            紅ToolStripMenuItem.Checked = false;
            藍ToolStripMenuItem.Checked = false;
        }

        private void 紅ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            textBox1.ForeColor = Color.Red;
            黑ToolStripMenuItem.Checked = false;
            紅ToolStripMenuItem.Checked = true;
            藍ToolStripMenuItem.Checked = false;
        }

        private void 藍ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            textBox1.ForeColor = Color.Blue;
            黑ToolStripMenuItem.Checked = false;
            紅ToolStripMenuItem.Checked = false;
            藍ToolStripMenuItem.Checked = true;
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            textBox1.Text = "";
            if (checkBox1.Checked == true)
                textBox1.Text += "英文 ";
            if (checkBox2.Checked == true)
                textBox1.Text += "數學 ";
            if (checkBox3.Checked == true)
                textBox1.Text += "國文 ";
            if (checkBox4.Checked == true)
                textBox1.Text += "物理 ";
            if (checkBox5.Checked == true)
                textBox1.Text += "化學 ";

        }
    }
}