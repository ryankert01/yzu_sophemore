namespace _1103339_ex_4_3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            label2.Text = "你喜歡的水果有\n";
            foreach (var control in this.Controls)
            {
                if (control is CheckBox)
                {
                    if (((CheckBox)control).Checked)
                    {
                        CheckBox c = (CheckBox)control;
                        label2.Text += c.Text + '\n';
                    }
                }
            }
        }
    }
}