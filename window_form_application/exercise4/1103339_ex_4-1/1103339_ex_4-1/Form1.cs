namespace _1103339_ex_4_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (comboBox1.SelectedIndex == 2)
                label2.Text = "correct!";
            else
                label2.Text = "答錯了，元智大學於1989年朝壽第一屆學生";
            if (comboBox2.SelectedIndex == 1)
                label4.Text = "correct!";
            else
                label4.Text = "Wrong! yzu university is localed at taoyuan city";
        }

        private void comboBox3_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(comboBox3.SelectedIndex == 0)
            {
                label2.Text = "";
                label4.Text = "";
                comboBox1.SelectedIndex = -1;
                comboBox2.SelectedIndex = -1;
                comboBox3.SelectedIndex = -1;
            }
        }
    }
}