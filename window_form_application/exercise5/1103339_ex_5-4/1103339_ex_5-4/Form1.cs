namespace _1103339_ex_5_4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void loadToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if(openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                StreamReader inFile = new StreamReader(openFileDialog1.FileName);
                textBox1.Text = inFile.ReadToEnd();
                inFile.Close();
            }
        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                StreamWriter outFile = new StreamWriter(saveFileDialog1.FileName);
                outFile.Write(textBox1.Text);
                outFile.Close();
            }


        }

        private void Form1_Load(object sender, EventArgs e)
        {
            openFileDialog1.Filter = "文字檔(*.txt)|*.txt";
            saveFileDialog1.Filter = "文字檔(*.txt)|*.txt";

        }
    }
}