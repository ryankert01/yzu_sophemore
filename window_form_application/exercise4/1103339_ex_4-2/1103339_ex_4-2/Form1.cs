namespace _1103339_ex_4_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (radioButton3.Checked == true)
                label3.Text = "Correct!";
            else
                label3.Text = "Wrong! It's 1989 that YZU university first have student.";
            if (radioButton7.Checked == true)
                label4.Text = "Correct";
            else
                label4.Text = "Wrong! YZU university is located at Taoyuan city.";
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }
    }
}